#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;
node *head=NULL,*newnode;


void insertlast(int value)
{
    newnode = (node *)malloc(sizeof(node));
    newnode->data = value;
	newnode->next = NULL;

    if(head == NULL)
    {
        head = newnode;
    }
    else{
        node *temp = head;
        while(temp->next!=NULL)
        {
        temp = temp->next;
        }
        temp->next = newnode;
    }
}

void display()
{
		node *temp=head;
		printf("Displaying Data..");
		while(temp!=NULL)
		{
		 printf("%d->",temp->data);
		 temp = temp->next;
		} 
		printf("\n");	
}

void delete(node *temp2)
{
   // printf("del");
    node *pre = temp2->next;
    temp2->next = pre->next;
    free(pre);

}
void removeduplicates()
{
   // printf("hie");
    node *temp1,*temp2;
    temp1 = head;
   // printf("%d",temp1->data);
    
    while(temp1!=NULL)
    {
        temp2 = temp1;  
        while(temp2->next!=NULL)
        {
            if(temp1->data == temp2->next->data)
            {
                delete(temp2);
            }
            else
            {
                temp2 = temp2->next;
            }
        }
        temp1 = temp1->next;
    }

}
int main(){

            int value,ch;
    
           
                printf("Enter Number Of nodes : ");
                scanf("%d",&ch);

                while(ch>0)
                {
                    printf("Enter Value : ");
                    scanf("%d",&value);
                    insertlast(value);
                    ch--;
                }
                removeduplicates();
                display();
                   
               
            
            return 0;
}
