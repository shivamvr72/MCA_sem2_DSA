#include <stdio.h>
#include <string.h>

int main(){
	char s1[10];// = "shivam";
	char s2[10];// = "shivam";
	printf("Enter Two String :\n");
	scanf(" %[^\n]", s1);
	scanf(" %[^\n]", s2);
	char *ptr1=s1;
	char *ptr2=s2;
	int x=0;
	int sl1 = strlen(s1);
	int sl2 = strlen(s2);
	
	
	for(int i=0; *(ptr1+i)!='\0' && *(ptr2+i)!='\0'; i++){
		if(*(ptr1+i)!=*(ptr2+i) || sl1!=sl2){
			printf("Strings Are not equal\n");
			break;
		}else{
			x++;
		}
	}
	if(sl1==x && sl2==x && x!=0){
		printf("Strings are equal\n");
	}
	
	return 0;
}
