
//the aim is to find out all the perfect squares in a given range
//the compiler needed to compile this program should be -std=c99

#include<stdio.h>
#include<string.h>
#include<math.h>

int main(void){

	int min,max;
	printf("Enter the range of numbers:");
	scanf("%d-%d",&min,&max);

	int counter=0;
	int temp;

//the loop will be executed as long as we get atleast one perfect square

//we will iterate through the range and check for each number whether it is a perfect square or not
		for(int x=min;x<=max;x++){
//if the square of the integral value of the number is equal to that number then it is a perfect square
			temp=sqrt(x);
			if(temp*temp==x){
				counter++;

				if(counter==1){
					printf("\nThe perfect squares in the given range are: %d",x);
				}
				else if(counter>1){
					printf(" ,%d",x);
				}
			}
		}
//once we get any perfect square we need to break out of the loop
		if(counter !=0){

		}
// if their were no perfect squares then loop again
		else if(counter==0){
			printf("\nNo perfect square exists. Please enter another range:");
			scanf("%d-%d",&min,&max);
		}
return 0;
}
