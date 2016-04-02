#include <stdio.h>
void fuction(int n)
{
	if(n == 0){
		putchar('0'); 
		return;
	}
	else if(n == 1){
		putchar('1');
		return;
	}
	fuction(n - 2);
	fuction(n - 1);
}
int main()
{
	int num;
	scanf("%d", &num);
	fuction(num);
	putchar('\n');	
	return 0;
}
