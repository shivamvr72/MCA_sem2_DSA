#include <stdio.h>
int main(){
	int a[] = {1,2,3,4,5,6,7};
	int b[] = {10,20,30,40,50,60,70};
	int c[] = {100,2,3,4,5,6,7};
	int *arrp[3] = {a,b,c};
	for(int i=0; i<=3; i++){
		for(int j=-1; j<6; j++){
		
			int *x=arrp[i];
			printf("%d\n", *(x+i));
		}
		
	}
	return 0;
}
