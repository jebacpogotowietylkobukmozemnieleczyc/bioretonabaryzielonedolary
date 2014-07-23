/**
*  TODO
*  NAPISAC PROSTY PROGRAM WCZYTUJACY PLIK KONFIGURACYJNY, ODSEPAROWUJACY NAZWE
*  PARAMETRU OD JEGO WARTOSCI I WYPISAC NA EKRAN W ODWROTNEJ KOLEJNOSCI NIZ
*  ZOSTALY ZAPISANE W PLIKU.
*
*  1. Wyedytowac plik stack.h (sic!), tak by nie byl zwracany blad kompilacji.
*
*  2. Wczytac plik o nazwie podanej przez uzytkownika z linii polecen.
*  
*  3. Wypisac kazda linie z osobna na konsole.
*
*  4. Odseparowac nazwe parametru od jego wartosci (wyszukac znak '=') i wypisac je w postaci "<nazwa>" = "<parametr>" (printf)  
*
*  5. Wypisac blad na stderr jesli wystapil jakis blad podczas wczytywania/otwierania pliku;
*
*  6. Stworzyc plik src/stack.c i dodac w nim funkcje umieszczajace i
*  sciagajace ze stosu. Deklaracje funkcji umiescic w pliku stack.h.
*
*  7. Wlozyc kazdy parametr i wartosc na stos i wypisac je w odwrotnej kolejnosci;
*  
*  8. Zwalniac zaalokowane zasoby...
*  
*  9. Dokonczyc w domu!
*  
*  PRZYDATNE FUNKCJE:
*  fopen, fclose, malloc, free, strdup, strndup, fgets, fgetc
*    
*  man fopen...

if(c=='=')printf("\"");
if(c=='\n')printf("\"");

if(c=='=')printf("\"");

if(c=='\n')printf("\"");

*/

#include"stack.h"
#include"stack.h"
#include <stdio.h>
#include <stdlib.h>



int main(int argc, char **argv)
{
//printf("nazwa: %s \n",argv[1]);



FILE *file;
file = fopen(argv[1],"rb");
if(file!=NULL) printf("Działa \n");
else fprintf(stderr,"Błąd \n");



char c = fgetc(file);
int i =0;






char * a= malloc(sizeof(char));

while(c!=EOF){


if(c=='\n' )
{
a[i]='\0';
i =0;
//printf("%s\n",a);
NewElement(a);
free(a);
a= malloc(sizeof(char));
c =  fgetc(file);
continue;

}

a[i]=c;

c =  fgetc(file);
a = realloc(a,sizeof(char) * (i+2));

i++;
}
free(a);



//printf("Add \n");
//for(i=0;i<=w;i++)pointer = 



printf("Show \n");
ShowStack();

printf("Delete stack\n");
DeleteAll();









fclose(file);



	
	
  return 0;
}

