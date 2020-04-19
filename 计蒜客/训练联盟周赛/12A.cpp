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

ll getnum(string s,int base){
    int len=s.length();
    ll res=0;
    if(base==1){
        rep(i,0,len-1){
            if(s[i]!='1')  return -1;
            res+=1;
        }
        return res;
    }
    int tmp;
    rep(i,0,len-1){
        if(s[i]>='a'&&s[i]<='z')  tmp=s[i]-'a'+10;
        else  tmp=s[i]-'0';
        if(tmp>=base)  return -1;
        res*=base;
        res+=tmp;
    }
    return res;
}

vector<char> ans;
char tab[50]="#123456789abcdefghijklmnopqrstuvwxyz0";

int main() {
    int n;
    string fi,op,se,eq,res;
    ll finum,senum,resnum;
    scanf("%d",&n);
    while(n--){
        cin>>fi>>op>>se>>eq>>res;
        ans.clear();
        // int i=16;
        rep(i,1,36){
            finum=getnum(fi,i);
            if(finum==-1)  continue;
            senum=getnum(se,i);
            if(senum==-1)  continue;
            resnum=getnum(res,i);
            if(resnum==-1)  continue;
            if(op=="+"){
                if(finum+senum==resnum)  ans.push_back(tab[i]);
            }
            else if(op=="-"){
                if(finum-senum==resnum)  ans.push_back(tab[i]);
            }
            else if(op=="*"){
                if(finum*senum==resnum)  ans.push_back(tab[i]);
            }
            else{
                if(resnum*senum==finum)  ans.push_back(tab[i]);
            }
        }
        if(ans.size()==0){
            printf("invalid\n");
        }
        else{
            for(auto &c:ans){
                printf("%c",c);
            }
            printf("\n");
        }
    }
    return 0;
}