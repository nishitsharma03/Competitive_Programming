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
string bulidlps(string s)
{
	int n=s.length();
	int i=1;
	int len=0;
	int lps[n+1]={0};
	while(i<n)
	{
		if(s[i]==s[len])
		{
			len++;
			lps[i]=len;
			i++;

		}
		else
		{
			if(len==0)
				{
					lps[i]=0;
					i++;
				}
				else
				{
					len=lps[len-1];
				}
		}
	}
	if(lps[n-1]==0)
		return "Just a legend\n";

	fab(1,n-1,i)
	{
		if(lps[i]==lps[n-1])
			return s.substr(0,lps[n-1]);
				
	}
	if(lps[lps[n-1]-1]==0)
		return "Just a legend\n";
	else
		return s.substr(0,lps[lps[n-1]-1]);
}

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	string s;
	cin>>s;
	cout<<bulidlps(s);


	return 0;
}