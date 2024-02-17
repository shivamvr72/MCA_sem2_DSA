#include <stdio.h>
#include <stdlib.h>

int main(){
	int n,*arr,i;
	
	printf("Enter Some size of an array: ");
	scanf("%d", &n);
	
	arr = (int *) malloc(n*sizeof(arr));
	if(arr == NULL){
		printf("malloc fails...\n");
		exit(1);
	}
	printf("malloc succeed...\n");
	
	printf("Enter some numbers...\n");
	
	for(i=0; i<n; i++){
		printf("Enter Number: \n");
		scanf("%d", arr+i);
	}
	printf("\nDispaying the output...\n");
	for(i=0; i<n; i++){
		printf("%d\t", *(arr+i));
	}
	
	printf("\nRelloc...\n");
	printf("Extend or shrunk the size of alloted memory by relloc...\n");
	scanf("%d", &n);
	arr = realloc(arr, n*sizeof(int));
	
	printf("New Size of array : %lu \n", sizeof(arr));
	if(arr == NULL){
		printf("malloc fails...\n");
		exit(1);
	}
	printf("relloc succeed...\n");
	
	printf("Enter some numbers...\n");
	
	for(i=0; i<n; i++){
		printf("Enter Number: \n");
		scanf("%d", arr+i);
	}
	printf("\nDispaying the output...\n");
	for(i=0; i<n; i++){
		printf("%d\t", *(arr+i));
	}
	
	
	free(arr);
	arr=NULL;
	return 0;
}
