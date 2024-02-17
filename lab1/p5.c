#include <stdio.h>
int main(){
	int varr[5]={10,20,30,40,50};
	int (*arr)[5]=NULL;
	
	arr = &varr;
		printf("\n");
	for(int i=0; i<5; i++){
		printf("value arr: %d \n",varr[i]);
		printf("value arr add: %p \n",&varr[i]);
		printf("pointer arr value: %d \n", *(*arr+i));
		printf("pointer array address: %p\n",&arr[i]);
	}
	return 0;
}
