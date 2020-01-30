#include<map>
#include<set>
#include<queue>
#include<stack>
#include<ctime>
#include<cmath>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 100000 + 5;
const int INF = 0x3f3f3f3f;
const ull seed = 131;
const ll MOD = 10007;
using namespace std;
ll n, m;
ll sum[4][maxn << 2], add[maxn << 2], mul[maxn << 2], change[maxn << 2];
ll ppow(ll a, ll b){
    ll ret = 1;
    while(b){
        if(b & 1) ret = ret * a % MOD;
        b >>= 1;
        a = a * a % MOD;
    }
    return ret;
}
void pushup(int rt){
    for(int i = 1; i <= 3; i++)
        sum[i][rt] = (sum[i][rt << 1] + sum[i][rt << 1 | 1]) % MOD;
}

void pushdown(int rt, int l, int r){
    int m = (l + r) >> 1;
    if(change[rt]){
        for(int i = 1; i <= 3; i++) sum[i][rt << 1] = ppow(change[rt], i) * (m - l + 1) % MOD;
        for(int i = 1; i <= 3; i++) sum[i][rt << 1 | 1] = ppow(change[rt], i) * (r - m) % MOD;
        change[rt << 1] = change[rt << 1 | 1] = change[rt];
        mul[rt << 1] = mul[rt << 1 | 1] = 1;
        add[rt << 1] = add[rt << 1 | 1] = 0;
    }
    if(mul[rt] != 1){
        sum[3][rt << 1] = sum[3][rt << 1] * ppow(mul[rt], 3) % MOD;
        sum[3][rt << 1 | 1] = sum[3][rt << 1 | 1] * ppow(mul[rt], 3) % MOD;

        sum[2][rt << 1] = sum[2][rt << 1] * ppow(mul[rt], 2) % MOD;
        sum[2][rt << 1 | 1] = sum[2][rt << 1 | 1] * ppow(mul[rt], 2) % MOD;

        sum[1][rt << 1] = sum[1][rt << 1] * mul[rt] % MOD;
        sum[1][rt << 1 | 1] = sum[1][rt << 1 | 1] * mul[rt] % MOD;

        mul[rt << 1] = mul[rt << 1] * mul[rt] % MOD;
        mul[rt << 1 | 1] = mul[rt << 1 | 1] * mul[rt] % MOD;
        add[rt << 1] = add[rt << 1] * mul[rt] % MOD;
        add[rt << 1 | 1] = add[rt << 1 | 1] * mul[rt] % MOD;

    }
    if(add[rt]){
        sum[3][rt << 1] = (sum[3][rt << 1] + 3LL * add[rt] * sum[2][rt << 1] + 3LL * ppow(add[rt], 2) * sum[1][rt << 1] + (m - l + 1) * ppow(add[rt], 3)) % MOD;
        sum[3][rt << 1 | 1] = (sum[3][rt << 1 | 1] + 3LL * add[rt] * sum[2][rt << 1 | 1] + 3LL * ppow(add[rt], 2) * sum[1][rt << 1 | 1] + (r - m) * ppow(add[rt], 3)) % MOD;

        sum[2][rt << 1] = (sum[2][rt << 1] + 2LL * add[rt] * sum[1][rt << 1] + ppow(add[rt], 2) * (m - l + 1)) % MOD;
        sum[2][rt << 1 | 1] = (sum[2][rt << 1 | 1] + 2LL * add[rt] * sum[1][rt << 1 | 1] + ppow(add[rt], 2) * (r - m)) % MOD;

        sum[1][rt << 1] = (sum[1][rt << 1] + add[rt] * (m - l + 1)) % MOD;
        sum[1][rt << 1 | 1] = (sum[1][rt << 1 | 1] + add[rt] * (r - m)) % MOD;

        add[rt << 1] = (add[rt << 1] + add[rt]) % MOD;
        add[rt << 1 | 1] = (add[rt << 1 | 1] + add[rt]) % MOD;
    }

    mul[rt] = 1, add[rt] = 0, change[rt] = 0;

}
void build(int l, int r, int rt){
    add[rt] = 0;
    mul[rt] = 1;
    change[rt] = 0;
    if(l == r){
        sum[1][rt] = sum[2][rt] = sum[3][rt] = 0;
        return;
    }
    int m = (l + r) >> 1;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
    pushup(rt);
}
void update(int L, int R, int l, int r, ll v, int op, int rt){
    if(L <= l && R >= r){
        if(op == 1){    //add
            sum[3][rt] = (sum[3][rt] + 3LL * v * sum[2][rt] + 3LL * v * v * sum[1][rt] + (r - l + 1LL) * v * v * v) % MOD;
            sum[2][rt] = (sum[2][rt] + 2LL * v * sum[1][rt] + (r - l + 1LL) * v * v) % MOD;
            sum[1][rt] = (sum[1][rt] + v * (r - l + 1)) % MOD;
            add[rt] += v;
        }
        else if(op == 2){   //mul
            sum[1][rt] = sum[1][rt] * v % MOD;
            sum[2][rt] = sum[2][rt] * v * v % MOD;
            sum[3][rt] = sum[3][rt] * v * v * v % MOD;
            mul[rt] = mul[rt] * v % MOD;
            add[rt] = add[rt] * v % MOD;
        }
        else{   //set
            sum[1][rt] = v * (r - l + 1) % MOD;
            sum[2][rt] = v * v * (r - l + 1) % MOD;
            sum[3][rt] = v * v * v * (r - l + 1) % MOD;
            mul[rt] = 1, add[rt] = 0, change[rt] = v;
        }
        return;
    }
    pushdown(rt, l, r);
    int m = (l + r) >> 1;
    if(L <= m)
        update(L, R, l, m, v, op, rt << 1);
    if(R > m)
        update(L, R, m + 1, r, v, op, rt << 1 | 1);
    pushup(rt);
}
ll query(int L, int R, int l, int r, int v, int rt){
    if(L <= l && R >= r){
        return sum[v][rt];
    }
    pushdown(rt, l, r);
    ll ret = 0;
    int m = (l + r) >> 1;
    if(L <= m)
        ret += query(L, R, l, m, v, rt << 1);
    if(R > m)
        ret += query(L, R, m + 1, r, v, rt << 1 | 1);
    return ret % MOD;
}
int main(){
    while(~scanf("%lld%lld", &n, &m) && n + m){
        build(1, n, 1);
        while(m--){
            int op, x, y, c;
            scanf("%d%d%d%d", &op, &x, &y, &c);
            if(op <= 3) update(x, y, 1, n, c, op, 1);
            else printf("%lld\n", query(x, y, 1, n, c, 1));
        }
    }
    return 0;
}