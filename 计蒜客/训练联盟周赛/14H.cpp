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
const int maxn = 100 + 5;

ll num[maxn];
set<ll> st;

int main() {
    int m;
    scanf("%d",&m);
    rep(i,1,m){
        scanf("%lld",num+i);
    }
    rep(i,1,m){
        rep(j,i+1,m){
            ll g=__gcd(num[i],num[j]);
            if(g!=1){
                st.insert(g);
                st.insert(num[i]/g);
                st.insert(num[j]/g);
            }
        }
    }
    // printf("%d\n",st.size());
    int sz=st.size();
    int i=0;
    for(auto &x:st){
        printf("%lld",x);
        if(i==sz-1||i%5==4)  printf("\n");
        else  printf(" ");
        i++;
    }
    return 0;
}