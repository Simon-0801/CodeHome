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

char mp[maxn][maxn];
int s[maxn];

int main() {
    int h,w;
    scanf("%d%d",&h,&w);
    rep(i,1,h){
        scanf("%s",mp[i]+1);
    }
    double sum=0,cnt=0;
    rep(i,1,h){
        rep(j,1,w){
            if(mp[i][j]!='.'){
                sum+=1.0*j-0.5;
                cnt+=1.0;
            }
        }
    }
    int l,r;
    double ans=sum/cnt;
    rep(i,1,w){
        if(mp[h][i]!='.'){
            l=1.0*i-1.0;
            break;
        }
    }
    repd(i,w,1){
        if(mp[h][i]!='.'){
            r=1.0*i;
            break;
        }
    }
    if(ans>r){
        printf("right\n");
    }
    else if(ans<l){
        printf("left\n");
    }
    else{
        printf("balanced\n");
    }
    return 0;
}