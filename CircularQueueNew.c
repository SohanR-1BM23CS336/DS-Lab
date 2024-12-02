
#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

int isFull(){

    return (front == 0 && rear == MAX-1) || (front == rear+1);
}

int isEmpty(){
    return front == -1 && rear == -1;
}


void insert(int element){

    if(isFull())
        printf("\nQueue is Full");
    else
    if(front == -1 && rear == -1){
        front = 0;
        rear = 0;
        queue[rear] = element;
    }
    else{
        rear = (rear+1)%MAX;
        queue[rear] = element;
    }
}

void delete(){

    if(isEmpty())
        printf("\nQueue is Empty");
    else
    if(front == rear){
        printf("\nElement %d deleted",queue[front]);
        front = -1;
        rear = -1;
    }
    else{
        printf("\nElement %d deleted",queue[front]);
        front = (front+1)%MAX;
    }
}

void display(){

    if(isEmpty())
        printf("\nQueue is Empty");
    else{

        int newfront = front;
        while(newfront != rear){

            printf("%d ",queue[newfront++]);
        }
        printf("%d ",queue[rear]);
    }
}


int main(){

    int choice;

    int element;

    while(1){

            printf("\nEnter your choice: ");
            scanf("%d",&choice);

            switch(choice){

                case 1:printf("\nEnter the element: ");
                        scanf("%d",&element);
                        insert(element);
                        break;

                case 2:
                        delete();
                        break;

                case 3:
                        display();
                        break;
                case 4:
                        exit(0);

            }
    }

    return 0;
}







