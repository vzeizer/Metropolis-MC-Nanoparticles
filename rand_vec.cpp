#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>
//#include <stdio.h>      /* printf, scanf, puts, NULL */
//#include <stdlib.h>     /* srand, rand */
//#include <time.h>       /* time */
#include <cstdlib>
#include <ctime>





void rand_vec(float solid_cone,int NN2,int thermalaver,float *xx,float *yy,float new_xx[][2000],float new_yy[][2000],float vecloopx[][2000],float vecloopy[][2000])
{
	

float deltavecx;
float deltavecy;


for(int l=0;l<thermalaver;l++)
{

	for(int i=0;i<NN2;i++)
	{
	
	float r2 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/2.));
	deltavecx=solid_cone*(r2-1);
	float r3 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/2.));
	deltavecy=solid_cone*(r3-1);
//	cout << (r2-1)-(r3-1)<<endl;
	new_xx[i][l] = vecloopx[i][l] + deltavecx;
	new_yy[i][l] = vecloopy[i][l] + deltavecy;
	
	
	}

}	
	
}
