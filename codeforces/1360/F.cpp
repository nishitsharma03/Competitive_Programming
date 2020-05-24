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
		int n,m;
		cin>>n>>m;
		vector<string > v(n);

		fab(0,n,i)
		{
			cin>>v[i];

		}
		string ans="-1";
		vector<string> s;
		
		fab(0,n,i)
		{
			//set<int> s;
			int cnt[m]={0};
			fab(0,n,j)
			{
				if(i==j)
					continue;
				
				fab(0,m,k)
				{
					if(v[j][k]!=v[i][k])
					{
						s.pb(v[j].substr(0,k)+v[i][k]+v[j].substr(k+1,m-k-1));
						s.pb((v[i].substr(0,k)+v[j][k]+v[i].substr(k+1,m-k-1)));
						string tm=v[j].substr(0,k)+v[i][k]+v[j].substr(k+1,m-k-1);
						string tp=v[i].substr(0,k)+v[j][k]+v[i].substr(k+1,m-k-1);
						//cout<<"tm:"<<k<<" "<<tm<<" "<<tp<<endl;
					}
				}
			}
			//cout<<"i"<<i<<" "<<s.size()<<endl;
			}
			fab(0,n,i)
			s.pb(v[i]);
			fab(0,s.size(),i)
			{
				 bool ok=true;
				fab(0,n,j)
				{
					int cnt=0;
					fab(0,m,k)
					{
						if(s[i][k]!=v[j][k])
							cnt++;

					}
					if(cnt>1)
						ok=false;
				}
				if(ok)
				{
					ans=s[i];
					break;
				}
			}
		
		cout<<ans<<endl;
	}
	

	return 0;
}