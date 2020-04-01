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
const int maxn = 100000 + 5;

int p[maxn],c[maxn];
int m;

void divide(int n){
    m=0;
    rep(i,2,sqrt(n)){
        if(n%i==0){
            p[++m]=i;
            c[m]=0;
            while(n%i==0)  n/=i,c[m]++;
        }
    }
    if(n>1){
        p[++m]=n,c[m]=1;
    }
}

vector<int> ans;

int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    divide(n);
    int tmp=0;
    rep(i,1,m){
        tmp+=c[i];
    }
    if(tmp<k){
        printf("-1\n");
        return 0;
    }
    tmp=1;
    if(k==1){
        printf("%d\n",n);
        return 0;
    }
    rep(i,1,m){
        int f=0;
        rep(j,1,c[i]){
            ans.push_back(p[i]);
            tmp*=p[i];
            k--;
            if(k==1){
                f=1;
                break;
            }
        }
        if(f)  break;
    }
    ans.push_back(n/tmp);
    int len=ans.size();
    rep(i,0,len-1){
        printf("%d%c",ans[i],i==len-1?'\n':' ');
    }
    return 0;
}