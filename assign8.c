
// Date: 14th march 2017
// Assignment 8


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* A linked list node */
struct mynode
{
	char roll[3] ;
	float cpi ;
	float attendance ;
	struct mynode *next ;
};
typedef struct mynode *node;

int main()
{
	int x1 , x2 ;
	char x3[3] , x4[3] ;
	// defining a head and tail and initializing it to null
node head ;
	node tail ;
	head = NULL ;
	tail = NULL ;

	head = (node)malloc(sizeof(node)) ;
	tail = head ;
   // getting input from user
   // assigning the value to tail without changing the head
	while (1)
	{
		printf ("Enter elements of the node\n" ) ;

		printf ("Enter the roll = " ) ;
		scanf ("%s" , tail->roll ) ;

		printf ("Enter the cpi = " ) ;
		scanf ("%f" , &tail->cpi ) ;

		printf ("Enter the attendance = " ) ;
		scanf ("%f" , &tail->attendance ) ;
        // initially terminating the list at tail
        // but if we want more data to be added,incrementing the tail
		tail->next = NULL ;

		printf ("Any more node (1/0) : " ) ;
		scanf ("%d" , &x1 ) ;

		if ( x1 == 1 )
		{
			tail->next = (node) malloc(sizeof(node)) ;
			tail = tail->next ;

		}
      // if we don't want to enter more nodes,complete the list
		if ( x1 == 0 )
			break ;
	}
  //if we have end up inputting the values in list,giving options for printing,swapping,reversing or to exit

	while ( x1 == 0 )
	{
		printf ("Enter 1 for print, 2 for swap, 3 for reverse, 0 for exit : " ) ;
		scanf ("%d" , &x2 ) ;
// if input is 1 we have to display the linked list


		if ( x2 == 1 )
		{
			printf ("The list of elements in the linked list is\n" ) ;
// making a new pointer variable as 'var' and assigning head as its value
    node var ;
			var = head;
// as long as 'var' does not point to null i.e. node is not completed, print the list in given form
			while( var!=NULL)
			{
				printf ("<%s, %0.2f, %0.2f>", var->roll ,var->cpi , var->attendance ) ;
				var = var->next;

				if ( var != NULL )
					printf (", ") ;
				else
				{
					printf("\n") ;
					break ;
				}
			}
		}
// for swapping
		if ( x2 == 2 )
		{
			printf ("Enter roll of first node to be swapped : " ) ;
			scanf ( "%s" , x3 ) ;
			printf ("Enter roll of second node to be swapped : " ) ;
			scanf ("%s" , x4 ) ;
// making two new pointer variables as 'var1' and 'var2'and assigning the 'head' as its value

			node var1 ;
			node var2 ;

			var1 = head ;
			var2 = head ;


			while ( var1 != NULL )
			{ // using string function to find roll 'x3'
				if ( !strcmp (var1->roll, x3 ))
					break ;
				else
		 			var1 = var1->next ;
			}

			while ( var2 != NULL )
			{ // using string function to find roll 'x4'
				if ( !strcmp (var2->roll, x4 ))
					break ;
				else
		 			var2 = var2->next ;
			}
      // if both roll no.s are found, swap them
			char r[4] ;
			strcpy (r, var1->roll) ;
			strcpy (var1->roll, var2->roll) ;
			strcpy (var2->roll, r);

	// swapping their cpi's and attendance too
			float c ;
			c = var1->cpi ;
			var1->cpi = var2->cpi ;
			var2->cpi = c ;

			float a ;
			a = var1->attendance ;
			var1->attendance = var2->attendance ;
			var2->attendance = a ;

			printf ("Swap successful\n") ;
		}

		// for reversing
		if ( x2 == 3 )
		{
			node var3 ;
			node var4 ;
			node var5 ;

			var3 = NULL ;
			var4 = head ;
			var5 = NULL ;

			while ( var4!= NULL )
			{
				var5 = var4->next ;
				var4->next = var3 ;
				var3 = var4 ;
				var4 = var5 ;

				if ( var4 == NULL )
					break ;
			}

			head = var3 ;

			printf ("Reverse operation is successfully done.\n" ) ;
		}

		if ( x2 == 0 )
		{
			printf ("Program ends.\n" ) ;
			break ;
		}

	}
}



