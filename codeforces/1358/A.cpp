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

 		ll ans=((m+1)/2)*n;
 		if(m%2)
 		{
 			ans=(m/2)*n+(n+1)/2;
 		}
 		cout<<ans<<endl;
 	}
 	
 
 	return 0;
 }