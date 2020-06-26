//#pragma GCC optimize "trapv"
#include<bits/stdc++.h>
#define ll long long int
#define fab(a,b,i) for(int i=a;i<b;i++)
#define pb push_back
#define db double
#define mp make_pair
#define endl "\n"
#define f first
#define se second
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
ll dp[100005];
int main()
{ quick;

    ll n,k;
    cin>>n>>k;
    ll a[n];
    fab(0,n,i)
    cin>>a[i];
    ll small=*min_element(a,a+n);
    
    fab(0,n,i) 
    {
        
        fab(a[i],small+a[i] and j<k+1,j)
        {
            dp[j]=1;
        }


    }
    fab(0,k+1,i)
    {
         
        fab(0,n,j)
        {
            if(i-a[j]>=0 and dp[i-a[j]]==0)
            {
                dp[i]=1;

            }
        }


    }
   
    if(dp[k])
        cout<<"First\n";
    else
        cout<<"Second\n";


 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}