#include <stdio.h>
#define MaxLength 20
int main()
{
	char str[MaxLength], i;
	gets(str);
	for(i = 0; str[i] != '\0'; i++){
		if(str[i] >= 'a' && str[i] <= 'z')
			printf("%c", str[i] += ('A' - 'a'));
		else if(str[i] >= 'A' && str[i] <= 'Z')
			printf("%c", str[i] -= ('A' - 'a'));
		else
			return 1;
	}
	return 0;
} 
