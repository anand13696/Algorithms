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
void rev(node *p);
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
	rev(head);
	display();
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
void rev(node *p)
{
	if(p->next==NULL)
	{
		head=p;
		return;
	}
	rev(p->next);
	node *q=p->next;
	q->next=p;
	p->next=NULL;
    	printf("revese list\n");
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

student@students-OptiPlex-755:~$ gcc llreverse.c
student@students-OptiPlex-755:~$ ./a.out
Enter the size of linked list-5

Enter the elements of linked list-1
2
3
4
5

The original linked list-1	2	3	4	5	
revese list
5	4	3	2	1
