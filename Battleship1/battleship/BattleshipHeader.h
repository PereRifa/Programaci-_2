#ifndef FUNCTIONS_H
#define FUNCTIONS_H
typedef struct{

	int lenght;
	int x;
	int y;
	char simbolo;

}Ship;

void battlesize(int**, int**, int);
void datosships(Ship*, int**, int);
void shots(int **, int **, int);
void printmap(int **, int **, int);

#endif FUNCTIONS_H