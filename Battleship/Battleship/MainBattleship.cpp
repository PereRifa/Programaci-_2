#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Functions.h"
#include<time.h>

void battlesize(Field*);
void datosships(Ship*,Field*);
int shots(Field *);
void printmap(Field *);

int main(){
	int i = 0, j = 0;

	srand(time(NULL));
	//int xlenght, yheight;
	Field *battlezone;
	Ship *battleships;
	int shotnumb=0;

	battleships = (Ship*)malloc(4 * sizeof(Ship));
	if (battleships == NULL) {
		printf("Error in allocating the data array.\n");
		exit(0);
	}
	battlezone = (Field*)malloc(sizeof(Field));
	if (battlezone == NULL) {
		printf("Error in allocating the data array.\n");
		exit(0);
	}
	battlesize(battlezone); // Define Battlefield;

	printf("\n\tWelcome to Battleship\n");
	printmap(battlezone);
	shotnumb = shots(battlezone);
	printf("\nNumber of bombs throun: %i", shotnumb);
	/*
	datosships(battleships, battlezone);
	printf("\nBattlefield\n");
	for (i = 0; i < 10; i++){
		for (j = 0; j < 10; j++){
			printf(" %c", (battlezone)->battlefield[i][j]);
		}
		printf("\n");
	}
	printf("\nBattlefieldhiden\n");
	for (i = 0; i < 10; i++){
		for (j = 0; j < 10; j++){
			printf(" %c", (battlezone)->battlefieldhiden[i][j]);
		}
		printf("\n");
	}
	*/
	free(battleships);
	free(battlezone);
	system("pause");
	return 0;
}

void battlesize(Field *battlezone){
	int i = 0;
	int j = 0;
	
	for (i = 0; i < 10; i++){
		for (j = 0; j < 10; j++){
			(battlezone)->battlefield[i][j] = '-';
		}
	}
	for (i = 0; i < 10; i++){
		for (j = 0; j < 10; j++){
			(battlezone)->battlefieldhiden[i][j] = '-';
		}
	}
}
void datosships(Ship *battleships, Field *battlezone){
	
	int pos;
	int xcor, ycor;
	char simbtype = 'A';
	srand(time(NULL));
	int i, k, ocupado, n = 1;
	for (i = 0; i < 7; i++){
		ocupado = 1;
	
		(battleships + i)->lenght = n;
		(battleships + i)->simbolo = simbtype;
		while (ocupado == 1){
			pos = rand() % 2;
			if (pos == 0){
				
				(battleships + i)->x = rand() % (10 - ((battleships + i)->lenght-1));
				(battleships + i)->y = rand() % 10;
				xcor = (battleships + i)->x; 
				ycor = (battleships + i)->y;
				for (k = 0; k < n; k++){
					if ((battlezone)->battlefieldhiden[(xcor + k)][ycor] != '-'){
						ocupado = 1;
					}
					else ocupado = 0;
					if (ocupado == 1){
						k = n;
					}
				}
				if (ocupado == 0){
					for (k = 0; k < n; k++){
						(battlezone)->battlefieldhiden[(xcor + k)][ycor] = simbtype;
					}
				}
				
			}
			if (pos == 1){
				
				(battleships + i)->x = rand() % 10;
				(battleships + i)->y = rand() % (10 - ((battleships + i)->lenght-1));
				xcor = (battleships + i)->x;
				ycor = (battleships + i)->y;
				for (k = 0; k < n; k++){/*k = n; k >= 0; k--*/
					if ((battlezone)->battlefieldhiden[xcor][ycor + k] != '-'){
						ocupado = 1;
					}
					else ocupado = 0;
					if (ocupado == 1){
						k = n;
					}
				}

				if (ocupado == 0){
					for (k = 0; k < n; k++){
						(battlezone)->battlefieldhiden[xcor][ycor + k] = simbtype;
					}
				}
			}
			
		}
		simbtype++;
		n++;
	}
}

int shots(Field *battlezone){
	int shots = 0;
	int end = 0;
	int xcor, ycor, destroyedships = 0;
	printf("\tLet's start the battle!!\n");
	while (end == 0){
		printf("\nSet the x and y cordinate to shot the bomb:\n\t x: ");
		scanf_s("%i", &xcor);
		printf("\t y: ");
		scanf_s("%i", &ycor);
		if ((battlezone)->battlefieldhiden[xcor][ycor] == (battlezone)->battlefield[xcor][ycor]){
			printf("Miss!! :(");
			(battlezone)->battlefield[xcor][ycor] = 0;
		}
		else {
			(battlezone)->battlefield[xcor][ycor] = (battlezone)->battlefieldhiden[xcor][ycor];
			printf("Success Hit!!");
			destroyedships++;
		}
		if (destroyedships == 10){
			printf("\nYou have won the battle!!\n");
			end = 1;
		}
		printmap(battlezone);
		shots++;
	}
	
	return shots;
}

void printmap(Field *battlezone){
	int i = 0, j = 0;
	printf("\nBattlefield\n");
	for (i = 0; i < 10; i++){
		for (j = 0; j < 10; j++){
			printf(" %c", (battlezone)->battlefield[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < 10; i++){
		for (j = 0; j < 10; j++){
			(battlezone)->battlefieldhiden[i][j] = '-';
		}
	}
}