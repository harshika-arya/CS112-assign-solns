
// Assignment 6(a)
// Objective: To print all permutations of a string.
# include <stdio.h>

// function 'swap' for swapping.
void swap (char *x, char *y)
{
char temp;
temp = *x;
*x = *y;
*y = temp;
}
// function 'permute' contains three parameters
// first parameter char *a is string pointer
// second and third parameter is left and right index of substring that has to be permuted

void permute(char *a, int i, int n)
{
int j;
// here (i==n) shows that we do not have more letters to permute
// so we'll print the string.
if (i == n){
for(j=0;j<=n;j++){
printf("%c",a[j]);
}
printf("\n");
}
// this means that we still have some string left for permutation
else
{
for (j = i; j <= n; j++)
{
swap((a+i), (a+j));
permute(a, i+1, n);
swap((a+i), (a+j));// backtrack
}
}
}


int main()
{
int i,n;
// getting the input from user.
printf("Number of letters:");
scanf("%d",&n);
char a[n];
printf("Enter the letters:");

char c;
for(i=0;i<n-1;i++){

	scanf(" %c,",&c);
	a[i]=c;
	}
scanf(" %c",&c);
a[n-1]=c;
// calling the permute function to get the final result
permute(a, 0, n-1);
return 0;
}
