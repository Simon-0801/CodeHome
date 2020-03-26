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

vector<int> v1,v2;

int main() {
    int n,m,u,v;
    scanf("%d%d",&n,&m);
    rep(i,1,m){
        scanf("%d%d",&u,&v);
        if(u>v)  v1.push_back(i);
        else  v2.push_back(i);
    }
    if(v1.size()<v2.size()){
        printf("%d\n",v1.size());
        for(auto &x:v1){
            printf("%d\n",x);
        }
    }
    else{
        printf("%d\n",v2.size());
        for(auto &x:v2){
            printf("%d\n",x);
        }
    }
    return 0;
}