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

int n;
bool vis[10][10];

int main() {
    scanf("%d", &n);
    printf("a1 ");
    vis[1][1] = 1;
    vis[8][8] = 1;
    int x = 1, y = 1;
    while (--n) {
        if (n <= 5 && x != 8 && y != 8) {
            y = 8;
        } else {
            int nx = 0;
            for (int i = 8; i; --i) if (!vis[i][y]) {
                nx = i;
                break;
            }
            if (nx) x = nx; else ++y;
        }
        vis[x][y] = 1;
        printf("%c%d ", 'a' + x - 1, y);
    }
    puts("h8");
    return 0;
}