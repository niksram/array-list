#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void init_list(list_t *list)
{
	for(int i=0;i<SIZE;i++)
	{
		list->key[i]=0;
		list->next[i]=i+1;
	}
	list->next[SIZE-1]=-1;
	list->head=-1;
	list->fhead=0;
}

void insert_list(list_t *list, int elem)
{
	if(list->fhead!=-1)
	{
		list->key[list->fhead]=elem;
		int nexthead=list->next[list->fhead];
		if(list->head==-1)
		{
			list->head=list->fhead;
			list->next[list->head]=-1;
		}
		else if (elem<list->key[list->head])
		{
			list->next[list->fhead]=list->head;
			list->head=list->fhead;
		}
		else
		{
			int pres=list->head;
			int prev=-1;
			int flag=0;
			while(elem>list->key[pres] && list->next[pres]!=-1)
			{
				prev=pres;
				pres=list->next[pres];
				flag=1;
			}
			if(!flag)
			{
				list->next[pres]=list->fhead;
				list->next[list->fhead]=-1;
			}
			else if(list->next[pres]==-1 && elem>list->key[pres])
			{
				list->next[pres]=list->fhead;
				list->next[list->fhead]=-1;
			}
			else
			{
				list->next[list->fhead]=pres;
				list->next[prev]=list->fhead;
			}
		}
		list->fhead=nexthead;
	}
}

void delete_list(list_t *list,int elem)
{

	int pres=list->head,presf=list->fhead;
	int prev=-1;
	int flag=0,keystr;
	while(list->key[pres]!=elem && list->next[pres]!=-1)
	{
		prev=pres;
		pres=list->next[pres];
		flag=1;
	}
	if(list->next[pres]!=-1 || list->key[pres]==elem)
	{
		keystr=pres;
		if(!flag)
		{	
			list->head=list->next[pres];
		}
		else
		{
			list->next[prev]=list->next[pres];
		}
		
		list->next[keystr]=list->fhead;
		list->fhead=keystr;	
	}
}

void disp_list(const list_t *ptr_list)
{
	for(int i=0;i<SIZE;i++)
	{
		printf("%d %d\n",ptr_list->key[i],ptr_list->next[i]);
	}
	display(ptr_list);
}

void display(const list_t *list)
{
	int pres=list->head;
	if(pres==-1)
	{
		printf("EMPTY LIST!\n");
		return;
	}
	while(pres!=-1)
	{
		printf("%d ",list->key[pres]);
		pres=list->next[pres];
	}
	printf("\n\n");
}
