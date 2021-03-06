#include<cstdio>
#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<string>
#include<cstring>
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<set>
#include<cmath>
using namespace std;
const int mmax = 10010;
const int inf = 0x3fffffff;
struct Bignum
{
    int Sz;
    int num[mmax];//根据实际情况确定数组长度 
    void print()
    {
        for(int i=Sz-1;i>=0;i--)
            printf("%0x",num[i]);
        puts("");
    }
    Bignum() {}
    Bignum(int sz,char *a)
    {
        Sz=sz;
        for(int i=0;i<Sz;i++)
        {
            num[i]=a[Sz-1-i]-'0';
        }
    }
    Bignum(int sz,int *a)
    {
        Sz=sz;
        for(int i=0;i<Sz;i++)
            num[i]=a[i];
    }
    //以16进制存储 
    Bignum(int x)
    {
        Sz=0;
        while(x)
        {
            num[Sz++]=x%16;
            x/=16;
        }
    }
    Bignum operator + (const Bignum &a)
    {
        int tmp[mmax];
        memset(tmp,0,sizeof tmp);
        int len=max(Sz,a.Sz);
        for(int i=0;i<len;i++)
        {
            tmp[i]+=num[i]+a.num[i];
            tmp[i+1]+=tmp[i]/10;
            tmp[i]%=10;
        }
        return Bignum(len+(tmp[len]?1:0),tmp);
    }
    Bignum operator - (const Bignum &a)
    {
        int tmp[mmax];
        memset(tmp,0,sizeof tmp);
        int len=max(Sz,a.Sz);
        for(int i=0;i<len;i++)
        {
            tmp[i]+=num[i]-a.num[i];
            if(tmp[i]<0)
            {
                tmp[i+1]-=1;
                tmp[i]+=10;
            }
        }
        for(int i=len-1;i>=0;i--)
        {
            if(tmp[i])
                return Bignum(i+1,tmp);
        }
        return Bignum(1,tmp);
    }
    //16进制大数乘法 
    Bignum operator * (const Bignum &a)
    {
        int tmp[mmax];
        memset(tmp,0,sizeof tmp);
        for(int i=0;i<Sz;i++)
            for(int j=0;j<a.Sz;j++)
            {
                tmp[i+j]+=num[i]*a.num[j];
            }
        for(int i=0;i<Sz+a.Sz;i++)
        {
            tmp[i+1]+=tmp[i]/16;
            tmp[i]%=16;
        }
        for(int i=Sz+a.Sz-1;i>=0;i--)
        {
            if(tmp[i])
                return Bignum(i+1,tmp);
        }
        return Bignum(1,tmp);
    }
};
int main()
{
    int n;
    while(~scanf("%d",&n) && n>=0)
    {
        Bignum ans(1);
        for(int i=1;i<=n;i++)
            ans=ans*Bignum(i);
        int cnt=0;
        for(int i=0;i<ans.Sz;i++)
        {
            if(ans.num[i]==0)
                cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
