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
ll power(ll x, ll y)  
{  
    ll res = 1;     // Initialize result  
  
    x = x ; // Update x if it is more than or  
                // equal to p 
   
    if (x == 0) return 0; // In case x is divisible by p; 
  
    while (y > 0)  
    {  
        // If y is odd, multiply x with result  
        if (y & 1)  
            res = (res*x) ;  
  
          
        y = y>>1;   
        x = (x*x) ;  
    }  
    return res;  
} 

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll cnt=0,ans=0;
		while(1)
		{
			ll x=power(3,cnt);
			if(x>=n)
			{

				ans=x;
				break;
			}
			else
			{	bool ok=0;
				

				fab(0,cnt,i)
			{
				x+=power(3,i);
				if(x>=n)
			{
			
					for(int pp=i-1;pp>=0;pp--)
					{
						if(x-power(3,pp)>=n)
							x-=power(3,pp);
						

					}
				
				ans=x;
				ok=1;
				break;
			}
			

			}
			if(ok)
				break;
		}
		cnt++;

		}
		cout<<ans<<endl;

	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}