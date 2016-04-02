#include "stdio.h"
int main(int argc, char const *argv[])
{
	int v1, v2, t, s, l, timeinsecond;
	int run1, run2;
	int i;
	scanf("%d%d%d%d%d", &v1, &v2, &t, &s, &l);
	for(timeinsecond = run1 = run2 = 0; run1 < l && run2 < l; )
	{
		while((run1 - run2) < t && run1 < l && run2 < l){
			run1 += v1;
			run2 += v2;
			timeinsecond++;
		}
		for(i = 0; i < s && run1 < l && run2 < l; i++){
			run2 += v2;
			timeinsecond++;
		}
	}
	if(run1 >= l && run2 >= l)
		printf("D\n");
	else if(run1 >= l)
		printf("R\n");
	else if(run2 >= l)
		printf("T\n");
	printf("%d", timeinsecond);
	return 0;
}
