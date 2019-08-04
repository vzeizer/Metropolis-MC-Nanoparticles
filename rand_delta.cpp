#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>


float rand_delta(int NN,float *listatheta, char* np_order)
{

	int NNaux = ceil(pow(NN,0.666666));

if(np_order == (char*)"square")
{	
	for(int i=0;i<NN;i++)
		{

			listatheta[i]=0;
			
		}
}	

else if(np_order == (char*)"nanomembrane")
{	

	for(int i=0;i<NN;i++)
		{

			listatheta[i]=2*3.1415*(i%NNaux)/NNaux;
			
		}

}

else if(np_order == (char*)"half_nanomembrane")
{	

	for(int i=0;i<NN;i++)
		{

			listatheta[i] = -3.1415/2.+1*3.1415*(i%NNaux)/NNaux;
			
		}

}


	return *listatheta;
	
}
