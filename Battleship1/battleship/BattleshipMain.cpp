#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BattleshipHeader.h"
#include<time.h>


int main(){
	
	srand(time(NULL));

	int i = 0, j = 0, n;
	int **battlezone;
	int **battlezonehiden;
	Ship *battleships;

	printf("\n\tWelcome to Battleship\n\nTell us the size of the sea you wanna clear:	");
	scanf_s("%i", &n);
	while (n < 4){
		printf("\nThe map size you want is to small, try again:");
		scanf_s("%i", &n);
	}

	battleships = (Ship*)malloc(4 * sizeof(Ship));
	if (battleships == NULL) {
		printf("Error in allocating the data array.\n");
		exit(0);
	}
	battlezone = (int **)malloc(n*(sizeof(int)));
	if (battlezone == NULL) {
		printf("Error in allocating the data array.\n");
		exit(0);
	}
	for (i = 0; i < n; i++){
		battlezone[i] = (int *)malloc(n * (sizeof(int)));
	}
	battlezonehiden = (int **)malloc(n*(sizeof(int)));
	if (battlezonehiden == NULL) {
		printf("Error in allocating the data array.\n");
		exit(0);
	}
	for (i = 0; i < n; i++){
		battlezonehiden[i] = (int *)malloc(n * (sizeof(int)));
	}
	
	battlesize(battlezone, battlezonehiden, n); // Define Battlefield;
	datosships(battleships, battlezonehiden, n); //Set up Ships;
	
	printmap(battlezone, battlezonehiden, n);
	shots(battlezone, battlezonehiden, n);
	
	for (i = 0; i < n; i++){
			free(battleships);
			free(battlezone+i);
			free(battlezonehiden+i);
			system("pause");
			return 0;
		}
}
