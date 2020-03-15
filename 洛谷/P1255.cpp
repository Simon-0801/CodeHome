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
const ll mod = 100003;
const int maxn = 5000 + 5;

struct Big{
    int len,s[maxn];
    Big(){memset(s,0,sizeof(s)); len=1;}
    Big(int val) {*this=val;}
    Big(const char *val) {*this=val;}
    Big operator = (const int &val){
        char s[maxn];
        sprintf(s,"%d",val);
        *this=s;return *this;
    }
    Big operator = (const char *val){
        len=strlen(val);
        while(len>1&&val[0]=='0') ++val,len--;
        for(int i=0;i<len;++i){
            s[i]=val[len-i-1]-'0';
        }
        return *this;
    }
    inline void deal(){
        while(len>1&&!s[len-1]) len--;
    }
    Big operator + (const Big &a) const {
        Big res; res.len=0;
        int top=max(len,a.len),add=0;
        for(int i=0;add||i<top;++i){
            int now=add;
            if(i<len) now+=s[i];
            if(i<a.len) now+=a.s[i];
            res.s[res.len++]=now%10;
            add=now/10;
        }
        return res;
    }
    Big operator - (const Big &a) const {
        Big res; res.len=0;int del=0;
        for(int i=0;i<len;++i){
            int now=s[i]-del;
            if(i<a.len) now-=a.s[i];
            if(now>=0) del=0;
            else del=1,now+=10;
            res.s[res.len++]=now;
        }
        res.deal(); return res;
    }
    Big operator * (const Big &a) const {
        Big res; res.len=len+a.len;
        for(int i=0;i<len;++i)
            for(int j=0;j<a.len;++j)
                res.s[i+j]+=s[i]*a.s[j];
        for(int i=0;i<res.len;++i)
            res.s[i+1]+=res.s[i]/10,res.s[i]%=10;
        res.deal(); return res;
    }
    Big operator / (const Big &a) const {
        Big res,cur=0;res.len=len;
        for(int i=len-1;~i;--i){
            cur=cur*10,cur.s[0]=s[i];
            while(cur>=a)
                cur-=a,res.s[i]++;
        }
        res.deal(); return res;
    }
    Big operator % (const Big &a) const {
        Big res=*this/a;
        return *this-res*a;
    }
    Big operator += (const Big &a) {*this=*this+a; return *this;}
    Big operator -= (const Big &a) {*this=*this-a; return *this;}
    Big operator *= (const Big &a) {*this=*this*a; return *this;}
    Big operator /= (const Big &a) {*this=*this/a; return *this;}
    Big operator %= (const Big &a) {*this=*this%a; return *this;}
    bool operator < (const Big &a) const {
        if(len!=a.len) return len<a.len;
        for(int i=len-1;~i;i--) 
        if(s[i]!=a.s[i]) return s[i]<a.s[i];
        return false;
    }
    bool operator >  (const Big &a) const {return a<*this;}
    bool operator <= (const Big &a) const {return !(*this>a);}
    bool operator >= (const Big &a) const {return !(*this<a);}
    bool operator == (const Big &a) const {return !(*this>a||*this<a);}
    bool operator != (const Big &a) const {return *this>a||*this<a;}
};

Big dp[maxn];

int main() {
    int n,k;
    scanf("%d",&n);
    mst(dp,0);
    dp[0]=1;
    rep(i,1,n){
        rep(l,1,2){
            if(i-l>=0)  dp[i]=(dp[i]+dp[i-l]);
        }
    }
    if(n==0){
        printf("0");return 0;
    }
    for(int i=dp[n].len-1;i>=0;i--){
        printf("%d",dp[n].s[i]);
    }
    return 0;
}