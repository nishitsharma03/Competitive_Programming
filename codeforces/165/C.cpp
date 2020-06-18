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

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ll k;
	cin>>k;
	string s;
	cin>>s;
	ll cnt=0;
	int i=0,j=0;
	int n=s.size();
	ll ans=0;
	if(k==0)
	{
		fab(0,n,i)
		{
			if(s[i]=='1')
				continue;
			ll res=0;
			while(i<n and s[i]=='0')
				{res++;
			i++;}
			ans+=(res*(res+1))/2;
			

		}
		cout<<ans<<endl;
		return 0;
	}
	while(i<n and j<n)
	{
		while(i<n and cnt<k)
		{cnt+=(s[i]=='1');
		i++;}

		if(i<=n and cnt==k)
		{
			ll tot=1;
			while(i<n and s[i]=='0')
			{
				tot++;
				i++;
			}
			//cout<<"I:"<<i<<endl;
			ll tot1=1;
			while(j<=i and s[j]=='0')
			{
				tot1++;
				j++;
			}
		//	cout<<j<<endl;
			cnt--;
			j++;
			//cout<<"tot:"<<tot<<" "<<tot1<<endl;
			ans+=(tot*tot1);
		}
	
	}
	cout<<ans<<endl;


 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}