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
		
		while(temp!=NULL)
		{
		 printf("%d-->",temp->data);
		 temp = temp->next;
		} 
		printf("\n");	
}

void displaysubsets(int el)
{
        node *temp1,*temp2;
       
        printf("{NULL}");
        temp1 = head;
        while(temp1!=NULL){
            printf("{%d} ,",temp1->data);
            temp1=temp1->next;
        } 
            temp1 = head;
            while(temp1!=NULL)
            {
                temp2 = temp1->next;
                while(temp2!=NULL){
                 printf("{ %d,%d } ,",temp1->data,temp2->data);
                 temp2 = temp2->next;
                }
                temp1 = temp1 -> next;
            }
            if(el>2){
                temp1 = head;
                printf("{");
                while(temp1!=NULL)
                {
                    printf("%d,",temp1->data);
                    temp1 = temp1->next;
                }
                printf("},");
            }      
}

int main()
{
        int no,value;
        printf("Enter Numbe Of Elements : ");
        scanf("%d",&no);

        for(int i=1;i<=no;i++)
        {
            printf("Enter %d element : ",i);
            scanf("%d",&value);
            insertlast(value);
        }  
        display();
        displaysubsets(no);
        return 0;
}