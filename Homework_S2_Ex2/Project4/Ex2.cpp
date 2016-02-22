#include <stdio.h>
#include <stdlib.h>

int main(){
	int num1, nummin, i = 0;
	printf("\nWrite 10 numbers:\n");
	scanf_s("%i", &nummin);
	for (i = 0; i <= 8; i++){
		scanf_s("%i", &num1);
		if (nummin > num1){
			nummin = num1;
		}
	}
	printf("\nThe number with the smallest value is: %i\n", nummin);
	system("pause");
	return 0;
}