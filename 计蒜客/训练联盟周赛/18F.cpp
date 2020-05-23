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
const int maxn = 200000 + 5;

VI p;
int n;

VI solve(VI mus,int msk){
    VI res;
    for(auto &nod:mus){
        if(nod&msk){
            res.push_back(nod);
        }
    }
    return res;
}

int getcnt(VI mus,int msk){
    int res=0;
    for(auto &nod:mus){
        if(nod&msk){
            res++;
        }
    }
    return res;
}

int main() {
    int k,tmp;
    scanf("%d%d",&n,&k);
    rep(i,1,n){
        scanf("%d",&tmp);
        p.push_back(tmp);
    }
    int msk=(1<<29);
    int ans=0;
    rep(i,1,30){
        if(getcnt(p,msk)>=k){
            p=solve(p,msk);
            ans|=msk;
        }
        msk>>=1;
    }
    printf("%d\n",ans);
    return 0;
}