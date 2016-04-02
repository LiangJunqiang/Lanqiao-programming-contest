/*
问题描述
　　对于n个数，从中取出m个数，如何取使得这m个数的乘积最大呢？
输入格式
　　第一行一个数表示数据组数
　　每组输入数据共2行：
　　第1行给出总共的数字的个数n和要取的数的个数m，1<=n<=m<=15，
　　第2行依次给出这n个数，其中每个数字的范围满足:a[i]的绝对值小于等于4。
输出格式
　　每组数据输出1行，为最大的乘积。
样例输入
1
5 5
1 2 3 4 2
样例输出
48 
*/
#include <stdio.h>
#define MaxCount 15
#define change(a, b){int t = a;	a = b;b = t;}
void AbsoluteQuickSort(int array[], int left, int right)
{	//基于快速排序法的绝对值从大到小排序 
	int i = left, j = right;
	int key = array[left];
	while (i < j) {
		for (; ((key > 0)?(key >= array[j] && key >= -1*array[j]):(-1*key >= array[j] && key <= array[j])) && j > i; --j)
			;
		array[i] = array[j];
		for (; ((key > 0)?(key <= array[i] || key <= -1*array[i]):(-1*key <= array[i] || key >= array[i])) && j > i; ++i)
			;
		array[j] = array[i];
	}
	array[i] = key;
	if(i + 1 < right)
		AbsoluteQuickSort(array, i + 1, right);
	if(left < i - 1)
		AbsoluteQuickSort(array, left, i - 1);
}//AbsoluteQuickSort
int MaxProduct(int num[], int n, int m)
{	//在 n 个数中取 m 个数，使 m 个数的乘积最大 
	int pd = 1, f_last = -1, f_case = -1, z_case[2] = {-1, -1}, i;
	AbsoluteQuickSort(num, 0, n - 1);//按绝对值由大到小排序 
	for(i = m - 1; i >= 0; i--){
		if(num[i] >= 0 && z_case[0] == -1)	//记下 m 前离 m 最近一个正数或零元素的下标 
			z_case[0] = i; 
		else if(num[i] < 0 && f_last == -1)	//记下 m 前离 m 最近一个负数元素的下标 
			f_last = i;
		else
			pd *= num[i];					//记下前 m 个数除num[f_last]和num[z_case[0]]外的元素的乘积 
	}
	if(pd <= 0){				//绝对值较大的前 m 个数的乘积为正数或零 
		if(z_case[0] == -1)		//前 m 个数中木有正数或零 
			return (pd = pd * num[f_last]);
		else					//前 m 个数有正数或零 
			return (pd = pd * num[z_case[0]] * num[f_last]);
	}
	else if(f_last == -1)	//前 m 个数中木有负数 
		return (pd *= num[z_case[0]]);

	//pd 大于零时 
	for(i = m; i < n; i++){
		if(num[i] >= 0 && z_case[1] == -1){		//记下 m 后离 m 最近一个正数或零元素的下标 
			z_case[1] = i;				
		}else if(num[i] < 0 && f_case == -1){	//记下 m 后离 m 最近一个负数元素的下标
			f_case = i;
		}else if(z_case[1] != -1 && f_case != -1)	//z_case[1]或f_case都找到啦~ 
			break;
	}
	//报告，前方出现负数 
	if(z_case[0] == -1){	//前 m 个数中木有正数或零 
		if(z_case[1] != -1)			//报告，第 m 个数后发现非负数 
			return (pd *= num[z_case[1]]);
		else{						//第 m 个数后没有正数或零
			pd = 1;
			for(i = 1; i <= m; i++)
				pd *= num[n - i];
			return pd;
		}						
	}else{			//前 m 个数中有正数或零 
		if(z_case[1] != -1){	//报告，第 m 个数后发现非负数 
			if(f_case != -1){	//报告，第 m 个数后发现负数 
				if(num[z_case[0]] * num[z_case[1]] >= num[f_last] * num[f_case])
					return (pd *= num[z_case[0]] * num[z_case[1]]);
				else
					return (pd *= num[f_last] * num[f_case]);
			}else
				return (pd *= num[z_case[0]] * num[z_case[1]]);
		}else{
			if(f_case != -1)
				return (pd *= num[f_last] * num[f_case]);
			else
				return (pd *= num[f_last] * num[z_case[0]]);	
		}				
	}		
}//MaxProduct
int main()
{
	int num[MaxCount], i, j, n, m, array, pd[MaxCount];
	scanf("%d", &array);
	for(i = 0; i < array; i++){
		scanf("%d%d", &n, &m);
		for(j = 0; j < n; j++)
			scanf("%d", &num[j]);
		pd[i] = MaxProduct(num, n, m);
	}
	for(i = 0; i < array; i++)
		printf("%d\n", pd[i]);
	return 0;
}//main
