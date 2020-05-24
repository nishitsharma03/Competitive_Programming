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
void div(ll n)
{
	fab(1,sqrt(n)+1,i)
	{
		if(n%i==0)
			{v.pb(i);
				if(n/i!=i)
					v.pb(n/i);
			}

	}
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
		ll n,k;
		cin>>n>>k;
		div(n);
		sort(all(v));
		auto l=lower_bound(all(v),k);
		if(*l==k)
			cout<<n/k<<endl;
		else
		{
			if(*l==1)
				cout<<n<<endl;
			else
			{
				l--;
				cout<<n/(*l)<<endl;
			}

		}
		v.clear();

	}
	

	return 0;
}