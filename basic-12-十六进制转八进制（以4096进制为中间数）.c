#include <stdio.h>
#include <string.h>

#define maxn 1000000 + 100

char Hex[maxn];          //保存十六进制字符串
int HexSquare[maxn / 3]; //保存4096进制
int Oct[maxn / 3 * 4];   //保存八进制
int Hexlen;              //十六进制长度
int HexSqlen;            //4096进制长度
int Octlen;              //八进制长度

//十六进制转4096进制，三个位的十六进制组成一位4096进制
void SetHexSquare()
{
	int i = Hexlen - 1;
	int j;
	int temp;
	HexSqlen = 0;
	while(i >= 0)
	{
		temp = 0;
		i = i - 3;
		for(j = 1; j <= 3;j++)
		{
			if(i + j >= 0)
			{
				if(Hex[j + i] <= 'Z' && Hex[j + i] >= 'A') temp = temp * 16 + Hex[i + j] - 'A' + 10;
				else temp = temp * 16 + Hex[i + j] - '0';
			}
		}
		HexSquare[HexSqlen ++] = temp;
	}
}
//4096进制转八进制，一个位的4096进制转换成4个位的八进制，最高位除外
void SetOct()
{
	int i;
	Octlen = 0;
	for(i = 0; i < HexSqlen - 1; i++)
	{
		Oct[Octlen ++] = HexSquare[i] % 8;
		HexSquare[i] /= 8;
		Oct[Octlen ++] = HexSquare[i] % 8;
		HexSquare[i] /= 8;
		Oct[Octlen ++] = HexSquare[i] % 8;
		HexSquare[i] /= 8;
		Oct[Octlen ++] = HexSquare[i] % 8;
		HexSquare[i] /= 8;
	}
	while(HexSquare[i] != 0)
	{
		Oct[Octlen ++] = HexSquare[i] % 8;
		HexSquare[i] /= 8;
	}
}
//输出八进制
void OutputOct()
{
	int i;
	for(i = Octlen - 1; i >= 0; i--)
	{
		printf("%d",Oct[i]);
	}
	printf("\n");
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",Hex);
		Hexlen = strlen(Hex);
		SetHexSquare();
		SetOct();
		OutputOct();
	}
	return 0;
}
