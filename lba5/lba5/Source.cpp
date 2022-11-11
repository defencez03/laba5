//Выполнили студенты группы 21ВВ3: Тюкалов В.Е. и Чинов Д.Д.
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N = 0;
	char c = 0;
	int* countColI,* countColJ;
	int countCol = 0, count = 0;
	int** Matrix,** MatrixI;

	printf("Введите размер матрицы: ");
	scanf_s("%d", &N);
	Matrix = (int**)malloc(N * sizeof(int*));
	for (int i = 0; i < N; i++) {
		Matrix[i] = (int*)malloc(N * sizeof(int));
	}

	for (int i = N; i > 0; i--) {
		count = count + i;
	}

	countColI = (int*)malloc(count * sizeof(int));
	countColJ = (int*)malloc(count * sizeof(int));
	count = 0;

	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			if (i == j) Matrix[i][j] = 0;
			else {
				Matrix[i][j] = rand() % 2;
				if (Matrix[i][j] == 1) {
					countColI[countCol] = i;
					countColJ[countCol] = j;
					countCol++;
				}
				Matrix[j][i] = Matrix[i][j];
			}
		}
	}

	printf("\n Матрица смежности\n");
	printf("\n   ");
	for (int i = 0; i < N; i++) {
		printf("  %c", (i + 97));
	}
	//printf("\n     a  b  c  d  e\n");
	printf("\n    _______________\n");
	for (int i = 0; i < N; i++) {
		printf(" %c | ", (i + 97));
		for (int j = 0; j < N; j++) {
			printf("%d  ", Matrix[i][j]);
		}
		printf("\n");
	}
	
	printf("\n Размер графа: %d\n\n", countCol);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (Matrix[i][j] == 1) count++;
		}
		if (count == 0) printf(" %c - изолированная\n", (i + 97));
		else if (count == 1) printf(" %c - конечная\n", (i + 97));
		else if (count == N - 1) printf(" %c - доминирующая\n", (i + 97));
		count = 0;
	}

	MatrixI = (int**)malloc(countCol * sizeof(int*));
	for (int i = 0; i < countCol; i++) {
		MatrixI[i] = (int*)malloc(N * sizeof(int));
	}

	printf("\n Матрица инцидентности\n");
	printf("\n     ");
	for (int i = 0; i < N; i++) {
		printf("  %c", (i + 97));
	}
	//printf("\n       a  b  c  d  e\n");
	printf("\n      _______________\n");
	for (int i = 0; i < countCol; i++) {
		printf(" %c-%c | ", (countColI[i] + 97), (countColJ[i] + 97));
		for (int j = 0; j < N; j++) {
			if (countColI[i] == j || countColJ[i] == j) {
				MatrixI[i][j] = 1;
				printf("1  ");
			}
			else {
				MatrixI[i][j] = 0;
				printf("0  ");
			}
		}
		printf("\n");
	}

	printf("\n");
	count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < countCol; j++) {
			if (MatrixI[j][i] == 1) count++;
		}
		if (count == 0) printf(" %c - изолированная\n", (i + 97));
		else if (count == 1) printf(" %c - конечная\n", (i + 97));
		else if (count == N - 1) printf(" %c - доминирующая\n", (i + 97));
		count = 0;
	}

	return 0;
}