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
const int maxn = 400000 + 5;

int len[maxn<<1];
char s[maxn],tmp[maxn<<1];

inline int init(char *p){
	int n=strlen(p);
	tmp[0]='@';
	for(int i=1;i<=2*n;i+=2){
		tmp[i]='#',tmp[i+1]=p[i/2];
	}
	tmp[2*n+1]='#'; tmp[2*n+2]='$';
	return 2*n+1;
}

inline int Manacher(char *p,int n){
	int mx=0,pos=0,ans=0;
	for(int i=1;i<=n;i++){
		if(mx>i) len[i]=min(mx-i,len[2*pos-i]);//i被mx覆盖了 
		else len[i]=1;
		while(p[i-len[i]]==p[i+len[i]]) len[i]++;//左右扩展 
		if(len[i]+i>mx) mx=len[i]+i,pos=i;//更新 
		ans=max(ans,len[i]-1);
	}
	return ans;
}

int main() {
    int n;
    scanf("%d",&n);
    scanf("%s",s);
    reverse(s,s+n);
    int m=init(s);
    Manacher(tmp,m);
    int mx=0;
    rep(i,1,m){
        if(i&1){
            int pos=i-1;
            if(pos==len[i]-1){
                mx=max(mx,pos);
            }
        }
        else{
            int pos=i-1;
            if(pos==len[i]-1){
                mx=max(mx,pos);
            }
        }
    }
    printf("%d\n",n-mx);
    return 0;
}