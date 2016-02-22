#include <stdio.h>
#include <stdlib.h>

int main(){

	int numero1, numero2, i = 1, n;

	printf("Dona dos numeros, torna el producte\n");
	scanf_s("%i", &numero1);
	scanf_s("%i", &numero2);
	n = numero1;
	
	while (i < numero2){
		numero1 += n;
		i++;
	}
	printf("\n%i ", numero1);
	system("pause");
	return 0;
}