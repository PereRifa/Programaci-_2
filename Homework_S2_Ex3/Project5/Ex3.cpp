#include <stdio.h>
#include <stdlib.h>

int main(){

	int option = 0, number;

	while (option != 'd'){
		printf("\n\nWrite one number and chose an option:\n");
		scanf_s("%i", &number);
		printf("\n\ta. Increment\n\tb. Decrement\n\tc. Power of two\n\td. Quit\n");
		scanf_s(" %c", &option);
		switch (option){
		case 'a':	printf("\nIncressed number = %i\n", ++number);
			break;
		case 'b':	printf("\nDecressed number = %i\n", --number);
			break;
		case 'c':	printf("\nPower of two = %i\n", number*number);
			break;
		}
	}
	system("pause");
	return 0;
}