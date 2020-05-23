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

ll num[maxn],cp[maxn];

int main() {
    int n;
    scanf("%d",&n);
    rep(i,1,n){
        scanf("%lld",num+i);
        cp[i]=num[i];
    }
    sort(cp+1,cp+n+1);
    rep(i,1,n){
        cp[i]=cp[i]-num[i];
    }
    int l=0,r=n+1;
    rep(i,1,n){
        if(cp[i]){
            l=i;
            break;
        }
    }
    repd(i,n,1){
        if(cp[i]){
            r=i;
            break;
        }
    }
    if(l==0){
        printf("1 1\n");
        return 0;
    }
    if(l==r){
        printf("impossible\n");
        return 0;
    }
    int flag=1,tl=l,tr=r;
    while(tl<=tr){
        if(cp[tl]+cp[tr]!=0){
            flag=0;
            break;
        }
        tl++,tr--;
    }
    if(flag){
        printf("%d %d\n",l,r);
    }
    else
    {
        printf("impossible\n");
    }
    
    // int cnt=0,flag=0;
    // rep(i,1,n){
    //     if(cp[i]==0)  continue;
    //     int j=i;
    //     cnt++;
    //     if(cnt>1) break;
    //     vector<ll> sta;
    //     sta.push_back(cp[j]);
    //     j++;
    //     while(j<=n){
    //         if(sta.empty())  break;
    //         if(cp[j]<0)  sta.push_back(cp[j]);
    //         else if(cp[j]==0){
    //             j++;
    //             continue;
    //         }
    //         else{
    //             ll tp=sta.back();
    //             if(tp+cp[j]!=0)
    //         }
    //     }
    // }
    return 0;
}