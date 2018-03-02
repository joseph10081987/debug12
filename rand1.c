#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

double rand1(double *vdx,double *vdy,double *vdz,int m,double m0,double kb,double td)
{  
   int i,high=1,low=0; // td in k
	double s;	
double tr;
    //double t; //m in kg, kb in ev/k
   
double vall=0.0;
   
   /* Intializes random number generator */
   srand(time(NULL));

   /* Print 5 random numbers from 0 to 49 */
   for( i = 0 ; i < m ; i++ ) {
      
       vdx[i]=rand() % (high - low + 1) + low;
       vdy[i]=rand() % (high - low + 1) + low;
       vdz[i]=rand() % (high - low + 1) + low;
  //printf("%lf %lf %lf \n", vx[i],vy[i],vz[i]);
     vall=vall+vdx[i]*vdx[i]+vdy[i]*vdy[i]+vdz[i]*vdz[i];
     

   }

 //printf("%lf",vall);
tr=(m0*vall)/(3*kb*m);

 return tr;
}


