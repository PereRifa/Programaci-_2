#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BattleshipHeader.h"
#include<time.h>


void battlesize(int  **battlezone, int **battlezonehiden, int n){
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			(*(*(battlezone + i) + j)) = '-';
		}
	}
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			(*(*(battlezonehiden + i) + j)) = '0';
		}
	}

}

void datosships(Ship *battleships, int **battlezonehiden, int n){

	int pos;
	int xcor, ycor;
	char simbtype = 'A';
	srand(time(NULL));
	int i, k, full, f = 1;
	for (i = 0; i < 4; i++){
		full = 1;

		(battleships + i)->lenght = f;
		(battleships + i)->simbolo = simbtype;
		while (full == 1){
			pos = rand() % 2;
			if (pos == 0){

				(battleships + i)->x = rand() % (n - ((battleships + i)->lenght - 1));
				(battleships + i)->y = rand() % n;
				xcor = (battleships + i)->x;
				ycor = (battleships + i)->y;
				for (k = 0; k < f; k++){
					if ((*(*(battlezonehiden + (xcor + k)) + ycor)) != '0'){
						full = 1;
					}
					else full = 0;
					if (full == 1){
						k = f;
					}
				}
				if (full == 0){
					for (k = 0; k < f; k++){
						(*(*(battlezonehiden + (xcor + k)) + ycor)) = simbtype;
					}
				}

			}
			if (pos == 1){

				(battleships + i)->x = rand() % n;
				(battleships + i)->y = rand() % (n - ((battleships + i)->lenght - 1));
				xcor = (battleships + i)->x;
				ycor = (battleships + i)->y;
				for (k = 0; k < f; k++){
					if ((*(*(battlezonehiden + xcor) + (ycor + k))) != '0'){
						full = 1;
					}
					else full = 0;
					if (full == 1){
						k = f;
					}
				}

				if (full == 0){
					for (k = 0; k < f; k++){
						(*(*(battlezonehiden + xcor) + (ycor + k))) = simbtype;
					}
				}
			}

		}
		simbtype++;
		f++;
	}
}

void shots(int **battlezone, int **battlezonehiden, int n){
	int i, j;
	int shots = 0;
	int specialbomb = 3;
	int bomboption;
	int successhit;
	int end = 0;
	int xcor, ycor, destroyedships;

	printf("\n\tLet's start the battle!!\n");

	while (end == 0){

		successhit = 0;
		destroyedships = 0;

		printf("\nWhich bomb do u want to chose: NormalBomb (1), Line Bomb (2): %i on stock\n\tBomb: ", specialbomb);
		scanf_s("%i", &bomboption);

		if (bomboption == 1){
			printf("\nWhere you want to throw the bomb: the number must be between 0 and %i\n\tDistance x: ", (n - 1));
			scanf_s("%i", &ycor);
			printf("\tDistance y: ");
			scanf_s("%i", &xcor);

			while ((ycor > (n - 1)) || (xcor > (n - 1))){
				printf("\nWhy you wanna throw it outside the battlefield? Chose Distance again:\n\tDistance x: ");
				scanf_s("%i", &ycor);
				printf("\tDistance y: ");
				scanf_s("%i", &xcor);
			}

			if ((*(*(battlezonehiden + xcor) + ycor)) == '0'){
				(*(*(battlezone + xcor) + ycor)) = '0';
				printf("Miss!! :(");
			}
			else {
				(*(*(battlezone + xcor) + ycor)) = (*(*(battlezonehiden + xcor) + ycor));
				successhit++;
			}
		}

		else if ((bomboption == 2) && (specialbomb >= 1)){
			printf("\nWhere you want to throw the bomb: the number must be between 0 and %i\n\tDistance x: ", (n-1));
			scanf_s("%i", &ycor);
			printf("\tDistance y: ");
			scanf_s("%i", &xcor);

			while ((ycor > (n - 1)) || (xcor > (n - 1))){
				printf("\nWhy you wanna throw it outside the battlefield? Chose Distance again:\n\tDistance x: ");
				scanf_s("%i", &ycor);
				printf("\tDistance y: ");
				scanf_s("%i", &xcor);
			}

			for (i = 0; i < n; i++){
				if ((*(*(battlezonehiden + i) + ycor)) == '0'){
					(*(*(battlezone + i) + ycor)) = '0';
				}
				else {
					(*(*(battlezone + i) + ycor)) = (*(*(battlezonehiden + i) + ycor));
					successhit++;
				}
			}
			for (i = 0; i < n; i++){
				if ((*(*(battlezonehiden + xcor) + i)) == '0'){
					(*(*(battlezone + xcor) + i)) = '0';
				}
				else {
					(*(*(battlezone + xcor) + i)) = (*(*(battlezonehiden + xcor) + i));
					successhit++;
				}

			}
			specialbomb--;
		}
		else if ((bomboption == 2) && (specialbomb == 0)){
			printf("\nYou dont have enouoght special bombs\n");
			shots--;
		}

		for (i = 0; i < n; i++){
			for (j = 0; j < n; j++){
				if (((*(*(battlezone + i) + j)) != ('-')) && ((*(*(battlezone + i) + j)) != ('0'))){
					destroyedships += 1;
				}
			}
		}
		if (destroyedships == 10){
			printmap(battlezone, battlezonehiden, n);
			printf("\n\tSuccess Hit!!\n");
			shots++;
			printf("\nNumber of destroyed ships: %i\n", destroyedships);
			printf("\nNumber of bombs throun: %i\n", shots);
			printf("\n\tYou have won the battle!!\n\n");
			end = 1;
		}
		if (destroyedships != 10){
			printmap(battlezone, battlezonehiden, n);
			if (successhit > 0){
				printf("\n\tSuccess Hit!!\n");
			}
		}
		shots++;
		if (shots == 30){
			printf("\nNumber of destroyed ships: %i\n", destroyedships);
			printf("\nNumber of ships remaining: %i\n", (10-destroyedships));
			printf("\nNumber of bombs throun: %i\n", shots);
			printf("\nYou have lost this time...\n\n");
			end = 1;
		}
	}
}

void printmap(int **battlezone, int **battlezonehiden, int n){
	int i = 0, j = 0;
	printf("\nBattlefield\n");
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			printf(" %c", (*(*(battlezone + i) + j)));
		}
		printf("\n");
	}
}