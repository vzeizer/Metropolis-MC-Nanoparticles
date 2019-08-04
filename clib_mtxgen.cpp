#include "clib_mtxgen.h"
#include <cmath>
#include <stdlib.h>
#include <iostream>



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////












//void launcher(char shape, float dl,float radiuscore, float radiusshell,float radiusc,int corenumber,int shellnumber,int radc,int Npix,int Npiy,int Ntam,int cnum, float cs)
//void launcher_columnpiling(char shape, float dl,float radiuscore, float radiusshell,float radiusc,int corenumber,int shellnumber,int radc,int Npix,int Npiy,int Ntam,int cnum, float cs)

void launcher_general( float dl,float radiuscore, float radiusshell,float radiusc,int corenumber,int shellnumber,float radc,int Npix,int Npiy,int Ntam,int cnum, float cs,float base, float width,float height,float base2,float width2,float radiusx1,float radiusy1,float radiusz1,float radiusx2,float radiusy2,float radiusz2,float radiusxcs,float radiusycs,float radiuszcs,float rcarbonpt,float radiuspt,float rcarbonpd,float radiuspd,float distcentro,int alloynumber,int basex,int basey,int basez, float lenpystruc, float heipystruc, int partes, int indorigins, int radiussurface, int surfaceindex, int xlength, int ylength, int zlength, int xlength2, int ylength2, int zlength2, int halfsphereradius1, int halfsphereradius2, int segmentheight, int segmentradius1, int segmentradius2, int pillheight1, int pillheight2, int pillradius1,  int pillradius2)
// Here some parameters will be specified and some variables initialized
{

	rcarbonpt=radiuspt + cs;
	rcarbonpd=radiuspd + cs;




	char* pilingshape =(char*)"pygeneral";

	char* pilingstruc =(char*)"pillform";



int hex_layers = 3;


cout<< cnum << "cnummmm"<<endl;




//int i;
//int j;
//int k;

if(pilingshape==(char*)"hexmono" or pilingshape== (char*)"hexpyramid")
{
		Npix=Npix*2;
		Npiy=Npiy*2-1;
		cout<<"simmmmmmm"<<endl;
}


if(pilingstruc==(char*)"cylinder" )
	{
	radiusshell = radiusxcs+10;
	radiusc = radiusshell+10.0;
	}


 int Nmaior;
// int Nmenor;


 if (Npix>Npiy)
{
 Nmaior=Npix;
// Nmenor=Npiy
}
 else 
{

 Nmaior=Npiy;
// Nmenor=Npix
}

 int Dx1;
 int Dy1;
 int Dz1;

// float 	basenew = 0;
// float 	widthnew = 0;


 if(pilingstruc == (char*)"pyramidal")
 {
	 
 Dx1=int(2*Nmaior*lenpystruc/dl);
 Dy1=int(2*Nmaior*lenpystruc/dl);
 Dz1=int(2*Ntam*heipystruc/dl);
 radiusc=lenpystruc;
	 
 }
 else if (pilingstruc == (char*)"ellipsoidal")
 {

	if(radiusxcs>radiusycs)
	{
 
	radiusc=radiusxcs;
	
	}
 
 	else
 	{
 	
 	radiusc=radiusycs;
 	
	}
 	 
 Dx1=int(2*Nmaior*radiusc/dl);
 Dy1=int(2*Nmaior*radiusc/dl);
 Dz1=int(2*Ntam*radiuszcs/dl);
 radiusc=radiusxcs;
	 
	 
 }

 else if (pilingstruc == (char*)"octahedron")
 {

	radiusc=radiusc;
	 
	 cout<< radiusc <<"octa"<< endl;
	 
 Dx1=int(2*Nmaior*radiusc/dl);
 Dy1=int(2*Nmaior*radiusc/dl);
 Dz1=int(2*Ntam*radiusc/dl);


 }
 
 else if (pilingstruc == (char*)"triplate")
 {

//	float 	basenew = 0;
//	float 	widthnew = 0;

 
// 	basenew= base2+cs;
//	widthnew=width2+cs;


	if(base2> width2)
		{
	radiusc=base2+cs;
		}
	else
		{
		radiusc=width2+cs;
		}

 Dx1=int(2*Nmaior*radiusc/dl);
 Dy1=int(2*Nmaior*radiusc/dl);
 Dz1=int(2*Ntam*radiusc/dl);


 }
 else if (pilingstruc == (char*)"cubic")
 {

	radiusc=radiusc;
	 
	cout<< radiusc <<"cubic"<< endl;
	 
 Dx1=int(2*Nmaior*radiusc/dl);
 Dy1=int(2*Nmaior*radiusc/dl);
 Dz1=int(2*Ntam*radiusc/dl);


 }
 
 else if (pilingstruc == (char*)"manyshell")
 {

	radiusc=radiusc;
	 
	cout<< radiusc <<"manyshell"<< endl;
	 
 Dx1=int(2*Nmaior*radiusc/dl);
 Dy1=int(2*Nmaior*radiusc/dl);
 Dz1=int(2*Ntam*radiusc/dl);


 }

 else if (pilingstruc == (char*)"spheresurface")
 {

	radiusc=radiusc+2*radiussurface;
	 
	cout<< radiusc <<"spheresurface"<< endl;
	 
 Dx1=int(3*Nmaior*radiusc/dl);
 Dy1=int(3*Nmaior*radiusc/dl);
 Dz1=int(2*Ntam*radiusc/dl);


 }

 else if (pilingstruc == (char*)"spheresurfacetwo")
 {

	radiusc=radiusc+2*radiussurface;
	 
	cout<< radiusc <<"spheresurfacetwo"<< endl;
	 
 Dx1=int(3*Nmaior*radiusc/dl);
 Dy1=int(3*Nmaior*radiusc/dl);
 Dz1=int(2*Ntam*radiusc/dl);


 }
 else if (pilingstruc == (char*)"pavingstone")
 {

	radiusc=radiusc;
	
	 
	cout<< radiusc <<"pavingstone"<< endl;
	 
 Dx1=int(2*Nmaior*radiusc/dl);
 Dy1=int(2*Nmaior*radiusc/dl);
 Dz1=int(2*Ntam*radiusc/dl);


 }

 else if (pilingstruc == (char*)"halfsphere")
 {

	radiusc=radiusc;
	radiuscore=halfsphereradius1;
	radiusshell=halfsphereradius2;
	radiusc=radiusshell+cs;
	 
	cout<< radiusc <<"halfsphere"<< endl;
	 
 Dx1=int(2*Nmaior*radiusc/dl);
 Dy1=int(2*Nmaior*radiusc/dl);
 Dz1=int(1*Ntam*radiusc/dl);


 }
 

 else if (pilingstruc == (char*)"segmentsphere")
 {

	radiusc=radiusc;
	radiuscore=segmentradius1;
	radiusshell=segmentradius2;
	radiusc=radiusshell+cs;
	 
	cout<< radiusc <<"segmentsphere"<< endl;
	 
 Dx1=int(2*Nmaior*radiusc/dl);
 Dy1=int(2*Nmaior*radiusc/dl);
// Dz1=int(2*Ntam*(radiusc-int(segmentheight/2))/dl);
 Dz1=int(Ntam*(segmentheight+cs)/dl);

 }

 else if (pilingstruc == (char*)"pillform")
 {

	radiusc=radiusc;
	radiuscore=pillradius1;
	radiusshell=pillradius2;
	radiusc=radiusshell+cs;
	 
	cout<< radiusc <<"pillform"<< endl;
	 
 Dx1=int(2*Nmaior*(radiusc+pillheight2*0)/dl);
 Dy1=int(2*Nmaior*(radiusc+pillheight2*0)/dl);
// Dz1=int(2*Ntam*(radiusc-int(segmentheight/2))/dl);
 Dz1=int(Ntam*(2*radiusc+pillheight2)/dl);

 }

 
 else
 {
 Dx1=int(2*Nmaior*radiusc/dl);
 Dy1=int(2*Nmaior*radiusc/dl);
 Dz1=int(2*Ntam*radiusc/dl);


 }





	cout << Dx1<<Dy1<<Dz1<<"dimmm"  <<endl;



//if(pilingshape==(char*)"hexmono" or pilingshape== (char*)"hexpyramid")
//{
//Dx1=3/2*Dx1;
//Dy1=3/2*Dy1;
//Dz1=Dz1;
//}

// cout << Dx1<< endl;


 int **A= new int*[Dx1];


zeromatrix(Dx1,Dy1, Dz1, A);



//if (Npix>Npiy)
//{
//
 //Nmaiorini=Npix;
// Nmenorini=Npiy;
//}
// else 
//{
 //Nmaiorini=Npiy;
 //Nmenorini=Npix;
//}







//initializing arrays

int length=80000;

//float x[length],y[length],z[length];

float x[length],y[length],z[length];

vector_init( x, y, z, length);


int Npixn=Dx1;
int Npiyn=Dy1;
int Ntamn=Dz1;


int xini=1;
int xfin=Npixn;
int yini=1;
int yfin=Npiyn;
int zini=1;
int zfin=Ntamn;

// int Npix
// int Npiy
// int Ntam



// HERE THE COLUMN PILING WILL BE CALLED
/////////





///////////////

if(pilingshape == (char*)"column")
{
columnpiling (xini,xfin,yini,yfin,zini,zfin,Npix,Npiy,Ntam,Dx1,Dy1,Dz1,radiusc,radiuscore,radiusshell,A,corenumber,shellnumber,cnum,dl,x,y,z,cs);

// HERE THE RECTANGULAR AGGLOMERATION FORM IS CALLED
}

//rectangular (shape, pilingshape,dl,radiuscore,radiusshell,radiusc,corenumber,shellnumber,radc,Npix,Npiy,Ntam,cnum,cs,x,y,zint,A,Dx1,Dy1,Dz1);
//rectangular (xini,xfin,yini,yfin,zini,zfin,dl,radiuscore,radiusshell,radiusc,corenumber,shellnumber,radc,Npix,Npiy,Ntam,cnum,cs,x,y,z,A,Dx1,Dy1,Dz1);

if(pilingshape == (char*)"rect")
{

cout<< cnum <<"cnum"<<endl;


rectangular (xini,xfin,yini,yfin,zini,zfin,dl,radiuscore,radiusshell,radiusc,corenumber,shellnumber,radc,Npix,Npiy,Ntam,cnum,cs,x,y,z,A,Dx1,Dy1,Dz1);


}

if(pilingshape == (char*)"jonderstruct1")
{


jonderstruct1 (xini,xfin,yini,yfin,zini,zfin,Npix,Npiy,Ntam,Dx1,Dy1,Dz1,radiusc,radiuscore,radiusshell,A,corenumber,shellnumber,cnum,dl,x,y,z,base,width,height,base2,width2,radiusx1,radiusy1,radiusz1,radiusx2,radiusy2,radiusz2,radiusxcs,radiusycs,radiuszcs,cs);

}


if(pilingshape == (char*)"jonderstruct2")
{

jonderstruct2 (xini,xfin,yini,yfin,zini,zfin,Npix,Npiy,Ntam,Dx1,Dy1,Dz1,radiusc,radiuscore,radiusshell,A,corenumber,shellnumber,cnum,dl,x,y,z,base,width,height,base2,width2,radiusx1,radiusy1,radiusz1,radiusx2,radiusy2,radiusz2,radiusxcs,radiusycs,radiuszcs,cs);

}


if(pilingshape == (char*)"pygeneral")
{

pygeneral (xini,xfin,yini,yfin,zini,zfin,Npix,Npiy,Ntam,Dx1,Dy1,Dz1,radiusc,radiuscore,radiusshell,A,corenumber,shellnumber,cnum,dl,x,y,z,base,width,height,base2,width2,radiusx1,radiusy1,radiusz1,radiusx2,radiusy2,radiusz2,radiusxcs,radiusycs,radiuszcs,cs,rcarbonpt,radiuspt,rcarbonpd,radiuspd,distcentro,alloynumber,basex,basey,basez, lenpystruc, heipystruc,pilingstruc,partes,indorigins, radiussurface, surfaceindex, xlength, ylength, zlength, xlength2, ylength2, zlength2,halfsphereradius1,halfsphereradius2, segmentheight, segmentradius1, segmentradius2, pillheight1, pillheight2, pillradius1, pillradius2);
//int incoreshell_triplate(int ii, int cnum,float radiusc,float radiuscore,float radiusshell,int corenumber,int shellnumber,float dl,int h, float x[80000], float y[80000], float z[80000],int& aa,int& index,int& basex,int& basey,int& basez, float lenpystruc, float heipystruc,int i,int j,int k,int xini,int xfin,int yini,int yfin,int zini,int zfin, float radiuscini, float radiuspt, float radiuspd, float distcentro,float rcarbonpt,float rcarbonpd,int alloynumber, float radiusxcs, float radiusycs, float radiuszcs, char* pilingstruc,float base,float width,float height,float base2,float width2)

}

if(pilingshape == (char*)"hexpyramid")
{
hexpyramid (xini,xfin,yini,yfin,zini,zfin,Npix,Npiy,Ntam,Dx1,Dy1,Dz1,radiusc,radiuscore,radiusshell,A,corenumber,shellnumber,cnum,dl,x,y,z,base,width,height,base2,width2,radiusx1,radiusy1,radiusz1,radiusx2,radiusy2,radiusz2,radiusxcs,radiusycs,radiuszcs,cs,rcarbonpt,radiuspt,rcarbonpd,radiuspd,distcentro,alloynumber,hex_layers);
}


if(pilingshape == (char*)"hexmono")
{
hexmono (xini,xfin,yini,yfin,zini,zfin,Npix,Npiy,Ntam,Dx1,Dy1,Dz1,radiusc,radiuscore,radiusshell,A,corenumber,shellnumber,cnum,dl,x,y,z,base,width,height,base2,width2,radiusx1,radiusy1,radiusz1,radiusx2,radiusy2,radiusz2,radiusxcs,radiusycs,radiuszcs,cs,rcarbonpt,radiuspt,rcarbonpd,radiuspd,distcentro,alloynumber,hex_layers);
}


if(pilingshape == (char*)"hex1")
{
hex1 (xini,xfin,yini,yfin,zini,zfin,Npix,Npiy,Ntam,Dx1,Dy1,Dz1,radiusc,radiuscore,radiusshell,A,corenumber,shellnumber,cnum,dl,x,y,z,base,width,height,base2,width2,radiusx1,radiusy1,radiusz1,radiusx2,radiusy2,radiusz2,radiusxcs,radiusycs,radiuszcs,cs,rcarbonpt,radiuspt,rcarbonpd,radiuspd,distcentro,alloynumber,hex_layers);
}



if(pilingshape == (char*)"hex2")
{
hex2 (xini,xfin,yini,yfin,zini,zfin,Npix,Npiy,Ntam,Dx1,Dy1,Dz1,radiusc,radiuscore,radiusshell,A,corenumber,shellnumber,cnum,dl,x,y,z,base,width,height,base2,width2,radiusx1,radiusy1,radiusz1,radiusx2,radiusy2,radiusz2,radiusxcs,radiusycs,radiuszcs,cs,rcarbonpt,radiuspt,rcarbonpd,radiuspd,distcentro,alloynumber,hex_layers);
}


if(pilingshape == (char*)"hex3")
{
hex3 (xini,xfin,yini,yfin,zini,zfin,Npix,Npiy,Ntam,Dx1,Dy1,Dz1,radiusc,radiuscore,radiusshell,A,corenumber,shellnumber,cnum,dl,x,y,z,base,width,height,base2,width2,radiusx1,radiusy1,radiusz1,radiusx2,radiusy2,radiusz2,radiusxcs,radiusycs,radiuszcs,cs,rcarbonpt,radiuspt,rcarbonpd,radiuspd,distcentro,alloynumber,hex_layers);
}


if(pilingshape == (char*)"hex4")
{
hex4 (xini,xfin,yini,yfin,zini,zfin,Npix,Npiy,Ntam,Dx1,Dy1,Dz1,radiusc,radiuscore,radiusshell,A,corenumber,shellnumber,cnum,dl,x,y,z,base,width,height,base2,width2,radiusx1,radiusy1,radiusz1,radiusx2,radiusy2,radiusz2,radiusxcs,radiusycs,radiuszcs,cs,rcarbonpt,radiuspt,rcarbonpd,radiuspd,distcentro,alloynumber,hex_layers);
}


if(pilingshape == (char*)"hex5")
{
hex5 (xini,xfin,yini,yfin,zini,zfin,Npix,Npiy,Ntam,Dx1,Dy1,Dz1,radiusc,radiuscore,radiusshell,A,corenumber,shellnumber,cnum,dl,x,y,z,base,width,height,base2,width2,radiusx1,radiusy1,radiusz1,radiusx2,radiusy2,radiusz2,radiusxcs,radiusycs,radiuszcs,cs,rcarbonpt,radiuspt,rcarbonpd,radiuspd,distcentro,alloynumber,hex_layers);
}


if(pilingshape == (char*)"hex6")
{
hex6 (xini,xfin,yini,yfin,zini,zfin,Npix,Npiy,Ntam,Dx1,Dy1,Dz1,radiusc,radiuscore,radiusshell,A,corenumber,shellnumber,cnum,dl,x,y,z,base,width,height,base2,width2,radiusx1,radiusy1,radiusz1,radiusx2,radiusy2,radiusz2,radiusxcs,radiusycs,radiuszcs,cs,rcarbonpt,radiuspt,rcarbonpd,radiuspd,distcentro,alloynumber,hex_layers);
}


if(pilingshape == (char*)"hex7")
{
hex7 (xini,xfin,yini,yfin,zini,zfin,Npix,Npiy,Ntam,Dx1,Dy1,Dz1,radiusc,radiuscore,radiusshell,A,corenumber,shellnumber,cnum,dl,x,y,z,base,width,height,base2,width2,radiusx1,radiusy1,radiusz1,radiusx2,radiusy2,radiusz2,radiusxcs,radiusycs,radiuszcs,cs,rcarbonpt,radiuspt,rcarbonpd,radiuspd,distcentro,alloynumber,hex_layers);
}


if(pilingshape == (char*)"hex8")
{
hex8 (xini,xfin,yini,yfin,zini,zfin,Npix,Npiy,Ntam,Dx1,Dy1,Dz1,radiusc,radiuscore,radiusshell,A,corenumber,shellnumber,cnum,dl,x,y,z,base,width,height,base2,width2,radiusx1,radiusy1,radiusz1,radiusx2,radiusy2,radiusz2,radiusxcs,radiusycs,radiuszcs,cs,rcarbonpt,radiuspt,rcarbonpd,radiuspd,distcentro,alloynumber,hex_layers);
}


if(pilingshape == (char*)"hex9")
{
hex9 (xini,xfin,yini,yfin,zini,zfin,Npix,Npiy,Ntam,Dx1,Dy1,Dz1,radiusc,radiuscore,radiusshell,A,corenumber,shellnumber,cnum,dl,x,y,z,base,width,height,base2,width2,radiusx1,radiusy1,radiusz1,radiusx2,radiusy2,radiusz2,radiusxcs,radiusycs,radiuszcs,cs,rcarbonpt,radiuspt,rcarbonpd,radiuspd,distcentro,alloynumber,hex_layers);
}




//int rectangular (char* const shape, char* const pilingshape, int xini,int xfin,int yini,int yfin,int zini,int zfin,float dl,float radiuscore, float radiusshell,float radiusc,int corenumber,int shellnumber,int radc,int Npix,int Npiy,int Ntam,int cnum, float cs,float x,float y,float z,int **A,int Dx1,int Dy1,int Dz1)

//rectangular (char* const shape, char* const pilingshape, float dl,float radiuscore, float radiusshell,float radiusc,int corenumber,int shellnumber,int radc,int Npix,int Npiy,int Ntam,int cnum, float cs,float x,float y,float z,int **A,int Dx1,int Dy1,int Dz1)

//{


// cout<< "to aqui nessa porra" << endl;

//  

//	cout<<**A<<endl;


compac(A,Dx1,Dy1,Dz1,zini,zfin,yini,yfin,xini,xfin);
//int compac(int **A,int Dx1,int Dy1,int Dz1,int zini,int zfin,int yini,int yfin,int xini,int xfin)

delete_alloc(A,Dx1);

// return **A;

}


void delete_alloc(int **A, int Dx1)
{

// deleting allocated memory

for( int i = 0 ; i < Dx1 ; i++ )
{
delete [] A[i] ;
}

delete [] A;



}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



int compac(int **A,int Dx1,int Dy1,int Dz1,int zini,int zfin,int yini,int yfin,int xini,int xfin)
{


//	fileemp=open('/home/vagner/Desktop/GREAT_REFS/MEISMATHEMATICA/shay/matrizpython/marmittexamples/ajudamarmitt/emp.mtx','w')


	ofstream fs;
	fs.open("gen.mtx"); // now open the file for writing




//	cout << Dx1<<Dy1<<Dz1<<"dimmm2222"  <<endl;

	

	fs << Dx1;
	fs << " ";
	fs << Dy1;
	fs << " ";
	fs << Dz1;
//	fs << " ";
	fs << endl;

			

	cout << A[0][0]<< "Primeiro matrix" << endl;

/*

	for(int k = zini; k < zfin+1 ; k++)
		{
		for(int j=yini;j<yfin+1;j++)
			{
			for(int i=xini;i<xfin+1;i++)
				{
				if(A[i][j+(k-1)*Dy1]!=0)
					{
				cout<< "eh diferente de zero";		
					}
				}
			}
		}
*/		
		
		
	int iCp_old = A[0][0];
	int c = 1;
	int iCp;

//	for k in range(zini,zfin+1):
//	for(int k = zini; k < zfin+1 ; k++)
	for(int k = zini; k < zfin+1 ; k++)
	{

//		for j in range(yini,yfin+1):
//		for(int j=yini;j<yfin+1;j++)
		for(int j=yini;j<yfin+1;j++)
		{
//			for(int i=xini;i<xfin+1;i++)
			for(int i=xini;i<xfin+1;i++)
			{

//			for i in range(xini,xfin+1):
				iCp = A[i][j+(k-1)*Dy1];
//				cout << iCp << "i" << i << endl;
//				cout << iCp_old<< endl;
				if (iCp == iCp_old)
				{
					c += 1;

					if (c == 50000)
					{

//						print(c, iCp_old, file=fileemp);
						
						fs << c <<" " << iCp_old <<endl;
						c = 1;
						iCp_old = A[i][j+(k-1)*Dy1];
					}

				}

				else
					{
//					print(c, iCp_old, file=fileemp);
//					cout<< "aqi" << endl;
					fs << c << " " << iCp_old <<endl;
					iCp_old = iCp;
					c = 1;
//					cout<< "icpold"<< iCp <<endl;

					}
				if (i==Dx1 and j==Dy1 and k==Dz1)
					{				
//					print(c,iCp_old, file=fileemp);
					fs << c << " " << iCp_old <<endl;
			
					}



}
}
}


fs.close();


return 0;

}


//cout << x <<endl;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



int columnpiling (int xini,int xfin,int yini,int yfin,int zini,int zfin,int Npix,int Npiy,int Ntam,int Dx1,int Dy1,int Dz1,float radiusc,float radiuscore,float radiusshell,int **A,int corenumber,int shellnumber,int cnum,float dl, float x[80000], float y[80000], float z[80000], float cs)
{
//cout<< "to aqui nessa porra" << endl;

// int a;
// int b;
int ii;

//int w=0;
//int g=0;

for (int k=zini; k<zfin;k++)
{
for (int j=yini; j<yfin;j++)
{
for (int i=xini; i<xfin;i++)
{
//	a=i;

//	b=j+(k-1)*Dy1;

	ii=1;

	for (int h=zini;h<Ntam+1;h++)
{

		x[ii] = float(((float(radiusc)/float(dl)-float(i)+2.0)));
		y[ii] = float(((float(radiusc)/float(dl)-float(j))+2.0));
		z[ii] = float(((float(radiusc*(2*(h-1)+1))/float(dl)-float(k)+2.0)));

			int index=0;

			int aa=0;

			incoreshell_sphere(ii,cnum,radiusc,radiuscore,radiusshell,corenumber,shellnumber,dl,h,x,y,z,index,aa);

			if (aa==1)
		    	{
// corrigir aqui para fazer matriz 2D
					A[i][j+(k-1)*Dy1] = index;
				}
		ii=ii+1;

//			}



}
}
}
}

return **A;

}




int rectangular (int xini,int xfin,int yini,int yfin,int zini,int zfin,float dl,float radiuscore, float radiusshell,float radiusc,int corenumber,int shellnumber,float radc,int Npix,int Npiy,int Ntam,int cnum, float cs,float x[80000],float y[80000],float z[80000],int **A,int Dx1,int Dy1,int Dz1)
{

cout<< cnum <<endl;

	
//int g=0

int ii;

for(int k=zini; k < zfin+1;k++)
{
for(int j=yini; j < yfin+1;j++)
{
for(int i=xini; i < xfin+1;i++)    
{
//		        	int a=(i);
//		        	int b=(j+(k-1)*Dy1);
ii=1;
for(int h=zini; h < Npix+1;h++)
{
for(int g=zini; g < Npiy+1;g++)
{	
for(int w= zini; w < Ntam+1;w++)
{	
		x[ii]= float(((float(radiusc*(2*(w-1)+1))/float(dl)-float(i)+2.0)));
		y[ii]= float(((float(radiusc*(2*(g-1)+1))/float(dl)-float(j))+2.0));
		z[ii]= float(((float(radiusc*(2*(h-1)+1))/float(dl)-float(k)+2.0)));
			
			int index=0;
			int aa=0;

	
//			if(shape==(char*)"sphere")
			
			incoreshell_sphere(ii,cnum,radiusc,radiuscore,radiusshell,corenumber,shellnumber,dl,h,x,y,z,index,aa);
			


			if (aa==1)
    	        {
// corrigir aqui para fazer matriz 2D
					A[i][j+(k-1)*Dy1] = index;
				}

ii=ii+1;
}
}
}
}
}
}
	


return **A;

}


//int rectangular (int xini,int xfin,int yini,int yfin,int zini,int zfin,float dl,float radiuscore, float radiusshell,float radiusc,int corenumber,int shellnumber,float radc,int Npix,int Npiy,int Ntam,int cnum, float cs,float x[80000],float y[80000],float z[80000],int **A,int Dx1,int Dy1,int Dz1)

int jonderstruct1 (int xini,int xfin,int yini,int yfin,int zini,int zfin, int Npix,int Npiy,int Ntam, int Dx1,int Dy1,int Dz1,float radiusc,float radiuscore, float radiusshell,int **A,int corenumber,int shellnumber,int cnum,float dl,float x[80000],float y[80000],float z[80000],float base, float width,float height,float base2,float width2,float radiusx1,float radiusy1,float radiusz1,float radiusx2,float radiusy2,float radiusz2,float radiusxcs,float radiusycs,float radiuszcs,float cs)
{
	
//	int w=0;
//	int g=0;
//	int h=0;
	float xx1,yy1,zz1;
	float xx2,yy2,zz2;
	float xx3,yy3,zz3;
	float xx4,yy4,zz4;
	float xx5,yy5,zz5;
	float xx6,yy6,zz6;
	float xx7,yy7,zz7;
	float xx8,yy8,zz8;
	float xx9,yy9,zz9;
	float div,cc;



//	print(corenumber,'aqui')

	for (int k=zini;k<zfin+1;k++)
	{
		for (int j =yini; j< yfin+1;j++)
		{
		        for (int i=xini; i < xfin+1; i++)
		        {
		        
		        	int a=int(i);
		        	int b=int(j+(k-1)*Dy1);
		        	int ii=1;

// #############

		        	xx1=((1)*float(radiusc/dl)-i+1);
		        	yy1= ((1)*float(radiusc/dl)-j+1);
		        	zz1=(float(radiusc/dl)-k+1);
    
		        	xx2=((1.0)*float(radiusc/dl)-i+1);
		        	yy2= ((3.0)*float(radiusc/dl)-j+1);
		        	zz2=(float(radiusc/dl)-k+1);

		        	xx3=((3.0)*float(radiusc/dl)-i+1);
		        	yy3= ((1.0)*float(radiusc/dl)-j+1);
		        	zz3=(float(radiusc/dl)-k+1);

		        	xx4=((3.0)*float(radiusc/dl)-i+1);
		        	yy4= ((3.0)*float(radiusc/dl)-j+1);
		        	zz4=(float(radiusc/dl)-k+1);

// !!! second layer, one sphere

		        	xx5=((2.0)*float(radiusc/dl)-i+1);
		        	yy5= ((2.0)*float(radiusc/dl)-j+1);
		        	zz5=((sqrt(2.0)+1.0)*float(radiusc/dl)-k+1);

// !!! third layer, four spheres


		        	xx6=(1*float(radiusc/dl)-i+1);
		        	yy6= (1*float(radiusc/dl)-j+1);
		        	zz6=((sqrt(3.0)+2.0)*float(radiusc/dl)-k+1);

		        	xx7=(1*float(radiusc/dl)-i+1);
		        	yy7= (3*float(radiusc/dl)-j+1);
		        	zz7=((sqrt(3.0)+2.0)*float(radiusc/dl)-k+1);

		        	xx8=(3*float(radiusc/dl)-i+1);
		        	yy8= (1*float(radiusc/dl)-j+1);
		        	zz8=((sqrt(3.0)+2.0)*float(radiusc/dl)-k+1);
    
		        	xx9=(3*float(radiusc/dl)-i+1);
		        	yy9= (3*float(radiusc/dl)-j+1);
		        	zz9=((sqrt(3.0)+2.0)*float(radiusc/dl)-k+1);


//		        	div=float(radiusc)/float(dl);
//		        	cc=float(((xx1/(div))**2+(yy1/(div))**2+(zz1/(div))**2) );


//           print radiuscore,radiusshell,radiusc
            



		        	div=float(radiusc)/float(dl);
		        	cc=float(pow((xx1/(div)),2)+pow((yy1/(div)),2)+pow((zz1/(div)),2) );


		        	if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
						{
		        		A[a][b]=corenumber;
						}
						
		        	if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
						{
		        		A[a][b]=shellnumber;
						}

		        	if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
						{
		        		A[a][b]=cnum;
					}




		        	div=float(radiusc)/float(dl);
		        	cc=float(pow((xx2/(div)),2)+pow((yy2/(div)),2)+pow((zz2/(div)),2) );


		        	if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
						{
		        		A[a][b]=corenumber;
						}
						
		        	if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
						{
		        		A[a][b]=shellnumber;
						}

		        	if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
						{
		        		A[a][b]=cnum;
					}




		        	div=float(radiusc)/float(dl);
		        	cc=float(pow((xx3/(div)),2)+pow((yy3/(div)),2)+pow((zz3/(div)),2) );


		        	if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
						{
		        		A[a][b]=corenumber;
						}
						
		        	if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
						{
		        		A[a][b]=shellnumber;
						}

		        	if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
						{
		        		A[a][b]=cnum;
					}





		        	div=float(radiusc)/float(dl);
		        	cc=float(pow((xx4/(div)),2)+pow((yy4/(div)),2)+pow((zz4/(div)),2) );


		        	if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
						{
		        		A[a][b]=corenumber;
						}
						
		        	if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
						{
		        		A[a][b]=shellnumber;
						}

		        	if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
						{
		        		A[a][b]=cnum;
					}




		        	div=float(radiusc)/float(dl);
		        	cc=float(pow((xx5/(div)),2)+pow((yy5/(div)),2)+pow((zz5/(div)),2) );


		        	if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
						{
		        		A[a][b]=corenumber;
						}
						
		        	if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
						{
		        		A[a][b]=shellnumber;
						}

		        	if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
						{
		        		A[a][b]=cnum;
					}



		        	div=float(radiusc)/float(dl);
		        	cc=float(pow((xx6/(div)),2)+pow((yy6/(div)),2)+pow((zz6/(div)),2) );


		        	if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
						{
		        		A[a][b]=corenumber;
						}
						
		        	if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
						{
		        		A[a][b]=shellnumber;
						}

		        	if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
						{
		        		A[a][b]=cnum;
					}


	

		        	div=float(radiusc)/float(dl);
		        	cc=float(pow((xx7/(div)),2)+pow((yy7/(div)),2)+pow((zz7/(div)),2) );


		        	if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
						{
		        		A[a][b]=corenumber;
						}
						
		        	if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
						{
		        		A[a][b]=shellnumber;
						}

		        	if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
						{
		        		A[a][b]=cnum;
					}



//		        	div=float(radiusc)/float(dl);
//		        	cc=float(((xx8/(div))**2+(yy8/(div))**2+(zz8/(div))**2) );
		        	div=float(radiusc)/float(dl);
		        	cc=float(pow((xx8/(div)),2)+pow((yy8/(div)),2)+pow((zz8/(div)),2) );


		        	if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
						{
		        		A[a][b]=corenumber;
						}
						
		        	if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
						{
		        		A[a][b]=shellnumber;
						}

		        	if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
						{
		        		A[a][b]=cnum;
					}



		        	div=float(radiusc)/float(dl);
		        	cc=float(pow((xx9/(div)),2)+pow((yy9/(div)),2)+pow((zz9/(div)),2) );

	
		        	if ( ((cc))<= pow((((radiuscore)/(radiuscore+(radiusc-radiuscore)) )),2)) 
						{
						A[a][b]=corenumber;
						}

		        	if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
						{
		        		A[a][b]=shellnumber;
						}
	
		        	if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
						{
		        		A[a][b]=cnum;
						}





		        	ii=ii+1;

	
}	
}	
}	
	
	
	
	
return **A;


}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////



//int jonderstruct2 (xini,xfin,yini,yfin,zini,zfin,Npix,Npiy,Ntam,Dx1,Dy1,Dz1,radiusc,radiuscore,radiusshell,A,corenumber,shellnumber,cnum,dl,x,y,z,shape,base,width,height,base2,width2,radiusx1,radiusy1,radiusz1,radiusx2,radiusy2,radiusz2,radiusxcs,radiusycs,radiuszcs):
int jonderstruct2 (int xini,int xfin,int yini,int yfin,int zini,int zfin, int Npix,int Npiy,int Ntam, int Dx1,int Dy1,int Dz1,float radiusc,float radiuscore, float radiusshell,int **A,int corenumber,int shellnumber,int cnum,float dl,float x[80000],float y[80000],float z[80000],float base, float width,float height,float base2,float width2,float radiusx1,float radiusy1,float radiusz1,float radiusx2,float radiusy2,float radiusz2,float radiusxcs,float radiusycs,float radiuszcs,float cs)
{


	float xx1,yy1,zz1;
	float xx2,yy2,zz2;
	float xx3,yy3,zz3;
	float xx4,yy4,zz4;
	float xx5,yy5,zz5;
	float xx6,yy6,zz6;
	float xx7,yy7,zz7;
	float xx8,yy8,zz8;
	float xx9,yy9,zz9;
	float xx10,yy10,zz10;
	float xx11,yy11,zz11;
	float xx12,yy12,zz12;
	float xx13,yy13,zz13;
	float xx14,yy14,zz14;

	float div,cc;



	for (int k=zini;k<zfin+1;k++)
	{
		for (int j =yini; j< yfin+1;j++)
		{
		        for (int i=xini; i < xfin+1; i++)
		        {
		        
		        	int a=int(i);
		        	int b=int(j+(k-1)*Dy1);
		        	int ii=1;



		        	xx1=((1.0)*float(radiusc/dl)-i+1);
		        	yy1= ((1.0)*float(radiusc/dl)-j+1);
		        	zz1=(float(radiusc/dl)-k+1);
    

		        	xx2=((2.0+sqrt(3.0))*float(radiusc/dl)-i+1);
		        	yy2= ((1.0)*float(radiusc/dl)-j+1);
		        	zz2=(float(radiusc/dl)-k+1);



		        	xx3=((1.0)*float(radiusc/dl)-i+1);
		        	yy3= ((2.0+sqrt(3.0)) *float(radiusc/dl)-j+1);
		        	zz3=(float(radiusc/dl)-k+1);




		        	xx4=((2+sqrt(3.0))*float(radiusc/dl)-i+1);
		        	yy4= ((2+sqrt(3.0))*float(radiusc/dl)-j+1);
		        	zz4=(float(radiusc/dl)-k+1);




		        	xx5=((1.0+sqrt(2.0))*float(radiusc/dl)-i+1);
		        	yy5= ((1.0+sqrt(2.0))*float(radiusc/dl)-j+1);
		        	zz5=(float(radiusc/dl)-k+1);

//!!!!

		        	xx6=(1.0*float(radiusc/dl)-i+1);
		        	yy6= (1.0*float(radiusc/dl)-j+1);
		        	zz6=((2+sqrt(3.0))*float(radiusc/dl)-k+1);




		        	xx7=((2+sqrt(3.0))*float(radiusc/dl)-i+1);
		        	yy7= (1*float(radiusc/dl)-j+1);
		        	zz7=((2+sqrt(3.0))*float(radiusc/dl)-k+1);






		        	xx8=((1+sqrt(2.0))*float(radiusc/dl)-i+1);
		        	yy8= ((1)*float(radiusc/dl)-j+1);
		        	zz8=((1+sqrt(2.0))*float(radiusc/dl)-k+1);
    
		        	xx9=((1.0)*float(radiusc/dl)-i+1);
		        	yy9= ((2+sqrt(3.0))*float(radiusc/dl)-j+1);
		        	zz9=((2+sqrt(3.0))*float(radiusc/dl)-k+1);



		        	xx10=((2+sqrt(3.0))*float(radiusc/dl)-i+1);
		        	yy10= ((2+sqrt(3.0))*float(radiusc/dl)-j+1);
		        	zz10=((2+sqrt(3.0))*float(radiusc/dl)-k+1);



		        	xx11=((1.0+sqrt(2.0))*float(radiusc/dl)-i+1);
		        	yy11= ((2.0+sqrt(3.0))*float(radiusc/dl)-j+1);
		        	zz11=((1.0+sqrt(2.0))*float(radiusc/dl)-k+1);

		        	xx12=((2.0+sqrt(3.0))*float(radiusc/dl)-i+1);
		        	yy12= ((1.0+sqrt(2.0))*float(radiusc/dl)-j+1);
		        	zz12=((1.0+sqrt(2.0))*float(radiusc/dl)-k+1);

		        	xx13=((1.0+sqrt(2.0))*float(radiusc/dl)-i+1);
		        	yy13= ((1.0+sqrt(2.0))*float(radiusc/dl)-j+1);
		        	zz13=((2.0+sqrt(3.0))*float(radiusc/dl)-k+1);





		        	xx14=(1*float(radiusc/dl)-i+1);
		        	yy14= ((1.0+sqrt(2.0))*float(radiusc/dl)-j+1);
		        	zz14=((1.0+sqrt(2.0))*float(radiusc/dl)-k+1);






		        	div=float(radiusc)/float(dl);
		        	cc=float((pow((xx1/(div)),2)+pow((yy1/(div)),2)+pow((zz1/(div)),2)) );


//            print radiuscore,radiusshell,radiusc
            
		        	if ( ((cc))<= (pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2))) 
						{
		        		A[a][b]=corenumber;
						}
		        	if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
		        		{
		        		A[a][b]=shellnumber;
						}

		        	if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
						{
		        		A[a][b]=cnum;
						}
	



		        	div=float(radiusc)/float(dl);
		        	cc=float((pow((xx2/(div)),2)+pow((yy2/(div)),2)+pow((zz2/(div)),2)) );


//            print radiuscore,radiusshell,radiusc
            
		        	if ( ((cc))<= (pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2))) 
						{
		        		A[a][b]=corenumber;
						}
		        	if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
		        		{
		        		A[a][b]=shellnumber;
						}

		        	if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
						{
		        		A[a][b]=cnum;
						}
	
		        	div=float(radiusc)/float(dl);
		        	cc=float((pow((xx3/(div)),2)+pow((yy3/(div)),2)+pow((zz3/(div)),2)) );


//            print radiuscore,radiusshell,radiusc
            
		        	if ( ((cc))<= (pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2))) 
						{
		        		A[a][b]=corenumber;
						}
		        	if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
		        		{
		        		A[a][b]=shellnumber;
						}

		        	if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
						{
		        		A[a][b]=cnum;
						}
	


		        	div=float(radiusc)/float(dl);
		        	cc=float((pow((xx4/(div)),2)+pow((yy4/(div)),2)+pow((zz4/(div)),2)) );


//            print radiuscore,radiusshell,radiusc
            
		        	if ( ((cc))<= (pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2))) 
						{
		        		A[a][b]=corenumber;
						}
		        	if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
		        		{
		        		A[a][b]=shellnumber;
						}

		        	if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
						{
		        		A[a][b]=cnum;
						}
	


		        	div=float(radiusc)/float(dl);
		        	cc=float((pow((xx5/(div)),2)+pow((yy5/(div)),2)+pow((zz5/(div)),2)) );


//            print radiuscore,radiusshell,radiusc
            
		        	if ( ((cc))<= (pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2))) 
						{
		        		A[a][b]=corenumber;
						}
		        	if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
		        		{
		        		A[a][b]=shellnumber;
						}

		        	if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
						{
		        		A[a][b]=cnum;
						}
	

		        	div=float(radiusc)/float(dl);
		        	cc=float((pow((xx6/(div)),2)+pow((yy6/(div)),2)+pow((zz6/(div)),2)) );


//            print radiuscore,radiusshell,radiusc
            
		        	if ( ((cc))<= (pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2))) 
						{
		        		A[a][b]=corenumber;
						}
		        	if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
		        		{
		        		A[a][b]=shellnumber;
						}

		        	if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
						{
		        		A[a][b]=cnum;
						}
	





		        	div=float(radiusc)/float(dl);
		        	cc=float((pow((xx7/(div)),2)+pow((yy7/(div)),2)+pow((zz7/(div)),2)) );


//            print radiuscore,radiusshell,radiusc
            
		        	if ( ((cc))<= (pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2))) 
						{
		        		A[a][b]=corenumber;
						}
		        	if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
		        		{
		        		A[a][b]=shellnumber;
						}

		        	if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
						{
		        		A[a][b]=cnum;
						}
	








		        	div=float(radiusc)/float(dl);
		        	cc=float((pow((xx8/(div)),2)+pow((yy8/(div)),2)+pow((zz8/(div)),2)) );


//            print radiuscore,radiusshell,radiusc
            
		        	if ( ((cc))<= (pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2))) 
						{
		        		A[a][b]=corenumber;
						}
		        	if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
		        		{
		        		A[a][b]=shellnumber;
						}

		        	if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
						{
		        		A[a][b]=cnum;
						}
	










		        	div=float(radiusc)/float(dl);
		        	cc=float((pow((xx9/(div)),2)+pow((yy9/(div)),2)+pow((zz9/(div)),2)) );


//            print radiuscore,radiusshell,radiusc
            
		        	if ( ((cc))<= (pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2))) 
						{
		        		A[a][b]=corenumber;
						}
		        	if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
		        		{
		        		A[a][b]=shellnumber;
						}

		        	if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
						{
		        		A[a][b]=cnum;
						}
	







		        	div=float(radiusc)/float(dl);
		        	cc=float((pow((xx10/(div)),2)+pow((yy10/(div)),2)+pow((zz10/(div)),2)) );


//            print radiuscore,radiusshell,radiusc
            
		        	if ( ((cc))<= (pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2))) 
						{
		        		A[a][b]=corenumber;
						}
		        	if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
		        		{
		        		A[a][b]=shellnumber;
						}

		        	if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
						{
		        		A[a][b]=cnum;
						}
	








		        	div=float(radiusc)/float(dl);
		        	cc=float((pow((xx11/(div)),2)+pow((yy11/(div)),2)+pow((zz11/(div)),2)) );


//            print radiuscore,radiusshell,radiusc
            
		        	if ( ((cc))<= (pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2))) 
						{
		        		A[a][b]=corenumber;
						}
		        	if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
		        		{
		        		A[a][b]=shellnumber;
						}

		        	if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
						{
		        		A[a][b]=cnum;
						}
	








		        	div=float(radiusc)/float(dl);
		        	cc=float((pow((xx12/(div)),2)+pow((yy12/(div)),2)+pow((zz12/(div)),2)) );


//            print radiuscore,radiusshell,radiusc
            
		        	if ( ((cc))<= (pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2))) 
						{
		        		A[a][b]=corenumber;
						}
		        	if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
		        		{
		        		A[a][b]=shellnumber;
						}

		        	if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
						{
		        		A[a][b]=cnum;
						}
	








		        	div=float(radiusc)/float(dl);
		        	cc=float((pow((xx13/(div)),2)+pow((yy13/(div)),2)+pow((zz13/(div)),2)) );


//            print radiuscore,radiusshell,radiusc
            
		        	if ( ((cc))<= (pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2))) 
						{
		        		A[a][b]=corenumber;
						}
		        	if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
		        		{
		        		A[a][b]=shellnumber;
						}

		        	if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
						{
		        		A[a][b]=cnum;
						}
	




























		        	div=float(radiusc)/float(dl);
		        	cc=float((pow((xx14/(div)),2)+pow((yy14/(div)),2)+pow((zz14/(div)),2)) );


//            print radiuscore,radiusshell,radiusc
            
		        	if ( ((cc))<= (pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2))) 
						{
		        		A[a][b]=corenumber;
						}
		        	if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
		        		{
		        		A[a][b]=shellnumber;
						}

		        	if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
						{
		        		A[a][b]=cnum;
						}
	



		        	ii=ii+1;


}	
}	
}	
	
	
	
	
return **A;


}









//int pygeneral (xini,xfin,yini,yfin,zini,zfin,Npix,Npiy,Ntam,Dx1,Dy1,Dz1,radiusc,radiuscore,radiusshell,A,corenumber,shellnumber,cnum,dl,x,y,z,shape,base,width,height,base2,width2,radiusx1,radiusy1,radiusz1,radiusx2,radiusy2,radiusz2,radiusxcs,radiusycs,radiuszcs,cs,rcarbonpt,radiuspt,rcarbonpd,radiuspd,distcentro,alloynumber):
//int pygeneral (int xini,int xfin,int yini,int yfin,int zini,int zfin, int Npix,int Npiy,int Ntam, int Dx1,int Dy1,int Dz1,float radiusc,float radiuscore, float radiusshell,int **A,int corenumber,int shellnumber,int cnum,float dl,float x[80000],float y[80000],float z[80000],float base, float width,float height,float base2,float width2,float radiusx1,float radiusy1,float radiusz1,float radiusx2,float radiusy2,float radiusz2,float radiusxcs,float radiusycs,float radiuszcs,float cs,float rcarbonpt,float radiuspt,float rcarbonpd,float radiuspd,float distcentro,int alloynumber, int& index,int& aa,int& basex,int& basey,int& basez)
//pygeneral (xini,xfin,yini,yfin,zini,zfin,Npix,Npiy,Ntam,Dx1,Dy1,Dz1,radiusc,radiuscore,radiusshell,A,corenumber,shellnumber,cnum,dl,x,y,z,base,width,height,base2,width2,radiusx1,radiusy1,radiusz1,radiusx2,radiusy2,radiusz2,radiusxcs,radiusycs,radiuszcs,cs,rcarbonpt,radiuspt,rcarbonpd,radiuspd,distcentro,alloynumber,basex,basey,basez);

//	pygeneral (xini,xfin,yini,yfin,zini,zfin,Npix,Npiy,Ntam,Dx1,Dy1,Dz1,radiusc,radiuscore,radiusshell,A,corenumber,shellnumber,cnum,dl,x,y,z,base,width,height,base2,width2,radiusx1,radiusy1,radiusz1,radiusx2,radiusy2,radiusz2,radiusxcs,radiusycs,radiuszcs,cs,rcarbonpt,radiuspt,rcarbonpd,radiuspd,distcentro,alloynumber,basex,basey,basez, lenpystruc, heipystruc,pilingstruc, base, width, height, base2, width2);

//, float base, float width, float height, float base2, float width2


int pygeneral (int xini,int xfin,int yini,int yfin,int zini,int zfin, int Npix,int Npiy,int Ntam, int Dx1,int Dy1,int Dz1,float radiusc,float radiuscore, float radiusshell,int **A,int corenumber,int shellnumber,int cnum,float dl,float x[80000],float y[80000],float z[80000],float base, float width,float height,float base2,float width2,float radiusx1,float radiusy1,float radiusz1,float radiusx2,float radiusy2,float radiusz2,float radiusxcs,float radiusycs,float radiuszcs,float cs,float rcarbonpt,float radiuspt,float rcarbonpd,float radiuspd,float distcentro,int alloynumber, int basex,int basey, int basez, float lenpystruc, float heipystruc, char* pilingstruc, int partes, int indorigins, int radiussurface, int surfaceindex, int xlength, int ylength, int zlength, int xlength2, int ylength2, int zlength2, int halfsphereradius1, int halfsphereradius2, int segmentheight, int segmentradius1, int segmentradius2, int pillheight1, int pillheight2, int pillradius1,  int pillradius2)
{
// else if (pilingstruc == (char*)"ellipsoidal")

	float radiuscxx=radiusc;
	float radiuscyy=radiusc;
	float radiusczz=radiusc;


	if (pilingstruc == (char*)"ellipsoidal" or pilingstruc == (char*)"cylinder")
	{

		radiuscxx=radiusxcs;
		radiuscyy=radiusycs;
		radiusczz=radiuszcs;
		
	}	
	
	
	if (pilingstruc == (char*)"cylinder")
	{


	radiuscore =radiusxcs;
	radiusshell = radiusxcs+10;
	radiusc = radiusshell+10.0;



		radiuscxx=radiusc;
		radiuscyy=radiusc;
		radiusczz=radiusc;



	}



	if (pilingstruc == (char*)"octahedron")
	{


//	radiuscore =radiusxcs;
//	radiusshell = radiusxcs+10;
	radiusc = radiusshell+10.0;

cout << "eeee"<< "octa"<< endl;


		radiuscxx=radiusc;
		radiuscyy=radiusc;
		radiusczz=radiusc;



	}





	if (pilingstruc == (char*)"triplate")
	{

	if(base2> width2)
			{
		radiusc=base2+cs;
			}
	else
		{

		radiusc=width2+cs;
		
		}
	
	cout<< "triiiiiiiii"<< radiuscxx << "raddd" << endl;


		radiuscxx=radiusc;
		radiuscyy=radiusc;
		radiusczz=radiusc;


	}


//	float div;

	

	float radiuscini=lenpystruc;

for (int k=zini;k<zfin+1;k++)
	{


	if(pilingstruc == (char*) "pyramid")

	{
	radiusc=radiuscini -(k-1)*radiuscini/(zfin-1);

	}
//	cout <<radiusc << "herreeeee"<<endl;


	if(radiusc<=0.0)	
	{
	break;
	}


//		cout <<zini<< "zinnniii"<<radiusc << "radiusc" << endl;


		for (int j =yini; j< yfin+1;j++)
		{
		        for (int i=xini; i < xfin+1; i++)
		        {
		        
//		        	int a=int(i);
//		        	int b=int(j+(k-1)*Dy1);
		        	int ii=1;

//						radiusc=lenpystruc;

				        for (int h=zini; h < Ntam+1;h++)
						{
				    	        int Npiyw=Npiy-(h-1);
				    	        int w=Npiyw;
//					print h					
//								radiuscini=radiusc-(h-1)*radiusc/(Ntam);
							


				    	        while (w > 0)
								{
				    	        	int Npixg=Npix-(h-1);
						
				    	        	int g=Npixg;

				    	        	while (g>0)
									{
//				    	        		float div=float(radiusc/dl);

//										radiusc=radiusc-k*dl

//										cout << Ntam << "ntam"<< zfin<< "zfinnnn" <<h<< "hhhh" << endl;



//				    	        		x[ii]= float((((float((1-(g-1)*sqrt(3.0)+Npiy)))*div-i+2)))
//				    	        		y[ii]= float(((float((-1+1-(g-1)+2*(w-1)+Npiy))*div-j)+2))
//				    	        		z[ii]= float(((float((sqrt(3.0)*(h-1)+1))*div-k+2)))

// for the pyramid!!!

//				    	        		x[ii]= float((((float(2.0*(g-1)+1+(h-1)))*float(radiuscini)/float(dl)-float(i))));
//				    	        		y[ii]= float((((float(2.0*(w-1)+1+(h-1)))*float(radiuscini)/float(dl)-float(j))));
//				    	        		z[ii]= float((((float(sqrt(3.0)*(h-1)+1))*float(heipystruc)/float(dl)-float(k))));
	

				    	        		x[ii]= float((((float(2.0*(g-1)+1+(h-1)))*float(radiuscxx)/float(dl)-float(i))));
				    	        		y[ii]= float((((float(2.0*(w-1)+1+(h-1)))*float(radiuscyy)/float(dl)-float(j))));
				    	        		z[ii]= float((((float(sqrt(3.0)*(h-1)+1))*float(radiusczz)/float(dl)-float(k))));
										
//										cout << radiusc <<radiuscxx << radiuscyy<< radiusczz << "radiusss"<< endl;
										

										int index=0;

										int aa=0;
										
//										in_pyramid(ii, cnum,radiusc,radiuscore,radiusshell,corenumber,shellnumber,dl,h,x,y,z,index,aa,basex,basey,basez, lenpystruc, heipystruc,i,j,k,xini,xfin,yini,yfin,zini,zfin,radiuscini);

// int in_pyramid(int ii, int cnum,float radiusc,float radiuscore,float radiusshell,int corenumber,int shellnumber,float dl,int h, float x[80000], float y[80000], float z[80000],int& aa,int& index,int& basex,int& basey,int& basez, float lenpystruc, float heipystruc)



//										incoreshell_sphere(ii,cnum,radiusc,radiuscore,radiusshell,corenumber,shellnumber,dl,h,x,y,z,index,aa);
//										sphere_interpen(ii,cnum,radiusc,radiuscore,radiusshell,corenumber,shellnumber,dl,h,x,y,z, aa,index,basex,basey,basez, lenpystruc, heipystruc,i,int j,int k,int xini,int xfin,int yini,int yfin,int zini,int zfin, float radiuscini, float radiuspt, float radiuspd, float distcentro,float rcarbonpt,float rcarbonpd, int alloynumber);

//										sphere_interpen(ii,cnum,radiusc,radiuscore,radiusshell,corenumber,shellnumber,dl,h,x,y,z, aa,index,basex,basey,basez, lenpystruc, heipystruc,i,j,k,xini,xfin,yini,yfin,zini,zfin,radiuscini,radiuspt,radiuspd,distcentro,rcarbonpt,rcarbonpd,alloynumber);
//
//										incoreshell_ellipsoid(ii,cnum,radiusc,radiuscore,radiusshell,corenumber,shellnumber,dl,h,x,y,z, aa,index,basex,basey,basez, lenpystruc, heipystruc,i,j,k,xini,xfin,yini,yfin,zini,zfin,radiuscini,radiuspt,radiuspd,distcentro,rcarbonpt,rcarbonpd,alloynumber, radiusxcs, radiusycs, radiuszcs,pilingstruc);

//										incoreshell_cylinder(ii,cnum,radiusc,radiuscore,radiusshell,corenumber,shellnumber,dl,h,x,y,z,aa,index,basex,basey,basez,lenpystruc,heipystruc,i,j,k,xini,xfin,yini,yfin,zini,zfin,radiuscini,radiuspt,radiuspd,distcentro,rcarbonpt,rcarbonpd,alloynumber,radiusxcs,radiusycs,radiuszcs,pilingstruc);

//										incoreshell_octahedron(ii,cnum,radiusc,radiuscore,radiusshell,corenumber,shellnumber,dl,h,x,y,z,aa,index,basex,basey,basez,lenpystruc,heipystruc,i,j,k,xini,xfin,yini,yfin,zini,zfin,radiuscini,radiuspt,radiuspd,distcentro,rcarbonpt,rcarbonpd,alloynumber,radiusxcs,radiusycs,radiuszcs,pilingstruc);

//		int incoreshell_triplate(int ii, int cnum,float radiusc,float radiuscore,float radiusshell,int corenumber,int shellnumber,float dl,int h, float x[80000], float y[80000], float z[80000],int& aa,int& index,int& basex,int& basey,int& basez, float lenpystruc, float heipystruc,int i,int j,int k,int xini,int xfin,int yini,int yfin,int zini,int zfin, float radiuscini, float radiuspt, float radiuspd, float distcentro,float rcarbonpt,float rcarbonpd,int alloynumber, float radiusxcs, float radiusycs, float radiuszcs, char* pilingstruc,float base,float width,float height,float base2,float width2)

//										incoreshell_triplate(ii,cnum,radiusc,radiuscore,radiusshell,corenumber,shellnumber,dl,h,x,y,z,aa,index,basex,basey,basez,lenpystruc,heipystruc,i,j,k,xini,xfin,yini,yfin,zini,zfin,radiuscini,radiuspt,radiuspd,distcentro,rcarbonpt,rcarbonpd,alloynumber,radiusxcs,radiusycs,radiuszcs,pilingstruc, base, width, height, base2, width2, cs);



//										incoreshell_cubic(ii,cnum,radiusc,radiuscore,radiusshell,corenumber,shellnumber,dl,h,x,y,z,aa,index,basex,basey,basez,lenpystruc,heipystruc,i,j,k,xini,xfin,yini,yfin,zini,zfin,radiuscini,radiuspt,radiuspd,distcentro,rcarbonpt,rcarbonpd,alloynumber,radiusxcs,radiusycs,radiuszcs,pilingstruc, base, width, height, base2, width2, cs);

//					incoreshell_manyshell(int ii, int cnum,float radiusc,float radiuscore,float radiusshell,int corenumber,int shellnumber,float dl,int h, float x[80000], float y[80000], float z[80000],int& aa,int& index,int& basex,int& basey,int& basez, float lenpystruc, float heipystruc,int i,int j,int k,int xini,int xfin,int yini,int yfin,int zini,int zfin, float radiuscini, float radiuspt, float radiuspd, float distcentro,float rcarbonpt,float rcarbonpd,int alloynumber, float radiusxcs, float radiusycs, float radiuszcs, char* pilingstruc,float base,float width,float height,float base2,float width2,float cs, int partes, int indorigins)

//										incoreshell_spheresurfacetwo(ii,cnum,radiusc,radiuscore,radiusshell,corenumber,shellnumber,dl,h,x,y,z,index,aa, radiussurface, surfaceindex);

//										incoreshell_pavingstone(ii,cnum,radiusc,radiuscore,radiusshell,corenumber,shellnumber,dl,h,x,y,z,aa,index,basex,basey,basez,lenpystruc,heipystruc,i,j,k,xini,xfin,yini,yfin,zini,zfin,radiuscini,radiuspt,radiuspd,distcentro,rcarbonpt,rcarbonpd,alloynumber,radiusxcs,radiusycs,radiuszcs,pilingstruc, base, width, height, base2, width2, cs, xlength, ylength, zlength, xlength2, ylength2, zlength2);

//										incoreshell_halfsphere(ii,cnum,radiusc,radiuscore,radiusshell,corenumber,shellnumber,dl,h,x,y,z,index,aa,halfsphereradius1,halfsphereradius2);


//										incoreshell_segmentsphere(ii,cnum,radiusc,radiuscore,radiusshell,corenumber,shellnumber,dl,h,x,y,z,index,aa,segmentheight,segmentradius1,segmentradius2);

										incoreshell_pill(ii,cnum,radiusc,radiuscore,radiusshell,corenumber,shellnumber,dl,h,x,y,z,index,aa,pillheight1,pillheight2,pillradius1,pillradius2);



//int incoreshell_ellipsoid(int ii, int cnum,float radiusc,float radiuscore,float radiusshell,int corenumber,int shellnumber,float dl,int h, float x[80000], float y[80000], float z[80000],int& aa,int& index,int& basex,int& basey,int& basez, float lenpystruc, float heipystruc,int i,int j,int k,int xini,int xfin,int yini,int yfin,int zini,int zfin, float radiuscini, float radiuspt, float radiuspd, float distcentro,float rcarbonpt,float rcarbonpd,int alloynumber, float radiusxcs, float radiusycs, float radiuszcs)


//										int incoreshell_ellipsoid(int ii, int cnum,float radiusc,float radiuscore,float radiusshell,int corenumber,int shellnumber,float dl,int h, float x[80000], float y[80000], float z[80000],int& aa,int& index,int& basex,int& basey,int& basez, float lenpystruc, float heipystruc,int i,int j,int k,int xini,int xfin,int yini,int yfin,int zini,int zfin, float radiuscini, float radiuspt, float radiuspd, float distcentro,float rcarbonpt,float rcarbonpd,int alloynumber, float radiusxcs, float radiusycs, float radiuszcs)



//int sphere_interpen(int ii, int cnum,float radiusc,float radiuscore,float radiusshell,int corenumber,int shellnumber,float dl,int h, float x[80000], float y[80000], float z[80000],int& aa,int& index,int& basex,int& basey,int& basez, float lenpystruc, float heipystruc,int i,int j,int k,int xini,int xfin,int yini,int yfin,int zini,int zfin, float radiuscini, float radiuspt, float radiuspd, float distcentro,float rcarbonpt,float rcarbonpd,int alloynumber)//int sphere_interpen(int ii, int cnum,float radiusc,float radiuscore,float radiusshell,int corenumber,int shellnumber,float dl,int h, float x[80000], float y[80000], float z[80000],int& aa,int& index,int& basex,int& basey,int& basez, float lenpystruc, float heipystruc,int i,int j,int k,int xini,int xfin,int yini,int yfin,int zini,int zfin, float radiuscini, float radiuspt, float radiuspd, float distcentro,float rcarbonpt,float rcarbonpd,int alloynumber))

										if (aa==1)
										{
// corrigir aqui para fazer matriz 2D
										A[i][j+(k-1)*Dy1] = index;

//											cout<< aa <<"aa"<<"matrizele" << A[i][j+(k-1)*Dy1] << index<< endl;

										}



						    	        g=g-1;
			            			
//							print ii,A[a][b]
						    	        ii=ii+1;
									}
//							print g
					    	        w=w-1;
								}
//						print w


}
}
}
}

	return **A;
}





/////////////////////////////////////////////////////////////////////////////////////////////////////////////






//hexpyramid (xini,xfin,yini,yfin,zini,zfin,Npix,Npiy,Ntam,Dx1,Dy1,Dz1,radiusc,radiuscore,radiusshell,A,corenumber,shellnumber,cnum,dl,x,y,z,base,width,height,base2,width2,radiusx1,radiusy1,radiusz1,radiusx2,radiusy2,radiusz2,radiusxcs,radiusycs,radiuszcs):
int hexpyramid (int xini,int xfin,int yini,int yfin,int zini,int zfin, int Npix,int Npiy,int Ntam, int Dx1,int Dy1,int Dz1,float radiusc,float radiuscore, float radiusshell,int **A,int corenumber,int shellnumber,int cnum,float dl,float x[80000],float y[80000],float z[80000],float base, float width,float height,float base2,float width2,float radiusx1,float radiusy1,float radiusz1,float radiusx2,float radiusy2,float radiusz2,float radiusxcs,float radiusycs,float radiuszcs,float cs,float rcarbonpt,float radiuspt,float rcarbonpd,float radiuspd,float distcentro,int alloynumber)
{


int Npixn= int(Npix*2*radiusc/dl);
int Npiyn= int(Npiy*2*radiusc/dl);
int Ntamn= int(Ntam*2*radiusc/dl);

int Nmaiorini;
int box=0;

Nmaiorini=Ntamn;
//int Nmenorini=Npix;








int Npixw;

//float div;

//	for v in range(1,5):
for(int v=1;v<5;v++)
{
	for (int k=1;k<Ntamn+1;k++)
	{
		for (int j =1; j< Npiyn+1;j++)
		{
		        for (int i=1; i < Npixn+1; i++)
		        {
		        
		        	int ii=1;



//			        	for h in range (1, Ntam+1):	
					for(int h=1;h<Ntam+1;h++)
					{
			        		int Npiyw=Npiy;
//	#	w=Npiyw/2

//			        		int Npixg=Npix;
// #	g=Npixg/2

							Npiyw=Npiy-2*(h-1);
							Npixw=Npix-2*(h-1);


							if(Npiyw<=2 or Npixw <=2)
							{
							Npiyw=2;
							Npixw=2;
							}



							for (int w=1;w<int(Npiyw/2+1);w++)
							{
			        			box=box+1;
//			        			Npixg=Npixg-1;

	
//			        			for g in range(1,int(Npixg/2+1)):
								for(int g=1;g<int(Npixw/2+1);g++)
								{


	int steptocor=4-1;



if (h < Nmaiorini)
{

	//		        					div=float(radiusc/dl);


//									cout<<A[i][j+(k-1)*Dy1]<<endl;
			        				if (v==1)
										{
		//	        					div=float(radiusc/dl);

			        					//x[ii]= float((((float((1+(g-1)*sqrt(3.0)+Npiyw)))*div-i+2)));
			        					//y[ii]= float(((float((+1+(g-1)+2*(w-1)))*div-j)+2));
			        					//z[ii]= float(((float((sqrt(3.0)*(h-1)+1))*div-k+2)));
										x[ii]= float((((1+(g-1)*sqrt(3.0)+Npiy))*radiusc/dl-i+2));
										y[ii]= float(((+1+(g-1)+steptocor+2*(w-1)+2*(h-1))*radiusc/dl-j)+2);
										z[ii]= float(((sqrt(3.0)*(h-1)+1)*radiusc/dl-k+2));

										}



			        				if (v==2)
										{
			//        					div=float(radiusc/dl);

			        					//x[ii]= float((((float((1-(g-1)*sqrt(3.0)+Npiyw)))*div-i+2)));
			        					//y[ii]= float(((float((+1+(g-1)+2*(w-1)))*div-j)+2));
			        					//z[ii]= float(((float((sqrt(3.0)*(h-1)+1))*div-k+2)));
										x[ii]= ((((1-(g-1)*sqrt(3.0)+Npiy))*radiusc/dl-i+2));
										y[ii]= (((+1+(g-1)+steptocor+2*(w-1)+2*(h-1))*radiusc/dl-j)+2);
										z[ii]= (((sqrt(3.0)*(h-1)+1)*radiusc/dl-k+2));
										}

	
			        				if (v==3 )
										{
			  //      					div=float(radiusc/dl);
			
		
			        					//x[ii]= float((((float((1+(g-1)*sqrt(3.0)+Npiyw)))*div-i+2)));
			        					//y[ii]= float(((float((-1+1-(g-1)+2*(w-1)+Npiyw))*div-j)+2));
			        					//z[ii]= float(((float((sqrt(3.0)*(h-1)+1))*div-k+2)));
										x[ii]= ((((1+(g-1)*sqrt(3.0)+Npiy))*radiusc/dl-i+2));
										y[ii]= (((-1+1+steptocor-(g-1)+2*(w-1)+Npiyw+2*(h-1))*radiusc/dl-j)+2);
										z[ii]= (((sqrt(3.0)*(h-1)+1)*radiusc/dl-k+2));



										}

			        				if (v==4 )
										{
	
			    //    					div=float(radiusc/dl);


//			        					x[ii]= float((((float((1-(g-1)*sqrt(3.0)+Npiyw)))*div-i+2)));
	//		        					y[ii]= float(((float((-1+1-(g-1)+2*(w-1)+Npiyw))*div-j)+2));
		//	        					z[ii]= float(((float((sqrt(3.0)*(h-1)+1))*div-k+2)));

										x[ii]= ((((1-(g-1)*sqrt(3.0)+Npiy))*radiusc/dl-i+2));
										y[ii]= (((-1+1-(g-1)+steptocor+2*(w-1)+Npiyw+2*(h-1))*radiusc/dl-j)+2);
										z[ii]= (((sqrt(3.0)*(h-1)+1)*radiusc/dl-k+2));


										}

}



if (h == Nmaiorini)
{
	x[ii]= ((((1+(g-1)*sqrt(3.0)+Npiy))*radiusc/dl-i+2));
	y[ii]= ((((g-1)+steptocor+2*(w-1)+2*(h-1))*radiusc/dl-j)+2);
	z[ii]= (((sqrt(3.0)*(h-1)+1)*radiusc/dl-k+2));
}




										int index=0;

										int aa=0;
	
										incoreshell_sphere(ii,cnum,radiusc,radiuscore,radiusshell,corenumber,shellnumber,dl,h,x,y,z,index,aa);

//									cout<<ii<< "ii"<<endl;


										if (aa==1)
										{
// corrigir aqui para fazer matriz 2D
										A[i][j+(k-1)*Dy1] = index;
										}






	
	//		        				g=g-1;




			        				ii=ii+1;
										}
		//	        			w=w-1;


}
}
}
}
}
}



	return **A;

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////



// hexmono (xini,xfin,yini,yfin,zini,zfin,Npix,Npiy,Ntam,Dx1,Dy1,Dz1,radiusc,radiuscore,radiusshell,A,corenumber,shellnumber,cnum,dl,x,y,z,shape,base,width,height,base2,width2,radiusx1,radiusy1,radiusz1,radiusx2,radiusy2,radiusz2,radiusxcs,radiusycs,radiuszcs)
int hexmono (int xini,int xfin,int yini,int yfin,int zini,int zfin, int Npix,int Npiy,int Ntam, int Dx1,int Dy1,int Dz1,float radiusc,float radiuscore, float radiusshell,int **A,int corenumber,int shellnumber,int cnum,float dl,float x[80000],float y[80000],float z[80000],float base, float width,float height,float base2,float width2,float radiusx1,float radiusy1,float radiusz1,float radiusx2,float radiusy2,float radiusz2,float radiusxcs,float radiusycs,float radiuszcs,float cs,float rcarbonpt,float radiuspt,float rcarbonpd,float radiuspd,float distcentro,int alloynumber, int hex_layers)
{
	
float div;

for(int v=1;v<5;v++)
{
	for (int k=zini;k<zfin+1;k++)
	{
		for (int j =yini; j< yfin+1;j++)
		{
		        for (int i=xini; i < xfin+1; i++)
		        {
		        
		        	int ii=1;

			        	for (int h=1; h< Ntam+1;h++)
						{
//			        		int Npiyw=Npiy;

			        		int Npixg=Npix;
			        		int box=0;
						
			        		for (int w=1;w < int(Npiy/2)+1;w++)
							{
			        			box=box+1;
			        			Npixg=Npixg-1;
	

			        			for(int g=1; g< int(Npix/2+1);g++)
								{


			        				if (v==1)
									{
			        					div=float(radiusc/dl);


			        					x[ii]= float((((float((1+(g-1)*sqrt(3.0)+Npiy)))*div-i+2)));
			        					y[ii]= float(((float((+1+(g-1)+2*(w-1)))*div-j)+2));
			        					z[ii]= float(((float((sqrt(3.0)*(h-1)+1))*div-k+2)));
									}

			        				if (v==2)

									{
			        					div=float(radiusc/dl);


			        					x[ii]= float((((float((1-(g-1)*sqrt(3.0)+Npiy)))*div-i+2)));
			        					y[ii]= float(((float((+1+(g-1)+2*(w-1)))*div-j)+2));
			        					z[ii]= float(((float((sqrt(3.0)*(h-1)+1))*div-k+2)));

	
									}
			        				if (v==3 )
									{
			        					div=float(radiusc/dl);
									
	
			        					x[ii]= float((((float((1+(g-1)*sqrt(3.0)+Npiy)))*div-i+2)));
			        					y[ii]= float(((float((-1+1-(g-1)+2*(w-1)+Npiy))*div-j)+2));
			        					z[ii]= float(((float((sqrt(3.0)*(h-1)+1))*div-k+2)));
									}

			        				if (v==4 )
									{
	
			        					div=float(radiusc/dl);



			        					x[ii]= float((((float((1-(g-1)*sqrt(3.0)+Npiy)))*div-i+2)));
			        					y[ii]= float(((float((-1+1-(g-1)+2*(w-1)+Npiy))*div-j)+2));
			        					z[ii]= float(((float((sqrt(3.0)*(h-1)+1))*div-k+2)));

									}


	
										int index=0;

										int aa=0;
	
										incoreshell_sphere(ii,cnum,radiusc,radiuscore,radiusshell,corenumber,shellnumber,dl,h,x,y,z,index,aa);

//									cout<<ii<< "ii"<<endl;


										if (aa==1)
										{
// corrigir aqui para fazer matriz 2D
										A[i][j+(k-1)*Dy1] = index;
										}





	
			        				ii=ii+1;


}
}
}
}
}
}
}


	return **A;

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////


// hex1 (xini,xfin,yini,yfin,zini,zfin,Npix,Npiy,Ntam,Dx1,Dy1,Dz1,radiusc,radiuscore,radiusshell,A,corenumber,shellnumber,cnum,dl,x,y,z,shape,base,width,height,base2,width2,radiusx1,radiusy1,radiusz1,radiusx2,radiusy2,radiusz2,radiusxcs,radiusycs,radiuszcs):
int hex1 (int xini,int xfin,int yini,int yfin,int zini,int zfin, int Npix,int Npiy,int Ntam, int Dx1,int Dy1,int Dz1,float radiusc,float radiuscore, float radiusshell,int **A,int corenumber,int shellnumber,int cnum,float dl,float x[80000],float y[80000],float z[80000],float base, float width,float height,float base2,float width2,float radiusx1,float radiusy1,float radiusz1,float radiusx2,float radiusy2,float radiusz2,float radiusxcs,float radiusycs,float radiuszcs,float cs,float rcarbonpt,float radiuspt,float rcarbonpd,float radiuspd,float distcentro,int alloynumber, int hex_layers)
{

	float div;
	float cc;

	float xx1,yy1,zz1;
	float xx2,yy2,zz2;
	float xx3,yy3,zz3;
	float xx4,yy4,zz4;
	float xx5,yy5,zz5;
	float xx6,yy6,zz6;
	float xx7,yy7,zz7;
	float xx8,yy8,zz8;
	float xx9,yy9,zz9;
	float xx10,yy10,zz10;
	float xx11,yy11,zz11;

	for (int k = zini; k < zfin+1;k++)
		{
	    for (int j = yini;j < yfin+1; j++)
	     {
			for (int i=xini; j < xfin+1;j++)
			{
//	            a=int(i)
//	            b=int(j+(k-1)*Dy1)


	            xx1 = float(((float(3.0*radiusc))/float(dl)-float(i)));
	            yy1 = float(((float(3.0*radiusc))/float(dl)-float(j)));
	            zz1 = float(((float(radiusc))/float(dl)-float(k+1)+float(1)));

	            xx2 = float(((float(2.0*radiusc))/float(dl)-float(i)));  
	            yy2 = float(((float((3.0-sqrt(3.0))*radiusc))/float(dl)-float(j))); 
	            zz2 = float(((float(radiusc))/float(dl)-float(k+1)+float(1)));

	            xx3 = float(((float(4.0*radiusc))/float(dl)-float(i)));  
	            yy3= float(((float((3.0-sqrt(3.0))*radiusc))/float(dl)-float(j))); 
	            zz3 = float(((float(radiusc))/float(dl)-float(k+1)+float(1)));

	            xx4 = float(((float(2.0*radiusc))/float(dl)-float(i)));  
	            yy4 = float(((float((3.0+sqrt(3.0))*radiusc))/float(dl)-float(j))); 
	            zz4 = float(((float(radiusc))/float(dl)-float(k+1)+float(1)));

	            xx5 = float(((float(4.0*radiusc))/float(dl)-float(i)));  
	            yy5 = float(((float((3.0+sqrt(3.0))*radiusc))/float(dl)-float(j))); 
	            zz5 = float(((float(radiusc))/float(dl)-float(k+1)+float(1)));

	            xx6 = float(((float(1.0*radiusc))/float(dl)-float(i)));  
	            yy6 = float(((float(3.0*radiusc))/float(dl)-float(j))); 
	            zz6 = float(((float(radiusc))/float(dl)-float(k+1)+float(1)));

	            xx7 = float(((float(5.0*radiusc))/float(dl)-float(i)));  
	            yy7 = float(((float(3.0*radiusc))/float(dl)-float(j))); 
	            zz7 = float(((float(radiusc))/float(dl)-float(k+1)+float(1)));

// second layer

	            xx8 = float(((float(4.0*radiusc))/float(dl)-float(i)));  
	            yy8 = float(((float(4.0*radiusc))/float(dl)-float(j))); 
	            zz8 = float(((float((1.0+sqrt(3.0))*radiusc))/float(dl)-float(k+1)+float(1)));

	            xx9 = float(((float(4.0*radiusc))/float(dl)-float(i)));  
	            yy9 = float(((float(2.0*radiusc))/float(dl)-float(j))); 
	            zz9 = float(((float((1.0+sqrt(3.0))*radiusc))/float(dl)-float(k+1)+float(1)));

	            xx10 = float(((float((3.0-sqrt(3.0)/2)*radiusc))/float(dl)-float(i)));  
	            yy10 = float(((float(3.0*radiusc))/float(dl)-float(j))); 
	            zz10 = float(((float((1.0+sqrt(3.0))*radiusc))/float(dl)-float(k+1)+float(1)));
	
// third layer

	            xx11 = float(((float(3.0*radiusc))/float(dl)-float(i)));  
	            yy11 = float(((float(3.0*radiusc))/float(dl)-float(j))); 
	            zz11 = float(((float((1.0+2*sqrt(3.0))*radiusc))/float(dl)-float(k+1)+float(1)));

	            int a=int(i);
	            int b=int(j+(k-1)*Dy1);

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx1/(div),2)+pow(yy1/(div),2)+pow(zz1/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx2/(div),2)+pow(yy2/(div),2)+pow(zz2/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx3/(div),2)+pow(yy3/(div),2)+pow(zz3/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx4/(div),2)+pow(yy4/(div),2)+pow(zz4/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx5/(div),2)+pow(yy5/(div),2)+pow(zz5/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx6/(div),2)+pow(yy6/(div),2)+pow(zz6/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx7/(div),2)+pow(yy7/(div),2)+pow(zz7/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

				if(hex_layers>= 2)
				{


	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx8/(div),2)+pow(yy8/(div),2)+pow(zz8/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx9/(div),2)+pow(yy9/(div),2)+pow(zz9/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx10/(div),2)+pow(yy10/(div),2)+pow(zz10/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

			}


			if(hex_layers>= 3)
			{
	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx11/(div),2)+pow(yy11/(div),2)+pow(zz11/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}
			}







}
}
}


	return **A;

}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////


// def hex2 (xini,xfin,yini,yfin,zini,zfin,Npix,Npiy,Ntam,Dx1,Dy1,Dz1,radiusc,radiuscore,radiusshell,A,corenumber,shellnumber,cnum,dl,x,y,z,shape,base,width,height,base2,width2,radiusx1,radiusy1,radiusz1,radiusx2,radiusy2,radiusz2,radiusxcs,radiusycs,radiuszcs):
int hex2 (int xini,int xfin,int yini,int yfin,int zini,int zfin, int Npix,int Npiy,int Ntam, int Dx1,int Dy1,int Dz1,float radiusc,float radiuscore, float radiusshell,int **A,int corenumber,int shellnumber,int cnum,float dl,float x[80000],float y[80000],float z[80000],float base, float width,float height,float base2,float width2,float radiusx1,float radiusy1,float radiusz1,float radiusx2,float radiusy2,float radiusz2,float radiusxcs,float radiusycs,float radiuszcs,float cs,float rcarbonpt,float radiuspt,float rcarbonpd,float radiuspd,float distcentro,int alloynumber, int hex_layers)
{

	float div;
	float cc;

	float xx1,yy1,zz1;
	float xx2,yy2,zz2;
	float xx3,yy3,zz3;
	float xx4,yy4,zz4;
	float xx5,yy5,zz5;
	float xx6,yy6,zz6;
	float xx7,yy7,zz7;
	float xx8,yy8,zz8;
	float xx9,yy9,zz9;
	float xx10,yy10,zz10;
	float xx11,yy11,zz11;
	float xx12,yy12,zz12;
	float xx13,yy13,zz13;
	float xx14,yy14,zz14;




	for (int k = zini; k < zfin+1;k++)
		{
	    for (int j = yini;j < yfin+1; j++)
	     {
			for (int i=xini; j < xfin+1;j++)
			{


// first layer

//	            int a=int(i);
//	            int b=int(j+(k-1)*Dy1);


        	    xx1=float((float((3)*radiusc/dl)-float(i)+1));
        	    yy1= float((float((3)*radiusc/dl)-float(j)+1));
        	    zz1=float((float(radiusc/dl)-float(k)+1));
    
        	    xx2=float((float((3-1.0)*radiusc/dl)-float(i)+1));
        	    yy2= float((float((3-sqrt(3.0)))*radiusc/dl-float(j)+1));
        	    zz2=float((float(radiusc/dl)-float(k)+1));

        	    xx3=float(((3.0+1.0)*float(radiusc/dl)-float(i)+1));
        	    yy3= float(((3.0-sqrt(3.0))*float(radiusc/dl)-j+1));
        	    zz3=float((float(radiusc/dl)-float(k)+1));

        	    xx4=float(((3.0-1.0)*float(radiusc/dl)-float(i)+1));
        	    yy4= float(((3.0+sqrt(3.0))*float(radiusc/dl)-float(j)+1));
        	    zz4=float((float(radiusc/dl)-float(k)+1));

        	    xx5=float(((3.0+1.0)*float(radiusc/dl)-float(i)+1));
        	    yy5= float(((3.0+sqrt(3.0))*float(radiusc/dl)-float(j)+1));
        	    zz5=float((float(radiusc/dl)-float(k)+1));

        	    xx6=float((1.0*float(radiusc/dl)-float(i)+1));
        	    yy6= float((3.0*float(radiusc/dl)-float(j)+1));
        	    zz6=float((float(radiusc/dl)-float(k)+1));

        	    xx7=float((5.0*float(radiusc/dl)-float(i)+1));
        	    yy7= float((3.0*float(radiusc/dl)-float(j)+1));
        	    zz7=float((float(radiusc/dl)-float(k)+1));
// second layer

        	    xx8=float(((3.0-1.0)*float(radiusc/dl)-float(i)+1));
        	    yy8= float(((3.0)*float(radiusc/dl)-float(j)+1));
        	    zz8=float(((1.0+sqrt(3.0))*float(radiusc/dl)-float(k)+1));

        	    xx9=float(((3+1)*float(radiusc/dl)-float(i)+1));
        	    yy9= float(((3.0)*float(radiusc/dl)-float(j)+1));
        	    zz9= float(((1.0+sqrt(3.0))*float(radiusc/dl)-float(k)+1));

        	    xx10= float(((3.0)*float(radiusc/dl)-float(i)+1));
        	    yy10= float(((3.0-1.0-sqrt(2.0)/2)*float(radiusc/dl)-float(j)+1));
        	    zz10= float(((1.0+sqrt(3.0))*float(radiusc/dl)-float(k)+1));

        	    xx11=float(((3.0)*float(radiusc/dl)-float(i)+1));
        	    yy11= float(((3.0+1.0+sqrt(2.0)/2)*float(radiusc/dl)-float(j)+1));
        	    zz11= float(((1.0+1.0*sqrt(3.0))*float(radiusc/dl)-float(k)+1));

// third layer

        	    xx12= float(((3.0)*float(radiusc/dl)-float(i)+1));
        	    yy12= float(((3.0-sqrt(3.0)/2)*float(radiusc/dl)-float(j)+1));
        	    zz12= float(((1.0+2*sqrt(3.0))*float(radiusc/dl)-float(k)+1));

        	    xx13= float(((3.0)*float(radiusc/dl)-float(i)+1));
        	    yy13= float(((3.0+sqrt(3.0)/2)*float(radiusc/dl)-float(j)+1));
        	    zz13= float(((1.0+2.0*sqrt(3.0))*float(radiusc/dl)-float(k)+1));

// fourth layer

        	    xx14=float(((3.0)*float(radiusc/dl)-float(i)+1));
        	    yy14= float(((3.0)*float(radiusc/dl)-float(j)+1));
        	    zz14=float(((1.0+3.0*sqrt(3.0))*float(radiusc/dl)-float(k)+1));


	            int a=int(i);
	            int b=int(j+(k-1)*Dy1);

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx1/(div),2)+pow(yy1/(div),2)+pow(zz1/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx2/(div),2)+pow(yy2/(div),2)+pow(zz2/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx3/(div),2)+pow(yy3/(div),2)+pow(zz3/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx4/(div),2)+pow(yy4/(div),2)+pow(zz4/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx5/(div),2)+pow(yy5/(div),2)+pow(zz5/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx6/(div),2)+pow(yy6/(div),2)+pow(zz6/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx7/(div),2)+pow(yy7/(div),2)+pow(zz7/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}


				if(hex_layers >= 2)
				{


	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx8/(div),2)+pow(yy8/(div),2)+pow(zz8/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx9/(div),2)+pow(yy9/(div),2)+pow(zz9/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx10/(div),2)+pow(yy10/(div),2)+pow(zz10/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx11/(div),2)+pow(yy11/(div),2)+pow(zz11/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

				}

			if(hex_layers >= 3)
			{


	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx12/(div),2)+pow(yy12/(div),2)+pow(zz12/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx13/(div),2)+pow(yy13/(div),2)+pow(zz13/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

				}

			if(hex_layers>= 4)
			{



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx14/(div),2)+pow(yy14/(div),2)+pow(zz14/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}
			}





}
}
}


	return **A;

}



//def hex3 (xini,xfin,yini,yfin,zini,zfin,Npix,Npiy,Ntam,Dx1,Dy1,Dz1,radiusc,radiuscore,radiusshell,A,corenumber,shellnumber,cnum,dl,x,y,z,shape,base,width,height,base2,width2,radiusx1,radiusy1,radiusz1,radiusx2,radiusy2,radiusz2,radiusxcs,radiusycs,radiuszcs):
int hex3 (int xini,int xfin,int yini,int yfin,int zini,int zfin, int Npix,int Npiy,int Ntam, int Dx1,int Dy1,int Dz1,float radiusc,float radiuscore, float radiusshell,int **A,int corenumber,int shellnumber,int cnum,float dl,float x[80000],float y[80000],float z[80000],float base, float width,float height,float base2,float width2,float radiusx1,float radiusy1,float radiusz1,float radiusx2,float radiusy2,float radiusz2,float radiusxcs,float radiusycs,float radiuszcs,float cs,float rcarbonpt,float radiuspt,float rcarbonpd,float radiuspd,float distcentro,int alloynumber,int hex_layers)
{

	float div;
	float cc;

	float xx1,yy1,zz1;
	float xx2,yy2,zz2;
	float xx3,yy3,zz3;
	float xx4,yy4,zz4;
	float xx5,yy5,zz5;
	float xx6,yy6,zz6;
	float xx7,yy7,zz7;
	float xx8,yy8,zz8;
	float xx9,yy9,zz9;
	float xx10,yy10,zz10;
	float xx11,yy11,zz11;
	float xx12,yy12,zz12;
//	float xx13,yy13,zz13;
//	float xx14,yy14,zz14;




	for (int k = zini; k < zfin+1;k++)
		{
	    for (int j = yini;j < yfin+1; j++)
	     {
			for (int i=xini; j < xfin+1;j++)
			{


// first layer

	            int a=int(i);
	            int b=int(j+(k-1)*Dy1);




	            xx1=float(((3.0)*float(radiusc/dl)-float(i)+1));
	            yy1= float(((3.0)*float(radiusc/dl)-float(j)+1));
	            zz1=float((float(radiusc/dl)-float(k)+1));
    
	            xx2= float(((3.0-1.0)*float(radiusc/dl)-float(i)+1));
	            yy2= float(((3.0-sqrt(3.0))*float(radiusc/dl)-float(j)+1));
	            zz2= float((float(radiusc/dl)-float(k)+1));

	            xx3=float(((3.0+1.0)*float(radiusc/dl)-float(i)+1));
	            yy3= float(((3.0-sqrt(3.0))*float(radiusc/dl)-float(j)+1));
	            zz3= float((float(radiusc/dl)-float(k)+1));

	            xx4= float(((3.0-1.0)*float(radiusc/dl)-float(i)+1));
	            yy4= float(((3.0+sqrt(3.0))*float(radiusc/dl)-float(j)+1));
	            zz4= float((float(radiusc/dl)-float(k)+1));

	            xx5= float(((3.0+1.0)*float(radiusc/dl)-float(i)+1));
	            yy5= float(((3.0+sqrt(3.0))*float(radiusc/dl)-float(j)+1));
	            zz5= float((float(radiusc/dl)-float(k)+1));

	            xx6=float((1.0*float(radiusc/dl)-float(i)+1));
	            yy6= float((3.0*float(radiusc/dl)-float(j)+1));
	            zz6= float((float(radiusc/dl)-float(k)+1));

	            xx7=float((5.0*float(radiusc/dl)-float(i)+1));
	            yy7= float((3.0*float(radiusc/dl)-float(j)+1));
	            zz7= float((float(radiusc/dl)-float(k)+1));

// second layer


	            xx8= float(((3.0-1.0)*float(radiusc/dl)-float(i)+1));
	            yy8= float(((3.0)*float(radiusc/dl)-float(j)+1));
	            zz8= float(((1.0+sqrt(3.0))*float(radiusc/dl)-float(k)+1));

	            xx9= float(((3.0+1.0)*float(radiusc/dl)-float(i)+1));
	            yy9= float(((3.0)*float(radiusc/dl)-float(j)+1));
	            zz9= float(((1+sqrt(3.0))*float(radiusc/dl)-float(k)+1));

	            xx10= float(((3.0)*float(radiusc/dl)-float(i)+1));
	            yy10= float(((3.0-1.0-sqrt(2.0)/2)*float(radiusc/dl)-float(j)+1));
	            zz10= float(((1.0+sqrt(3.0))*float(radiusc/dl)-float(k)+1));

	            xx11= float(((3.0)*float(radiusc/dl)-float(i)+1));
	            yy11= float(((3.0+1.0+sqrt(2.0)/2)*float(radiusc/dl)-float(j)+1));
	            zz11= float(((1.0+1.0*sqrt(3.0))*float(radiusc/dl)-float(k)+1));

// third layer

	            xx12= float(((3)*float(radiusc/dl)-float(i)+1));
	            yy12= float(((3)*float(radiusc/dl)-float(j)+1));
	            zz12= float(((1+2*sqrt(3.0))*float(radiusc/dl)-float(k)+1));

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx1/(div),2)+pow(yy1/(div),2)+pow(zz1/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx2/(div),2)+pow(yy2/(div),2)+pow(zz2/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx3/(div),2)+pow(yy3/(div),2)+pow(zz3/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx4/(div),2)+pow(yy4/(div),2)+pow(zz4/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx5/(div),2)+pow(yy5/(div),2)+pow(zz5/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx6/(div),2)+pow(yy6/(div),2)+pow(zz6/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx7/(div),2)+pow(yy7/(div),2)+pow(zz7/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}


				if(hex_layers >= 2)
				{


	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx8/(div),2)+pow(yy8/(div),2)+pow(zz8/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx9/(div),2)+pow(yy9/(div),2)+pow(zz9/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx10/(div),2)+pow(yy10/(div),2)+pow(zz10/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx11/(div),2)+pow(yy11/(div),2)+pow(zz11/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}


				}


				if(hex_layers >= 3)
				{



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx12/(div),2)+pow(yy12/(div),2)+pow(zz12/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

				}






}
}
}


	return **A;

}



int hex4 (int xini,int xfin,int yini,int yfin,int zini,int zfin, int Npix,int Npiy,int Ntam, int Dx1,int Dy1,int Dz1,float radiusc,float radiuscore, float radiusshell,int **A,int corenumber,int shellnumber,int cnum,float dl,float x[80000],float y[80000],float z[80000],float base, float width,float height,float base2,float width2,float radiusx1,float radiusy1,float radiusz1,float radiusx2,float radiusy2,float radiusz2,float radiusxcs,float radiusycs,float radiuszcs,float cs,float rcarbonpt,float radiuspt,float rcarbonpd,float radiuspd,float distcentro,int alloynumber,int hex_layers)
{

	float div;
	float cc;

	float xx1,yy1,zz1;
	float xx2,yy2,zz2;
	float xx3,yy3,zz3;
	float xx4,yy4,zz4;
	float xx5,yy5,zz5;
	float xx6,yy6,zz6;
	float xx7,yy7,zz7;
	float xx8,yy8,zz8;
	float xx9,yy9,zz9;
	float xx10,yy10,zz10;
	float xx11,yy11,zz11;
	float xx12,yy12,zz12;
	float xx13,yy13,zz13;
	float xx14,yy14,zz14;
	float xx15,yy15,zz15;
	float xx16,yy16,zz16;
	float xx17,yy17,zz17;
	float xx18,yy18,zz18;
	float xx19,yy19,zz19;
	float xx20,yy20,zz20;
	float xx21,yy21,zz21;




	for (int k = zini; k < zfin+1;k++)
		{
	    for (int j = yini;j < yfin+1; j++)
	     {
			for (int i=xini; j < xfin+1;j++)
			{


// first layer

	            int a=int(i);
	            int b=int(j+(k-1)*Dy1);


	            xx1= float(((3.0)*float(radiusc/dl)-float(i)+1));
	            yy1= float(((3.0)*float(radiusc/dl)-float(j)+1));
	            zz1= float((float(radiusc/dl)-float(k)+1));
    
	            xx2= float(((3.0-1.0)*float(radiusc/dl)-float(i)+1));
	            yy2= float(((3.0-sqrt(3.0))*float(radiusc/dl)-float(j)+1));
	            zz2= float((float(radiusc/dl)-float(k)+1));

	            xx3= float(((3.0+1.0)*float(radiusc/dl)-float(i)+1));
	            yy3= float(((3.0-sqrt(3.0))*float(radiusc/dl)-float(j)+1));
	            zz3= float((float(radiusc/dl)-float(k)+1));

	            xx4= float(((3.0-1.0)*float(radiusc/dl)-float(i)+1));
	            yy4= float(((3.0+sqrt(3.0))*float(radiusc/dl)-float(j)+1));
	            zz4= float((float(radiusc/dl)-float(k)+1));

	            xx5=float(((3.0+1.0)*float(radiusc/dl)-float(i)+1));
	            yy5= float(((3.0+sqrt(3.0))*float(radiusc/dl)-float(j)+1));
	            zz5= float((float(radiusc/dl)-float(k)+1));

	            xx6= float((1.0*float(radiusc/dl)-float(i)+1));
	            yy6= float((3.0*float(radiusc/dl)-float(j)+1));
	            zz6= float((float(radiusc/dl)-float(k)+1));

	            xx7= float((5.0*float(radiusc/dl)-float(i)+1));
	            yy7= float((3.0*float(radiusc/dl)-float(j)+1));
	            zz7= float((1.0*float(radiusc/dl)-float(k)+1));


//	            print(xx1,xx2,xx3,xx4,xx5,xx6,xx7)
// second layer


	            xx8= float(((3.0)*float(radiusc/dl)-float(i)+1));
	            yy8= float(((3.0)*float(radiusc/dl)-float(j)+1));
	            zz8= float((3.0*float(radiusc/dl)-float(k)+1));
    
	            xx9= float(((3.0-1.0)*float(radiusc/dl)-float(i)+1));
	            yy9= float(((3.0-sqrt(3.0))*float(radiusc/dl)-float(j)+1));
	            zz9= float((3.0*float(radiusc/dl)-float(k)+1));

	            xx10=float(((3.0+1.0)*float(radiusc/dl)-float(i)+1));
	            yy10= float(((3.0-sqrt(3.0))*float(radiusc/dl)-float(j)+1));
	            zz10= float((3.0*float(radiusc/dl)-float(k)+1));

	            xx11= float(((3.0-1.0)*float(radiusc/dl)-float(i)+1));
	            yy11= float(((3.0+sqrt(3.0))*float(radiusc/dl)-float(j)+1));
	            zz11= float((3.0*float(radiusc/dl)-float(k)+1));

	            xx12= float(((3.0+1.0)*float(radiusc/dl)-float(i)+1));
	            yy12= float(((3.0+sqrt(3.0))*float(radiusc/dl)-float(j)+1));
	            zz12= float((3.0*float(radiusc/dl)-float(k)+1));

	            xx13= float((1.0*float(radiusc/dl)-float(i)+1));
	            yy13= float((3.0*float(radiusc/dl)-float(j)+1));
	            zz13= float((3.0*float(radiusc/dl)-float(k)+1));

	            xx14=float((5.0*float(radiusc/dl)-float(i)+1));
	            yy14= float((3.0*float(radiusc/dl)-float(j)+1));
	            zz14= float((3.0*float(radiusc/dl)-float(k)+1));


// third layer


	            xx15=float(((3.0)*float(radiusc/dl)-float(i)+1));
	            yy15= float(((3.0)*float(radiusc/dl)-float(j)+1));
	            zz15= float((5.0*float(radiusc/dl)-float(k)+1));
    
	            xx16= float(((3.0-1.0)*float(radiusc/dl)-float(i)+1));
	            yy16= float(((3.0-sqrt(3.0))*float(radiusc/dl)-float(j)+1));
	            zz16= float((5.0*float(radiusc/dl)-float(k)+1));

	            xx17= float(((3.0+1.0)*float(radiusc/dl)-float(i)+1));
	            yy17= float(((3.0-sqrt(3.0))*float(radiusc/dl)-float(j)+1));
	            zz17=float((5.0*float(radiusc/dl)-float(k)+1));

	            xx18= float(((3.0-1.0)*float(radiusc/dl)-float(i)+1));
	            yy18= float(((3.0+sqrt(3.0))*float(radiusc/dl)-float(j)+1));
	            zz18= float((5.0*float(radiusc/dl)-float(k)+1));

	            xx19= float(((3.0+1.0)*float(radiusc/dl)-float(i)+1));
	            yy19= float(((3.0+sqrt(3.0))*float(radiusc/dl)-float(j)+1));
	            zz19=float((5.0*float(radiusc/dl)-float(k)+1));

	            xx20= float((1.0*float(radiusc/dl)-float(i)+1));
	            yy20= float((3.0*float(radiusc/dl)-float(j)+1));
	            zz20= float((5.0*float(radiusc/dl)-float(k)+1));

	            xx21= float((5.0*float(radiusc/dl)-float(i)+1));
	            yy21= float((3.0*float(radiusc/dl)-float(j)+1));
	            zz21= float((5.0*float(radiusc/dl)-float(k)+1));






	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx1/(div),2)+pow(yy1/(div),2)+pow(zz1/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx2/(div),2)+pow(yy2/(div),2)+pow(zz2/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx3/(div),2)+pow(yy3/(div),2)+pow(zz3/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx4/(div),2)+pow(yy4/(div),2)+pow(zz4/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx5/(div),2)+pow(yy5/(div),2)+pow(zz5/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx6/(div),2)+pow(yy6/(div),2)+pow(zz6/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx7/(div),2)+pow(yy7/(div),2)+pow(zz7/(div),2)) );

				if(hex_layers >=2)
				{

            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx8/(div),2)+pow(yy8/(div),2)+pow(zz8/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx9/(div),2)+pow(yy9/(div),2)+pow(zz9/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx10/(div),2)+pow(yy10/(div),2)+pow(zz10/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx11/(div),2)+pow(yy11/(div),2)+pow(zz11/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}


	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx12/(div),2)+pow(yy12/(div),2)+pow(zz12/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx13/(div),2)+pow(yy13/(div),2)+pow(zz13/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx14/(div),2)+pow(yy14/(div),2)+pow(zz14/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

			}
			if(hex_layers >=3)
			{




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx15/(div),2)+pow(yy15/(div),2)+pow(zz15/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx16/(div),2)+pow(yy16/(div),2)+pow(zz16/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx17/(div),2)+pow(yy17/(div),2)+pow(zz17/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx18/(div),2)+pow(yy18/(div),2)+pow(zz18/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx19/(div),2)+pow(yy19/(div),2)+pow(zz19/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx20/(div),2)+pow(yy20/(div),2)+pow(zz20/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx21/(div),2)+pow(yy21/(div),2)+pow(zz21/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

		}







}
}
}


	return **A;

}



int hex5 (int xini,int xfin,int yini,int yfin,int zini,int zfin, int Npix,int Npiy,int Ntam, int Dx1,int Dy1,int Dz1,float radiusc,float radiuscore, float radiusshell,int **A,int corenumber,int shellnumber,int cnum,float dl,float x[80000],float y[80000],float z[80000],float base, float width,float height,float base2,float width2,float radiusx1,float radiusy1,float radiusz1,float radiusx2,float radiusy2,float radiusz2,float radiusxcs,float radiusycs,float radiuszcs,float cs,float rcarbonpt,float radiuspt,float rcarbonpd,float radiuspd,float distcentro,int alloynumber,int hex_layers)
{

	float div;
	float cc;

	float xx1,yy1,zz1;
	float xx2,yy2,zz2;
	float xx3,yy3,zz3;
	float xx4,yy4,zz4;
	float xx5,yy5,zz5;
	float xx6,yy6,zz6;
	float xx7,yy7,zz7;
	float xx8,yy8,zz8;
	float xx9,yy9,zz9;
	float xx10,yy10,zz10;
	float xx11,yy11,zz11;
	float xx12,yy12,zz12;
	float xx13,yy13,zz13;
	float xx14,yy14,zz14;
	float xx15,yy15,zz15;
	float xx16,yy16,zz16;
	float xx17,yy17,zz17;
	float xx18,yy18,zz18;
	float xx19,yy19,zz19;
	float xx20,yy20,zz20;
	float xx21,yy21,zz21;




	for (int k = zini; k < zfin+1;k++)
		{
	    for (int j = yini;j < yfin+1; j++)
	     {
			for (int i=xini; j < xfin+1;j++)
			{


// first layer

	            int a=int(i);
	            int b=int(j+(k-1)*Dy1);


	            xx1=float(((3.0)*float(radiusc/dl)-float(i)+1));
	            yy1= float(((3.0)*float(radiusc/dl)-float(j)+1));
	            zz1=float((float(radiusc/dl)-k+1));
    
	            xx2=((3-1.0)*radiusc/dl-i+1);
	            yy2= ((3-sqrt(3.0))*radiusc/dl-j+1);
	            zz2=(radiusc/dl-k+1);

	            xx3=((3+1.0)*radiusc/dl-i+1);
	            yy3= ((3-sqrt(3.0))*radiusc/dl-j+1);
	            zz3=(radiusc/dl-k+1);

	            xx4=((3-1.0)*radiusc/dl-i+1);
	            yy4= ((3+sqrt(3.0))*radiusc/dl-j+1);
	            zz4=(radiusc/dl-k+1);

	            xx5=((3+1.0)*radiusc/dl-i+1);
	            yy5= ((3+sqrt(3.0))*radiusc/dl-j+1);
	            zz5=(radiusc/dl-k+1);

	            xx6=(1*radiusc/dl-i+1);
	            yy6= (3*radiusc/dl-j+1);
	            zz6=(radiusc/dl-k+1);

	            xx7=(5*radiusc/dl-i+1);
	            yy7= (3*radiusc/dl-j+1);
	            zz7=(1*radiusc/dl-k+1);

// second layer

	            xx8=((3)*radiusc/dl-i+1);
	            yy8= ((3)*radiusc/dl-j+1);
	            zz8=(3*radiusc/dl-k+1);
    
	            xx9=((3-1.0)*radiusc/dl-i+1);
	            yy9= ((3-sqrt(3.0))*radiusc/dl-j+1);
	            zz9=(3*radiusc/dl-k+1);

	            xx10=((3+1.0)*radiusc/dl-i+1);
	            yy10= ((3-sqrt(3.0))*radiusc/dl-j+1);
	            zz10=(3*radiusc/dl-k+1);

	            xx11=float(((3-1.0)*radiusc/dl-i+1));
	            yy11= float(((3+sqrt(3.0))*radiusc/dl-j+1));
	            zz11=float((3*radiusc/dl-k+1));

	            xx12=((3+1.0)*radiusc/dl-i+1);
	            yy12= ((3+sqrt(3.0))*radiusc/dl-j+1);
	            zz12=(3*radiusc/dl-k+1);

	            xx13=(1*radiusc/dl-i+1);
	            yy13= (3*radiusc/dl-j+1);
	            zz13=(3*radiusc/dl-k+1);

	            xx14=(5*radiusc/dl-i+1);
	            yy14= (3*radiusc/dl-j+1);
	            zz14=(3*radiusc/dl-k+1);

// third layer

	            xx15=((3-1)*radiusc/dl-i+1);
	            yy15= ((3)*radiusc/dl-j+1);
	            zz15=((3+sqrt(3.0))*radiusc/dl-k+1);

	            xx16=((3+1)*radiusc/dl-i+1);
	            yy16= ((3)*radiusc/dl-j+1);
	            zz16=((3+sqrt(3.0))*radiusc/dl-k+1);

	            xx17=((3)*radiusc/dl-i+1);
	            yy17= ((3-1-sqrt(2.0)/2)*radiusc/dl-j+1);
	            zz17=((3+sqrt(3.0))*radiusc/dl-k+1);

	            xx18=((3)*radiusc/dl-i+1);
	            yy18= ((3+1+sqrt(2.0)/2)*radiusc/dl-j+1);
	            zz18=((3+1*sqrt(3.0))*radiusc/dl-k+1);

// fourth layer

	            xx19=((3)*radiusc/dl-i+1);
	            yy19= ((3-sqrt(3.0)/2)*radiusc/dl-j+1);
	            zz19=((3+2*sqrt(3.0))*radiusc/dl-k+1);

	            xx20=((3)*radiusc/dl-i+1);
	            yy20= ((3+sqrt(3.0)/2)*radiusc/dl-j+1);
	            zz20=((3+2*sqrt(3.0))*radiusc/dl-k+1);

// fifth layer

	            xx21=((3)*radiusc/dl-i+1);
	            yy21= ((3)*radiusc/dl-j+1);
	            zz21=((4+3*sqrt(3.0))*radiusc/dl-k+1);





	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx1/(div),2)+pow(yy1/(div),2)+pow(zz1/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx2/(div),2)+pow(yy2/(div),2)+pow(zz2/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx3/(div),2)+pow(yy3/(div),2)+pow(zz3/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx4/(div),2)+pow(yy4/(div),2)+pow(zz4/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx5/(div),2)+pow(yy5/(div),2)+pow(zz5/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx6/(div),2)+pow(yy6/(div),2)+pow(zz6/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx7/(div),2)+pow(yy7/(div),2)+pow(zz7/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}


				if(hex_layers >=2)
				{



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx8/(div),2)+pow(yy8/(div),2)+pow(zz8/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx9/(div),2)+pow(yy9/(div),2)+pow(zz9/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx10/(div),2)+pow(yy10/(div),2)+pow(zz10/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx11/(div),2)+pow(yy11/(div),2)+pow(zz11/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}


	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx12/(div),2)+pow(yy12/(div),2)+pow(zz12/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx13/(div),2)+pow(yy13/(div),2)+pow(zz13/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx14/(div),2)+pow(yy14/(div),2)+pow(zz14/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

			}
				if(hex_layers >=3)
				{


	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx15/(div),2)+pow(yy15/(div),2)+pow(zz15/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx16/(div),2)+pow(yy16/(div),2)+pow(zz16/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx17/(div),2)+pow(yy17/(div),2)+pow(zz17/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx18/(div),2)+pow(yy18/(div),2)+pow(zz18/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}


				}
				if(hex_layers >=4)
				{




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx19/(div),2)+pow(yy19/(div),2)+pow(zz19/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx20/(div),2)+pow(yy20/(div),2)+pow(zz20/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

			}
			if(hex_layers >=5)
			{


	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx21/(div),2)+pow(yy21/(div),2)+pow(zz21/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}


			}






}
}
}


	return **A;

}















int hex6 (int xini,int xfin,int yini,int yfin,int zini,int zfin, int Npix,int Npiy,int Ntam, int Dx1,int Dy1,int Dz1,float radiusc,float radiuscore, float radiusshell,int **A,int corenumber,int shellnumber,int cnum,float dl,float x[80000],float y[80000],float z[80000],float base, float width,float height,float base2,float width2,float radiusx1,float radiusy1,float radiusz1,float radiusx2,float radiusy2,float radiusz2,float radiusxcs,float radiusycs,float radiuszcs,float cs,float rcarbonpt,float radiuspt,float rcarbonpd,float radiuspd,float distcentro,int alloynumber,int hex_layers)
{

	float div;
	float cc;

	float xx1,yy1,zz1;
	float xx2,yy2,zz2;
	float xx3,yy3,zz3;
	float xx4,yy4,zz4;
	float xx5,yy5,zz5;
	float xx6,yy6,zz6;
	float xx7,yy7,zz7;
	float xx8,yy8,zz8;
	float xx9,yy9,zz9;
	float xx10,yy10,zz10;
	float xx11,yy11,zz11;
	float xx12,yy12,zz12;
	float xx13,yy13,zz13;
	float xx14,yy14,zz14;
	float xx15,yy15,zz15;
	float xx16,yy16,zz16;
	float xx17,yy17,zz17;
	float xx18,yy18,zz18;
	float xx19,yy19,zz19;
	float xx20,yy20,zz20;
	float xx21,yy21,zz21;
	float xx22,yy22,zz22;
	float xx23,yy23,zz23;
	float xx24,yy24,zz24;
	float xx25,yy25,zz25;
	float xx26,yy26,zz26;
	float xx27,yy27,zz27;
	float xx28,yy28,zz28;
	float xx29,yy29,zz29;
	float xx30,yy30,zz30;
	float xx31,yy31,zz31;
	float xx32,yy32,zz32;
	float xx33,yy33,zz33;
	float xx34,yy34,zz34;
	float xx35,yy35,zz35;
	float xx36,yy36,zz36;
	float xx37,yy37,zz37;
	float xx38,yy38,zz38;
	float xx39,yy39,zz39;
	float xx40,yy40,zz40;
	float xx41,yy41,zz41;
	float xx42,yy42,zz42;
	float xx43,yy43,zz43;
	float xx44,yy44,zz44;
	float xx45,yy45,zz45;
	float xx46,yy46,zz46;
	float xx47,yy47,zz47;
	float xx48,yy48,zz48;
	float xx49,yy49,zz49;
	float xx50,yy50,zz50;
	float xx51,yy51,zz51;
	float xx52,yy52,zz52;
	float xx53,yy53,zz53;
	float xx54,yy54,zz54;
	float xx55,yy55,zz55;
	float xx56,yy56,zz56;
	float xx57,yy57,zz57;




	for (int k = zini; k < zfin+1;k++)
		{
	    for (int j = yini;j < yfin+1; j++)
	     {
			for (int i=xini; j < xfin+1;j++)
			{


// first layer

	            int a=int(i);
	            int b=int(j+(k-1)*Dy1);






	            xx1=((6)*radiusc/dl-i+1);
	            yy1= ((6)*radiusc/dl-j+1);
	            zz1=(radiusc/dl-k+1);
    
	            xx2=((6-1.0)*radiusc/dl-i+1);
	            yy2= ((6-sqrt(3.0))*radiusc/dl-j+1);
	            zz2=(radiusc/dl-k+1);

	            xx3=((6+1.0)*radiusc/dl-i+1);
	            yy3= ((6-sqrt(3.0))*radiusc/dl-j+1);
	            zz3=(radiusc/dl-k+1);

	            xx4=((6-1.0)*radiusc/dl-i+1);
	            yy4= ((6+sqrt(3.0))*radiusc/dl-j+1);
	            zz4=(radiusc/dl-k+1);

	            xx5=((6+1.0)*radiusc/dl-i+1);
	            yy5= ((6+sqrt(3.0))*radiusc/dl-j+1);
	            zz5=(radiusc/dl-k+1);

	            xx6=(4*radiusc/dl-i+1);
	            yy6= (6*radiusc/dl-j+1);
	            zz6=(radiusc/dl-k+1);

	            xx7=(8*radiusc/dl-i+1);
	            yy7= (6*radiusc/dl-j+1);
	            zz7=(1*radiusc/dl-k+1);

	            xx8=((6)*radiusc/dl-i+1);
	            yy8= ((8+sqrt(2.0))*radiusc/dl-j+1);
	            zz8=(1*radiusc/dl-k+1);
    
	            xx9=((6)*radiusc/dl-i+1);
	            yy9= ((4-sqrt(2.0))*radiusc/dl-j+1);
	            zz9=(1*radiusc/dl-k+1);

	            xx10=((10.0)*radiusc/dl-i+1);
	            yy10= ((6.0)*radiusc/dl-j+1);
	            zz10=(1*radiusc/dl-k+1);

	            xx11=((3-1.0)*radiusc/dl-i+1);
	            yy11= ((6.0)*radiusc/dl-j+1);
	            zz11=(1*radiusc/dl-k+1);

	            xx12=((3)*radiusc/dl-i+1);
	            yy12= ((6-sqrt(3.0))*radiusc/dl-j+1);
	            zz12=(1*radiusc/dl-k+1);

	            xx13=(9*radiusc/dl-i+1);
	            yy13= ((6-sqrt(3.0))*radiusc/dl-j+1);
	            zz13=(1*radiusc/dl-k+1);

	            xx14=((9+0.05)*radiusc/dl-i+1);
	            yy14= ((6+sqrt(3.0))*radiusc/dl-j+1);
	            zz14=(1*radiusc/dl-k+1);


	            xx15=((3)*radiusc/dl-i+1);
	            yy15= ((6+sqrt(3.0))*radiusc/dl-j+1);
	            zz15=((1)*radiusc/dl-k+1);

	            xx16=((3+1+0.05)*radiusc/dl-i+1);
	            yy16= ((11-sqrt(3.0)+0.15)*radiusc/dl-j+1);
	            zz16=((1)*radiusc/dl-k+1);

	            xx17=((8)*radiusc/dl-i+1);
	            yy17= ((11-sqrt(3.0)+0.15)*radiusc/dl-j+1);
	            zz17=((1)*radiusc/dl-k+1);

	            xx18=((8)*radiusc/dl-i+1);
	            yy18= ((1+sqrt(3.0)-0.1)*radiusc/dl-j+1);
	            zz18=((1)*radiusc/dl-k+1);


	            xx19=((4)*radiusc/dl-i+1);
	            yy19= ((1+sqrt(3.0)-0.1)*radiusc/dl-j+1);
	            zz19=((1)*radiusc/dl-k+1);

// second layer


	            xx20=((6)*radiusc/dl-i+1);
	            yy20= ((6)*radiusc/dl-j+1);
	            zz20=(3*radiusc/dl-k+1);
    
	            xx21=((6-1.0)*radiusc/dl-i+1);
	            yy21= ((6-sqrt(3.0))*radiusc/dl-j+1);
	            zz21=(3*radiusc/dl-k+1);

	            xx22=((6+1.0)*radiusc/dl-i+1);
	            yy22= ((6-sqrt(3.0))*radiusc/dl-j+1);
	            zz22=(3*radiusc/dl-k+1);

	            xx23=((6-1.0)*radiusc/dl-i+1);
	            yy23= ((6+sqrt(3.0))*radiusc/dl-j+1);
	            zz23=(3*radiusc/dl-k+1);

	            xx24=((6+1.0)*radiusc/dl-i+1);
	            yy24= ((6+sqrt(3.0))*radiusc/dl-j+1);
	            zz24=(3*radiusc/dl-k+1);

	            xx25=(4*radiusc/dl-i+1);
	            yy25= (6*radiusc/dl-j+1);
	            zz25=(3*radiusc/dl-k+1);

	            xx26=(8*radiusc/dl-i+1);
	            yy26= (6*radiusc/dl-j+1);
	            zz26=(3*radiusc/dl-k+1);

	            xx27=((6)*radiusc/dl-i+1);
	            yy27= ((8+sqrt(2.0))*radiusc/dl-j+1);
	            zz27=(3*radiusc/dl-k+1);
    
	            xx28=((6)*radiusc/dl-i+1);
	            yy28= ((4-sqrt(2.0))*radiusc/dl-j+1);
	            zz28=(3*radiusc/dl-k+1);

	            xx29=((10.0)*radiusc/dl-i+1);
	            yy29= ((6.0)*radiusc/dl-j+1);
	            zz29=(3*radiusc/dl-k+1);

	            xx30=((3-1.0)*radiusc/dl-i+1);
	            yy30= ((6.0)*radiusc/dl-j+1);
	            zz30=(3*radiusc/dl-k+1);

	            xx31=((3)*radiusc/dl-i+1);
	            yy31= ((6-sqrt(3.0))*radiusc/dl-j+1);
	            zz31=(3*radiusc/dl-k+1);

	            xx32=(9*radiusc/dl-i+1);
	            yy32= ((6-sqrt(3.0))*radiusc/dl-j+1);
	            zz32=(3*radiusc/dl-k+1);

	            xx33=((9+0.05)*radiusc/dl-i+1);
	            yy33= ((6+sqrt(3.0))*radiusc/dl-j+1);
	            zz33=(3*radiusc/dl-k+1);


	            xx34=((3)*radiusc/dl-i+1);
	            yy34= ((6+sqrt(3.0))*radiusc/dl-j+1);
	            zz34=((3)*radiusc/dl-k+1);

	            xx35=((3+1+0.05)*radiusc/dl-i+1);
	            yy35= ((11-sqrt(3.0)+0.15)*radiusc/dl-j+1);
	            zz35=((3)*radiusc/dl-k+1);

	            xx36=((8)*radiusc/dl-i+1);
	            yy36= ((11-sqrt(3.0)+0.15)*radiusc/dl-j+1);
	            zz36=((3)*radiusc/dl-k+1);

	            xx37=((8)*radiusc/dl-i+1);
	            yy37= ((1+sqrt(3.0)-0.1)*radiusc/dl-j+1);
	            zz37=((3)*radiusc/dl-k+1);


	            xx38=((4)*radiusc/dl-i+1);
	            yy38= ((1+sqrt(3.0)-0.1)*radiusc/dl-j+1);
	            zz38=((3)*radiusc/dl-k+1);


// third layer

	            xx39=((6)*radiusc/dl-i+1);
	            yy39= ((6)*radiusc/dl-j+1);
	            zz39=(5*radiusc/dl-k+1);
    
	            xx40=((6-1.0)*radiusc/dl-i+1);
	            yy40= ((6-sqrt(3.0))*radiusc/dl-j+1);
	            zz40=(5*radiusc/dl-k+1);

	            xx41=((6+1.0)*radiusc/dl-i+1);
	            yy41= ((6-sqrt(3.0))*radiusc/dl-j+1);
	            zz41=(5*radiusc/dl-k+1);

	            xx42=((6-1.0)*radiusc/dl-i+1);
	            yy42= ((6+sqrt(3.0))*radiusc/dl-j+1);
	            zz42=(5*radiusc/dl-k+1);

	            xx43=((6+1.0)*radiusc/dl-i+1);
	            yy43= ((6+sqrt(3.0))*radiusc/dl-j+1);
	            zz43=(5*radiusc/dl-k+1);

	            xx44=(4*radiusc/dl-i+1);
	            yy44= (6*radiusc/dl-j+1);
	            zz44=(5*radiusc/dl-k+1);

	            xx45=(8*radiusc/dl-i+1);
	            yy45= (6*radiusc/dl-j+1);
	            zz45=(5*radiusc/dl-k+1);

	            xx46=((6)*radiusc/dl-i+1);
	            yy46= ((8+sqrt(2.0))*radiusc/dl-j+1);
	            zz46=(5*radiusc/dl-k+1);
    
	            xx47=((6)*radiusc/dl-i+1);
	            yy47= ((4-sqrt(2.0))*radiusc/dl-j+1);
	            zz47=(5*radiusc/dl-k+1);

	            xx48=((10.0)*radiusc/dl-i+1);
	            yy48= ((6.0)*radiusc/dl-j+1);
	            zz48=(5*radiusc/dl-k+1);

	            xx49=((3-1.0)*radiusc/dl-i+1);
	            yy49= ((6.0)*radiusc/dl-j+1);
	            zz49=(5*radiusc/dl-k+1);

	            xx50=((3)*radiusc/dl-i+1);
	            yy50= ((6-sqrt(3.0))*radiusc/dl-j+1);
	            zz50=(5*radiusc/dl-k+1);

	            xx51=(9*radiusc/dl-i+1);
	            yy51= ((6-sqrt(3.0))*radiusc/dl-j+1);
	            zz51=(5*radiusc/dl-k+1);

	            xx52=((9+0.05)*radiusc/dl-i+1);
	            yy52= ((6+sqrt(3.0))*radiusc/dl-j+1);
	            zz52=(5*radiusc/dl-k+1);


	            xx53=((3)*radiusc/dl-i+1);
	            yy53= ((6+sqrt(3.0))*radiusc/dl-j+1);
	            zz53=((5)*radiusc/dl-k+1);

	            xx54=((3+1+0.05)*radiusc/dl-i+1);
	            yy54= ((11-sqrt(3.0)+0.15)*radiusc/dl-j+1);
	            zz54=((5)*radiusc/dl-k+1);

	            xx55=((8)*radiusc/dl-i+1);
	            yy55= ((11-sqrt(3.0)+0.15)*radiusc/dl-j+1);
	            zz55=((5)*radiusc/dl-k+1);

	            xx56=((8)*radiusc/dl-i+1);
	            yy56= ((1+sqrt(3.0)-0.1)*radiusc/dl-j+1);
	            zz56=((5)*radiusc/dl-k+1);


	            xx57=((4)*radiusc/dl-i+1);
	            yy57= ((1+sqrt(3.0)-0.1)*radiusc/dl-j+1);
	            zz57=((5)*radiusc/dl-k+1);









	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx1/(div),2)+pow(yy1/(div),2)+pow(zz1/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx2/(div),2)+pow(yy2/(div),2)+pow(zz2/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx3/(div),2)+pow(yy3/(div),2)+pow(zz3/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx4/(div),2)+pow(yy4/(div),2)+pow(zz4/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx5/(div),2)+pow(yy5/(div),2)+pow(zz5/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx6/(div),2)+pow(yy6/(div),2)+pow(zz6/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx7/(div),2)+pow(yy7/(div),2)+pow(zz7/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx8/(div),2)+pow(yy8/(div),2)+pow(zz8/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx9/(div),2)+pow(yy9/(div),2)+pow(zz9/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx10/(div),2)+pow(yy10/(div),2)+pow(zz10/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx11/(div),2)+pow(yy11/(div),2)+pow(zz11/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}


	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx12/(div),2)+pow(yy12/(div),2)+pow(zz12/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx13/(div),2)+pow(yy13/(div),2)+pow(zz13/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx14/(div),2)+pow(yy14/(div),2)+pow(zz14/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx15/(div),2)+pow(yy15/(div),2)+pow(zz15/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx16/(div),2)+pow(yy16/(div),2)+pow(zz16/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx17/(div),2)+pow(yy17/(div),2)+pow(zz17/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx18/(div),2)+pow(yy18/(div),2)+pow(zz18/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx19/(div),2)+pow(yy19/(div),2)+pow(zz19/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

				if(hex_layers >=2)
				{



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx20/(div),2)+pow(yy20/(div),2)+pow(zz20/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx21/(div),2)+pow(yy21/(div),2)+pow(zz21/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx22/(div),2)+pow(yy22/(div),2)+pow(zz22/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx23/(div),2)+pow(yy23/(div),2)+pow(zz23/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx24/(div),2)+pow(yy24/(div),2)+pow(zz24/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx25/(div),2)+pow(yy25/(div),2)+pow(zz25/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx26/(div),2)+pow(yy26/(div),2)+pow(zz26/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx27/(div),2)+pow(yy27/(div),2)+pow(zz27/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx28/(div),2)+pow(yy28/(div),2)+pow(zz28/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}


	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx29/(div),2)+pow(yy29/(div),2)+pow(zz29/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx30/(div),2)+pow(yy30/(div),2)+pow(zz30/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx31/(div),2)+pow(yy31/(div),2)+pow(zz31/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx32/(div),2)+pow(yy32/(div),2)+pow(zz32/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}







	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx33/(div),2)+pow(yy33/(div),2)+pow(zz33/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx34/(div),2)+pow(yy34/(div),2)+pow(zz34/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx35/(div),2)+pow(yy35/(div),2)+pow(zz35/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}









	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx36/(div),2)+pow(yy36/(div),2)+pow(zz36/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx37/(div),2)+pow(yy37/(div),2)+pow(zz37/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx38/(div),2)+pow(yy38/(div),2)+pow(zz38/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

			}
			
			if(hex_layers >=3)
			{


	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx39/(div),2)+pow(yy39/(div),2)+pow(zz39/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx40/(div),2)+pow(yy40/(div),2)+pow(zz40/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}


	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx41/(div),2)+pow(yy41/(div),2)+pow(zz41/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}


	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx42/(div),2)+pow(yy42/(div),2)+pow(zz42/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}





	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx43/(div),2)+pow(yy43/(div),2)+pow(zz43/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx44/(div),2)+pow(yy44/(div),2)+pow(zz44/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx45/(div),2)+pow(yy45/(div),2)+pow(zz45/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx46/(div),2)+pow(yy46/(div),2)+pow(zz46/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx47/(div),2)+pow(yy47/(div),2)+pow(zz47/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}





	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx48/(div),2)+pow(yy48/(div),2)+pow(zz48/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx49/(div),2)+pow(yy49/(div),2)+pow(zz49/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx50/(div),2)+pow(yy50/(div),2)+pow(zz50/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx51/(div),2)+pow(yy51/(div),2)+pow(zz51/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx52/(div),2)+pow(yy52/(div),2)+pow(zz52/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx53/(div),2)+pow(yy53/(div),2)+pow(zz53/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx54/(div),2)+pow(yy54/(div),2)+pow(zz54/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}


	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx55/(div),2)+pow(yy55/(div),2)+pow(zz55/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}


	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx56/(div),2)+pow(yy56/(div),2)+pow(zz56/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx57/(div),2)+pow(yy57/(div),2)+pow(zz57/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

		}




}
}
}


	return **A;

}




int hex7 (int xini,int xfin,int yini,int yfin,int zini,int zfin, int Npix,int Npiy,int Ntam, int Dx1,int Dy1,int Dz1,float radiusc,float radiuscore, float radiusshell,int **A,int corenumber,int shellnumber,int cnum,float dl,float x[80000],float y[80000],float z[80000],float base, float width,float height,float base2,float width2,float radiusx1,float radiusy1,float radiusz1,float radiusx2,float radiusy2,float radiusz2,float radiusxcs,float radiusycs,float radiuszcs,float cs,float rcarbonpt,float radiuspt,float rcarbonpd,float radiuspd,float distcentro,int alloynumber,int hex_layers)
{

	float div;
	float cc;

	float xx1,yy1,zz1;
	float xx2,yy2,zz2;
	float xx3,yy3,zz3;
	float xx4,yy4,zz4;
	float xx5,yy5,zz5;
	float xx6,yy6,zz6;
	float xx7,yy7,zz7;
	float xx8,yy8,zz8;
	float xx9,yy9,zz9;
	float xx10,yy10,zz10;
	float xx11,yy11,zz11;
	float xx12,yy12,zz12;
	float xx13,yy13,zz13;
	float xx14,yy14,zz14;
	float xx15,yy15,zz15;
	float xx16,yy16,zz16;
	float xx17,yy17,zz17;
	float xx18,yy18,zz18;
	float xx19,yy19,zz19;
	float xx20,yy20,zz20;
	float xx21,yy21,zz21;
	float xx22,yy22,zz22;
	float xx23,yy23,zz23;
	float xx24,yy24,zz24;
	float xx25,yy25,zz25;
	float xx26,yy26,zz26;



	for (int k = zini; k < zfin+1;k++)
		{
	    for (int j = yini;j < yfin+1; j++)
	     {
			for (int i=xini; j < xfin+1;j++)
			{


// first layer

	            int a=int(i);
	            int b=int(j+(k-1)*Dy1);




	            xx1=((6)*radiusc/dl-i+1);
	            yy1= ((6)*radiusc/dl-j+1);
	            zz1=(radiusc/dl-k+1);
    
	            xx2=((6-1.0)*radiusc/dl-i+1);
	            yy2= ((6-sqrt(3.0))*radiusc/dl-j+1);
	            zz2=(radiusc/dl-k+1);

	            xx3=((6+1.0)*radiusc/dl-i+1);
	            yy3= ((6-sqrt(3.0))*radiusc/dl-j+1);
	            zz3=(radiusc/dl-k+1);

	            xx4=((6-1.0)*radiusc/dl-i+1);
	            yy4= ((6+sqrt(3.0))*radiusc/dl-j+1);
	            zz4=(radiusc/dl-k+1);

	            xx5=((6+1.0)*radiusc/dl-i+1);
	            yy5= ((6+sqrt(3.0))*radiusc/dl-j+1);
	            zz5=(radiusc/dl-k+1);

	            xx6=(4*radiusc/dl-i+1);
	            yy6= (6*radiusc/dl-j+1);
	            zz6=(radiusc/dl-k+1);

	            xx7=(8*radiusc/dl-i+1);
	            yy7= (6*radiusc/dl-j+1);
	            zz7=(1*radiusc/dl-k+1);

	            xx8=((6)*radiusc/dl-i+1);
	            yy8= ((8+sqrt(2.0))*radiusc/dl-j+1);
	            zz8=(1*radiusc/dl-k+1);
    

	            xx9=((6)*radiusc/dl-i+1);
	            yy9= ((4-sqrt(2.0))*radiusc/dl-j+1);
	            zz9=(1*radiusc/dl-k+1);

	            xx10=((10.0)*radiusc/dl-i+1);
	            yy10= ((6.0)*radiusc/dl-j+1);
	            zz10=(1*radiusc/dl-k+1);

	            xx11=((3-1.0)*radiusc/dl-i+1);
	            yy11= ((6.0)*radiusc/dl-j+1);
	            zz11=(1*radiusc/dl-k+1);

	            xx12=((3)*radiusc/dl-i+1);
	            yy12= ((6-sqrt(3.0))*radiusc/dl-j+1);
	            zz12=(1*radiusc/dl-k+1);

	            xx13=(9*radiusc/dl-i+1);
	            yy13= ((6-sqrt(3.0))*radiusc/dl-j+1);
	            zz13=(1*radiusc/dl-k+1);

	            xx14=((9+0.05)*radiusc/dl-i+1);
	            yy14= ((6+sqrt(3.0))*radiusc/dl-j+1);
	            zz14=(1*radiusc/dl-k+1);


	            xx15=((3)*radiusc/dl-i+1);
	            yy15= ((6+sqrt(3.0))*radiusc/dl-j+1);
	            zz15=((1)*radiusc/dl-k+1);


	            xx16=((3+1+0.05)*radiusc/dl-i+1);
	            yy16= ((11-sqrt(3.0)+0.15)*radiusc/dl-j+1);
	            zz16=((1)*radiusc/dl-k+1);


	            xx17=((8)*radiusc/dl-i+1);
	            yy17= ((11-sqrt(3.0)+0.15)*radiusc/dl-j+1);
	            zz17=((1)*radiusc/dl-k+1);



	            xx18=((8)*radiusc/dl-i+1);
	            yy18= ((1+sqrt(3.0)-0.1)*radiusc/dl-j+1);
	            zz18=((1)*radiusc/dl-k+1);


	            xx19=((4)*radiusc/dl-i+1);
	            yy19= ((1+sqrt(3.0)-0.1)*radiusc/dl-j+1);
	            zz19=((1)*radiusc/dl-k+1);

// second layer


	            xx20=((5)*radiusc/dl-i+1);
	            yy20= ((6)*radiusc/dl-j+1);
	            zz20=((1+sqrt(3.0))*radiusc/dl-k+1);
    
	            xx21=((7.0)*radiusc/dl-i+1);
	            yy21= ((6.0)*radiusc/dl-j+1);
	            zz21=((1+sqrt(3.0))*radiusc/dl-k+1);



	            xx22=((6.0)*radiusc/dl-i+1);
	            yy22= ((7.0+sqrt(2.0)/2)*radiusc/dl-j+1);
	            zz22=((1+sqrt(3.0))*radiusc/dl-k+1);

	            xx23=((6)*radiusc/dl-i+1);
	            yy23= ((5-sqrt(2.0)/2)*radiusc/dl-j+1);
	            zz23=((1+sqrt(3.0))*radiusc/dl-k+1);

// third layer

	            xx24=((6.0)*radiusc/dl-i+1);
	            yy24= ((6.0-sqrt(3.0)/2)*radiusc/dl-j+1);
	            zz24=((1+2*sqrt(3.0))*radiusc/dl-k+1);


	            xx25=((6)*radiusc/dl-i+1);
	            yy25= ((6+sqrt(3.0)/2)*radiusc/dl-j+1);
	            zz25=((1+2*sqrt(3.0))*radiusc/dl-k+1);

// fourth layer

	            xx26=((6.0)*radiusc/dl-i+1);
	            yy26= ((6.0)*radiusc/dl-j+1);
	            zz26=((1+3*sqrt(3.0))*radiusc/dl-k+1);









	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx1/(div),2)+pow(yy1/(div),2)+pow(zz1/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx2/(div),2)+pow(yy2/(div),2)+pow(zz2/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx3/(div),2)+pow(yy3/(div),2)+pow(zz3/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx4/(div),2)+pow(yy4/(div),2)+pow(zz4/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx5/(div),2)+pow(yy5/(div),2)+pow(zz5/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx6/(div),2)+pow(yy6/(div),2)+pow(zz6/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx7/(div),2)+pow(yy7/(div),2)+pow(zz7/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx8/(div),2)+pow(yy8/(div),2)+pow(zz8/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx9/(div),2)+pow(yy9/(div),2)+pow(zz9/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx10/(div),2)+pow(yy10/(div),2)+pow(zz10/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx11/(div),2)+pow(yy11/(div),2)+pow(zz11/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}


	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx12/(div),2)+pow(yy12/(div),2)+pow(zz12/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx13/(div),2)+pow(yy13/(div),2)+pow(zz13/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx14/(div),2)+pow(yy14/(div),2)+pow(zz14/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx15/(div),2)+pow(yy15/(div),2)+pow(zz15/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx16/(div),2)+pow(yy16/(div),2)+pow(zz16/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx17/(div),2)+pow(yy17/(div),2)+pow(zz17/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx18/(div),2)+pow(yy18/(div),2)+pow(zz18/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx19/(div),2)+pow(yy19/(div),2)+pow(zz19/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

		
		
				if(hex_layers >=2)
				{



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx20/(div),2)+pow(yy20/(div),2)+pow(zz20/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx21/(div),2)+pow(yy21/(div),2)+pow(zz21/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx22/(div),2)+pow(yy22/(div),2)+pow(zz22/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx23/(div),2)+pow(yy23/(div),2)+pow(zz23/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}


			}
			
				if(hex_layers >=3)
				{

			


	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx24/(div),2)+pow(yy24/(div),2)+pow(zz24/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx25/(div),2)+pow(yy25/(div),2)+pow(zz25/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

			}
			if(hex_layers >=4)
			{


	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx26/(div),2)+pow(yy26/(div),2)+pow(zz26/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}
			
			}















}
}
}


	return **A;

}




int hex8 (int xini,int xfin,int yini,int yfin,int zini,int zfin, int Npix,int Npiy,int Ntam, int Dx1,int Dy1,int Dz1,float radiusc,float radiuscore, float radiusshell,int **A,int corenumber,int shellnumber,int cnum,float dl,float x[80000],float y[80000],float z[80000],float base, float width,float height,float base2,float width2,float radiusx1,float radiusy1,float radiusz1,float radiusx2,float radiusy2,float radiusz2,float radiusxcs,float radiusycs,float radiuszcs,float cs,float rcarbonpt,float radiuspt,float rcarbonpd,float radiuspd,float distcentro,int alloynumber,int hex_layers)
{

	float div;
	float cc;

	float xx1,yy1,zz1;
	float xx2,yy2,zz2;
	float xx3,yy3,zz3;
	float xx4,yy4,zz4;
	float xx5,yy5,zz5;
	float xx6,yy6,zz6;
	float xx7,yy7,zz7;
	float xx8,yy8,zz8;
	float xx9,yy9,zz9;
	float xx10,yy10,zz10;
	float xx11,yy11,zz11;
	float xx12,yy12,zz12;
	float xx13,yy13,zz13;
	float xx14,yy14,zz14;
	float xx15,yy15,zz15;
	float xx16,yy16,zz16;
	float xx17,yy17,zz17;
	float xx18,yy18,zz18;
	float xx19,yy19,zz19;
	float xx20,yy20,zz20;
	float xx21,yy21,zz21;
	float xx22,yy22,zz22;
	float xx23,yy23,zz23;
	float xx24,yy24,zz24;
	float xx25,yy25,zz25;
	float xx26,yy26,zz26;
	float xx27,yy27,zz27;
	float xx28,yy28,zz28;
	float xx29,yy29,zz29;
	float xx30,yy30,zz30;
	float xx31,yy31,zz31;
	float xx32,yy32,zz32;
	float xx33,yy33,zz33;



	for (int k = zini; k < zfin+1;k++)
		{
	    for (int j = yini;j < yfin+1; j++)
	     {
			for (int i=xini; j < xfin+1;j++)
			{


// first layer

	            int a=int(i);
	            int b=int(j+(k-1)*Dy1);






	            xx1=((6)*radiusc/dl-i+1);
	            yy1= ((6+1)*radiusc/dl-j+1);
	            zz1=(radiusc/dl-k+1);
    
	            xx2=((6-1.0)*radiusc/dl-i+1);
	            yy2= ((6+1-sqrt(3.0))*radiusc/dl-j+1);
	            zz2=(radiusc/dl-k+1);

	            xx3=((6+1.0)*radiusc/dl-i+1);
	            yy3= ((6+1-sqrt(3.0))*radiusc/dl-j+1);
	            zz3=(radiusc/dl-k+1);

	            xx4=((6-1.0)*radiusc/dl-i+1);
	            yy4= ((6+1+sqrt(3.0))*radiusc/dl-j+1);
	            zz4=(radiusc/dl-k+1);

	            xx5=((6+1.0)*radiusc/dl-i+1);
	            yy5= ((6+1+sqrt(3.0))*radiusc/dl-j+1);
	            zz5=(radiusc/dl-k+1);

	            xx6=(4*radiusc/dl-i+1);
	            yy6= ((6+1)*radiusc/dl-j+1);
	            zz6=(radiusc/dl-k+1);

	            xx7=(8*radiusc/dl-i+1);
	            yy7= ((6+1)*radiusc/dl-j+1);
	            zz7=(1*radiusc/dl-k+1);

	            xx8=((6)*radiusc/dl-i+1);
	            yy8= ((8+1+sqrt(2.0))*radiusc/dl-j+1);
	            zz8=(1*radiusc/dl-k+1);
    
	            xx9=((6)*radiusc/dl-i+1);
	            yy9= ((4+1-sqrt(2.0))*radiusc/dl-j+1);
	            zz9=(1*radiusc/dl-k+1);

	            xx10=((10.0)*radiusc/dl-i+1);
	            yy10= ((6.0+1)*radiusc/dl-j+1);
	            zz10=(1*radiusc/dl-k+1);

	            xx11=((3-1.0)*radiusc/dl-i+1);
	            yy11= ((6.0+1)*radiusc/dl-j+1);
	            zz11=(1*radiusc/dl-k+1);

	            xx12=((3)*radiusc/dl-i+1);
	            yy12= ((6+1-sqrt(3.0))*radiusc/dl-j+1);
	            zz12=(1*radiusc/dl-k+1);

	            xx13=(9*radiusc/dl-i+1);
	            yy13= ((6+1-sqrt(3.0))*radiusc/dl-j+1);
	            zz13=(1*radiusc/dl-k+1);

	            xx14=((9+0.05)*radiusc/dl-i+1);
	            yy14= ((6+1+sqrt(3.0))*radiusc/dl-j+1);
	            zz14=(1*radiusc/dl-k+1);


	            xx15=((3)*radiusc/dl-i+1);
	            yy15= ((6+1+sqrt(3.0))*radiusc/dl-j+1);
	            zz15=((1)*radiusc/dl-k+1);

	            xx16=((3+1+0.05)*radiusc/dl-i+1);
	            yy16= ((11+1-sqrt(3.0)+0.15)*radiusc/dl-j+1);
	            zz16=((1)*radiusc/dl-k+1);

	            xx17=((8)*radiusc/dl-i+1);
	            yy17= ((11+1-sqrt(3.0)+0.15)*radiusc/dl-j+1);
	            zz17=((1)*radiusc/dl-k+1);

	            xx18=((8)*radiusc/dl-i+1);
	            yy18= ((1+1+sqrt(3.0)-0.1)*radiusc/dl-j+1);
	            zz18=((1)*radiusc/dl-k+1);


	            xx19=((4)*radiusc/dl-i+1);
	            yy19= ((1+1+sqrt(3.0)-0.1)*radiusc/dl-j+1);
	            zz19=((1)*radiusc/dl-k+1);

// second layer


	            xx20 = (6*(radiuscore + (radiusc-radiuscore))/dl-i); 
	            yy20 = (7*(radiuscore+(radiusc-radiuscore))/dl-j); 
	            zz20 = (3*(radiuscore+(radiusc-radiuscore))/dl-k+1);




	            xx21 = (5*(radiuscore + (radiusc-radiuscore))/dl-i); 
	            yy21 = ((7-sqrt(3.0))*(radiuscore+(radiusc-radiuscore))/dl-j); 
	            zz21 = (3*(radiuscore+(radiusc-radiuscore))/dl-k+1);


	            xx22 = (7*(radiuscore + (radiusc-radiuscore))/dl-i); 
	            yy22 = ((7-sqrt(3.0))*(radiuscore+(radiusc-radiuscore))/dl-j); 
	            zz22 = (3*(radiuscore+(radiusc-radiuscore))/dl-k+1);




	            xx23 = (5*(radiuscore + (radiusc-radiuscore))/dl-i); 
	            yy23 = ((7+sqrt(3.0))*(radiuscore+(radiusc-radiuscore))/dl-j); 
	            zz23 = (3*(radiuscore+(radiusc-radiuscore))/dl-k+1);




	            xx24 = (7*(radiuscore + (radiusc-radiuscore))/dl-i); 
	            yy24 = ((7+sqrt(3.0))*(radiuscore+(radiusc-radiuscore))/dl-j); 
	            zz24 = (3*(radiuscore+(radiusc-radiuscore))/dl-k+1);



	            xx25 = (4*(radiuscore + (radiusc-radiuscore))/dl-i); 
	            yy25 = (7*(radiuscore+(radiusc-radiuscore))/dl-j); 
	            zz25 = (3*(radiuscore+(radiusc-radiuscore))/dl-k+1);




	            xx26 = (8*(radiuscore + (radiusc-radiuscore))/dl-i); 
	            yy26 = (7*(radiuscore+(radiusc-radiuscore))/dl-j); 
	            zz26 = (3*(radiuscore+(radiusc-radiuscore))/dl-k+1);


// third layer

	            xx27 = (5*(radiuscore + (radiusc-radiuscore))/dl-i); 
	            yy27 = (7*(radiuscore+(radiusc-radiuscore))/dl-j); 
	            zz27 = ((3+sqrt(3.0))*(radiuscore+(radiusc-radiuscore))/dl-k+1);


	            xx28 = (7*(radiuscore + (radiusc-radiuscore))/dl-i); 
	            yy28 = (7*(radiuscore+(radiusc-radiuscore))/dl-j); 
	            zz28 = ((3+sqrt(3.0))*(radiuscore+(radiusc-radiuscore))/dl-k+1);


	            xx29 = (6*(radiuscore + (radiusc-radiuscore))/dl-i); 
	            yy29 = ((8.0+sqrt(2.0)/2)*(radiuscore+(radiusc-radiuscore))/dl-j); 
	            zz29 = ((3+sqrt(3.0))*(radiuscore+(radiusc-radiuscore))/dl-k+1);




	            xx30 = (6*(radiuscore + (radiusc-radiuscore))/dl-i); 
	            yy30 = ((6.0-sqrt(2.0)/2)*(radiuscore+(radiusc-radiuscore))/dl-j); 
	            zz30 = ((3+sqrt(3.0))*(radiuscore+(radiusc-radiuscore))/dl-k+1);


// fourth layer

	            xx31 = (6*(radiuscore + (radiusc-radiuscore))/dl-i); 
	            yy31 = ((7.0-sqrt(3.0)/2)*(radiuscore+(radiusc-radiuscore))/dl-j); 
	            zz31 = ((3+2*sqrt(3.0))*(radiuscore+(radiusc-radiuscore))/dl-k+1);


	            xx32 = (6*(radiuscore + (radiusc-radiuscore))/dl-i); 
	            yy32 = ((7.0+sqrt(3.0)/2)*(radiuscore+(radiusc-radiuscore))/dl-j); 
	            zz32 = ((3+2*sqrt(3.0))*(radiuscore+(radiusc-radiuscore))/dl-k+1);

// fifth layer


	            xx33 = (6*(radiuscore + (radiusc-radiuscore))/dl-i); 
	            yy33 = ((7.0)*(radiuscore+(radiusc-radiuscore))/dl-j); 
	            zz33 = ((3+3*sqrt(3.0))*(radiuscore+(radiusc-radiuscore))/dl-k+1);









	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx1/(div),2)+pow(yy1/(div),2)+pow(zz1/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx2/(div),2)+pow(yy2/(div),2)+pow(zz2/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx3/(div),2)+pow(yy3/(div),2)+pow(zz3/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx4/(div),2)+pow(yy4/(div),2)+pow(zz4/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx5/(div),2)+pow(yy5/(div),2)+pow(zz5/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx6/(div),2)+pow(yy6/(div),2)+pow(zz6/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx7/(div),2)+pow(yy7/(div),2)+pow(zz7/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx8/(div),2)+pow(yy8/(div),2)+pow(zz8/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx9/(div),2)+pow(yy9/(div),2)+pow(zz9/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx10/(div),2)+pow(yy10/(div),2)+pow(zz10/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx11/(div),2)+pow(yy11/(div),2)+pow(zz11/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}


	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx12/(div),2)+pow(yy12/(div),2)+pow(zz12/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx13/(div),2)+pow(yy13/(div),2)+pow(zz13/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx14/(div),2)+pow(yy14/(div),2)+pow(zz14/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx15/(div),2)+pow(yy15/(div),2)+pow(zz15/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx16/(div),2)+pow(yy16/(div),2)+pow(zz16/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx17/(div),2)+pow(yy17/(div),2)+pow(zz17/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx18/(div),2)+pow(yy18/(div),2)+pow(zz18/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx19/(div),2)+pow(yy19/(div),2)+pow(zz19/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

			
		
				if(hex_layers >=2)
				{



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx20/(div),2)+pow(yy20/(div),2)+pow(zz20/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx21/(div),2)+pow(yy21/(div),2)+pow(zz21/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx22/(div),2)+pow(yy22/(div),2)+pow(zz22/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx23/(div),2)+pow(yy23/(div),2)+pow(zz23/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx24/(div),2)+pow(yy24/(div),2)+pow(zz24/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx25/(div),2)+pow(yy25/(div),2)+pow(zz25/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx26/(div),2)+pow(yy26/(div),2)+pow(zz26/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

			}


		
		
				if(hex_layers >=3)
				{



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx27/(div),2)+pow(yy27/(div),2)+pow(zz27/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx28/(div),2)+pow(yy28/(div),2)+pow(zz28/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}


	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx29/(div),2)+pow(yy29/(div),2)+pow(zz29/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx30/(div),2)+pow(yy30/(div),2)+pow(zz30/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}


			}
		
		
				if(hex_layers >=4)
				{




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx31/(div),2)+pow(yy31/(div),2)+pow(zz31/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx32/(div),2)+pow(yy32/(div),2)+pow(zz32/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



			}
		
		
				if(hex_layers >=5)
				{




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx33/(div),2)+pow(yy33/(div),2)+pow(zz33/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}


			}









}
}
}


	return **A;

}








int hex9 (int xini,int xfin,int yini,int yfin,int zini,int zfin, int Npix,int Npiy,int Ntam, int Dx1,int Dy1,int Dz1,float radiusc,float radiuscore, float radiusshell,int **A,int corenumber,int shellnumber,int cnum,float dl,float x[80000],float y[80000],float z[80000],float base, float width,float height,float base2,float width2,float radiusx1,float radiusy1,float radiusz1,float radiusx2,float radiusy2,float radiusz2,float radiusxcs,float radiusycs,float radiuszcs,float cs,float rcarbonpt,float radiuspt,float rcarbonpd,float radiuspd,float distcentro,int alloynumber,int hex_layers)
{

	float div;
	float cc;

	float xx1,yy1,zz1;
	float xx2,yy2,zz2;
	float xx3,yy3,zz3;
	float xx4,yy4,zz4;
	float xx5,yy5,zz5;
	float xx6,yy6,zz6;
	float xx7,yy7,zz7;
	float xx8,yy8,zz8;
	float xx9,yy9,zz9;
	float xx10,yy10,zz10;
	float xx11,yy11,zz11;
	float xx12,yy12,zz12;
	float xx13,yy13,zz13;
	float xx14,yy14,zz14;
	float xx15,yy15,zz15;
	float xx16,yy16,zz16;
	float xx17,yy17,zz17;
	float xx18,yy18,zz18;
	float xx19,yy19,zz19;
	float xx20,yy20,zz20;
	float xx21,yy21,zz21;
	float xx22,yy22,zz22;
	float xx23,yy23,zz23;
	float xx24,yy24,zz24;
	float xx25,yy25,zz25;
	float xx26,yy26,zz26;
	float xx27,yy27,zz27;
	float xx28,yy28,zz28;
	float xx29,yy29,zz29;
	float xx30,yy30,zz30;
	float xx31,yy31,zz31;
	float xx32,yy32,zz32;
	float xx33,yy33,zz33;
	float xx34,yy34,zz34;
	float xx35,yy35,zz35;
	float xx36,yy36,zz36;
	float xx37,yy37,zz37;
	float xx38,yy38,zz38;
	float xx39,yy39,zz39;
	float xx40,yy40,zz40;
	float xx41,yy41,zz41;
	float xx42,yy42,zz42;
	float xx43,yy43,zz43;
	float xx44,yy44,zz44;
	float xx45,yy45,zz45;
	float xx46,yy46,zz46;
	float xx47,yy47,zz47;






	for (int k = zini; k < zfin+1;k++)
		{
	    for (int j = yini;j < yfin+1; j++)
	     {
			for (int i=xini; j < xfin+1;j++)
			{


// first layer

	            int a=int(i);
	            int b=int(j+(k-1)*Dy1);


	            xx1=((6)*radiusc/dl-i+1);
	            yy1= ((7)*radiusc/dl-j+1);
	            zz1=(radiusc/dl-k+1);
    
	            xx2=((6-1.0)*radiusc/dl-i+1);
	            yy2= ((7-sqrt(3.0))*radiusc/dl-j+1);
	            zz2=(radiusc/dl-k+1);

	            xx3=((6+1.0)*radiusc/dl-i+1);
	            yy3= ((7-sqrt(3.0))*radiusc/dl-j+1);
	            zz3=(radiusc/dl-k+1);

	            xx4=((6-1.0)*radiusc/dl-i+1);
	            yy4= ((7+sqrt(3.0))*radiusc/dl-j+1);
	            zz4=(radiusc/dl-k+1);

	            xx5=((6+1.0)*radiusc/dl-i+1);
	            yy5= ((7+sqrt(3.0))*radiusc/dl-j+1);
	            zz5=(radiusc/dl-k+1);

	            xx6=(4*radiusc/dl-i+1);
	            yy6= (7*radiusc/dl-j+1);
	            zz6=(radiusc/dl-k+1);

	            xx7=(8*radiusc/dl-i+1);
	            yy7= (7*radiusc/dl-j+1);
	            zz7=(1*radiusc/dl-k+1);

	            xx8=((6)*radiusc/dl-i+1);
	            yy8= ((9+sqrt(2.0))*radiusc/dl-j+1);
	            zz8=(1*radiusc/dl-k+1);
    
	            xx9=((6)*radiusc/dl-i+1);
	            yy9= ((5-sqrt(2.0))*radiusc/dl-j+1);
	            zz9=(1*radiusc/dl-k+1);

	            xx10=((10.0)*radiusc/dl-i+1);
	            yy10= ((7.0)*radiusc/dl-j+1);
	            zz10=(1*radiusc/dl-k+1);

	            xx11=((3-1.0)*radiusc/dl-i+1);
	            yy11= ((7.0)*radiusc/dl-j+1);
	            zz11=(1*radiusc/dl-k+1);

	            xx12=((3)*radiusc/dl-i+1);
	            yy12= ((7-sqrt(3.0))*radiusc/dl-j+1);
	            zz12=(1*radiusc/dl-k+1);

	            xx13=(9*radiusc/dl-i+1);
	            yy13= ((7-sqrt(3.0))*radiusc/dl-j+1);
	            zz13=(1*radiusc/dl-k+1);

	            xx14=((9+0.05)*radiusc/dl-i+1);
	            yy14= ((7+sqrt(3.0))*radiusc/dl-j+1);
	            zz14=(1*radiusc/dl-k+1);


	            xx15=((3)*radiusc/dl-i+1);
	            yy15= ((7+sqrt(3.0))*radiusc/dl-j+1);
	            zz15=((1)*radiusc/dl-k+1);

	            xx16=((3+1+0.05)*radiusc/dl-i+1);
	            yy16= ((12-sqrt(3.0)+0.15)*radiusc/dl-j+1);
	            zz16=((1)*radiusc/dl-k+1);

	            xx17=((8)*radiusc/dl-i+1);
	            yy17= ((12-sqrt(3.0)+0.15)*radiusc/dl-j+1);
	            zz17=((1)*radiusc/dl-k+1);

	            xx18=((8)*radiusc/dl-i+1);
	            yy18= ((2+sqrt(3.0)-0.1)*radiusc/dl-j+1);
	            zz18=((1)*radiusc/dl-k+1);


	            xx19=((4)*radiusc/dl-i+1);
	            yy19= ((2+sqrt(3.0)-0.1)*radiusc/dl-j+1);
	            zz19=((1)*radiusc/dl-k+1);

// second layer

	            xx20=((5)*radiusc/dl-i+1);
	            yy20= ((7)*radiusc/dl-j+1);
	            zz20=((1+sqrt(3.0))*radiusc/dl-k+1);
    
	            xx21=((7)*radiusc/dl-i+1);
	            yy21= ((7)*radiusc/dl-j+1);
	            zz21=((1+sqrt(3.0))*radiusc/dl-k+1);

	            xx22=((6)*radiusc/dl-i+1);
	            yy22= ((8+sqrt(2.0)/2)*radiusc/dl-j+1);
	            zz22=((1+sqrt(3.0))*radiusc/dl-k+1);

	            xx23=((6)*radiusc/dl-i+1);
	            yy23= ((6-sqrt(2.0)/2)*radiusc/dl-j+1);
	            zz23=((1+sqrt(3.0))*radiusc/dl-k+1);

	            xx24=((3.0)*radiusc/dl-i+1);
	            yy24= ((7)*radiusc/dl-j+1);
	            zz24=((1+sqrt(3.0))*radiusc/dl-k+1);

	            xx25=(9*radiusc/dl-i+1);
	            yy25= (7*radiusc/dl-j+1);
	            zz25=((1+sqrt(3.0))*radiusc/dl-k+1);

	            xx26=((8)*radiusc/dl-i+1);
	            yy26= ((8+sqrt(2.0)/2)*radiusc/dl-j+1);
	            zz26=((1+sqrt(3.0))*radiusc/dl-k+1);



	            xx27=((4)*radiusc/dl-i+1);
	            yy27= ((8+sqrt(2.0)/2)*radiusc/dl-j+1);
	            zz27=((1+sqrt(3.0))*radiusc/dl-k+1);
    
	            xx28=((8.0)*radiusc/dl-i+1);
	            yy28= ((6.0-sqrt(2.0)/2)*radiusc/dl-j+1);
	            zz28=((1+sqrt(3.0))*radiusc/dl-k+1);

	            xx29=((4.0)*radiusc/dl-i+1);
	            yy29= ((6.0-sqrt(2.0)/2)*radiusc/dl-j+1);
	            zz29=((1+sqrt(3.0))*radiusc/dl-k+1);

	            xx30=((5)*radiusc/dl-i+1);
	            yy30= ((8+sqrt(2.0)/2+sqrt(3.0))*radiusc/dl-j+1);
	            zz30=((1+sqrt(3.0))*radiusc/dl-k+1);

	            xx31=((7.0)*radiusc/dl-i+1);
	            yy31= ((8.0+sqrt(2.0)/2+sqrt(3.0))*radiusc/dl-j+1);
	            zz31=((1+sqrt(3.0))*radiusc/dl-k+1);

	            xx32=((5)*radiusc/dl-i+1);
	            yy32= ((6-sqrt(2.0)/2-sqrt(3.0))*radiusc/dl-j+1);
	            zz32=((1+sqrt(3.0))*radiusc/dl-k+1);


	            xx33=((7.0)*radiusc/dl-i+1);
	            yy33= ((6.0-sqrt(2.0)/2-sqrt(3.0))*radiusc/dl-j+1);
	            zz33=((1+sqrt(3.0))*radiusc/dl-k+1);

// third layer


	            xx34=((4.0)*radiusc/dl-i+1);
	            yy34= ((7.0)*radiusc/dl-j+1);
	            zz34=((1+2*sqrt(3.0))*radiusc/dl-k+1);

	            xx35=((6)*radiusc/dl-i+1);
	            yy35= ((7)*radiusc/dl-j+1);
	            zz35=((1+2*sqrt(3.0))*radiusc/dl-k+1);


	            xx36=((8.0)*radiusc/dl-i+1);
	            yy36= ((7.0)*radiusc/dl-j+1);
	            zz36=((1+2*sqrt(3.0))*radiusc/dl-k+1);


	            xx37=((7.0)*radiusc/dl-i+1);
	            yy37= ((8.0+sqrt(2.0)/2)*radiusc/dl-j+1);
	            zz37=((1+2*sqrt(3.0))*radiusc/dl-k+1);

	            xx38=((5)*radiusc/dl-i+1);
	            yy38= ((8+sqrt(2.0)/2)*radiusc/dl-j+1);
	            zz38=((1+2*sqrt(3.0))*radiusc/dl-k+1);


	            xx39=((7.0)*radiusc/dl-i+1);
	            yy39= ((6.0-sqrt(2.0)/2)*radiusc/dl-j+1);
	            zz39=((1+2*sqrt(3.0))*radiusc/dl-k+1);

	            xx40=((5.0)*radiusc/dl-i+1);
	            yy40= ((6.0-sqrt(2.0)/2)*radiusc/dl-j+1);
	            zz40=((1+2*sqrt(3.0))*radiusc/dl-k+1);

	            xx41=((6)*radiusc/dl-i+1);
	            yy41= ((8+sqrt(2.0)/2+sqrt(3.0))*radiusc/dl-j+1);
	            zz41=((1+2*sqrt(3.0))*radiusc/dl-k+1);


	            xx42=((6.0)*radiusc/dl-i+1);
	            yy42= ((6.0-sqrt(2.0)/2-sqrt(3.0))*radiusc/dl-j+1);
	            zz42=((1+2*sqrt(3.0))*radiusc/dl-k+1);

// fourth layer


	            xx43=((5)*radiusc/dl-i+1);
	            yy43= ((7.0)*radiusc/dl-j+1);
	            zz43=((1+3*sqrt(3.0))*radiusc/dl-k+1);



	            xx44=((7.0)*radiusc/dl-i+1);
	            yy44= ((7.0)*radiusc/dl-j+1);
	            zz44=((1+3*sqrt(3.0))*radiusc/dl-k+1);

	            xx45=((6)*radiusc/dl-i+1);
	            yy45= ((7+sqrt(3.0))*radiusc/dl-j+1);
	            zz45=((1+3*sqrt(3.0))*radiusc/dl-k+1);


	            xx46=((6.0)*radiusc/dl-i+1);
	            yy46= ((7-sqrt(3.0))*radiusc/dl-j+1);
	            zz46=((1+3*sqrt(3.0))*radiusc/dl-k+1);

// fifth layer

	            xx47=((6.0)*radiusc/dl-i+1);
	            yy47= ((7.0)*radiusc/dl-j+1);
	            zz47=((1+4*sqrt(3.0))*radiusc/dl-k+1);








	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx1/(div),2)+pow(yy1/(div),2)+pow(zz1/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx2/(div),2)+pow(yy2/(div),2)+pow(zz2/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx3/(div),2)+pow(yy3/(div),2)+pow(zz3/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx4/(div),2)+pow(yy4/(div),2)+pow(zz4/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx5/(div),2)+pow(yy5/(div),2)+pow(zz5/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx6/(div),2)+pow(yy6/(div),2)+pow(zz6/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx7/(div),2)+pow(yy7/(div),2)+pow(zz7/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx8/(div),2)+pow(yy8/(div),2)+pow(zz8/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx9/(div),2)+pow(yy9/(div),2)+pow(zz9/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx10/(div),2)+pow(yy10/(div),2)+pow(zz10/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx11/(div),2)+pow(yy11/(div),2)+pow(zz11/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}


	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx12/(div),2)+pow(yy12/(div),2)+pow(zz12/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx13/(div),2)+pow(yy13/(div),2)+pow(zz13/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx14/(div),2)+pow(yy14/(div),2)+pow(zz14/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx15/(div),2)+pow(yy15/(div),2)+pow(zz15/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx16/(div),2)+pow(yy16/(div),2)+pow(zz16/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx17/(div),2)+pow(yy17/(div),2)+pow(zz17/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx18/(div),2)+pow(yy18/(div),2)+pow(zz18/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx19/(div),2)+pow(yy19/(div),2)+pow(zz19/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

				if(hex_layers >=2)
				{


	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx20/(div),2)+pow(yy20/(div),2)+pow(zz20/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx21/(div),2)+pow(yy21/(div),2)+pow(zz21/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx22/(div),2)+pow(yy22/(div),2)+pow(zz22/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx23/(div),2)+pow(yy23/(div),2)+pow(zz23/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx24/(div),2)+pow(yy24/(div),2)+pow(zz24/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx25/(div),2)+pow(yy25/(div),2)+pow(zz25/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx26/(div),2)+pow(yy26/(div),2)+pow(zz26/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx27/(div),2)+pow(yy27/(div),2)+pow(zz27/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx28/(div),2)+pow(yy28/(div),2)+pow(zz28/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}


	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx29/(div),2)+pow(yy29/(div),2)+pow(zz29/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx30/(div),2)+pow(yy30/(div),2)+pow(zz30/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx31/(div),2)+pow(yy31/(div),2)+pow(zz31/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx32/(div),2)+pow(yy32/(div),2)+pow(zz32/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}







	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx33/(div),2)+pow(yy33/(div),2)+pow(zz33/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

			}

				if(hex_layers >=3)
				{



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx34/(div),2)+pow(yy34/(div),2)+pow(zz34/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx35/(div),2)+pow(yy35/(div),2)+pow(zz35/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}









	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx36/(div),2)+pow(yy36/(div),2)+pow(zz36/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx37/(div),2)+pow(yy37/(div),2)+pow(zz37/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx38/(div),2)+pow(yy38/(div),2)+pow(zz38/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}




	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx39/(div),2)+pow(yy39/(div),2)+pow(zz39/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx40/(div),2)+pow(yy40/(div),2)+pow(zz40/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}


	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx41/(div),2)+pow(yy41/(div),2)+pow(zz41/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}


	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx42/(div),2)+pow(yy42/(div),2)+pow(zz42/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}

			}
				if(hex_layers >=4)
				{



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx43/(div),2)+pow(yy43/(div),2)+pow(zz43/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx44/(div),2)+pow(yy44/(div),2)+pow(zz44/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}



	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx45/(div),2)+pow(yy45/(div),2)+pow(zz45/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}






	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx46/(div),2)+pow(yy46/(div),2)+pow(zz46/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}


		}
		
		
				if(hex_layers >=5)
				{

	            div=float(radiusc)/float(dl);
	            cc=float((pow(xx47/(div),2)+pow(yy47/(div),2)+pow(zz47/(div),2)) );


            
	            if ( ((cc))<= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore)) ),2)) 
	            {
	                A[a][b]=corenumber;
				}


	            if ( cc >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2) and (cc) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2))
				{
	                A[a][b]=shellnumber;
				}

	            if ( cc >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2) and cc <= 1.0)
				{
	                A[a][b]=cnum;
				}


				}










}
}
}


	return **A;

}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////

// here comes the shapes that are available!!!!!

//int incoreshell_sphere(Npiy,Npix,w,g,i,j,k,ii,a,b,cnum,radiusc,radiuscore, radiusshell, corenumber, shellnumber,dl,h,x,y,z)

// It creates a core@shell with a thin shell of a surfactant, for example

int incoreshell_sphere(int ii, int cnum,float radiusc,float radiuscore,float radiusshell,int corenumber,int shellnumber,float dl,int h, float x[80000], float y[80000], float z[80000], int& index,int& aa)
{

	float div=float(radiusc/dl);


	if ( (pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+pow(z[ii]/div,2.0)   ) <= (pow((radiuscore)/radiusc,2.0 )) )
{
//					#			A[a][b]=corenumber
								index=corenumber;
								aa=1;
//		cout << pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+pow(z[ii]/div,2.0) << endl;

}
// shell

	if ( (  pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+ pow(z[ii]/div,2.0)) >= (pow(radiuscore/radiusc,2.0)  ) and ((pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+ pow(z[ii]/div,2.0) ) <= (pow(radiusshell/radiusc,2.0))))
{
//						                A[a][b]=shellnumber
								index=shellnumber;
								aa=1;

}

// carbon shell

	if ( ((  pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+ (pow(z[ii]/div,2.0)) ) >= (pow((radiusshell)/radiusc,2.0))) and ((pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+ pow(z[ii]/div,2.0)) <= ((1.0))))
		{

//		        			        	A[a][b]=cnum
								index=cnum;
//	cout << pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+pow(z[ii]/div,2.0) << endl;

								aa=1;

	}

	if(aa==0)
	{
		index=0;
	}

	if(aa==1)
	{
//		print (index,'index')
	}



	return index;

}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int in_pyramid(int ii, int cnum,float radiusc,float radiuscore,float radiusshell,int corenumber,int shellnumber,float dl,int h, float x[80000], float y[80000], float z[80000],int& aa,int& index,int& basex,int& basey,int& basez, float lenpystruc, float heipystruc,int i,int j,int k,int xini,int xfin,int yini,int yfin,int zini,int zfin, float radiuscini)
{


//	cout<< radiuscini<< "radiiii"<< endl;



// novos parametros para estrutura de piramide!!!

// define-se a largura base, lenpystruc, float

// altura da piramide, heipystruc, float


	float div=float(radiusc/dl);

//	radiusc=1.0;

//	cout<< radiusc<< "radiuscccccc"<< radiuscini<< "radiusciniiii" << endl;

	float divini=float(heipystruc/dl);


//	cout << corenumber<<endl;


//	float div=float(radiusc/dl);
	
//   cout<< div <<"div"<< divini<< "divini" << endl;

//	exit(0);


//	if ( (pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+pow(z[ii]/div,2.0)   ) <= (pow((radiuscore)/radiusc,2.0 )) )




	if (  pow(x[ii]/div,2.0)<= 1.0 and pow(y[ii]/div,2.0)<= 1.0 and   pow(z[ii]/divini,2.0) <=1.0 )

//	if ( pow(x[ii]/div,2.0)<= 1.0 and pow(y[ii]/div,2.0)<= 1.0 and k==h)
	{
//					#			A[a][b]=corenumber
								index=corenumber;
								aa=1;
//		cout << pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+pow(z[ii]/div,2.0) << endl;

	}

//	cout<< div <<"hereeee"<<endl;



	if(aa==0)
{
		index=0;
}

	if(aa==1)
{
//		print (index,'index')
}

// returning the current value of the variable zz.

	if(index != 1 and index != 0)
	{
		
		cout<< index<<"index"<<endl;

	}

	return index;

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////


//int sphere_interpen(int ii, int cnum,float radiusc,float radiuscore,float radiusshell,int corenumber,int shellnumber,float dl,int h, float x[80000], float y[80000], float z[80000],int& aa,int& index,int& basex,int& basey,int& basez, float lenpystruc, float heipystruc,int i,int j,int k,int xini,int xfin,int yini,int yfin,int zini,int zfin, float radiuscini, float radiuspt, float radiuspd, float distcentro);


//int sphere_interpen(int ii, int cnum,float radiusc,float radiuscore,float radiusshell,int corenumber,int shellnumber,float dl,int h, float x[80000], float y[80000], float z[80000],int& aa,int& index,int& basex,int& basey,int& basez, float lenpystruc, float heipystruc,int i,int j,int k,int xini,int xfin,int yini,int yfin,int zini,int zfin, float radiuscini, float radiuspt, float radiuspd, float distcentro,float rcarbonpt,float rcarbonpd, int alloynumber, float radiuspt, float radiuspd, float distcentro))
int sphere_interpen(int ii, int cnum,float radiusc,float radiuscore,float radiusshell,int corenumber,int shellnumber,float dl,int h, float x[80000], float y[80000], float z[80000],int& aa,int& index,int& basex,int& basey,int& basez, float lenpystruc, float heipystruc,int i,int j,int k,int xini,int xfin,int yini,int yfin,int zini,int zfin, float radiuscini, float radiuspt, float radiuspd, float distcentro,float rcarbonpt,float rcarbonpd,int alloynumber)
{
	
	
//	float rcarbonpt=radiuspt + cs;
																																	//	float rcarbonpd=radiuspd + cs;


//	float	div=float(radiusc/dl);

	float xx1, xx2, xx3, xx4;
	float yy1, yy2, yy3, yy4;
	float zz1, zz2, zz3, zz4;


	aa=0;

	int em;

// FIRST ELEMENT!

	float largerr;

	if(radiuspt>radiuspd)
	{
		largerr = rcarbonpt;
	}
	else
		{
		largerr = rcarbonpd;
		}

	xx1 = ((radiuspt + (largerr-radiuspt))/dl-i); 
//	xx1 = ((radiuspt + (rcarbonpt-radiuspt))/dl-i); 
	yy1 = ((radiuspt+(rcarbonpt-radiuspt))/dl-j); 
	zz1 = ((radiuspt+(largerr-radiuspt))/dl-k+1);

//	print(xx1)

// FIRST ELEMENT SHELL

	xx2 = ((radiuspt+(largerr-radiuspt))/dl-i); 
//	xx2 = ((radiuspt+(rcarbonpt-radiuspt))/dl-i); 
	yy2 = ((radiuspt+(rcarbonpt-radiuspt))/dl-j);
	zz2 = ((radiuspt+(largerr-radiuspt))/dl-k+1);



// SECOND ELEMENT !

	xx3 = ((radiuspd+(largerr-radiuspd))/dl-i+1);
//	xx3 = ((radiuspd+(rcarbonpd-radiuspd))/dl-i+1) 
	yy3 = ((radiuspd+(rcarbonpd-radiuspd)+distcentro)/dl-j+1);
	zz3 = ((radiuspd+(largerr-radiuspd))/dl-k+1);

// SECOND ELEMENT SHELL

	xx4 = ((radiuspd+(largerr-radiuspd))/dl-i+1);
//	xx4 = ((radiuspd+(rcarbonpd-radiuspd))/dl-i+1)
	yy4 = ((radiuspd+(rcarbonpd-radiuspd)+distcentro)/dl-j+1);
	zz4 = ((radiuspd+(largerr-radiuspd))/dl-k+1);

	em=1;

	float pott=float(2.0);



	if (distcentro>rcarbonpt+rcarbonpd)
	{


		if ( (  pow((xx1/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott)+pow((yy1/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott)+ 
pow((zz1/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott)) <= pow(((radiuspt)/(radiuspt+(rcarbonpt-radiuspt))),pott)) 
			{
			index=corenumber;
			aa=1;
//			print (aa)
			}

		else if (pow((xx2/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott)+pow((yy2/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott)+
pow((zz2/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott) >= pow(((radiuspt)/(radiuspt+(rcarbonpt-radiuspt))),pott) 
and pow((xx2/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott)+pow((yy2/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott)+
pow((zz2/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott) <= 1.0)
			{
			index=cnum;
			aa=1;
			}

		else if (pow((xx3/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott)+pow((yy3/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott)+
pow((zz3/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott)<=pow(((radiuspd)/(radiuspd+(rcarbonpd-radiuspd))),pott))
			{
			index=shellnumber;
			aa=1;
			}


		else if (pow((xx4/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott)+pow((yy4/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott)+
pow((zz4/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott) >= pow(((radiuspd)/(radiuspd+(rcarbonpd-radiuspd))),pott) 
and pow((xx4/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott)+pow((yy4/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott)+
pow((zz4/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott) <= 1.0)
			{

			index=cnum;
			aa=1;
			}



	}



	if (em == 1 and pow((xx1/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott)+pow((yy1/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott)+
pow((zz1/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott) <= pow(((radiuspt)/(radiuspt+(rcarbonpt-radiuspt))),pott) 
 and pow((xx3/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott)+pow((yy3/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott)+
pow((zz3/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott)  >  pow(((radiuspd)/(radiuspd+(rcarbonpd-radiuspd))),pott) 
 and ((pow((xx4/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott)+pow((yy4/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott)+
pow((zz4/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott) > 1.0) or (pow(((xx4/((radiuspd+(rcarbonpd-radiuspd))/dl))),pott) 
+pow((yy4/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott)+
pow((zz4/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott) < (pow(((radiuspd)/(radiuspd+(rcarbonpd-radiuspd))),pott) ) ))) 
		{

		index=corenumber;
		aa=1;

		em=1;
		}
// 	xy(i,j+(k-1)*(Dy1))=1
 
	else if (em == 1 and pow((xx1/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott)+pow((yy1/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott) 
+pow((zz1/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott) <= pow(((radiuspt)/(radiuspt+(rcarbonpt-radiuspt))),pott)  
and ( pow((xx4/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott)+pow((yy4/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott)+
pow((zz4/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott)  >=  pow(((radiuspd)/(radiuspd+(rcarbonpd-radiuspd))),pott) 
and pow((xx4/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott)+pow((yy4/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott) 
+pow((zz4/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott) <=1.0))
		{
		em=1;

		index=corenumber;
		aa=1;

		}

// 	xy(i,j+(k-1)*(Dy1))=1



	else if (em == 1 and pow((xx1/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott)+pow((yy1/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott) 
+pow((zz1/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott)  <=  pow(((radiuspt)/(radiuspt+(rcarbonpt-radiuspt))),pott) 
and pow((xx3/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott)+pow((yy3/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott) 
+pow((zz3/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott)  <=  pow(((radiuspd)/(radiuspd+(rcarbonpd-radiuspd))),pott))
		{
		em=1;
		index=alloynumber;
		aa=1;
		}

//	}


//	xy(i,j+(k-1)*(Dy1))=3

//  NOW FOR PT CARBON SHELL, i changed here

	if ((em == 1 and pow((xx2/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott)+pow((yy2/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott)
+pow((zz2/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott) >= pow(((radiuspt)/(radiuspt+(rcarbonpt-radiuspt))),pott) 
and pow((xx2/((radiuspt + (rcarbonpt-radiuspt))/dl)),pott)+pow((yy2/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott)+
pow((zz2/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott) <= 1.0 and pow((xx3/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott)+
pow((yy3/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott)+
pow((zz3/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott) >= pow(((radiuspd)/(radiuspd+(rcarbonpd-radiuspd))),pott) 
and ((pow((xx4/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott)+pow((yy4/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott)+
pow((zz4/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott) <= pow(((radiuspd)/(radiuspd+(rcarbonpd-radiuspd))),pott) )
or ( pow((xx4/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott) + pow((yy4/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott)+
pow((zz4/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott))>=1.0)))
		{
		em=1;
		index= cnum;
		aa=1;
		}

//	xy(i,j+(k-1)*(Dy1))=4



	else if (em == 1 and pow((xx2/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott)+pow((yy2/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott)+
pow((zz2/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott) >=pow(((radiuspt)/(radiuspt+(rcarbonpt-radiuspt))),pott) 
 and pow((xx2/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott)+pow((yy2/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott)+
pow((zz2/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott) <= 1.0 
 and pow((xx4/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott) + 
pow((yy4/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott)+
pow((zz4/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott) >= pow(((radiuspd)/(radiuspd+(rcarbonpd-radiuspd))),pott) 
and pow((xx4/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott)+pow((yy4/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott)+
pow((zz4/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott) <= 1.0)
		{
		em=1;
		index=cnum;
		aa=1;
	
		}
// xy(i,j+(k-1)*(Dy1))=4


	else if (em == 1 and pow((xx2/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott)+pow((yy2/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott)+
pow((zz2/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott) >=pow(((radiuspt)/(radiuspt+(rcarbonpt-radiuspt))),pott) 
and pow((xx2/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott)+pow((yy2/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott)+
pow((zz2/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott) <= 1.0 
and pow((xx3/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott)+pow((yy3/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott)+
pow((zz3/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott) <=(pow(((radiuspd)/(radiuspd+(rcarbonpd-radiuspd))),pott)) )
		{
		em=1;
		index= shellnumber;
		aa=1;
		}

// xy(i,j+(k-1)*(Dy1))=2



// just PD SPHERE! i changed here

//	}


	if (em == 1 and pow((xx3/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott)+pow((yy3/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott)+
pow((zz3/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott)<=pow(((radiuspd)/(radiuspd+(rcarbonpd-radiuspd))),pott) 
 and pow((xx1/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott)+pow((yy1/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott)+
pow((zz1/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott) > pow(((radiuspt)/(radiuspt+(rcarbonpt-radiuspt))),pott) 
and ((pow((xx2/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott)+pow((yy2/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott)+
pow((zz2/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott) < pow(((radiuspt)/(radiuspt+(rcarbonpt-radiuspt))),pott) 
or (pow((xx2/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott)+pow((yy2/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott)+
pow((zz2/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott) > 1.0))))
		{
		em=1;
		index=shellnumber;
		aa=1;
		}
// xy(i,j+(k-1)*(Dy1))=2



// JUST PD CARBON SHELL, i changed here

	if ((em == 1 and pow((xx4/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott)+pow((yy4/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott)+
pow((zz4/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott) >=pow(((radiuspd)/(radiuspd+(rcarbonpd-radiuspd))),pott) 
and pow((xx4/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott)+pow((yy4/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott)+
pow((zz4/((radiuspd+(rcarbonpd-radiuspd))/dl)),pott) <= 1.0 and pow((xx1/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott)+
pow((yy1/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott)+
pow((zz1/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott) > pow(((radiuspt)/(radiuspt+(rcarbonpt-radiuspt))),pott) 
and (( (  pow(xx2/((radiuspt+(rcarbonpt-radiuspt))/dl),pott))+pow((yy2/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott)+
pow((zz2/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott) < pow(((radiuspt)/(radiuspt+(rcarbonpt-radiuspt))),pott) ) 
or (( pow((xx2/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott)+pow((yy2/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott)+
(pow((zz2/((radiuspt+(rcarbonpt-radiuspt))/dl)),pott))) > 1.0))))
		{
		em=1;
		index=cnum;
		aa=1;

		}






	if(aa==0)
	{
		index=0;
	}

	if(aa==1)
	{
//		print (index,'index')
	}

// returning the current value of the variable zz.


	return index;

}


//////////////////////////////////////////////////////////////////////////////////////////////////////////


int incoreshell_ellipsoid(int ii, int cnum,float radiusc,float radiuscore,float radiusshell,int corenumber,int shellnumber,float dl,int h, float x[80000], float y[80000], float z[80000],int& aa,int& index,int& basex,int& basey,int& basez, float lenpystruc, float heipystruc,int i,int j,int k,int xini,int xfin,int yini,int yfin,int zini,int zfin, float radiuscini, float radiuspt, float radiuspd, float distcentro,float rcarbonpt,float rcarbonpd,int alloynumber, float radiusxcs, float radiusycs, float radiuszcs, char* pilingstruc)
{

	float div1=float(radiusxcs/dl);
	float div2=float(radiusycs/dl);
	float div3=float(radiuszcs/dl);


	radiuscore =radiusxcs;
	radiusshell = radiusxcs+10;
	radiusc = radiusshell+10.0;


	float tent01 =	(pow(x[ii]/(div1),2.0)+pow(y[ii]/(div2),2.0)+pow(z[ii]/(div3),2.0));
	
	if ( tent01 <= ((pow(float(radiuscore)/(float(radiusc)),2.0) )))
//					#			A[a][b]=corenumber
	{
								index=corenumber;
								aa=1;

	}
// shell

	float tentum11=(pow(x[ii]/(div1),2.0)+pow(y[ii]/(div2),2.0)+ pow(z[ii]/(div3),2.0));
	float tentum12=(pow(x[ii]/(div1),2.0)+pow(y[ii]/(div2),2.0)+ pow(z[ii]/(div3),2.0));

	if ( tentum11 >= (pow(float(radiuscore)/(float(radiusc)),2.0)) and tentum12 <= ((pow(float(radiusshell)/(float(radiusc)),2.0))))																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																											
	{
//						                A[a][b]=shellnumber
								index=shellnumber;
								aa=1;

	}

// carbon shell

	float tentum  =((pow(x[ii]/div1,2.0))+pow(y[ii]/(div2),2.0)+ pow(z[ii]/(div3),2.0));
	float tentdois = (pow(x[ii]/(div1),2.0)+pow(y[ii]/(div2),2.0)+ pow(z[ii]/(div3),2.0));


	if ( tentum >= (pow((float(radiusshell))/(float(radiusc)),2.0)) and  tentdois <= (1.0))
//		        			        	A[a][b]=cnum
	{

								index=cnum;
								aa=1;
	}



	return index;

}


///////////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////////////////



int incoreshell_cylinder(int ii, int cnum,float radiusc,float radiuscore,float radiusshell,int corenumber,int shellnumber,float dl,int h, float x[80000], float y[80000], float z[80000],int& aa,int& index,int& basex,int& basey,int& basez, float lenpystruc, float heipystruc,int i,int j,int k,int xini,int xfin,int yini,int yfin,int zini,int zfin, float radiuscini, float radiuspt, float radiuspd, float distcentro,float rcarbonpt,float rcarbonpd,int alloynumber, float radiusxcs, float radiusycs, float radiuszcs, char* pilingstruc)
{



	radiuscore =radiusxcs;
	radiusshell = radiusxcs+10;
	radiusc = radiusshell+10.0;

	float div1=float(radiusc/dl);
	float div2=float(radiusc/dl);
//	float div3=float(radiuszcs/dl);




	float tent01 =	(pow(x[ii]/(div1),2.0)+pow(y[ii]/(div2),2.0));
	
//	float tent02= pow(z[ii]/(div3),2.0);
	// and tent02 <= ((pow(float(radiuscore)/(float(radiusc)),2.0) ))
	
	if ( tent01 <= ((pow(float(radiuscore)/(float(radiusc)),2.0) )))
//					#			A[a][b]=corenumber
	{
								index=corenumber;
								aa=1;

	}
// shell

	float tentum11 = pow(x[ii]/(div1),2.0)+pow(y[ii]/(div2),2.0);
//	float tentum11z = pow(z[ii]/(div3),2.0);
	float tentum12 = (pow(x[ii]/(div1),2.0)+pow(y[ii]/(div2),2.0));
//	float tentum12z = pow(z[ii]/(div3),2.0);

	//	and tentum11z >= (pow(float(radiuscore)/(float(radiusc)),2.0))
	//	and tentum12z <= ((pow(float(radiusshell)/(float(radiusc)),2.0))

	if ( tentum11 >= (pow(float(radiuscore)/(float(radiusc)),2.0))  and tentum12 <= ((pow(float(radiusshell)/(float(radiusc)),2.0))) )							
	{
//						                A[a][b]=shellnumber
								index=shellnumber;
								aa=1;

	}

// carbon shell

	float tentum  =((pow(x[ii]/div1,2.0))+pow(y[ii]/(div2),2.0));
//	float tentumz  =pow(z[ii]/(div3),2.0);


	float tentdois = (pow(x[ii]/(div1),2.0)+pow(y[ii]/(div2),2.0));
//	float tentdoisz = pow(z[ii]/(div3),2.0);

	// and tentumz >= (pow((float(radiusshell))/(float(radiusc)),2.0)) 
	//   and tentdoisz <= (1.0)

	if ( tentum >= (pow((float(radiusshell))/(float(radiusc)),2.0)) and  tentdois <= (1.0))
//		        			        	A[a][b]=cnum
	{

								index=cnum;
								aa=1;
	}



	return index;

}


///////////////////////////////////////////////////////////////////////////////////////////////////////////

int incoreshell_octahedron(int ii, int cnum,float radiusc,float radiuscore,float radiusshell,int corenumber,int shellnumber,float dl,int h, float x[80000], float y[80000], float z[80000],int& aa,int& index,int& basex,int& basey,int& basez, float lenpystruc, float heipystruc,int i,int j,int k,int xini,int xfin,int yini,int yfin,int zini,int zfin, float radiuscini, float radiuspt, float radiuspd, float distcentro,float rcarbonpt,float rcarbonpd,int alloynumber, float radiusxcs, float radiusycs, float radiuszcs, char* pilingstruc)
{



	float div = float(radiusc/dl);


//	print (x[ii])

	aa=0;

// core

	float acore = (abs(x[ii]/(div))+abs(y[ii]/(div))+abs(z[ii]/(div)));


	if (( acore <= pow(((float(radiuscore))/(float(radiusc))),2.0) ))
	{
//					#			A[a][b]=corenumber
								index=corenumber;
								aa=1;
// shell

	}

	float ashell = (abs(x[ii]/(div))+abs(y[ii]/(div))+abs(z[ii]/(div)));  //  <= pow(((float(radiusshell))/(float(radiusc))),2.0);

	if ( (ashell <= pow(((float(radiusshell))/(float(radiusc))),2.0) ) and ( acore >= pow(((float(radiuscore))/(float(radiusc))),2.0) ))
	{
//						                A[a][b]=shellnumber
		index=shellnumber;
		aa=1;

	}

// carbon shell

	float acarbon= (abs(x[ii]/div)+abs(y[ii]/div)+abs(z[ii]/div));


	if ( (acarbon <= (pow(((float(radiusc))/(float(radiusc))),2.0)) ) and ((ashell >=  pow(((float(radiusshell))/(float(radiusc))),2.0) )))
	{
//		        			        	A[a][b]=cnum
	index=cnum;
	aa=1;

	}



	return index;

}



/////////////////////////////////////////////////////////////////////////////////////////////////////////

int incoreshell_triplate(int ii, int cnum,float radiusc,float radiuscore,float radiusshell,int corenumber,int shellnumber,float dl,int h, float x[80000], float y[80000], float z[80000],int& aa,int& index,int& basex,int& basey,int& basez, float lenpystruc, float heipystruc,int i,int j,int k,int xini,int xfin,int yini,int yfin,int zini,int zfin, float radiuscini, float radiuspt, float radiuspd, float distcentro,float rcarbonpt,float rcarbonpd,int alloynumber, float radiusxcs, float radiusycs, float radiuszcs, char* pilingstruc,float base,float width,float height,float base2,float width2,float cs)
//										incoreshell_triplate(ii,cnum,radiusc,radiuscore,radiusshell,corenumber,shellnumber,dl,h,x,y,z,aa,index,basex,basey,basez,lenpystruc,heipystruc,i,j,k,xini,xfin,yini,yfin,zini,zfin,radiuscini,radiuspt,radiuspd,distcentro,rcarbonpt,rcarbonpd,alloynumber,radiusxcs,radiusycs,radiuszcs,pilingstruc, base, width, height, base2, width2, cs);
{

//   here are described the equations to form a triangular plate nanoparticle
//  it must be repaired

	float	div=float(radiusc/dl);





//	cout<< radiusc << "radddccccc" << endl;





//	float basenew = base2+cs;
//	float widthnew =width2+cs;

	float basenew = base2+cs;
	float widthnew =width2+cs;


	aa=0;

	bool acore1=false;
	bool acore2=false;


if( 0 <= x[ii]/div and x[ii]/div <= base/(2*basenew))
{



	if( y[ii]/div >=width/widthnew-(x[ii]/div)*(2*width*(basenew)/(base*widthnew)))
	{
//		print (x[ii],base/2)

		acore1=true;

	}

}

if( -base/(2*basenew) <= x[ii]/div and  x[ii]/div<= 0 )
{
	if( y[ii]/div >=width/widthnew+(x[ii]/div)*(2*width*(basenew)/(base*widthnew)))
	{
			acore2= true;
	}

}


if ( acore1 or acore2 )
{

//								print (x[ii],base/2)


//					#			A[a][b]=corenumber
		index=corenumber;
		index=0;
		aa=1;

//								print(index)

}




	bool ashell1 = false;
	bool ashell2 = false;



	
	
//	cout << base/2 << base/2.0 << "eiiiaaaa" << endl;
	
	


if( 0 <= x[ii] and x[ii] <= base2/2)
{
	if( y[ii]<=width2-x[ii]*(2*width2/base2))
	{
		ashell1 = true;
	}
	
}

if( -base2/2 <= x[ii] and x[ii] <= 0 )
{
	if( y[ii]<=width2+x[ii]*(2*width2/base2))
	{
		ashell2= true;
	}

}

	 bool aant=true;
	

if (acore1==false and acore2==false)
{
	aant=false;
}

if ( ashell1 or (ashell2 and  aant==false) )
{


//					#			A[a][b]=corenumber
	index=shellnumber;
	aa=1;

}



	bool acnum1 = false;
	bool acnum2 = false;

	basenew = base2+cs;
	widthnew =width2+cs;


//	cout<< width << base << height << base2 <<width2 << "widthhhh" << endl;



if( 0 <=x[ii] and  x[ii] <= basenew/2)
{
		if( y[ii]<=widthnew-x[ii]*(2*widthnew/basenew))
		{
			acnum1=true;
		}

}

if( -base2/2 <= x[ii] and  x[ii] <= 0 )
{

	if( y[ii]<=widthnew+x[ii]*(2*widthnew/basenew))
	{
		acnum2= true;
	}
	
}	
aant = true;
	
if (ashell1 == false and ashell2 == false)
{

	aant=false;

}

if ( acnum1 or (acnum2 and  aant==false) )
{

//					#			A[a][b]=corenumber
	index=cnum;
	index=0;
	aa=1;

}



	if(aa==0)
	{

		index=0;

	}










	return index;


}

/*
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

				HERE BEGINS THE CUBIC IN CORE SHELL

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*/

//int incoreshell_triplate(int ii, int cnum,float radiusc,float radiuscore,float radiusshell,int corenumber,int shellnumber,float dl,int h, float x[80000], float y[80000], float z[80000],int& aa,int& index,int& basex,int& basey,int& basez, float lenpystruc, float heipystruc,int i,int j,int k,int xini,int xfin,int yini,int yfin,int zini,int zfin, float radiuscini, float radiuspt, float radiuspd, float distcentro,float rcarbonpt,float rcarbonpd,int alloynumber, float radiusxcs, float radiusycs, float radiuszcs, char* pilingstruc,float base,float width,float height,float base2,float width2,float cs)
int incoreshell_cubic(int ii, int cnum,float radiusc,float radiuscore,float radiusshell,int corenumber,int shellnumber,float dl,int h, float x[80000], float y[80000], float z[80000],int& aa,int& index,int& basex,int& basey,int& basez, float lenpystruc, float heipystruc,int i,int j,int k,int xini,int xfin,int yini,int yfin,int zini,int zfin, float radiuscini, float radiuspt, float radiuspd, float distcentro,float rcarbonpt,float rcarbonpd,int alloynumber, float radiusxcs, float radiusycs, float radiuszcs, char* pilingstruc,float base,float width,float height,float base2,float width2,float cs)
//										incoreshell_triplate(ii,cnum,radiusc,radiuscore,radiusshell,corenumber,shellnumber,dl,h,x,y,z,aa,index,basex,basey,basez,lenpystruc,heipystruc,i,j,k,xini,xfin,yini,yfin,zini,zfin,radiuscini,radiuspt,radiuspd,distcentro,rcarbonpt,rcarbonpd,alloynumber,radiusxcs,radiusycs,radiuszcs,pilingstruc, base, width, height, base2, width2, cs);
{

	float div=float(radiusc/dl);
	aa=0;
	
	bool acore;
	
	acore=pow((x[ii]/(div)),2.0) <= pow(((float(radiuscore))/(float(radiusc))),2.0) and pow((y[ii]/(div)),2.0) <= pow(((float(radiuscore))/(float(radiusc))),2.0) and pow((z[ii]/(div)),2.0) <= pow(((float(radiuscore))/(float(radiusc))),2.0);
	
	if ( acore )
	{

	index=corenumber;
	aa=1;

	}
	
	bool ashell= pow((x[ii]/(div)),2.0) <= pow(((float(radiusshell))/(float(radiusc))),2.0) and  pow((y[ii]/(div)),2.0) <= pow(((float(radiusshell))/(float(radiusc))),2.0)  and  pow((z[ii]/(div)),2.0) <= pow(((float(radiusshell))/(float(radiusc))),2.0);

	if ( ashell and acore== false)
	{

	index=shellnumber;
	aa=1;
	
	}

	bool acarbon= pow( (x[ii]/(div)),2.0)<=1.0 and pow((y[ii]/(div)),2.0) <= 1.0 and pow((z[ii]/(div)),2.0) <= 1.0;


	if ( ashell == false and acarbon == true)
	{

	index=cnum;
	aa=1;

	}


	if(aa==0)
	{
		
	index=0;
	
	}



	return index;


}


/////////////////////////////////////////////////////////////////////////////////////////////////////////

/*

				HERE COMES THE MANY SHELL FUNC

*/

int incoreshell_manyshell(int ii, int cnum,float radiusc,float radiuscore,float radiusshell,int corenumber,int shellnumber,float dl,int h, float x[80000], float y[80000], float z[80000],int& aa,int& index,int& basex,int& basey,int& basez, float lenpystruc, float heipystruc,int i,int j,int k,int xini,int xfin,int yini,int yfin,int zini,int zfin, float radiuscini, float radiuspt, float radiuspd, float distcentro,float rcarbonpt,float rcarbonpd,int alloynumber, float radiusxcs, float radiusycs, float radiuszcs, char* pilingstruc,float base,float width,float height,float base2,float width2,float cs, int partes, int indorigins)
//										incoreshell_triplate(ii,cnum,radiusc,radiuscore,radiusshell,corenumber,shellnumber,dl,h,x,y,z,aa,index,basex,basey,basez,lenpystruc,heipystruc,i,j,k,xini,xfin,yini,yfin,zini,zfin,radiuscini,radiuspt,radiuspd,distcentro,rcarbonpt,rcarbonpd,alloynumber,radiusxcs,radiusycs,radiuszcs,pilingstruc, base, width, height, base2, width2, cs);
{

//	partes=int(radiusc/dl);

	float radd[partes+1];
	float rad;
	float indd;

	radd[0]=dl;
	
	float indice[partes+1];
	
	indice[0]=indorigins;

	rad=0;

	indd=indorigins;

//	float x[partes+1];

//	int aaa=0;

for(int uu=0; uu < partes; uu++)
{
//	float radmaisum;

//	radmaisum=rad+dl;
	rad=rad+int(radiusc/partes);

	radd[uu+1]=rad;

	indd=indd+1;

	indice[uu+1]=indd;

	if ( ((   pow((x[ii]/((radiuscore+(radiusc-radiuscore))/dl)),2.0)+pow((y[ii]/((radiuscore+(radiusc-radiuscore))/dl)),2.0)+ 
	pow((z[ii]/((radiuscore+(radiusc-radiuscore))/dl)),2.0)   ) >=  pow(((radd[uu])/(radiuscore+(radiusc-radiuscore))),2.0) ) 
	and ((   pow((x[ii]/((radiuscore+(radiusc-radiuscore))/dl)),2.0)   +    pow((y[ii]/((radiuscore+(radiusc-radiuscore))/dl)),2.0)+ 
	pow((z[ii]/((radiuscore+(radiusc-radiuscore))/dl)),2.0)    )  <=  pow(((radd[uu+1])/(radiuscore+(radiusc-radiuscore))),2.0)   ))
	{
	
// em=1;
	
	
	index = indice[uu];
	aa=1;
	}

}


//	cout << index << "indexxxx" << endl;


	if(aa==0)
	{
	index=0;	
	}


	return index;


}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

int incoreshell_spheresurface(int ii, int cnum,float radiusc,float radiuscore,float radiusshell,int corenumber,int shellnumber,float dl,int h, float x[80000], float y[80000], float z[80000], int& index,int& aa, int radiussurface, int surfaceindex)
{


///////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
  
				THAT IS THE CENTRAL SPHERE
 
*/

///////////////////////////////////////////////////////////////////////////////////////////////////////////


	float div=float(radiusc/dl);

	// the below value should be a function parameter

//	float cs=10.0;

	float bb=x[ii];
	float cc=y[ii];
	float dd=z[ii];


	x[ii]=x[ii]-radiussurface*0;
	y[ii]=y[ii]-radiussurface*0;
	z[ii]=z[ii]-radiussurface*0;
	



	if ( (pow((x[ii])/div,2.0)+pow((y[ii])/div,2.0)+pow((z[ii])/div,2.0)   ) <= (pow((radiuscore)/radiusc,2.0 )) )
{
//					#			A[a][b]=corenumber
								index=corenumber;
								aa=1;
//		cout << pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+pow(z[ii]/div,2.0) << endl;

}
// shell

	if ( (  pow((x[ii])/div,2.0)+pow((y[ii])/div,2.0)+ pow((z[ii])/div,2.0)) >= (pow(radiuscore/radiusc,2.0)  ) and ((pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+ pow(z[ii]/div,2.0) ) <= (pow(radiusshell/radiusc,2.0))))
{
//				                A[a][b]=shellnumber
								index=shellnumber;
								aa=1;

}

// carbon shell

	if ( ((  pow( (x[ii])/div,2.0)+pow((y[ii])/div,2.0)+ (pow((z[ii])/div,2.0)) ) >= (pow((radiusshell)/radiusc,2.0))) and ((pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+ pow(z[ii]/div,2.0)) <= (pow((radiusshell)/radiusc,2.0))))
	{

//		        			        	A[a][b]=cnum
								index=cnum;
//	cout << pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+pow(z[ii]/div,2.0) << endl;

								aa=1;

	}



	x[ii]=bb-radiussurface*0;
	y[ii]=cc;
	z[ii]=dd;



		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

				FIRST SPHERE TRANSLATED IN X
 
 */

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////



	if ( (pow((x[ii]-radiusshell-radiussurface)/div,2.0)+pow(y[ii]/div,2.0)+pow(z[ii]/div,2.0)   ) <= (pow((radiussurface)/radiusc,2.0 )) )
{
//					#			A[a][b]=corenumber
								index=surfaceindex;
								aa=1;
//		cout << pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+pow(z[ii]/div,2.0) << endl;

}



		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

				SECOND SPHERE TRANSLATED IN X
 
 */

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////



	if ( (pow((x[ii]+radiusshell+radiussurface)/div,2.0)+pow(y[ii]/div,2.0)+pow(z[ii]/div,2.0)   ) <= (pow((radiussurface)/radiusc,2.0 )) )
{
//					#			A[a][b]=corenumber
								index=surfaceindex;
								aa=1;
//		cout << pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+pow(z[ii]/div,2.0) << endl;

}






////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

				FIRST SPHERE TRANSLATED IN Y
 
 */

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////



	if ( (pow((x[ii])/div,2.0)+pow((y[ii]-radiusshell-radiussurface)/div,2.0)+pow(z[ii]/div,2.0)   ) <= (pow((radiussurface)/radiusc,2.0 )) )
	{
//					#			A[a][b]=corenumber
								index=surfaceindex;
								aa=1;
//		cout << pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+pow(z[ii]/div,2.0) << endl;

	}



		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

				SECOND SPHERE TRANSLATED IN Y
 
 */

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////



	if ( (pow((x[ii])/div,2.0)+pow((y[ii]+radiusshell+radiussurface)/div,2.0)+pow(z[ii]/div,2.0)   ) <= (pow((radiussurface)/radiusc,2.0 )) )
	{
//					#			A[a][b]=corenumber
								index=surfaceindex;
								aa=1;
//		cout << pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+pow(z[ii]/div,2.0) << endl;

	}






//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

				FIRST SPHERE TRANSLATED IN Z
 
 */

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////



	if ( (pow((x[ii])/div,2.0)+pow((y[ii])/div,2.0)+pow((z[ii]-radiusshell-radiussurface)/div,2.0)   ) <= (pow((radiussurface)/radiusc,2.0 )) )
	{
//					#			A[a][b]=corenumber
								index=surfaceindex;
								aa=1;
//		cout << pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+pow(z[ii]/div,2.0) << endl;

	}



		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

				SECOND SPHERE TRANSLATED IN Z
 
 */

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////



	if ( (pow((x[ii])/div,2.0)+pow((y[ii])/div,2.0)+pow((z[ii]+radiusshell+radiussurface)/div,2.0)   ) <= (pow((radiussurface)/radiusc,2.0 )) )
	{
//					#			A[a][b]=corenumber
								index=surfaceindex;
								aa=1;
//		cout << pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+pow(z[ii]/div,2.0) << endl;

	}











	if(aa==0)
	{
		index=0;
	}

	if(aa==1)
	{
//		print (index,'index')
	}



	return index;

}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////////////////

int incoreshell_spheresurfacetwo(int ii, int cnum,float radiusc,float radiuscore,float radiusshell,int corenumber,int shellnumber,float dl,int h, float x[80000], float y[80000], float z[80000], int& index,int& aa, int radiussurface, int surfaceindex)
{


///////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
  
				THAT IS THE CENTRAL SPHERE
 
*/

///////////////////////////////////////////////////////////////////////////////////////////////////////////


	float div=float(radiusc/dl);

	// the below value should be a function parameter

//	float cs=10.0;

	float bb=x[ii];
	float cc=y[ii];
	float dd=z[ii];


	x[ii]=x[ii]-radiussurface*0;
	y[ii]=y[ii]-radiussurface*0;
	z[ii]=z[ii]-radiussurface*0;
	



	if ( (pow((x[ii])/div,2.0)+pow((y[ii])/div,2.0)+pow((z[ii])/div,2.0)   ) <= (pow((radiuscore)/radiusc,2.0 )) )
{
//					#			A[a][b]=corenumber
								index=corenumber;
								aa=1;
//		cout << pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+pow(z[ii]/div,2.0) << endl;

}
// shell

	if ( (  pow((x[ii])/div,2.0)+pow((y[ii])/div,2.0)+ pow((z[ii])/div,2.0)) >= (pow(radiuscore/radiusc,2.0)  ) and ((pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+ pow(z[ii]/div,2.0) ) <= (pow(radiusshell/radiusc,2.0))))
{
//				                A[a][b]=shellnumber
								index=shellnumber;
								aa=1;

}

// carbon shell

	if ( ((  pow( (x[ii])/div,2.0)+pow((y[ii])/div,2.0)+ (pow((z[ii])/div,2.0)) ) >= (pow((radiusshell)/radiusc,2.0))) and ((pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+ pow(z[ii]/div,2.0)) <= (pow((radiusshell)/radiusc,2.0))))
	{

//		        			        	A[a][b]=cnum
								index=cnum;
//	cout << pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+pow(z[ii]/div,2.0) << endl;

								aa=1;

	}



	x[ii]=bb-radiussurface*0;
	y[ii]=cc;
	z[ii]=dd;



		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

				FIRST SPHERE TRANSLATED IN X
 
 */

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////



	if ( (pow((x[ii]-radiusshell-radiussurface)/div,2.0)+pow(y[ii]/div,2.0)+pow(z[ii]/div,2.0)   ) <= (pow((radiussurface)/radiusc,2.0 )) )
{
//					#			A[a][b]=corenumber
								index=surfaceindex;
								aa=1;
//		cout << pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+pow(z[ii]/div,2.0) << endl;

}



		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

				SECOND SPHERE TRANSLATED IN X
 
 */

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////



	if ( (pow((x[ii]+radiusshell+radiussurface)/div,2.0)+pow(y[ii]/div,2.0)+pow(z[ii]/div,2.0)   ) <= (pow((radiussurface)/radiusc,2.0 )) )
{
//					#			A[a][b]=corenumber
								index=surfaceindex;
								aa=1;
//		cout << pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+pow(z[ii]/div,2.0) << endl;

}






////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

				FIRST SPHERE TRANSLATED IN Y
 
 */

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////



	if ( (pow((x[ii])/div,2.0)+pow((y[ii]-radiusshell-radiussurface)/div,2.0)+pow(z[ii]/div,2.0)   ) <= (pow((radiussurface)/radiusc,2.0 )) )
	{
//					#			A[a][b]=corenumber
								index=surfaceindex;
								aa=1;
//		cout << pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+pow(z[ii]/div,2.0) << endl;

	}



		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

				SECOND SPHERE TRANSLATED IN Y
 
 */

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////



	if ( (pow((x[ii])/div,2.0)+pow((y[ii]+radiusshell+radiussurface)/div,2.0)+pow(z[ii]/div,2.0)   ) <= (pow((radiussurface)/radiusc,2.0 )) )
	{
//					#			A[a][b]=corenumber
								index=surfaceindex;
								aa=1;
//		cout << pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+pow(z[ii]/div,2.0) << endl;

	}






//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

				FIRST SPHERE TRANSLATED IN Z
 
 */

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////



	if ( (pow((x[ii])/div,2.0)+pow((y[ii])/div,2.0)+pow((z[ii]-radiusshell-radiussurface)/div,2.0)   ) <= (pow((radiussurface)/radiusc,2.0 )) )
	{
//					#			A[a][b]=corenumber
								index=surfaceindex;
								aa=1;
//		cout << pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+pow(z[ii]/div,2.0) << endl;

	}



		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

				SECOND SPHERE TRANSLATED IN Z
 
 */

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////



	if ( (pow((x[ii])/div,2.0)+pow((y[ii])/div,2.0)+pow((z[ii]+radiusshell+radiussurface)/div,2.0)   ) <= (pow((radiussurface)/radiusc,2.0 )) )
	{
//					#			A[a][b]=corenumber
								index=surfaceindex;
								aa=1;
//		cout << pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+pow(z[ii]/div,2.0) << endl;

	}


/*

									NOW COMES THE OTHERS

*/


		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

													FIRST SPHERE 
 
 */

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////



	if ( (pow((x[ii]+(radiusshell+radiussurface)/sqrt(3.0))/(div),2.0)+pow((y[ii]+(radiusshell+radiussurface)/sqrt(3.0))/(div),2.0)+pow((z[ii]+(radiusshell+radiussurface)/sqrt(3.0))/(div),2.0)   ) <= (pow((radiussurface)/radiusc,2.0 )) )
	{
//					#			A[a][b]=corenumber
								index=surfaceindex;
								aa=1;
//		cout << pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+pow(z[ii]/div,2.0) << endl;

	}




		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

													SECOND SPHERE 
 
 */

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////



	if ( (pow((x[ii]-(radiusshell+radiussurface)/sqrt(3.0))/(div),2.0)+pow((y[ii]+(radiusshell+radiussurface)/sqrt(3.0))/(div),2.0)+pow((z[ii]+(radiusshell+radiussurface)/sqrt(3.0))/(div),2.0)   ) <= (pow((radiussurface)/radiusc,2.0 )) )
	{
//					#			A[a][b]=corenumber
								index=surfaceindex;
								aa=1;
//		cout << pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+pow(z[ii]/div,2.0) << endl;

	}




		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

													THIRD SPHERE 
 
 */

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////



	if ( (pow((x[ii]+(radiusshell+radiussurface)/sqrt(3.0))/(div),2.0)+pow((y[ii]-(radiusshell+radiussurface)/sqrt(3.0))/(div),2.0)+pow((z[ii]+(radiusshell+radiussurface)/sqrt(3.0))/(div),2.0)   ) <= (pow((radiussurface)/radiusc,2.0 )) )
	{
//					#			A[a][b]=corenumber
								index=surfaceindex;
								aa=1;
//		cout << pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+pow(z[ii]/div,2.0) << endl;

	}


		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

													FOURTH SPHERE 
 
 */

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////



	if ( (pow((x[ii]+(radiusshell+radiussurface)/sqrt(3.0))/(div),2.0)+pow((y[ii]+(radiusshell+radiussurface)/sqrt(3.0))/(div),2.0)+pow((z[ii]-(radiusshell+radiussurface)/sqrt(3.0))/(div),2.0)   ) <= (pow((radiussurface)/radiusc,2.0 )) )
	{
//					#			A[a][b]=corenumber
								index=surfaceindex;
								aa=1;
//		cout << pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+pow(z[ii]/div,2.0) << endl;

	}


		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

													FIFTH SPHERE 
 
 */

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////



	if ( (pow((x[ii]-(radiusshell+radiussurface)/sqrt(3.0))/(div),2.0)+pow((y[ii]+(radiusshell+radiussurface)/sqrt(3.0))/(div),2.0)+pow((z[ii]-(radiusshell+radiussurface)/sqrt(3.0))/(div),2.0)   ) <= (pow((radiussurface)/radiusc,2.0 )) )
	{
//					#			A[a][b]=corenumber
								index=surfaceindex;
								aa=1;
//		cout << pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+pow(z[ii]/div,2.0) << endl;

	}



		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

													SIXTH SPHERE 
 
 */

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////



	if ( (pow((x[ii]-(radiusshell+radiussurface)/sqrt(3.0))/(div),2.0)+pow((y[ii]-(radiusshell+radiussurface)/sqrt(3.0))/(div),2.0)+pow((z[ii]+(radiusshell+radiussurface)/sqrt(3.0))/(div),2.0)   ) <= (pow((radiussurface)/radiusc,2.0 )) )
	{
//					#			A[a][b]=corenumber
								index=surfaceindex;
								aa=1;
//		cout << pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+pow(z[ii]/div,2.0) << endl;

	}


		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

													FIRST SPHERE 
 
 */

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////



	if ( (pow((x[ii]+(radiusshell+radiussurface)/sqrt(3.0))/(div),2.0)+pow((y[ii]-(radiusshell+radiussurface)/sqrt(3.0))/(div),2.0)+pow((z[ii]-(radiusshell+radiussurface)/sqrt(3.0))/(div),2.0)   ) <= (pow((radiussurface)/radiusc,2.0 )) )
	{
//					#			A[a][b]=corenumber
								index=surfaceindex;
								aa=1;
//		cout << pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+pow(z[ii]/div,2.0) << endl;

	}




		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

													FIRST SPHERE 
 
 */

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////



	if ( (pow((x[ii]-(radiusshell+radiussurface)/sqrt(3.0))/(div),2.0)+pow((y[ii]-(radiusshell+radiussurface)/sqrt(3.0))/(div),2.0)+pow((z[ii]-(radiusshell+radiussurface)/sqrt(3.0))/(div),2.0)   ) <= (pow((radiussurface)/radiusc,2.0 )) )
	{
//					#			A[a][b]=corenumber
								index=surfaceindex;
								aa=1;
//		cout << pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+pow(z[ii]/div,2.0) << endl;

	}




	if(aa==0)
	{
		index=0;
	}

	if(aa==1)
	{
//		print (index,'index')
	}



	return index;

}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
 * 
				*	 
				HERE COMES THE PAVING STONE
				* 
				* 
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int incoreshell_pavingstone(int ii, int cnum,float radiusc,float radiuscore,float radiusshell,int corenumber,int shellnumber,float dl,int h, float x[80000], float y[80000], float z[80000],int& aa,int& index,int& basex,int& basey,int& basez, float lenpystruc, float heipystruc,int i,int j,int k,int xini,int xfin,int yini,int yfin,int zini,int zfin, float radiuscini, float radiuspt, float radiuspd, float distcentro,float rcarbonpt,float rcarbonpd,int alloynumber, float radiusxcs, float radiusycs, float radiuszcs, char* pilingstruc,float base,float width,float height,float base2,float width2,float cs, int xlength, int ylength, int zlength, int xlength2, int ylength2, int zlength2)
//										incoreshell_triplate(ii,cnum,radiusc,radiuscore,radiusshell,corenumber,shellnumber,dl,h,x,y,z,aa,index,basex,basey,basez,lenpystruc,heipystruc,i,j,k,xini,xfin,yini,yfin,zini,zfin,radiuscini,radiuspt,radiuspd,distcentro,rcarbonpt,rcarbonpd,alloynumber,radiusxcs,radiusycs,radiuszcs,pilingstruc, base, width, height, base2, width2, cs);
{

	float div=float(radiusc/dl);
	aa=0;
	
	bool acore;
	
	acore=pow((x[ii]/(div)),2.0) <= pow(((float(xlength))/(float(radiusc))),2.0) and pow((y[ii]/(div)),2.0) <= pow(((float(ylength))/(float(radiusc))),2.0) and pow((z[ii]/(div)),2.0) <= pow(((float(zlength))/(float(radiusc))),2.0);
	
	if ( acore )
	{

	index=corenumber;
	aa=1;

	}
	
	bool ashell= pow((x[ii]/(div)),2.0) <= pow(((float(xlength2))/(float(radiusc))),2.0) and  pow((y[ii]/(div)),2.0) <= pow(((float(ylength2))/(float(radiusc))),2.0)  and  pow((z[ii]/(div)),2.0) <= pow(((float(zlength2))/(float(radiusc))),2.0);

	if ( ashell and acore== false)
	{

	index=shellnumber;
	aa=1;
	
	}


/*

	bool acarbon= pow( (x[ii]/(div)),2.0)<=1.0 and pow((y[ii]/(div)),2.0) <= 1.0 and pow((z[ii]/(div)),2.0) <= 1.0;


	if ( ashell == false and acarbon == true)
	{

	index=cnum;
	aa=1;

	}

*/

	if(aa==0)
	{
		
	index=0;
	
	}



	return index;


}


/////////////////////////////////////////////////////////////////////////////////////////////////////////

/*

								HERE COMES THE HALF SPHERE!!!!!!

*/


//int incoreshell_sphere(int ii, int cnum,float radiusc,float radiuscore,float radiusshell,int corenumber,int shellnumber,float dl,int h, float x[80000], float y[80000], float z[80000], int& index,int& aa)
//						incoreshell_halfsphere(ii,cnum,radiusc,radiuscore,radiusshell,corenumber,shellnumber,dl,h,x,y,z,index,aa,halfsphereradius1,halfsphereradius2);
int incoreshell_halfsphere(int ii, int cnum,float radiusc,float radiuscore,float radiusshell,int corenumber,int shellnumber,float dl,int h,float x[80000],float y[80000],float z[80000], int& index,int& aa, int halfsphereradius1, int halfsphereradius2)
{

	z[ii]=z[ii]-radiusc/dl;

	if ( z[ii] <= 0 ) 
	{
		if ( (pow(x[ii]/((radiuscore+(radiusc-radiuscore))/dl),2.0)+pow(y[ii]/((radiuscore+(radiusc-radiuscore))/dl),2.0)+ 
		pow(z[ii]/((radiuscore+(radiusc-radiuscore))/dl),2.0)) <= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2.0) )
		{
			index=corenumber;
			aa=1;
//			em=1;
		}
// shell
		if ( ( ( pow(x[ii]/((radiuscore+(radiusc-radiuscore))/dl),2.0) + pow(y[ii]/((radiuscore+(radiusc-radiuscore))/dl),2.0)+ 
		pow(z[ii]/((radiuscore+(radiusc-radiuscore))/dl),2.0) ) >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2.0) )
		and ( ( pow(x[ii]/((radiuscore+(radiusc-radiuscore))/dl),2.0)+pow(y[ii]/((radiuscore+(radiusc-radiuscore))/dl),2.0)+ 
		pow(z[ii]/((radiuscore+(radiusc-radiuscore))/dl),2.0) ) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2.0) ))
		{
			index=shellnumber;
			aa=1;
//			em=1;
		}
// carbon shell
		if ( ( ( pow(x[ii]/((radiuscore+(radiusc-radiuscore))/dl),2.0)+pow(y[ii]/((radiuscore+(radiusc-radiuscore))/dl),2.0)+
		pow(z[ii]/((radiuscore+(radiusc-radiuscore))/dl),2.0)) >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2.0) )
		and ( ( pow(x[ii]/((radiuscore+(radiusc-radiuscore))/dl),2.0)+pow(y[ii]/((radiuscore+(radiusc-radiuscore))/dl),2.0)+ 
		pow(z[ii]/((radiuscore+(radiusc-radiuscore))/dl),2.0) ) <= (pow((radiusc)/(radiuscore+(radiusc-radiuscore)),2.0) )))
		{
			index=cnum;
			aa=1;
//			em=1;
		}
	}





	if(aa==0)
	{
		index=0;
	}

	if(aa==1)
	{
		
//		print (index,'index')
	}



	return index;

}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*

								HERE COMES THE SEGMENT OF SPHERE!!!


*/


int incoreshell_segmentsphere(int ii, int cnum,float radiusc,float radiuscore,float radiusshell,int corenumber,int shellnumber,float dl,int h,float x[80000],float y[80000],float z[80000], int& index,int& aa,  int segmentheight, int segmentradius1, int segmentradius2)
{

	z[ii]=z[ii]-(2*radiusc-segmentheight)/dl;

	if ( z[ii] <= (radiusc-segmentheight)/dl ) 
	{
		if ( (pow(x[ii]/((radiuscore+(radiusc-radiuscore))/dl),2.0)+pow(y[ii]/((radiuscore+(radiusc-radiuscore))/dl),2.0)+ 
		pow(z[ii]/((radiuscore+(radiusc-radiuscore))/dl),2.0)) <= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2.0) )
		{
			index=corenumber;
			aa=1;
//			em=1;
		}
// shell
		if ( ( ( pow(x[ii]/((radiuscore+(radiusc-radiuscore))/dl),2.0) + pow(y[ii]/((radiuscore+(radiusc-radiuscore))/dl),2.0)+ 
		pow(z[ii]/((radiuscore+(radiusc-radiuscore))/dl),2.0) ) >= pow(((radiuscore)/(radiuscore+(radiusc-radiuscore))),2.0) )
		and ( ( pow(x[ii]/((radiuscore+(radiusc-radiuscore))/dl),2.0)+pow(y[ii]/((radiuscore+(radiusc-radiuscore))/dl),2.0)+ 
		pow(z[ii]/((radiuscore+(radiusc-radiuscore))/dl),2.0) ) <= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2.0) ))
		{
			index=shellnumber;
			aa=1;
//			em=1;
		}
// carbon shell
		if ( ( ( pow(x[ii]/((radiuscore+(radiusc-radiuscore))/dl),2.0)+pow(y[ii]/((radiuscore+(radiusc-radiuscore))/dl),2.0)+
		pow(z[ii]/((radiuscore+(radiusc-radiuscore))/dl),2.0)) >= pow(((radiusshell)/(radiuscore+(radiusc-radiuscore))),2.0) )
		and ( ( pow(x[ii]/((radiuscore+(radiusc-radiuscore))/dl),2.0)+pow(y[ii]/((radiuscore+(radiusc-radiuscore))/dl),2.0)+ 
		pow(z[ii]/((radiuscore+(radiusc-radiuscore))/dl),2.0) ) <= (pow((radiusc)/(radiuscore+(radiusc-radiuscore)),2.0) )))
		{
			index=cnum;
			aa=1;
//			em=1;
		}
	}





	if(aa==0)
	{
		index=0;
	}

	if(aa==1)
	{
		
//		print (index,'index')
	}



	return index;

}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
 * 
 *								 				HERE COMES THE PILL FORM
 * 
 */

int incoreshell_pill(int ii, int cnum,float radiusc,float radiuscore,float radiusshell,int corenumber,int shellnumber,float dl,int h, float x[80000], float y[80000], float z[80000], int& index,int& aa, int pillheight1, int pillheight2, int pillradius1,  int pillradius2)
{

	float div = float(radiusc/dl);

//	x[ii] = x[ii] - pillheight2/dl;
	x[ii] = x[ii] + pillheight2/2/dl;

	float jax = x[ii];
	float jay = y[ii];
	float jaz = z[ii];
	
	z[ii] = z[ii] + (pillheight2)/dl;


	x[ii] = x[ii] -	 (radiusc)/dl;
	
	if(z[ii] <= 0)
	{
		
//		z[ii] = ja;
		
		if ( (pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+pow(z[ii]/div,2.0)   ) <= (pow((radiuscore)/radiusc,2.0 )) )
			{
//					#			A[a][b]=corenumber
								index=corenumber;
								aa=1;
//		cout << pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+pow(z[ii]/div,2.0) << endl;

			}
// shell

		if ( (  pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+ pow(z[ii]/div,2.0)) >= (pow(radiuscore/radiusc,2.0)  ) and ((pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+ pow(z[ii]/div,2.0) ) <= (pow(radiusshell/radiusc,2.0))))
			{
//						                A[a][b]=shellnumber
								index=shellnumber;
								aa=1;

			}

// carbon shell

		if ( ((  pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+ (pow(z[ii]/div,2.0)) ) >= (pow((radiusshell)/radiusc,2.0))) and ((pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+ pow(z[ii]/div,2.0)) <= ((1.0))))
			{

//		        			        	A[a][b]=cnum
								index=cnum;
//	cout << pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+pow(z[ii]/div,2.0) << endl;

								aa=1;

			}
	}

	x[ii]=jax;

	x[ii] = x[ii] + (radiusc)/dl;
	
	if(z[ii] <= 0)
	{
		
//		z[ii] = ja;
		
		if ( (pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+pow(z[ii]/div,2.0)   ) <= (pow((radiuscore)/radiusc,2.0 )) )
			{
//					#			A[a][b]=corenumber
								index=corenumber;
								aa=1;
//		cout << pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+pow(z[ii]/div,2.0) << endl;

			}
// shell

		if ( (  pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+ pow(z[ii]/div,2.0)) >= (pow(radiuscore/radiusc,2.0)  ) and ((pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+ pow(z[ii]/div,2.0) ) <= (pow(radiusshell/radiusc,2.0))))
			{
//						                A[a][b]=shellnumber
								index=shellnumber;
								aa=1;

			}

// carbon shell

		if ( ((  pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+ (pow(z[ii]/div,2.0)) ) >= (pow((radiusshell)/radiusc,2.0))) and ((pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+ pow(z[ii]/div,2.0)) <= ((1.0))))
			{

//		        			        	A[a][b]=cnum
								index=cnum;
//	cout << pow(x[ii]/div,2.0)+pow(y[ii]/div,2.0)+pow(z[ii]/div,2.0) << endl;

								aa=1;

			}
	}



	x[ii]=jax;
	y[ii]=jay;
	z[ii]=jaz;

///////////////////////////////////////////////////////////////////////////////////////////////

/*
 * 
 *				 				CYLINDRIC PART
 * 
	*/

//	z[ii] = z[ii] - (pillheight2/2.0)/dl;
	x[ii] = x[ii] - (radiusc)/dl;


if( z[ii] <= 0 and z[ii] >= -pillheight2)
	{
//	x[ii] = x[ii] + pillheight2/2/dl;

	float div1=float(radiusc/dl);
	float div2=float(radiusc/dl);
//	float div3=float(radiuszcs/dl);




	float tent01 =	(pow(x[ii]/(div1),2.0)+pow(y[ii]/(div2),2.0));
	
//	float tent02= pow(z[ii]/(div3),2.0);
	// and tent02 <= ((pow(float(radiuscore)/(float(radiusc)),2.0) ))
	
	if ( tent01 <= ((pow(float(radiuscore)/(float(radiusc)),2.0) )))
//					#			A[a][b]=corenumber
	{
								index=corenumber;
								aa=1;

	}
// shell

	float tentum11 = pow(x[ii]/(div1),2.0)+pow(y[ii]/(div2),2.0);
//	float tentum11z = pow(z[ii]/(div3),2.0);
	float tentum12 = (pow(x[ii]/(div1),2.0)+pow(y[ii]/(div2),2.0));
//	float tentum12z = pow(z[ii]/(div3),2.0);

	//	and tentum11z >= (pow(float(radiuscore)/(float(radiusc)),2.0))
	//	and tentum12z <= ((pow(float(radiusshell)/(float(radiusc)),2.0))

	if ( tentum11 >= (pow(float(radiuscore)/(float(radiusc)),2.0))  and tentum12 <= ((pow(float(radiusshell)/(float(radiusc)),2.0))) )							
	{
//						                A[a][b]=shellnumber
								index=shellnumber;
								aa=1;

	}

// carbon shell

	float tentum  =((pow(x[ii]/div1,2.0))+pow(y[ii]/(div2),2.0));
//	float tentumz  =pow(z[ii]/(div3),2.0);


	float tentdois = (pow(x[ii]/(div1),2.0)+pow(y[ii]/(div2),2.0));
//	float tentdoisz = pow(z[ii]/(div3),2.0);

	// and tentumz >= (pow((float(radiusshell))/(float(radiusc)),2.0)) 
	//   and tentdoisz <= (1.0)

	if ( tentum >= (pow((float(radiusshell))/(float(radiusc)),2.0)) and  tentdois <= (1.0))
//		        			        	A[a][b]=cnum
	{

								index=cnum;
								aa=1;
	}



	}


	x[ii]=jax;

	x[ii] = x[ii] + (radiusc)/dl;


if( z[ii] <= 0 and z[ii] >= -pillheight2)
	{
//	x[ii] = x[ii] + pillheight2/2/dl;

	float div1=float(radiusc/dl);
	float div2=float(radiusc/dl);
//	float div3=float(radiuszcs/dl);




	float tent01 =	(pow(x[ii]/(div1),2.0)+pow(y[ii]/(div2),2.0));
	
//	float tent02= pow(z[ii]/(div3),2.0);
	// and tent02 <= ((pow(float(radiuscore)/(float(radiusc)),2.0) ))
	
	if ( tent01 <= ((pow(float(radiuscore)/(float(radiusc)),2.0) )))
//					#			A[a][b]=corenumber
	{
								index=corenumber;
								aa=1;

	}
// shell

	float tentum11 = pow(x[ii]/(div1),2.0)+pow(y[ii]/(div2),2.0);
//	float tentum11z = pow(z[ii]/(div3),2.0);
	float tentum12 = (pow(x[ii]/(div1),2.0)+pow(y[ii]/(div2),2.0));
//	float tentum12z = pow(z[ii]/(div3),2.0);

	//	and tentum11z >= (pow(float(radiuscore)/(float(radiusc)),2.0))
	//	and tentum12z <= ((pow(float(radiusshell)/(float(radiusc)),2.0))

	if ( tentum11 >= (pow(float(radiuscore)/(float(radiusc)),2.0))  and tentum12 <= ((pow(float(radiusshell)/(float(radiusc)),2.0))) )							
	{
//						                A[a][b]=shellnumber
								index=shellnumber;
								aa=1;

	}

// carbon shell

	float tentum  =((pow(x[ii]/div1,2.0))+pow(y[ii]/(div2),2.0));
//	float tentumz  =pow(z[ii]/(div3),2.0);


	float tentdois = (pow(x[ii]/(div1),2.0)+pow(y[ii]/(div2),2.0));
//	float tentdoisz = pow(z[ii]/(div3),2.0);

	// and tentumz >= (pow((float(radiusshell))/(float(radiusc)),2.0)) 
	//   and tentdoisz <= (1.0)

	if ( tentum >= (pow((float(radiusshell))/(float(radiusc)),2.0)) and  tentdois <= (1.0))
//		        			        	A[a][b]=cnum
	{

								index=cnum;
								aa=1;
	}



	}


/* 
 * 
 * 
 *					ANOTHER SEMI-SPHERE, THE BELOW PART 
 * 
 * 
 */

	x[ii]=jax;
	y[ii]=jay;
	z[ii]=jaz;




//////////////////////////////////////////////////////////////////////////////////////////////////////////////




	if(aa==0)
	{
		index=0;
	}

	if(aa==1)
	{
//		print (index,'index')
	}



	return index;

}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////










/////////////////////////////////////////////////////////////////////////////////////////////////////////

//float vector_init(float* x[80000],float* y[80000],float* z[80000],int length)
void vector_init(float* x,float* y,float* z,int length)
{

for(int i=0;i<length;i++)
{

x[i]=0;
y[i]=0;
z[i]=0;

}

//return 0;

}










int zeromatrix(int Dx1,int Dy1, int Dz1, int **A)
{


  for (int i=0; i<=Dx1; i++)
  {
  A[i]= new int[Dy1*Dz1];
  }

  for (int i=0; i<Dx1; i++)
  {
  for (int j=0; j<Dy1; j++)
  {
  for (int k=0; k<Dz1; k++)
  {



// it sums up all the elements of the array

   A[i][j+(k)*Dy1]=0;

// cout <<  A[i][j+(k)*Dy1] <<endl;

//     A[i]=0;
//     cout << A[i]<< endl;

  }
  }
  }


cout <<  A[2][Dy1] << "secraaaaaaaa" << endl;

//cout << A[10] << endl;

//cout<< "to aqui nessa porra" << endl;
	

  return  **A;

}

//float radiusc,radiuscore,radiusshell,dl,radc;



int main()
{

// int Dx1,Dy1,Dz1;



// launcher(dl,radiuscore, radiusshell,radiusc,corenumber, shellnumber,radc,Npix,Npiy,Ntam)

// initializing the launcher function

//launcher(2.0,20.0, 30.0,40.0,1, 2,10.0,5,5,5, "s","n",4, 20.0, 30.0)

// char* const shape=(char*)"sphere";
// char* const pilingshape=(char*)"rect";


//char form = shape();

//char shape= "sphere";
//char pilingshape= "rect";


//launcher_general(2.0,20.0, 30.0,40.0,1,2,10.0,5,5,5,4,10.0);

launcher_general(2.0,20.0,30.0,40.0,1,2,10,1,1,1,4,10.0,10.0, 10.0,10.0,10.0,20.0,20.0,20.0,20.0,30.0,30.0,30.0,20.0,20.0,20.0,45.0,25.0,20.0,20.0,30.0,3,40,40,40,20.0,30.0,10,4,10,5,30,20,50,40,30,60,50,60,30,40,50,50,60,50,60);

//void launcher_general( float dl,float radiuscore, float radiusshell,float radiusc,int corenumber,int shellnumber,float radc,int Npix,int Npiy,int Ntam,int cnum, float cs,float base, float width,float height,float base2,float width2,float radiusx1,float radiusy1,float radiusz1,float radiusx2,float radiusy2,float radiusz2,float radiusxcs,float radiusycs,float radiuszcs,float rcarbonpt,float radiuspt,float rcarbonpd,float radiuspd,float distcentro,int alloynumber,int basex,int basey,int basez, float lenpystruc, float heipystruc)


//launcher_general( float dl,float radiuscore, float radiusshell,float radiusc,int corenumber,int shellnumber,float radc,int Npix,int Npiy,int Ntam,int cnum, float cs)


//launcher_general( dl,radiuscore, radiusshell,radiusc,corenumber,shellnumber,radc,Npix,Npiy,int Ntam,int cnum, float cs)

//launcher_general( char* shape, char* pilingshape , float dl,float radiuscore, float radiusshell,float radiusc,int corenumber,int shellnumber,int radc,int Npix,int Npiy,int Ntam,int cnum, float cs);


//return 0;

}

