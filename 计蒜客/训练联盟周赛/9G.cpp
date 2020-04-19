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
const int maxn = 200000 + 5;

char str[maxn];
char f[maxn];
vector<int> pos[30];

int main() {
    scanf("%s",str+1);
    int len=strlen(str+1);
    rep(i,1,len){
        int tmp=str[i]-'A'+1;
        pos[tmp].push_back(i);
    } 
    int n;
    scanf("%d",&n);
    while(n--){
        scanf("%s",f+1);
        int ln=strlen(f+1);
        int p=1;
        while(p<=ln){
            
        }
    }
    return 0;
}