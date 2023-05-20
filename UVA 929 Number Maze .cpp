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

#define for0 for(int i = 0 ; i < n ; i++)
#define for1  for(int j = 0; j < m ; j++)
#define memset() memset(visited,false,sizeof(visited))
#define endl "\n"
#define output ios::sync_with_stdio(0);cin.tie(0);
int n, m;
int dx[] = {1,0,0,-1};
int dy[] = {0,1,-1,0};
struct edge{
    int u, v;
    int w;
     bool operator>(const edge &e) const
    {
        return this->w > e.w;
    }
};
int a[10000][10000];
bool visited[10000][10000];
void dijkstra()
{
    int d[n][m];
    for0
    {
        for1
        {
            d[i][j] = INT_MAX;
        }
    }
    d[0][0] = a[0][0];
    priority_queue<edge,vector<edge>,greater<edge>> ve;
    edge e ; e.u = 0;
    e.v = 0;
    e.w = a[0][0];
    ve.push(e);
    while(!ve.empty())
    {
        int u = ve.top().u;
        int v = ve.top().v;
        int w = ve.top().w;
        ve.pop();
        visited[u][v] = true;
        if(w > d[u][v]) continue;
        for(int k = 0; k < 4 ; k++)
        {
            int ni =  u + dx[k];
            int nj =  v + dy[k];
            if(ni >= 0 and ni < n and nj >= 0 and nj < m  and !visited[ni][nj])
            {
                if(d[ni][nj] > d[u][v] + a[ni][nj])
                {
                    d[ni][nj] = d[u][v] + a[ni][nj];
                    edge neww; neww.u = ni; neww.v =nj; neww.w = d[ni][nj];
                    ve.push(neww);
                }
            }
        }

    }
    cout << d[n-1][m-1] << endl;

}
int main()
{
    int tc; cin >> tc;
    output;
    while(tc --)
    {
        cin >> n;
        cin >> m;
        memset();
        for0
        {
            for1
            {
                cin >> a[i][j];
            }
        }
        dijkstra();
    }
}