#include <stdio.h>

#include "vars_defs_functions.h"
#include <pthread.h>
// Child Thread function
void *basicThread(void *param)
{
    
    long thread_no = (long) param;
    printf("in a thread %ld \n", thread_no);

    CELL current[ROWS][COLS];
    CELL future[ROWS][COLS];
    
    initialiseWorld(current, future);
    
    int day = 0;
    int row = 0;
    int col = 0;
    
    
    int segement_each_thread = ROWS / NUMTHREADS;
    int start = thread_no * segement_each_thread;
    int end = (thread_no + 1) * segement_each_thread;
    
    printf("------------\n");
    printf("start %i \n", start);
    printf("end %i \n", end);
    printf("------------\n");
    
    
    
       // looping for 40 days
  for(day=1; day <= TOTAL_DAYS; day++){ // 40 days
printf("in day loop");
  
        // looping over the 2-D grid for each simulations
        for(row=start; row<end; row++){
          for(col=0; col<COLS; col++){
	int num=0;
                            // whats is the current cell state?
                          switch(current[row][col].state){
                            
                          case 'F':
                            num = countBurningNeighbours_ClosedBoundaries(row, col, current);
                            
                            decide_F_to_B(row, col, num, future);
                            break;

                            
                          case 'B':
                                  
                            
                          
                            decide_B_to_X_VaryingDays(row, col, current, future);

                            break;
	  
	                       }//switch
      } // cols
    }// rows
    
    
    
    int i = 0;
    int j = 0;
    
    
    for(i = start; i <end; i++){
        for(j = 0 ; j<COLS; j++){
            current[i][j] = future[i][j];
        }
        
    }

    
    
    
  }//days
return 0; 

}














