

// Circular Queue

#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

int front=-1,rear=-1;

void push(int *);
void pop(int *);
void display(int *);
int is_full(int *);
int is_empty(int *);

int main()
{
    int arr[SIZE],choice,k=-1;
    while(1)
    {
        printf("-----------\n");
        printf("1.PUSH\n");
        printf("2.POP\n");
        printf("3.DISPLAY\n");
        printf("4.IS_FULL\n");
        printf("5.IS_EMPTY\n");
        printf("6.EXIT\n");
        printf("Enter the choice=");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                push(arr);
                break;
            case 2:
                pop(arr);
                break;
            case 3:
                display(arr);
                break;
            case 4:
                 k=is_full(arr);
                 if(k==1)
                    printf("Queue is full\n");
                 else
                    printf("Queue is not full\n");
                break;
            case 5:
                k=is_empty(arr);
                if(k==1)
                    printf("Queue is Empty\n");
                else
                    printf("Queue is not empty\n");
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");

        }
    }
    return 0;
}

void push(int *p)
{
    int element;
    if((rear+1==SIZE && front==0) || (front==rear+1))
        printf("Queue is full\n");
    else
    {
        if(front==-1)
            front=0;
        printf("Enter the element you want to insert=");
        scanf("%d",&element);
        rear=(rear+1)%SIZE;
        p[rear]=element;
    }
}

void pop(int *p)
{
    if(front==-1)
        printf("Queue is empty\n");
    else
    {
        printf("POP Elemet is %d\n",p[front]);
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
            front=(front+1)%SIZE;
    }
}


int is_full(int *p)
{

    if((rear+1==SIZE && front==0) || (front==rear+1))
        return 1;
    else
        return -1;

}


int is_empty(int *p)
{
    if(front==-1)
        return 1;
    else
        return -1;
}

void display(int *p)
{
    int i;
    if(front==-1)
        printf("Queue is Empty\n");
    else
    {
        printf("Front=%d\n",front);
        printf("Items:");
        for(i=front;i!=rear;i=(i+1)%SIZE)
            printf("%d->",p[i]);
        printf("%d",p[i]);
    }
}