#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Queue * newQueue()
{
	Queue * q = (Queue *)malloc(sizeof(Queue));
	
	q->size=0;
	q->front=NULL;
	q->rear=NULL;
	q->temp=NULL;
	q->enqueue = enqueueData;
	q->dequeue = dequeueData;
	q->peek = peekQueue;
	q->clear = clearQueue;
	q->delete = deleteQueue;

	return q;
}

Node * newNode(Data d)
{
		Node * node =(Node *)malloc(sizeof(Node));
		node->next = NULL;
		node->data = d;
		return node;
}

int enqueueData(Queue * queue, Data value)
{
	Node * n = newNode(value);
	if(queue->front == NULL && queue->rear == NULL)
	{
		queue->front=n;
		queue->rear=n;
	}
	else
	{
		queue->rear->next=n;
		queue->rear=n;	
	}
	queue->size++;
	return queue->size;
}

Data * peekQueue(Queue * queue)
{
	if(queue->front == NULL)
	{
		printf("\nQueue is Empty\n");
		return NULL;
	}
	return &(queue->front->data);
}

Data * dequeueData(struct Queue * queue)
{
	if(queue->size > 0)
	{
		queue->size--;
		
		if(queue->front!=NULL && queue->rear!=NULL)
		{
			queue->temp = queue->front;
			if(queue->temp == queue->front && queue->temp == queue->rear)
			{

				return &(queue->temp->data);
			}
			else if(queue->temp == queue->front)
			{
				if(queue->temp->next == queue->rear)
				{
					queue->front=queue->rear=queue->temp->next;
				}
				else 
				{

					queue->front=queue->temp->next;
		
				}

				return &(queue->temp->data);

			}
			
		}
	}
	
}


void clearQueue(Queue * queue)
{
	Node * current = queue->front;
	while(queue->size != 0)
	{	
		current = current->next;
		free(queue->front);
		queue->front = current;
		queue->size--;
	}
	free(current);


}

void deleteQueue(Queue * queue)
{
	free(queue->temp);
	free(queue);
}
