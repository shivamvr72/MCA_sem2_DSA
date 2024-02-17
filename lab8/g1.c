#include <stdio.h>
#include <stdlib.h>

int main(){
	int v=0;
	printf("Enter the number of vertex : ");
	scanf("%d" ,&v); 
	
	int m[v][v];
	
	for(int i=0; i<v; i++){
		for(int j=0; j<v; j++){
			m[i][j] = 0;
		}
	}
	
	int x=v*v;
	
	for(int i=0; i<v; i++){
		for(int j=0; j<v; j++){
			printf("enter node connection for row %d ; vertext %d : ", i+1, j);
			scanf("%d", &(m[i][j]));
		}
	}
	
	
	
	for(int i=0; i<v; i++){
		for(int j=0; j<v; j++){
			if(m[i][j] == 1){
				printf("%d %d\n", i, j); 
			}
		}
		printf("\n");
	}

}
