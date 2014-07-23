#ifndef STACK_H
#define STACK_H

enum EType {UNKNOW,NUMBER,STRING};

struct stack
{
 struct stack *next;
 char *name;
 char *value;
 enum EType type;
};
extern struct stack * pointer;

void AddtoStack(char* name,char* value);
void NewElement(char* element);
void ShowStack();
void DeleteAll();

void Convert(int * number,char * string);
struct stack * DeletefromStack(struct stack * pointer);
#endif
