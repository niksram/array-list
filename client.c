//#define SIZE is given as 5 which can be modidfied in the header file
#include <stdio.h>
// avoid the problem of multiple inclusion at compile time
#include "list.h"
#include "list.h"

int main()
{
	//#define SIZE is given as 5 which can be modidfied in the header file
	printf("#define SIZE is given as 5 which can be modidfied in the header file\n\n");
	list_t l;
	init_list(&l);
	int i,j,flag=1;
	while(flag)
	{
		printf("\ninsert=1, delete=2, display=3, default=exit()\n");
		scanf("%d",&j);
		switch(j)
		{
			case 1:
			{
				scanf("%d",&i);
				insert_list(&l,i);
				break;
			}
			case 2:
			{
				scanf("%d",&i);
				delete_list(&l,i);
				break;
			}
			case 3:
			{
				printf("displaying\n");
				disp_list(&l);
				break;
			}
			default:
			{
				printf("END\n");
				flag=0;
			}
		}
	}	
}
