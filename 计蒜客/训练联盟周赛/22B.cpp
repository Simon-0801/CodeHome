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

map<string,int> mp;

int main() {
    int n;
    scanf("%d",&n);
    string s;
    rep(i,1,n){
        cin>>s;
        mp[s]++;
    }
    for(auto &x:mp){
        if(x.second>n-x.second){
            cout<<x.first<<endl;
            return 0;
        }
    }
    cout<<"NONE"<<endl;
    return 0;
}