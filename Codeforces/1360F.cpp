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

char str[15][15];
int mp[15][15];
int n,m;

int check(int i,int j){
    int res=0;
    rep(k,1,m){
        if(str[i][k]!=str[j][k])  res++;
    }
    return res;
}

bool check1(char a[]){
    rep(i,1,n){
        int dif=0;
        rep(j,1,m){
            if(str[i][j]!=a[j]){
                dif++;
            }
        }
        if(dif>1)  return false;
    }
    return true;
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        rep(i,1,n){
            scanf("%s",str[i]+1);
        }
        mst(mp,0);
        int mx=-1;
        rep(i,1,n){
            rep(j,i+1,n){
                int dif=check(i,j);
                mp[i][j]=mp[j][i]=dif;
                mx=max(mx,dif);
            }
        }
        if(mx>=3){
            printf("-1\n");
            continue;
        }
        if(mx==2){
            int i=0,j=0;
            rep(ii,1,n){
                rep(jj,ii+1,n){
                    if(mp[ii][jj]==2){
                        i=ii;
                        j=jj;
                    }
                }
            }
            char tstr[15];
            mst(tstr,0);
            int l=0,r=0;
            rep(k,1,m){
                if(str[i][k]==str[j][k]){
                    tstr[k]=str[i][k];
                }
                else{
                    if(l==0){
                        l=k;
                    }
                    else{
                        r=k;
                    }
                }
            }
            tstr[l]=str[i][l];
            tstr[r]=str[j][r];
            if(check1(tstr)){
                printf("%s\n",tstr+1);
                continue;
            }
            tstr[l]=str[j][l];
            tstr[r]=str[i][r];
            if(check1(tstr)){
                printf("%s\n",tstr+1);
                continue;
            }
            printf("-1\n");
            continue;
        }
        printf("%s\n",str[1]+1);
    }
    return 0;
}