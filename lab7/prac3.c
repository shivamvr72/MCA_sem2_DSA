#include <stdio.h>
#include <stdlib.h>

typedef struct n{
    struct n *pre;
    int data;
    struct n *next;
}node;

node *head = NULL, *tail = NULL, *temp = NULL, *newnode = NULL;
int count = 0;
void create(){
    newnode = (node*) calloc(1,sizeof(node));
    if(newnode == NULL){
        printf("failed\n");
        exit(0);
    }
    newnode->next = NULL;
    newnode->pre = NULL;
    printf("Enter data : ");
    scanf("%d", &newnode->data);
    count++;
}

void insertFirst(){
    create();
    if(head == NULL){
        head = newnode;
        tail = newnode;
        return;
    }
    head->pre = newnode;
    newnode->next = head;
    head = newnode;
}
void deleteFirst(){
    if(head == NULL || count==0){
        printf("List is empty\n");
        exit(0);
    }
    temp = head;
    head = head->next;
    head->pre = NULL;
    free(temp);
    temp = NULL;
    count--;
    printf("deleted from first\n");
}
void insertLast(){
    create();
    tail->next = newnode;
    newnode->pre = tail;
    tail = newnode;
    newnode->next = NULL;
}
 void deleteLast(){
    if(head == NULL || count==0){
        printf("List is empty\n");
        exit(0);
    }
    temp = tail;
    tail = tail->pre;
    tail->next = NULL;
    free(temp);
    count--;
    printf("deleted from last\n");
 }

void insertLocation(int index){
    if(count<index){
        printf("index entered out of range\n");
        printf("Available nodes %d \n", count);
        return;
    }
    if(index == 1){
        insertFirst();
        return;
    }
    create();
    temp = head;
    node *ptr = temp;
    int cnt = 2;
    while(temp->next!=NULL && cnt<=index){
        ptr = temp;
        temp = temp->next;
        cnt++;
    }
    ptr->next = newnode;
    newnode->pre = ptr;
    newnode->next = temp;
    temp->pre = newnode;
    temp = NULL;

}
void deleteLocation(int index){
    if(head == NULL || count==0){
        printf("List is empty\n");
        exit(0);
    }else if(count<index){
        printf("index entered out of range\n");
        printf("Available nodes %d \n", count);
        return;
    }
    if(index == 1){
        deleteFirst();
        return;
    }
    temp = head;
    node *ptr = temp;
    int cnt = 2;
    while(temp->next!=NULL && cnt<=index){
        ptr = temp;
        temp= temp->next;
        cnt++;
    }
    
    ptr->next = temp->next;
    temp->pre ->pre = ptr;
    
    temp = NULL;
    ptr = NULL;
    count--;
    
    printf("deleted from location %d\n", index);
}
void display(){
    if(head == NULL || count==0){
        printf("List is empty\n");
        exit(0);
    }
    temp = head;
    printf("->");
    while (temp != NULL){
        printf("[%d]-><-", temp->data);
        temp = temp->next;
    }
    printf("\n");
    temp = NULL;
}

int main(){
    int ch=0;
    while (1){
		printf("Menu\n1.Insert First\n2.Insert End\n3.Insert Location\n4.Delete First\n5.Delete End\n6.Delete Location\n7.Display\n8.Exit\nselect: ");
        scanf("%d", &ch);
        switch (ch){
        case 1: insertFirst(); break;
        case 2: insertLast(); break;
        case 3: printf("Enter Index: "); scanf("%d", &ch); insertLocation(ch); break;
        case 4: deleteFirst(); break;
        case 5: deleteLast(); break;
        case 6: printf("Enter Index: "); scanf("%d", &ch); deleteLocation(ch); break;
        case 7: display();break;
        case 8: exit(0);break;
        default: printf("Enter Approprite choice!\n");
        }
    }
    
    return 0;
}
