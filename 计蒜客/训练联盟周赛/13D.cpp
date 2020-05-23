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
const int maxn = 100 + 5;

char str[maxn];
vector<string> dict;
string strq;
vector<string> t,ans;
int len;

bool dfs(int pos){
    if(pos>=len){
        for(auto &x:t){
            ans.push_back(x);
        }
        return true;
    }
    for(auto &x:dict){
        int tlen=x.length();
        if(tlen+pos>len)  continue;
        string sub=strq.substr(pos,tlen);
        if(sub==x){
            t.push_back(sub);
            if(dfs(pos+tlen))  return true;
            t.pop_back();
        }
    }
    return false;
}

int main() {
    int n,m,cas=0;
    string tmp;
    while(scanf("%d",&n)&&n){
        cas++;
        dict.clear();
        rep(i,1,n){
            scanf("%s",str);
            tmp=str;
            dict.push_back(tmp);
        }
        printf("Data set #%d:\n",cas);
        scanf("%d",&m);
        rep(i,1,m){
            scanf("%s",str);
            strq=str;
            int f=0;
            len=strq.length();
            for(auto &x:dict){
                if(x==strq){
                    f=1;
                    break;
                }
            }
            if(f){
                cout<<"     "<<strq<<" --- the word is in dictionary"<<endl;
                continue;
            }
            t.clear();
            ans.clear();
            bool flag=dfs(0);
            if(flag){
                cout<<"     "<<strq<<" --- the word is concatenation of"<<endl;
                for(auto &x:ans){
                    cout<<"          "<<x<<endl;
                }
            }
            else{
                cout<<"     "<<strq<<" --- misspelled word"<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}