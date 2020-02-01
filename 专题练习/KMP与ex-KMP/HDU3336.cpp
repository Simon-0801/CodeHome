#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 200000 + 5;
const int mod = 10007;

char str[maxn];
int nxt[maxn];
int extend[maxn];
// int num[maxn];

void get_nxt(char b[]) 
{
    int len=strlen(b);
    nxt[0]=len;
    int i=0;
    while(i<len-1&&b[i]==b[i+1]) ++i;
    nxt[1]=i;
    i=1;
    for(int k=2;k<len;++k)
	{
        int p=i+nxt[i]-1;
        int L=nxt[k-i];
        if(k-1+L>=p) 
		{
            int j=(p-k+1)>0?(p-k+1):0;
            while(k+j<len&&b[k+j]==b[j]) ++j;
            nxt[k]=j;
            i=k;
        } 
		else nxt[k]=L;
    }
}
void get_extend(char a[],char b[]) //extend[i]保存以a[i]为起始的文本串与模式串的最大公共前缀长度 
{
    int i=0,j,po,alen=strlen(a),blen=strlen(b);
    get_nxt(b);
    while(a[i]==b[i]&&i<alen&&i<blen) i++;
    extend[0]=i;
    po=0;
    for(i=1;i<alen;i++) 
	{
        if(nxt[i-po]+i<extend[po]+po) extend[i]=nxt[i-po];
		else 
		{
            j=extend[po]+po-i;
            if(j<0) j=0;
            while(i+j<alen&&j<blen&&a[j+i]==b[j]) j++;
            extend[i]=j;
            po=i;
        }
    }
}

int main() {
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%s",str);
        get_extend(str,str);
        // memset(num,0,sizeof num);
        int ans=0;
        for(int i=1;i<n;i++){
            if(extend[i]>0){
                ans=(ans+extend[i]%mod)%mod;
            }
        }
        ans=(ans+n)%mod;
        printf("%d\n",ans%mod);
    }
    return 0;
}