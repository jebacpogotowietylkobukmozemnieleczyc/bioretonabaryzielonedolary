
#include "triangle.h"

triangles * tpointer = NULL;

int CheckTriangles(vector position){

    triangles * pointer = tpointer;
    while(pointer!=NULL){

        if(PointInTriangle(position,pointer->v1,pointer->v2,pointer->v3) )return 1;
        pointer = pointer->next;
    }
    return 0;
}








int AddtoTriangles(vector v1,vector v2,vector v3){
if(tpointer==NULL){

tpointer = malloc(sizeof(struct triangles));
tpointer->next = NULL;
}
else{
 triangles* tmp =tpointer;
tpointer = malloc(sizeof(struct triangles));
tpointer->next = tmp;
}

tpointer->v1 =v1;
tpointer->v2 =v2;
tpointer->v3 =v3;
return 1;
}

triangles * DeletefromTriangles( triangles* toDelete){
if(toDelete!=NULL){
triangles * tmp =toDelete->next;
//free(toDelete->name);
free(toDelete);
return  tmp;

}
return NULL;
}

void DeleteAllTriangles(){

if(tpointer!=NULL){
tpointer = DeletefromStack(tpointer);
DeleteAllTriangles();
}
}




float sign(vector p1,vector p2, vector p3)
{
  return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

int PointInTriangle(vector pt, vector v1, vector v2, vector v3)
{
  int b1=0, b2=0, b3=0;

  if(sign(pt, v1, v2) < 0.0f)b1=1;
  if(sign(pt, v2, v3) < 0.0f)b2=1;
  if(sign(pt, v3, v1) < 0.0f)b3=1;

  return ((b1 == b2) && (b2 == b3));
}


