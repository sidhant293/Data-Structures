#include<stdio.h>
typedef struct nodetype
		{
			struct nodetype *prev;
			int info;
			struct nodetype *next;
		}node;
node *head,*tail;
void createemptylist(node **head, node **tail)
			{
				*head=NULL; *tail=NULL;
			}
void traverseinorder(node *head)
    {
        while(head!=NULL)
        {
            printf("%d ",head->info);
            head=head->next;
        }
    }
void traversereverseorder(node *tail)
		{
			if(tail!=NULL)
			{
				printf("%d ",tail->info);
				tail=tail->prev;
			}
		}
node *search (node *head, int item)
{
	while(head!=NULL)
	{
		if(head->info==item)
			return head;
		head=head->next;
	}
	return NULL;
}
void insertatbegining (node **head, node **tail, int item)
	{
		node *ptr;
		ptr=(node*)malloc(sizeof(node));
		ptr->info=item;
		if(*head==NULL)
			{ptr->next=ptr->prev=NULL;
			*head=*tail=ptr;}
		else
		{
			ptr->prev=NULL;
			ptr->next=*head;
			(*head)->prev=ptr;
			*head=ptr;
		}
}
void insertatend (node **head, node **tail, int item)
	{
		node *ptr;
		ptr=(node*)malloc(sizeof(node));
		ptr->info=item;
		if(*head==NULL)
			{ptr->next=ptr->prev=NULL;
			*head=*tail=ptr;}
		else
		{
			ptr->next=NULL;
			ptr->prev=*tail;
			(*tail)->next=ptr;
			*tail=ptr;
		}
}
void insertafterelement (node **head, node **tail, int item, int after)
	{
		node *ptr, *loc;
		ptr=head;
		loc=search(ptr,after);
		if(loc==NULL)
			return;
		ptr=(node*)malloc(sizeof(node));
		ptr->info=item;
		if(loc->next==NULL)
		{
			ptr->next=NULL;
			loc->next=ptr;
			ptr->prev=*tail;
			*tail=ptr;
		}
		else
		{
			ptr->prev=loc;
			ptr->next=loc->next;
			(loc->next)->prev=ptr;
			loc->next=ptr;
		}
}
void insertbeforeelement (node **head, node **tail, int item, int before)
	{
		node *ptr, *loc;
		ptr=head;
		loc=search(ptr,before);
		if(loc==NULL)
			return;
		ptr=(node*)malloc(sizeof(node));
		ptr->info=item;
		if(loc->prev==NULL)
		{
			ptr->prev=NULL;
			loc->prev=ptr;
			ptr->next=*head;
			*head=ptr;
		}
		else
		{
			ptr->prev=loc->prev;
			ptr->next=loc;
			(loc->prev)->next=ptr;
			loc->prev=ptr;
		}
}
void deletefrombegining( node **head, node **tail)
{
	node *ptr;
	if(*head==NULL)
		return;
	ptr=*head;
	if(*head==*tail)       /*one element only*/
		*head=*tail=NULL;
	else
	{
		(ptr->next)->prev=NULL;
		*head=ptr->next;
	}
	free(ptr);
}
void deletefromend( node **head, node **tail)
{
	node *ptr;
	if(*head==NULL)
		return;
	ptr=*tail;
	if(*head==*tail)       /*one element only*/
		*head=*tail=NULL;
	else
	{
		(ptr->prev)->next=NULL;
		*tail=ptr->prev;
	}
	free(ptr);
}
void deleteafterelement (node **head, node **tail,int after)
	{
		node *ptr, *loc;
		ptr=head;
		loc=search(ptr,after);
		if(loc==NULL)
			return;
		else if((loc->next)->next==NULL)
			{
			ptr=loc->next;
			loc->next=NULL;
			*tail=loc;
			free(ptr);
			}
            else
			{
			ptr=loc->next;
			loc->next=ptr->next;
			(ptr->next)->prev=loc;
			free(ptr);
			}
}
void deletebeforelement (node **head, node **tail, int before)
	{
		node *ptr, *loc;
		ptr=head;
		loc=search(ptr,before);
		if(loc==NULL)
			return;
		else if((loc->prev)->prev==NULL)
			{
			ptr=loc->prev;
			loc->prev=NULL;
			*head=loc;
			free(ptr);
			}
            else
			{
			ptr=loc->prev;
			loc->prev=ptr->prev;
			(ptr->prev)->next=loc;
			free(ptr);
			}
}
void main()
{
   int ch,item,after;
   createemptylist(&head,&tail);
   while(1)
   {
       printf("\n1.insert at beg\n2.insert at end\n3.insert after element\n4.insert before element \n");
       printf("5.traverse\n6.traverse rev\n7.exit");
       printf("\n8.delete beg\n9.del end\n10.del after\n11.del before\n enter choice ");
       scanf("%d",&ch);
       switch(ch)
       {
       case 1:printf("\nenter element ");
       scanf("%d",&item);
       insertatbegining(&head,&tail,item);
       break;
       case 2:
        printf("\nenter element ");
       scanf("%d",&item);
       insertatend(&head,&tail,item);
       break;
       case 3:
        printf("\nenter element ");
       scanf("%d",&item);
       printf("enter position ");
       scanf("%d",&after);
       insertafterelement(&head,&tail,item,after);
       break;
       case 4:
        printf("\nenter element ");
       scanf("%d",&item);
       printf("enter position ");
       scanf("%d",&after);
       insertbeforeelement(&head,&tail,item,after);
       break;
       case 5:traverseinorder(head); break;
       case 6:traversereverseorder(tail); break;
       case 7:exit(0); break;
       case 8:deletefrombegining(&head,&tail);
       break;
       case 9:deletefromend(&head,&tail);
       break;
       case 10:
        printf("enter loc ");
        scanf("%d",&after);
        deleteafterelement(&head,&tail,after);
        break;
       case 11:
        printf("enter loc ");
        scanf("%d",&after);
        deletebeforelement(&head,&tail,after);
        break;
        default:printf("wrong choice");
       }
   }
}
