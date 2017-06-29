
#include<stdio.h>
/* Alternate: Using function to find nth term of fibonacci sequence
  int fibo(int n)
{  if(n==0 || n==1) return 1;
   else
    return (fibo(n-1) +fibo(n-2));
}*/
int main(void){

    int n;
	printf("Enter the month after which the area is to be closed: ");
	scanf("%d",&n);

// the sequence is the fibonacci sequence that satisfies t(m)=t(m-1)+t(m-2)
//saving the first and second term of the sequence and calculating the remaining term by using for loop

    long long firstnumber=1,secondnumber=2;
    long long answer=0;
      long long temp;

      //for n=1 or 2 answer is 1 and 2 respectively
      if(n<3){
            answer=n;
      }

// if n>=3 then answer is the sum of the answers of previous two
      if(n>=3){

      for (int i = 3; i <=n ; i++)
          {
        answer=firstnumber+secondnumber;
        temp=firstnumber;
        firstnumber=secondnumber;
        secondnumber=temp+secondnumber;
          }


      }

//printing final answer
    printf("There are %lld choices of plan.",answer);
    return 0;
}
