#include "stdio.h"
#define MAXNUM 	20
typedef enum{BAD = 0, GOOD = 1}State;
int main(int argc, char const *argv[])
{
	int n, i, j, GOOD_votes;
	State state[MAXNUM][MAXNUM];
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			scanf("%d", &state[i][j]);
		}
	}
	for (j = 0; j < n; ++j)
	{
		for (GOOD_votes = i = 0; i < n && GOOD_votes <= (n-1)/2; ++i)
		{
			if(state[i][j] == GOOD && i != j)
				GOOD_votes++;
		}
		if(GOOD_votes >= (n-1)/2)
			printf("%d ", j + 1);
	}
	return 0;
}
