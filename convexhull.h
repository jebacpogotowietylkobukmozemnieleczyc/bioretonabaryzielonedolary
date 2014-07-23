/*
 * SConvexhull - struktura figury
 * amout - liczba wierzchołków
 * color - kolor figury
 * vertex - tablica wierzchołków
 *
 * stack - dynamiczna struktura, magazynująca figury
 * next -wkażnik na następną
 * convexhull - figura
 *
 * pointer - wkażnik na stos figur
 *
 * AddtoStack -dodowanie elementu do stack
 * DeletefromStack - usuwanie elemntu z stack
 * DeleteAll - usuwa wszystkie alementy z stack
 * GetPointer() - daje wskaznik do stacka
 * DrawConvexhull - rysuje figure
 * DrawAll -rysuje wszsykie gifury
 *
*/


#ifndef CONVEXHULL_H
#define CONVEXHULL_H
#include <maths.h>

typedef struct SConvexhull{
    int amout;
    int color;
    vector * vertex;
} SConvexhull;





typedef struct stack
{
  struct stack *next;
 SConvexhull *  convexhull;
} stack;

extern  stack * pointer;

int AddtoStack(SConvexhull * convexhull);
stack * DeletefromStack( stack * toDelete);
//void ShowStack();
void DeleteAll();
stack * GetPointer();
int DrawConvexhull(BITMAP * bufor,SConvexhull * convexhull);


int DrawAll(BITMAP * bufor);
#endif  //CONVEXHULL_H




