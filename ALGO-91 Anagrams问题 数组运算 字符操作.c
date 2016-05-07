#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char A[81], B[81];
	char _A[26], _B[26];
	char lenA, lenB;
	int i;
	gets(A);
	gets(B);
	lenA = strlen(A);
	lenB = strlen(B);
	if(lenA != lenB)
	{
		printf("N\n");
		return 0;
	}
	memset(_A, 1, sizeof(_A));
	memset(_B, 1, sizeof(_B));
	for(i = 0; i < lenA; i++)
		if(toupper(A[i]) <= 'Z' && toupper(A[i]) >= 'A')
			_A[toupper(A[i]) - 'A']++;
	for(i = 0; i < lenB; i++)
		if(toupper(B[i]) <= 'Z' && toupper(B[i]) >= 'A')
			_B[toupper(B[i]) - 'A']++;
	if(strncmp(_A, _B, 26) == 0)
		printf("Y\n");
	else
		printf("N\n");
	return 0;
}
