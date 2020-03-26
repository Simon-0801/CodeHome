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
const int maxn = 300000 + 5;

vector<int> ans;
int pre[maxn],suf[maxn];
int h[maxn],th[maxn];
int vis[maxn];
vector<int> v;
map<int,int> mp;
set<int> st;

// int bsearch(int st,int en,int num){
//     int res=-1;
//     int l=st,r=en;
//     while(l<=r){
//         if()
//     }
// }

int main() {
    int k,n;
    scanf("%d",&k);
    rep(i,1,k){
        scanf("%d",&n);
        rep(j,1,n){
            scanf("%d",h+j);
            th[j]=h[j];
        }
        sort(th+1,th+n+1);
        int cnt=unique(th+1,th+n+1)-th-1;
        rep(j,1,cnt){
            mp[th[j]]=j;
        }
        suf[n]=-1;
        int mx=h[n];
        repd(j,n-1,1){
            if(mx<=h[j]){
                suf[j]=-1;
            }
            else{
                suf[j]=mx;
            }
            mx=max(mx,h[j]);
        }
        // v.clear();
        // v.push_back(h[1]);
        st.clear();
        // mst(vis,0);
        pre[1]=-1;
        st.insert(h[1]);
        rep(j,2,n){
            auto pos=st.upper_bound(h[j]);
            if(pos==st.end()){
                pre[j]=-1;
            }
            else{
                pre[j]=*pos;
            }
            // vis[mp[h[j]]]=1;
            st.insert(h[j]);
        }
        int flag=0;
        rep(i,2,n-1){
            if(pre[i]==-1||suf[i]==-1)  continue;
            if(pre[i]<suf[i]){
                flag=1;
                break;
            }
        }
        if(flag)  ans.push_back(i);
    }
    printf("%d\n",ans.size());
    for(auto &x:ans){
        printf("%d\n",x);
    }
    return 0;
}