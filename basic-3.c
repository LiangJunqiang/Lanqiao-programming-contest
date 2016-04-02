#include <stdio.h>
main()
{
	int n, m, i, j;/* n为行数，m为列数；i，j用于控制两重循环次数； */ 
	char k = 'A';/* 用于一重循环输出字符 */
	char t;/* 用于二重循环输出字符 */ 
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; ++i){
		while(k > 'Z'){
			k = k - 26;
		} 
		t = k;
		j = 0;
		if(t <= 'Z' && t > 'A'){
			for(; j < m && t > 'A'; j++){
				while(t > 'Z'){
					t = t - 26;
				} 
				printf("%c", t);
				t--;
			}
		}
		for(; j < m; j++){
			while(t > 'Z'){
				t = t - 26;
			} 
			printf("%c", t);
				t++;
		}
		printf("\n");
		k++;
	}
	return 0;
}
