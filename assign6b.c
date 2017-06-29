
#include <stdio.h>
// here unique function is defined for avoiding duplicates which
// may arise in the possible combinations.
int unique(int a[],int b, int I)
{ int i,j,k, x ,num=0;
    float p = 0.1;

    // sorting the array in descending order
    // where a[i] represents the (i+1)th bowler.
    for (i=0; i<b; i++)
    {
        for (j= i +1; j < b; j++)
        {
            if( a[i]< a[j])
            {
                k= a[i];
                a[i]= a[j];
                a[j]=k;
            }
        }
    }
    for(i=b-1; i> (-1);i--)
    {
        p=p*10;
        num= num + a[i]*p;
    }
    if (num== I)
        x= 1;
    else
        x= 0;
    return x;
}
// here function 'pattern' is defined for finding all the possible combinations
// then printing them.
void pattern (int total_overs, int max, int no_bowler)
{
    // forming an array for individual bowlers
    // where a[0] = first bowler and so on

    int a[no_bowler], sum=0, add, i,j,k;
    float p =0.1;
// running loop as many times as we have no.of bowlers
    for(i=0; i< no_bowler; i++)
    {
        p=p*10;
        sum = sum + max*p;
    }
    for (i=sum ; i>=0; i--)
    {
        k=i;
        add=0;

        for(j=0;j<no_bowler; j++)
        {
            a[j]=k %10;
            k= k/10;
            add= add + a[j];
        }
// In the following lines 'unique' function has been called to avoid duplication
        if(add==total_overs && unique(a,no_bowler,i)==1)
        {
            printf("\n");

            for( j=0; j< no_bowler; j++)
            {
                printf("%d", a[j]);
            }
        }

    }
    printf("\n");
}

int main()
{
    int total_overs,max,no_bowler;
// getting the input of total no. of overs, max. no. of overs a player can play and no.of bowlers from user
    printf("\n Total overs:");
    scanf("%d", &total_overs);
    printf("Maximum number of overs for one bowler:");
    scanf("%d", &max);
    printf( "Number of bowlers:");
    scanf("%d",&no_bowler);
    // calling the 'pattern' function to get the final result
    pattern(total_overs,max,no_bowler);

    return 0;
}
