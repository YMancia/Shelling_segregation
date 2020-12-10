#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "util.h"

#define ROW 30
#define COL 50
#define N 1000000

int main() {
	int i, j, k, z, s, temp, sum, h ,c , w, nticks = 0;
	int N1, N2, empty, preference, answer;
	int **GRID;
	double rapp, speed;
	FILE *fdata, *fout;
        
         printf ("\n\t\t\t\t\t\tSIMULATION OF SCHELLING'S SEGREGATION MODEL\n\n--This program reproduces the evolution of Schelling's    segregation model, returning a file (simulation_data.dat) with the principal data of the simulation--\n\n-->Press 'enter' to start it ");
        getchar();
        fout = fopen ("simulation_data.dat","w");
        fprintf(fout,"\t\t\tFINAL SIMULATION DATA:\n\n");
	fdata = fopen ("simulation_data2.dat", "w");
	fprintf (fdata, "Ticks\tUnhappy elements:\n");
	
	
	/*prende in input le condizioni iniziali del sistema e calcola il numero di elementi per famiglia e gli spazi vuoti*/
	printf ("\nInsert percentage of empty space: ");
	scanf ("%d", &empty);

        fprintf(fout,"Percentage of empty space: %d o/o \n",empty);
        
	
	printf ("Insert ratio between the population (white/black): ");
	scanf ("%lf", &rapp);
	printf ("Insert percentage of similar neighbors' preference: ");
	scanf ("%d", &preference);
	printf ("Insert speed of simulation (between 1 and 10): ");
	scanf ("%lf", &speed);
	speed = 1/speed; 
	empty = ROW*COL*empty/100;
	N1 = (ROW*COL-empty)/(rapp+1);
	N2 = ROW*COL-empty-N1;
	
        fprintf(fout,"Ratio between the populations: %lf\n",rapp);
	fprintf(fout,"Percentage of preference of similar neighbors: %d o/o\n",preference);
	fprintf(fout,"Number of black elements: %d\nNumber of white elements: %d\nSize of the grid: %dx%d\n\n\t\tSYSTEM'S INITIAL CONDICTION:\n",N1,N2,ROW,COL);
	fclose(fout); /**/
	
	/*alloca e popola la matrice-griglia secondo i parametri iniziali, successivamente mescola gli elementi in modo random*/	
	GRID = (int **) malloc ((ROW+2)*sizeof(int *));
	for (i=0; i<ROW+2; i++) {
		GRID[i] = (int *) malloc ((COL+2)*sizeof(int));
	}
	populate ( GRID, N1, N2, ROW, COL);
	PRINT ( GRID, ROW, COL);
	srand(time(0));
	mixup (GRID, ROW, COL);
	PRINT ( GRID, ROW, COL);
	
        FPRINT ( GRID, ROW, COL);
	
	/*verifica la "felicita'" di ogni elemento, e se inferiore alla preferenza lo sposta in uno spazio vuoto random, il programma termina 		quando ogni elemento della griglia e' felice*/
        
        fout = fopen("simulation_data.dat","a");
	fprintf(fout,"\t\t\tBAR CHART OF SYSTEM'S EVOLUTION:\n\nNumber of unhappy elements: \n");
	fclose(fout);
	for (z=0; z<N; z++) {
		wait ( speed);
		sum = 0;
		
		for (i=1; i<ROW+1; i++) {
			for (j=1; j<COL+1;j++) {
				if (GRID[i][j] != 0) {
					answer = ask_happiness ( GRID, i, j, preference, ROW, COL);
					if (answer == 1) {
						move ( GRID, i, j, ROW, COL);
					} 
				}
				sum += answer;
			}
		}
		printf ("Ticks: %d\nUnhappy elements : %d\n",z, sum);
		if (z >= 500) {
			printf ("WARNING: simulation parameters could not allow a stable grid\n");
			z = N;
			fout = fopen ("simulation_data.dat","a");
			fprintf (fout,"\nWARNING\nThe solving process is too long\nthe simulation has stopped before the system reached a stable state\n\nLast tick:\n");
			fclose (fout);
		}
		nticks = nticks +1;
		fprintf (fdata, "%d\t%d\n", nticks, sum);
		h = (int) sum/15;
		bar_chart (sum, h);
		PRINT ( GRID, ROW, COL);
		if (sum == 0) {
			z = N;
		}
	}
	fout = fopen("simulation_data.dat","a");
	fprintf(fout,"\nTicks of the simulation: %d\n\n\t\t\tSYSTEM'S FINAL CONDICTION:\n",nticks);
	fclose (fout);
	fclose (fdata);
	FPRINT ( GRID, ROW, COL);
}

