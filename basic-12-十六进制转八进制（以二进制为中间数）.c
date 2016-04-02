#include <stdio.h>
#include <string.h>
#include <math.h>
#define Length 100010
#define Len 200020
#define OK 		1
#define ERROR 	0
typedef int Status;
typedef char QElemType;
typedef struct BinaryS{
	char bs[13];
	int front;
	int rear;
	int maxsize;
}BinaryS;
Status EnQueue(BinaryS *Q, QElemType e){
	if((Q->rear + 1) % Q->maxsize == Q->front)
		return ERROR;
	Q->bs[Q->rear] = e;
	Q->rear = (Q->rear + 1) % Q->maxsize;
	return OK;
}//EnQueue
Status DeQueue(BinaryS *Q, QElemType *e){
	if(Q->front == Q->rear) return ERROR;			//队列为空 
	*e = Q->bs[Q->front];
	Q->front = (Q->front + 1) % Q->maxsize;
	return OK;
}//DeQueue
void HexConversion(char s[], char e[])
{	//十六进制s[]转换为八进制存放在e[]中 
	int len, i, j, si, ei = 0;
	char b;
	BinaryS Q;
	len = strlen(s);
	Q.front = Q.rear = 0;
	Q.maxsize = 13;
	for(i = len; i > 0; i -= 3){
		for(si = 1; i - si >= 0 && si <= 3; si++){
			if(s[i - si] >= '0' && s[i - si] <= '9')
				s[i - si] -= '0';
			else if(s[i - si] >= 'A' && s[i - si] <= 'F')
				s[i - si] = s[i - si] - 'A' + 10;
			else
				return;
			j = 4;
			while(j--){
				b = s[i - si] % 2;
				s[i - si] /= 2;
				EnQueue(&Q, b);
			}
		}
		//每连续三个出队并转换为8进制存放于e[]中, e[]为8进制的倒序
		while(Q.front != Q.rear){
			e[ei] = '0';
			for(j = 0; Q.front != Q.rear && j < 3; j++){
				DeQueue(&Q, &b);
				e[ei] += b * pow(2, j);
			}
			ei++;
		}	 
	}
	e[ei] = '\0';
}//HexConversion
int main()
{
	int n, i, len, j;
	char sixteen[Length], eight[Len];
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%s", sixteen);
		HexConversion(sixteen, eight);
		len = strlen(eight);
		for(j = len - 1; j >= 0; j--)
			if(eight[j] != '0')
				break;
		for(; j >= 0; j--)
			printf("%c", eight[j]);
		putchar('\n');
	}
	return 0;
}//main

