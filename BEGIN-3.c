#include <stdio.h>
#define PI 3.14159265358979323
main()
{
	double r, area;
	scanf("%lf", &r);
	area = PI * r * r;
	printf("%.7lf", area);
	return 0;
}