#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>

// connecting C++ with Python

//#include <fstream>

using namespace std;

void delete_alloc(int **A, int Dx1);



int zeromatrix(int Dx1,int Dy1, int Dz1, int **A);

int columnpiling ( int xini, int xfin,int yini,int yfin,int zini,int zfin,int Npix,int Npiy,int Ntam,int Dx1,int Dy1,int Dz1,float radiusc,float radiuscore,float radiusshell,int **A,int corenumber,int shellnumber,int cnum,float dl,float x[80000],float y[80000],float z[80000], float cs);

//int rectangular (char* const shape, char* const pilingshape, int xini, int xfin, int yini, int yfin,int zini, int zfin,float dl,float radiuscore, float radiusshell,float radiusc,int corenumber,int shellnumber,int radc,int Npix,int Npiy,int Ntam,int cnum, float cs, float x[80000], float y[80000],float z[80000],int **A, int Dx1, int Dy1,int Dz1)
int rectangular ( int xini,int xfin,int yini,int yfin,int zini,int zfin,float dl,float radiuscore, float radiusshell,float radiusc,int corenumber,int shellnumber,float radc,int Npix,int Npiy,int Ntam,int cnum, float cs,float x[80000],float y[80000],float z[80000],int **A,int Dx1,int Dy1,int Dz1);
//rectangular (xini,xfin,yini,yfin,zini,zfin,dl,radiuscore,radiusshell,radiusc,corenumber,shellnumber,radc,Npix,Npiy,Ntam,cnum,cs,x,y,z,A,Dx1,Dy1,Dz1);


//rectangular (shape,pilingshape,xini,xfin,yini,yfin,zini,zfin,dl,radiuscore,radiusshell,radiusc,corenumber,shellnumber,radc,Npix,Npiy,Ntam,cnum,cs,x,y,z,A,Dx1,Dy1,Dz1);

int pygeneral (int xini,int xfin,int yini,int yfin,int zini,int zfin, int Npix,int Npiy,int Ntam, int Dx1,int Dy1,int Dz1,float radiusc,float radiuscore, float radiusshell,int **A,int corenumber,int shellnumber,int cnum,float dl,float x[80000],float y[80000],float z[80000],float base, float width,float height,float base2,float width2,float radiusx1,float radiusy1,float radiusz1,float radiusx2,float radiusy2,float radiusz2,float radiusxcs,float radiusycs,float radiuszcs,float cs,float rcarbonpt,float radiuspt,float rcarbonpd,float radiuspd,float distcentro,int alloynumber, int basex,int basey, int basez, float lenpystruc, float heipystruc, char* pilingstruc, int partes, int indorigins, int radiussurface, int surfaceindex, int xlength, int ylength, int zlength, int xlength2, int ylength2, int zlength2, int halfsphereradius1, int halfsphereradius2,int segmentheight,int segmentradius1,int segmentradius2, int pillheight1, int pillheight2, int pillradius1,  int pillradius2);

int hexpyramid (int xini,int xfin,int yini,int yfin,int zini,int zfin, int Npix,int Npiy,int Ntam, int Dx1,int Dy1,int Dz1,float radiusc,float radiuscore, float radiusshell,int **A,int corenumber,int shellnumber,int cnum,float dl,float x[80000],float y[80000],float z[80000],float base, float width,float height,float base2,float width2,float radiusx1,float radiusy1,float radiusz1,float radiusx2,float radiusy2,float radiusz2,float radiusxcs,float radiusycs,float radiuszcs,float cs,float rcarbonpt,float radiuspt,float rcarbonpd,float radiuspd,float distcentro,int alloynumber,int hex_layers);

int hexmono (int xini,int xfin,int yini,int yfin,int zini,int zfin, int Npix,int Npiy,int Ntam, int Dx1,int Dy1,int Dz1,float radiusc,float radiuscore, float radiusshell,int **A,int corenumber,int shellnumber,int cnum,float dl,float x[80000],float y[80000],float z[80000],float base, float width,float height,float base2,float width2,float radiusx1,float radiusy1,float radiusz1,float radiusx2,float radiusy2,float radiusz2,float radiusxcs,float radiusycs,float radiuszcs,float cs,float rcarbonpt,float radiuspt,float rcarbonpd,float radiuspd,float distcentro,int alloynumber,int hex_layers);


int compac(int **A,int Dx1,int Dy1,int Dz1,int zini,int zfin,int yini,int yfin,int xini,int xfin);




// int estruturas( char alloytudo, float cascaptpd, int cs, int dl, int& cnum, float& radiuspt, float& radiuspd, float& radiusc, float& radiuscore, float& radiusshell, int& corenumber, int& shellnumber);



void vector_init(float x[80000],float y[80000],float z[80000],int length);
//void vector_init(float *x,float *y,float *z, int nx, int ny, int nz, int length);

//int launcher(float dl,float radiuscore, float radiusshell,float radiusc,int corenumber,int shellnumber,int radc,int Npix,int Npiy,int Ntam);

int incoreshell_sphere(int ii, int cnum,float radiusc,float radiuscore,float radiusshell,int corenumber,int shellnumber,float dl,int h,float x[80000],float y[80000],float z[80000], int& index,int& aa);

//int incoreshell_sphere(int ii, int cnum,float radiusc,float radiuscore,float radiusshell,int corenumber,int shellnumber,float dl,int h,float x[80000],float y[80000],float z[80000], int& index,int& aa,int& basex,int& basey,int& basez);

// int in_pyramid(int ii, int cnum,float radiusc,float radiuscore,float radiusshell,int corenumber,int shellnumber,float dl,int h,float x[80000],float y[80000],float z[80000], int& index,int& aa,int& basex,int& basey,int& basez);

int in_pyramid(int ii, int cnum,float radiusc,float radiuscore,float radiusshell,int corenumber,int shellnumber,float dl,int h, float x[80000], float y[80000], float z[80000],int& aa,int& index,int& basex,int& basey,int& basez, float lenpystruc, float heipystruc,int i,int j,int k,int xini,int xfin,int yini,int yfin,int zini,int zfin,float radiuscini);

//int sphere_interpen(int ii, int cnum,float radiusc,float radiuscore,float radiusshell,int corenumber,int shellnumber,float dl,int h, float x[80000], float y[80000], float z[80000],int& aa,int& index,int& basex,int& basey,int& basez, float lenpystruc, float heipystruc,int i,int j,int k,int xini,int xfin,int yini,int yfin,int zini,int zfin, float radiuscini, float radiuspt, float radiuspd, float distcentro);

int sphere_interpen(int ii, int cnum,float radiusc,float radiuscore,float radiusshell,int corenumber,int shellnumber,float dl,int h, float x[80000], float y[80000], float z[80000],int& aa,int& index,int& basex,int& basey,int& basez, float lenpystruc, float heipystruc,int i,int j,int k,int xini,int xfin,int yini,int yfin,int zini,int zfin, float radiuscini, float radiuspt, float radiuspd, float distcentro,float rcarbonpt,float rcarbonpd,int alloynumber);


int incoreshell_ellipsoid(int ii, int cnum,float radiusc,float radiuscore,float radiusshell,int corenumber,int shellnumber,float dl,int h, float x[80000], float y[80000], float z[80000],int& aa,int& index,int& basex,int& basey,int& basez, float lenpystruc, float heipystruc,int i,int j,int k,int xini,int xfin,int yini,int yfin,int zini,int zfin, float radiuscini, float radiuspt, float radiuspd, float distcentro,float rcarbonpt,float rcarbonpd,int alloynumber, float radiusxcs, float radiusycs, float radiuszcs, char* pilingstruc);

int incoreshell_cylinder(int ii, int cnum,float radiusc,float radiuscore,float radiusshell,int corenumber,int shellnumber,float dl,int h, float x[80000], float y[80000], float z[80000],int& aa,int& index,int& basex,int& basey,int& basez, float lenpystruc, float heipystruc,int i,int j,int k,int xini,int xfin,int yini,int yfin,int zini,int zfin, float radiuscini, float radiuspt, float radiuspd, float distcentro,float rcarbonpt,float rcarbonpd,int alloynumber, float radiusxcs, float radiusycs, float radiuszcs, char* pilingstruc);


int incoreshell_octahedron(int ii, int cnum,float radiusc,float radiuscore,float radiusshell,int corenumber,int shellnumber,float dl,int h, float x[80000], float y[80000], float z[80000],int& aa,int& index,int& basex,int& basey,int& basez, float lenpystruc, float heipystruc,int i,int j,int k,int xini,int xfin,int yini,int yfin,int zini,int zfin, float radiuscini, float radiuspt, float radiuspd, float distcentro,float rcarbonpt,float rcarbonpd,int alloynumber, float radiusxcs, float radiusycs, float radiuszcs, char* pilingstruc);

int incoreshell_triplate(int ii, int cnum,float radiusc,float radiuscore,float radiusshell,int corenumber,int shellnumber,float dl,int h, float x[80000], float y[80000], float z[80000],int& aa,int& index,int& basex,int& basey,int& basez, float lenpystruc, float heipystruc,int i,int j,int k,int xini,int xfin,int yini,int yfin,int zini,int zfin, float radiuscini, float radiuspt, float radiuspd, float distcentro,float rcarbonpt,float rcarbonpd,int alloynumber, float radiusxcs, float radiusycs, float radiuszcs, char* pilingstruc,float base,float width,float height,float base2,float width2,float cs);

int incoreshell_cubic(int ii, int cnum,float radiusc,float radiuscore,float radiusshell,int corenumber,int shellnumber,float dl,int h, float x[80000], float y[80000], float z[80000],int& aa,int& index,int& basex,int& basey,int& basez, float lenpystruc, float heipystruc,int i,int j,int k,int xini,int xfin,int yini,int yfin,int zini,int zfin, float radiuscini, float radiuspt, float radiuspd, float distcentro,float rcarbonpt,float rcarbonpd,int alloynumber, float radiusxcs, float radiusycs, float radiuszcs, char* pilingstruc,float base,float width,float height,float base2,float width2,float cs);

int incoreshell_manyshell(int ii, int cnum,float radiusc,float radiuscore,float radiusshell,int corenumber,int shellnumber,float dl,int h, float x[80000], float y[80000], float z[80000],int& aa,int& index,int& basex,int& basey,int& basez, float lenpystruc, float heipystruc,int i,int j,int k,int xini,int xfin,int yini,int yfin,int zini,int zfin, float radiuscini, float radiuspt, float radiuspd, float distcentro,float rcarbonpt,float rcarbonpd,int alloynumber, float radiusxcs, float radiusycs, float radiuszcs, char* pilingstruc,float base,float width,float height,float base2,float width2,float cs, int partes, int indorigins);

int incoreshell_spheresurface(int ii, int cnum,float radiusc,float radiuscore,float radiusshell,int corenumber,int shellnumber,float dl,int h,float x[80000],float y[80000],float z[80000], int& index,int& aa, int radiussurface, int surfaceindex);

int incoreshell_spheresurfacetwo(int ii, int cnum,float radiusc,float radiuscore,float radiusshell,int corenumber,int shellnumber,float dl,int h,float x[80000],float y[80000],float z[80000], int& index,int& aa, int radiussurface, int surfaceindex);

int incoreshell_pavingstone(int ii, int cnum,float radiusc,float radiuscore,float radiusshell,int corenumber,int shellnumber,float dl,int h, float x[80000], float y[80000], float z[80000],int& aa,int& index,int& basex,int& basey,int& basez, float lenpystruc, float heipystruc,int i,int j,int k,int xini,int xfin,int yini,int yfin,int zini,int zfin, float radiuscini, float radiuspt, float radiuspd, float distcentro,float rcarbonpt,float rcarbonpd,int alloynumber, float radiusxcs, float radiusycs, float radiuszcs, char* pilingstruc,float base,float width,float height,float base2,float width2,float cs, int xlength, int ylength, int zlength, int xlength2, int ylength2, int zlength2);

int incoreshell_halfsphere(int ii, int cnum,float radiusc,float radiuscore,float radiusshell,int corenumber,int shellnumber,float dl,int h,float x[80000],float y[80000],float z[80000], int& index,int& aa, int halfsphereradius1, int halfsphereradius2);

int incoreshell_segmentsphere(int ii, int cnum,float radiusc,float radiuscore,float radiusshell,int corenumber,int shellnumber,float dl,int h,float x[80000],float y[80000],float z[80000], int& index,int& aa, int segmentheight, int segmentradius1, int segmentradius2);

int incoreshell_pill(int ii, int cnum,float radiusc,float radiuscore,float radiusshell,int corenumber,int shellnumber,float dl,int h,float x[80000],float y[80000],float z[80000], int& index,int& aa, int pillheight1, int pillheight2, int pillradius1,  int pillradius2);





int jonderstruct1 (int xini,int xfin,int yini,int yfin,int zini,int zfin, int Npix,int Npiy,int Ntam, int Dx1,int Dy1,int Dz1,float radiusc,float radiuscore, float radiusshell,int **A,int corenumber,int shellnumber,int cnum,float dl,float x[80000],float y[80000],float z[80000],float base, float width,float height,float base2,float width2,float radiusx1,float radiusy1,float radiusz1,float radiusx2,float radiusy2,float radiusz2,float radiusxcs,float radiusycs,float radiuszcs,float cs);


int jonderstruct2 (int xini,int xfin,int yini,int yfin,int zini,int zfin, int Npix,int Npiy,int Ntam, int Dx1,int Dy1,int Dz1,float radiusc,float radiuscore, float radiusshell,int **A,int corenumber,int shellnumber,int cnum,float dl,float x[80000],float y[80000],float z[80000],float base, float width,float height,float base2,float width2,float radiusx1,float radiusy1,float radiusz1,float radiusx2,float radiusy2,float radiusz2,float radiusxcs,float radiusycs,float radiuszcs,float cs);


int hex1 (int xini,int xfin,int yini,int yfin,int zini,int zfin, int Npix,int Npiy,int Ntam, int Dx1,int Dy1,int Dz1,float radiusc,float radiuscore, float radiusshell,int **A,int corenumber,int shellnumber,int cnum,float dl,float x[80000],float y[80000],float z[80000],float base, float width,float height,float base2,float width2,float radiusx1,float radiusy1,float radiusz1,float radiusx2,float radiusy2,float radiusz2,float radiusxcs,float radiusycs,float radiuszcs,float cs,float rcarbonpt,float radiuspt,float rcarbonpd,float radiuspd,float distcentro,int alloynumber,int hex_layers);

int hex2 (int xini,int xfin,int yini,int yfin,int zini,int zfin, int Npix,int Npiy,int Ntam, int Dx1,int Dy1,int Dz1,float radiusc,float radiuscore, float radiusshell,int **A,int corenumber,int shellnumber,int cnum,float dl,float x[80000],float y[80000],float z[80000],float base, float width,float height,float base2,float width2,float radiusx1,float radiusy1,float radiusz1,float radiusx2,float radiusy2,float radiusz2,float radiusxcs,float radiusycs,float radiuszcs,float cs,float rcarbonpt,float radiuspt,float rcarbonpd,float radiuspd,float distcentro,int alloynumber,int hex_layers);

int hex3 (int xini,int xfin,int yini,int yfin,int zini,int zfin, int Npix,int Npiy,int Ntam, int Dx1,int Dy1,int Dz1,float radiusc,float radiuscore, float radiusshell,int **A,int corenumber,int shellnumber,int cnum,float dl,float x[80000],float y[80000],float z[80000],float base, float width,float height,float base2,float width2,float radiusx1,float radiusy1,float radiusz1,float radiusx2,float radiusy2,float radiusz2,float radiusxcs,float radiusycs,float radiuszcs,float cs,float rcarbonpt,float radiuspt,float rcarbonpd,float radiuspd,float distcentro,int alloynumber,int hex_layers);

int hex4 (int xini,int xfin,int yini,int yfin,int zini,int zfin, int Npix,int Npiy,int Ntam, int Dx1,int Dy1,int Dz1,float radiusc,float radiuscore, float radiusshell,int **A,int corenumber,int shellnumber,int cnum,float dl,float x[80000],float y[80000],float z[80000],float base, float width,float height,float base2,float width2,float radiusx1,float radiusy1,float radiusz1,float radiusx2,float radiusy2,float radiusz2,float radiusxcs,float radiusycs,float radiuszcs,float cs,float rcarbonpt,float radiuspt,float rcarbonpd,float radiuspd,float distcentro,int alloynumber,int hex_layers);


int hex5 (int xini,int xfin,int yini,int yfin,int zini,int zfin, int Npix,int Npiy,int Ntam, int Dx1,int Dy1,int Dz1,float radiusc,float radiuscore, float radiusshell,int **A,int corenumber,int shellnumber,int cnum,float dl,float x[80000],float y[80000],float z[80000],float base, float width,float height,float base2,float width2,float radiusx1,float radiusy1,float radiusz1,float radiusx2,float radiusy2,float radiusz2,float radiusxcs,float radiusycs,float radiuszcs,float cs,float rcarbonpt,float radiuspt,float rcarbonpd,float radiuspd,float distcentro,int alloynumber,int hex_layers);

int hex6 (int xini,int xfin,int yini,int yfin,int zini,int zfin, int Npix,int Npiy,int Ntam, int Dx1,int Dy1,int Dz1,float radiusc,float radiuscore, float radiusshell,int **A,int corenumber,int shellnumber,int cnum,float dl,float x[80000],float y[80000],float z[80000],float base, float width,float height,float base2,float width2,float radiusx1,float radiusy1,float radiusz1,float radiusx2,float radiusy2,float radiusz2,float radiusxcs,float radiusycs,float radiuszcs,float cs,float rcarbonpt,float radiuspt,float rcarbonpd,float radiuspd,float distcentro,int alloynumber,int hex_layers);

int hex7 (int xini,int xfin,int yini,int yfin,int zini,int zfin, int Npix,int Npiy,int Ntam, int Dx1,int Dy1,int Dz1,float radiusc,float radiuscore, float radiusshell,int **A,int corenumber,int shellnumber,int cnum,float dl,float x[80000],float y[80000],float z[80000],float base, float width,float height,float base2,float width2,float radiusx1,float radiusy1,float radiusz1,float radiusx2,float radiusy2,float radiusz2,float radiusxcs,float radiusycs,float radiuszcs,float cs,float rcarbonpt,float radiuspt,float rcarbonpd,float radiuspd,float distcentro,int alloynumber,int hex_layers);

int hex8 (int xini,int xfin,int yini,int yfin,int zini,int zfin, int Npix,int Npiy,int Ntam, int Dx1,int Dy1,int Dz1,float radiusc,float radiuscore, float radiusshell,int **A,int corenumber,int shellnumber,int cnum,float dl,float x[80000],float y[80000],float z[80000],float base, float width,float height,float base2,float width2,float radiusx1,float radiusy1,float radiusz1,float radiusx2,float radiusy2,float radiusz2,float radiusxcs,float radiusycs,float radiuszcs,float cs,float rcarbonpt,float radiuspt,float rcarbonpd,float radiuspd,float distcentro,int alloynumber,int hex_layers);

int hex9 (int xini,int xfin,int yini,int yfin,int zini,int zfin, int Npix,int Npiy,int Ntam, int Dx1,int Dy1,int Dz1,float radiusc,float radiuscore, float radiusshell,int **A,int corenumber,int shellnumber,int cnum,float dl,float x[80000],float y[80000],float z[80000],float base, float width,float height,float base2,float width2,float radiusx1,float radiusy1,float radiusz1,float radiusx2,float radiusy2,float radiusz2,float radiusxcs,float radiusycs,float radiuszcs,float cs,float rcarbonpt,float radiuspt,float rcarbonpd,float radiuspd,float distcentro,int alloynumber,int hex_layers);



//int jonderstruct2 (xini,xfin,yini,yfin,zini,zfin,Npix,Npiy,Ntam,Dx1,Dy1,Dz1,radiusc,radiuscore,radiusshell,A,corenumber,shellnumber,cnum,dl,x,y,z,shape,base,width,height,base2,width2,radiusx1,radiusy1,radiusz1,radiusx2,radiusy2,radiusz2,radiusxcs,radiusycs,radiuszcs,cs):




//external functions

extern "C"{

//	void launcher(char shape, float dl,float radiuscore, float radiusshell,float radiusc,int corenumber,int shellnumber,int radc,int Npix,int Npiy,int Ntam, int cnum, float cs);
//	void launcher_general(float dl,float radiuscore, float radiusshell,float radiusc,int corenumber,int shellnumber,float radc,int Npix,int Npiy,int Ntam, int cnum, float cs);
	void launcher_general( float dl,float radiuscore, float radiusshell,float radiusc,int corenumber,int shellnumber,float radc,int Npix,int Npiy,int Ntam,int cnum, float cs,float base, float width,float height,float base2,float width2,float radiusx1,float radiusy1,float radiusz1,float radiusx2,float radiusy2,float radiusz2,float radiusxcs,float radiusycs,float radiuszcs,float rcarbonpt,float radiuspt,float rcarbonpd,float radiuspd,float distcentro,int alloynumber,int basex, int basey, int basez, float lenpystruc, float heipystruc, int partes, int indorigins, int radiussurface, int surfaceindex, int xlength, int ylength, int zlength, int xlength2, int ylength2, int zlength2, int halfsphereradius1, int halfsphereradius2, int segmentheight,int segmentradius1,int segmentradius2, int pillheight1, int pillheight2, int pillradius1,  int pillradius2);


}







