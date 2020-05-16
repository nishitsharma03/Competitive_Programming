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
ll int digi(ll int n)
{
	ll int tm=n;
	vector<int> v;
	while(tm>0)
	{
		v.pb(tm%10);
		tm/=10;
	}
	return *min_element(all(v))*(*max_element(all(v)));
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
		ll int n,k;
		cin>>n>>k;
		fab(2,k+1,i)
		{
			ll int top=digi(n);
			if(top==0)
				break;
			n+=top;

			
		}
		cout<<n<<endl;
	}
	

	return 0;
}