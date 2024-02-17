#include <stdio.h>
typedef struct{
	int rno;
	char name[50];
	int marks;
}stud;

int main(){
	int n,m;
	printf("Enter Number of Students: ");
	scanf("%d", &n);
	stud s[n];
	
	for(int i=0; i<n; i++){
		printf("Enter Student %d Roll No: ", i+1);
		scanf("%d", &s[i].rno);
		printf("Enter Student %d name : ", i+1);
		scanf(" %[^\n]", s[i].name);
		printf("Enter Student %d marks : ", i+1);
		scanf("%d", &s[i].marks);
	}
	for(int i=0; i<n; i++){
	if(m <= s[i].marks){
			printf("Student %d \n", i+1);
			printf("Roll No : %d\n", s[i].rno);
			printf("Name : %s\n", s[i].name);
			printf("Marks : %d\n", s[i].marks);
		}
	}
	return 0;
}
