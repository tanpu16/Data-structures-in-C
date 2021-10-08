
#include "list.h"
#include "list.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/********************************************************************/
/*    DO NOT ALTER ANY OF THE THE DRIVER CODE 	                    */
/********************************************************************/

int main(){
	int i = 0;
	srand(time(NULL));

	printf("\t-----------------------------------\n");
	printf("\t-          Part2 : Lists        -\n");
	printf("\t-----------------------------------\n");

	printf("\n\t=========Test #11: Creating your Linked List===========\n\n");
	List * list = newList();
	assert(list->head == NULL && list->tail == NULL);
	printf("\n\t\tTest #11: Passed ...\n\n");

	printf("\n\t=========Test #12: Linked List Insertion===========\n\n");
	int index = 0,size;
	//add elements to the list
	for(index = 0 ; index < 10 ; index++ ){
		list->insert(list, (Data){index+1});
	}


	fprintf(stderr, "\n\t\tTest #2: Passed ...\n\n");

	printf("\n\t=========Test #13: Linked List Read===========\n\n");
	


	for(index=0;index<list->size;index++)
	{
		Data * d = list->read(list,index);
		printf("-%d-",*d);
	}
	
	printf("\n\t\tTest #3: Passed ...\n\n");

	//list->delete(list);
	printf("\n\n******** Testing Join operation ********\n\n");
	List * list1=newList();
	List * list2=newList();

	for(index = 0 ; index < 5 ; index++ ){
		int value = rand() % 30;
		list1->insert(list1, (Data){value});
	}

	printf("\n\nPrinting list 1 : \n ");

	for(index=0;index<list1->size;index++)
	{
		Data * d = list1->read(list1,index);
		printf("%d-",*d);
	}
	for(index = 0 ; index < 5 ; index++ ){
		int value = rand() % 20;
		list2->insert(list2, (Data){value});
	}
	printf("\n\nPrinting list 2 : \n ");
	for(index=0;index<list2->size;index++)
	{
		Data * d = list2->read(list2,index);
		printf("%d-",*d);
	}

	List * mergerList=newList();
	mergerList=mergerList->join(list1,list2);
	size = list1->size + list2->size;
	
	printf("\n\nPrinting Merged List : \n");

	for(index=0;index<size;index++)
	{
		Data * d = mergerList->read(mergerList,index);
		printf("%d-",*d);
	}


	printf("\n\n\n Join : Testing corner cases \n\n");

	printf("\n CASE 1 : both lists are null : \n");

	List *nlist1 = newList();
	List *nlist2 = newList();

	List *n_mlist=newList();
	n_mlist=n_mlist->join(nlist1,nlist2);
	
	printf("\n CASE 2 : One of the list is null : \n");

	List *clist1 = newList();
	List *clist2 = newList();
	
	for(index = 0 ; index < 5 ; index++ ){
		int value = rand() % 20;
		clist2->insert(clist2, (Data){value});
	}

	printf("\n\nList 1 is Null and Printing List 2 : \n");

	for(index=0;index<clist2->size;index++)
	{
		Data * d = clist2->read(clist2,index);
		printf("%d-",*d);
	}




	List *n_clist=newList();
	n_clist=n_clist->join(clist1,clist2);
	size = clist1->size + clist2->size;

	printf("\n\n Printing Merged list (should be list 2) \n");

	for(index=0;index<size;index++)
	{
		Data * d = n_clist->read(n_clist,index);
		printf("%d-",*d);
	}

		
	printf("\n\n");

	printf("\n\n******* Testing Split Operation *********\n\n");

	List * slist = newList();

	for(index = 0 ; index < 10 ; index++ ){
		int value = rand() % 50;
		slist->insert(slist, (Data){value});
	}
	printf("\nPrinting List to be split : \n");

	for(index=0;index<slist->size;index++)
	{
		Data * d = slist->read(slist,index);
		printf("%d-",*d);
	}

	printf("\n\nAfter Split\n");
	
	//slist->split(slist);
	
	List **rlist = malloc(sizeof(List*)*2);
	rlist=slist->split(slist);

	List *olist = newList();
	List *elist = newList();

	olist = rlist[1];
	elist = rlist[0];

	printf("\nPrinting first List (odd place) : \n");

	for(index=0;index<olist->size;index++)
	{
		Data * d = olist->read(olist,index);
		printf("%d-",*d);
	}

	printf("\n\nPrinting second List (even place) : \n");

	for(index=0;index<elist->size;index++)
	{
		Data * d = elist->read(elist,index);
		printf("%d-",*d);
	}


	printf("\n\n\nSplit -- Testing Corner case -- Input List is empty\n");
	List * n_slist = newList();


	printf("\n\ncalling split function \n");
	
	n_slist->split(n_slist);

	printf("\n\n");

	return 0;
}
