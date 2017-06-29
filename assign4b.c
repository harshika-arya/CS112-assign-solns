
// Objective: To represent the given numbers in binary and hexaadecimal
// form
#include <stdio.h>
#include<string.h>
#include<math.h>


int main()
{
//to store the two numbers
int num1,num2;

//to store the binary of the two numbers
long long binary1=0,binary2=0;

//input
printf(" Enter two decimal integers:");
scanf("%d,%d",&num1,&num2);

//copy for later use
int numcopy1=num1;
int numcopy2=num2;
int i, count=0,lastcount1=0,lastcount2=0,multiplier=1;

//variable to store hammingweight
int hammingweight1=0,hammingweight2=0;

//for the binary representation
    while(num1>0 || num2>0)
    {
        binary1+= multiplier*(num1%2);
        binary2+=multiplier*(num2%2);
        multiplier*=10;
        count++;
        if(num1%2==1){
            lastcount1=count;
            hammingweight1++;
        }
        if(num2%2==1){
            lastcount2=count;
            hammingweight2++;
        }

        num1/=2;
        num2/=2;
    }

        long long copybinary1=binary1;
        long long copybinary2=binary2;



//from binary to hexadecimal

char hexadecimal1[8]={'0'};
char hexadecimal2[8]={'0'};

// for first number

int index=0;
int tempo,valuetempo;

//to convert from binary to hexadecimal we need to group it in 4 digits and find its value (it will be in the range 0-15) and assign hexadecimal values accordingly
while(!binary1<=0){

	//dividing the number in group of 4 digits of binary sequence
	tempo=binary1%10000;
	binary1/=10000;
	valuetempo=0;
	int factor=1;

	//we need to get the decimal value of the four digit sequence
	int n=4;
	while(n>0){
        int x=tempo%10;
        valuetempo+=factor*x;
		factor*=2;
		tempo/=10;
        n--;
	}

    //finding the hexadecimal character
	if(valuetempo==0){
		hexadecimal1[index]='0';
	}
	else if(valuetempo==1){
		hexadecimal1[index]='1';
	}
	else if(valuetempo==2){
		hexadecimal1[index]='2';
	}
	else if(valuetempo==3){
		hexadecimal1[index]='3';
	}
	else if(valuetempo==4){
		hexadecimal1[index]='4';
	}
	else if(valuetempo==5){
		hexadecimal1[index]='5';
	}
	else if(valuetempo==6){
		hexadecimal1[index]='6';
	}
	else if(valuetempo==7){
		hexadecimal1[index]='7';
	}
	else if(valuetempo==8){
		hexadecimal1[index]='8';
	}
	else if(valuetempo==9){
		hexadecimal1[index]='9';
	}
	else if(valuetempo==10){
		hexadecimal1[index]='A';
	}
	else if(valuetempo==11){
		hexadecimal1[index]='B';
	}
	else if(valuetempo==12){
		hexadecimal1[index]='C';
	}
	else if(valuetempo==13){
		hexadecimal1[index]='D';
	}
	else if(valuetempo==14){
		hexadecimal1[index]='E';
	}
	else if(valuetempo==15){
		hexadecimal1[index]='F';
	}

	index++;
}


//for second number we repeat the same process as in the first number
 index=0;

while(!binary2<=0){
	tempo=binary2%10000;
	binary2/=10000;
	valuetempo=0;
	int factor=1;

    //getting the value of the 4digit sequence
	int n=4;
	while(n>0){
        int x=tempo%10;
        valuetempo+=factor*x;
		factor*=2;
		tempo/=10;
        n--;
	}

    //finding the hexadecimal character
    if(valuetempo==0){
		hexadecimal2[index]='0';
	}
	else if(valuetempo==1){
		hexadecimal2[index]='1';
	}
	else if(valuetempo==2){
		hexadecimal2[index]='2';
	}
	else if(valuetempo==3){
		hexadecimal2[index]='3';
	}
	else if(valuetempo==4){
		hexadecimal2[index]='4';
	}
	else if(valuetempo==5){
		hexadecimal2[index]='5';
	}
	else if(valuetempo==6){
		hexadecimal2[index]='6';
	}
	else if(valuetempo==7){
		hexadecimal2[index]='7';
	}
	else if(valuetempo==8){
		hexadecimal2[index]='8';
	}
	else if(valuetempo==9){
		hexadecimal2[index]='9';
	}
	else if(valuetempo==10){
		hexadecimal2[index]='A';
	}
	else if(valuetempo==11){
		hexadecimal2[index]='B';
	}
	else if(valuetempo==12){
		hexadecimal2[index]='C';
	}
	else if(valuetempo==13){
		hexadecimal2[index]='D';
	}
	else if(valuetempo==14){
		hexadecimal2[index]='E';
	}
	else if(valuetempo==15){
		hexadecimal2[index]='F';
	}

	index++;
}


//printing the output
        printf("The binary representation for %d is %lld\n",numcopy1,copybinary1);
        printf("The binary representation for %d is %lld\n",numcopy2,copybinary2);

        printf("Hamming weight for the first string = %d\n",hammingweight1);
        printf("Hamming weight for the second string = %d\n",hammingweight2);


  // we have to calculate hamming distance only if the length of both binary numbers is same
  //hence we compare the values of lastcount1 and lastcount2
        int hammingdistance=0;
        if(lastcount1==lastcount2){

            while(copybinary1>0){

                if(copybinary1%10 != copybinary2%10){
                    hammingdistance++;
                }
                copybinary1/=10;
                copybinary2/=10;
            }

            printf("Hamming distance between the two strings = %d\n",hammingdistance);

        }




//printing the hexadecimal values

printf("The hexadecimal representation for the first string =");

// the string in reversed order
 i=8;
while(i--){
printf("%c",hexadecimal1[i]);
}
printf("\n");

i=8;
printf("The hexadecimal representation for the second string =");
while(i--){
printf("%c",hexadecimal2[i]);
}


    return 0;
}

