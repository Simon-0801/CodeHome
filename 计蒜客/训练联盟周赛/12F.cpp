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
const int maxn = 50 + 5;

int a[maxn];
char ans[maxn];

int main() {
    int t;
    scanf("%d",&t);
    getchar();
    while(t--){
        mst(a,0);
        mst(ans,0);
        string s;
        getline(cin,s);
        for(int i = 0; i < s.length(); i ++){
            if(s[i] >= 'a' && s[i] <= 'z')
            a[s[i] - 'a'] ++;
            if(s[i] >= 'A' && s[i] <= 'Z')
            a[s[i] - 'A'] ++;
        }
        int k = 0;
        for(int i  = 0; i < 26; i ++){
            if(!a[i]){
                ans[k++] = i + 'a';
            }
        }
        if(k ==0) {
            printf("pangram\n");
        }
        else{
            printf("missing ");
            for(int i = 0; i< k;  i ++){
                printf("%c",ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}