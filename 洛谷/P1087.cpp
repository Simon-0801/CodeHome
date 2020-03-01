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
const int maxn = 1024 + 5;

char str[maxn];
int sum0[maxn],sum1[maxn];

void dfs(int l,int r){
    if(l>r)  return;
    if(l==r){
        if(str[l]=='0')  printf("B");
        if(str[l]=='1')  printf("I");
        return;
    }
    int mid=(l+r)/2;
    dfs(l,mid);
    dfs(mid+1,r);
    if(sum0[r]-sum0[l-1]==r-l+1){
        printf("B");
    }
    else if(sum1[r]-sum1[l-1]==r-l+1){
        printf("I");
    }
    else{
        printf("F");
    }
}

int main() {
    int n;
    scanf("%d",&n);
    scanf("%s",str+1);
    int len=strlen(str+1);
    rep(i,1,len){
        if(str[i]=='0'){
            sum0[i]=sum0[i-1]+1;
            sum1[i]=sum1[i-1];
        }
        else{
            sum0[i]=sum0[i-1];
            sum1[i]=sum1[i-1]+1;
        }
    }
    dfs(1,len);
    return 0;
}