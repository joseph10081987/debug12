#include<stdio.h>
#include<stdlib.h>

void leapfrog(double* ax,double* ay,double* az,double* vx,double* vy,double* vz,double* fx,double* fy,double* fz,int m,double m0,double dt,double time,double D,double r0,int nx,int ny,int nz,double alpha,double a,double reg1,double reg3)

{
  int i;
double* ax_old;
double* ay_old;
double* az_old;        

ax_old=(double*) malloc(m*sizeof(double));
ay_old=(double*) malloc(m*sizeof(double));
az_old=(double*) malloc(m*sizeof(double));

double* ax_new;
double* ay_new;
double* az_new;        

ax_new=(double*) malloc(m*sizeof(double));
ay_new=(double*) malloc(m*sizeof(double));
az_new=(double*) malloc(m*sizeof(double));

double* vx_old;
double* vy_old;
double* vz_old;        

vx_old=(double*) malloc(m*sizeof(double));
vy_old=(double*) malloc(m*sizeof(double));
vz_old=(double*) malloc(m*sizeof(double));

double* vx_new;
double* vy_new;
double* vz_new;        

vx_new=(double*) malloc(m*sizeof(double));
vy_new=(double*) malloc(m*sizeof(double));
vz_new=(double*) malloc(m*sizeof(double));

            for(i=0;i<m;i++)
				
                              {
					ax_old[i] = ax[i] -  vx[i]*dt + (0.5*(fx[i]/m0)*(dt*dt));
				 	ay_old[i] = ay[i] -  vy[i]*dt + (0.5*(fy[i]/m0)*(dt*dt));
				  	az_old[i] = az[i] -  vz[i]*dt + (0.5*(fz[i]/m0)*(dt*dt));
					//printf("%le %le %le\n",ax_old[i],ay_old[i],az_old[i]);
				}
				
				
		force(fx,fy,fz,ax,ay,az,D,r0,m,nx,ny,nz,alpha,a,reg1,reg3);
	
		    for(i=0;i<m;i++)
			{
			  
			        vx_old[i] = (0.5*(ax[i] - ax_old[i]))/dt;
				vy_old[i] = (0.5*(ay[i] - ay_old[i]))/dt;
				vz_old[i] = (0.5*(az[i] - az_old[i]))/dt;
				
                        vx_new[i]=vx_old[i]+(fx[i]*dt)/m0;
                        vy_new[i]=vy_old[i]+(fy[i]*dt)/m0;
                        vz_new[i]=vz_old[i]+(fz[i]*dt)/m0;
		               
		               ax_new[i]=ax[i]+vx_new[i]*dt;
			       ay_new[i]=ay[i]+vy_new[i]*dt;
			       az_new[i]=az[i]+vz_new[i]*dt;
			       
			       vx[i]=((vx_new[i]+vx_old[i])/2);
			       vy[i]=((vy_new[i]+vy_old[i])/2);
			       vz[i]=((vz_new[i]+vz_old[i])/2);
			       
			       ax_old[i]=ax[i];
			       ay_old[i]=ay[i];
			       az_old[i]=az[i];
			       
			       ax[i]=ax_new[i];
			       ay[i]=ay_new[i];
			       az[i]=az_new[i];
			
			}
			
}	