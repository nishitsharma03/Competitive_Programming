//#pragma GCC optimize "trapv"
#include<bits/stdc++.h>
#define ll long long int
#define fab(a,b,i) for(int i=a;i<b;i++)
#define pb push_back
#define db double
#define mp make_pair
//#define endl "\n"
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
	
	{
		int n;
		cin>>n;
		bool vis[n]={0};
		ll a[n];
		vector<int> v;
		fab(0,n,i)
		{cin>>a[i];
			a[i]--;
			if(a[i]==-1)
				v.pb(i);
			else
				vis[a[i]]=1;
		}
	//	for(auto i:v)
	//		cout<<i<<" ";
	//		cout<<endl; 
		int j=0;
		fab(0,n,i)
		{
			if(vis[i]==0)
			{
				//cout<<"i:"<<i<<endl;
				if(i==v[j])
				{
					//cout<<"FDGF"<<v[j]<<endl;
					if(j==0)
					swap(v[j],v[j+1]);
					else swap(v[j],v[j-1]);
				}
				//cout<<"vj:"<<v[j]<<endl;
				
				j++;
			}
		}
		j=0;
		fab(0,n,i)
		{
			if(vis[i]==0)
			{
				a[v[j]]=i;
				j++;
			}

		}
		fab(0,n,i)
		cout<<a[i]+1<<" ";
		cout<<endl;


	}

	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}