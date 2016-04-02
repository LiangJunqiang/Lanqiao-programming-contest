#include <stdio.h>
int main(int argc, char const *argv[])
{
    int N, i, j, k, odd = 0;  //有odd个字母出现奇数次
    char s[8001] = {'\0'}; //保证可存下结尾的'\0'
    int b[26] = {0};    //记录'a'~'z'出现的次数
    char charodd = '\0';//出现奇数次的字母
    int change = 0;
    scanf("%d", &N);
    getchar(); 
    for(i=0;i<N;i++)   
        scanf("%c",&s[i]); 
    //判断是否可变为回文串
    for (i = 0; i < N; ++i)
        b[s[i] - 'a']++;    //相应字母字数加一
    for (i = 0; i < 26; i++)
        if (b[i] & 1)      // b[i]是奇数
        {
            odd++;
            charodd = i + 'a';  // 记录该字母
        }
    if(odd > 1)
        printf("Impossible\n");
    else{
        for (i = 0; i < N / 2; ++i) //依次考虑左侧的字母
        {
            if(s[i] == charodd)//是charodd，转而考虑右侧字母
            {
                for(j = i; j <= N - i - 1; j++)//从左侧该位置开始，找相同字母
                    if(s[j] == s[N - i - 1])    //找到
                        break;
                change += j - i;    //需要j - 1次移动可到左侧位置
                for(k = j; k > i; k--)  //实现字母的移动
                    s[k] = s[k - 1];
                s[i] = s[N - i - 1];
            }
            else//考虑左侧字母
            {
                for(j = N - i - 1; j >= i; j--)//从右侧对称位置开始，找相同字母
                    if(s[j] == s[i])    //找到
                        break;
                change += N - 1 - i - j;    //需要N - i - 1 - j次移动可到右侧位置
                for(k = j; k < N - i - 1; k++)//实现字母的移动
                    s[k] = s[k + 1];
                s[N - i - 1] = s[i];
            }
        }
        printf("%d\n", change);
    }
    return 0;
}
