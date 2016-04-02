#include <stdio.h>
#define MaxCount 100
int main()
{
	int N, i, id[MaxCount];
	scanf("%d", &N);
	for(i = 0; i < N; i++)
		scanf("%d", &id[i]);
	N = choseSort(id, N);
	printf("%d\n", N);
	for(i = 0; i < N; i++)
		printf("%d ", id[i]);
	return 0;
}
int choseSort(int num[], int n)
{
	int i, j, k, temp;
	for(i = 0; i < n - 1; i++){		
		k = i;
		for(j = i+1; j < n; j++)
			if(num[k] > num[j])
				k = j;
		if(i != 0 && num[k] == num[i - 1]){
			num[k] = num[--n];
			i--;
		}			
		else if(i != k){
			temp = num[i];
			num[i] = num[k];
			num[k] = temp;
		}
	}
	return n;
}
