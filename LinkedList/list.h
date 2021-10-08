#ifndef LIST_H
#define LIST_H

typedef struct Data
{
	int value;
}Data;

typedef struct Node
{
	struct Node * prev, * next;
	struct Data data;
}Node;

typedef struct List
{
	int size;
	struct Node * head, * tail;
	void (* insert)(struct List * list, Data value);
	struct Data * (* read)(struct List * list,int index);
	struct List * (*join)(struct List *list1,struct List *list2);
	struct List **(*split)(struct List *slist);
}List;

List * newList();
Node * newNode();
void insertList(struct List * list, Data value);
struct Data * readData(struct List * list,int index);
struct List * joinList(struct List *list1,struct List *list2);
struct List ** splitList(struct List *slist);
#endif
