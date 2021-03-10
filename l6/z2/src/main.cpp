#include <stdio.h>
#include <string.h>

int main(){
	char str[40];
	printf("Enter string: ");
	scanf("%s", str);
	int len = strlen(str);
	bool bad = false;
	for(int i = 0; i < len; i++){
		if(str[i]!='0' |
		   str[i]!='1' |
		   str[i]!='2' |
		   str[i]!='3' |
		   str[i]!='4' |
		   str[i]!='5' |
		   str[i]!='6' |
		   str[i]!='7' |
		   str[i]!='8' |
		   str[i]!='9' |
		   str[i]!='+' |
		   str[i]!='-' |
		   str[i]!='/' |
		   str[i]!='*'){
			bad = true;
			break;
		}
	}
	printf(!bad? "Ok.\n" : "Not Ok!!!\n");
	return 0;
}
