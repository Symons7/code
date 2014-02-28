/*************************************************************************
	> File Name: revert.c
	> Author: simon_5s
	> Mail:  simon_5s@gmail.com
	> Created Time: Fri 07 Feb 2014 05:02:55 PM HKT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct _node
{
	int data;
	struct _node *next;
}node;

node *createnode()
{
	node *pNode;

	pNode = (node *)malloc(sizeof(node));
	pNode->data = 0;
	pNode->next = NULL;

	return pNode;
}

int addnode(node *head, int data)
{
	node *pNode;

	if(head == NULL)
		return -1;

	pNode = (node *)malloc(sizeof(node));
	pNode->data = data;
	pNode->next = head->next;
	head->next = pNode;

	return;
}

int deletenode(node *head)
{
	node *pNode;

	if(head == NULL)
		return -1;

	while(head->next != NULL)
	{
		pNode = head->next;
		head->next = head->next->next;
		free(pNode);
	}

	free(head);
	return;
}

void printnodes(const node *head)
{
	while(head->next != NULL)
	{
		head = head->next;
		printf("%d ", head->data);
	}
	printf("\n");
	return;
}

int revert(node *head)
{
	node *p1, *p2, *p3;

	if(head == NULL || head->next == NULL || head->next->next == NULL)
		return -1;

	p1 = head->next;
	p2 = p1->next;
	p3 = p2->next;
	p1->next = NULL;

	while(p3 != NULL)
	{
		p2->next = p1;
		p1 = p2;
		p2 = p3;
		p3 = p3->next;
	}
	p2->next = p1;
	head->next = p2;

	return;
}

void main()
{
	node *head;
	int i, data;

	head=createnode();//head has no real data
	for(i=0; i<20; i++)
	{
		data = rand() % 100;
		addnode(head, data);
	}
	
	printnodes(head);
	revert(head);
	printnodes(head);
	deletenode(head);
	head = NULL;

	return;
}

