#include <stdio.h>
int main()
{
	int n, m;
	long Ak, num;
	int i, t1, t2;
	scanf("%d%d", &n, &m);
	Ak = n + m;
	for(num = 0; num < 100000000; num++)
	{
		Ak = num * (n - 1);
		for(i = 0; i <= n && (Ak % (n - 1) == 0); i++){
			Ak = Ak/(n - 1)*n+m;
		}
		if(i > n){
			printf("%d\n", Ak);
			return 0;		
		}
	}
	return 0;
}
