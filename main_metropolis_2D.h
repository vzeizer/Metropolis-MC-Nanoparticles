#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>



using namespace std;

void delete_alloc(int ***A, int NN);
//float square_vec_2d(int NN1,float ***squarevec);
void square_vec_2d(int NN2,float *x_coord,float *y_coord,float *z_coord);
//float creating_pos(float ***squarevec,int NN1);
void creating_pos(int NN2,float *x_coord,float *y_coord, float *z_coord, char* np_order, int NN);

float rand_delta(int NN,float *listatheta, char* np_order);
//void angles_vecs(float ***squarevec,int NN2,float x_ang[][50],float y_ang[][50]);
void angles_vecs(int NN2,float x_ang[][500],float y_ang[][500],float *x_coord,float *y_coord,float *z_coord);

void energy_array(int NN2,int NN,float *energy_vec,float x_ang[][500],float y_ang[][500],float *xx,float *yy,float Ms,float Msat,float K1,float K2,float Kmeio,float Kmeio2,float Kshear,float K1fielddepen,float K2fielddepen,float Knucl,float Kuni,float Kuni2,float Krot,float K2rot,float Kdiag,float Kperp,float K2perp,float hphih,float hthetah,float expnucl,float H,float beta,float jota,float m,float vizparj,float vizperpj, char* np_order,float *listatheta);

void init_vecloop(int NN2,int thermalaver,float vecloopx[][2000],float vecloopy[][2000],float hphih,float hthetah);

void rand_vec(float solid_cone,int NN2,int thermalaver,float *xx,float *yy,float new_xx[][2000],float new_yy[][2000],float vecloopx[][2000],float vecloopy[][2000]);

void after_vecs(int NN2,float *xx,float *yy,float *xx_after,float *yy_after,float new_xx[][2000],float new_yy[][2000],int j,int l);

float formula_dipolar(float beta,int i, int j,float *xx,float *yy,float x_ang[][500],float y_ang[][500]);

float formula_exchange(float jota,int i, int j,float *xx,float *yy);

float formula_moriya(float m,int i, int j,float *xx,float *yy);
