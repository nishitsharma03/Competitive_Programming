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
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> v;
		bitset<1030> y;
		fab(0,n,i)
		{
			int x;
			cin>>x;
			v.pb(x);
			y.set(x);
			
		}
		int ans=-1;
		fab(1,1025,i)
		{
			bitset<1030> temp;
			fab(0,n,j)
			{
				if((v[j]^i)<=1025)
				temp.set(v[j]^i);

			}
			if(temp==y)
			{

				ans=i;
				break;
			}

		}
		cout<<ans<<endl;

	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}