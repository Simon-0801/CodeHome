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
const int maxn = 100000 + 5;

set<ll> st;

int main() {
    ll k;
    scanf("%lld",&k);
    for(ll i=1;i*i<=k;i++){
        if(k%i==0){
           ll a=min(i,k/i),b=max(i,k/i);
           if(b-a==0)  continue;
           ll n,m;
           if((a+b)%2==0){
               n=(a+b)/2;
               st.insert(-n*n);
           }
           if((b-a)%2==0){
               m=(b-a)/2;
               st.insert(m*m);
           }
        //    a=k/i,b=i;
        //    if((a+b)%2==0){
        //        n=(a+b)/2;
        //        st.insert(-n*n);
        //    }
        //    if((b-a)%2==0){
        //        m=(b-a)/2;
        //        st.insert(m*m);
        //    }
        }
    }
    for(ll i=1;i*i<=k;i++){
        ll lft=k-i*i;
        if(lft==0)  continue;
        ll tmp=sqrt(lft);
        if(tmp*tmp==lft){
            st.insert(-i*i);
            // ll mn=min(tmp,i);
            // ll mx=max(tmp,i);
            // st.insert(-mn*mn);
            // st.insert(-mx*mx);
        }
    }
    printf("%lld\n",st.size());
    if(st.size()>0){
        for(auto &x:st){
            printf("%lld ",x);
        }
        printf("\n");
    }
    return 0;
}