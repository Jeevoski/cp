#include <stdio.h>
void main()
{
 int n,i,key,a[50],mid,low,high,found=0;
 printf("enter the size of the array");
 scanf("%d",&n);
 printf("enter the elements");
 for(i=0;i<n;i++)
  {
   scanf("%d",&a[i]);
  }
 printf("enter the key to be searched");
 scanf("%d",&key);
 low=0;
 high=n-1;
 for(;low<=high;)
  {
   mid=(low+high)/2;
   if(a[mid]==key)
     {
     printf("the element is found");
     found=1;
     break;
    }
   else if (a[mid]<key)
    {
     low=mid+1;
    }
   else
    {
     high=mid-1;
    }
  }
  if(!found)
   {
    printf("the elemenet is noat faound");
   }
}
