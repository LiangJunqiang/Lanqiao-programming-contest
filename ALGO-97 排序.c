#include "stdio.h"
void sort(int array[], int left, int right)
{
	int i = left;
	int j = right;
	int key = array[left];
	
	while (i < j) {
		for (; key >= array[j] && j > i; --j)
			;
		array[i] = array[j];
		for (; key <= array[i] && j > i; ++i)
			;
		array[j] = array[i];
	}
	array[i] = key;
	if(i + 1 < right)
		sort(array, i + 1, right);
	if(left < i - 1)
		sort(array, left, i - 1);
}
int main(int argc, char const *argv[])
{
	int a[3], i;
	scanf("%d%d%d", &a[0], &a[1], &a[2]); 
	sort(a, 0, 2);
	for (i = 0; i < 3; ++i)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
