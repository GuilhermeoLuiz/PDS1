void processar_dados_sensores(const char* dadosbrutos, float* temperatura, float* umidade)
{
    *temperatura = 0.0;
    *umidade = 0.0;
    sscanf(dadosbrutos, "T%f U%f", temperatura, umidade);
    sscanf(dadosbrutos, "U%f T%f", umidade, temperatura);
}

int main() {
    float temp;
    float umid;
    processar_dados_sensores("T25.5 U60", &temp, &umid);
    printf("Temp=%.1f, Umid=%.1f\n", temp, umid); // Temp=25.5, Umid=60.0
    processar_dados_sensores("U11 T55", &temp, &umid);
    printf("Temp=%.1f, Umid=%.1f\n", temp, umid); // Temp=55.0, Umid=11.0
    processar_dados_sensores("U66.1 T99.8", &temp, &umid);
    printf("Temp=%.1f, Umid=%.1f\n", temp, umid); // Temp=99.8, Umid=66.1
    processar_dados_sensores("U66.1", &temp, &umid);
    printf("Temp=%.1f, Umid=%.1f\n", temp, umid); // Temp=0.0, Umid=66.1
    processar_dados_sensores("T99.8", &temp, &umid);
    printf("Temp=%.1f, Umid=%.1f\n", temp, umid); // Temp=99.8, Umid=0.0
    return 0;
}