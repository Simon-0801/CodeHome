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
const int maxn = 200 + 5;

int tot;
map<string,int> mp;
char str[105];
int vis[maxn][maxn];

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    tot=0;
    string s1,s2;
    rep(i,1,n){
        rep(j,1,5){
            scanf("%s",str);
            if(j==1){
                s1=str;
                if(!mp.count(s1)){
                    mp[s1]=++tot;
                }
            }
            if(j==5){
                s2=str;
                if(!mp.count(s2)){
                    mp[s2]=++tot;
                }
            }
        }
        vis[mp[s1]][mp[s2]]=1;
    }
    rep(k,1,tot){
        rep(i,1,tot){
            rep(j,1,tot){
                if(i==j)  continue;
                if(vis[i][j])  continue;
                vis[i][j]=(vis[i][k]&vis[k][j]);
            }
        }
    }
    rep(i,1,m){
        rep(j,1,5){
            scanf("%s",str);
            if(j==1){
                s1=str;
            }
            if(j==5){
                s2=str;
            }
        }
        if(!mp.count(s1)||!mp.count(s2)){
            printf("Pants on Fire\n");
            continue;
        }
        if(vis[mp[s1]][mp[s2]]){
            printf("Fact\n");
            continue;
        }
        if(vis[mp[s2]][mp[s1]]){
            printf("Alternative Fact\n");
            continue;
        }
        printf("Pants on Fire\n");
    }
    return 0;
}