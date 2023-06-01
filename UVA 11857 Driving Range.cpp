/* 
Author : Nguyen Xuan An 
Gmail : xuanan437@gmail.com
*/   
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define for0(i ,l ,r) for(int i = (l); i < (r); ++i)
#define for1(i, l, r) for(int i = (l); i >= (r); --i)
#define for2(v) for(auto it : v)
#define reset(a) memset(a,0,sizeof(a))
#define mem(a) memset(a,-1,sizeof(a))
#define membo(a) memset(a,false,sizeof(a))

#define vi vector<int>
#define vpi vector<pair<int, int>>
#define pii pair<int,int>
#define fi first
#define se second
#define prq priority_queue
#define pb push_back

#define output ios::sync_with_stdio(0);cin.tie(0);
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define PI 3.1415926535897932385
#define INF 10000000

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a) | (b))
#define XOR(a,b) ((a) ^ (b))


#define ll long long
#define sst stringstream
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define for0 for(int i = 0 ; i < n ; i++)
#define for1  for(int j = 0; j < m ; j++)
#define memset() memset(visited,false,sizeof(visited))
#define endl "\n"
#define output ios::sync_with_stdio(0);cin.tie(0);
struct edge{
    ll u,v;
    ll w;
};
ll n, m;
ll parent[100000];
void make_set()
{
    for(ll i = 0 ; i < n ; i++)
    {
        parent[i] = i;
    }
}
int find(ll a)
{
    if(a == parent[a]) return a;
    return parent[a] = find(parent[a]);
}
bool union1(ll a,ll b)
{
    a = find(a); b = find(b);
    if(a == b) return false;
    parent[b] = a;
    return true;
}
vector<edge> dsc;
vector<edge> mst;
bool cmp(edge a, edge b)
{
    return a.w < b.w;
}
ll maxx;
void kruskal()
{
    sort(dsc.begin(),dsc.end(),cmp);
    maxx = INT_MIN;
    for(auto it : dsc)
    {
        if(mst.size() == n - 1) break;
        if(union1(it.u,it.v))
        {
            maxx = max(it.w,maxx);
            mst.push_back(it);
        }
    }
    if(mst.size() != n - 1) cout << "IMPOSSIBLE" << endl;
    else cout << maxx << endl;

}
int main()
{
    output;
    while(cin >> n >> m and (n||m))
    {
        while(m --)
        {
            ll x, y, w; cin >> x >> y >> w;
            dsc.push_back({x,y,w});
        }
        make_set();
        kruskal();
        dsc.clear();
        mst.clear();

    }
}