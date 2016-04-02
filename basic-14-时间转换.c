#include <stdio.h>

int main()
{
	int t, h, m, s;
	scanf("%d", &t);
	s = t % 60;
	m = (t - s) / 60 % 60;
	h = (t - s - m * 60) / 60 / 60;
	printf("%d:%d:%d", h, m, s);
	return 0;
}
