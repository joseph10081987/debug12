#include<stdio.h>
#include<math.h>
void force(double *fx,double *fy,double *fz,double *ax,double *ay,double *az,double D,double r0,int m,int nx,int ny,int nz,double alpha,double a,double reg1,double reg3,int bx[m][m],int count[m])
{
//D=0.325294*(1.6021e-19);//ev
int i,j,px,py,pz;
double r,xr,yr,zr;


for(i=0;i<m;i++)
{
fx[i]=0;
fy[i]=0;
fz[i]=0;

}


for(i=0;i<m;i++)
{
for(j=i+1;j<count[i];j++)
{
//for(dt=1e-12;dt<1e-11;dt++)
//{
/*xr=ax[i]-ax[j];
yr=ay[i]-ay[j];
zr=az[i]-az[j];*/
xr=(ax[i]-ax[bx[i][j]])/(nx*a);
yr=(ay[i]-ay[bx[i][j]])/(ny*a);
zr=(az[i]-az[bx[i][j]])/(nz*a);

//printf("%le %le %le\n",xr,yr,zr);

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
if (fabs(zr)>0.5)    //periodic along 2 directions free along 3rd direction
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
 double a1,a2,a3;
a1=exp(-alpha*(r-r0));
a2=exp(-2*alpha*(r-r0));
a3=(2*D*alpha)/r;
fx[i]=fx[i]+((a3*(xr))*(a2-a1));
fy[i]=fy[i]+((a3*(yr))*(a2-a1));
fz[i]=fz[i]+((a3*(zr))*(a2-a1));
fx[j]=fx[j]-((a3*(xr))*(a2-a1));      //reaction forces
fy[j]=fy[j]-((a3*(yr))*(a2-a1));
fz[j]=fz[j]-((a3*(zr))*(a2-a1));
/*fx[i]=fx[i]+((-2*alpha*D*exp(alpha*r0-alpha*r))*(exp(alpha*r0-alpha*r)-1))*xr/r;
fy[i]=fy[i]+((-2*alpha*D*exp(alpha*r0-alpha*r))*(exp(alpha*r0-alpha*r)-1))*yr/r;
fz[i]=fz[i]+((-2*alpha*D*exp(alpha*r0-alpha*r))*(exp(alpha*r0-alpha*r)-1))*zr/r;
fx[j]=fx[j]-((-2*alpha*D*exp(alpha*r0-alpha*r))*(exp(alpha*r0-alpha*r)-1))*xr/r;
fy[j]=fy[j]-((-2*alpha*D*exp(alpha*r0-alpha*r))*(exp(alpha*r0-alpha*r)-1))*yr/r;
fz[j]=fz[j]-((-2*alpha*D*exp(alpha*r0-alpha*r))*(exp(alpha*r0-alpha*r)-1))*zr/r;*/

//printf("%le %le %le\n",fx[i],fy[i],fz[i]);
//printf("%lf %lf %lf\n",fx[j],fy[j],fz[j]);
    


 }

}

/*for(i=0;i<N;i++)
{
if( az[i]<=reg1 && az[i]>reg3)
{
fx[i]=0;
fy[i]=0;
fz[i]=0;
}
else if(az[i]<=reg3 && az[i]>reg1)
{
fx[i]=0;
fy[i]=fy[i];
fz[i]=0; 
}
}
//printf("%le %le %le\n",fx[i],fy[i],fz[i]);
}
}*/
}
  