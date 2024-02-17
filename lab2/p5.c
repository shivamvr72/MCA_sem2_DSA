#include <stdio.h>

int main(){
	char s[30];
	char *ptr=s;
	printf("Enter String: ");
	scanf("%[^\n]", s);
	
	int cnt=0, sm=0;
	while(*(ptr+cnt)!='\0'){
		cnt++;
	}
	//printf("%d\n", i);
	int temp = cnt;
	for(int i=0;  i<cnt/2; i++){
		temp--;
		if(*(ptr+i)== *(ptr+temp)){
			sm++;
		}else{
			sm=0;
		}
	}
	if(sm>=1){
		printf("palindrom\n");
	}else{
		printf("not palindrom\n");
	}
	
	return 0;
}

