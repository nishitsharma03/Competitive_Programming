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
string prefsuf(string s)
{
	int n=s.size();
	int lps[n+1]={0};
	int i=1,len=0;
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
			if(len!=0)
			{
				len=lps[len-1];
			}
			else
			{
				lps[i]=0;
				i++;
			}
		}
	}
	if(lps[n-1]==0)
		return "Just a legend";
	fab(1,n-1,i)
	{
		if(lps[i]==lps[n-1])
			return s.substr(0,lps[n-1]);

	}
	if(lps[lps[n-1]-1]==0)
		return "Just a legend";
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
	cout<<prefsuf(s);


	return 0;
}