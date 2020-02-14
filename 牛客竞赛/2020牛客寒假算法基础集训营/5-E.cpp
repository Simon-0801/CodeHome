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

bool check(ll n){
    while(n%2==0)  n>>=1;
    if(n>1)  return true;
    return false;
}

int main() {
    ll n;
    scanf("%lld",&n);
    if(n&1)  printf("Bob\n");
    else{
        if(check(n))  printf("Bob\n");
        else  printf("Alice\n");
    }
    return 0;
}