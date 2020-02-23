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
const int maxn = 4000 + 5;

struct int_l {
    int data[maxn];
    int_l() {//初始化 
        memset(data, 0, sizeof(data));
        data[0] = 1;
    }
    int_l(int x) {//用低精数 初始化（赋值） 高精数 
        memset(data, 0, sizeof(data));
        data[0] = 1;
        int i = 1;
        while (x) {
            data[i++] = x % 10;
            x /= 10;
        }
        data[0] = --i;// 这里位数不能错 
    }
    int_l operator *(const int &x) {//很普通的重载 *号 
        int_l a;
        int len;
        a.data[0] = data[0];
        rep(i, 1, data[0]) a.data[i] = data[i] * x;
        for (int i = 1; i <= a.data[0] || a.data[i]; len = ++i) {
            a.data[i + 1] += a.data[i] / 10;
            a.data[i] %= 10;
        }
        a.data[len] ? a.data[0] = len : a.data[0] = --len;
        return a;
    }
    int_l operator /(const int &x) { //高精除低精 
        int_l a;
        a.data[0]=data[0];
        int rest = 0;
        for (int i = data[0]; i >= 1; i--) { //注意要从最高位开始模拟 
            rest = rest * 10 + data[i];
            a.data[i] = rest / x;
            rest %= x;
        }
        while (!a.data[a.data[0]] && a.data[0]>1) a.data[0]--; //去掉多余的 0 
        return a;
    }
    bool operator <(const int_l &x)const{// 重载 <号 
        if(data[0]==x.data[0]){ //从位数开始比较 
            int i;
            for(i=data[0];data[i]==x.data[i] && i > 1;i--);//然后是最高位 
            if(i >= 1) return data[i] < x.data[i];
            else return false;
        }
        else return data[0] < x.data[0];
    }
};
ostream& operator << (ostream& out, const int_l &x) {
    rep(i, 1, x.data[0]) out << x.data[x.data[0] - i + 1];
    return out;
}

struct node
{
    int a,b;
    bool operator< (const node& nod) const{
        return a*b<nod.a*nod.b;
    }
}p[maxn];


int main() {
    int n;
    scanf("%d",&n);
    scanf("%d%d",&p[0].a,&p[0].b);
    rep(i,1,n){
        scanf("%d%d",&p[i].a,&p[i].b);
    }
    sort(p+1,p+n+1);
    int_l pre=int_l(p[0].a);
    int_l ans=int_l(0);
    rep(i,1,n){
        int_l tmp=pre/p[i].b;
        if(ans<tmp)  ans=tmp;
        pre=pre*p[i].a;
    }
    cout<<ans<<endl;
    return 0;
}