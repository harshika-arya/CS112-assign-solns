
// Objective: To get the encrypted number
#include <stdio.h>

int main()
{
int num,encrynum,decrynum;
printf("Enter the four digit number to be encrypted: ");
scanf("%d",num);

/* ones=o, tens=t, hundreds=h,thousands=th*/
int o,t,h,th;

/* finding the digits at respective places*/
o=num%10;
num= num/10;
t=num%10;
num= num/10;
h=num%10;
num= num/10;
th=num;

/*required operations*/
 o= (o+7)%10;
 t= (t+7)%10;
 h= (h+7)%10;
 th= (th+7)%10;

/* required swapping*/
int a;
a=o;
o=h;
h=a;

a=t;
t=th;
th=a;

/* printing the encrypted number*/
if (th==0)
    {encrynum= o +t*10 +h*100 +th*0;
    printf("The encrypted number:%d ",encrynum);}
else
   {encrynum= o +t*10+ h*100 +th*1000;
printf(" The encrypted number: %d",encrynum);}

/* reverse checking*/
 printf(" Enter the four digit to be decrypted: ");
 scanf("%d",&decrynum);

 /* finding the digits at respective places*/
o= decrynum%10;
decrynum= decrynum/10;
t= decrynum%10;
decrynum= decrynum/10;
h= decrynum%10;
decrynum= decrynum/10;
th= decrynum;

//required swapping
a=o;
o=h;
h=a;

a=t;
t=th;
th=a;

//original digits
o-=7;
if(o<0)
o+=10;

t-=7;
if(t<0)
t+=10;

h-=7;
if(h<0)
h+=10;

th-=7;
if(th<0)
th+=10;
// final number
num= o +t*10+ h*100 +th*1000;
printf(" The decrypted number:%d",num);
return 0;

}
