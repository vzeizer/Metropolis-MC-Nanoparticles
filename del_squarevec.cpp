
#include <iostream>
#include <math.h>
/*#include "main_metropolis_2D.h"*/
#include <cmath>
#include <stdlib.h>


void delete_alloc(float ***A, int NN1)
{

//	int NN1 =pow(NN,1/3); 

// deleting allocated memory

//	for( int i = 0 ; i < NN1 ; i++ )
//	{
//	delete [] A[i] ;
//	}

//	delete [] A;


for(int i=0;i<NN1;i++) {
  for(int j=0;j<NN1;j++) {
    delete [] A[i][j];
  }
  delete [] A[i];
}
delete [] A;


}
