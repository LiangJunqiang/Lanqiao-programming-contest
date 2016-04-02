#include <stdio.h>

int main()
{
	int i, d2 = 1, d3 = 1;
	char a[10], b[10];
	gets(a);
	gets(b);
	for(i = 0; a[i] != 0 && b[i] != 0; ++i){
		if(a[i] == b[i])
			continue;
		else{
			d2 = 0;
			if(a[i] == b[i] + ('a' - 'A') || a[i] + ('a' - 'A') == b[i])
				continue;
			else{
				d3 = 0;
			}
		}
	}
	if(a[i] == 0 && b[i] != 0 || a[i] != 0 && b[i] == 0)
		putchar('1');
	else{
		if(d2)
			putchar('2');
		else if(d3)
			putchar('3');
		else
			putchar('4');
	}
	return 0;
}
