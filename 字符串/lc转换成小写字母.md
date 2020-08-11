### 题目
实现函数 ToLowerCase()，该函数接收一个字符串参数 str，并将该字符串中的大写字母转换成小写字母，之后返回新的字符串。

 ### 代码
 ~~~ c++
 class Solution {
public:
    string toLowerCase(string str) {
        string res;
        for(int i = 0;i<str.size();i++){
            if(str[i]>='A'&&str[i]<='Z') res += str[i]+32 ;
            else res+=str[i];
        }
        return res;
    }
};

~~~
