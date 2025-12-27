#define MAXSIZE 1000

class str
{
public:
    int StrLength(char *s)
    {
        int i=0;
        while(*s!='\0')
        {
            i++;
            s++;
        }
        return i;
    }
    void StrAssigh(char* d,const char* s)
    {
        if(d==nullptr)
                throw "no Space to allocate";
        while(*d++=*s++);
        //取值 & 赋值：取出字符串结束符 \0 (其 ASCII 码值为 0) 赋给 *d。

        //判断：while 检查赋值的结果。结果是 0。

        //终止：因为结果是 0 (False)，循环 停止。
    }
    str Concat();
    str StrSub();
    int StrCmp(char* s1,char* s2)
    {
        while(*s1==*s2)
        {
            if(*s1=='\0')   return 0;
            s1++;
            s2++;
        }
        if(*s1>*s2) return 1;//说明前一个更大
        else return -1; //后一个更大
    }
    int StrIndex(char *S,char* T)
    {
        //模式匹配技术
        int i=0,j=0;
        while(S[i]!='\0' && T[j]!='\0')
        {
            if(S[i]==T[j]){ i++; j++;}
            else{i=i-j+1;j=0;}
        }
        if(T[j]=='\0')  return i-j+1;
        else return 0;
    }
private:
    char arr[MAXSIZE];

};
