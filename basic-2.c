#include <stdio.h>
main()
{
	int ten, temp, i;
	for(ten = 0; ten < 32; ++ten){
		temp = ten;
		for(i = 16; i >= 1; i = i / 2){
			if(temp / i == 1)
				printf("1");
			else printf("0");
			temp = temp % i;
		}
		printf("\n");
	}
	return 0;
}