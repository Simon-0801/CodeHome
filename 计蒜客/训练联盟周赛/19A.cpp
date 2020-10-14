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



int main() {
    int a,b,n;
    scanf("%d%d%d",&a,&b,&n);
    int tmp=b-a;
    int cnt=(n-b)/tmp;
    if(cnt*tmp==n-b){
        cnt*=2;
        cnt++;
    }
    else{
        cnt*=2;
        cnt++;
        cnt+=2;
    }
    printf("%d\n",cnt);
    return 0;
}