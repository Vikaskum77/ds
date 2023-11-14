#include<stdio.h>  
#include<stdlib.h>  
void randominsert(int);  
void create(int);  
struct node  
{  
    int data;  
    struct node *next;  
};  
struct node *head;  
void main ()  
{  
     
            create(10); 
            create(52);
            create(47); 
        
            randominsert(2);  
        
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
void randominsert(int item)  
    {  
        struct node *ptr = (struct node *) malloc (sizeof(struct node));  
        struct node *temp;  
        int i,loc;  
        if(ptr == NULL)  
        {  
            printf("\nOVERFLOW");  
        }  
        else  
        {  
              
            printf("Enter the location");  
            scanf("%d",&loc);             
            ptr->data = item;  
            temp=head;  
            for(i=0;i<loc;i++)  
            {  
                temp = temp->next;  
                if(temp == NULL)  
                {  
                    printf("\ncan't insert\n");  
                    return;  
                }  
              
            }  
            ptr ->next = temp ->next;   
            temp ->next = ptr;   
            printf("\nNode inserted");  
        }  
          
    }