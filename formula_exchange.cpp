#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>


float formula_exchange(float jota,int i, int j,float *xx,float *yy)
{

	float exc_ener;

	exc_ener = -jota*(sin(yy[i])*sin(yy[j])*cos(xx[i]-xx[j])+cos(yy[i])*cos(yy[j]));

	return exc_ener;

}
