  #include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node*next;
};
struct node*front=0;
struct node*rear= 0;
void enqueue(int x){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    if((rear==0)&&(front ==0))
    {
        front=rear=newnode;
        rear->next=front;
    }
    else{
        rear->next=newnode;
        rear= newnode;
        rear->next=front;

    }
}
void dequeue(){
    struct node*temp;
    temp =front;
    if (front==0&&rear==0){
        printf("underflow");
    }
    else if(front==rear)
    {
        front =rear=0;
        free(temp);
    }
    else{
        front=front->next;
        rear->next=front;
        free(temp);
    }
}
void peek(){
    if(front==0&&rear==0){
        printf("queue is empty");

    }
    else{
        printf("%d\n", front ->data);
    }
}
void display(){
    struct node*temp;
    temp=front;
     if(front==0&&rear==0){
        printf("queue is empty");

    }
     else
    {
      do
	{
	  printf (" %d", temp->data);
	  temp = temp->next;
	}
      while (temp != front);
    }
}
int main(){
    enqueue(69);
    enqueue(77);
    enqueue(80);
      printf ("Circular Queue: ");
  display ();
  printf ("\n");

  dequeue ();
  printf ("Circular Queue After dequeue: ");
  display ();
}