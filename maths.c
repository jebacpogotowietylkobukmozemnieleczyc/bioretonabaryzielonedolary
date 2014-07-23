#include<math.h>
#include"maths.h"


double getRadians( vector point )
{
    if( point.x == 0 )
    {


        if( point.y > 0 )
             return M_PI / 2;

        if( point.y < 0 )
             return - M_PI / 2;



                return 0;
    } //if

    return atan2( point.y , point.x ) ;//+( point.x < 0 ? M_PI : 0 );
}

int dotproduct(vector a, vector b)
{
return    a.x * b.x + a.y * b.y;
}





double length(vector point){
        return sqrt(point.x*point.x+point.y*point.y);
     }




vector normal(vector currentPoint,vector prevPoint){
     vector result;
     result.x = currentPoint.y - prevPoint.y;
     result.y = -(currentPoint.x - prevPoint.x);
     return result;
}

vector Vector(vector currentPoint,vector prevPoint){
     vector result;
     result.x = currentPoint.x - prevPoint.x;
     result.y = currentPoint.y - prevPoint.y;
     return result;
}




