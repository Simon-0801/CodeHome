#include <iostream>
#include <sstream>
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
    int t;
    scanf("%d",&t);
    getchar();
    while(t--){
        string s;
        getline(cin,s);
        istringstream ss(s);
        string fi,se;
        ss>>fi;
        if(fi=="Simon"){
            ss>>se;
            if(se=="says"){
                cout<<s.substr(10)<<endl;
            }
        }
    }
    return 0;
}