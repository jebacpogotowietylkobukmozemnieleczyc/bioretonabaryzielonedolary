/*
 *App - główna struktura aplikacji
 *  size - wielkość okna
 * bufor - bufor
 * alpha -bufor alpha
 * ditance_collision - odleglosc od jakiej aplikacja sprawdza kolizje
 * ects - punkty gracza
 *
 * Start - inicjalizacja allegro
 * Init - tworzenie bitmap
 * End - usuwanie bitmap i zakończenie allegro
 * LoadConfig - wczytywanie configu
 * SetProperties - ustawienia
*/

#ifndef APP_H
#define APP_H
#include <allegro.h>
#include "maths.h"
#include "enemy.h"
#include "convexhull.h"
typedef struct SApp{
    vector size;
    BITMAP * bufor;
    BITMAP * alpha;
    int ditance_collision;
    int ects;
} SApp;


int Start(SApp * app);
int Init(SApp * app);
int Draw(SApp * app,SEnemy * enemy,SEnemy * enemy2,SConvexhull * convexhull);
int End(SApp * app);


int LoadConfig(SApp * app,SEnemy * enemy,SEnemy * enemy2);
int SetProperties(SApp * app,SEnemy * enemy,SEnemy * enemy2,char* element);
#endif // APP_H
