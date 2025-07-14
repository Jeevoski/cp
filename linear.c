#include <stdio.h>
void main()
{
 int n,i,j,a[50],key,found=0;
 printf("enter the size");
 scanf("%d",&n);
 printf("enter the elements of the array");
 for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
 printf("enter the element to be searched");
 scanf("%d",&key);
 for(i=0;i<n;i++)
  { if(a[i] == key)
     {
      printf("the element is found");
      found = 1;
      break;
    }
  }
 if(!found)
  {
   printf("element not found");
  }
}
     
