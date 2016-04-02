//将有二个有序数列a[first...mid]和a[mid+1...last]合并。
#include <stdio.h>
#include <malloc.h>
#define true	1
#define false	0
#define MAXN	100000
struct kit{
	int h;
	int t;
};
struct kit l[MAXN], t[MAXN];
void mergearray(struct kit *a, int first, int mid, int last, struct kit *temp)
{
	int i = first, j = mid + 1;
	int m = mid,   n = last;
	int k = 0;
	
	while (i <= m && j <= n)
	{
		if (a[i].h <= a[j].h){
			a[i].t += j - mid - 1;
			temp[k++] = a[i++];
		}
		else{
			temp[k++] = a[j++];
			
		}
	}
	
	while (i <= m)
		temp[k++] = a[i++];
	
	while (j <= n)
		temp[k++] = a[j++];
	
	for (i = 0; i < k; i++)
		a[first + i] = temp[i];
}
void mergesort(struct kit *a, int first, int last, struct kit *temp)
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		mergesort(a, first, mid, temp);    //左边有序
		mergesort(a, mid + 1, last, temp); //右边有序
		mergearray(a, first, mid, last, temp); //再将二个有序数列合并
	}
}
int main()
{
	int n;
	mergesort(l, 0, n - 1, t);
	return 0;	
} 
