#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
     
};
struct node*front=NULL;
 struct node*rear=NULL;
 void enqueue(int x){
    struct node *newnode;
    newnode =(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    if(front==0&&rear==0){
        front = rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
    
 }
 void display(){
    struct node*temp;
    if(front==0&&rear==0)
    {
        printf("queue is empty");
    }
    else {
        temp=front;
        while(temp!=NULL)
        {
            printf("enqueue element is: %d\n", temp->data);
            temp=temp->next;
        }
    }
     
 }
 void dequeue(){
    struct node *temp;
    temp=front;
    if(front==0&&rear==0){
        printf("queue is empty");
    }
    else{
        printf("the dequeued element is :%d\n", front ->data);
        front= front->next;
        free(temp);
    }
 }
   void peek(){
    if(front==0&&rear==0){
        printf("queue is empty");

    }
    else{
        printf("peek element is : %d\n", front->data);
    }
   }
   int main(){
    enqueue(5);
    enqueue(10);
    enqueue(-3);
    display();
    dequeue();
    peek();
   }