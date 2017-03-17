#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int info;
	struct node *next;
}node;
node *head;
void cel();//cel-check empty list
void ins(int val);//ie-insert at end
void de();//de-delete at end
void db();//db-delete at beginning
void dt(int t);//dt-delete target
void dat(int t);//dat-delete after target
void dbt(int t);//dbt-delete before target
void del();
void display();
int main()
{

	cel();
	int c=0,val,t,n;
	printf("Enter the size of linked list-");
	scanf("%d",&n);
	printf("\nEnter the elements of linked list-");
	while(n--)
	{
		scanf("%d",&val);
		ins(val);
	}
	printf("\nThe original linked list-");
	display();
	printf("Enter 1-Delete at beginning, 2-Delete at end, 3-Delete target, 4-Delete after target, 5-Delete before target 6-Delete list and any other number to exit.");
	scanf("%d",&c);
	while(c<=6)
    	{
        	switch(c)
        	{
	            case 1:
        	    db();
        	    display();
        	    break;
        	    case 2:
        	    de();
        	    display();
        	    break;
        	    case 3:
        	    printf("Enter the target to be deleted");
        	    scanf("%d",&t);
        	    dt(t);
        	    display();
        	    break;
        	    case 4:
        	    printf("Enter the target after which node is to be deleted-");
        	    scanf("%d",&t);
        	    dat(t);
        	    display();
        	    break;
		    case 5:
        	    printf("Enter the target before which node is to be deleted-");
        	    scanf("%d",&t);
        	    dbt(t);
        	    display();
        	    break;
        	    case 6:
        	    del();
        	    display();
        	    break;
        	    default :
        	    break;
        	}
        	printf("Enter 1-Delete at beginning, 2-Delete at end, 3-Delete target, 4-Delete after target, 5-Delete before target 6-Delete list and any other number to exit.");
        	scanf("%d",&c);
    	}
	return 0;
}
void cel()
{
	head=NULL;
}
void ins(int val)
{
	node *p,*q=head;
	p=(node *)malloc(sizeof(node));
	p->info=val;
	if(head==NULL)
	{
		p->next=head;
		head=p;
	}
	else
	{
		while(q->next!=NULL)
		{
			q=q->next;
		}
		q->next=p;
		p->next=NULL;
	}
}
void db()
{
	node *p;
	p=head;
	head=head->next;
	p->next=NULL;
	free(p);
	printf("The list after deletion in the beginning is-\n");
}
void de()
{
	node *p=head,*q=p->next;
	while(q->next!=NULL)
	{
		p=p->next;
		q=q->next;
	}
	p->next=NULL;
	free(q);
	printf("The list after deletion at end is-\n");
}
void dat(int t)
{
	node *q,*r;
	q=head->next;
	r=head;
	while((r->info!=t)&&((q->next!=NULL)))
	{
		r=r->next;
		q=q->next;
	}
	if(q==NULL)
		printf("target not found");
	else
    {
		r->next=q->next;
		q->next=NULL;
		printf("\nvalue deleted is  %d \n",q->info);
		free(q);
	}
	printf("The list after deletion after target is-\n");
}
void dbt(int t)
{
	node *q,*r;
	q=head->next;
	r=head;
	while((q->next->info!=t)&&((q->next!=NULL)))
	{
		r=r->next;
		q=q->next;
	}
	if(q==NULL)
		printf("target not found");
	else
    {
		r->next=q->next;
		q->next=NULL;
		printf("\nvalue deleted is  %d \n",q->info);
		free(q);
	}
	printf("The list after deletion before target is-\n");
}
void dt(int t)
{
    node *p=head,*q;
    while(p->next->info!=t&&p!=NULL)
    {
        p=p->next;
    }
    if(p==NULL)
    {
	printf("Target NOT found\n");
    }
    else
    {
	q=p->next;
	p->next=p->next->next;
    }
    free(q);
    printf("The list after deletion of target is-\n");
}
void del()
{
    node *p=head;
    while(head!=NULL)
    {
        head=head->next;
        p->next=NULL;
        printf("Node deleted %d\t",p->info);
        free(p);
        p=head;
    }
}
void display()
{
	node *p=head;
	if(head==NULL)
    {
        printf("\nEmpty list");
    }
    else
    {
	while(p!=NULL)
	{
		printf("%d\t",p->info);
		p=p->next;
	}
    }
	printf("\n");
}

OUTPUT

student@students-OptiPlex-755:~$ gedit llstack.c
student@students-OptiPlex-755:~$ gcc lldelete.c
student@students-OptiPlex-755:~$ ./a.out
Enter the size of linked list-8

Enter the elements of linked list-1
2
3
4
5
6
7
8

The original linked list-1	2	3	4	5	6	7	8
Enter 1-Delete at beginning, 2-Delete at end, 3-Delete target, 4-Delete after target, 5-Delete before target 6-Delete list and any other number to exit.1
The list after deletion in the beginning is-
2	3	4	5	6	7	8	
Enter 1-Delete at beginning, 2-Delete at end, 3-Delete target, 4-Delete after target, 5-Delete before target 6-Delete list and any other number to exit.2
The list after deletion at end is-
2	3	4	5	6	7	
Enter 1-Delete at beginning, 2-Delete at end, 3-Delete target, 4-Delete after target, 5-Delete before target 6-Delete list and any other number to exit.3
Enter the target to be deleted4
The list after deletion of target is-
2	3	5	6	7	
Enter 1-Delete at beginning, 2-Delete at end, 3-Delete target, 4-Delete after target, 5-Delete before target 6-Delete list and any other number to exit.4
Enter the target after which node is to be deleted-5

value deleted is  6 
The list after deletion after target is-
2	3	5	7	
Enter 1-Delete at beginning, 2-Delete at end, 3-Delete target, 4-Delete after target, 5-Delete before target 6-Delete list and any other number to exit.5
Enter the target before which node is to be deleted-5

value deleted is  3 
The list after deletion before target is-
2	5	7	
Enter 1-Delete at beginning, 2-Delete at end, 3-Delete target, 4-Delete after target, 5-Delete before target 6-Delete list and any other number to exit.6
Node deleted 2	Node deleted 5	Node deleted 7	
Empty list
Enter 1-Delete at beginning, 2-Delete at end, 3-Delete target, 4-Delete after target, 5-Delete before target 6-Delete list and any other number to exit.9

