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
typedef vector<int> VI;
const ll mod = 1e9 + 7;
const int maxn = 100000 + 5;

int pos[maxn];
int L,n,k;

bool check(int len){
    int num=0;
    rep(i,2,n){
        int dis=pos[i]-pos[i-1];
        int tmp=dis/len;
        num+=tmp;
        if(dis%len==0){
            num--;
        }
    }
    if(num<=k)  return true;
    else  return false;
}

int main() {
    scanf("%d%d%d",&L,&n,&k);
    rep(i,1,n){
        scanf("%d",pos+i);
    }
    int l=0,r=L,ans;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    printf("%d\n",ans);
    return 0;
}