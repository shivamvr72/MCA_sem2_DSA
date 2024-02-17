#include <stdio.h>
int main(){
	
	char *names[] = {"Snehal", "Shivam", "Kaushik", "Jay", "Sanjay"};
	for(int i=0; i<5; i++){
		printf(" %s ", names[i]);
	}
	printf("\n");
	return 0;
}
