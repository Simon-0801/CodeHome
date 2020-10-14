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

int a[maxn];
int sum[maxn];
int n;

struct node
{
    int id,t,ans;
};

node qry[maxn];

int cmp(node a,node b){
    return a.t<b.t;
}

int cmpid(node a,node b){
    return a.id<b.id;
}

int solve(int num){
    int res=0;
    int pos=0;
    while(pos<=n){
        int en=upper_bound(sum+1,sum+1+n,sum[pos]+num)-sum;
        en--;
        if(pos>=en){
            return -1;
        }
        res++;
        pos=en;
        if(pos==n)  break;
    }
    return res;
}

int main() {
    scanf("%d",&n);
    sum[0]=0;
    rep(i,1,n){
        scanf("%d",a+i);
        sum[i]=a[i]+sum[i-1];
    }
    int q;
    scanf("%d",&q);
    rep(i,1,q){
        scanf("%d",&qry[i].t);
        qry[i].id=i;
    }
    sort(qry+1,qry+1+q,cmp);
    int tans=-1;
    rep(i,1,q){
        if(i==1||qry[i].t!=qry[i-1].t){
            tans=solve(qry[i].t);
        }
        qry[i].ans=tans;
    }
    sort(qry+1,qry+1+q,cmpid);
    rep(i,1,q){
        if(qry[i].ans==-1){
            printf("Impossible\n");
        }
        else
        {
            printf("%d\n",qry[i].ans);
        }
        
    }
    return 0;
}