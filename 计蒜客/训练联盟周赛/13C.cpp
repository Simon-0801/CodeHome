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

char str[5][10];
int num[20];
int ans[5],tmp[5];

bool check(){
    if(ans[1]>tmp[1])  return true;
    if(ans[1]==tmp[1]&&ans[2]>tmp[2])  return true;
    if(ans[1]==tmp[1]&&ans[2]==tmp[2]&&ans[3]>tmp[3])  return true;
    return false;
}

void dfs(int pos){
    if(pos>9){
        tmp[1]=0;
        rep(i,1,3){
            tmp[1]*=10;
            tmp[1]+=num[i];
        }
        tmp[2]=0;
        rep(i,4,6){
            tmp[2]*=10;
            tmp[2]+=num[i];
        }
        tmp[3]=0;
        rep(i,7,9){
            tmp[3]*=10;
            tmp[3]+=num[i];
        }
        if(!(tmp[1]<tmp[2]&&tmp[2]<tmp[3]))  return;
        if(check()){
            rep(i,1,3){
                ans[i]=tmp[i];
            }
        }
        return;
    }
    
    if(num[pos]!=-1){
        dfs(pos+1);
    }
    else{
        if(pos==1||pos==4||pos==7){
            rep(i,2,5){
                num[pos]=i;
                dfs(pos+1);
                num[pos]=-1;
            }
        }
        else{
            rep(i,0,9){
                num[pos]=i;
                dfs(pos+1);
                num[pos]=-1;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d",&n);
    rep(cas,1,n){
        rep(i,1,3){
            scanf("%s",str[i]+1);
        }
        int tot=0;
        rep(i,1,3){
            rep(j,1,3){
                if(str[i][j]=='-')  num[++tot]=-1;
                else  num[++tot]=str[i][j]-'0';
            }
        }
        mst(ans,0x3f);
        dfs(1);
        printf("Gas Station #%d:\n",cas);
        printf("   Input:  ");
        rep(i,1,3){
            printf("%s%c",str[i]+1,i==3?'\n':' ');
        }
        printf("   Output: ");
        rep(i,1,3){
            printf("%d%c",ans[i],i==3?'\n':' ');
        }
        printf("\n");
        // rep(i,1,3){
        //     if(num[1][i]!=-1)  continue;
        //     if(num[2][i]==-1&&num[3][i]==-1){

        //     }
        // }
    }
    return 0;
}