#include <stdio.h>

void inc(int *n){
	*n+=2;
}
void dec(int *n){
	*n-=2;
}

void (*func[])(int*) = {NULL,inc, dec};

int main(){
	int num,op;
	printf("Enter Number: ");
	scanf("%d", &num);
	printf("Increment = 1\nDecrement=2\nEnter choice:");
	scanf("%d", &op);
	
	if(op!=1 && op!=2){
		printf("Wrong choice \n");
		return 0;
	}
	(*func[op])(&num);		
	printf("%d\n", num);
	
	return 0;
}
