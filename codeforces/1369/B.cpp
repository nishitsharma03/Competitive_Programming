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
		string s;
		int n;
		cin>>n;
		cin>>s;
		int consc1=0;
		string ans="";

		int  ok=-1;
		fab(0,n,i)
		{
			if(ok==-1 and s[i]=='1')
				ok=i;
			ans+=s[i];
			if(i+1<n and s[i]=='1' and s[i+1]=='0')
			{
				//cout<<"ok:"<<ok<<endl;
				if(ok!=-1)
					ans.erase(ok);
				else
					ans.erase(ans.size()-1);
				//cout<<"ans:"<<ans<<endl;
				ans+='0';
				while(i+1<n and s[i+1]=='0')
					i++;

			}

		}	




		
		//reverse(all(ans));
		cout<<ans<<endl;

	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}