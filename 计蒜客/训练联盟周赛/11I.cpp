#include<iostream>
#include<algorithm>
using namespace std;
  
typedef unsigned long long ull;
 
const int N=1e6+100;
 
ull Hash[N],p[N];
 
int n;
 
string str;
 
void _hash()//打个哈希表
{
    Hash[0]=0;
    for(int i=1;i<=n;i++)
    {
        Hash[i]=Hash[i-1]*131+str[i]-'0'+1;
    }
    p[0]=1;
    for(int i=1;i<=n;i++)
        p[i]=p[i-1]*131;
}
  
int main()
{
    cin>>str;
    n=str.size();
    str=" "+str;
    _hash();
    int l=1,r=n;
    int start=1,end=n;
    int ans=0;
    while(l<r)
    {
        ull a=Hash[l]-Hash[start-1]*p[l-start+1];
        ull b=Hash[end]-Hash[r-1]*p[end-r+1];
        if(a==b)
        {
            ans+=2;
            start=l+1;
            end=r-1;        
        }
        l++;
        r--;    
    }
    if(l==r)//不明原理的胡搞
        ans++;
    if(start < end&&l>r) ans++;//同上-..-
    cout<<ans<<endl;
      
      
      
      
      
      
      
      
    return 0;
}