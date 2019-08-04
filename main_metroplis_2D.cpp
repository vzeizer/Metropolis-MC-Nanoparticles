/*
 *  THIS IS A PROGRAM TO SIMULATE THE METROPOLIS MONTE CARLO
 *  OF INTERACTING MICROSPINS FORMING A NANOSTRUCTURE!
 *  
 *  IN THIS VERSION, WE ARE GOING TO ADDRESS THE 3D CASE!
 * 
 * /
 
 
 
 /* 

 */
  
#include <iostream>
#include <math.h>
#include "main_metropolis_2D.h"
#include <cmath>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <ctime>


#include "vec_square.cpp"
#include "del_squarevec.cpp"
#include "creating_pos.cpp"
#include "rand_delta.cpp"
#include "angles_vec.cpp"
#include "energy_array.cpp"
#include "init_vecloop.cpp"
#include "rand_vec.cpp"
#include "after_vecs.cpp"


//#include <vector>

using namespace std;


int main()
{

	int start_s=clock();
	
// Float Precision Variable accounts for the system accuracy!

// defining the dimensions of the System!
// It is a two-dimensional system!

	int NN=pow(3,3);
	

// Boltzmann's Constant! (erg/K)
	float Kb=1.38*pow(10,-16);
// Volume of the Particle	
// Diameter! (cm)
	float Diam = 60*pow(10,-7);
// Volume! (cm**3)
	float V = pow(Diam,3);
//Temperature when measurement is performed!
//	float Temp = 3*pow(10,2);
	float Temp = 3*pow(10,2);
	
// MAGNETIZATION AND ANISOTROPY CONSTANTS!
	float Ms=1/1000.;
	float Msat=1000.;
	float K1=-4.0*pow(10,3)/(pow(Msat,2));
	float K2=0*pow(10,4)/(pow(Msat,2));
	float Kmeio=0*pow(10,4)/(pow(Msat,2));
	float Kmeio2=0*pow(10,4)/(pow(Msat,2));
	float Kshear=0*pow(10,4)/(pow(Msat,2));
	float K1fielddepen=0*pow(10,2)/(pow(Msat,2));
	float K2fielddepen=0*pow(10,2)/(pow(Msat,2));
	float Knucl=0*pow(10,2)/(pow(Msat,2));
	float Kuni=4.0*pow(10,3)/(pow(Msat,2));
	float Kuni2=0.0*pow(10,4)/(pow(Msat,2));
//	float Kmeio=0*pow(10,4)/(pow(Msat,2));
//	float Kmeio2=0*pow(10,4)/(pow(Msat,2));
	float Krot=0*pow(10,3)/(pow(Msat,2));
	float K2rot=0*pow(10,4)/(pow(Msat,2));
	float Kdiag=0*pow(10,4)/(pow(Msat,2));
	float Kperp=0*pow(10,4)/(pow(Msat,2));
	float K2perp=0*pow(10,4)/(pow(Msat,2));


	// field orientation specifications!
	float pi = 3.14156;
	float tauh= 2.0*pi/4.;
	float thetah = 1*pi/2.;
	float hphih = tauh;
	float hthetah = thetah;
	float expnucl = 1.;
	float solid_cone=pi/8;
	
	// NP's arrangement in the surface!
//	char* nporder = (char*)"square";
	
	// Monte Carlo parameters!!
	int thermalaver = 25*1;

	// controlling the thermalization process!
	int switchonoff =1;


	int NN1 = ceil(pow(NN,0.33333));
	int NN2 = ceil(pow(NN,0.666666));
	  

	// float np_order! What kind of ordering the NPs have?
//	char* np_order= (char*)"nanomembrane";
//	char* np_order = (char*)"half_nanomembrane";
	char* np_order = (char*)"square";

	if(np_order ==  (char*)"nanomembrane" or np_order == (char*)"half_nanomembrane")
	{
		
		NN2=NN;
	}

	// Strength of the interactions!!!!
	
	// dipolar Interaction
	float beta = 0.00;

	// Exchange Interaction
	float jota = 0.000;

	float vizparj = 1;
	float vizperpj = 1;
	
	// DMI Interaction
	float m = 0.0600;

	float hini = 2000.;
	float hfinal = -2000.;
	int step = 2*400;

	float hpasso = (hfinal - hini)/step;

// calling the functions to perform the Calculations!!

//	float **squarevec= new float*[NN1];


//	float ***squarevec = new float**[NN1];

/*	struct vec_coord
	{
		float x_coord;
		float y_coord;
		float z_coord;		

	};

	vec_coord vec_square[NN];

*/

//		}vec_coord[NN];

	float x_coord[NN2];
	float y_coord[NN2];
	float z_coord[NN2];		

	square_vec_2d(NN2,x_coord,y_coord,z_coord);


//	cout << squarevec[0][0][0] <<'\n'<<endl;


//	creating_pos(squarevec,NN1);
	creating_pos(NN2,x_coord,y_coord, z_coord, np_order, NN);
//	cout << NN1 << '\n' << squarevec[2][2][2] <<'\n'<<endl;

	cout << x_coord[2] << y_coord[1] << endl;

	float listatheta[NN2];
		
	rand_delta(NN2,listatheta,np_order);
	
	cout << NN1 << '\n' << listatheta[2] << "delta" <<'\n'<<endl;


	float x_ang[500][500];
	float y_ang[500][500];

//		angles_vecs(squarevec,NN2,x_ang,y_ang);
	angles_vecs(NN2,x_ang,y_ang,x_coord,y_coord,z_coord);

	cout << "x ang" <<x_ang[1][2] <<endl;

	float energy_vec[NN2];
	float xx[NN2];
	float yy[NN2];
	float H=hini;
	
//	energy_array(NN2,energy_vec,x_ang,y_ang,xx,yy,Ms,Msat,K1,K2,Kmeio,Kmeio2,Kshear,K1fielddepen,K2fielddepen,Knucl,Kuni,Kuni2,Krot,K2rot,Kdiag,Kperp,K2perp,hphih,hthetah,expnucl,H);

//	cout << energy_vec[1]  << endl;

	float magnewpostrue[NN2];
	float new_xx[NN2][2000];
	float new_yy[NN2][2000];
	float vecloopx[NN2][2000];
	float vecloopy[NN2][2000];

	float vecloopxaux[NN2][2000];
	float vecloopyaux[NN2][2000];



	init_vecloop(NN2,thermalaver,vecloopxaux,vecloopyaux,hphih,hthetah);

//	cout << "vecloop" << vecloopx[1][1]<< endl;

//	srand(time(NULL));

	srand (static_cast <unsigned> (time(0)));

	float energybefore[NN2][thermalaver];
	float energyafter[NN2][thermalaver];
	
	float energytest[NN2];

	float xx_after[NN2];
	float yy_after[NN2];
	float finalhyst[step];
	float soma_mm;
	float soma_ener;
	float delta_ang_anis;

	for(int i=0;i< NN2;i++)
	{

	xx[i] = hphih;
	yy[i] = hthetah;
	magnewpostrue[i]=0;
	}

	ofstream myfile;
	myfile.open ("/home/vagner/Desktop/Metropolis_MC_magnetics/hystMCM_cpp.dat");

	
/*
	for(int l=0;l<thermalaver;l++)
	{

			for(int i=0;i<NN2;i++)
			{			
				
				cout<< vecloopx[i][l] << vecloopy[i][l]<<endl;

			}
	}

*/

	for(int k=0;k<step;k++)
	{
//	cout<< k<<" k"<<endl;
	for(int l=0;l<thermalaver;l++)
	{

			for(int i=0;i<NN2;i++)
			{			

			vecloopx[i][l] = vecloopxaux[i][l];
			vecloopy[i][l] = vecloopyaux[i][l];
			}
	}


	for(int l=0;l<thermalaver;l++)
	{

			for(int i=0;i<NN2;i++)
			{			

			new_xx[i][l] = 0.;
			new_yy[i][l] = 0.;

			}

	}


	rand_vec(solid_cone,NN2,thermalaver,xx,yy,new_xx,new_yy,vecloopxaux,vecloopyaux);

	for(int l=0;l<thermalaver;l++)
	{

			for(int i=0;i<NN2;i++)
			{			

			vecloopxaux[i][l]=0;
			vecloopyaux[i][l]=0;

				
//				cout<< new_xx[i][l] << new_yy[i][l]<<endl;

			}
	}

/*
	for(int l=0;l<thermalaver;l++)
	{

			for(int i=0;i<NN2;i++)
			{			
				
				cout<< new_xx[i][l] << new_yy[i][l]<<endl;

			}
	}
*/

/*
	for(int l=0;l<thermalaver;l++)
	{

			for(int i=0;i<NN2;i++)
			{			
				
				cout<< vecloopx[i][l] << vecloopy[i][l]<<endl;

			}
	}
*/

//	energy_array(NN2,energybefore,x_ang,y_ang,vecloopx,vecloopy,Ms,Msat,K1,K2,Kmeio,Kmeio2,Kshear,K1fielddepen,K2fielddepen,Knucl,Kuni,Kuni2,Krot,K2rot,Kdiag,Kperp,K2perp,hphih,hthetah,expnucl,H);
	
	
//	cout << H << endl;

	for(int l=0;l<thermalaver;l++)
	{

			for(int i=0;i<NN2;i++)
			{
				// passo anterior
				xx[i]=vecloopx[i][l];
				yy[i]=vecloopy[i][l];
				
//				cout<< xx[i] << yy[i]<<endl;
//				cout<< vecloopx[i][l] << vecloopy[i][l]<<endl;
			}


			for(int j=0;j<NN2;j++)
			{
				
//			delta_ang_anis = listatheta[j];

			energy_array(NN2,NN,energytest,x_ang,y_ang,xx,yy,Ms,Msat,K1,K2,Kmeio,Kmeio2,Kshear,K1fielddepen,K2fielddepen,Knucl,Kuni,Kuni2,Krot,K2rot,Kdiag,Kperp,K2perp,hphih,hthetah,expnucl,H,beta,jota,m,vizparj,vizperpj, np_order,listatheta);

			soma_ener =0.;
			
			for(int i=0;i<NN2;i++)
			{
				soma_ener+=energytest[i];
			}
			
//			energybefore[j][l] = energytest[j];
			energybefore[j][l] = soma_ener;


			for(int i=0;i<NN2;i++)
			{
				energytest[i]=0;
				
			}

			// function to change the position of single spin modification

			after_vecs(NN2,xx,yy,xx_after,yy_after,new_xx,new_yy,j,l);

			energy_array(NN2,NN,energytest,x_ang,y_ang,xx_after,yy_after,Ms,Msat,K1,K2,Kmeio,Kmeio2,Kshear,K1fielddepen,K2fielddepen,Knucl,Kuni,Kuni2,Krot,K2rot,Kdiag,Kperp,K2perp,hphih,hthetah,expnucl,H,beta,jota,m,vizparj,vizperpj, np_order,listatheta);

			soma_ener =0.;
			
			for(int i=0;i<NN2;i++)
			{
				soma_ener+=energytest[i];
//				cout << x_ang[i] << endl;
			}
			
//			energyafter[j][l] = energytest[j];
			energyafter[j][l] = soma_ener;

			if(H<-9)
			{
//			cout << xx_after[j] - xx[j] << endl;
//			cout << energyafter[j][l] - energybefore[j][l] << endl;
//			cout << (energyafter[j][l] - energybefore[j][l])<0 << endl;
			}


			for(int i=0;i<NN2;i++)
			{
				xx_after[i]=0;
				yy_after[i]=0;			
				
			}
		
			for(int i=0;i<NN2;i++)
			{
				energytest[i]=0;
				
			}
		
		
//			cout<< energyafter[j][l] << energybefore[j][l]<<endl;
		
		
			}
	
	}




	for(int l=0;l<thermalaver;l++)
	{
		for(int i=0;i<NN2;i++)
		{
	 		
			if ((energyafter[i][l]-energybefore[i][l])<0)
			{
				if(H<10)
				{
//					cout << vecloopx[i][l]-new_xx[i][l] << endl;
//					cout << vecloopy[i][l]-new_yy[i][l] << endl;
//					cout << (energyafter[i][l]-energybefore[i][l]) << endl;
				}
				
				vecloopxaux[i][l]=new_xx[i][l];
				vecloopyaux[i][l]=new_yy[i][l];
				magnewpostrue[i]=sin(vecloopyaux[i][l])*sin(hthetah)*cos(vecloopxaux[i][l]-hphih)+cos(vecloopyaux[i][l])*cos(hthetah)+magnewpostrue[i];

			}
			else //((energyafter[i][l]-energybefore[i][l])>= 0.0)
			{

				float r4 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX));
//				cout << (energyafter[i][l]-energybefore[i][l])*(V*Msat*Msat)/(Kb*Temp)<< endl;
				if((energyafter[i][l]-energybefore[i][l])*(V*Msat*Msat)/(Kb*Temp)<10.)
				{
					if(r4<pow(2.71,-(energyafter[i][l]-energybefore[i][l])*(V*Msat*Msat)/(Kb*Temp)))
					{
						
						vecloopxaux[i][l]=new_xx[i][l];
						vecloopyaux[i][l]=new_yy[i][l];
						
						magnewpostrue[i]=sin(vecloopyaux[i][l])*sin(hthetah)*cos(vecloopxaux[i][l]-hphih)+cos(vecloopyaux[i][l])*cos(hthetah)+magnewpostrue[i];					
						
					}
					else //if(r4>=pow(2.71,-(energyafter[i][l]-energybefore[i][l])*(V*Msat*Msat)/(Kb*Temp)))
					{
						//nothing happens						
						vecloopxaux[i][l]=vecloopx[i][l];
						vecloopyaux[i][l]=vecloopy[i][l];
						magnewpostrue[i]=sin(vecloopy[i][l])*sin(hthetah)*cos(vecloopx[i][l]-hphih)+cos(vecloopy[i][l])*cos(hthetah)+magnewpostrue[i];						
					}

				}
				else// if((energyafter[i][l]-energybefore[i][l])*(V*Msat*Msat)/(Kb*Temp)>=10.)
				{					
						vecloopxaux[i][l]=vecloopx[i][l];
						vecloopyaux[i][l]=vecloopy[i][l];
						magnewpostrue[i]=sin(vecloopy[i][l])*sin(hthetah)*cos(vecloopx[i][l]-hphih)+cos(vecloopy[i][l])*cos(hthetah)+magnewpostrue[i];	
				}

			
			}

		}
	}



	//finalhyst

	soma_mm=0.0;
	for(int i=0;i<NN2;i++)
	{
		
		soma_mm+=magnewpostrue[i]/float(NN2)/float(thermalaver);
		
	}

//	finalhyst[k]=soma_mm;


//	cout << soma_mm << endl;

	H+=hpasso;

	for(int i=0;i<NN2;i++)
	{
		
		magnewpostrue[i]=0;
		
	}

	//

	//	delete_alloc(squarevec,NN1);

	myfile << H << "\t" << soma_mm << "\n";

			
	}

	int stop_s=clock();
	cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
	
	myfile.close();
	
	
/*
	cout << "\n" << finalhyst[0] << "\n" << finalhyst[1] << finalhyst[2] << endl; 
	cout << finalhyst[100] << endl;
	cout << finalhyst[200] << endl;
	cout << finalhyst[step/2] << endl;
	cout << finalhyst[step-1] << endl;
*/
	cout <<"\n"<< NN2 <<endl;
	cout << H << endl;
	cout << solid_cone<< endl;
	return 0;

}


