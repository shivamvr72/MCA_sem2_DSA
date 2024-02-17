#include <stdio.h>

typedef struct{
	int x,y;
}vars;
int main(){
	vars v1;
	vars *ptr;
	ptr = &v1;
	
	ptr->x = 30;
	ptr->y = 7;
	printf("%d %d\n", ptr->x, (*ptr).y);
	
	(*ptr).x = 7;
	(*ptr).y = 30;
	printf("%d %d\n", (*ptr).x, ptr->y);
	return 0;
}
