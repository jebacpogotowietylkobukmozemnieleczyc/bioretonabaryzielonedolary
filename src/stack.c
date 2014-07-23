#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
struct stack * pointer = NULL;



void Convert(int *number,char * string){
	int i =0;
	
	while(string[i]!='\0'){
		i++;
	}
	int m =1;	
	*number =0;
		
	for(i=i-1;i>=0;i--){
		
		(*number)+=(string[i]-48)*m;
		m*=10;	
	}
	


}




char * DeleteWhitespace(char * string){
	int i = 0;
	int b =0;
	int a =0;
	int j =0;
	int length = 0;
		
	while(string[length]!='\0')length++;
	//printf("Length: %d \n",length);
	for(i=0;i<length && string[i]==' ';i++)b++;
	//printf("b: %d \n",b);
	for(i=length-1;i>=0 && string[i]==' ';i--)a++;
	//printf("a: %d \n",a);
	char * newstring = malloc(sizeof(char)*(length-a-b));
	if(a>0 || b> 0)fprintf(stderr,"Spacje\n");
	for(i=b,j=0;i<length-a;i++,j++)newstring[j]=string[i];
	newstring[length-a-b]='\0';	
	free(string);
	return newstring;
}
		
			
void NewElement(char* element){
	int i =0;
	int j =0;
	int c =0;
	
	char  ** part = malloc(sizeof(char*)*2);
	part[0]=malloc(sizeof(char));
	

	while(element[i]!='\0'){
		if(j>20){
			fprintf(stderr,"Za dlugi string \n");
			if(c==1)free(part[1]);	
			free(part[0]);		
			free(part);
			return;
		}		
		
		if(element[i]=='='){
			part[0][j]='\0';		
			j=0;
			c=1;
			i++;
			part[1]=malloc(sizeof(char));		
			continue;
		}
		part[c][j]=element[i];
		part[c]= realloc(part[c],sizeof(int) * (j+2));
		i++;
		j++;
	}
	if(c==1){
		part[1][j]='\0';
		printf("\"%s\"=\"%s\"\n",part[0],part[1]);
		part[0]=DeleteWhitespace(part[0]);
		part[1]=DeleteWhitespace(part[1]);			
		AddtoStack(part[0],part[1]);
		
		
	}
	else {
		part[0][j]='\0';	
		printf("\"%s\"\n",part[0]);	
		fprintf(stderr,"Brak = \n");	
		
	}	
	free(part);
	
	
}


void AddtoStack(char* name,char* value){
if(pointer==NULL){

pointer = malloc(sizeof(struct stack));
pointer->next = NULL;
}
else{
struct stack* tmp =pointer;
pointer = malloc(sizeof(struct stack));
pointer->next = tmp;
}

pointer->name =name;
pointer->value = value;
pointer->type = STRING;


int i =0;
do{
if((int)value[i]<48 || (int)value[i] > 57)return;
i++;
}
while(value[i]!='\0');
pointer->type = NUMBER;

}
void ShowStack(){
while(pointer!=NULL){

if(pointer->type==STRING)printf("%s = %s\n",pointer->name,pointer->value);
else{
	int number;
	Convert(&number,pointer->value);		
 	printf("%s = %d\n",pointer->name,number);
}
pointer = pointer->next;
}
}


void DeleteAll(){

while(pointer!=NULL){
pointer = DeletefromStack(pointer);

}

}


struct stack * DeletefromStack(struct stack * toDelete){
if(toDelete!=NULL){
struct stack* tmp =toDelete->next;
free(toDelete->name);
free(toDelete->value);	
free(toDelete);
return  tmp;

}
}

