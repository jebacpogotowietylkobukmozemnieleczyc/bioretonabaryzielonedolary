#include"enemy.h"
#include"app.h"



void DrawLight(BITMAP * bufor,SEnemy * enemy){



    double angle;
    for (angle = enemy->direction*0.25*M_PI; angle < ((enemy->direction*0.25)+enemy->angle)*M_PI; angle+=enemy->rSubdivisions*M_PI) {

        int tr1x= enemy->position.x + enemy->range * cos(angle);
        int tr1y= enemy->position.y+ enemy->range * sin(angle);

       int  tr2x= enemy->position.x + enemy->range * cos(angle+enemy->rSubdivisions*M_PI);
       int  tr2y= enemy->position.y + enemy->range * sin(angle+enemy->rSubdivisions*M_PI);
        triangle( bufor, enemy->position.x, enemy->position.y, tr1x, tr1y, tr2x, tr2y, makecol( 255, 255, 0) );
    }



}

int CheckEdge(vector   position,SConvexhull * convexhull, int * FACE_EDGES){
    int i;
    int j;
    int shadow_exist = 0;
    int * dot= malloc(sizeof(int) * convexhull->amout);
    if (dot==NULL)return 0;

    for(i=0; i<convexhull->amout;i++){


            j = i+1;
            if(j==convexhull->amout)j=0;
            dot[i]= dotproduct(normal(convexhull->vertex[j],convexhull->vertex[i]),Vector(position,convexhull->vertex[j]));

            if(dot[i]>0){FACE_EDGES[i]=1;shadow_exist = 1;}
            else FACE_EDGES[i]=0;

            //check
            /*
            char napis[100];
            itoa (FACE_EDGES[i],napis,10);
            textout_ex( screen, font, napis, i *200 , 550, makecol( 255, 0, 255 ), - 1 );
            */

        }
    free(dot);
    return shadow_exist;
}

int CheckShadowVertex(SConvexhull * convexhull, int * FACE_EDGES,int  * start_shadow_vertex, int  * end_shadow_vertex){
    int i;
    int j;

    for(i=0; i<convexhull->amout;i++){

        j = i +1;
        if(j==convexhull->amout)j=0;
        if(FACE_EDGES[i]==1 && FACE_EDGES[j]==0)  *start_shadow_vertex =j;
        else if(FACE_EDGES[i]==0 && FACE_EDGES[j]==1)  *end_shadow_vertex =j;

        }
    //check
       /*
    char napis[100];
    itoa (*start_shadow_vertex,napis,10);
    textout_ex( screen, font, napis, 200 , 750, makecol( 255, 0, 255 ), - 1 );
    itoa (*end_shadow_vertex,napis,10);
    textout_ex( screen, font, napis, 400 , 750, makecol( 255, 0, 255 ), - 1 );
*/
    return 1;
}




int DrawShadow(BITMAP * bufor,SEnemy * enemy,SConvexhull * convexhull, int  * start_shadow_vertex, int  * end_shadow_vertex){

    vector shadow;
    vector ver;
    vector before_shadow;
    double proportion;
    double length_vector;

    int j=*start_shadow_vertex;
    int v;

        while(j!=*end_shadow_vertex){

                if(j==convexhull->amout){j=0;continue;}
                v = j+1;
                if(v==convexhull->amout)v=0;

                length_vector = length(Vector(enemy->position,convexhull->vertex[j]));
                proportion = enemy->range*2/length_vector;

                ver = Vector(convexhull->vertex[j],enemy->position);
                shadow.x = enemy->position.x + ver.x * (double)proportion;
                shadow.y = enemy->position.y + ver.y * (double)proportion;

                if(proportion>1){

                    vector vertex[4];
                        vertex[0] = convexhull->vertex[j];
                        vertex[1] = shadow;
                        vertex[2] = convexhull->vertex[v];
                        vertex[3] = before_shadow;
                        triangle( bufor, vertex[0].x, vertex[0].y, vertex[1].x, vertex[1].y, vertex[2].x, vertex[2].y, makecol( 0, 0, 0));//255, 0, 255 0,0,0
                        AddtoTriangles(vertex[0],vertex[1],vertex[2]);
                        if(j!=*start_shadow_vertex){
                         triangle( bufor, vertex[0].x, vertex[0].y, vertex[3].x, vertex[3].y, vertex[1].x, vertex[1].y, makecol( 0,0,0));//100, 100, 100
                        AddtoTriangles(vertex[0],vertex[3],vertex[1]);
                        }
                }
                before_shadow.x = shadow.x;
                before_shadow.y = shadow.y;
                j++;
            }
   length_vector = length(Vector(enemy->position,convexhull->vertex[*end_shadow_vertex]));
   proportion = enemy->range*2/length_vector;
   ver = Vector(convexhull->vertex[*end_shadow_vertex],enemy->position);
   shadow.x = enemy->position.x + ver.x * (double)proportion;
   shadow.y = enemy->position.y + ver.y * (double) proportion;
   if(j!=*start_shadow_vertex){
       triangle( bufor, convexhull->vertex[*end_shadow_vertex].x, convexhull->vertex[*end_shadow_vertex].y, before_shadow.x, before_shadow.y, shadow.x, shadow.y, makecol( 0,0,0 ));//100, 100, 100
        AddtoTriangles(convexhull->vertex[*end_shadow_vertex],before_shadow,shadow);
   }
    return 1;
}




int CreateShadow(BITMAP * alpha,SEnemy * enemy,SConvexhull * convexhull){

    int * FACE_EDGES= malloc(sizeof(int) * convexhull->amout);
    if (FACE_EDGES==NULL)return 0;
    if(CheckEdge(enemy->position,convexhull,FACE_EDGES)){

        int start_shadow_vertex;
        int end_shadow_vertex;
        if(!CheckShadowVertex(convexhull,FACE_EDGES,&start_shadow_vertex,&end_shadow_vertex))return 0;
        if(!DrawShadow(alpha,enemy,convexhull,&start_shadow_vertex,&end_shadow_vertex))return 0;
    }
    /*else{
        if(key[ KEY_LEFT ] )enemy->position.x+=enemy->speed;
        if(key[ KEY_RIGHT ])enemy->position.x-=enemy->speed;
        if( key[ KEY_UP ] )enemy->position.y+=enemy->speed;
        if(key[ KEY_DOWN ] )enemy->position.y-=enemy->speed;
    }*/

    free(FACE_EDGES);
    return 1;
}


int ShadowCaster(BITMAP * alpha,SEnemy * enemy){

    int i;
    stack * pointer = GetPointer();
    while(pointer!=NULL){
    SConvexhull * convexhull = pointer->convexhull;
        for(i=0; i<convexhull->amout;i++){
            if(length(Vector(enemy->position,convexhull->vertex[i]))<=enemy->range){
               CreateShadow(alpha,enemy,convexhull);
                break;
            }
        }
        pointer = pointer->next;
    }
    return 1;
}




int Move(SEnemy * enemy){


    if( key[ enemy->keyboardSettings->LEFT ] ) {
        enemy->position.x-=enemy->speed;
        enemy->direction=LEFT;
    }

    if( key[ enemy->keyboardSettings->RIGHT ] ) {
        enemy->position.x+=enemy->speed;
        enemy->direction=RIGHT;
    }

    if( key[ enemy->keyboardSettings->UP ] ) {
        enemy->position.y-=enemy->speed;
        enemy->direction=UP;
    }

    if( key[ enemy->keyboardSettings->DOWN ] ){
        enemy->position.y+=enemy->speed;
        enemy->direction=DOWN;
    }
    return 1;
}



int CheckCollision(SEnemy * enemy,SConvexhull * convexhull){
    int * FACE_EDGES= malloc(sizeof(int) * convexhull->amout);
    if (FACE_EDGES==NULL)return 0;

    vector vertex[4];
    vertex[0].x = enemy->position.x - enemy->size;
    vertex[0].y = enemy->position.y - enemy->size;
    vertex[1].x = enemy->position.x + enemy->size;
    vertex[1].y = enemy->position.y - enemy->size;
    vertex[2].x = enemy->position.x + enemy->size;
    vertex[2].y = enemy->position.y + enemy->size;
    vertex[3].x = enemy->position.x - enemy->size;
    vertex[3].y = enemy->position.y + enemy->size;

    int i ;
    for (i = 0; i < 4; ++i) {
        if(!CheckEdge(vertex[i],convexhull,FACE_EDGES)){
            if(key[ enemy->keyboardSettings->LEFT ] )enemy->position.x+=enemy->speed;
            if(key[ enemy->keyboardSettings->RIGHT ])enemy->position.x-=enemy->speed;
            if(key[ enemy->keyboardSettings->UP ] )enemy->position.y+=enemy->speed;
            if(key[ enemy->keyboardSettings->DOWN  ] )enemy->position.y-=enemy->speed;
            break;
        }
    }

    free(FACE_EDGES);

    return 1;
}






int Collision(int ditance_collision, SEnemy * enemy){

    int i;
    stack * pointer = GetPointer();
    while(pointer!=NULL){
    SConvexhull * convexhull = pointer->convexhull;
        for(i=0; i<convexhull->amout;i++){
            if(length(Vector(enemy->position,convexhull->vertex[i]))<=ditance_collision){
               CheckCollision(enemy,convexhull);
                break;
            }
        }
        pointer = pointer->next;
    }
    return 1;
}





int Catch(SEnemy * enemy,SEnemy * enemy2){

    if(length(Vector(enemy->position,enemy2->position))>enemy->range+enemy2->size)return 0;
    double angle = getRadians(Vector(enemy->position,enemy2->position));
    //if(angle >= enemy->direction*0.25*M_PI && angle <= ((enemy->direction*0.25)+enemy2->angle)*M_PI)

    double r;
    if(enemy->direction==DOWN)r = -0.75;
    else if(enemy->direction==LEFT)r = -0.25;
    else if(enemy->direction==UP)r = 0.25;
    else if(enemy->direction==RIGHT)r = 0.75;
    double d = r+ 0.5;
    if(d>1)d=-0.75;

    //printf("%f - %f - %f \n",angle ,r, d );
    if(!((angle>=r*M_PI && angle <=d*M_PI) || (enemy->direction==RIGHT &&(angle>=r*M_PI || angle <=d*M_PI))))return 0;


    if(CheckTriangles(enemy2->position))return 0;



    return 1;
}


