//Joseph Roy-58085-1
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include"fcc.h"
#include"rand1.h"
#include"Build_neigh_list.h"
#include"force.h"
#include"vverlet.h"
#include"penergy.h"
//#include"verlet.h"
//#include"leapfrog.h"
#include"velocity.h"

int main()
{
int i,nx,ny,nz,m;
double a,dt,S=10000,pe;
FILE *input= fopen("input.dat","r"); // file containing the input datas
fscanf(input,"%lg %d %d %d %le", &a, &nx, &ny, &nz,&dt);

m=nx*ny*nz*4;

int j;
double kb=1.3806488e-23;
double r0=3.13e-10,D;/*pe*/
double alpha=1.3535e10;
D=5.2118e-20;
double m0= 1.79093e-25;
double td=200;

double *ax,*ay,*az;
ax=(double*) malloc(m*sizeof(double));
ay=(double*) malloc(m*sizeof(double));
az=(double*) malloc(m*sizeof(double));

double *vx,*vy,*vz;
vx=(double*) malloc(m*sizeof(double));
vy=(double*) malloc(m*sizeof(double));
vz=(double*) malloc(m*sizeof(double));

fcc(ax,ay,az,nx,ny,nz,a);
for(i=0;i<m;i++)
{ //printf("%le %le %le\n",ax[i],ay[i],az[i]);
}

double temp=rand1(vx,vy,vz,m,m0,kb,td);
//for(i=0;i<m;i++)
{// printf("%le \n",temp);
}

velocity(vx,vy,vz,m,td,m0,kb);
for(i=0;i<m;i++)
{ //printf("%le %le %le\n",vx[i],vy[i],vz[i]);
}

double lx,ly,lz;
lx=a*nx;
ly=a*ny;
lz=a*nz;

int integration;
integration=1;
double *fx,*fy,*fz;
fx=(double*) malloc(m*sizeof(double));
fy=(double*) malloc(m*sizeof(double));
fz=(double*) malloc(m*sizeof(double));
//---------------      specify the region --------------------------------------------------
	double reg1,reg2,reg3;
	
	int r1,r2;
	r1=1;			// define the number of layer at region 1
	r2=1;			// define the number of layer at region 2
	reg1=a*r1;
	reg2=a*(nz-(r1+r2));
	reg3=lz-a*r2;


int N1,N2;
double time=0;
double *ax_old,*ay_old,*az_old;
//for(time=1e-15;time<S*dt;time=time+dt)
//{
 //force[time]=0;  
//if(integration==1){


FILE *in;
//printf("%le %le %le %le \n",time,ke,pe,totalenergy);
in= fopen("energy.dat","w+"); // file containing the input datas
int bx[m][m];
//int by[m][m];
//int bz[m][m];
int count[m];
Build_neigh_list(m,lx,ly,lz,ax,ay,az,bx,count);
for(i=0;i<m;i++)
{ //printf("%le %le %le\n",ax[i],ay[i],az[i]);
}
while(time<1000*dt){
force(fx,fy,fz,ax,ay,az,D,r0,m,nx,ny,nz,alpha,a,reg1,reg3,bx,count);
for(i=0;i<m;i++)
{ //printf("%le %le %le\n",fx[i],fy[i],fz[i]);
}
vverlet(ax,ay,az,fx,fy,fz,vx,vy,vz,dt,m0,m,r0,D,nx,ny,nz,alpha,a,reg3,N1,reg1,time,bx,count);
for(i=0;i<m;i++)
{ //printf("%le %le %le\n",ax[i],ay[i],az[i]);
}
//verlet(ax,ay,az,vx,vy,vz,fx,fy,fz,m,m0,dt,time,D,r0,nx,ny,nz,alpha,a,reg1,reg3);

//leapfrog(ax,ay,az,vx,vy,vz,fx,fy,fz,m,m0,dt,time,D,r0,nx,ny,nz,alpha,a,reg1,reg3);
	

//printf("%le %le %le\n",ax[i],ay[i],az[i]);
//double v=0;
for(i=0;i<m;i++)
  
{ //v=v+vx[i]*vx[i]+vy[i]*vy[i]+vz[i]*vz[i];
  //
}
//printf("%le\n",v);
double ke,totalenergy,v;
 //double s;
 //s=lx*ly;
  
	pe = 0.0;
 	ke = 0.0; 
	v = 0.0;
		pe = penergy(ax,ay,az,D,r0,m,alpha,nx,ny,nz,a);
                 //printf("%le \n",pe);
	for(i=0;i<m;i++)
	{
	    v=v+vx[i]*vx[i]+vy[i]*vy[i]+vz[i]*vz[i];
	    
	}
	//printf("%le\n",v);
	ke=0.5*m0*v;
       //printf("%le\n",v);
totalenergy=ke+pe;
//printf("%le %le %le %le \n",time,ke,pe,totalenergy);
fprintf(in,"%le %le %le %le \n",time,ke,pe,totalenergy);
time=time+dt;
}
//}
/*verlet(ax,ay,az,vx,vy,vz,fx,fy,fz,m,m0,dt,time);
}
for(i=0;i<m;i++)
{ //printf("%d %le %le %le\n",time,vx[i],vy[i],vz[i]);
}
//}

//else if(integration==2){
//vverlet(ax,ay,az,fx,fy,fz,vx,vy,vz,dt,m0,m,r0,D);
//}


/*if((time%Nfreq)==0) //Frequency for saving the output
			{

		 fprintf(out, "ITEM: TIMESTEP\n");                            // ovito file format
        	 fprintf(out, " %d\n",k);
        	 fprintf(out, "ITEM: NUMBER OF ATOMS\n");
        	 fprintf(out, " %d\n",m);
        	 fprintf(out, "ITEM: BOX BOUNDS\n");
		 fprintf(out,"0 %d \n",nx);
		 fprintf(out,"0 %d \n",ny);
		 fprintf(out,"0 %d \n",nz);		
        	 fprintf(out, "ITEM: ATOMS id x y z\n");
       			
			for(i = 0 ; i <m ; i++)
		    		{
		        fprintf(out,"%d %g %g %g\n",i+1, ax[i], ay[i], az[i]);
	   			}

			}*/
				
//}
 

return 0;

}
