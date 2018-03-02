#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void Build_neigh_list(int m,double lx,double ly,double lz,double *ax,double *ay,double* az,int bx[m][m],int count[m])

{
int i,j,k,y;
//int count[m];
double cutoff;
cutoff=sqrt(lx*lx+ly*ly+lz*lz);
double dx,dy,dz;
double bal;


for(i=0;i<m;i++){
count[i]=0;  
  for(j=0;j<m;j++){
    
    if(i!=j){
      dx=ax[i]-ax[j];
      dy=ay[i]-ay[j];
       dz=az[i]-az[j];
      bal=sqrt(dx*dx+dy*dy+dz*dz);
      if(bal<=cutoff)

      count[i]++;
      
    }
  }
  }
  for(i=0;i<m;i++){
    //printf("%i\n",count[i]);
  }

struct neigh{
  int* x;
  
};

struct neigh list[m];

for( i=0; i<m; i++){
    list[i].x = (int*)malloc(count[i]*sizeof(int*));
}
// list=(neigh*) malloc(m*sizeof(neigh));
int roy;
for(i=0;i<m;i++){
roy=0;  
  for(j=0;j<m;j++){
    //bx[i][count]=
    if(i!=j){
      dx=ax[i]-ax[j];
      dy=ay[i]-ay[j];
      dz=az[i]-az[j];
      bal=sqrt(dx*dx+dy*dy+dz*dz);
      if(bal<=cutoff){
	list[i].x[roy]=j;
        roy++;
      }
      
    }
  }
  }
  

for(i=0;i<m;i++){
    //printf("neighbor of %i\n",i);
   roy=0;
    for(j=0;j<count[i];j++){
    //printf("%i\n",list[i].x[j]);
     bx[i][roy]=list[i].x[j];
     roy++;
    }
    
  }




  
}
      
  
    
