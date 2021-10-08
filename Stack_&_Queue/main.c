#include <stdio.h>
#include "queue.h"
#include "stack.h"
#include <stdlib.h>
#include <assert.h>

int main()
{
	printf("\n***** Stack  ****\n\n");
	
	printf("\ncreate stack\n");

	Stack * stk1 = newStack();
		
	printf("\n\n******Push******\n");
	
	int val;
	Data *d;
	Data data_array[20];
	
	val = stk1->push(stk1,(Data){10});
	assert(val==0);
	
	val = stk1->push(stk1,(Data){20});
	assert(val==1);

	val = stk1->push(stk1,(Data){30});
	assert(val==2);

	val = stk1->push(stk1,(Data){40});
	assert(val==3);

	val = stk1->push(stk1,(Data){50});
	assert(val==4);

	printf("\n\n********Peek*********\n");
	
	d=stk1->peek(stk1);
	
	printf("\nValue at top is : %d ",d->value);
	
	printf("\n\n*******POP*********\n");
	
	d = stk1->pop(stk1);
	
	printf("\nValue at top is after pop : %d ",d->value);
	
	d = stk1->pop(stk1);
	
	printf("\nValue at top is after pop: %d ",d->value);

	printf("\n\n");	

	printf("\n\n*****Clean*****\n");
	
	stk1->clear(stk1);	
	d = stk1->pop(stk1);
	
	/*
	val = stk1->push(stk1,(Data){16});
	assert(val==0);

	d=stk1->peek(stk1);
	printf("\nValue at top is : %d\n ",d->value);
	*/

	stk1->delete(stk1);
	
	printf("\n\n");

	
	//Data *d;
	printf("\n\n");	
	
	printf("\n\n******Queue*****\n\n");
	
	printf("\ncreate Queue\n");

	Queue * q1 = newQueue();
		
	printf("\n\n******Enqueue******\n");
	
	int size;
	
	size=q1->enqueue(q1,(Data){10});
	printf("\nSize is : %d\n",size);
	
	size=q1->enqueue(q1,(Data){20});
	printf("\nSize is : %d\n",size);
	
	size=q1->enqueue(q1,(Data){30});
	printf("\nSize is : %d\n",size);
	
	size=q1->enqueue(q1,(Data){40});
	printf("\nSize is : %d\n",size);

	size=q1->enqueue(q1,(Data){40});
	printf("\nSize is : %d\n",size);

	size=q1->enqueue(q1,(Data){50});
	printf("\nSize is : %d\n",size);

	size=q1->enqueue(q1,(Data){60});
	printf("\nSize is : %d\n",size);

	printf("\n\n******peek queue******\n");
	
	d=q1->peek(q1);

	printf("\nValue at front is : %d\n",d->value);
	
	printf("\n\n******dequeue******\n");
	
	d=q1->dequeue(q1);
	
	printf("\nValue at front is : %d and size after dequeue is: %d\n",d->value,q1->size);
	
	d=q1->dequeue(q1);
	
	printf("\nValue at front is : %d and size after dequeue is : %d\n",d->value,q1->size);

	printf("\n\nValue inserted\n");
	size=q1->enqueue(q1,(Data){70});
	printf("\nSize is : %d\n",size);
	
	//printf("***front element : %d",q1->front->next->data);

	printf("\n\n*****clear queue****\n\n");
	q1->clear(q1);

	printf("\n\ncheck if queue is cleared or not by calling -> peek queue\n");
	
	d=q1->peek(q1);

	/*
	size=q1->enqueue(q1,(Data){16});
	printf("\nSize is : %d\n",size);
	*/

	printf("\n\nDelete Queue (free memory)\n\n");
	q1->delete(q1);
	return 0;

}
