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
const int maxn = 50 + 5;

ll a[maxn];
map<int,int> mp;

int main() {
    int t,n,k;
    scanf("%d",&t);
    while(t--){
        mp.clear();
        scanf("%d%d",&n,&k);
        rep(i,1,n){
            scanf("%lld",a+i);
        }
        int ff=1;
        rep(i,1,n){
            ll num=a[i];
            int pre=0;
            while(num>0){
                int tmp=0;
                while(num%k==0){
                    tmp++;
                    num/=k;
                }
                num-=1;
                if(!(num==0||num%k==0)){
                    ff=0;
                    break;
                }
                mp[tmp+pre]++;
                pre=tmp+pre;
            }
        }
        if(!ff){
            printf("NO\n");
            continue;
        }
        int flag=1;
        for(auto &x:mp){
            if(x.second>1){
                flag=0;
                break;
            }
        }
        if(flag)  printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}