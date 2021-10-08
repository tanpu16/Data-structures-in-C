#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

List * newList()
{
	List * lt = malloc(sizeof(List));
	
	lt->size=0;
	lt->head=NULL;
	lt->tail=NULL;
	
	lt->insert = insertList;
	lt->read = readData;
	lt->join = joinList;	
	lt->split = splitList;
	//lt->delete = deleteList;
	return lt;
}

Node * newNode(Data d)
{
		Node * node = malloc(sizeof(Node));
		node->next = NULL;
		node->prev = NULL;
		node->data = d;
		
		return node;
}

void insertList(List * list, Data value)
{
	//printf("\n index = %d  data = %d \n",index,value);
	Node * n = newNode(value);
	if(list->head == NULL)
	{
		list->head=n;
		list->tail=n;
	}
	else
	{
		list->tail->next=n;
		n->prev=list->tail;
		list->tail=n;	
	}
	list->size++;

}

List * joinList(List *list1,List *list2)
{
	List *temp;
	if(list1->head==NULL && list2->head==NULL) 
	{
		printf("\nBoth Lists are NULL\n");
		return NULL;
	}

	if(list1->head==NULL) return list2;
	if(list2->head==NULL) return list1;
	

	list1->tail->next = list2->head;
	list2->head->prev= list1->tail;
	temp->tail = list2->tail;
	temp->head = list1->head;

	return temp;
}

List ** splitList(List *slist)
{

	if(slist->head==NULL)
	{
		printf("\nList is empty\n");
	}

	List *elist = newList();
	List *olist = newList();

	Node *c;
	int i;

	for(i =1, c = slist->head ; c!=NULL;i++,c=c->next)
	{
		if(i%2==0)
			elist->insert(elist,c->data);
		else
			olist->insert(olist,c->data); 
	
	}

	List **rlist = malloc(sizeof(List*)*2);
	rlist[0] = elist;
	rlist[1] = olist;

	return rlist;	
	
}

Data * readData(List * list, int index)
{

	int count=0;
	Node *current = list->head;
	while(count<index)
	{
		current = current->next;
		count++;

	}
	return &(current->data);
}


