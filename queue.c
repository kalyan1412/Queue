

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *front=NULL,*rear=NULL;

void push();
void pop();
void display();


int main()
{
    int choice;
    while(1)
    {
        printf("-------------\n");
        printf("1.push\n");
        printf("2.POP\n");
        printf("3.DISPLAY\n");
        printf("4.EXIT\n");

        printf("Enter the choice=");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}


void push()
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data to insert=");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(front==NULL || rear==NULL)
    {
        rear=temp;
        front=temp;
    }

    else
    {
        rear->link=temp;
        rear=temp;
    }
}

void pop()
{
    struct node *temp;
    if(front==NULL)
        printf("No elements to delete\n");
    else
    {
        printf("Delete element is %d\n",front->data);
        temp=front;
        front=temp->link;
        temp->link=NULL;
        free(temp);
    }   
}

void display()
{
    struct node *temp;
    temp=front;
    if(temp==NULL)
        printf("No elements to display\n");
    else
    {
        while(temp!=NULL)
        {
            printf("%d->",temp->data);
            temp=temp->link;
        }
    }
}