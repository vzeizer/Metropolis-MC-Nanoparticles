#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>


float formula_dipolar(float beta,int i, int j,float *xx,float *yy,float x_ang[][500],float y_ang[][500])
{
	float dip_ener=0;
	
	dip_ener = -3*beta*(sin(yy[i])*sin(y_ang[i][j])*cos(xx[i]-x_ang[i][j])+cos(yy[i])*cos(y_ang[i][j]))*(sin(yy[j])*sin(y_ang[i][j])*cos(xx[j]-x_ang[i][j])+cos(yy[j])*cos(y_ang[i][j]));
	dip_ener+= beta*(sin(yy[i])*sin(yy[j])*cos(xx[i]-xx[j])+cos(yy[i])*cos(yy[j]));
	return dip_ener;
}







