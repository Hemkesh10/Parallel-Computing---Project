#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "timer.h"
#include "vars_defs_functions.h"
#include <pthread.h>
//Global Variables

//The quantity of F, B, O, X cz
unsigned long int numF; //unsigned means positive number
unsigned long int numB;
unsigned long int numO;
unsigned long int numX;



void *basicThread(void *param);


int main(){
  

  
  double start, finish, elapsed;

  GET_TIME(start);




  // Initial values for #F, #B, #O, #X have to be zero
  numF = 0;
  numB = 0;
  numO = 0;
  numX = 0;
  
  


  CELL current[ROWS][COLS]; // 2-Dim array for current world
  CELL future[ROWS][COLS]; // 2-Dim array for future world
  







  //int day = 0; //Current day
  //int i, j;
  //int row, col;
  //int num_Burning_Neighbours;








  // Generate random seed
  srand((unsigned int)time(NULL));

  // Create the initial world and give each cell a state
//  initialiseWorld(current, future);


  // Output the day, #F, #B, #O, #X to file
  //outputDayFBOX(fp_DayFBOX, day);

  // Output the day and the 2-dim array of the current world
  //outputWorld(day, current);
  



 
 

  printf("total days to loop..%d", TOTAL_DAYS);
  // -------------- thread bit -----------------------------------

  long thread;

  // Pthread handler (pointer/array of pthread structures)
  pthread_t *thread_handler;

  // Allocate memory for the child threads
  thread_handler = malloc(NUMTHREADS*sizeof(pthread_t));




  // Create child threads
  for(thread = 0; thread < NUMTHREADS; thread++) {
    pthread_create(&thread_handler[thread], NULL, &basicThread, (void *) thread);
  }



  // The pthread_join() function waits for mythread to complete
  for(thread = 0; thread < NUMTHREADS; thread++) {
    pthread_join(thread_handler[thread], NULL);
  }





  // clean up
  free(thread_handler);
  // ----------------------------------------








  
 

 




  
  GET_TIME(finish);
  elapsed = finish - start;
  printf("Elapsed time = %lf\n\n", elapsed);

  return 0;
}
