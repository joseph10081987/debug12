#include<stdio.h>
#include<stdlib.h>

 
void verlet(double* ax,double* ay,double* az,double* vx,double* vy,double* vz,double* fx,double* fy,double* fz,int m,double m0,double dt,double time,double D,double r0,int nx,int ny,int nz,double alpha,double a,double reg1,double reg3)
{
int i;	
	
	double ax_new, ay_new, az_new;
double* ax_old;
double* ay_old;
double* az_old;        

ax_old=(double*) malloc(m*sizeof(double));
ay_old=(double*) malloc(m*sizeof(double));
az_old=(double*) malloc(m*sizeof(double));

	
	//if (time==0) 
			//{

			 for(i=0;i<m;i++)
				{
					ax_old[i] = ax[i] -  vx[i]*dt + (0.5*(fx[i]/m0)*(dt*dt));
				 	ay_old[i] = ay[i] -  vy[i]*dt + (0.5*(fy[i]/m0)*(dt*dt));
				  	az_old[i] = az[i] -  vz[i]*dt + (0.5*(fz[i]/m0)*(dt*dt));
					//printf("%le %le %le\n",ax_old[i],ay_old[i],az_old[i]);
				}
			//}

	 
	force(fx,fy,fz,ax,ay,az,D,r0,m,nx,ny,nz,alpha,a,reg1,reg3);  //force is updated because position is changed from ax to ax_old
	
		    for(i=0;i<m;i++)
			{

				ax_new = 2.0 * ax[i] - ax_old[i] + ((fx[i]/m0)*(dt*dt));
				ay_new = 2.0 * ay[i] - ay_old[i] + ((fy[i]/m0)*(dt*dt));
				az_new = 2.0 * az[i] - az_old[i] + ((fz[i]/m0)*(dt*dt));
				
				/*vx[i] = (0.5*(ax_new - ax_old[i]))/dt;
				vy[i] = (0.5*(ay_new - ay_old[i]))/dt;
				vz[i] = (0.5*(az_new - az_old[i]))/dt;*/
				
				ax_old[i] = ax[i];
				ay_old[i] = ay[i];
				az_old[i] = az[i];
				
				ax[i] = ax_new;
				ay[i] = ay_new;
				az[i] = az_new;
			//printf("%le %le %le\n",ax[i],ay[i],az[i]);	

 			}
 			for(i=0;i<m;i++)
			{

				
				vx[i] = (0.5*(ax_new - ax_old[i]))/dt;
				vy[i] = (0.5*(ay_new - ay_old[i]))/dt;
				vz[i] = (0.5*(az_new - az_old[i]))/dt;
				
				
			//printf("%le %le %le\n",ax[i],ay[i],az[i]);	

 			}


}
		
