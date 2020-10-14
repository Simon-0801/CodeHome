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

char str[55];
int mp[55][55];
int vis[55];

int main() {
    int n;
    scanf("%d",&n);
    rep(i,1,n){
        scanf("%s",str+1);
        rep(j,1,n){
            if(str[j]>='0'&&str[j]<='9')  mp[i][j]=str[j]-'0';
            else  mp[i][j]=str[j]-'A'+10;
        }
    }
    rep(i,1,n){
        mst(vis,0);
        rep(j,1,n){
            vis[mp[i][j]]=1;
        }
        rep(j,0,n-1){
            if(!vis[j]){
                printf("No\n");
                return 0;
            }
        }
    }
    rep(j,1,n){
        mst(vis,0);
        rep(i,1,n){
            vis[mp[i][j]]=1;
        }
        rep(i,0,n-1){
            if(!vis[i]){
                printf("No\n");
                return 0;
            }
        }
    }
    int f=1;
    rep(i,1,n){
        if(mp[1][i]!=i-1){
            f=0;
            break;
        }
    }
    rep(i,1,n){
        if(mp[i][1]!=i-1){
            f=0;
            break;
        }
    }
    if(f)  printf("Reduced\n");
    else  printf("Not Reduced\n");
    return 0;
}