#include <stdio.h>
int main(){
	int clr;
	char *names = {"Snehal", "Shivam", "Kaushik", "Jay", "Sanjay"};
	
	for(int i=0; i<5; i++){
		printf("%s\n", names[i]);
	}
	return 0;
}
