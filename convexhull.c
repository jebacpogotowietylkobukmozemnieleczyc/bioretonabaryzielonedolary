#include "allegro.h"
#include <stdio.h>
#include "convexhull.h"

stack * pointer = NULL;
int DrawConvexhull(BITMAP * bufor,SConvexhull * convexhull){
    int i;
    int mx =0;
    int my =0 ;
    for ( i= 0; i < convexhull->amout; ++i) {

        int j = i+1;
        if(j>=convexhull->amout)j=0;
        line( bufor, convexhull->vertex[i].x, convexhull->vertex[i].y,  convexhull->vertex[j].x, convexhull->vertex[j].y , convexhull->color  );
        mx+=convexhull->vertex[i].x;
        my+=convexhull->vertex[i].y;
    }
    mx/=convexhull->amout;
    my/=convexhull->amout;

    floodfill( bufor, mx, my, convexhull->color);
    return 1;
}



int DrawAll(BITMAP * bufor){

stack * pointer = GetPointer();
while(pointer!=NULL){
    DrawConvexhull(bufor,pointer->convexhull);
    pointer = pointer->next;
}
return 1;
}

int AddtoStack(SConvexhull * convexhull){
if(pointer==NULL){

pointer = malloc(sizeof(struct stack));
pointer->next = NULL;
}
else{
 stack* tmp =pointer;
pointer = malloc(sizeof(struct stack));
pointer->next = tmp;
}

pointer->convexhull =convexhull;

return 1;
}

//rekurencja

 stack * DeletefromStack( stack * toDelete){
if(toDelete!=NULL){
 stack* tmp =toDelete->next;
//free(toDelete->name);
free(toDelete);
return  tmp;

}
return NULL;
}

void DeleteAll(){

if(pointer!=NULL){
pointer = DeletefromStack(pointer);
DeleteAll();
}
}


stack * GetPointer(){
    return pointer;
}







