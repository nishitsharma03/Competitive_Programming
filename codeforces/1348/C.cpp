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
		ll int n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		sort(all(s));
		//string ans[k];
		ll int freq[26]={0};
		fab(k,n,i)
		{
			freq[s[i]-'a'];
		}
		if(k==1)
		{
			cout<<s<<endl;
			continue;
		}
		else if(k==n)
		{
			cout<<s[n-1]<<endl;
			continue;
		}

		else
		{
			string res="empty";
			fab(0,k,i)
			{
				if(s[i]!=s[0])
				{
					res=s[k-1];
					break;
				}
			}
			if(res=="empty")
			{ 
				if(count(s.begin()+k,s.end(),s[k])==n-k)
				{
					res=s[0];
				//	cout<<"check:";
					//if((n-k)/k>0)
					res+=string(((n-k)+k-1)/k,s[k]);
					//else
					//	res+=string(1,s[k]);
					cout<<res<<endl;
					continue;
				}
				cout<<s[0]<<s.substr(k,n)<<endl;

			}
			else
				cout<<res<<endl;
		}
	}
	

	return 0;
}