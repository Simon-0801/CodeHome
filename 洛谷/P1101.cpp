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
const int maxn = 100 + 5;

char mp[maxn][maxn];
map<char,int> mm;
vector<PII> v;
int vis[maxn][maxn];

int dir[10][2]={{0,0},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
char str[10]={'#','y','i','z','h','o','n','g'};



bool dfs(int index,int d,int x,int y){
    if(index>7){
        return true;
    }
    if(mp[x][y]!=str[index]){
        return false;
    }
    if(dfs(index+1,d,x+dir[d][0],y+dir[d][1])){
        vis[x][y]=1;
        return true;
    }
}

int main() {
    int n;
    scanf("%d",&n);
    rep(i,1,n){
        scanf("%s",mp[i]+1);
    }
    mm['y']=mm['i']=mm['z']=mm['h']=mm['o']=mm['n']=mm['g']=1;
    rep(i,1,n){
        rep(j,1,n){
            // if(!mm[mp[i][j]])  mp[i][j]='*';
            if(mp[i][j]=='y'){
                v.push_back(PII(i,j));
            }
        }
    }
    for(auto &x:v){
        rep(i,1,8){
            bool flag=dfs(1,i,x.first,x.second);
        }
    }
    rep(i,1,n){
        rep(j,1,n){
            if(vis[i][j])  printf("%c",mp[i][j]);
            else  printf("%c",'*');
        }
        printf("\n");
    }
    return 0;
}