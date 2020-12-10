
/*funzione che serve a controllare la velocitÃ  della simulazione, negli argomenti vanno inseriti i secondi tra un tick e l'altro*/
void wait ( double );

/*funzione che stampa la griglia, negli argomenti vanno inseriti il puntatore alla griglia, il numero di righe ed il numero di colonne della griglia*/
void PRINT (int** , int , int );
/*stampa la griglia su file*/
void FPRINT (int** , int , int );

/*verifica la "felicitÃ " del singolo elemento a partire dalle posizioni correnti in griglia, gli argomenti sono il puntatore a griglia,l'indice della riga e della colonna dell'elemento da verificare, la preferenza (in percentuale) di vicini simili per considerare un elemento felice, il numero di righe e il numero di colonne della griglia*/
int ask_happiness (int**, int, int, double, int, int);

/*muove gli elementi della griglia che hanno bassa felicitÃ  nello spazio vuoto piÃ¹ vicino, gli argomenti sono il puntatore alla griglia, l'indice di riga e colonna dell'elemento considerato, il numero di righe e il numero di colonne della griglia*/
void move ( int**, int, int, int, int);
 
/*funzione che popola la matrice ordinatamente secondo i parametri inseriti, i gli argomenti sono il puntatore a griglia, il numero di elementi della prima famiglia, il numero di elementi della seconda famiglia, il numero di righe e il numero di colonne della matrice*/
void populate ( int** , int, int, int, int);

/*funzione che mescola in modo casuale gli elementi in griglia, gli argomenti sono il puntatore alla matrice, il numero di righe e il numero di colonne*/ 
void mixup (int** , int, int);
/*fa il grafico a barre del numero di elementi infelici*/
void bar_chart (int, int);
