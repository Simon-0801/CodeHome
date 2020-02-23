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
const int maxn = 100 + 5;

struct BigInt {
    const static int BASE = 1000000000;
    const static int DLEN = 9;
    vector<int> a;
    int len;

    BigInt() {
        a.resize(4);
        len = 1;
    }

    BigInt(int v) {
        a.resize(4);
        len = 0;
        do {
            a[len++] = v % BASE;
            v /= BASE;
        } while(v);
    }

    BigInt(const char *s) {
        int L = strlen(s);
        len = L / DLEN;
        if(L % DLEN)
            len++;
        a.resize(len + 1);
        int id = 0;
        for(int i = L - 1; i >= 0; i -= DLEN) {
            int t = 0;
            int k = i - DLEN + 1;
            if(k < 0)
                k = 0;
            for(int j = k; j <= i; j++)
                t = t * 10 + s[j] - '0';
            a[id++] = t;
        }
    }

    BigInt operator +(const BigInt &b)const {
        BigInt res;
        res.len = max(len, b.len);
        res.a.resize(res.len + 1);
        for(int i = 0; i < res.len; i++) {
            res.a[i] += ((i < len) ? a[i] : 0) + ((i < b.len) ? b.a[i] : 0);
            res.a[i + 1] += res.a[i] / BASE;
            res.a[i] %= BASE;
        }
        if(res.a[res.len] > 0)
            res.len++;
        return res;
    }

    BigInt operator *(const BigInt &b)const {
        //高精乘高精，考虑用FFT优化
        BigInt res;
        res.a.resize(len + b.len);
        for(int i = 0; i < len; i++) {
            int up = 0;
            for(int j = 0; j < b.len; j++) {
                ll temp = 1ll * a[i] * b.a[j] + res.a[i + j] + up;
                res.a[i + j] = temp % BASE;
                up = temp / BASE;
            }
            if(up != 0)
                res.a[i + b.len] = up;
        }
        res.len = len + b.len;
        while(res.a[res.len - 1] == 0 && res.len > 1)
            res.len--;
        return res;
    }

    BigInt operator *(const int &b)const {
        //高精乘低精
        BigInt res;
        res.a.resize(len + 1);
        for(int i = 0; i < len; i++) {
            int up = 0;
            ll temp = 1ll * a[i] * b + res.a[i] + up;
            res.a[i] = temp % BASE;
            up = temp / BASE;
            if(up != 0)
                res.a[i + 1] = up;
        }
        res.len = len + 1;
        while(res.a[res.len - 1] == 0 && res.len > 1)
            res.len--;
        return res;
    }

    bool operator <(const BigInt &b)const {
        if(len != b.len)
            return len < b.len;
        else {
            for(int ln = len - 1; ln >= 0; ln--) {
                if(a[ln] != b.a[ln])
                    return a[ln] < b.a[ln];
            }
            return false;
        }
    }

    void output() {
        printf("%d", a[len - 1]);
        for(int i = len - 2; i >= 0 ; i--)
            printf("%09d", a[i]);
        printf("\n");
    }
};

BigInt dp[maxn][maxn];

int mp[maxn][maxn];
int n,m;

BigInt solve(int row){
    for(int i=1;i<=m;i++){
        dp[i][i]=BigInt(mp[row][i]);
    }
    for(int len=2;len<=m;len++){
        for(int l=1;l<=m+1-len;l++){
            int r=l+len-1;
            BigInt tmp1=dp[l+1][r]*2+mp[row][l],tmp2=dp[l][r-1]*2+mp[row][r];
            dp[l][r]=max(tmp1,tmp2);
        }
    }
    return dp[1][m];
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&mp[i][j]);
        }
    }
    BigInt ans=0;
    for(int i=1;i<=n;i++){
        ans=ans+solve(i);
    }
    ans=ans*2;
    ans.output();
    return 0;
}