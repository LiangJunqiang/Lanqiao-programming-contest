#include <stdio.h>
#include <memory.h>
#include <math.h>
#define MAX 2100000000
int isPrime(int num)
{
	int i, myin;
	myin = (int)pow(num, 0.5) + 1;
	if(num < 2)
		return 0;
	else if(num == 2)
		return 1;
	for(i = 2; i <= myin; i++)
		if((num % i) == 0)
			return 0;
	return 1;
}
int main()
{
	char count[28];	//每个字母出现的次数
	int max, min, i;
	char c;
	memset(count, 0, sizeof(count));
	max = 0;
	min = 0;
	while((c = getchar()) != '\n' && c != EOF)
	{
		count[c - 'a']++;
		if(count[c - 'a'] > count[max])
			max = c - 'a';
		else if((count[c - 'a'] < count[min] && count[c - 'a'] != 0) || count[min] == 0)
			min = c - 'a';
	}
	if(isPrime(count[max] - count[min]) == 1)
		printf("Lucky Word\n%d\n", count[max] - count[min]);
	else
		printf("No Answer\n0\n");
	return 0;
}
