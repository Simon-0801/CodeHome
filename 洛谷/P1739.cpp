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
const int maxn = 255 + 5;

char str[maxn];
vector<char> v;

int main() {
    scanf("%s",str+1);
    int len=strlen(str+1);
    int flag=1;
    rep(i,1,len){
        if(str[i]=='(')  v.push_back('(');
        if(str[i]==')'){
            if(v.empty()){
                flag=0;
                break;
            }
            else  v.pop_back();
        }
    }
    if(!v.empty())  flag=0;
    if(flag)  printf("YES\n");
    else  printf("NO\n");
    return 0;
}