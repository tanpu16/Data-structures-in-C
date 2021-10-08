#ifndef STACK_H
#define STACK_H 

#include "data.h"

/*
typedef struct Data
{
	int value;
	
}Data;
*/
typedef struct Stack
{
  struct Data * data;
  int top;
  int cur_size;
  int max_size;
  int (* push)(struct Stack * stack, Data value);
  Data * (* peek)(struct Stack * stack);
  Data * (* pop)(struct Stack * stack);
  void (*clear)(struct Stack * stack);
  void (*delete)(struct Stack * stack );
}Stack;



Stack * newStack();
int pushStack(Stack * stack, Data value );
Data * peekStack(Stack * stack);
Data * popStack(Stack * stack);
void  clearStack(Stack * stack);
void deleteStack(Stack * stack);
#endif
