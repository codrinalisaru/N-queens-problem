#include <stdio.h>

#define N 8
#define MAX_SOLUTIONS 6

int tabla[N][N];
int generatedSolutions = 0;

bool pozitieValida(int linie, int col) { //verifica daca mai sunt alte regine pe aceasta coloana, sau pe diagonale
	for (int i = 0; i < linie; i++) {
		if (tabla[i][col] == 1) {
			return false;
		}
	}
	//diag stanga
	for (int i = linie - 1,  j = col - 1; (i >= 0) && (j >= 0); i--, j--) {
		if (tabla[i][j] == 1) {
			return false;
		}
	}
	//diag dreapta
	for (int i = linie - 1, j = col + 1; (i >= 0) && (j < N); i--, j++) {
		if (tabla[i][j] == 1) {
			return false;
		}
	}

	return true;
}

void printSolution() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d", tabla[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void queens(int linie) {
	if (linie == N) {
		printSolution();
		generatedSolutions++;
		return;
	}

	for (int col = 0; col < N; col++) { //coloana unde incercam sa punem regina
		if (pozitieValida(linie, col)) {
			tabla[linie][col] = 1;
			queens(linie + 1);
			if (generatedSolutions == MAX_SOLUTIONS) return;
			tabla[linie][col] = 0;
		}
	}
}

int main() {
	queens(0);
	getchar();
	return 0;
}

