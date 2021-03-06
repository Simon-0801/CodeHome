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
const int maxn = 100000 + 5;

int pos[100];

int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    int cnt=0;
    rep(i,0,31){
        if((1<<i)&n){
            pos[++cnt]=i;
        }
    }
    if(k>=cnt)  printf("0\n");
    else{
        int sum=0;
        rep(i,1,cnt-k+1){
            sum+=(1<<pos[i]);
        }
        int tmp=log2(sum);
        if(pow(2,tmp)==sum)  printf("0\n");
        else printf("%d\n",(1<<(tmp+1))-sum);
    }
    return 0;
}