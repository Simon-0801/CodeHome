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
const int maxn = 500 + 5;

char mp[maxn][maxn];
int dir[5][2]={{0,0},{0,1},{-1,0},{1,0},{0,-1}};

int r,c;
bool check(int x,int y){
    if(x>=1&&x<=r&&y>=1&&y<=c)  return true;
    return false;
}

int main() {
    scanf("%d%d",&r,&c);
    rep(i,1,r){
        scanf("%s",mp[i]+1);
    }
    rep(i,1,r){
        rep(j,1,c){
            if(mp[i][j]=='W'){
                rep(d,1,4){
                    int x=dir[d][0]+i,y=dir[d][1]+j;
                    if(check(x,y)){
                        if(mp[x][y]=='S'){
                            printf("No\n");
                            return 0;
                        }
                        else{
                            if(mp[x][y]=='.')  mp[x][y]='D';
                        }
                    }
                }
            }
        }
    }
    printf("Yes\n");
    rep(i,1,r){
        rep(j,1,c){
            printf("%c",mp[i][j]);
        }
        printf("\n");
    }
    return 0;
}