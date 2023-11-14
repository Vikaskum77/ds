#include<stdio.h>
#include<stdlib.h>
#define n 5
int queue[n];
int front = -1;
int rear = -1;

int enqueue(int x)
{
    if (front==-1&& rear ==-1)
    {
        front = rear =0;
        queue[rear] = x;
    }
    else if((rear +1)%n==front)
    {
        printf("queue is empty");
    }
    else {
        rear = (rear+1)%n;
        queue[rear]= x;
    }



}
void dequeue()
{
    if(front==-1&&rear==-1){
        printf("queue is empty\n");
    }
    else if(front ==rear)
    {
        front =rear =-1;
    }
    else
    {
        printf("\nthe dequeued element is %d\n", queue[front]);

        front =(front+1)%n;

    }

}
void display(){ for (int i = front;i<=rear;i++)
printf(" %d\t", queue[i]);

    
}
int main() {
    enqueue(2);
    enqueue(20);
    enqueue(22);
    display();
    dequeue();
    display();

return 0;
}