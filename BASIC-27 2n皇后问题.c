/* 
** 目前最快的2N皇后递归解决方法 
** 2N Queens Problem 
** 试探-回溯算法，递归实现
** 根据http://blog.csdn.net/hackbuteer1/article/details/6657109改编
*/
#include <stdio.h>
#include <stdlib.h>
#define MAXN   32
long sum = 0, upperlim = 1, wall[MAXN] = {0};
// 试探算法从最右边的列开始。  
void BlackWhiteQueen(int line, long row1, long ld1, long rd1, long row2, long ld2, long rd2)
{
    long pos1, pos2, p1, p2;
    if(row1 != upperlim || row2 != upperlim)
    {
        // row，ld，rd进行“或”运算，求得所有可以放置皇后的列,对应位为0，  
        // 然后再取反后“与”上全1的数，来求得当前所有可以放置皇后的位置，对应列改为1  
        // 也就是求取当前哪些列可以放置皇后  
        pos1 = upperlim & ~(row1 | ld1 | rd1) & ~wall[line];
        while(pos1)     // 0 -- 皇后没有地方可放，回溯  
        {
            // 拷贝pos最右边为1的bit，其余bit置0  
            // 也就是取得可以放皇后的最右边的列  
            p1 = pos1 & -pos1;
            // 将pos最右边为1的bit清零  
            // 也就是为获取下一次的最右可用列使用做准备，  
            // 程序将来会回溯到这个位置继续试探
            pos1 -= p1;
            pos2 = upperlim & ~(row2 | ld2 | rd2) & ~wall[line] & ~p1;
            while(pos2)
            {
                p2 = pos2 & -pos2;
                pos2 -= p2;
                // row + p，将当前列置1，表示记录这次皇后放置的列。  
                // (ld + p) << 1，标记当前皇后左边相邻的列不允许下一个皇后放置。  
                // (ld + p) >> 1，标记当前皇后右边相邻的列不允许下一个皇后放置。  
                // 此处的移位操作实际上是记录对角线上的限制，只是因为问题都化归  
                // 到一行网格上来解决，所以表示为列的限制就可以了。显然，随着移位  
                // 在每次选择列之前进行，原来N×N网格中某个已放置的皇后针对其对角线  
                // 上产生的限制都被记录下来了  
                BlackWhiteQueen(line + 1, row1 + p1, (ld1 + p1) << 1, (rd1 + p1) >> 1, row2 + p2, (ld2 + p2) << 1, (rd2 + p2) >> 1); 
            }
        }
    }
    else
        sum++;
}//BlackWhiteQueen
 
int main(int argc, char const *argv[])
{
    int n = 8, i, d;
    scanf("%d", &n);
    // 因为整型数的限制，最大只能32位，  
    // 如果想处理N大于32的皇后问题，需要  
    // 用bitset数据结构进行存储  
    if((n < 1) || (n > 32))
    {
        printf("只能计算1~32之间\n");
        exit(-1);
    }
    // N个皇后只需N位存储，N列中某列有皇后则对应bit置1。 
    upperlim = (upperlim << n) - 1;
    for (i = 0; i < n * n; ++i)
    {
        scanf("%d", &d);
        if(d == 0)
            wall[i / n] |= 1 << (i % n);
    }
    BlackWhiteQueen(0, 0, 0, 0, 0, 0, 0);
    printf("%d", sum);
    return 0;
}
