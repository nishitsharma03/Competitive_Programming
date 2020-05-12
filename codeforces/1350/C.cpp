//#pragma GCC optimize "trapv"
#include<bits/stdc++.h>
#define ll long long 
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

 vector< map<ll int,ll int> > v(200005);
 vector< ll int > pres[200005];
 void primeFactors(ll int n,ll int i)  
{  
    // Print the number of 2s that divide n  
    
    	//dp[2]++;
   
    //ll int cnt=0;
   // cout<<n<<" \n";
    map<ll int,ll int> m;
    while (n % 2 == 0)  
    { 

    	m[2]++;
          
        n = n/2;  
    }  
    
    //m[2]=cnt;

  
    // n must be odd at this point. So we can skip  
    // one element (Note i = i +2)  
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {  
        // While i divides n, print i and divide n  
        while (n % i == 0)  
        {  
            m[i]++;
            n = n/i;  
        }  
    }  
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2  
    if (n > 2)  
        m[n]++;
    //for(auto i:m)
    //	cout<<i.f<<" "<<i.se<<endl;
        
        v[i]=m;  
}  
int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ll int n;
	cin>>n;
	ll int a[n];
	fab(0,n,i)
	cin>>a[i];
	//ll int gg=a[0];
	//set<ll int> v;
	fab(0,n,i)
	{
		primeFactors(a[i],i);
		//cout<<"SF";
	}
	//ll int chk[100005];
	
	//fab(0,n,i)
	//gg=v[0];
	
	fab(0,n,i)
	{
		
		{map<ll int,ll int> m=v[i];
		for(auto j: m)
		{
			pres[j.f].pb(j.se);
		}
	}

	}
	ll int ans=1;
	fab(1,200005,i)
	{
		if(pres[i].size()<n-1)
			continue;
		else if(pres[i].size()==n-1)
			{ans*=(pow(i,*min_element(all(pres[i]))));
			//cout<<"dfs";

		}
		else if (pres[i].size()==n)
		{
			//cout<<"sd"<<i<<" "<<*min_element(all(pres[i]))<<endl;
			
			sort(all(pres[i]));
			ans*=(pow(i,pres[i][1]));


		}

	}
	cout<<ans<<endl;
	

	return 0;
}