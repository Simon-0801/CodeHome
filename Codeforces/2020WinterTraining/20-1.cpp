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

char str[maxn];

int main() {
    scanf("%s",str+1);
    int len=strlen(str+1);
    int cnt1=0,cnt2=0;
    rep(i,1,len){
        if(str[i]=='-')  cnt1++;
        else  cnt2++;
    }
    if(cnt2==0||cnt1%cnt2==0)  printf("YES\n");
    else  printf("NO\n");
    return 0;
}