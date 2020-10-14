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

ll a[maxn];
ll w[maxn];
int n,m;
ll lsum,rsum;
set<ll> st;
vector<ll> lft;

void dfs(int id){
    if(id>m){
        if(lsum<rsum){
            st.insert(rsum-lsum);
        }
        return;
    }
    dfs(id+1);
    lsum+=w[id];
    dfs(id+1);
    lsum-=w[id];
    rsum+=w[id];
    dfs(id+1);
    rsum-=w[id];
}

bool check(ll num){
    for(auto &nod:lft){
        if(st.find(nod+num)!=st.end()||st.find(nod-num)!=st.end()||st.find(num-nod)!=st.end())  continue;
        if(nod==num)  continue;
        return false;
    }
    return true;
}

int main() {
    while (scanf("%d%d",&n,&m)&&n&&m){
        rep(i,1,n){
            scanf("%lld",a+i);
        }
        rep(i,1,m){
            scanf("%lld",w+i);
        }
        lsum=rsum=0;
        st.clear();
        dfs(1);
        lft.clear();
        rep(i,1,n){
            if(st.find(a[i])==st.end()){
                lft.push_back(a[i]);
            }
        }
        if(lft.size()==0){
            printf("0\n");
            continue;
        }
        ll tmp=lft[0],added,mn=1e18;
        if(check(tmp)){
            mn=min(mn,tmp);
        }
        for(auto &x:st){
            if(tmp<x){
                added=x-tmp;
            }
            else{
                added=tmp-x;
            }
            if(check(added)){
                mn=min(mn,added);
            }
            added=tmp+x;
            if(check(added)){
                mn=min(mn,added);
            }
        }
        if(mn==1e18){
            printf("-1\n");
            continue;
        }
        printf("%lld\n",mn);
    }
    return 0;
}