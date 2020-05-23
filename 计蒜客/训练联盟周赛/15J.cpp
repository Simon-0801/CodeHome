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
const int maxn = 2000000 + 5;

int vis[maxn];
int base;

bool check(int n){
    int a[105];
    int tot=0;
    while(n){
        a[++tot]=n%base;
        n/=base;
    }
    rep(i,1,tot){
        if(a[i]!=a[tot-i+1])  return false;
    }
    return true;
}

int main() {
    int a,b,k;
    scanf("%d%d%d",&a,&b,&k);
    int ans=0;
    rep(n,a,b){
        int f=1;
        rep(i,2,k){
            base=i;
            if(!check(n)){
                f=0;
                break;
            }
        }
        if(f)  ans++;
    }
    printf("%d",ans);

    // int cnt=0;
    // mst(vis,0);
    // rep(i,2,100){
    //     base=i;
    //     cnt=0;
    //     rep(n,0,2000000){
    //         if(check(n))  cnt++;
    //         else  vis[n]=1;
    //     }
    //     int f=1;
    //     rep(n,0,2000000){
    //         if(!vis[n]){
    //             f=0;
    //             break;
    //         }
    //     }
    //     if(f){
    //         cout<<i<<endl;
    //         break;
    //     }
    //     // if(!cnt){
    //     //     cout<<i<<"!!!"<<endl;
    //     //     break;
    //     // }
    //     cout<<i<<":"<<cnt<<endl;
    // }
    return 0;
}