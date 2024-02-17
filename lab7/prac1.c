#include <stdio.h>
#include <stdlib.h>

typedef struct n{
    int data;
    struct n *next;
}node;

node *head=NULL, *tail=NULL, *temp=NULL, *newnode = NULL;

int count = 0;
void create(){
    newnode = (node*) calloc(1, sizeof(node));
    if(newnode == NULL){
        printf("failed..\n");
        exit(1);
    }
    newnode->next = NULL;
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    count++;
}
void enq(){
    create();
    if(tail == NULL){
        head = tail = newnode;
        return;
    }
    tail->next = newnode;
    newnode->next = head;
    head = newnode;

}
void dq(){
    if(tail == NULL || count==0){
        printf("list is empty\n");
        exit(0);
    }
    temp = head;
    node * ptr = head;
    // do{
    //     ptr = temp;
    //     temp = temp->next;
    // }while(temp->next != head);
    while(temp != tail){
		ptr = temp;
		temp = temp->next;
	}
    //temp = tail;
    tail = ptr;
    tail->next = head;
    free(temp);
    temp = NULL;
    count--;
}


void display(){
    if(tail == NULL || count == 0){
        printf("list is empty\n");
        exit(1);
    }
    temp = head;
    printf("| ");
    do{
        printf("[ %d ]-> | ", temp->data);
        temp = temp->next;
    }while(temp!= head);
    printf("\n");
}
int main(){
    int ch = 0;
    while (1)
    {
        printf("Menu \n1.Enqueue\n2.Dequeue\n3.Display\n4.exit\nSelect :");
        scanf("%d", &ch);
        switch(ch){
            case 1: enq();break;
            case 2: dq();break;
            case 3: display();break;
            case 4: exit(0);
            default: printf("select appropriate option!\n");
        }
    }
    return 0;
}