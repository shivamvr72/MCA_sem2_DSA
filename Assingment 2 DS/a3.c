#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	int data;
	struct node *next;
}node;
node *headl=NULL,*temp,*t,*head1,*prev;

void op(){
		printf("1 = Create 2 Linked list\n");
		printf("2 = Merge 2 List\n");
}

node *sort(node *head){	
	if(head==NULL){
		printf("List not available");
		exit(0);
	}
	else{
		int temp1;
		prev=head;
		while(prev!=NULL){
			temp=prev->next;
			while(temp!=NULL){
				if(prev->data>temp->data){
					temp1=prev->data;
					prev->data=temp->data;
					temp->data=temp1;
				}
						
		
				temp=temp->next;
			}
			prev=prev->next;
		}
		
	}
	return head;	
}
node *create(int a){
	node *new=(node *)malloc(sizeof(node));

	if(new==NULL){
		printf("Node is note available ");
		exit(0);
	}
	
	new->next=NULL;
	new->data=a;
	return  new;
}


node *inlast(node *head,int a){
	node *new=create(a);
	if(head==NULL){
		head=new;
	
	}else{
	temp=head;
	
	while(temp->next != NULL){
		temp=temp->next;
	}
	
	temp->next=new;
	}
	return head;
	

}

void disp(node * head){
	if(head==NULL){
		
		printf("List is empty");
		exit(0);
		
	}else{
	temp=head;
	printf("List...\n");
	
	while(temp != NULL){
		
		printf(" %d ",temp->data);
		
		temp=temp->next;
	}

}
	
	
	
}	
int main(int argc,char *argv[]){
	op();
	int ch;

	for(;;){
		printf("\nSelect option : ");
		scanf("%d",&ch);
		
		
		
		if(ch==1){
			if(argc<32){
				
				for(int i=1;i<argc;i++){
				
					if(i<16)				
						headl=inlast(headl,atoi(argv[i]));
					else
						head1=inlast(head1,atoi(argv[i]));
				}			
			}else{
			
				printf("no is not valid %d",argc);
			}
		}else if(ch==2){
			sort(headl);
			sort(head1);
			temp=headl;
			while(temp->next!=NULL){
			
				temp=temp->next;
			}
			temp->next=head1;
			disp(headl);	
		}	
	}
}
	
