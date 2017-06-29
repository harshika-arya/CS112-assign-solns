

#include<stdio.h>
#include<math.h>

int main(void){
// 'uniqueid' denotes the unique ids given to the guests.

    int uniqueid[15];
    int i,j;

    int no_people=0;

    int no_males=0,no_females=0;
    int male_id[15]={0};
    int female_id[15]={0};

    int red_people=0,blue_people=0;


   // to terminate the input enter 0 otherwise it will take 15 inputs
   // getting the input of unique ids from the user
    printf("Enter the unique ids of the guests: ");
    for ( i = 0; i < 15; i++)
    {
        scanf("%d,",&uniqueid[i]);
        no_people++;
  // The assumption given in question restricts us to take 0 as guest id

        if (uniqueid[i]==0)
        {
            no_people--;
            break;
        }
// According to given question positive ids represents female while negative represents males
        if (uniqueid[i]>0)
        {
            female_id[no_females]=uniqueid[i];
            no_females++;
        }

        if (uniqueid[i]<0)
        {
            male_id[no_males]=uniqueid[i];
            no_males++;
        }

    }

	// to count the number of red people and blue people
	// even no. ids denotes people dressed in red while odd ids denotes people dressed in blue.
	for(i=0;i<no_people;i++){
		if(uniqueid[i]%2==0){
			red_people++;
		}

		else{
			blue_people++;
		}
	}
// If a new guest arrives checking if there is any seat to accommodate the guest
    int search_id;
    printf("\n");
    printf("Enter the id to be searched:");
    scanf("%d",&search_id);

    //temporary variable for sorting
    int a;
    //sorting the id array for printing
    for (i = 0; i < no_people; ++i)
    {
        for (j = i + 1; j < no_people; ++j)
        {
                if (uniqueid[i] < uniqueid[j])
                {
                    a =  uniqueid[i];
                    uniqueid[i] = uniqueid[j];
                    uniqueid[j] = a;
                }

        }
    }

    //for printing the sitting arrangement
    printf("The seating arrangement is:\n");

    for ( i = 0; i < no_people; i++)
    {
        printf("%d,",uniqueid[i]);


        if ((i+1)%5==0)
        {
            printf("\n");
        }
    }

    //to print the position of id to be searched


    for ( i = 0; i < no_people; i++)
    {
        if (uniqueid[i]==search_id)
        {
            printf("The guest with id %d is present and is seated at position %d.\n",search_id,i+1);
        }
    }

    //to print the number of males and females
    printf("There are %d males and %d females\n",no_males,no_females);


    //to print the male id we will first sort it and then print
     for (i = 0; i < no_males; ++i)
    {
        for (j = i + 1; j < no_males; ++j)
        {
                if (male_id[i] < male_id[j])
                {
                    a =  male_id[i];
                    male_id[i] = male_id[j];
                    male_id[j] = a;
                }

        }
    }
    printf("The male guest ids are:");
    //printing the male array
    for(i=0;i<no_males;i++){
	    printf("%d ",male_id[i]);
    }

    printf("\n");
    printf("The female guest ids are:");

    //to print the female id we will first sort it and then print
     for (i = 0; i < no_females; ++i)
    {
        for (j = i + 1; j < no_females; ++j)
        {
                if (female_id[i] < female_id[j])
                {
                    a =  female_id[i];
                    female_id[i] = female_id[j];
                    female_id[j] = a;
                }

        }
    }

    //printing the male array
    for(i=0;i<no_females;i++){
	    printf("%d ",female_id[i]);
    }

    printf("\n");

    printf("There are %d guests in red and %d guests in blue dress respectively.\n",red_people,blue_people);

    //printing the position of red people
    printf("The seating position of the guests in red dress are: ");
    for ( i = 0; i < no_people; i++)
    {
        if (uniqueid[i]%2==0)
        {
             printf("%d ",i+1);
        }
    }

    printf("\n");

    //printing the position of blue people
    printf("The seating position of the guests in blue dress are: ");
    for ( i = 0; i < no_people; i++)
    {
        if (uniqueid[i]%2==0)
        {

        }
	else{
	printf("%d ",i+1);
	}

    }

    printf("\n");

     // we can add another person only when their is a vacant seat available

    if (no_people<15)
    {
        printf("Enter the unique id of the new guests:");
        int newid;
        scanf("%d",&newid);

        uniqueid[no_people]=newid;
        no_people++;
        //now we will sort the newid again

         for (i = 0; i < no_people; ++i)
        {
            for (j = i + 1; j < no_people; ++j)
                {
                    if (uniqueid[i] < uniqueid[j])
                    {
                        a =  uniqueid[i];
                        uniqueid[i] = uniqueid[j];
                        uniqueid[j] = a;
                    }

                }
        }

        //now we will print the arrangement again
          printf("The new seating arrangement is:\n");

        for ( i = 0; i < no_people; i++)
        {
            printf("%d,",uniqueid[i]);


            if ((i+1)%5==0)
            {
                printf("\n");
            }
        }



    }

    return 0;
}
