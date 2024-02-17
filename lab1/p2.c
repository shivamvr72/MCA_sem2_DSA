#include <stdio.h>
typedef struct{
	int rno;
	char name[50];
	int s1,s2,s3,s4,s5;
	int total;
	float per;
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
		printf("Enter %d Marks 1:", i+1);
		scanf("%d", &s[i].s1);
		printf("Enter %d Marks 2:", i+1);
		scanf("%d", &s[i].s2);
		printf("Enter %d Marks 3:", i+1);
		scanf("%d", &s[i].s3);
		printf("Enter %d Marks 4:", i+1);
		scanf("%d", &s[i].s4);
		printf("Enter %d Marks 5:", i+1);
		scanf("%d", &s[i].s5);

	}
	for(int i=0; i<n; i++){
			printf("Student %d \n", i+1);
			printf("Roll No : %d\n", s[i].rno);
			printf("Name : %s\n", s[i].name);
			s[i].total = s[i].s1+s[i].s2+s[i].s3+s[i].s4+s[i].s5;
			s[i].per = s[i].total*100/50;
			printf("Marks : %d\n", s[i].total);
			printf("Percent: %.2f\n", s[i].per);
	}
	return 0;
}


/*		for(int j=0; j<5; j++){
			printf("Enter Student %d marks %d: ", i+1, j+1);
			scanf("%d", s[i].sm[j]);
		}
			for(int j=0; j<5; j++){
					s[i].total=s[i].total+s[i].sm[j];
			}
*/
