#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Stack * newStack()
{
	Stack * st = malloc(sizeof(Stack));

	st->data = NULL;
	st->top = -1;
	st->max_size = 0;
	st->cur_size = 0;
	st->push = pushStack;
	st->pop = popStack;
	st->clear = clearStack;
	st->peek = peekStack;
	st->delete = deleteStack;
	return st;
}


int pushStack(Stack * stack, Data value)
{

	
		stack->top++;
		if(stack->top >= stack->max_size)
		{
			stack->max_size=stack->top * 2 +1;
			Data * new_data=calloc(stack->max_size,stack->max_size*sizeof(Data));
			memcpy(new_data,stack->data,stack->cur_size*sizeof(Data));	
			free(stack->data);	
			stack->data = new_data;
		}	
		if(stack->cur_size <= (stack->top+1))
		{
			stack->cur_size= stack->top +1;
		}	
		stack->data[stack->top] = value;

		return stack->top;
	
}

Data * peekStack(Stack * stack)
{
      

        if(stack->top == -1)
         {
           printf("Stack is empty\n");
           return NULL;
         }
     
	Data * temp = &stack->data[stack->top];
	return temp;
 
}

Data * popStack(Stack * stack)
{
        if(stack->top == -1)
         {
           printf("Stack is empty\n");
           return NULL;
         }
      
	Data *temp = &stack->data[stack->top];
	stack->top --;

      return temp;
}

void clearStack(Stack * stack)
{
	//free(stack->data);

	while(stack->top != -1)
	{
		stack->top--;
	}

	free(stack->data);
	//free(stack);
}
void deleteStack(Stack *stack)
{
	free(stack);
}
