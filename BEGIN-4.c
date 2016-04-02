#include <stdio.h>

#define DIVISOR 10007

int main()
{
	int F[1000001], n, i;
	F[1] = F[2] =1;
	scanf("%d", &n);
	for (i = 3; i <= n; i++)
		F[i] = (F[i - 1] + F[i - 2]) % DIVISOR;
	printf("%d", F[n]);
	return 0;
}


/*int remainder(int a);
// 这是一个用于计算Fibonacci数列的第n项除以10007的余数的程序
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", remainder(n));
	return 0;
}
int remainder(int a)
{
	if (a == 1 || a == 2)
		return 1;
	else return (remainder(a - 1) + remainder(a - 2)) % DIVISOR; 由于Fibonacci数列的特点，第N项的余数就等于前两项的余数的和再求一次余数
}
*/
