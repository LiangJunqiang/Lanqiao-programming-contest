#include <stdio.h>
void fuction(int num)
{
	int i;
	if(num == 0){
		printf("0");
		return;
	}
	for(i = 31; i >= 0 && !(num & (1 << i)); i--)
		;//假定num最大32位，找到num二进制中最左边的1 
	if(i == 1)			//若是右边起第二位,不用再分解 
		putchar('2');
	else{				//若不是，则逐位分解 
		printf("2(");
		fuction(i);
		printf(")");
	}
	while(i > 0){	//此循环过程其实同上，只因后面的要有+号 
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

