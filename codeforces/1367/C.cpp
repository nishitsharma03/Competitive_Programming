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
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		vector<int> v;
		
		fab(0,n,i)
		{
			if(s[i]=='1')
				v.pb(i);
		}
		if(v.size()==0)
		{
			int ans=0;
			fab(0,n,i)
			{
				ans++;
				i+=k;
			}
			cout<<ans<<endl;
			continue;
		}
		//v.pb(n);
		int ans=0;
		int pp=v[0];
		int ed=v.back();
		fab(0,v.size()-1,i)
		{
			//cout<<"diff:"<<v[i+1]-v[i]<<endl;
			//cout<<"check:";
			//cout<<v[i]<<" ";

			while(v[i+1]-v[i]>(2*k+1))
			{
				
				ans++;
				v[i]+=(k+1);
			//	cout<<v[i]<<" ";
			}
			//cout<<endl;

		}
		//cout<<ans<<"\n";
		while(pp-k-1>=0)
		{
			pp-=(k+1);
			ans++;
		}
		while(ed+(k+1)<n)
		{
			ans++;
			ed+=(k+1);
		}
		cout<<ans<<endl;
	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}