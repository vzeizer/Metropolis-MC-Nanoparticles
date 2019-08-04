#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>


void creating_pos(int NN2,float *x_coord,float *y_coord, float *z_coord, char* np_order, int NN)
{
/*	
	for(int i=0;i<NN1;i++)
	{
//		squarevec[i]=float(i);

		for(int j=0;j<NN1;j++)
			{

//			squarevec[i][j]=float(j);
		
			for(int k=0;k<NN1;k++)
			{
			
				squarevec[i][j][k]=i+j;
	
			}
	
		}
			
	}


	return ***squarevec;
*/

 // Setting the coordinates for each structure!!

float pi = 3.1415;
int NNaux=ceil(pow(NN,0.666666));

int NN2root=ceil(pow(NN2,0.5));


if(np_order == (char*)"square")
{
	// aqui abaixo está errado!
	for(int i=0; i<NN2root;i++)
	{
		for(int j=0;j<NN2root;j++)
		{
			x_coord[j+i*NN2root] = i;
			y_coord[j+i*NN2root] = j;
			z_coord[j+i*NN2root] = 0.;
		}
	}
}
else if(np_order == (char*)"ring")
{
	for(int i=0; i<NN2;i++)
	{
		x_coord[i] = cos(2*pi*i/NN2);
		y_coord[i] = sin(2*pi*i/NN2);
		z_coord[i] = 0.;
	}
}

else if(np_order == (char*)"nanomembrane")
{
	for(int j=0;j<int(NN/NNaux);j++)
	{
		for(int i=0; i<NNaux;i++)
		{
			x_coord[i+j*NNaux] = cos(2*pi*i/NNaux);
			y_coord[i+j*NNaux] = j;
			z_coord[i+j*NNaux] = sin(2*pi*i/NNaux);

//			cout << i+j*NNaux << endl;

		}
	}
}

else if(np_order == (char*)"half_nanomembrane")
{
	for(int j=0;j<int(NN/NNaux);j++)
	{
		for(int i=0; i<NNaux;i++)
		{
			x_coord[i+j*NNaux] = cos(-pi/2.+1*pi*i/NNaux);
			y_coord[i+j*NNaux] = j;
			z_coord[i+j*NNaux] = sin(-pi/2.+1*pi*i/NNaux);

//			cout << i+j*NNaux << endl;

		}
	}

}


}



