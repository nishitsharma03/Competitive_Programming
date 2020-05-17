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
		cin>>s;
		ll n=s.size();
		ll a,b,c,i=0;
		
			a=0;
			b=0;c=0;
			//cout<<"n:"<<n<<endl;

			while(i<n and (a==0 or b==0 or c==0))
			{
				if(s[i]=='1')
					a++;
				else if(s[i]=='2')
					b++;
				else
					c++;
				i++;

			}
			//cout<<"dsf"<<i<<endl;
			//i++;
			ll ans=0;
			if(i<=n and(a>0 and b>0 and c>0))
			ans=i;
		else
			ans=0;
			ll left=0;
			bool fl=true;
			i--;
			while(left<n and i<n )
			{
				//cout<<"a:"<<a<<" "<<b<<" "<<c<<endl;
				if(fl)
				{if(s[left]=='1')
					a--;
				else if(s[left]=='2')
					b--;
				else
					c--;}
				else
				{

				if(s[i]=='1')
					a++;
				else if(s[i]=='2')
					b++;
				else
					c++;
				}
				//left++;
				//cout<<"i:"<<i<<" "<<left<<endl;
				if(a>0 and b>0 and c>0)
				{
					left++;
					//cout<<"i:"<<i<<" "<<left<<endl;
					ans=min(ans,i-left+1);
					fl=true;
				}
				else
					{i++;
						fl=false;}







			}
			cout<<ans<<endl;

		
	}
	

	return 0;
}