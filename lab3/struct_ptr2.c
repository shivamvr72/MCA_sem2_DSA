#include <stdio.h>

#define pr 2
typedef struct{
	char bname[30];
	char aname[30];
	int pages;
	float price[pr];
}book;

int main(){
	int n =pr;
//	book no=n;
	book s[n];
	book *ptr = s;
		
//	printf("Enter Number Of Book Want to store: ");
//	scanf("%d", &n);
	
	
	for(int i=0; i<n; i++){
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
	}
	for(int i=0; i<n; i++){
		printf("book name : %s\n", (ptr+i)->bname);
		printf("book auther : %s\n", (ptr+i)->aname);
		printf("book pages : %d\n", (ptr+i)->pages);
		for(int j=0;j<pr;j++){
			printf("book price : %.2f\n", (ptr+i)->price[j]);
		}
		
	}
	return 0;
}
