#include <stdio.h>

int main()
{
	void sort(int array[], int left, int right);
	int array[200], i, j, k, n;
	scanf("%d", &n);
	for(i = 0; i < n; ++i)
		scanf("%d", &array[i]);
	sort(array, 0, n - 1);
	for(i = 0; i < n; ++i)
		printf("%d ", array[i]);
	return 0;
}

void sort(int array[], int left, int right)
{
	int i = left;
	int j = right;
	int key = array[left];
	
	while (i < j) {
		for (; key <= array[j] && j > i; --j)
			;
		array[i] = array[j];
		for (; key >= array[i] && j > i; ++i)
			;
		array[j] = array[i];
	}
	array[i] = key;
	if(i + 1 < right)
		sort(array, i + 1, right);
	if(left < i - 1)
		sort(array, left, i - 1);
}
