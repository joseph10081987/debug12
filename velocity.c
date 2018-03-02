#include<stdio.h>
#include<math.h>
#include"rand1.h"

void velocity(double *vdx, double *vdy, double *vdz, int m, double td, double m0, double kb)

{

	int i;
	double sumvdx, sumvdy, sumvdz;
	sumvdx = 0;
	sumvdy = 0;	
	sumvdz = 0;

	for(i = 0; i<m; i++)
		{
		
			sumvdx = sumvdx + vdx[i];
			sumvdy = sumvdy + vdy[i];
			sumvdz = sumvdz + vdz[i];
		}

	for(i=0; i<m; i++)
	{
		vdx[i]= vdx[i]-(sumvdx/m);
		vdy[i]= vdy[i]-(sumvdy/m);
		vdz[i]= vdz[i]-(sumvdz/m);
	}

	sumvdx = 0;
	sumvdy = 0;
	sumvdz = 0;

	for(i = 0; i<m; i++)
		{
		
			sumvdx = sumvdx + vdx[i];
			sumvdy = sumvdy + vdy[i];
			sumvdz = sumvdz + vdz[i];
		}

double tr;

	tr = rand1(vdx,vdy,vdz,m,m0,kb,td);

for (i = 0; i <m; i++)
 	 {
   		 vdx[i] = vdx[i]*sqrt(td/tr);		
    		 vdy[i] = vdy[i]*sqrt(td/tr);
                 vdz[i] = vdz[i]*sqrt(td/tr);   
  	}
	sumvdx = 0;
	sumvdy = 0;
	sumvdz = 0;
	for(i = 0; i<m; i++)
	{
		
		sumvdx = sumvdx + vdx[i];
		sumvdy = sumvdy + vdy[i];
		sumvdz = sumvdz + vdz[i];
	}

}
