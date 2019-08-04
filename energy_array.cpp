#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>


#include "formula_dipolar.cpp"
#include "formula_exchange.cpp"
#include "formula_moriya.cpp"


void energy_array(int NN2,int NN,float *energy_vec,float x_ang[][500],float y_ang[][500],float *xx,float *yy,float Ms,float Msat,float K1,float K2,float Kmeio,float Kmeio2,float Kshear,float K1fielddepen,float K2fielddepen,float Knucl,float Kuni,float Kuni2,float Krot,float K2rot,float Kdiag,float Kperp,float K2perp,float hphih,float hthetah,float expnucl,float H,float beta,float jota,float m,float vizparj,float vizperpj, char* np_order,float *listatheta)
{
	
	float anis;
	float zeeman;
	float pi=3.14;
	int NNaux = ceil(pow(NN,0.666666));


	if(np_order ==(char*)"nanomembrane")
	{
		
		NN2=NN;
	}

	char* foi=(char*)"No";

/*	
	for(int i=0;i< NN2;i++)
	{

	xx[i] = hphih;
	yy[i] = hthetah;

	}
*/	
	
	float a;
	float dip_a;
	float b;
	float dip_b;
	float c;
	float dip_c;
	float d;
	float dip_d;
	float e;
	float dip_e;
	float f;
	float dip_f;
	float g;
	float dip_g;
	float p;
	float dip_p;
	float q;
	float dip_q;


	float exc_a;
	float exc_b;
	float exc_c;
	float exc_d;
	float exc_e;
	float exc_f;
	float exc_g;
	float exc_p;
	float exc_q;

	float mor_a;
	float mor_b;
	float mor_c;
	float mor_d;
	float mor_e;
	float mor_f;
	float mor_g;
	float mor_p;
	float mor_q;



	float listaNN1[int(ceil(sqrt(NN2))-2)];
	float listaNN2[int(ceil(sqrt(NN2))-2)];
	float listaNN3[int(ceil(sqrt(NN2))-2)];
	float listaNN4[int(ceil(sqrt(NN2))-2)];


	for(int i=0;i<sqrt(NN2)-2;i++)
	{
		listaNN1[i] = sqrt(NN2)-i-2;
		
	}

	for(int i=0;i<sqrt(NN2)-2;i++)
	{
		listaNN2[i] = sqrt(NN2)*(i+2)-1;
		
	}

	for(int i=0;i<sqrt(NN2)-2;i++)
	{
		listaNN3[i] = NN2-i-2;
		
	}

	for(int i=0;i<sqrt(NN2)-2;i++)
	{
		listaNN4[i] = sqrt(NN2)*(i+1);
		
	}



		
	for(int i=0;i< NN2;i++)
	{

		for(int j=0;j<sqrt(NN2)-2;j++)
		{
			if(listaNN1[j]==i)
			{
	
				foi=(char*)"NN1";
//				cout << i << endl;
				
			}

			else if(listaNN2[j]==i)
			{
				foi=(char*)"NN2";
				
			}
			
			else if(listaNN3[j]==i)
			{
				foi=(char*)"NN3";
				
			}
			else if(listaNN4[j]==i)
			{
				foi=(char*)"NN4";
				
			}
			else
			{
				foi=(char*)"No";
				
			}
			
		}

//		anis= Kuni*pow(sin(yy[i]),2.0)*pow(cos(xx[i]-pi/4.),2.0);
//		anis= Kuni*pow(sin(yy[i]+listatheta[i]),2.0)*pow(cos(xx[i]),2.0);
//		anis+= Kuni2*pow(sin(yy[i]+listatheta[i]),4.0)*pow(cos(xx[i]),4.0);
		anis= Kuni*pow(sin(yy[i]+listatheta[i]),2.0);
		anis+= Kuni2*pow(sin(yy[i]+listatheta[i]),4.0);
		anis+= Krot*pow((sin(yy[i])*sin(hthetah)*cos(xx[i]-hphih)+cos(yy[i])*cos(hthetah)),2);
		anis+= K1fielddepen*H*(sin(yy[i])*sin(hthetah)*cos(xx[i]-hphih)+cos(yy[i])*cos(hthetah));
		anis+=K1*(pow(sin(yy[i]),2)*pow(cos(xx[i]),2)*(1-pow(sin(yy[i]),2)*pow(cos(xx[i]),2))+pow(sin(yy[i]),2)*pow(sin(xx[i]),2)*pow(cos(yy[i]),2));
		anis+=-2*3.1415*pow(sin(yy[i]),2);
		anis += Kperp*(pow(cos(yy[i]),2));
		anis += K2perp*(pow(cos(yy[i]),4));
		zeeman= -H*Ms*(sin(yy[i])*sin(hthetah)*cos(xx[i]-hphih)+cos(yy[i])*cos(hthetah));


	if(np_order ==(char*)"square")
	{
//		dip_a = formula_dipolar(beta,i,j,xx,yy,x_ang,y_ang);


		if(i==0)
		{

		dip_b = formula_dipolar(beta,0,1,xx,yy,x_ang,y_ang);
		dip_b += formula_dipolar(beta,0,sqrt(NN2)+0,xx,yy,x_ang,y_ang);
		dip_b += formula_dipolar(beta,0,sqrt(NN2)-1,xx,yy,x_ang,y_ang);
		dip_b += formula_dipolar(beta,0,NN2-sqrt(NN2)+0,xx,yy,x_ang,y_ang);

		exc_b = vizparj*formula_exchange(jota,0,1,xx,yy);
		exc_b += vizparj*formula_exchange(jota,0,sqrt(NN2),xx,yy);
		exc_b += vizperpj*formula_exchange(jota,0,sqrt(NN2)-1,xx,yy);
		exc_b += vizperpj*formula_exchange(jota,0,NN2-sqrt(NN2)+0,xx,yy);

		mor_b = formula_moriya(m,0,1,xx,yy);
		mor_b += formula_moriya(m,0,sqrt(NN2),xx,yy);
		mor_b += formula_moriya(m,0,sqrt(NN2)-1,xx,yy);
		mor_b += formula_moriya(m,0,NN2-sqrt(NN2)+0,xx,yy);



		b=anis+zeeman+dip_b+exc_b+mor_b;


		energy_vec[i]=b;		

		
		}
//		else if(i!=1 and i!)
		else if(foi==(char*)"NN1")
		{
		dip_f = formula_dipolar(beta,i,i-1,xx,yy,x_ang,y_ang);
		dip_f += formula_dipolar(beta,i,i+1,xx,yy,x_ang,y_ang);
		dip_f += formula_dipolar(beta,i,i+sqrt(NN2),xx,yy,x_ang,y_ang);
		dip_f += formula_dipolar(beta,i,NN2-sqrt(NN2)+i,xx,yy,x_ang,y_ang);

		exc_f = vizparj*formula_exchange(jota,i,i-1,xx,yy);
		exc_f += vizparj*formula_exchange(jota,i,i+1,xx,yy);
		exc_f += vizperpj*formula_exchange(jota,i,i+sqrt(NN2),xx,yy);
		exc_f += vizperpj*formula_exchange(jota,i,NN2-sqrt(NN2)+i,xx,yy);


		mor_f = formula_moriya(m,i,i-1,xx,yy);
		mor_f += formula_moriya(m,i,i+1,xx,yy);
		mor_f += formula_moriya(m,i,i+sqrt(NN2),xx,yy);
		mor_f += formula_moriya(m,i,NN2-sqrt(NN2)+i,xx,yy);


		f=anis+zeeman+dip_f+exc_f+mor_f;
		energy_vec[i]=f;		
			
//		cout << sqrt(NN2) << endl;
			
		}
		else if(i==int(ceil(sqrt(NN2))-1))
		{

		dip_c = formula_dipolar(beta,sqrt(NN2)-1,sqrt(NN2)-2,xx,yy,x_ang,y_ang);
		dip_c += formula_dipolar(beta,sqrt(NN2)-1,2*sqrt(NN2)-1,xx,yy,x_ang,y_ang);
		dip_c += formula_dipolar(beta,sqrt(NN2)-1,0,xx,yy,x_ang,y_ang);
		dip_c += formula_dipolar(beta,sqrt(NN2)-1,NN2-1,xx,yy,x_ang,y_ang);

		exc_c = vizparj*formula_exchange(jota,sqrt(NN2)-1,sqrt(NN2)-2,xx,yy);
		exc_c += vizperpj*formula_exchange(jota,sqrt(NN2)-1,2*sqrt(NN2)-1,xx,yy);
		exc_c += vizparj*formula_exchange(jota,sqrt(NN2)-1,0,xx,yy);
		exc_c += vizperpj*formula_exchange(jota,sqrt(NN2)-1,NN2-1,xx,yy);

		mor_c = formula_moriya(m,sqrt(NN2)-1,sqrt(NN2)-2,xx,yy);
		mor_c += formula_moriya(m,sqrt(NN2)-1,2*sqrt(NN2)-1,xx,yy);
		mor_c += formula_moriya(m,sqrt(NN2)-1,0,xx,yy);
		mor_c += formula_moriya(m,sqrt(NN2)-1,NN2-1,xx,yy);


		c=anis+zeeman+dip_c+exc_c+mor_c;
		energy_vec[i]=c;
		

		}
		else if(foi==(char*)"NN2")
		{
		dip_q = formula_dipolar(beta,i,i-1,xx,yy,x_ang,y_ang);
		dip_q += formula_dipolar(beta,i,i+sqrt(NN2),xx,yy,x_ang,y_ang);
		dip_q += formula_dipolar(beta,i,i-sqrt(NN2),xx,yy,x_ang,y_ang);
		dip_q += formula_dipolar(beta,i,i-sqrt(NN2)+1,xx,yy,x_ang,y_ang);

		exc_q = vizparj*formula_exchange(jota,i,i-1,xx,yy);
		exc_q += vizperpj*formula_exchange(jota,i,i+sqrt(NN2),xx,yy);
		exc_q += vizperpj*formula_exchange(jota,i,i-sqrt(NN2),xx,yy);
		exc_q += vizparj*formula_exchange(jota,i,i-sqrt(NN2)+1,xx,yy);

		mor_q = formula_moriya(m,i,i-1,xx,yy);
		mor_q += formula_moriya(m,i,i+sqrt(NN2),xx,yy);
		mor_q += formula_moriya(m,i,i-sqrt(NN2),xx,yy);
		mor_q += formula_moriya(m,i,i-sqrt(NN2)+1,xx,yy);

		q=anis+zeeman+dip_q+exc_q+mor_q;
		energy_vec[i]=q;		
			
			
		}
		else if(i==NN2-1)
		{

		dip_e = formula_dipolar(beta,NN2-1,NN2-1-sqrt(NN2)-2,xx,yy,x_ang,y_ang);
		dip_e += formula_dipolar(beta,NN2-1,NN2-1-1,xx,yy,x_ang,y_ang);
		dip_e += formula_dipolar(beta,NN2-1,NN2-1-sqrt(NN2)+1,xx,yy,x_ang,y_ang);
		dip_e += formula_dipolar(beta,NN2-1,sqrt(NN2)-1,xx,yy,x_ang,y_ang);

		exc_e = vizperpj*formula_exchange(jota,NN2-1,NN2-1-sqrt(NN2)-2,xx,yy);
		exc_e += vizparj*formula_exchange(jota,NN2-1,NN2-1-1,xx,yy);
		exc_e += vizparj*formula_exchange(jota,NN2-1,NN2-1-sqrt(NN2)+1,xx,yy);
		exc_e += vizperpj*formula_exchange(jota,NN2-1,sqrt(NN2)-1,xx,yy);


		mor_e = formula_moriya(m,NN2-1,NN2-1-sqrt(NN2)-2,xx,yy);
		mor_e += formula_moriya(m,NN2-1,NN2-1-1,xx,yy);
		mor_e += formula_moriya(m,NN2-1,NN2-1-sqrt(NN2)+1,xx,yy);
		mor_e += formula_moriya(m,NN2-1,sqrt(NN2)-1,xx,yy);


		e=anis+zeeman+dip_e+exc_e+mor_e;
		energy_vec[i]=e;
		
		}
		else if(i==NN2-int(ceil(sqrt(NN2))))
		{

		dip_d = formula_dipolar(beta,NN2-int(ceil(sqrt(NN2))),NN2-int(ceil(sqrt(NN2)))+1,xx,yy,x_ang,y_ang);
		dip_d += formula_dipolar(beta,NN2-int(ceil(sqrt(NN2))),NN2-2*int(ceil(sqrt(NN2))),xx,yy,x_ang,y_ang);
		dip_d += formula_dipolar(beta,NN2-int(ceil(sqrt(NN2))),NN2-1,xx,yy,x_ang,y_ang);
		dip_d += formula_dipolar(beta,NN2-int(ceil(sqrt(NN2))),0,xx,yy,x_ang,y_ang);

		exc_d = vizparj*formula_exchange(jota,NN2-int(ceil(sqrt(NN2))),NN2-int(ceil(sqrt(NN2)))+1,xx,yy);
		exc_d += vizperpj*formula_exchange(jota,NN2-int(ceil(sqrt(NN2))),NN2-2*int(ceil(sqrt(NN2))),xx,yy);
		exc_d += vizparj*formula_exchange(jota,NN2-int(ceil(sqrt(NN2))),NN2-1,xx,yy);
		exc_d += vizperpj*formula_exchange(jota,NN2-int(ceil(sqrt(NN2))),0,xx,yy);


		mor_d = formula_moriya(m,NN2-int(ceil(sqrt(NN2))),NN2-int(ceil(sqrt(NN2)))+1,xx,yy);
		mor_d += formula_moriya(m,NN2-int(ceil(sqrt(NN2))),NN2-2*int(ceil(sqrt(NN2))),xx,yy);
		mor_d += formula_moriya(m,NN2-int(ceil(sqrt(NN2))),NN2-1,xx,yy);
		mor_d += formula_moriya(m,NN2-int(ceil(sqrt(NN2))),0,xx,yy);


		d=anis+zeeman+dip_d+exc_d+mor_d;
		energy_vec[i]=d;

		
		}
		else if(foi==(char*)"NN3")
		{
		dip_g = formula_dipolar(beta,i,i-1,xx,yy,x_ang,y_ang);
		dip_g += formula_dipolar(beta,i,i+1,xx,yy,x_ang,y_ang);
		dip_g += formula_dipolar(beta,i,i-sqrt(NN2),xx,yy,x_ang,y_ang);
		dip_g += formula_dipolar(beta,i,i%(int(sqrt(NN2))),xx,yy,x_ang,y_ang);

		exc_g = vizparj*formula_exchange(jota,i,i-1,xx,yy);
		exc_g += vizparj*formula_exchange(jota,i,i+1,xx,yy);
		exc_g += vizperpj*formula_exchange(jota,i,i-sqrt(NN2),xx,yy);
		exc_g += vizperpj*formula_exchange(jota,i,i%(int(sqrt(NN2))),xx,yy);


		mor_g = formula_moriya(m,i,i-1,xx,yy);
		mor_g += formula_moriya(m,i,i+1,xx,yy);
		mor_g += formula_moriya(m,i,i-sqrt(NN2),xx,yy);
		mor_g += formula_moriya(m,i,i%(int(sqrt(NN2))),xx,yy);


		g=anis+zeeman+dip_g+exc_g+mor_g;
		energy_vec[i]=g;		
			
			
		}
		else if(foi==(char*)"NN4")
		{
		dip_p = formula_dipolar(beta,i,i+1,xx,yy,x_ang,y_ang);
		dip_p += formula_dipolar(beta,i,i+sqrt(NN2),xx,yy,x_ang,y_ang);
		dip_p += formula_dipolar(beta,i,i-sqrt(NN2),xx,yy,x_ang,y_ang);
		dip_p += formula_dipolar(beta,i,i+sqrt(NN2)-1,xx,yy,x_ang,y_ang);


		exc_p = vizparj*formula_exchange(jota,i,i+1,xx,yy);
		exc_p += vizperpj*formula_exchange(jota,i,i+sqrt(NN2),xx,yy);
		exc_p += vizperpj*formula_exchange(jota,i,i-sqrt(NN2),xx,yy);
		exc_p += vizparj*formula_exchange(jota,i,i+sqrt(NN2)-1,xx,yy);


		mor_p = formula_moriya(m,i,i+1,xx,yy);
		mor_p += formula_moriya(m,i,i+sqrt(NN2),xx,yy);
		mor_p += formula_moriya(m,i,i-sqrt(NN2),xx,yy);
		mor_p += formula_moriya(m,i,i+sqrt(NN2)-1,xx,yy);


		p=anis+zeeman+dip_p+exc_p+mor_p;
		energy_vec[i] = p;		
			
			
		}
		else
		{
			
		dip_a = formula_dipolar(beta,i,i+1,xx,yy,x_ang,y_ang);
		dip_a += formula_dipolar(beta,i,i-1,xx,yy,x_ang,y_ang);
		dip_a += formula_dipolar(beta,i,i-sqrt(NN2),xx,yy,x_ang,y_ang);
		dip_a += formula_dipolar(beta,i,i+sqrt(NN2),xx,yy,x_ang,y_ang);

		exc_a = vizparj*formula_exchange(jota,i,i+1,xx,yy);
		exc_a += vizparj*formula_exchange(jota,i,i-1,xx,yy);
		exc_a += vizperpj*formula_exchange(jota,i,i-sqrt(NN2),xx,yy);
		exc_a += vizperpj*formula_exchange(jota,i,i+sqrt(NN2),xx,yy);

		mor_a = formula_moriya(m,i,i+1,xx,yy);
		mor_a += formula_moriya(m,i,i-1,xx,yy);
		mor_a += formula_moriya(m,i,i-sqrt(NN2),xx,yy);
		mor_a += formula_moriya(m,i,i+sqrt(NN2),xx,yy);

		a=anis+zeeman+dip_a+exc_a+mor_a;
		energy_vec[i] = a;		
			
//		cout << i << endl;
			
		}

//		cout << NN2-int(ceil(sqrt(NN2))) << endl;

//		dip_a = formula_dipolar(beta,1,2,xx,yy,x_ang,y_ang);
//		a=anis+zeeman+dip_a;

	}
	else if(np_order== (char*)"ring")
	{

		dip_a = formula_dipolar(beta,i,i+1,xx,yy,x_ang,y_ang);
		dip_a += formula_dipolar(beta,i,i-1,xx,yy,x_ang,y_ang);

		exc_a = vizparj*formula_exchange(jota,i,i+1,xx,yy);
		exc_a += vizparj*formula_exchange(jota,i,i-1,xx,yy);

		mor_a = formula_moriya(m,i,i+1,xx,yy);
		mor_a += formula_moriya(m,i,i-1,xx,yy);

		a=anis+zeeman+dip_a+exc_a+mor_a;
		energy_vec[i] = a;		

	
	
	}


	else if(np_order ==(char*)"nanomembrane" or np_order ==(char*)"half_nanomembrane")
	{

		if(i==0) 
		{


		dip_a = formula_dipolar(beta,i,i+1,xx,yy,x_ang,y_ang);
		dip_a += formula_dipolar(beta,i,NN-NNaux,xx,yy,x_ang,y_ang);
		dip_a += formula_dipolar(beta,i,i+NNaux,xx,yy,x_ang,y_ang);
		dip_a += formula_dipolar(beta,i,NN-1,xx,yy,x_ang,y_ang);

		exc_a = vizparj*formula_exchange(jota,i,i+1,xx,yy);
		exc_a += vizparj*formula_exchange(jota,i,NN-NNaux,xx,yy);
		exc_a += vizparj*formula_exchange(jota,i,i+NNaux,xx,yy);
		exc_a += vizparj*formula_exchange(jota,i,NN-1,xx,yy);

		mor_a = formula_moriya(m,i,i+1,xx,yy);
		mor_a += formula_moriya(m,i,NN-NNaux,xx,yy);
		mor_a += formula_moriya(m,i,i+NNaux,xx,yy);
		mor_a += formula_moriya(m,i,NN-1,xx,yy);

		a=anis+zeeman+dip_a+exc_a+mor_a;
		energy_vec[i] = a;		
//		cout << y_ang[i][i+1] << "\n" << i << endl;
		
		}

		else if(i==NN2-1) 
		{

		dip_a = formula_dipolar(beta,i,i-1,xx,yy,x_ang,y_ang);
		dip_a += formula_dipolar(beta,i,0,xx,yy,x_ang,y_ang);
		dip_a += formula_dipolar(beta,i,i-NNaux,xx,yy,x_ang,y_ang);
		dip_a += formula_dipolar(beta,i,NNaux-1,xx,yy,x_ang,y_ang);

		exc_a = vizparj*formula_exchange(jota,i,i-1,xx,yy);
		exc_a += vizparj*formula_exchange(jota,i,0,xx,yy);
		exc_a += vizparj*formula_exchange(jota,i,i-NNaux,xx,yy);
		exc_a += vizparj*formula_exchange(jota,i,NNaux-1,xx,yy);

		mor_a = formula_moriya(m,i,i-1,xx,yy);
		mor_a += formula_moriya(m,i,0,xx,yy);
		mor_a += formula_moriya(m,i,i-NNaux,xx,yy);
		mor_a += formula_moriya(m,i,NNaux-1,xx,yy);

		a=anis+zeeman+dip_a+exc_a+mor_a;
		energy_vec[i] = a;		
//		cout << y_ang[i][i+1] << "\n" << i << endl;
		
		}

		else if(1 <= i and i<= NNaux-1)
		{
		
		dip_a = formula_dipolar(beta,i,i+1,xx,yy,x_ang,y_ang);
		dip_a += formula_dipolar(beta,i,i-1,xx,yy,x_ang,y_ang);
		dip_a += formula_dipolar(beta,i,i+NNaux,xx,yy,x_ang,y_ang);
		dip_a += formula_dipolar(beta,i,NN-i,xx,yy,x_ang,y_ang);

		exc_a = vizparj*formula_exchange(jota,i,i+1,xx,yy);
		exc_a += vizparj*formula_exchange(jota,i,i-1,xx,yy);
		exc_a += vizparj*formula_exchange(jota,i,i+NNaux,xx,yy);
		exc_a += vizparj*formula_exchange(jota,i,NN-i,xx,yy);

		mor_a = formula_moriya(m,i,i+1,xx,yy);
		mor_a += formula_moriya(m,i,i-1,xx,yy);
		mor_a += formula_moriya(m,i,i+NNaux,xx,yy);
		mor_a += formula_moriya(m,i,NN-i,xx,yy);

		a=anis+zeeman+dip_a+exc_a+mor_a;
		energy_vec[i] = a;		

			
		}

		else if(NN-NNaux <= i and i <= NN-2)
		{

//		cout << "aaa" << i << endl;
//		cout << NNaux-1 << endl;

		dip_a = formula_dipolar(beta,i,i+1,xx,yy,x_ang,y_ang);
		dip_a += formula_dipolar(beta,i,i-1,xx,yy,x_ang,y_ang);
		dip_a += formula_dipolar(beta,i,i-NNaux,xx,yy,x_ang,y_ang);
		dip_a += formula_dipolar(beta,i,i%NNaux,xx,yy,x_ang,y_ang);

		exc_a = vizparj*formula_exchange(jota,i,i+1,xx,yy);
		exc_a += vizparj*formula_exchange(jota,i,i-1,xx,yy);
		exc_a += vizparj*formula_exchange(jota,i,i-NNaux,xx,yy);
		exc_a += vizparj*formula_exchange(jota,i,i%NNaux,xx,yy);

		mor_a = formula_moriya(m,i,i+1,xx,yy);
		mor_a += formula_moriya(m,i,i-1,xx,yy);
		mor_a += formula_moriya(m,i,i-NNaux,xx,yy);
		mor_a += formula_moriya(m,i,i%NNaux,xx,yy);

		a=anis+zeeman+dip_a+exc_a+mor_a;
		energy_vec[i] = a;		
		
		}
		else 
		{

//		cout << i <<"\t aqui" << endl;

		dip_a = formula_dipolar(beta,i,i+1,xx,yy,x_ang,y_ang);
		dip_a += formula_dipolar(beta,i,i-1,xx,yy,x_ang,y_ang);
		dip_a += formula_dipolar(beta,i,i-NNaux,xx,yy,x_ang,y_ang);
		dip_a += formula_dipolar(beta,i,i+NNaux,xx,yy,x_ang,y_ang);

		exc_a = vizparj*formula_exchange(jota,i,i+1,xx,yy);
		exc_a += vizparj*formula_exchange(jota,i,i-1,xx,yy);
		exc_a += vizparj*formula_exchange(jota,i,i-NNaux,xx,yy);
		exc_a += vizparj*formula_exchange(jota,i,i+NNaux,xx,yy);

		mor_a = formula_moriya(m,i,i+1,xx,yy);
		mor_a += formula_moriya(m,i,i-1,xx,yy);
		mor_a += formula_moriya(m,i,i-NNaux,xx,yy);
		mor_a += formula_moriya(m,i,i+NNaux,xx,yy);

		a=anis+zeeman+dip_a+exc_a+mor_a;
		energy_vec[i] = a;		
//		cout << y_ang[i][i+1] << "\n" << i << endl;



		
		}

	}


//		energy_vec[i]=anis+zeeman;		

	}
	
	
}



