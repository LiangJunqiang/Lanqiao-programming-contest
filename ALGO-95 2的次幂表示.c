#include <stdio.h>
void fuction(int num)
{
	int i;
	if(num == 0){
		printf("0");
		return;
	}
	for(i = 31; i >= 0 && !(num & (1 << i)); i--)
		;
	if(i == 1)
		putchar('2');
	else{
		printf("2(");
		fuction(i);
		printf(")");
	}
	while(i > 0){
		i--;
		for(; i >= 0 && !(num & (1 << i)); i--)
			;
		if(i < 0)
			continue;
		else if(i == 1)
			printf("+2"); 
		else{
			printf("+2(");
			fuction(i);
			printf(")");
		}
	}
}
int main()
{
	int num;
	scanf("%d", &num);
	fuction(num);
	return 0;
}
