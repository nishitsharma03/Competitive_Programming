#include<bits/stdc++.h>
#define boost ios::sync_with_stdio(false); cin.tie(0)
#define ll              long long int
#define ld              long double
#define mk              make_pair
#define pb              push_back
#define f               first
#define s               second
#define fo(i,a,b)       for(i=a;i<b;i++)
#define foe(i,a,b)      for(i=a;i<=b;i++)
#define all(x)          x.begin(),x.end()
#define vi              vector<int>
#define vl              vector <long long int>
#define vpii            vector< pair<int,int> >
#define vpll            vector < pair <long long int,long long int> >
#define MOD             1000000007
using namespace std;


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    boost;
    
   string s;
   cin>>s;
   cout<<((s[6]-'0')%2)<<endl;
    

    return 0;
}