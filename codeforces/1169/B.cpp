// WRONG CODE . GETTING COMPLICATED

#pragma GCC optimize "trapv"
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
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	
		ll int n,m;
		cin>>n>>m;
		pair<int,int> ab;
		vector< pair<int,int> > v,ve;
		fab(0,m,i)
		{
			ll int a,b;
			cin>>a>>b;
			ab=mp(a,b);
			v.pb(ab);
		}
		
		string ans="YES";
		if(m<3)
		{
			cout<<ans<<endl;
			return 0;
		}

		ans="YES";
		vector<int> vec={v[0].f,v[0].se};
		
		for(int x: vec)
		{
			int cnt[n+1]={0};
			int tot=0;
		fab(0,m,i)
		{
			if((v[i].f!=x&&v[i].se!=x))
			{
				//ve.pb(v[i]);
				cnt[v[i].f]++;
				cnt[v[i].se]++;
				tot++;

			}

		}
		//x=ve[0].f,y=ve[0].se;
		fab(1,n+1,i)
		{
			if(cnt[i]==tot)
			{
				cout<<"YES";
				return 0;
			}

		}
	}
		cout<<"NO"<<endl;
		
		

	
	

	return 0;
}