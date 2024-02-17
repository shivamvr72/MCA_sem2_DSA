#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};

struct node *head=NULL, *tail=NULL, *newnode=NULL, *temp=NULL;

void create(){
    newnode =  (struct node*) malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("fauled");
        exit(1);
    }
    newnode->next = NULL;
    printf("enter data : ");
    scanf("%d",&newnode->data);
}
void insertLast(){
    create();
    if(tail == NULL){
        newnode->next = newnode;
        tail = newnode;
    }else{
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }
}
void display(){
    if(tail == NULL){
        printf("list is empty!\n");
    }else{
        temp = tail->next;
        do{
            printf("[%d]->", temp->data);
            temp = temp->next;
        }while(temp != tail->next);
        printf("\n");
    }
}
int main(){
    insertLast();
    insertLast();
    insertLast();
    display();
    return 0;
}