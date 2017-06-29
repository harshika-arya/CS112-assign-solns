


#include <stdio.h>

int main()
{
    int no_of_participants,i=0,height[100];
    // getting the input of no. of participated from user
    printf("Enter the number of students participated: ");
    scanf("%d",&no_of_participants);

    printf("Enter their heights: ");
// getting the input of height
    int count=0,max=0;
for(i=0;i<no_of_participants;i++)
 {
     scanf("%d",&height[i]);
// here max stores the maximum height of participants and 'count' will tell us about how many times this loop will work
// which in turn gives us the value of no. of students who can see the stage.
    if (height[i]>=max)
      {max= height[i];
       count++;

      }
 }
 // printing the result
    printf("No. of students can see the stage: %d\n",count);


    printf("Enter the color of robes denoted by integers: ");

  // let us assume that firstly 'girlsparty' has been assigned the value as 1.
  // but if the given color code(i) matches with any of the previous ones(j)
  // girlsparty becomes 0 i.e. (girlsparty=0)

  int girlsparty=1,color[10],j;
  for(i=0;i<no_of_participants;i++)
  {
      scanf("%d",&color[i]);
      for(j=i-1;j>=0;j--)
      {
          if(color[j]==color[i])
            girlsparty=0;

      }
  }
  // finally if the 'girlsparty' remains 1, it is a GIRLS party .
  // but if changes to 0, it is a BOYS party.
    if(girlsparty==1)

        printf("It is a GIRLS party. ");

else

  printf("It is a BOYS party. ");




    return 0;
}
