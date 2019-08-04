#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <ctime>


void after_vecs(int NN2,float *xx,float *yy,float *xx_after,float *yy_after,float new_xx[][2000],float new_yy[][2000],int j, int l)
{
	for(int i=0;i<NN2;i++)
	{
	xx_after[i]=xx[i];

	yy_after[i]=yy[i];
	}
	
	xx_after[j]=new_xx[j][l];
	yy_after[j]=new_yy[j][l];
	
}
