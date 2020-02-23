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
const int maxn = 1000 + 5;

struct node
{
    int t,id;
    bool operator< (const node&a) const{
        return t<a.t;
    }
}p[maxn];


int main() {
    int n;
    scanf("%d",&n);
    rep(i,1,n){
        scanf("%d",&p[i].t);
        p[i].id=i;
    }
    sort(p+1,p+1+n);
    ll sum=0,ans=0;
    rep(i,1,n){
        ans+=sum;
        sum+=1ll*p[i].t;
    }
    double avg=ans/(double)n;
    rep(i,1,n){
        printf("%d%c",p[i].id,i==n?'\n':' ');
    }
    printf("%.2lf\n",avg);
    return 0;
}