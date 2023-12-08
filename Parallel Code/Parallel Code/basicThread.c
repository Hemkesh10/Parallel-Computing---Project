#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vars_defs_functions.h"

// "Child" Thread Function
void *basicThread(void *param)
{





    long thread_no = (long) param;  
    printf("in a thread %ld \n", thread_no);



    int day=0;
    int row=0;
    int col=0;

    int segment_each_thread = ROWS / NUMTHREADS;  
    int start = thread_no * segment_each_thread;  
    int end = (thread_no + 1) * segment_each_thread;
    end = end-1;

    printf("-------------\n");
    printf("start %i \n", start);
    printf("end %i \n", end);
    printf("-------------\n");

   


    for(day=1; day <= TOTAL_DAYS; day++){ // main day loop

            printf("looping new day...\n");


        
                // setting start and end positions in array
                for(row=start; row<end; row++){
                        for(col=0; col<COLS; col++){
                          // what is the current cell


                          switch(current[row][col].state){
                            
                          case 'F':
                          
                            //int num_Burning_Neighbours = countBurningNeighbours_ClosedBoundaries(row, col);
                            
                            decide_F_to_B(row, col, 4);


                            break;

                            
                            case 'B':
                                  
                          
                            decide_B_to_X_VaryingDays(row, col);

                            break;
	  
	                        }//switch
                        
          } //for
  } //for



           int i=0;
           int j=0;
           pthread_mutex_lock(&mutex); 
            //Overwrite the current world with the future world
            printf("saving future to current..\n");
            for(i=start; i<end; i++){
              for(j=0; j<COLS; j++) {
                current[i][j] = future[i][j];
              }
            }

           
          pthread_mutex_unlock(&mutex); 


} // end main day loop ---------------------



 






    return 0;
}

