#ifndef LIST_H
#define LIST_H

#include "data.h"

/*
typedef struct Data
{
	int value;
	
}Data;
*/
typedef struct Node
{
	struct Node * next;
	struct Data data;
}Node;

typedef struct Queue
{
	int size;
	struct Node * front, * rear,*temp;
	int (* enqueue)(struct Queue * queue, Data value);
	struct Data * (* dequeue)(struct Queue * queue);
	struct Data * (* peek)(struct Queue * queue);
	void (* clear)(struct Queue * queue);
	void (* delete)(struct Queue * queue);

}Queue;

Queue * newQueue();
Node * newNode();
int enqueueData(struct Queue * queue, Data value);
struct Data * dequeueData(struct Queue * queue);
struct Data * peekQueue(struct Queue * queue);
void clearQueue(struct Queue * queue);
void deleteQueue(struct Queue * queue);


#endif
