
// Objective: To decide the winner and winning distance margin
#include <stdio.h>
/* Alternate:
int main()
{
 int x,y;
 printf("Enter x: ");
 scanf("%d",&x);
 printf("Enter y: ");
 scanf("%d",&y);
 if ((y+ 90/7)> 20)
    printf("Winner: Hare\nWinning distance: %0.1f",(45/7+ 0.9*y));
 else
    printf("Winner: Tortoise\nWinning distance: %0.1f",(1.4*y -10));

}
*/
int main()
// Taking the input of X and Y
{   float X,Y,distance;
    printf("Enter X:");
    scanf("%f",&X);
    printf("Enter Y:");
    scanf("%f",&Y);

    if ((X+ (18-(1.4*X))/1.4 +Y) <20 )
        {printf("The hare wins.\n");
        distance=(18-0.9*((18/1.4) +Y));
        printf("Winning distance margin:%.1f",distance);}

    else if ((X+ (18-(1.4*X))/1.4 +Y)>20 )
       {
        printf("The tortoise wins.\n");
        distance=(18-1.4*X- 1.4*(20-X-Y));
        printf("Winning distance margin:%.1f",distance);}
    else
        printf("match ties.\n");
    return 0;
}
