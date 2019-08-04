#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>


void init_vecloop(int NN2,int thermalaver,float vecloopx[][2000],float vecloopy[][2000],float hphih,float hthetah)
{
	for(int j=0;j<thermalaver;j++)
	{
		for(int i=0;i<NN2;i++)
		{
			vecloopx[i][j] = hphih;
			vecloopy[i][j] = hthetah;		
		
		}
	}
	
	
	
}
