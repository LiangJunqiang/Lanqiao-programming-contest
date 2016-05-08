#include <stdio.h>
#include <string.h>
///*
int y[101];
//*/
int main()
{
	int n[101], W, flag = 0, n_sum = 0, w_ed;
	int i, j, k, l, min;
//	/*
	memset(y, 0, sizeof(y));
//	*/
	scanf("%d%d", &n[0], &W);
	for(i = 1; i <= n[0]; i++)
	{
		scanf("%d", &n[i]);
		n_sum += n[i];		//求n[1...n[0]]的和 
		if(n[i] == 1)
			flag = i;		//n[i]等于 1，记下下标 i 
	}
	if(n[0] == 1){		//当只有一个 n 值（即N = 1）时，只要比较 W 和 n[1]
		if(n[1] == W){
			printf("Yes\n");
			for(i = 1; i <= W*2; i++){
				printf("1 ");
//				/*
				y[1] = y[0];
				y[0] = y[1] + 1;
//				*/
			} 
		}
		else
			printf("No");
	}
	else if(W == 1){	//W 等于 1 时，Yes的条件是至少有一个n[i]等于1 
		if(flag == 0) 
			printf("No");
		else{
			printf("Yes\n");
			printf("%d ", flag);
//			/*
			y[flag] = y[0];
//			*/
			for(i = 1; i <= n[0]; i++)
			{
				if(i != flag){
					while(n[i]--){
						printf("%d %d ", i, i);
//						/*
						y[i] = y[0];
						y[0] = y[i] + 1;
//						*/
					}
				}
			}
			printf("%d ", flag);
//			/*
			y[0] = y[flag] + 1;
//			*/
		}
	}
	else{
		if(n_sum < W)
			printf("No");
		else{
			printf("Yes\n");
			if(n_sum == W){
				for(i = 1; i <= n[0]; i++)
				{
					while(n[i]--){
						printf("%d %d ", i, i);
//						/*
						y[i] = y[0];
						y[0] = y[i] + 1;
//						*/
					}
						
				}
			}
			else{      
				w_ed = 0;
				for(i = 1; ((W - w_ed - n[i]) > 1) && ((n[0] - i) > 2); i++)
				{
					w_ed += n[i];
					while(n[i]--){
						printf("%d %d ", i, i);
//						/*
						y[i] = y[0];
						y[0] = y[i] + 1;
//						*/
					}
				}
				min = i;
				for(j = i + 1; j <= n[0]; j++)
					if(n[j] < n[min])
						min = j;
				for(j = i; j == min; j++)
					;
					
				printf("%d ", j);
				n[j]--;
				w_ed++;
//						/*
				y[j] = y[0];
//						*/	
			
				//去除多余的部分 n_sum - W 
				for(k = 0; (k < n_sum - W) && n[min] > 1; k++)
				{
					printf("%d %d ", min, min);
					n[min]--;
					w_ed++;
//						/*
						y[min] = y[0];
						y[0] = y[min] + 1;
//						*/
				}
				//可能还有残留 n_sum - W - k 
				for(l = i; k < n_sum - W && l < n[0]; l++)
				{
					if(l != min){
						while(k < n_sum - W && n[l] > 0)
						{
							printf("%d %d ", l, l);
							n[l]--;
							k++;
							w_ed++;
//							/*
							y[l] = y[0];
							y[0] = y[l] + 1;
//							*/
						}
					}
				}
				
				printf("%d ", j);
//						/*
				y[0] = y[j] + 1;
//						*/

				printf("%d ", min);
				n[min]--;
				w_ed++;
//						/*
				y[min] = y[0];
//						*/

				for(j = i; j <= n[0]; j++)
					while(n[j]--){
						printf("%d %d ", j, j);
						w_ed++;
//						/*
						y[j] = y[0];
						y[0] = y[j] + 1;
//						*/
					}
					
				printf("%d ", min);
//						/*
				y[0] = y[min] + 1;
//						*/
			}
		}
	}
	putchar('\n');
	printf("y[0] = %d, w_ed = %d, k = %d, n_sum - k = %d\n", y[0], w_ed, k, n_sum - k);
	return 0;
}
