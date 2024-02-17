//This is malloc implementation basic
#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	
	int *arr; //behaves like an array cause malloc assings coninous block of free memory
	
	printf("Enter Size of an array: ");
	scanf("%d", &n);
	//printf("sizeof int %d:\n", sizeof(int));
	arr = (int *) malloc(n*sizeof(int));
	
	if(arr == NULL){
		printf("Memory Allocation failed...\n");
		exit(1);		
	}
	printf("malloc successful...\n");
	printf("enter intigers...\n");
	for(int i=0; i<n; i++){
		scanf("%d", arr+i);
	}
	printf("Printing entered elements...\n");
	for(int i=0; i<n; i++){
		printf("%d\n", *(arr+i));
	}

	
	free(arr);
	arr = NULL;
	return 0;
}
