#include <stdio.h>
#include <math.h>
/* function to find power using recursion
float power(float x,int n)
{ if (n!=0)
   return (x*power(x,n-1));
  else
   return 1;
 }*/

 /* function  to find power without using recursion
  float power(float x,int n)
  { float result=1;
    while(n!=0)
    { result*=x;
        --n;
    }
    return result;
  }*/
int main()
{float fare,price;
int rem,x;
printf("Enter the base fare: ");
scanf("%f",&fare);
printf("Enter the remaining seats: ");
scanf("%d",&rem);
x=rem/70;
price=fare* pow(1.1,9-x);
if(x<=5)
  price=fare*1.5;
printf("Your ticket price is %0.2f",price);
    return 0;
}
