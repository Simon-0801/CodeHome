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

char str[maxn];
int cnt[maxn];

int main() {
    scanf("%s",str+1);
    int len=strlen(str+1);
    rep(i,1,len){
        cnt[str[i]-'a'+1]++;
    }
    int flag=1;
    rep(i,1,26){
        if(cnt[i]&1){
            flag=0;
            break;
        }
    }
    if(flag){
        printf("0\n");
        return 0;
    }
    flag=1;
    rep(i,1,26){
        if(cnt[i]==0)  continue;
        if(cnt[i]%2==0){
            flag=0;
            break;
        }
    }
    if(flag){
        printf("1\n");
        return 0;
    }
    printf("2\n");
    return 0;
}