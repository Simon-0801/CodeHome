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
const int maxn = 200000 + 5;

int typ[maxn];
int ans[maxn];
map<int,int> mp;

int main() {
    int q;
    scanf("%d",&q);
    while(q--){
        int n;
        scanf("%d",&n);
        rep(i,1,n){
            scanf("%d",typ+i);
        }
        int flag=0,cnt=1;
        mp.clear();
        ans[1]=0;
        mp[0]=1;
        rep(i,2,n-1){
            if(typ[i]!=typ[i-1]){
                flag=(flag^1);
                ans[i]=flag;
            }
            else{
                ans[i]=flag;
            }
            if(!mp[ans[i]]){
                mp[ans[i]]=1;
                cnt++;
            }
        }
        if(typ[n]==typ[n-1]){
            if(typ[n]==typ[1]){
                ans[n]=flag;
            }
            else{
                ans[n]=(ans[1]^1);
            }
        }
        else{
            if(typ[n]==typ[1]){
                ans[n]=(ans[n-1]^1);
            }
            else{
                if(ans[n-1]==ans[1]){
                    ans[n]=(ans[1]^1);
                }
                else{
                    int f=0;
                    repd(i,n-1,2){
                        if(typ[i-1]==typ[i]){
                            f=i;
                            break;
                        }
                    }
                    if(f){
                        rep(i,f,n-1){
                            ans[i]=(ans[i]^1);
                        }
                        ans[n]=(ans[n-1]^1);
                    }
                    else{
                        ans[n]=2;
                    }
                }
            }
        }
        if(!mp[ans[n]])  cnt++;
        printf("%d\n",cnt);
        rep(i,1,n){
            printf("%d%c",ans[i]+1,i==n?'\n':' ');
        }
    }
    return 0;
}