
#ifndef LIST_H
#define LIST_H
#define SIZE 5
typedef struct list_t
{
	int key[SIZE];
	int next[SIZE];
	int head,fhead;
}list_t;

void init_list(list_t *list);
void insert_list(list_t *list, int elem);
void disp_list(const list_t *ptr_list);
void display(const list_t *list);
void delete_list(list_t *list,int elem);
#endif