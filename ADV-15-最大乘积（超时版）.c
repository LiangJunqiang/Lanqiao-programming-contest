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
#include <stdlib.h>
#define MaxCount 15
#define change(a, b){int t = a;	a = b;b = t;}
void Sort(int zheng[], int fu[], int n, int *zn, int *fn);
int MaxProduct(int zheng[], int fu[], int z, int f, int m);
int main()
{
	int zheng[MaxCount], fu[MaxCount], zn, fn, i, j, n, m, array, pd[MaxCount];
	scanf("%d", &array);
	for(i = 0; i < array; i++){
		scanf("%d%d", &n, &m);
		for(j = 0; j < n; j++)
			scanf("%d", &zheng[j]);
		Sort(zheng, fu, n, &zn, &fn);
		pd[i] = MaxProduct(zheng, fu, zn - 1, fn - 1, m);
	}
	for(i = 0; i < array; i++)
		printf("%d\n", pd[i]);
	return 0;
}//main
void Sort(int zheng[], int fu[], int n, int *zn, int *fn)
{	//把zheng[]数组的元素分为zheng[]、fu[]两个数组，并按绝对值从大到小排序 
	int i, j, k;
	for(i = 0; i < n - 1; i++){//先按从大到小排序 
		for(k = i, j = i + 1; j < n; j++)
			if(zheng[k] < zheng[j])
				k = j;
		change(zheng[k], zheng[i]);
	}
	for(i = 0, j = n - 1; zheng[j] < 0; i++, j--)//然后从最后把负数倒序存放到fu[] 
		fu[i] = zheng[j];
	*zn = j + 1;//整数和零的元素个数 
	*fn = i + 1;//负数的元素个数 
}//Sort

int MaxProduct(int zheng[], int fu[], int z, int f, int m)
{
	int pd = 1;
	while(m > 0){
		if(m > 1){//还需要取出多个值 
			if(z >= 1 && f >= 1){//正负数都剩下多个 
				if(zheng[z] * zheng[z - 1] > fu[f] * fu[f - 1]){
					pd = pd * zheng[z] * zheng[z - 1];
					z -= 2;
					m -= 2;
				}else{
					pd = pd * fu[f] * fu[f - 1];
					f -= 2;
					m -= 2;
				}
			}else if(f < 1 && z >= 0){
				pd *= zheng[z--];
				m--;
			}else if(z == 0 && f >= 1){
				if(zheng[z] > fu[f] * fu[f - 1]){
					pd = pd * zheng[z--];
					m--;
				}else{
					pd = pd * fu[f] * fu[f - 1];
					f -=2;
					m -= 2;
				}
			}else
				exit(1);
//				printf("m = %d, z = %d, f = %d", m, z, f);
		}else if(m = 1){
			if(z >= 0){
				pd *= zheng[z--];
				m--;
			}else{
				pd *= fu[f--];
				m--;
			}
		}
	}
}//MaxProduct
