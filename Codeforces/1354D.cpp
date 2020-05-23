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
const int maxn = 1000000 + 5;

int t[maxn];
int n;

int query(int x){
    int ans=0;
    for(;x;x-=(x&-x))  ans+=t[x];
    return ans;
}

void add(int x,int y){
    for(;x<=n;x+=(x&-x))  t[x]+=y;
}

int main() {
    int q,num;
    scanf("%d%d",&n,&q);
    rep(i,1,n){
        scanf("%d",&num);
        add(num,1);
    }
    rep(i,1,q){
        scanf("%d",&num);
        if(num>=1&&num<=n)  add(num,1);
        if(num<0){
            num=-num;
            int l=1,r=n,ans=-1;
            while(l<=r){
                int mid=(l+r)>>1;
                if(query(mid)>=num){
                    ans=mid;
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            add(ans,-1);
        }
    }
    int lef=query(n);
    if(lef==0)  printf("0\n");
    else{
        int l=1,r=n,ans=-1;
        while(l<=r){
            int mid=(l+r)>>1;
            if(query(mid)>0){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}