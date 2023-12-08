//
// Global Variables and Definitions
//  vars_and_defs.h

#include <pthread.h>
#ifndef VARS_AND_DEFS
#define VARS_AND_DEFS




#define ROWS 10
#define COLS 10



//Cell Datatype-definition
typedef struct cell {
  
  char state; // state can be one of: F for Fuel, B for Burning, O for Not Fuel, X for Burnt
  
  int counter_B_to_X; // Counter used to determine when a Burning cell gets changed to Burnt
  
} CELL;



extern CELL **current;
extern CELL **future;


#define DEBUG_LEVEL 1
#define TOTAL_DAYS 10
#define NUMTHREADS 1

//Probabilities for transition
#define PROB_F_TO_B_1 0.50
#define PROB_F_TO_B_2 0.6
#define PROB_F_TO_B_3 0.7
#define PROB_F_TO_B_4 0.75
#define PROB_F_TO_B_5 0.8
#define PROB_F_TO_B_6 0.85
#define PROB_F_TO_B_7 0.9
#define PROB_F_TO_B_8 1.0


#define MIN_DAYS_B_TO_X 1
#define MAX_DAYS_B_TO_X 2







// for the locks
extern pthread_mutex_t mutex;
extern pthread_cond_t cond_var;



//Global Variables.
extern unsigned long int numF; 
extern unsigned long int numB;
extern unsigned long int numO;
extern unsigned long int numX;












//Function Prototypes
void *basicThread(void *param);
void initialiseWorld();


void decide_F_to_B(int row,
		   int col,
		   int num_Burning_Neighbours);



void decide_B_to_X_VaryingDays(int row,
		   int col);

int countBurningNeighbours_ClosedBoundaries(int row,
			    int col);



#endif
