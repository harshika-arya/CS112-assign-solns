
//Objective: finding whether the points are collinear or not if they are non collinear then finding its area.
#include <stdio.h>
#include <math.h>
int main()
// let x1,x2,x3,y1,y2,y3 be the coordinates of points.
{int x1,x2,x3,y1,y2,y3;
float a,b,c,area,max,otherside1,otherside2;
 // Taking the input of points
    printf("Enter the points:\n");
    printf("Point1:");
    scanf("%d ,%d",&x1,&y1);
    printf("Point2:");
    scanf("%d ,%d",&x2,&y2);
    printf("Point3:");
    scanf("%d ,%d",&x3,&y3);
    // Calculating the square of sides (a,b,c)
    a=((x1-x2)*(x1-x2) +(y1-y2)*(y1-y2));
    b=((x1-x3)*(x1-x3) +(y1-y3)*(y1-y3));
    c=((x2-x3)*(x2-x3) +(y2-y3)*(y2-y3));
     // Finding the largest size
    if(a>=b && a>=c)
       {max=a;
        otherside1=b;
        otherside2=c;}
    if(b>=c && b>=a)
        {max=b;
        otherside1=a;
        otherside2=c;}
    if(c>=b && c>=a)
        {max=c;
        otherside1=a;
        otherside2=b;}

        // Formula for calculating area
    area= (x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))/2.0;

    if(area<0){
            area=area-2*area;
        }


    if(area==0)
        {printf("The points are collinear.\n");
        }
    else if( area!=0 && (otherside1 +otherside2- max)>0)
          {printf("The points are non-collinear. The formed triangle is a acute angled triangle with area = %.1f\n",area);
            }
    else if( area!=0 && ((otherside1) +(otherside2)- (max))<0)
            printf("The points are non-collinear. The formed triangle is a obtuse angled triangle with area = %.1f\n",area);
    else if( area!=0 && ((otherside1) +(otherside2)- (max))==0)
            printf("The points are non-collinear. The formed triangle is a right angled triangle with area = %.1f\n",area);

    return 0;
}
