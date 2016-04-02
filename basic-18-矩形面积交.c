#include <stdio.h>
#define exchange(a, b){\
    int t;\
    t = a;\
    a = b;\
    b = t;\
}

int main()
{
	double s, x[2][2], y[2][2], left, right, top, down, dx, dy;		/* x(y)[0]为第一个矩形的数据，x(y)[1]为第二个矩形的数据 */
	int i, j;
	for(i = 0; i < 2; ++i)
		for(j = 0; j < 2; ++j)
			scanf("%lf%lf", &x[i][j], &y[i][j]);		/* 输入四个点 */
	for(i = 0; i < 2; ++i){								/* 按大小排序 */
		if(x[i][0] > x[i][1])
			exchange(x[i][0], x[i][1]);
		if(y[i][0] > y[i][1])
			exchange(y[i][0], y[i][1]);
	}
	left = (x[0][0] >= x[1][0]) ? x[0][0] : x[1][0];	//推算相交区域的左边界 
	right = (x[0][1] <= x[1][1]) ? x[0][1] : x[1][1];	//推算相交区域的右边界 
	top = (y[0][1] <= y[1][1]) ? y[0][1] : y[1][1];		//推算相交区域的上边界 
	down = (y[0][0] >= y[1][0]) ? y[0][0] : y[1][0];	//推算相交区域的下边界
	dx = right - left;		//相交矩形的宽度 
	dy = top - down;		//相交矩形的高度
	if(dx <= 0 || dy <= 0)	//宽高不合法（两矩形不相交） 
		s = 0;
	else
		s = dx * dy;
	printf("%.2lf\n", s);
	return 0;
}
