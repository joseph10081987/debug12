#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include"force.h"

void vverlet(double *ax,double *ay,double *az,double *fx,double *fy,double *fz,double *vdx,double *vdy,double *vdz,double dt,double mass,int m,double r0,double D,double nx,double ny,double nz,double alpha,double a,double reg3,int N1,double reg1,double time,int bx[m][m],int count[m])
{
int i;

double *fx_new;
double *fy_new;
double *fz_new;
fx_new=(double*) malloc(m*sizeof(double));
fy_new=(double*) malloc(m*sizeof(double));
fz_new=(double*) malloc(m*sizeof(double));





for(i=0;i<m;i++)
{
                                ax[i] = ax[i] + (vdx[i]*dt) + ((0.5*fx[i])/mass)*dt*dt;
				ay[i] = ay[i] + (vdy[i]*dt) + ((0.5*fy[i])/mass)*dt*dt;
				az[i] = az[i] + (vdz[i]*dt) + ((0.5*fz[i])/mass)*dt*dt;
				//printf("%le %le %le\n",fx[i],fy[i],fz[i]);
}

   force(fx_new,fy_new,fz_new,ax,ay,az,D,r0,m,nx,ny,nz,alpha,a,reg1,reg3,bx,count);

for(i=0;i<m;i++)
{
//  for(dt=1e-12;dt<1e-11;dt++)
  //{
  vdx[i]=vdx[i]+dt*0.5*((fx[i]/mass)+(fx_new[i]/mass));
  vdy[i]=vdy[i]+dt*0.5*((fy[i]/mass)+(fy_new[i]/mass));
  vdz[i]=vdz[i]+dt*0.5*((fz[i]/mass)+(fz_new[i]/mass)); 
  
//printf("%lf %lf %lf\n",vdx[i],vdy[i],vdz[i]); 
 //}

}

/*for(i=0;i<m;i++)
{
 if(time>N1)
 {
   if(az[i]>=reg3)
   {
     vdx[i]=0;
     vdy[i]=0.05;
     vdz[i]=0;
   }
 }
 else
 {
   vdx[i]=0;
   vdy[i]=0;
   vdz[i]=0;
   
 }
}*/
}