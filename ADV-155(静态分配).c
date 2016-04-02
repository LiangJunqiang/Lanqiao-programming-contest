#include <stdio.h>
#include <malloc.h>
#include <sys/time.h>
int Searchmin(int num[], int lo, int hi){
	int i, k;
	for(i = k = lo; i <= hi; i++){
		if(num[i] < num[k])
			k = i;
	}
	printf("%d\n", num[k]);
	return num[k];
}

int main()
{
	int n, Q, i, *pn, (*pQ)[2];
//	srand((int)time(0));
	scanf("%d%d", &n, &Q);
	fflush(stdin);
	pn = (int*)malloc(n*sizeof(int));
	pQ = (int (*)[2])malloc(Q*2*sizeof(int));
	for(i = 0; i < n; i++)
		scanf("%d", &pn[i]);
//	for(i = 0; i < n; i++)
//		pn[i] = rand();
//	for(i = 0; i < n; i++)
//		printf(" %d ", pn[i]);
	for(i = 0; i < Q; i++)
		scanf("%d%d", &pQ[i][0], &pQ[i][1]);
	for(i = 0; i < Q; i++)
		Searchmin(pn, pQ[i][0], pQ[i][1]);
	return 0;
}
