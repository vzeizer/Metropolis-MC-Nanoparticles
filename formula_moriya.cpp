#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>

float formula_moriya(float m,int i, int j,float *xx,float *yy)
{
	
	float ener_mor;
	
	// vectorial product with k^ versor !
	ener_mor = m*(cos(xx[i])*sin(xx[j])*sin(yy[i])*sin(yy[j])-cos(xx[j])*sin(xx[i])*sin(yy[i])*sin(yy[j]));

	// vectorial product with i^ versor !
//	ener_mor = m*(cos(yy[j])*sin(xx[i])*sin(yy[i])-cos(yy[i])*sin(xx[j])*sin(yy[j]));
	
	// vectorial product with j^ versor !
//	ener_mor = m*(cos(xx[j])*cos(yy[i])*sin(yy[j])-cos(xx[i])*cos(yy[j])*sin(yy[i]));

	return ener_mor;

}

