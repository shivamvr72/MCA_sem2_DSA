#include <stdio.h>
#include <stdlib.h>

#define pr 2
typedef struct{
	char bname[30];
	char aname[30];
	int pages;
	float price[pr];
}book;

void printBookD(book *bn, int n){
	printf("\n");
	for(int i=0; i<n; i++){
		//if((bn+i)->bname[0] == 'D' || (bn+i)->bname[0] == 'd'){
				printf("book name : %s\n", (bn+i)->bname);
				printf("book auther : %s\n", (bn+i)->aname);
				printf("book pages : %d\n", (bn+i)->pages);
				for(int j=0;j<pr;j++){
					printf("book price : %.2f\n", (bn+i)->price[j]);
				}	
				printf("\n");
		//}
	}
}

int main(){
	int n=0, i=0;
	char choice='y';
//	book *s;
	book *ptr;
	
	printf("Enter Number Of Book Want to store: ");
	scanf("%d", &n);
	ptr = (book *) malloc(n*sizeof(book));
	
	
	while(choice == 'y' || choice == 'Y'){
		printf("enter book name : ");
		scanf(" %[^\n]", (ptr + i)->bname);
		printf("enter auther name : ");
		scanf(" %[^\n]", (ptr + i)->aname);
		printf("enter pages : ");
		scanf("%d", &(ptr + i)->pages);
		for(int j=0; j<pr; j++){
			printf("Enter Price: ");
			scanf("%f", &(ptr + i)->price[j]);
		}
		printf("Do You want to modify storage of book? y/n\n");	
		scanf(" %c", &choice);
		if(choice == 'y' || choice == 'Y'){
			n++,i++;
			printf("Enter Number Of Book Want to store : ");
			scanf("%d", &n);
			ptr = realloc(ptr,n*sizeof(book));	
		}
	}
	
	
	//print call
	printBookD(ptr, n);	
	
	free(ptr);
	ptr = NULL;
	return 0;
}

/*for(int i=0; i<n; i++){
		printf("book name : %s\n", (ptr+i)->bname);
		printf("book auther : %s\n", (ptr+i)->aname);
		printf("book pages : %d\n", (ptr+i)->pages);
		for(int j=0;j<pr;j++){
			printf("book price : %.2f\n", (ptr+i)->price[j]);
		}
		
	}*/
