#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vars_defs_functions.h"
#include "timer.h"

//Global Variables

//The quantity of F, B, O, X cz
unsigned long int numF; //unsigned means positive number
unsigned long int numB;
unsigned long int numO;
unsigned long int numX;



CELL **current;
CELL **future;


pthread_mutex_t mutex;
pthread_cond_t cond_var;

int main(){
  



  double start, finish, elapsed;

  GET_TIME(start);

  // make some space for the current and future
  current = (CELL**)malloc(ROWS*sizeof(CELL*));
  future = (CELL**)malloc(ROWS*sizeof(CELL*));
  
  for(int i=0; i<ROWS; i++){
    current[i] = (CELL*)malloc(COLS*sizeof(CELL));
    future[i] = (CELL*)malloc(COLS*sizeof(CELL));
  }






  // Initial values for #F, #B, #O, #X have to be zero
  numF = 0;
  numB = 0;
  numO = 0;
  numX = 0;
  
  pthread_mutex_init(&mutex, NULL);














// init the world
int i,j =0;
 for(i=0; i<ROWS; i++){
      // printf("looping rows\n");
    for(j=0; j<COLS; j++){
        //  printf("looping col\n");
      current[i][j].state = 'F';

   
      current[i][j].counter_B_to_X = rand()%(MAX_DAYS_B_TO_X - MIN_DAYS_B_TO_X + 1) + MIN_DAYS_B_TO_X;

      future[i][j] = current[i][j]; 
      
      numF++; // 
    }
  }

 // two random burning fires!
 current[0][0].state = 'B';
 current[9][9].state = 'B';
  
 future[0][0].state = 'B';
 future[9][9].state = 'B';



 





 printf("Total days to loop..%d \n", TOTAL_DAYS);
  // -------------- thread bit -----------------------------------
  long thread;
  pthread_t *thread_handler;
  thread_handler = malloc(NUMTHREADS*sizeof(pthread_t)); //handler space






  // -------------------------------------------------------------
  // Create child threads
  //
  // ------------------------------------------------------------
  for(thread = 0; thread < NUMTHREADS; thread++) {
   pthread_create(&thread_handler[thread], NULL, &basicThread, (void *) thread);
  }




  // -------------------------------------------------------------
  // Join the threads threads
  //
  // ------------------------------------------------------------

  for(thread = 0; thread < NUMTHREADS; thread++){
   pthread_join(thread_handler[thread], NULL);
  }




 // clean up
 free(thread_handler);
 pthread_mutex_destroy(&mutex);




  

printf("Final output........\n");
for(int i=0; i<ROWS; i++){ 
    for(int j=0; j<COLS; j++){
      printf(" %c ", current[i][j].state);
 

    }

    printf("\n");

}

  
 

 




  // get the final time and subtract to get the total time
  GET_TIME(finish);
  elapsed = finish - start;
  printf("Total time = %lf\n\n", elapsed);

  return 0;
}
