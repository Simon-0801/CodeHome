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

void dfs(int n){
    vector<int> v;
    repd(i,31,0){
        if((1<<i)&n){
            v.push_back(i);
        }
    }
    int len=v.size();
    int tmp=v[0];
    printf("2");
    if(tmp>1){
        printf("(");
        dfs(tmp);
        printf(")");
    }
    else if(tmp<1){
        printf("(0)");
    }
    if(len>1){
        rep(i,1,len-1){
            printf("+2");
            tmp=v[i];
            if(tmp>1){
                printf("(");
                dfs(tmp);
                printf(")");
            }
            else if(tmp<1){
                printf("(0)");
            }
        }
    }
}

int main() {
    int n;
    scanf("%d",&n);
    dfs(n);
    return 0;
}