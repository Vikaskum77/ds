 #include<stdio.h>  
#include<stdlib.h>  
void create(int);  
void traverse();  
struct node  
{  
    int data;  
    struct node *next;  
};  
struct node *head;  
int main ()  
{   create(10);
     create(1100);
     create(103);
     create(100);
     traverse();
}  
void create(int item)  
    {  
        struct node *ptr = (struct node *)malloc(sizeof(struct node *));  
        if(ptr == NULL)  
        {  
            printf("\nOVERFLOW\n");  
        }  
        else  
        {  
            ptr->data = item;  
            ptr->next = head;  
            head = ptr;  
            printf("\nNode inserted\n");  
        }  
          
    }  
void traverse()  
    {  
        struct node *ptr;     
        ptr = head;   
        if(ptr == NULL)  
        {  
            printf("Empty list..");  
        }  
        else  
        {  
            printf("printing values \n");   
            while (ptr!=NULL)  
            {  
                printf("\n%d",ptr->data);  
                ptr = ptr -> next;  
            }  
        }  
     }  