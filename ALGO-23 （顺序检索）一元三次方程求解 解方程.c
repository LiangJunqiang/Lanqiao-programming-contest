#include <stdio.h>
#include <math.h>
#define MAXERROR 	0.01
#define MAXROOT		100.0
#define MINROOT		-100.0
typedef struct{
	float state_num[4];	//系数 
	float root[3];		//根 
	int rootc;			//已解出根的数目
}equation;
void narrow_range(equation *ABCDx3, float left, float right);
void find_range(equation *ABCDx3, float left, float right);

void narrow_range(equation *ABCDx3, float left, float right)
{	//已知f(left)和f(right)异号，即零点在left和right之间，本函数的作用是不断缩小范围以求符合误差范围的零点的近似值 
	float x[2] = {left, right};
	float y[2];
	float xmid, ymid;
	int i;
	for(i = 0; i < 2; i++)
	{
		y[i] = ABCDx3->state_num[0] * x[i]*x[i]*x[i] 
				+ ABCDx3->state_num[1] * x[i]*x[i] 
				+ ABCDx3->state_num[2] * x[i] 
				+ ABCDx3->state_num[3];
		
	}
	if(y[1] == 0.0)
	{
		ABCDx3->root[ABCDx3->rootc] = x[1];
		ABCDx3->rootc = ABCDx3->rootc + 1;
		return;
	}
	else if(y[0] == 0.0)
		return;
	while(fabs(x[0] - x[1]) >= MAXERROR)
	{
		xmid = (x[0] + x[1]) / 2.0;
		ymid = ABCDx3->state_num[0] * xmid*xmid*xmid 
				+ ABCDx3->state_num[1] * xmid*xmid
				+ ABCDx3->state_num[2] * xmid 
				+ ABCDx3->state_num[3];
		if(0.0 == ymid)
		{
			ABCDx3->root[ABCDx3->rootc] = xmid;
			ABCDx3->rootc = ABCDx3->rootc + 1;
			return;
		}
		else
		{
			for(i = 0; i < 2; i++)
				if((ymid * y[i]) > 0)
				{
					x[i] = xmid;
					y[i] = ymid;
					break;
				}
		}
	}
	xmid = (x[0] + x[1]) / 2.0;
	ABCDx3->root[ABCDx3->rootc] = xmid;
	ABCDx3->rootc = ABCDx3->rootc + 1;
}
void find_range(equation *ABCDx3, float left, float right)
{
	float x[2];
	float y[2];
	float xmid, ymid;
	int i;
	for(x[0] = left, x[1] = x[0] + 1; x[1] <= right; x[0] += 1, x[1] += 1)
	{
		if((x[0] == left) && (y[0] == 0.0))
		{
			ABCDx3->root[ABCDx3->rootc] = left;
			ABCDx3->rootc = ABCDx3->rootc + 1;
			continue;
		}
		for(i = 0; i < 2; i++)
		{
			y[i] = ABCDx3->state_num[0] * x[i]*x[i]*x[i] 
					+ ABCDx3->state_num[1] * x[i]*x[i] 
					+ ABCDx3->state_num[2] * x[i] 
					+ ABCDx3->state_num[3];
		}
		if((y[0] * y[1]) <= 0)
		{
			narrow_range(ABCDx3, x[0], x[1]);
			if(ABCDx3->rootc >= 3)
				return;
		}
	}
}
int main()
{
	equation ABCDx3;
	int i;
	for(i = 0; i < 4; i++) 
		scanf("%f", &(ABCDx3.state_num[i]));
	ABCDx3.rootc = 0;
	find_range(&ABCDx3, MINROOT, MAXROOT);
	printf("%.2f %.2f %.2f\n", ABCDx3.root[0], ABCDx3.root[1], ABCDx3.root[2]);
	return 0;
}
