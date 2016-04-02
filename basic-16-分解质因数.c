#include <stdio.h>
#include <math.h>

int main()
{
	int a, b, i, n, j, k, one = 0;
	scanf("%d%d", &a, &b);
	if(a == 1){
		printf("%d=%d\n", a, a);
		a++;
	}
	for(i = a; i <= b; i++){
		k = i;
		one = 0;
		while(k != 1){
			for(n = 2; n <= k; ++n){
				for(j = 2; j <= sqrt(n); ++j){
					if(n % j == 0)
						break;
					else
						continue;
				}
				if(j > sqrt(n) && k % n == 0){
					if(one == 0){
						printf("%d=%d", i, n);
						one = 1;
					}
					else
						printf("*%d", n);
					k /= n;
					break;
				}			
			}
		}
		putchar('\n');
	}
	return 0;
}
