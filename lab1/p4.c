#include <stdio.h>
int main(){
	int arr[15]={10,20,30,40,50,60,70,80,90,100,110,120,130,140,150};
	int *ptr;
	
	ptr = arr;
	
	printf("values =\n");
	for(int i=0; i<15; i++){
		printf("%d\t",*(i+arr));
	}
	printf("\n");
	printf("address =\n");
	for(int i=0; i<15; i++){
		printf("%ld\n",(i+arr));
	}
	printf("\n");
	return 0;
}
