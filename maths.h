/*
 * vector - struktura punktów i wektorów
 * getRadians - oblicza kąt
 * dotproduct - iloczyn skalarny
 * length - długość wektora
 * normal -  oblicza noramlną wektora
 * Vector - oblicza wektor dwóch punktów
*/


#ifndef MATHS_H
#define MATHS_H


//point & vector
typedef struct vector{
int x;
int y;
} vector;

double getRadians( vector point );

int dotproduct(vector a, vector b);

double length(vector point);

vector normal(vector currentPoint,vector prevPoint);

vector Vector(vector currentPoint,vector prevPoint);

#endif // MATHS_H
