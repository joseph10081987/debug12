#include<stdio.h>
#include<math.h>
double penergy(double *ax,double *ay,double *az,double D,double r0,int m,double alpha,int nx,int ny,int nz,double a)
{
int i,j,px,py,pz;
double r,xr,yr,zr;

 double pej;
 pej=0.0;




for(i=0;i<m-1;i++)
{
for(j=i+1;j<m;j++)
{
//for(dt=1e-12;dt<1e-11;dt++)
//{
xr=ax[i]-ax[j];
yr=ay[i]-ay[j];
zr=az[i]-az[j];
xr=(ax[i]-ax[j])/(nx*a);
yr=(ay[i]-ay[j])/(ny*a);
zr=(az[i]-az[j])/(nz*a);

//Periodic boundary conditions
if (fabs(xr)>0.5)
{
      if(xr>0)
{   px=1;
}
else if(xr<0)
{
px=-1;
}
xr=xr-px;
}
if (fabs(yr)>0.5)
{
    if(yr>0)
{
py=1;
}
else if(yr<0)
{
py=-1;
}
yr=yr-py;
}
if (fabs(zr)>0.5)
{
   if(zr>0)
{
  pz=1;
}
else if(zr<0)
{
  pz=-1;
}
zr=zr-pz;

}
xr=xr*nx*a;
yr=yr*ny*a;
zr=zr*nz*a;

 r=sqrt(xr*xr+yr*yr+zr*zr);
    pej=pej+D*(exp(-2*alpha*r+2*alpha*r0)-2*exp(-alpha*r+alpha*r0));

//printf("%le \n",pej);
}
} 
return pej;



}
