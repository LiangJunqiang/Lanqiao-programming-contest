/*描述

小渊和小轩是好朋友也是同班同学，他们在一起总有谈不完的话题。一次素质拓展活动中，班上同学安排做成一个m行n列的矩阵，而小渊和小轩被安排在矩阵对角线的两端，因此，他们就无法直接交谈了。幸运的是，他们可以通过传纸条来进行交流。纸条要经由许多同学传到对方手里，小渊坐在矩阵的左上角，坐标(1,1)，小轩坐在矩阵的右下角，坐标(m,n)。从小渊传到小轩的纸条只可以向下或者向右传递，从小轩传给小渊的纸条只可以向上或者向左传递。

在活动进行中，小渊希望给小轩传递一张纸条，同时希望小轩给他回复。班里每个同学都可以帮他们传递，但只会帮他们一次，也就是说如果此人在小渊递给小轩纸条的时候帮忙，那么在小轩递给小渊的时候就不会再帮忙。反之亦然。

还有一件事情需要注意，全班每个同学愿意帮忙的好感度有高有低（注意：小渊和小轩的好心程度没有定义，输入时用0表示），可以用一个0-1000的自然数来表示，数越大表示越好心。小渊和小轩希望尽可能找好心程度高的同学来帮忙传纸条，即找到来回两条传递路径，使得这两条路径上同学的好心程度之和最大。现在，请你帮助小渊和小轩找到这样的两条路径。

输入

输入文件的第一行有2个用空格隔开的整数m和n，表示班里有m行n列（2<=m,n<=50）。
接下来的m行是一个m*n的矩阵，矩阵中第i行j列的整数表示坐在第i行j列的学生的好心程度（不大于1000）。每行的n个整数之间用空格隔开。

输出

输出共一行，包含一个整数，表示来回两条路上参与传递纸条的学生的好心程度之和的最大值。

样例输入

3 3
0 3 9
2 8 5
5 7 0
样例输出

34
来源

Tyvj1011

这道题刚开始的时候就想到用动态规划的方法来做，以为只是两次动态规划，第二次动态规划排除掉第一次走过的点而已。

但实现了单条道路的最大好感度和的计算之后，却发现远远没这么简单，两条道路如何不交叉是一个问题。

最后用四维数组来动态规划解决了这倒题。

设f[i][j][k][l]为从 (0, 0) 位置由两条不交叉的线路走到 (i, j)，(k, l) 位置时的最大好感度和，则它的上一步可能有四种情况：

第一个点由上走来，第二个点也由上走来，此时的好感度和为f[i - 1][j][k - 1][l] + a[i][j] + a[k][l]
第一个点由上走来，第二个点则由左走来，此时的好感度和为f[i - 1][j][k][l - 1] + a[i][j] + a[k][l]，但此时应考虑第一个点的上方的点是否会与第二个点的左方的点重合，如果重合则不可取
第一个点由左走来，第二个点则由上走来，此时的好感度和为f[i][j - 1][k - 1][l] + a[i][j] + a[k][l]，但此时应考虑第一个点的左方的点是否会与第二个点的上方的点重合，如果重合则不可取
第一个点由左走来，第二个点也由左走来，此时的好感度和为f[i][j - 1][k][l - 1] + a[i][j] + a[k][l]
取四种情况中的最大者即可。

代码如下：
 *
 */
#include<stdio.h> 
int a[51][51] = {0};
// 好感度数组
int f[51][51][51][51] = {0};
// 动态规划数组，f[i][j][k][l] 表示从 (0, 0) 位置由两条不交叉的线路走到 (i, j)，(k, l) 位置时的最大好感度和
 
int max(int a, int b)
{
	return a > b ? a : b;
}
//void suiji(int *m, int *n, int a[][51])
//{
//	int i, j;
//	srand((unsigned)time(NULL));
//	j = rand()%100;
//	for(i = 0; i < j; i++)
//		rand();
//	srand((unsigned)rand());
//	*m = /*rand() % 6 + 2*/4;
//	*n = /*rand() % 6 + 2*/4;
//	printf("%d %d\n", *m, *n);
//	for(i = 1; i <= *m; ++i){
//		for(j = 1; j <= *n; ++j){
//			a[i][j] = rand() % 1001;
//			printf("%5d ", a[i][j]);
//		}
//		putchar('\n');
//	}
//	a[1][1] = a[*m][*n] = 0;
//}
int main()
{
	int m, n;
	int num, i, j, k, l;
	scanf("%d%d", &m, &n);
	for(i = 1; i <= m; ++i){
		for(j = 1; j <= n; ++j){
			scanf("%d", &a[i][j]);
		}
	}
//	suiji(&m, &n, a);
	// 开始循环解题
	for(i = 1; i <= m; ++i){
		for(j = 1; j <= n; ++j){
			for(k = 1; k <= m; ++k){
				for(l = 1; l <= n; ++l){
					// 还没到终点前不能走到同一个点，因此(i, j)不能等于(k, l)
					// 加上小于判断是因为当(i, j)跟(k, l)互换时，最大好感度值必定一样，不必重复计算
					if((i < m || j < n) && i <= k && j <= l){
						continue;
					}
					// 两个点都由上走来的好感度
					num = f[i - 1][j][k - 1][l];
					// 第一个点由上走来，第二个点从左走来，并且两个来源点不重合时的好感度
					if(i - 1 != k && j != l - 1){
						num = max(num, f[i - 1][j][k][l - 1]);
					}
					// 第一个点由左走来，第二个点从上走来，并且两个来源点不重合时的好感度
					if(i != k - 1 && j - 1 != l){
						num = max(num, f[i][j - 1][k - 1][l]);
					}
					// 两个点都由左走来的好感度
					num = max(num, f[i][j - 1][k][l - 1]);
					// 加上当前两点的好感度，即为走到这两点时的最大好感度和
					f[i][j][k][l] = num + a[i][j] + a[k][l];
				}
			}
		}
	}
	// 输出由两条不交叉的线路走到右下角时的最大好感度和
	printf("%d\n", f[m][n][m][n]);
	return 0;
}
