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

char dic[105][50];
char str[50];

bool check(int k){
    int dl=strlen(dic[k]+1);
    int l=strlen(str+1);
    if(dl!=l)  return false;
    rep(i,1,dl){
        if(str[i]=='-')  continue;
        if(str[i]!=dic[k][i])  return false;
    }
    return true;
}

int main() {
    int n,m;
    scanf("%d",&n);
    rep(i,1,n){
        scanf("%s",dic[i]+1);
    }
    scanf("%d",&m);
    rep(i,1,m){
        scanf("%s",str+1);
        printf("Word #%d: %s\n",i,str+1);
        int cnt=0;
        rep(j,1,n){
            if(check(j)){
                cnt++;
                printf("%s\n",dic[j]+1);
            }
        }
        printf("Total number of candidate words = %d\n\n",cnt);
    }
    return 0;
}