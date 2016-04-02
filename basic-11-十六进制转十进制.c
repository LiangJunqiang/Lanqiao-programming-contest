#include <stdio.h>

int main()
{
	char sixteen[8];
	double num = 0;
	int i;
	gets(sixteen);
	for(i = 0; i < 8 && sixteen[i] != '\0'; i++){
		if(sixteen[i] >= '0' && sixteen[i] <= '9') 
			num = num * 16 + sixteen[i] - '0';
		else if(sixteen[i] >= 'A' && sixteen[i] <= 'F') 
			num = num * 16 + sixteen[i] - 'A' + 10;
	}
	printf("%.0f", num);
	return 0;
}
