#include<stdio.h>
int pos, i=1;
struct node{
    int data; 
    struct  node * next;
    
 
};
int main()
{int count;
struct node * head, *newnode , *temp;
newnode = (struct node *)malloc(sizeof(struct node));
printf("enter the position");
scanf("%d", &pos);
if(pos>count)
{
printf("invalid position");
}
else{
    temp=head;
    while(i<pos)
    {
        temp= temp->next;
        i++;
    }
    printf("enter the data");
    scanf("%d",&newnode->data);
    newnode->next=temp->next;
    temp->next=newnode
}

}




 
