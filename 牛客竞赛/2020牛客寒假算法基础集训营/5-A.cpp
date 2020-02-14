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
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
const ll mod = 1e9 + 7;
const int maxn = 100000 + 5;

char s1[maxn],s2[maxn];

int main() {
    int n,m,cnt=0;
    scanf("%d%d",&n,&m);
    scanf("%s",s1+1);
    scanf("%s",s2+1);
    int len=min(n,m);
    for(int i=1;i<=len;i++){
        if(s1[i]==s2[i])  cnt++;
    }
    printf("%d\n",max(n,m)-len+len-cnt);
    return 0;
}