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
const int maxn = 100 + 5;

// char str[maxn];

int main() {
    string str;
    getline(cin,str);
    int i=0;
    int len=str.length();
    while(i<len&&str[i]!='-')  i++;
    if(i>=len){
        printf("NO\n");
        return 0;
    }
    int fi=i-0;
    if(fi<=1||fi>8){
        printf("NO\n");
        return 0;
    }
    int se=len-i-1;
    if(se<1||se>24){
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    return 0;
}