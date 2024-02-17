#include <stdio.h>
#include <stdlib.h>

typedef struct n
{
    int data;
    struct n *pre;
    struct n *next;
}node;

node *head= NULL, *tail = NULL, *temp=NULL, *newnode=NULL;
int count=0;

void create(){
    newnode = (node*)calloc(1,sizeof(node));
    if(newnode == NULL){
        printf("failed\n");
        exit(1);
    }
    newnode->pre = NULL;
    newnode->next = NULL;
    printf("Enter Data: ");
    scanf("%d", &newnode->data);
    count++;
}
void insertFirst(){
    create();
    if(head == NULL){
        head = newnode;
        tail = newnode;
    }
    temp = head;
    newnode->next = temp;
    temp->pre = newnode;
    head = newnode;
    tail->next = newnode;
    head->pre = tail;
    
}
void deleteFirst(){
    if(head == NULL || count==0){
        printf("List is empty\n");
        exit(0);
    }
    temp = head;
    head = head->next;
    head->pre = tail;
    tail->next = head;
    free(temp);
    temp=NULL;
    count--;
    printf("deleted first\n");
}
void insertEnd(){
    create();
    newnode->next = head;
    head->pre = newnode;
    tail->next = newnode;
    newnode->pre = tail;
    tail = newnode;
}
void deleteEnd(){
     if(head == NULL || count==0){
        printf("List is empty\n");
        exit(0);
    }
    temp = tail;
    tail = tail->pre;
    head->pre = tail;
    tail->next = head;
    free(temp);
    temp = NULL;
    count--;
    printf("Deleted from last\n");
}
void insertLocation(int index){
    if(index > count){
        printf("index exeeds\n");
        return;
    }
    if(index == 1){
        insertFirst();
        return;
    }
    create();
    int cnt = 2;
    temp = head;
    node *ptr = temp;
    while (cnt <= index && temp->next != tail){
        ptr = temp;
        temp = temp->next;
        cnt++;
    }
    newnode->next = temp;
    newnode->pre = ptr;
    ptr->next = newnode;
    temp->pre = newnode;
    temp = NULL;
}
void deleteLocation(int index){
    if(head == NULL || count==0){
        printf("List is empty\n");
        exit(0);
    }else if(count < index){
        printf("index exeeds\n");
        return;
    }
    if(index == 1){
        deleteFirst();
        return;
    }
    temp = head;
    node *ptr = temp;
    int cnt = 1;
    do{
        cnt++;
        ptr = temp;
        temp = temp->next;
    }while(temp->next != tail && index>=cnt);
    
    ptr->next = temp->next;
    temp->pre->pre = ptr;
    temp = NULL;
    ptr = NULL;

    printf("Deleted from location %d\n", index);
    count--;
}
void display(){
    if(head == NULL || count==0){
        printf("List is empty\n");
        exit(0);
    }
    temp = head;
    do{
        printf("[ %d ]<=>", temp->data);
        temp = temp->next;
    }while(temp!=tail->next);
    printf("\n");
}
int main(){
    int ch=0;
    while (1){
		printf("Menu\n1.Insert First\n2.Insert End\n3.Insert Location\n4.Delete First\n5.Delete End\n6.Delete Location\n7.Display\n8.Exit\nselect: ");
        scanf("%d", &ch);
        switch (ch){
        case 1: insertFirst(); break;
        case 2: insertEnd(); break;
        case 3: printf("Enter Index: "); scanf("%d", &ch); insertLocation(ch); break;
        case 4: deleteFirst(); break;
        case 5: deleteEnd(); break;
        case 6: printf("Enter Index: "); scanf("%d", &ch); deleteLocation(ch); break;
        case 7: display();break;
        case 8: exit(0);break;
        default: printf("Enter Approprite choice!\n");
        }
    }
    
    return 0;
}
