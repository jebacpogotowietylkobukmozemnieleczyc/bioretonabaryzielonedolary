/*
 * triangles - dynamiczna struktura, magazynująca cienie
 * next - wkażnik na następną
 * color - kolor figury
 * vertex - tablica wierzchołków
 *
 * tpointer - wkażnik na stos cieni
 * AddtoStack -dodowanie elementu do triangles
 * DeletefromStack - usuwanie elemntu z triangles
 * DeleteAll - usuwa wszystkie alementy z triangles
 *
 * CheckTriangles - sprawdza czy punkt znajduje sie wewnątrz któregoś z ceni
 * PointInTriangle - sprawdza czy punkt znajduje sie wewnątrz cienia
 * sign - po, ktorej stronie boku znajduje się punkt
*/



#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <maths.h>
#include <stdio.h>



typedef struct triangles
{
  struct triangles *next;
  vector  v1;
  vector  v2;
  vector  v3;
} triangles;

extern  triangles * tpointer;

int AddtoTriangles(vector v1,vector v2,vector v3);
triangles  * DeletefromTriangles( triangles * toDelete);
//void ShowStack();
void DeleteAllTriangles();
//stack * GetPointer();

int CheckTriangles();


#endif // TRIANGLE_H
