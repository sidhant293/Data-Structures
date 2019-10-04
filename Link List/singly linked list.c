#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct nodetype
		{
			int info;
			struct nodetype *next;
		}node;
		node *head;
void createemptylist(node **head)
			{
				*head=NULL;
			}
void traverseinorder(node *head)
		{
			while(head!=NULL)
			{
				printf("%d ",head->info);
				head=head->next;
			}
		}
void insertatbegining(node **head,int item)
	{
		node *ptr;
		ptr=(node*)malloc(sizeof(node));
		ptr->info=item;
		if(*head==NULL)
			ptr->next=NULL;
		else
			ptr->next=*head;
		*head=ptr;
	}

	node *searchunsortedlist(node *head, int item)
{
	while(head!=NULL)
    {
        if(head->info==item)
            return head;
        else
            head=head->next;
    }
}

void insertatend(node **head, int item)
	{
		node *ptr, *loc;
		 ptr=(node*)malloc(sizeof(node));
		ptr->info=item;
		ptr->next=NULL;
		if(*head==NULL)
			*head=ptr;
		else
		{
			loc=*head;
			while (loc->next!=NULL)
				loc=loc->next;
				loc->next=ptr;
		}
	}

node *searchinsortedlist(node *head, int item)
{
	while(head!=NULL)
	{
		if(head->info==item)
			return head;
		else if (item<head->info)
			return NULL;
		else
			head=head->next;
	}
	return NULL;
}

void traversereverseorder(node *head)
		{
			if(head!=NULL)
			{
				traversereverseorder(head->next);
				printf("%d ",head->info);
			}
		}

void insertafterelement(node *head, int item,int after)
{
	node *ptr, *loc;
	loc=searchunsortedlist(head,after);
	if(loc==NULL)
    {
        printf("\nnot found\n");
        return;
    }
	 ptr=(node*)malloc(sizeof(node));
	ptr->info=item;
	ptr->next=loc->next;
	loc->next=ptr;
}

void deletefrombegining( node **head)
{
	node *ptr;
	if(*head==NULL)
		return;
	else
	{
		ptr=*head;
		*head=(*head)->next;
		free(ptr);
	}
}

void deletefromend( node **head)
{
	node *ptr,*loc;
	if (*head==NULL)
		return;
	else if ((*head)->next==(node*) NULL)
		{
		ptr=*head;
		*head=NULL;
		free(ptr);
		}
	      else
		{
		loc=*head;
		ptr=(*head)->next;
		while(ptr->next!=NULL)
		       {
		          loc=ptr;
		          ptr=ptr->next;
		        }
		 loc->next=NULL;
	           free(ptr);
	            }
}

void deleteafterelement( node*head, int after)
{
	node *ptr, *loc;
	loc=searchunsortedlist(head,after);
	if(loc==(node*)NULL)   /*element after not found*/
		return;
	ptr=loc->next;
	loc->next=ptr->next;
	free(ptr);
}


void main()
{
    int item,ch,element,after;
    node *ele;// for search
    createemptylist(&head);
    while(1)
    {
        printf("\nenter choice\n");
        printf("1.exit\n2.insert at beg\n3.display\n4.search element unsorted\n5.insert at end\n6.search element sorted\n7.display reverse\n8.insert after node\n");
        printf("9.delete from beg\n10.delete from end\n11.delete after node\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:exit(0);
            break;
            case 2:{printf("enter element ");
                    scanf("%d",&item);
                    insertatbegining(&head,item);
                   }
            break;
            case 3:traverseinorder(head);
            break;
            case 4:{printf("enter element to be searched ");
                    scanf("%d",&element);
                    ele=searchunsortedlist(head,element);
                    printf("%d",ele->info);
                   }
            break;
            case 5:{printf("enter element ");
                    scanf("%d",&item);
                    insertatend(&head,item);
                    }
            break;
            case 6:{printf("enter element to be searched ");
                    scanf("%d",&element);
                    ele=searchinsortedlist(head,element);
                    printf("%d",ele->info);
                    }
            break;
            case 7:traversereverseorder(head);
            break;
            case 8:{printf("enter element ");
                    scanf("%d",&item);
                    printf("enter element after you want to insert ");
                    scanf("%d",&after);
                    insertafterelement(head,item,after);
                    }
            break;
            case 9:deletefrombegining(&head);
            break;
            case 10:deletefromend(&head);
            break;
            case 11:{printf("enter element after you want to insert ");
                    scanf("%d",&after);
                    deleteafterelement(head,after);
                     }
            break;
            default:printf("wrong choice");
        }
    }
}
