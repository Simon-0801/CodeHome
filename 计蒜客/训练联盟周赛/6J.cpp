#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <bitset>
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
const int maxn = 500 + 5;

bitset<maxn> st[20];
char str[maxn];

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        rep(i,1,m){
            scanf("%s",str+1);
            rep(j,1,n){
                if(str[j]=='1'){
                    st[i][j]=1;
                }
                else{
                    st[i][j]=0;
                }
            }
        }
        int ans=INF;
        int mx=(1<<m)-1;
        rep(state,1,mx){
            bitset<maxn> tmp;
            rep(i,1,n)  tmp[i]=0;
            int cnt=0;
            rep(i,0,m-1){
                if((state&(1<<i))){
                    cnt++;
                    tmp|=st[i+1];
                }
            }
            int f=1;
            rep(i,1,n){
                if(tmp[i]==0){
                    f=0;
                    break;
                }
            }
            if(f){
                ans=min(ans,cnt);
            }
        }
        printf("%d\n",ans==INF?-1:ans);
    }
    return 0;
}