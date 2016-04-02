#include <stdio.h>
main()
{
	int n, a, num[1000], i, k = 0;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &num[i]);
	scanf("%d", &a);
	for(i = 0; i < n; i++)
		if(num[i] == a){
			k = i + 1;
			break;
		}
	if(k != 0)
		printf("%d", k);
	else printf("-1");
	return 0;
} 
