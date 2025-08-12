//compilar no terminal
//gcc main.c -o meu_executavel -lallegro -lallegro_primitives -lallegro_font -lallegro_ttf -lallegro_audio -lallegro_acodec -lallegro_image -lm && ./meu_executavel

//bibliotecas e definicoes globais
#include <allegro5/allegro.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>

#define SUCESSO  0
#define ERRO -1
#define MAX_TIROS 1
#define PASSO_HORIZONTAL 1
#define PASSO_VERTICAL 20
#define PASSO_NAVE 5
#define INIMIGOS_LINHAS 4
#define INIMIGOS_COLUNAS 5
#define MAX_INIMIGOS (INIMIGOS_LINHAS * INIMIGOS_COLUNAS)
#define TOTAL_MUSICAS 5
#define SOM_MORTE_INIMIGO "morte_inimigo.ogg"
#define TECLA_ESQUERDA_J1  ALLEGRO_KEY_LEFT
#define TECLA_DIREITA_J1 ALLEGRO_KEY_RIGHT
#define TECLA_TIRO_J1 ALLEGRO_KEY_SPACE
#define TECLA_ESQUERDA_J2 ALLEGRO_KEY_A
#define TECLA_DIREITA_J2 ALLEGRO_KEY_D
#define TECLA_TIRO_J2 ALLEGRO_KEY_W
#define DISTANCIA_INICIAL_JOGADORES 100

//constantes globais
const float FPS = 60;
const int LARGURA_TELA = 960;
const int ALTURA_TELA = 540;
const int NAVE_W = 100;
const int NAVE_H = 50;
const int TIRO_LARGURA = 15;
const int TIRO_ALTURA = 10;

//structs
ALLEGRO_COLOR COR_CENARIO;

//struct nave
typedef struct Nave
{
    int x, y;
    ALLEGRO_COLOR cor;
}Nave;

//struct tiro
typedef struct Tiro{
    int x, y;
    int ativo;
    int velocidade;
    ALLEGRO_COLOR cor;
}Tiro;

//struct inimigo
typedef struct Inimigo{
    int x, y;
    int ativo;
    int velocidade;
    ALLEGRO_COLOR cor;
}Inimigo;

//funcao para iniciar cor inicial do cenario
void init_globais()
{
    COR_CENARIO = al_map_rgb(0,0,255);
}

//funcao para desenhar cenario
void desenha_cenario()
{
    al_clear_to_color(COR_CENARIO);
}

//funcao para criar a nave (triangular)
void init_nave(Nave *nave, int fase)
{
    nave->x = LARGURA_TELA/2;
    nave->y = ALTURA_TELA - (NAVE_H/2) - 10;
    if((fase%2) == 0)
    {
        nave->cor = al_map_rgb(255, 0, 0);
    }
    else
    {
        nave->cor = al_map_rgb(0, 255, 0);
    }
}

//funcao para inserir a nave no jogo
void desenha_nave(Nave nave)
{
    al_draw_filled_triangle(
        nave.x, nave.y - NAVE_H/2, //Ponta superior 
        nave.x - NAVE_W/2, nave.y + NAVE_H/2, //canto inferior esquerdo 
        nave.x + NAVE_W/2, nave.y + NAVE_H/2, //canto inferiro direito 
        nave.cor); //cor da nave
}

//inicializa tiros do jogo
void inicializa_tiros(Tiro tiros[])
{
    for(int i = 0; i < MAX_TIROS; i++)
    {
        tiros[i].ativo = 0;
        tiros[i].x = 0;
        tiros[i].y = ALTURA_TELA;
        tiros[i].velocidade = 5;
        tiros[i].cor = al_map_rgb(0,0,255);
    }
}

//desenha tiros
void desenha_tiros(Tiro tiros[])
{
    //desenha tiros
    for (int i = 0; i < MAX_TIROS; i++)
    {
        if (tiros[i].ativo)
        {
            al_draw_filled_rectangle(tiros[i].x - TIRO_LARGURA/2, tiros[i].y - TIRO_ALTURA/2,
                tiros[i].x + TIRO_LARGURA/2,
                tiros[i].y, 
                tiros[i].cor);
        }
    }
}

//funcao para movimentar os tiros e verifica colisao
void movimenta_tiros(Tiro tiros[], Inimigo inimigos[], int* pontuacao, ALLEGRO_SAMPLE *som_morte)
{
    //movimenta os tiros existentes
    for (int i = 0; i < MAX_TIROS; i++)
    {
        if(tiros[i].ativo)
        {
            tiros[i].y -= tiros[i].velocidade;
            if(tiros[i].y < 0)
            {
                tiros[i].ativo = 0;
            }

            //verifica colisão com inimigos //distancia euclidiana
            for (int j = 0; j < MAX_INIMIGOS; j++) {
                if (inimigos[j].ativo) {
                    int dx = tiros[i].x - inimigos[j].x;
                    int dy = tiros[i].y - inimigos[j].y;
                    int distancia2 = dx * dx + dy * dy;
                    int raio_colisao = 15;  

                    if (distancia2 <= raio_colisao * raio_colisao) {
                        // Acertou o inimigo!
                        inimigos[j].ativo = 0;
                        tiros[i].ativo = 0;
                        (*pontuacao) += 1;
                        if(som_morte) 
                        {
                            al_play_sample(som_morte, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                        }
                        break; 
                    }
                }
            }
        }

    }
}

//funcao para lidar com teclas dos jogadores
void input_jogador(ALLEGRO_EVENT ev, int* move_esquerda, int* move_direita, Tiro tiros[], Nave nave, int tecla_esquerda, int tecla_direita, int tecla_tiro)
{
    if(ev.type == ALLEGRO_EVENT_KEY_UP || ev.type == ALLEGRO_EVENT_KEY_DOWN) {
        switch(ev.keyboard.keycode) {
            case TECLA_ESQUERDA_J1:
            case TECLA_ESQUERDA_J2:
                if(ev.keyboard.keycode == tecla_esquerda)
                    *move_esquerda = (ev.type == ALLEGRO_EVENT_KEY_DOWN);
                break;

            case TECLA_DIREITA_J1:
            case TECLA_DIREITA_J2:
                if(ev.keyboard.keycode == tecla_direita)
                    *move_direita = (ev.type == ALLEGRO_EVENT_KEY_DOWN);
                break;

            case TECLA_TIRO_J1:
            case TECLA_TIRO_J2:
                if(ev.type == ALLEGRO_EVENT_KEY_DOWN && ev.keyboard.keycode == tecla_tiro) {
                    for (int i = 0; i < MAX_TIROS; i++) {
                        if(!tiros[i].ativo) {
                            tiros[i].x = nave.x;
                            tiros[i].y = nave.y - NAVE_H/2;
                            tiros[i].ativo = 1;
                            break;
                        }
                    }
                }
                break;
        }
    }
}

//inicializa inimigos
void inicializa_inimigos(Inimigo inimigos[], int fase)
{
    int espacamento_x = 80;
    int espacamento_y = 50; 
    int inicio_x = 100;
    int inicio_y = 100;

    for (int linha = 0; linha < INIMIGOS_LINHAS; linha++) {
        for (int col = 0; col < INIMIGOS_COLUNAS; col++) {
            int index = linha * INIMIGOS_COLUNAS + col;
            inimigos[index].x = inicio_x + col * espacamento_x;
            inimigos[index].y = inicio_y + linha * espacamento_y;
            inimigos[index].velocidade = PASSO_HORIZONTAL + fase;
            inimigos[index].ativo = 1;
            inimigos[index].cor = al_map_rgb(0, 0, 0);
        }
    }
}

//desenha inimigos
void desenha_inimigos(Inimigo inimigos[])
{
    for (int i = 0; i < MAX_INIMIGOS; ++i)
    {
        if(inimigos[i].ativo)
        {
            al_draw_filled_circle(inimigos[i].x, inimigos[i].y, 15, inimigos[i].cor);
        }
    }
}

//funcao para mover os inimigos
void movimenta_inimigos(Inimigo inimigos[], int * direcao)
{
    //movimenta inimigos
    int mudar_direcao = 0;

    for(int i = 0; i < MAX_INIMIGOS; i++) {
        if(inimigos[i].ativo) {
            inimigos[i].x += *direcao * inimigos[i].velocidade;

            // Verifica se algum inimigo tocou a borda
            if(inimigos[i].x <= 0 || inimigos[i].x >= LARGURA_TELA) {
                mudar_direcao = 1;
            }
        }
    }

    //muda direcao do inimigo e desce uma linha
    if(mudar_direcao) {
        *direcao *= -1;
        for (int i = 0; i < MAX_INIMIGOS; i++) {
            inimigos[i].y += PASSO_VERTICAL;
        }
    }
}

//funcao para verificar se o inimigo colidiu com a nave
int colisao_inimigo_nave(Inimigo inimigo, Nave nave) {
    int inimigo_radius = 15;

    // Caixa do inimigo (circulo aproximado por quadrado)
    int inimigo_left = inimigo.x - inimigo_radius;
    int inimigo_right = inimigo.x + inimigo_radius;
    int inimigo_top = inimigo.y - inimigo_radius;
    int inimigo_bottom = inimigo.y + inimigo_radius;

    // Caixa da nave (triangulo aproximadamente retangular)
    int nave_left = nave.x - NAVE_W/2;
    int nave_right = nave.x + NAVE_W/2;
    int nave_top = nave.y - NAVE_H/2;
    int nave_bottom = nave.y + NAVE_H/2;

    // Verifica sobreposição das caixas (AABB)
    if (inimigo_right < nave_left || inimigo_left > nave_right ||
        inimigo_bottom < nave_top || inimigo_top > nave_bottom) {
        return 0; // Não colidiu
    }
    return 1; // Colidiu
}

//reinicia o jogo
void reset_jogo(Nave *nave, Tiro tiros[], Inimigo inimigos[], int *game_over, int fase, int modoJogo, Nave *nave2, Tiro tiros2[]) 
{
    init_nave(nave, fase);
    inicializa_tiros(tiros);
    inicializa_inimigos(inimigos, fase);
    *game_over = 0;
    init_globais();

    if(modoJogo == 2)
    {
        init_nave(nave2, fase+1);
        nave2->y = nave->y;
        nave2->x = nave->x - DISTANCIA_INICIAL_JOGADORES;
        inicializa_tiros(tiros2);
    }
}

int ler_recorde()
{
    FILE *f = fopen("recorde.txt", "r");
    if(f == NULL)
    {
        return 0;
    }

    int recorde;
    fscanf(f,"%d", &recorde);
    fclose(f);
    return recorde;
}

//salva recorde
void salvar_recorde(int pontuacao)
{
    FILE *f = fopen("recorde.txt", "w");
    if(f != NULL)
    {
        fprintf(f, "%d\n", pontuacao);
        fclose(f);
    }
}

//Game Over
int tela_game_over(ALLEGRO_FONT *fonte, ALLEGRO_EVENT_QUEUE *event_queue, int pontuacao, int recorde)
{
    desenha_cenario();
    al_draw_text(fonte, al_map_rgb(255, 0, 0), LARGURA_TELA/2, ALTURA_TELA/2 - 20, ALLEGRO_ALIGN_CENTER, "PERDEU, MANE");
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA_TELA/2, ALTURA_TELA/2 + 20, ALLEGRO_ALIGN_CENTER, "Pontuação: %d", pontuacao);
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), 10, 30, 0, "Recorde: %d", recorde);
    al_draw_text(fonte, al_map_rgb(255, 255, 0), LARGURA_TELA/2, ALTURA_TELA/2 + 60, ALLEGRO_ALIGN_CENTER, "Pressione R para reiniciar ou ESC para sair");
    al_flip_display();

    // Espera escolha do jogador
    while(1) 
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            if (ev.keyboard.keycode == ALLEGRO_KEY_R)
            {
                return 1; //reiniciar o jogo
            }
            else if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) 
            {
                return 0; //sair do jogo
            }
        }

        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            return 0; //sair do jogo
        }
    }
}

//funcao multiplayer
int escolher_modo_jogo(ALLEGRO_FONT * fonte, ALLEGRO_EVENT_QUEUE *event_queue)
{
    desenha_cenario();
    al_draw_text(fonte, al_map_rgb(255, 255, 0), LARGURA_TELA/2, ALTURA_TELA/2 - 40, ALLEGRO_ALIGN_CENTER, "Escolha o modo de jogo:");
    al_draw_text(fonte, al_map_rgb(255, 255, 255), LARGURA_TELA/2, ALTURA_TELA/2, ALLEGRO_ALIGN_CENTER, "1 - Um Jogador");
    al_draw_text(fonte, al_map_rgb(255, 255, 255), LARGURA_TELA/2, ALTURA_TELA/2 + 40, ALLEGRO_ALIGN_CENTER, "2 - Dois Jogadores");
    al_flip_display();

    while(1)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            if(ev.keyboard.keycode == ALLEGRO_KEY_1)
            {
                return 1;
            }
            else if(ev.keyboard.keycode == ALLEGRO_KEY_2)
            {
                return 2;
            }
        }
        else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            return 0;
        }
    }
}

//funcao para tocar as musicas em cada fase
void tocar_musica_fase(int fase, ALLEGRO_SAMPLE *musicas[], ALLEGRO_SAMPLE_ID *musica_id) {
    // Para a música anterior (se estiver tocando)
    if(musica_id != 0)
    {
        al_stop_sample(musica_id);
    }

    // Limita fase ao número de músicas disponíveis
    int index = (fase - 1) % TOTAL_MUSICAS;

    al_play_sample(musicas[index], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, musica_id);
}


//funcao principal
int main() {

    //passando o time como semente para funcao de pseudos-aleatorios
    srand(time(NULL));

    ALLEGRO_DISPLAY *display = NULL; // Ponteiro para a janela (o "display")
    ALLEGRO_EVENT_QUEUE *event_queue = NULL; // Ponteiro para a fila de eventos
    ALLEGRO_TIMER *timer = NULL; // Ponteiro para o temporizador

    //inicia o allegro
    if (!al_init()){
        fprintf(stderr, "Falha ao inicializar o Allegro!\n");
        return ERRO;
    }

    //instala teclado
    if(!al_install_keyboard()){
        fprintf(stderr, "Falha ao instalar teclado!\n");
        return ERRO;
    }

    //inicia funcoes primitivas usadas no jogo
    if(!al_init_primitives_addon()){
        fprintf(stderr, "Falha ao inicializar primitivas!\n");
        return ERRO;
    }

    //inicializa fontes
    if (!al_init_font_addon() || !al_init_ttf_addon()) {
    fprintf(stderr, "Falha ao inicializar fontes!\n");
    return ERRO;
    }

    //carrega e define fonte
    ALLEGRO_FONT* fonte = al_create_builtin_font();

    if (!fonte) {
        fprintf(stderr, "Falha ao carregar fonte!\n");
        return ERRO;
    }

    //cria a janela e define o tamanho.
    display = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if(!display){
        fprintf(stderr, "Falha ao criar a janela!\n");
        return ERRO;
    }

    //inicializa funcoes de audio
    if(!al_install_audio())
    {
        fprintf(stderr, "Falha ao inicializar o sistema de áudio.\n");
        return ERRO;
    }

    if(!al_init_acodec_addon())
    {
        fprintf(stderr, "Falha ao inicializar os codecs de áudio.\n");
        return ERRO;
    }

    if(!al_reserve_samples(TOTAL_MUSICAS))
    {
        fprintf(stderr, "Falha ao reservar amostras de áudio.\n");
        return ERRO;
    }

    ALLEGRO_SAMPLE *musicas[TOTAL_MUSICAS];
    ALLEGRO_SAMPLE_ID musica_id = {0};
    ALLEGRO_SAMPLE *som_morte = NULL;

    //musicas
    char nome_arquivo[20];
    for (int i = 0; i < TOTAL_MUSICAS; i++) {
        snprintf(nome_arquivo, sizeof(nome_arquivo), "fase%d.ogg", i+1);
        musicas[i] = al_load_sample(nome_arquivo);
        if (!musicas[i]) {
            fprintf(stderr, "Falha ao carregar %s\n", nome_arquivo);
            for (int j = 0; j < i; j++) {
                al_destroy_sample(musicas[j]);
            }
            al_destroy_display(display);
            return ERRO;
        }
    }

    som_morte = al_load_sample(SOM_MORTE_INIMIGO);
    if (!som_morte) {
        fprintf(stderr, "Erro ao carregar som de morte do inimigo: %s\n", SOM_MORTE_INIMIGO);
        // você pode continuar o jogo mesmo sem som, então não precisa retornar ERRO
    }

    //inicializa funcoes de imagem
    if(!al_init_image_addon()) {
    fprintf(stderr, "Falha ao inicializar addon de imagens!\n");
    al_destroy_display(display);
    return ERRO;
    }

    ALLEGRO_BITMAP *background = al_load_bitmap("cruzeiro_background.jpg"); // ou .png, dependendo do formato
    if(!background) {
        fprintf(stderr, "Falha ao carregar imagem de fundo!\n");
        al_destroy_display(display);
        return ERRO;
    }

    //cria timer
    timer = al_create_timer(1.0/FPS);
    if(!timer){
        fprintf(stderr, "Falha ao criar temporizador!\n");
        al_destroy_display(display);
        return ERRO;
    }

    //cria lista de eventos
    event_queue = al_create_event_queue();
    if(!event_queue){
        fprintf(stderr, "Falha ao criar lista de eventos!\n");
        return ERRO;
    }

    //define o título da janela
    al_set_window_title(display, "Cabuloso");

    //registra os eventos na fila
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer)); 

    //gera cor aleatoria
    init_globais();

    //inicializa temporizador
    al_start_timer(timer);

    //escolhe o modo players
    int modoJogo = escolher_modo_jogo(fonte, event_queue);
    if(modoJogo == 0)
    {
        al_destroy_display(display);
        return SUCESSO;
    }
    Nave nave2;
    Tiro tiros2[MAX_TIROS];
    int moveA = 0, moveD = 0;

    //loop do jogo
    int playing = 1;
    int recorde = ler_recorde();
    int fase = 1;
    int pontuacao = 0;
    while(playing){
        // Inicializa variáveis do jogo
        Nave nave;
        Tiro tiros[MAX_TIROS];
        Inimigo inimigos[MAX_INIMIGOS];
        int game_over = 0;
        int move_rigth = 0, move_left = 0;
        int direcao = 1;

        reset_jogo(&nave, tiros, inimigos, &game_over, fase, modoJogo, &nave2, tiros2);
        tocar_musica_fase(fase, musicas, &musica_id);

        //subloop pro jogo
        int jogando = 1;
        while(jogando)
        {
            ALLEGRO_EVENT ev;
            //espera evento e o armazena na variavel ev
            al_wait_for_event(event_queue, &ev);

            if(!game_over)
            {
                //verifica se o evento foi um evento do temporizador
                if(ev.type == ALLEGRO_EVENT_TIMER){

                    //movimenta jogador 1
                    if(move_left && nave.x - NAVE_W/2 > 0)
                    {
                        nave.x -= PASSO_NAVE;
                    }
                    if(move_rigth && nave.x + NAVE_W/2 < LARGURA_TELA)
                    {
                        nave.x += PASSO_NAVE;
                    }

                    movimenta_tiros(tiros, inimigos, &pontuacao, som_morte);

                    //movimenta jogador 2
                    if(modoJogo == 2)
                    {
                        if(moveA && nave2.x - NAVE_W/2 > 0)
                        {
                            nave2.x -= 5;
                        }
                        if(moveD && nave2.x + NAVE_W/2 < LARGURA_TELA)
                        {
                            nave2.x += 5;
                        }

                        movimenta_tiros(tiros2, inimigos, &pontuacao, som_morte);
                    }

                    movimenta_inimigos(inimigos, &direcao);

                    //desenha a cena
                    // desenha_cenario();
                    al_draw_scaled_bitmap(background, 0, 0, al_get_bitmap_width(background), al_get_bitmap_height(background), 0, 0, LARGURA_TELA, ALTURA_TELA, 0);       
                    desenha_nave(nave);
                    desenha_tiros(tiros);
                    desenha_inimigos(inimigos);

                    if(modoJogo == 2)
                    {
                        desenha_nave(nave2);
                        desenha_tiros(tiros2);
                    }

                    //atualiza a tela
                    al_draw_textf(fonte, al_map_rgb(0, 0, 0), 10, 10, 0, "Pontuação: %d", pontuacao);
                    al_draw_textf(fonte, al_map_rgb(0, 0, 0), 10, 30, 0, "Recorde: %d", recorde);
                    al_draw_textf(fonte, al_map_rgb(0, 0, 0), 10, 50, 0, "Fase: %d", fase);
                    al_flip_display();
                }

                //movimenta jogadores
                input_jogador(ev, &move_left, &move_rigth, tiros, nave, TECLA_ESQUERDA_J1, TECLA_DIREITA_J1, TECLA_TIRO_J1);
                if (modoJogo == 2) {
                    input_jogador(ev, &moveA, &moveD, tiros2, nave2, TECLA_ESQUERDA_J2, TECLA_DIREITA_J2, TECLA_TIRO_J2);
                }
            }

            // Verifica colisão real entre inimigos e nave:
            for (int i = 0; i < MAX_INIMIGOS; i++)
            {
                if (inimigos[i].ativo && (colisao_inimigo_nave(inimigos[i], nave) ||((modoJogo == 2 && colisao_inimigo_nave(inimigos[i], nave2)))))
                {
                    game_over = 1;
                }
            }

            //verifica se o programa foi fechado
            if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                jogando = 0;
                playing = 0;
            }

            //salva recorde e verifica se jogador quer continuar
            if(game_over)
            {
                //salva maior pontuacao
                if (pontuacao > recorde)
                {
                    recorde = pontuacao;
                    salvar_recorde(recorde);
                }

                int resposta = tela_game_over(fonte, event_queue, pontuacao, recorde);
                if(resposta == 0)
                {
                    jogando = 0;
                    playing = 0;
                }
                else
                {
                    //reinicia o jogo
                    jogando = 0;
                    fase = 1;
                    pontuacao = 0;
                }
            }

            //verifica se o jogador venceu e avanca fase
            int todosMortos = 1;
            for(int i = 0; i < MAX_INIMIGOS; ++i)
            {
                if (inimigos[i].ativo)
                {
                     todosMortos = 0;
                     break;
                } 
            }

            if(todosMortos)
            {
                fase++;
                jogando = 0;
            }

        }
    }

    //libera ponteiros inicializados durante o jogo
    al_destroy_timer(timer);
    al_destroy_event_queue(event_queue);
    al_destroy_display(display);
    al_destroy_font(fonte);
    al_destroy_bitmap(background);
    for (int i = 0; i < TOTAL_MUSICAS; i++)
    {
        if (musicas[i]) 
        {
            al_destroy_sample(musicas[i]);
        }
    }
    if(som_morte)
    {
        al_destroy_sample(som_morte);
    }

    //encerra programa
    return SUCESSO;
}