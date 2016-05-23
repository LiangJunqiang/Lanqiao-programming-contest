#include <stdio.h>
#define MAXN	30000
int h[MAXN] = {0};
int min[MAXN/100] = {0};
int main()
{
	int i = 0, n, maxlen, j, k;
	char c;
	scanf("%d%c", &h[i], &c);
	while(c != '\n'){
		i++;
		scanf("%d%c", &h[i], &c);
	}
	n = i + 1;
	maxlen = 0;
	//把众多导弹分为min[0] + 1个高度递减队列既所求的第二个数值，最长队列长度为maxlen，既所求的第一个数值
	for(i = 0; i < n; i++)
	{	//对每一个导弹做以下判断和操作
		for(j = 0; j < maxlen; j++){
			if(h[j] < h[i]){	//找出前面高度比它低的导弹
				if(h[i] > h[i - 1]){	//若它也比它的前一个高，说明它不能跟着前一个的屁股走（脱队） 
					for(k = 1; k <= min[0]; k++)
						if(h[i] <= min[k]){	//在前面的已知队伍中，有队尾元素大于等于它，则允许它入队 
							min[k] = h[i];
							break;
						}
					if(k > min[0])	//没有能加入的队伍，只好自己另辟江山，此时应补加一队，它的前一个元素为队尾元素
						min[++min[0]] = h[i - 1];
				}
				h[j] = h[i];	//把此导弹调到前面，以求最长队列，中间元素无关痛痒，不管了 
				break;	//跳到处理下一个导弹 
			}
		}
		if(j >= maxlen){	//最长队列中，它比前面的导弹都小，加入到队尾吧，但先不用记录，最长队队长加一 
			h[j] = h[i];
			maxlen = j + 1;
		}
	}
	printf("%d\n%d\n", maxlen, min[0] + 1);
	return 0;
}
