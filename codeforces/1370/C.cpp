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
vector<ll> v;
void fact(ll n)
{
	fab(1,sqrt(n)+1,i)
	{
		if(n%i==0)
		{
			v.pb(i);
			if(n/i!=i)
				v.pb(n/i);
		}
	}
}
void primeFactors(ll n)  
{  
    // Print the number of 2s that divide n  
    while (n % 2 == 0)  
    {  
        v.pb(2); 
        n = n/2;  
    }  
  
    // n must be odd at this point. So we can skip  
    // one element (Note i = i +2)  
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {  
        // While i divides n, print i and divide n  
        while (n % i == 0)  
        {  
            v.pb(i);  
            n = n/i;  
        }  
    }  
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2  
    if (n > 2)  
        v.pb(n);
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

		string a="Ashishgup";
		string b="FastestFinger";
		if(n==1)
		{
			cout<<b<<endl;
			continue;
		}

		
		if(n%2 or n==2)
		{
			cout<<a<<endl;
			continue;
		}
		v.clear();
		primeFactors(n);
		int cnt=0,cnt2=0;

		for(auto i: v)
		{
			if(i%2 )
				cnt++;
			else if(i==2)
				cnt2++;
		}
		//cout<<"cnt:"<<cnt<<" "<<cnt2<<endl;
		if(cnt==0)
			cout<<b<<endl;
		else if(cnt2==1 and cnt==1)
			cout<<b<<endl;
		else
		{
			cout<<a<<endl;
		}


		

	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}