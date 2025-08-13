#include <stdio.h>
void main()
{
int a[20]={0},b[20]={0},r[30]={0},m,n,i,k;
printf("enter no of degree of 1st poly");
scanf("%d",&n);
printf("enter polynomials of 1st  \n");
for(i=n;i>=0;i--)
{
scanf("%d",&a[i]);
}
printf("enter no of degree of 2nd poly");
scanf("%d",&m);
printf("enter polynomials of 2nd  \n");
for(i=m;i>=0;i--)
{
scanf("%d",&b[i]);
}
if(m>n){
k=m;
for(i=k;i>=0;i--)
r[i]=a[i]+b[i];
}
else
{k=n;
for(i=n;i>=0;i--)
r[i]=a[i]+b[i];
}
printf("sum is \n ");
for(i=k;i>=0;i--){
printf("%dx^%d ",r[i],i);
if (i != 0)
                printf(" + ");
}
}
