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
		int n;
		cin>>n;
		vector<string > v(n);
		fab(0,n,i)
		{
			cin>>v[i];
		}
		string ans="YES";
		fab(0,n-1,i)
		{
			fab(0,n-1,j)

			{
				if(i==0)
				{
					if(v[i][j]=='1')
					{
						if(v[i][j+1]=='0' and v[i+1][j]=='0')
						{
							ans="NO";
							break;
						}
					}
				}
				else 
				{
					if(v[i][j]=='1')
					{
						if(v[i][j+1]=='0' and v[i+1][j]=='0')
						{
							ans="NO";
							break;
						}
					
					}
				}

			}
		}
		cout<<ans<<endl;
	}
	

	return 0;
}