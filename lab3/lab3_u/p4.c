#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int empid;
	char name[30];
	short age;
}emp;

int main(){
	int cnt=1,i=0;
	emp *e = (emp*) malloc(cnt * sizeof(emp));
	char ch = 'y';
	while(ch=='y' || ch=='Y'){
	
		printf("enter employee id : ");
		scanf("%d", &(e + i)->empid);
		printf("enter employee name : ");
		scanf(" %[^\n]", (e + i)->name);
		printf("enter employee age : ");
		scanf("%hd", &(e + i)->age);

		printf("Do You want to modify storage of employee data? y/n:");	
		scanf(" %c", &ch);
		if(ch == 'y' || ch=='Y'){
			cnt++;
			i++;
			e = realloc(e, cnt*sizeof(emp));
		}
	}
			for(int i=0; i<cnt; i++){
				printf("enter employee id : %d\n", (e+i)->empid);
				printf("enter employee name : %s\n", (e+i)->name);	
				printf("enter employee age : %d\n", (e+i)->age);
			}
	
	free(e);
	e=NULL;
	return 0;
}
