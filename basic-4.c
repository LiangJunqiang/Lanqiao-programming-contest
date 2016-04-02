#include <stdio.h>
main()
{
	int n, i, num[1000], sum = 0, ma, mi;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &num[i]);
	ma = mi = 0;
	for(i = 0; i < n; i++){
		if(num[i] > num[ma])
			ma = i;
		if(num[i] < num[mi])
			mi = i;
		sum = sum + num[i];
	}
	printf("%d\n", num[ma]);
	printf("%d\n", num[mi]);
	printf("%d\n", sum);
	return 0;
}
