#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;

int mp[2][maxn];
set<pair<int,int>> st;

int main() {
    int n,q,r,c,flag=1;
    scanf("%d%d",&n,&q);
    memset(mp,0,sizeof(mp));
    for(int i=1;i<=q;i++){
        // scanf("%d%d",&r,&c);
        // r--;
        // if(r==0){
        //     if(mp[1][c-1]){
        //         st.insert(make_pair(c,c-1));
        //     }
            
        // }

        if(i==1){
            scanf("%d%d",&r,&c);
            mp[r-1][c]=1-mp[r-1][c];
            printf("Yes\n");
            flag=1;//ok
            continue;
        }
        scanf("%d%d",&r,&c);
        mp[r-1][c]=1-mp[r-1][c];
        if(mp[r-1][c]==0){
            if(r-1==0){
                if(st.count(make_pair(c,c+1)))  st.erase(make_pair(c,c+1));
                if(st.count(make_pair(c,c)))  st.erase(make_pair(c,c));
                if(st.count(make_pair(c,c-1)))  st.erase(make_pair(c,c-1));
            }
            else{
                if(st.count(make_pair(c+1,c)))  st.erase(make_pair(c+1,c));
                if(st.count(make_pair(c,c)))  st.erase(make_pair(c,c));
                if(st.count(make_pair(c-1,c)))  st.erase(make_pair(c-1,c));
            }
            if(flag){
                printf("Yes\n");
                flag=1;
            }
            else{
                if(st.size()>0){
                    printf("No\n");
                    flag=0;
                }
                else{
                    printf("Yes\n");
                    flag=1;
                }
            }
        }
        else{
            if(r-1==0){
                if(mp[2-r][c-1]){
                    st.insert(make_pair(c,c-1));
                }
                if(mp[2-r][c]){
                    st.insert(make_pair(c,c));
                }
                if(mp[2-r][c+1]){
                    st.insert(make_pair(c,c+1));
                }
            }
            else{
                if(mp[2-r][c-1]){
                    st.insert(make_pair(c-1,c));
                }
                if(mp[2-r][c]){
                    st.insert(make_pair(c,c));
                }
                if(mp[2-r][c+1]){
                    st.insert(make_pair(c+1,c));
                }
            }
            if(flag){
                if(st.size()>0){
                    printf("No\n");
                    flag=0;
                }
                else{
                    printf("Yes\n");
                    flag=1;
                }
            }
            else{
                printf("No\n");
                flag=0;
            }
        }
    }
    return 0;
}