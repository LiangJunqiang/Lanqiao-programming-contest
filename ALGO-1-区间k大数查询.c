#include <stdio.h>
#define MaxCount 1000
#define change(a, b) {\
	int t = a;\
	a = b;\
	b = t;\
}
int SearchKmax(int num[], int l, int r, int k);
int main()
{
	int n, m, kmax[MaxCount], num[MaxCount], i, l, r, k;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &num[i]);
	scanf("%d", &m);
	for(i = 0; i < m; i++){
		scanf("%d%d%d", &l, &r, &k);
		kmax[i] = SearchKmax(num, l, r, k);
	}
	for(i = 0; i < m; i++)
		printf("%d\n", kmax[i]);
	return 0;
}//main
int SearchKmax(int num[], int l, int r, int k)
{
	int x[MaxCount], i, j, m;
	for(i = l - 1; i < r; i++)
		x[i - (l - 1)] = num[i];
	for(j = 0; j < k; j++){
		m = j;
		for(i = j + 1; i < r - l + 1; i++)
			if(x[m] < x[i])
				m = i;
		change(x[m], x[j]);
	}
	return x[--j];
}//SearchKmax
