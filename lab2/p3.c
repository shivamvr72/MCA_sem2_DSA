#include <stdio.h>

void oddeven(int x){
	if(x%2==0){
		printf("Even Number\n");
	}else{
		printf("odd Number\n");
	}
}

int main(){
	int n;
	printf("Enter Number : ");
	scanf("%d", &n);
	
	void (*ptr)(int) = &oddeven;
	(*ptr)(n);
}
