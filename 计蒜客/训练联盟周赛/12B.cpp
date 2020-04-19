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
const int maxn = 20 + 5;

int c[maxn][maxn];

void init(){
    c[1][0]=c[1][1]=1;
    rep(i,2,15){
        c[i][0]=c[i][i]=1;
        rep(j,1,i-1){
            c[i][j]=c[i-1][j]+c[i-1][j-1];
        }
    }
}

int main() {
    int t;
    scanf("%d",&t);
    init();
    while(t--){
        int r,s,x,y,w;
        scanf("%d%d%d%d%d",&r,&s,&x,&y,&w);
        double p=1.0*(s-r+1)/s;
        double ans=0.0;
        rep(i,x,y){
            double tmp=1.0;
            rep(k,1,i){
                tmp*=p;
            }
            rep(k,1,y-i){
                tmp*=(1.0-p);
            }
            ans+=tmp*c[y][i];
        }
        if(ans*w>1){
            printf("yes\n");
        }
        else  printf("no\n");
    }
    return 0;
}