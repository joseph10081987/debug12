#include<stdio.h>
#include<math.h>
#include<stdlib.h>


void fcc(double *ax,double *ay,double *az,int nx,int ny,int nz,double a)
{

int i,j,k,l;
l=1;
for(i=0;i<nx;i++)
{
for(j=0;j<ny;j++)
{
for(k=0;k<nz;k++)
{
ax[l-1]=a*i;
ay[l-1]=a*j;
az[l-1]=a*k;
ax[l]=a/2+i*a;
ay[l]=a/2+j*a;
az[l]=a*k;
ax[l+1]=a/2+i*a;
ay[l+1]=a*j;
az[l+1]=a/2+k*a;
ax[l+2]=a*i;
ay[l+2]=a/2+j*a;
az[l+2]=a/2+k*a;

l=l+4;

}
}

}

}
