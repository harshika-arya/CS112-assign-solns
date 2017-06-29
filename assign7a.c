
// Objective: To find the inverse of given matrix if possible

#include<stdio.h>
#include<math.h>

//  making functions which calculate determinant, transpose and matrix for the
// calculation of inverse

float determinant(float[25][25],float);
void cofactor(float[25][25],float);
void transpose(float[25][25],float[25][25],float);

float determinant(float a[25][25],float k)
{
  float s=1,det=0,b[25][25];
  int i,j,m,n,c;
// if order of the matrix is 1 ,then determinant= element of the matrix

if (k==1)
    {
     return (a[0][0]);
    }
// if order is greater than 1 ,then finding determinant using recursion
else
    {
     det=0;
     for (c=0;c<k;c++)
       {
        m=0;
        n=0;
        for (i=0;i<k;i++)
          {
            for (j=0;j<k;j++)
              {
                  // initializing the element to be 0
                b[i][j]=0;
                // neglecting the row and column in which the element is present
                if (i != 0 && j != c)
                 {
                   b[m][n]=a[i][j];
                   if (n<(k-2))
                    n++;
                   else
                    {
                     n=0;
                     m++;
                     }
                   }
               }
             }
       // finding the determinant using recursion by multiplying each element of column
       // by matrix of one unit lower order(k-1)
          det=det + s * (a[0][c] * determinant(b,k-1));
          // for finding determinant we multiply alternate element with -1
          s=-1 * s;
          }
    }

    return (det);
}

// function for finding cofactor of matrix
void cofactor(float num[25][25],float f)
{
 float b[25][25],fac[25][25];
 int p,q,m,n,i,j;
 for (q=0;q<f;q++)
 {
   for (p=0;p<f;p++)
    {
     m=0;
     n=0;
     for (i=0;i<f;i++)
     {
       for (j=0;j<f;j++)
        {
            // neglecting the row and column in which the element is present
          if (i != q && j != p)
          {
            b[m][n]=num[i][j];
            if (n<(f-2))
             n++;
            else
             {
               n=0;
               m++;
               }
            }
        }
      }
      fac[q][p]=pow(-1,q + p) * determinant(b,f-1);
    }
  }
  transpose(num,fac,f);
}

void transpose(float num[25][25],float fac[25][25],float r)
{
  int i,j;
  float b[25][25],inverse[25][25],d;

   int a[25][25] ;

  for (i=0;i<r;i++)
    {
     for (j=0;j<r;j++)
       {
         a[i][j]=fac[j][i];
        }
    }
  d=determinant(num,r);
   printf("\n\n\nThe inverse of matrix is : \n");

   int det= d ;
   for (i=0;i<r;i++)
    {
     for (j=0;j<r;j++)
       {
         printf("\t%d/%d",a[i][j], det);
        }
    printf("\n");
     }
     // finding the position of element with highest minor
    int m, posx, posy ;
    m=-100 ;
    for (i=0;i<r;i++)
    {
     for (j=0;j<r;j++)
       {

         if(m<fac[i][j])
         {
             m=fac[i][j] ;
             posx=j+1 ;
             posy=i+1 ;
         }
        }
    }
    printf("\nThe position of the element with highest minor is i=%d and j=%d", posx, posy) ;
}


int main()
{
  float a[25][25], k, l, d ;
  int i, j, det ;
  printf("Enter the size of the matrix");
  scanf("%f, %f", &k, &l) ;
// taking the input of elements from user
  for (i=0;i<k;i++)
    { printf("Enter the elements of row %d: ",i+1) ;
     for (j=0;j<l;j++)
       {
        scanf("%f",&a[i][j]);
       }
    }
  d=determinant(a,k);
  // if no.of rows is not equal to no.of columns then matrix is not invertible
    if(l!=d)
    {
        printf("\nInverse of entered Matrix is not possible\n");
        printf("\nIt is not a square matrix\n");
        return 0 ;
    }
    // if determinant is 0 then also matrix is not invertible
  if (d==0)
   printf("\nInverse of entered matrix is not possible\n");
  else
    // if matrix is invertible then printing the inverse by calling cofactor function
   cofactor(a,k);
   return 0 ;
}
