#include <stdio.h>
#define MAX 1990 
int Searchmin(int num[], int lo, int hi){
	int i, k;
	for(i = k = lo; i <= hi; i++){
		if(num[i] < num[k])
			k = i;
	}
	return num[k];
}

int main()
{
	int n, Q, i, pn[MAX], lo, hi, min[MAX];
	scanf("%d%d", &n, &Q);
	for(i = 0; i < n; i++)
		scanf("%d", &pn[i]);
	for(i = 0; i < Q; i++){
		scanf("%d%d", &lo, &hi);
		min[i] = Searchmin(pn, lo, hi);
	}
	for(i = 0; i < Q; i++)
		printf("%d\n", min[i]);
	return 0;
}
