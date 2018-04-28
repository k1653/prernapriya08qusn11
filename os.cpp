#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void input(int All[][10],int Need[][10],int Max[10][10],int n,int r)
{
        for(int i=0;i<n;i++){
		printf("\n Process %d\n",i);
		for(int j=0;j<r;j++){
			printf(" Allocation for resource %d : ",j+1);
			scanf("%d",&All[i][j]);
			}
	   }
        for(int i=0;i<n;i++){
		printf("\n Process %d\n",i);
		for(int j=0;j<r;j++){
			printf(" Maximum for resource %d : ",j+1);
			scanf("%d",&Max[i][j]);
		}
	}
		for(int i=0;i<n;i++)
		for(int j=0;j<r;j++)
			Need[i][j]=Max[i][j]-All[i][j];
	printf("\n ");
	printf("Allocation Matrix");
	for(int i=0;i<n;i++)
	{
		printf("\n");
		for(int j=0;j<r;j++)
		{
			printf("%d\t",All[i][j]);
		}
	}	
	printf("\n ");
	printf("Maximum Requirement Matrix");
	for(int i=0;i<n;i++)
	{
		printf("\n");
		for(int j=0;j<r;j++)
		{
			printf("%d\t",Max[i][j]);
		}
	}	
	printf("\n ");
	printf("Need Matrix");
	for(int i=0;i<n;i++)
	{
		printf("\n");
		for(int j=0;j<r;j++)
		{
			printf("%d\t",Need[i][j]);
		}
	}	
}

int checks(int Need[10][10],int Avail[1][10],int m,int r)
{
for(int i=m;i<m+1;i++){
  for(int j=0;j<r;j++)
      {
       
       if(Need[i][j]>Avail[0][j])
            {return 0;}
    }}
return 1;
}

int checks1(int Need[10][10],int Avail1[1][10],int m,int r)
{
for(int i=m;i<m+1;i++){
  for(int j=0;j<r;j++)
      {
       
       if(Need[i][j]>Avail1[0][j])
            {return 0;}
}}
return 1;
}
int checks2(int req[1][10],int Need[10][10],int p,int r)
{
  for(int j=0;j<r;j++)
      {
       
       if(req[0][j]>Need[p][j])
            {return 0;}
         
}
return 1;
}

void request(int All[10][10],int Need[10][10],int Avail1[10][10],int n,int r)
{
printf("Enter process no");
int p;
int req[1][10];
scanf("%d",&p);
printf("Enter resources:");
for(int j=0;j<r;j++)
{
  scanf("%d",&req[0][j]);}
  if(checks2(req,Need,p,r)==1)
{
for(int j=0;j<r;j++)
{
Avail1[0][j]=Avail1[0][j]-req[0][j];
}
for(int j=0;j<r;j++)
{
All[p][j]=Avail1[0][j]+req[0][j];
}
for(int j=0;j<r;j++)
{
Need[p][j]=Need[p][j]-req[0][j];
}

int done1[n];
int s=0;
while(s<n)
{
int allocated1=0;
for(int i=0;i<n;i++)
if(done1[i]==0 && checks1(Need,Avail1,i,r)==1){
    for(int j=0;j<r;j++)
       Avail1[0][j]=Avail1[0][j]+All[i][j];
 printf("\n Allocated process %d ",i);
       
       done1[i]=1;
       allocated1=1;
       s++;
   }
if(allocated1==0)break;
}

if(s==n)
{
printf("\n safe");
}
else{
printf("\n unsafe");
exit(0);}
}
}
int safe(int All[10][10],int Need[10][10],int Max[10][10],int Avail[1][10],int n,int r)
{
int done[n];
int c=0;
while(c<n)
{
int allocated=0;
for(int i=0;i<n;i++)
if(done[i]==0 && checks(Need,Avail,i,r)==1){
    for(int j=0;j<r;j++)
       Avail[0][j]=Avail[0][j]+All[i][j];
 printf("\n Allocated process %d ",i);
       
       done[i]=1;
       allocated=1;
       c++;
   }
if(allocated==0)break;
}
if(c==n)
{
	printf("\n safe");
}

else{
printf("\n unsafe");
return 0;}
}
int main()
{  int All[10][10];
	int Max[10][10];
	int Need[10][10];
	int Avail[1][10];
	int Avail1[1][10];
	int n,r,ret,ch;
	printf("                          BANKERS ALGORITHM\n");
    printf("\nEnter total no. of processes : ");
	scanf("%d",&n);
	printf("\nEnter total no. of resources : ");
	scanf("%d",&r);
	input(All,Need,Max,n,r);
	printf("\n Available resources : \n");
	for(int i=0;i<r;i++){
		printf(" Resource %d : ",i+1);
		scanf("%d",&Avail[0][i]);
		Avail1[0][i]=Avail[0][i];}
	ret=safe(All,Need,Max,Avail,n,r);
	if(ret!=0)	
	{
		 printf("\n Do you want make an additional request ? (1=Yes|0=No)");
		scanf("%d",&ch);
		if(ch == 1){
			
			request(All,Need,Avail1,n,r);
			if(ret == 0 )
				exit(0);
		}
	}else
		exit(0);
	}
