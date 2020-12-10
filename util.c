#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void wait ( double seconds ) {
	clock_t endwait;
	endwait = clock () + seconds * CLOCKS_PER_SEC ;
	while (clock() < endwait) {}
}

void PRINT ( int **A, int ROW, int COL) {
	int i, j;
	printf ("\n\n");
	printf ("\t\t\t____________");
	for (i=1; i<ROW+1;i++) {
		printf ("___");
	}
	for (i=1; i<ROW+1; i++) {
		printf ("\n\t\t\t|");
		for (j=1; j<COL+1; j++) {
			if (A[i][j] == 0) {
				printf ("  ");
			} else if (A[i][j] == 1) {
				printf ("O ");
				}
				else {
					printf ("X ");
				}
		}
		printf ("|");
	}
	printf ("\n\t\t\t************");
	for (i=1; i<ROW+1; i++) {
		printf ("***");
	}
	printf ("\n\n\n\n\n\n");
}

int ask_happiness (int **GRID, int i, int j, double preference, int ROW, int COL) {
		int z, k, sim=-1, diff=0, total;
		int answer;
		double perc;
		for (z=i-1; z<= i+1; z++) {
			for (k=j-1; k<= j+1; k++) {
				if (GRID[i][j] == GRID[z][k]) {
					sim += 1;
				} else if (GRID[i][j] != GRID[z][k] && GRID[z][k] != 0 && GRID[z][k] != 3) {
					diff += 1;
				}
			}
		}
		total = sim + diff;
		if (total != 0) {
			perc = ( (double) sim/total)*100;
		} else {
			perc = 0;
		}
		if (perc > preference) {
			answer = 0;
		} else {
			answer = 1;
		}
		return answer;
}

void move (int **GRID,int i,int j, int ROW, int COL) {
		int z=0, k=0, temp;
		while (GRID[z][k] != 0) {
			z = (int) (rand()%ROW) +1;
			k = (int) (rand()%COL) +1;
		}
		temp = GRID[i][j];
		GRID[i][j] = GRID[z][k];
		GRID[z][k] = temp;
}

void populate (int **GRID, int N1, int N2, int ROW, int COL) {
	int i, j;
	for (i=1; i<ROW+1; i++) {
		for (j=1; j<COL+1; j++) {
			if (N1 != 0) {
				GRID[i][j] = 1;
				N1--;
			} else if (N2 !=0) {
				GRID[i][j] = 2;
				N2--;
			} else {
				GRID[i][j] = 0;
			}
		}	
	}
		for (j=0; j<COL+2; j++) {
			GRID[0][j] = 3;
			GRID[ROW+1][j] = 3;
		}
		for (i=0; i<ROW+2; i++) {
			GRID[i][0] = 3;
			GRID[i][COL+1] = 3;
		}
}

void mixup (int **GRID, int ROW, int COL) {
	int i, j, k, z, s, temp;
	srand(time(0));
	for (k=0; k<100; k++) {
		for (i=1; i<ROW+1; i++) {
			for (j=1; j<COL+1; j++) {
				z = (int) (rand()%ROW) +1;
				s = (int) (rand()%COL) +1;
				temp = GRID[i][j];
				GRID[i][j] = GRID[z][s];
				GRID[z][s] = temp;
			}
		}
	}
}

void FPRINT ( int **A, int ROW, int COL) {
	int i, j;
	FILE *fout;
	fout = fopen ("simulation_data.dat","a");
	fprintf (fout,"____________");
	for (i=1; i<ROW+1;i++) {
		fprintf (fout,"___");
	}
	for (i=1; i<ROW+1; i++) {
		fprintf (fout,"\n|");
		for (j=1; j<COL+1; j++) {
			if (A[i][j] == 0) {
				fprintf (fout,"  ");
			} else if (A[i][j] == 1) {
				fprintf (fout,"X ");
				}
				else {
					fprintf (fout,"0 ");
				}
		}
		fprintf (fout,"|");
	}
	fprintf (fout,"\n");
	fprintf (fout,"************");
	for (i=1; i<ROW+1; i++) {
		fprintf (fout,"***");
	}
	fprintf (fout,"\n\n\n");
	fclose(fout);
}

void bar_chart (int sum, int h){
        int c;
        for (c=0; c<= h; c++){
                FILE *fout;
                fout = fopen ("simulation_data.dat","a");
                fprintf(fout,"O");
                if ( c == h) {
                        fprintf(fout," | %d\n", sum);
                }
        fclose(fout);
        }
}

