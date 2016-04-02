#include "stdio.h"
#define MAXLEN	67108863
void copystrings(char fj[], int current)
{
	int i;
	for (i = 0; i < current; ++i)
		fj[current + i + 1] = fj[i];
}//copystrings
int main(int argc, char const *argv[])
{
	int n, new_subscript, new_char;
	char fj[MAXLEN] = {'\0'};
	scanf("%d", &n);
	for (new_char = 'A', new_subscript = 0; new_char < ('A' + n) && new_char <= 'Z'; new_char++)
	{
		fj[new_subscript] = new_char;
		copystrings(fj, new_subscript);
		new_subscript = new_subscript * 2 + 1;
	}
	printf("%s", fj);
	return 0;
}//main
