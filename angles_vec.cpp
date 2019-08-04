#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>


void angles_vecs(int NN2,float x_ang[][500],float y_ang[][500],float *x_coord,float *y_coord,float *z_coord)
{
	
	
	
//	cout << 1 << endl;

	float innerproduct;
	float dist1,dist2;
//	float new_vec[NN2];
	float distnewvec;
	float distnewvecplane;
	float angphi;
	float angtheta;
	
	
	
	for (int i=0;i<NN2;i++)
	{
		for (int j=0;j<NN2;j++)
		{
			
			if(i!=j)
			{
				
				innerproduct = x_coord[i]*x_coord[j]+y_coord[i]*y_coord[j];
				dist1 = sqrt(pow(x_coord[i],2)+pow(y_coord[i],2)+pow(z_coord[i],2));
				dist2 = sqrt(pow(x_coord[j],2)+pow(y_coord[j],2)+pow(z_coord[j],2));
				
				distnewvec = sqrt(pow(x_coord[j]-x_coord[i],2)+pow(y_coord[j]-y_coord[i],2)+pow(z_coord[j]-z_coord[i],2));
				distnewvecplane = sqrt(pow(x_coord[j]-x_coord[i],2)+pow(y_coord[j]-y_coord[i],2));
				
				if(distnewvecplane != 0.0)
				{
					angphi = acos((x_coord[j]-x_coord[i])/distnewvecplane);
					angtheta = acos((z_coord[j]-z_coord[i])/distnewvec);
					
				}
				else if(distnewvecplane == 0.0)
				{
					angphi = 0;
					angtheta = 3.1415/2.;//acos((z_coord[j]-z_coord[i])/distnewvecplane);
//					cout << "aqui" << endl;
				}
				x_ang[i][j] = angphi;
				y_ang[i][j] = angtheta;

	
			}

			else if(i==j)
			{
//				x_ang[i][j] = angphi;
//				y_ang[i][j] = angtheta;
				x_ang[i][j] = 0;
				y_ang[i][j] = 0;
				
			}
			
			
		}
	}
//	return ***squarevec;
	
}




