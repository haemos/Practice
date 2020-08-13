### KMP算法
KMP 算法是 D.E.Knuth、J,H,Morris 和 V.R.Pratt 三位神人共同提出的，称之为 Knuth-Morria-Pratt 算法，简称 KMP 算法。该算法相对于 Brute-Force（暴力）算法有比较大的改进，主要是消除了主串指针的回溯，从而使算法效率有了某种程度的提高。

[reference](https://blog.csdn.net/dark_cy/article/details/88698736)

### code
构建next数组
~~~ c++
void Getnext(int next[],String t)
{
   int j=0,k=-1;
   next[0]=-1;
   while(j<t.length-1)
   {
      if(k == -1 || t[j] == t[k])
      {
         j++;k++;
         next[j] = k;
      }
      else k = next[k];//此语句是这段代码最反人类的地方，如果你一下子就能看懂，那么请允许我称呼你一声大神！
   }
}
~~~ 
kmp
~~~ c++
int KMP(String s,String t)
{
   int next[MaxSize],i=0;j=0;
   Getnext(t,next);
   while(i<s.length&&j<t.length)
   {
      if(j==-1 || s[i]==t[j])
      {
         i++;
         j++;
      }
      else j=next[j];               //j回退。。。
   }
   if(j>=t.length)
       return (i-t.length);         //匹配成功，返回子串的位置
   else
      return (-1);                  //没找到
}
~~~ 
