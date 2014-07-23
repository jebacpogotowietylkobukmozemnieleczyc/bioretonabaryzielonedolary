/*
 * EDirection - typ wiliczeniowy kierunków
 * SEnemy - struktura
 * position - pozycja
 * range - zakres pola widzenia
 * angle - kąt pola widzenia
 * direction - kierunek
 * speed - szybkość
 * size - wielkość
 * rSubdivisions - pole widzenia to zbiór trojkątów, współczynnik określa wielkość jednego trójkąta
 * keyboardSettings -  ustawienia klawiszy
 * image - bitmapa wyglądu
 *
 * DrawLight - rysuje pole widzenia
 * Move -  funkcja do poruszania SEnemy
 * ShadowCaster - rysuje wszystkie cienie
 * CreateShadow - funkcja tworząca i rysująca cienie {
 *      CheckEdge - sprawdza czy obiekt widzi bok figury czy nie
 *      CheckShadow - sprawdza, który wierzchołek zaczyna tworzyć cienie, aktóry kończy
 *      DrawShadow - rysuje cienie
 * }
 *  CheckCollision - sprawdza czy obiekty kolidują ze sobą
 *  Collision - sprawdza czy SEnemy koliduje z jakąs figurą
 *
 *  Catch - sprawdza czy SEnemy znajduje się w polu widzenia innego SEnemy
*/
#ifndef ENEMY_H
#define ENEMY_H
#include <allegro.h>
#include<math.h>
#include"maths.h"
#include"triangle.h"
#include "convexhull.h"

enum EDirection{UP=5,DOWN=1,RIGHT=7,LEFT=3};

typedef struct SKeyBoardSettings{
    int UP;
    int DOWN;
    int RIGHT;
    int LEFT;
}SKeyBoardSettings;


typedef struct SEnemy{
    vector position;
    int range;
    double angle;
    enum EDirection direction;
    int speed;
    int size;
    double rSubdivisions;
    SKeyBoardSettings * keyboardSettings;
    BITMAP * image;

} SEnemy;



void DrawLight(BITMAP * alpha,SEnemy * enemy);

int Move(SEnemy * enemy);

int ShadowCaster(BITMAP * alpha,SEnemy * enemy);
int CreateShadow(BITMAP * alpha,SEnemy * enemy,SConvexhull * convexhull);
int CheckShadow(SEnemy * enemy,SConvexhull * convexhull,int * FACE_EDGES);
int CheckShadowVertex(SConvexhull * convexhull, int * FACE_EDGES,int  * start_shadow_vertex, int  * end_shadow_vertex);
int DrawShadow(BITMAP * bufor,SEnemy * enemy,SConvexhull * convexhull, int  * start_shadow_vertex, int  * end_shadow_vertex);

int Catch(SEnemy * enemy,SEnemy * enemy2);
int Collision(int ditance_collision, SEnemy * enemy);

#endif // ENEMY_H
