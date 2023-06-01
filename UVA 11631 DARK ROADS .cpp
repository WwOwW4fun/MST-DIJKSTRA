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
#define out ios::sync_with_stdio(0);cin.tie(0);
struct edge{
    int u;
    int v;
    int w;
};
int n, m;
int parent[10000];
int sze[10000];
void make_set()
{
    for(int i = 0 ; i < n ; i++)
    {
        parent[i] = i;
        sze[i] = 1;
    }
}

int find(int a)
{
    if(a == parent[a]) return a;
    return parent[a] = find(parent[a]);
}
bool union1(int a, int b)
{
    a = find(a); b = find(b);
    if(a == b) return false;
    if(sze[a] < sze[b]) swap(a, b);
    parent[b] = a;
    sze[a] += sze[b];
    return true;
}
int cmp(edge a, edge b)
{
    return a.w < b.w;
}
vector<edge> dsc;
vector<edge> mst;
int ans;
void kruskal()
{
    ans = 0;

    sort(dsc.begin(), dsc.end(),cmp);
    for(edge it : dsc)
    {
        if(mst.size() == n - 1) break;
        if(union1(it.u, it.v))
        {
            mst.push_back(it);
            ans += it.w;
        }
    }

}
int main()
{
   out;
   while(cin >> n >> m and (n||m))
   {
       ll sum = 0;
        while(m --)
        {
            int x, y, w; cin >> x >> y >> w;
            dsc.push_back({x,y,w});
            sum += w;
        }

        make_set();
        kruskal();
        cout << sum-ans << endl;
        mst.clear();dsc.clear();
   }
}