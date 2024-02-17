//string and vowel usig poiner
#include <stdio.h>
int main(){
	char s[30];//= "Shivam Rana";
	printf("enter string : ");
	scanf("%[^\n]", s);
	
	char *ptr=s;
	int vol=0, con=0;
	for(int i=0; *(ptr+i)!='\0'; i++){
		if(*(ptr+i)== 'a' || *(ptr+i)== 'i' || *(ptr+i)== 'o' || *(ptr+i)== 'u' || *(ptr+i)== 'e'){
			vol++;
		}else{
			if(*(ptr+i)== ' '){			
				continue;
				i++;
			}else{
				con++;
			}
		}
	}
	printf("vowel = %d\n", vol);
	printf("consonent = %d\n", con);
	printf("total char = %d\n", vol+con);
	return 0;
}
