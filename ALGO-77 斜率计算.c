#include <stdio.h>

int main()
{
	double x1, y1, x2, y2, dx, dy, rs;
	scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
	dx = x1 - x2;
	dy = y1 - y2;
	if(dx == 0 || dx == -0.0)
		printf("INF\n");
	else if(dy == 0)
		printf("0");
	else{
		rs = dy / dx;
		printf("%.0lf\n", rs);
	}
	return 0;
}
