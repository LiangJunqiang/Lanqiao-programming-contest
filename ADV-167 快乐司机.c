#include <stdio.h>
#define MaxNum 10000
void sort(float array[][2], int left, int right)
{
	int i = left;
	int j = right;
	float key[2] = {array[left][0], array[left][1]};
	
	while (i < j) {
		for (; (float)key[1]/(float)key[0] >= (float)array[j][1]/(float)array[j][0] && j > i; --j)
			;
		array[i][0] = array[j][0];
		array[i][1] = array[j][1];
		for (; (float)key[1]/(float)key[0] <= (float)array[i][1]/(float)array[i][0] && j > i; ++i)
			;
		array[j][0] = array[i][0];
		array[j][1] = array[i][1];
	}
	array[i][0] = key[0];
	array[i][1] = key[1];
	if(i + 1 < right)
		sort(array, i + 1, right);
	if(left < i - 1)
		sort(array, left, i - 1);
}//Sort
int main()
{
	int n, i;
	float gp[MaxNum][2], sum[2] = {0}, w;
	scanf("%d%f", &n, &w);
	for(i = 0; i < n; i++)
		scanf("%f%f", &gp[i][0], &gp[i][1]);
	sort(gp, 0, n - 1);
	for(i = 0; sum[0] + gp[i][0] <= w; i++){
		sum[0] += gp[i][0];
		sum[1] += gp[i][1];
	}
	printf("%.1f", sum[1]);
	return 0;
}//main
