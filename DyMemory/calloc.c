//calloc implemetation basic
#include <stdio.h>
#include <stdlib.h>

int main(){
	char *name;
	int n;
	printf("Enter size : ");
	scanf("%d", &n);
	
	name = (char *) calloc(n, sizeof(char));
	if(name == NULL){
		printf("calloc failed...\n");
	}
	printf("calloc succeed...\n");
	
	printf("enter name\n");
	scanf("%s", name );
	printf("displaying name...\n");
	printf("%s\n", name);
	
	free(name);
	name = NULL;
	return 0;
}
