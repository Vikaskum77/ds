#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
}*head,*tail;
void createdcll(){
    struct node *newnode;
    head =0;
    newnode =(struct node*)malloc(sizeof(struct node));
    printf("enter the dtat");
    scanf("%d", &newnode->data);
    if(head==0){
        head= tail= newnode;
        head->next= head;
        head->prev= head;

    }
    else{
        tail->next= newnode;
        newnode->prev =tail;
        newnode->next=head;
        head->prev=newnode;
        tail=newnode;

    }
     
    
}
void display() {
    struct node*temp;
    temp=head;
    
    
        while(temp!=tail)
        {
            printf("%d", temp->data);
            temp= temp->next;
        }
        printf("elements are : %d", temp->data);
    
     
}
int main() {

    createdcll();
    createdcll();
    display();
    createdcll();
    createdcll();
    display();
}