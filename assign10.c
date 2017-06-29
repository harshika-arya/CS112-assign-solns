
// Assignment 10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Structure for creating nodes of the circular linked list
struct mynode
{
	int data ;
	struct mynode* left ;
	struct mynode* right ;
};

//Function for entering values in the circular linked list
struct mynode* mycirlist ( long long num )
{
	struct mynode *head , *tail, *temp ;
	int h = 0 ;

	head = NULL ;
	tail = NULL ;
	temp = NULL ;

	head = (struct mynode*)malloc(sizeof(struct mynode)) ;
	tail = head ;

	while (1)
	{
		tail->left = NULL ;
		tail->right = NULL ;
		tail->data = num % 100000 ;
		num = num/100000 ;
		h = h + 1 ;

		tail->right = (struct mynode*)malloc(sizeof(struct mynode)) ;
		temp = tail ;
		tail = tail->right ;
		tail->left = temp ;


		if ( num == 0 )
		{
			tail->data = h ;
			tail->right = head ;
			head->left = tail ;
			head = tail ;
			break ;
		}
	}

	return head ;

}

//The comparison function
void comparison ( long long f , long long s )
{
	if ( f > s )
		printf ( "1st number is larger\n" ) ;

	if ( f < s )
		printf ( "2nd number is larger\n" ) ;

	if ( f == s )
 		printf ( "Both numbers are equal\n" ) ;

}

//The addition function
void addition ( long long f , long long s )
{
	long long add ;

	add = f + s ;

	printf ("Sum is : %lld\n" , add ) ;
}

//The subtraction function
void subtraction ( long long f , long long s )
{
	long long sub ;

	sub = f - s ;

	printf ("Difference is : %lld\n" , sub ) ;
}

//The main function
int main()
{
	char choice ;
	long long first , second ;
	int i ;
 	struct mynode *head1 , *head2 ;

	while (1)
	{
		printf("\nComparison(c) or Addition(a) or Subtraction(s) or Exit(x) : ") ;
		scanf("%c" , &choice ) ;

		if ( choice == 'x' )
			break ;

		if ( choice == 'c' || choice == 'a' || choice == 's' )
		{
			scanf("%lld" , &first ) ;
			scanf("%lld" , &second ) ;

			head1 = NULL ;
			head2 = NULL ;

			head1 = mycirlist( first ) ;
			head2 = mycirlist( second ) ;

			if ( choice == 'c' )
				comparison ( first , second ) ;

			if ( choice == 'a' )
				addition ( first , second ) ;

			if ( choice == 's' )
				subtraction ( first , second ) ;
        continue;
		}
	}

	return 0 ;
}


