 #include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node* next;
    struct node* prev;
} *top;


void push(int e)
{
	
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	if (!temp)
	{
	    printf("We cannot allocate memory");
	    return;
	}
	
	printf("Enter element which you want to push\n");
	
	scanf("%d", &e);
	temp->data = e;
	if (top == NULL)
	{
	    temp->next = NULL;
	    temp->prev = NULL;
	    top = temp;
	}
	else
	{
	    top->next = temp;
	    temp->prev = top;
	    top = temp;
	}
}
int pop()
{
    if (top == NULL)
    {
    printf("stack is empty. We have nothing to pop\n");
    return 0;
    
    }
    if(top->next == NULL && top->prev ==NULL){
        int a = top->data;
        struct node *temp;
        temp = top;
        top= NULL;
        free(temp);
        return a;
    }
    struct node *temp;
	temp = top;
	top = top->prev;
	top->next = NULL;
	free(temp);
}	
void display()
{
    struct node *temp = top;
    if (temp==NULL)
    {
        printf("Stack is empty\n");
        return;
    }
     while(temp!= NULL)
    { 
        printf(" %d  ",temp->data);
        temp = temp->prev;
    }
     printf("\n");
}
	
int main()
{ int x;
push(x);
 

  
 push(x);
  
 push(x);
 pop();
 display();

     
       
    return 0;
    
}