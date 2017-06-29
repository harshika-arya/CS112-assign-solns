// Writing roll nos. in seven segment display

#include <stdio.h>

// Defining the digits from 0 to 9 in seven segment display.
void print (int n)

{
   if (n==0)
        printf("\n*****\n*   *\n*   *\n*   *\n*   *\n*   *\n*****\n\n");
   if(n==1)
        printf("\n   *\n   *\n   *\n   *\n   *\n   *\n   *\n\n");
   if(n==2)
        printf("\n*****\n    *\n    *\n    *\n*****\n     *\n*   \n*****\n\n");
   if(n==3)
        printf("\n*****\n    *\n    *\n*****\n    *\n    *\n*****\n\n");
   if(n==4)
        printf("\n*   *\n*   *\n*   *\n*****\n    *\n    *\n    *\n\n");
    if(n==5)
        printf("\n*****\n*   \n*   \n*****\n    *\n    *\n*****\n\n");
    if(n==6)
        printf("\n*****\n*   \n*   \n*****\n*   *\n*   *\n*****\n\n");
    if(n==7)
        printf("\n*****\n    *\n    *\n*****\n    *\n    *\n    *\n\n");
    if(n==8)
        printf("\n*****\n*   *\n*   *\n*****\n*   *\n*   *\n*****\n\n");
    if(n==9)
        printf("\n*****\n*   *\n*   *\n*****\n    *\n    *\n*****\n\n");

}
int main()
{// Taking the input as Roll no.
    int roll;
    printf(" Enter last two digits of your Roll no.: ");
    scanf("%d", &roll);
// Finding the ones and tens place digits for the above computation.
    print(roll/10);
    print(roll%10);
    return 0;
}
