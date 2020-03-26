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
		ll int n;
		cin>>n;
		string s;
		cin>>s;
		string sa,sb;
		bool fl=false;
		fab(0,n,i)
		{
			if(s[i]=='1')
			{
				if(!fl)
				{sa+='1';
				sb+='0';
				fl=true;
				}
				else
				{
					sa+='0';
					sb+='1';
				}

			}
			else if(s[i]=='2')
			{
				if(!fl)
				{sa+='1';
				sb+='1';
				}
				else
				{
					sa+='0';
					sb+='2';
				}

			}
			else
			{
				sa+='0';
				sb+='0';
			}
		}
		cout<<sa<<endl<<sb<<endl;
	}
	

	return 0;
}