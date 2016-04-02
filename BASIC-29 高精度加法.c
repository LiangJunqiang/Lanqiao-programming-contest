#include "stdio.h"
#include <string.h> 
#define MAXLEN	101
void Addition(char a[], char b[], char sum[])
{
	int i, j, k;
	int carry = 0;
	for (i = strlen(a) - 1, j = strlen(b) - 1, k = 0; i >= 0 && j >= 0; i--, j--, k++)
	{
		sum[k] = a[i] - '0' + b[j] - '0' + carry;
		carry = sum[k] / 10;
		sum[k] = sum[k] % 10 + '0';
	}
	while(i >= 0){
		sum[k] = a[i] - '0' + carry;
		carry = sum[k] / 10;
		sum[k] = sum[k] % 10 + '0';
		i--;
		k++;
	}
	while(j >= 0){
		sum[k] = b[j] - '0' + carry;
		carry = sum[k] / 10;
		sum[k] = sum[k] % 10 + '0';
		j--;
		k++;
	}
	if(carry > 0){
		sum[k] = carry + '0';
		k++;
	}
	sum[k] = '\0';
}
int IsDigit(char x)
{
	if(x >= '0' && x <= '9')
		return 1;
	else
		return 0;
}
int main(int argc, char const *argv[])
{
	char a[MAXLEN] = {'\0'}, b[MAXLEN] = {'\0'};
	char sum[MAXLEN+1] = {'\0'};
	int i;
	for (i = 0; i < MAXLEN && IsDigit(a[i] = getchar()) ; ++i)
		;
	a[i] = '\0';
	for (i = 0; i < MAXLEN && IsDigit(b[i] = getchar()) ; ++i)
		;
	b[i] = '\0';
	Addition(a, b, sum);
	for(i = strlen(sum) - 1; i >= 0; i--)
		putchar(sum[i]);
	return 0;
}
