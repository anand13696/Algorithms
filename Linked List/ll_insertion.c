#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node;
node* newNode(int data);
node* ib(node *head,int val);//ib-insert before target
node* iat(node *head,int t,int val);//iat-insert after target
node* ibt(node *head,int t,int val);//ibt-insert before target
node* ie(node *head,int val);//ie-insert at end
void display(node *head);
int main()
{
	node *head=NULL;
	int c=0,val,t;
	printf("Enter 1-Insert at beginning, 2-Insert at end, 3-Insert after target, 4-Insert before target and any other number to exit.");
	scanf("%d",&c);
	while(c<=4)
    {
        switch(c)
        {
            case 1:
            printf("Enter the first value-");
            scanf("%d",&val);
            head=ib(head,val);
            display(head);
            break;
            case 2:
            printf("Enter the last value-");
            scanf("%d",&val);
            head=ie(head,val);
            display(head);
            break;
            case 3:
            printf("Enter the value to be inserted after and the target-");
            scanf("%d%d",&val,&t);
            head=iat(head,t,val);
            display(head);
            break;
            case 4:
            printf("Enter the value to be inserted before and the target-");
            scanf("%d%d",&val,&t);
            head=ibt(head,t,val);
            display(head);
            break;
            default :
            break;
        }
        printf("Enter 1-Insert at beginning, 2-Insert at end, 3-Insert after target, 4-Insert before target and any other number to exit.");
        scanf("%d",&c);
    }
	return 0;
}
node* newNode(int data)
{
    node* p=(node*)malloc(sizeof(node));
    p->data=data;
    p->next=NULL;
    return p;
}
node* ib(node* head,int data)
{
    if(head==NULL)
    {
        head=newNode(data);
    }
    else
    {
        node *q=newNode(data);
        q->next=head;
        head=q;
    }
    return head;
}
node* ie(node* head,int data)
{
    if(head==NULL)
        head=newNode(data);
    else
    {
        node *q=newNode(data);
        node *p=head;
        while(p->next!=NULL)
            p=p->next;
        p->next=q;
    }
    return head;
}
node* iat(node* head,int t,int data)
{
    if(head==NULL)
    {
        head=newNode(data);
    }
    else
    {
        node *q=newNode(data);
        node *p=head;
        while(p->data!=t&&p!=NULL)
        {
            p=p->next;
        }
        if(p==NULL)
            printf("Target NOT found.\n");
        else
        {
            q->next=p->next;
            p->next=q;
        }
    }
    return head;
}
node* ibt(node* head,int t,int data)
{
    if(head==NULL)
        head=newNode(data);
    else
    {
        node *q=newNode(data);
        node *p=head;
        if(head->data==t)
        {
            q->next=head;
            head=q;
        }
        else
        {
            while(p->next->data!=t&&p!=NULL)
            {
                p=p->next;
            }
            q->next=p->next;
            p->next=q;
        }
    }
    return head;
}
void display(node *head)
{
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}

OUTPUT

student@students-OptiPlex-755:~$ gedit ll.c
student@students-OptiPlex-755:~$ gcc ll.c
student@students-OptiPlex-755:~$ ./a.out
Enter 1-Insert at beginning, 2-Insert at end, 3-Insert after target, 4-Insert before target and any other number to exit.1
Enter the first value-5
The list after insertion in the beginning is-
5	
Enter 1-Insert at beginning, 2-Insert at end, 3-Insert after target, 4-Insert before target and any other number to exit.2
Enter the last value-3
The list after insertion at end is-
5	3	
Enter 1-Insert at beginning, 2-Insert at end, 3-Insert after target, 4-Insert before target and any other number to exit.3
Enter the value to be inserted after and the target-4 3
The list after insertion after target is-
5	3	4	
Enter 1-Insert at beginning, 2-Insert at end, 3-Insert after target, 4-Insert before target and any other number to exit.4
Enter the value to be inserted before and the target-9 4
The list after insertion before target is-
5	3	9	4	
Enter 1-Insert at beginning, 2-Insert at end, 3-Insert after target, 4-Insert before target and any other number to exit.7
