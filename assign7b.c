
// Objective: To represent the strings in lexicographical order
// Date: 7th march 2017

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{ char word[20],**w;
// “**w” is a pointer to a pointer array
// Thus it is a dynamic array of pointers

  char temp[20];

int i,n,j;

scanf("%d",&n);
w= (char**) malloc(n*sizeof(char*));

// getting the input of strings from user
for(i=0;i<n ;i++)
  { scanf("%s",word);
//  malloc requires the number of bytes you want to allocate dynamically

    w[i]=(char*) malloc((strlen(word)+1)* sizeof(char));
    // copying the word array into w[i]
    strcpy(w[i],word);
  }
  for(i=0;i< n-1;++i)
  {
      for(j=i+1;j<n;++j)
      {    // comparing the word with next word
          if(strcmp(w[i],w[j])>0)
          {
              //  swapping the words if they are not in dictionary order

              strcpy(temp,w[i]);
              strcpy(w[i],w[j]);
              strcpy(w[j],temp);

          }
      }
  }
  //  printing the words in dictionary order
  for(i=0;i<n;i++)
    printf("%s\n",w[i]);
return 0;
}
