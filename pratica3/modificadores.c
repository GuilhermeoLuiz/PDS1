#define SUCESSO 0
#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{	
	short shortP = (short int) -pow(2,15);
	short shortG = (short int) (pow(2,15) - 1);
	printf("menor: %hd\n", shortP);
	printf("maior: %hd\n", shortG);

	int intP = (int) -pow(2,31);
	int intG = (int) (pow(2,31) - 1);
	printf("menor: %d\n", intP);
	printf("maior: %d\n", intG);

	long int longP = (long int) -pow(2,31);
	long int longG = (long int) (pow(2,31) - 1);
	printf("menor: %ld\n", longP);
	printf("maior: %ld\n", longG);

	long long int llongP = (long long int) -pow(2,63);
	long long int llongG = (long long int) (pow(2,63) - 1);
	printf("menor: %lld\n", llongP);
	printf("maior: %lld\n", llongG);

	unsigned int unsignedP = (unsigned int) pow(2,0) - 1;
	unsigned int unsignedG = (unsigned int) (pow(2,32) - 1);
	printf("menor: %u\n", unsignedP);
	printf("maior: %u\n", unsignedG);

	long long unsigned int lluG = (long long unsigned int) (pow(2,64) - 1);
	printf("maior: %llu\n", lluG);

	return SUCESSO;
}