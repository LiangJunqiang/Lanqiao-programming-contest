#include <stdio.h>
#include <math.h>
typedef struct fushu{
	float shibu;
	float xubu;
}fushu;
void Normalize(fushu *f)
{
	float a = f->shibu, b = f->xubu;
	f->shibu = a/sqrt(a*a+b*b);
	f->xubu = b/sqrt(a*a+b*b);
}
int main()
{
	fushu f;
	scanf("%f%f", &f.shibu, &f.xubu);
	Normalize(&f);
	printf("%.1f+%.1fi", f.shibu, f.xubu);
	return 0;
} 

