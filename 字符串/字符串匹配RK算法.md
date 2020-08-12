### RK
把模式串通过hash算出hash值，然后在主串中切割和模式串一样长度的字串串 比较hash值。

### code
[reference](https://www.jianshu.com/p/40243a33d8da)

~~~ c++
bool RK(const char *main, const char *pattern)
{
    int mlen = strlen(main);
    int plen = strlen(pattern);

    int target = 0;
    for(int i = 0; i < plen; i++)
    {
        target += (pattern[i] - ' ');
    }
    int last = 0;
    for(int i = 0; i <= (mlen - plen); i++)
    {
        if(last > 0)
        {
            last = last - (main[i-1] - ' ') + (main[i+plen-1] - ' ');
        }
        else
        {
            for(int j = 0; j < plen; j++)
            {
                last += (main[i+j] - ' ');
            }
        }
        if(last == target && 0 == strncmp(main+i, pattern, plen))
        {
            //printf("RX match succ: index = %d\n", i);
            return  true;
        }
    }
    //printf("BF match fail!\n");
    return  false;
}
~~~
