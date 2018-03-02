#ifndef VVERLET_H_INCLUDED
#define VVERLET_H_INCLUDED
void vverlet(double *ax,double *ay,double *az,double *fx,double *fy,double *fz,double *vdx,double *vdy,double *vdz,double dt,double mass,int m,double r0,double D,double nx,double ny,double nz,double alpha,double a,double reg3,int N1,double reg1,double time,int bx[m][m],int count[m]);
	#endif
