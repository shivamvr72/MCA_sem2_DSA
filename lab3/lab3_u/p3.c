#include <stdio.h>
#include <stdlib.h>

int main(){
	int *arr,n,i,sum=0;
	printf("Enter Size of an array: ");
	scanf("%d", &n);	
	arr = (int *) malloc(n*sizeof(int));
	rlc:
	for(i=0; i<n; i++){
		printf("Enter Num: ");
		scanf("%d", arr+i);
	}
	for(i=0; i<n; i++){
		sum += *(arr+i);
	}
	printf("sum of an array: %d\n", sum);
	char ch;
	printf("Enter to modify Size of an array? y/n : ");
	scanf(" %c", &ch);
	if(ch=='y' || ch=='Y'){
		printf("Enter Size to modify an array: ");
		scanf("%d", &n);
		arr = realloc(arr, sizeof(arr));
		goto rlc;
	}	
	free(arr);
	arr = NULL;
	return 0;
}
