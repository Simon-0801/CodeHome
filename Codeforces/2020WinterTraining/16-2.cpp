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
const int maxn = 100000 + 5;

char str[50];
int op[maxn];
int n;
int flag;
vector<pair<ll,int>> st;

// pair<ll,int> dfs(int l,int op){
//     if()  
//     if(l>n)  return make_pair(op,l);
//     ll res=op;
//     int i=l;
//     while(i<=n){
//         ll tmp;
//         if(num[i]==-1){
//             pair<ll,int> re=dfs(i+1,op^1);
//             i=re.second;
//             tmp=re.first;
//             // int j=i+1;
//             // while(j<=r){
//             //     if(num[j]==-2)  break;
//             //     j++;
//             // }
//             // tmp=dfs(i+1,j-1,op^1);
//             // i=j;
//         }
//         else if(num[i]==-2){
//             return make_pair(res%mod,i);
//         }
//         else  tmp=num[i];
//         if(op)  res=(res*tmp)%mod;
//         else  res=(res+tmp)%mod;
//         i++;
//     }
//     return make_pair(res%mod,i);
// }

int main() {
    scanf("%d",&n);
    flag=1;
    rep(i,1,n){
        scanf("%s",str);
        if(str[0]=='a'){
            op[i]=-1;
        }
        else if(str[0]=='f'){
            int tmp;
            scanf("%d",&tmp);
            op[i]=tmp;
        }
        else{
            op[i]=-2;
        }
    }
    ll tmp=0;
    // st.push_back(make_pair(0,1))
    rep(i,1,n){
        if(op[i]==-1){
            tmp++;
        }
        else if(op[i]>0){
            st.push_back(make_pair(tmp,op[i]));
            tmp=0;
        }
        else{
            pair<ll,int> tp=st.back();
            st.pop_back();
            ll num=tmp*tp.second;
            tmp=tp.first+num;
        }
        if(tmp>(1ll<<32)-1){
            flag=0;
            break;
        }
    }
    if(flag)  printf("%lld\n",tmp);
    else  printf("OVERFLOW!!!\n");
    return 0;
}