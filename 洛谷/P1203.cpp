#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#define INF 0x3f3f3f3f
#define mst(a,num) memset(a,num,sizeof a)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define repd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
const ll mod = 1e9 + 7;
const int maxn = 1500 + 5;

char str[maxn];
int dpl[maxn],dpr[maxn];

int main() {
    int n;
    scanf("%d",&n);
    scanf("%s",str+1);
    rep(i,1,n){
        str[i+n]=str[i+n+n]=str[i];
    }
    int tmp=0,j=n+1;
    while(j<=(n+n)&&str[j]=='w')  j++,tmp++;
    char c=str[j];
    while(j<=(n+n)&&str[j]==c)  j++,tmp++;
    dpr[n+1]=tmp;
    tmp=0,j=n;
    while(j>0&&str[j]=='w')  j--,tmp++;
    c=str[j];
    while(j>0&&str[j]==c)  j--,tmp++;
    dpl[n+1]=tmp;
    int ans=0;
    rep(i,n+1,n+n){
        int tmp=0,j=i;
        while(j<=(n+i-1)&&str[j]=='w')  j++,tmp++;
        char c=str[j];
        while(j<=(n+i-1)&&(str[j]==c||str[j]=='w'))  j++,tmp++;
        dpr[i]=tmp;
        tmp=0,j=i-1;
        while(j>=i-n&&str[j]=='w')  j--,tmp++;
        c=str[j];
        while(j>=i-n&&(str[j]==c||str[j]=='w'))  j--,tmp++;
        dpl[i]=tmp;
        if(dpl[i]+dpr[i]>n)  ans=max(ans,n);
        else  ans=max(ans,dpl[i]+dpr[i]);
    }
    printf("%d\n",ans);
    return 0;
}