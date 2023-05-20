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
#define for1  for(int i = 0; i < m ; i++)

#define output ios::sync_with_stdio(0);cin.tie(0);
#define for0(l,r) for(int i = (l); i < (r); i++)
#define for1(l,r) for(int j = (l); j < (r); j++)
#define vi vector<int>
#define pii pair<int,int>
#define output ios::sync_with_stdio(0);cin.tie(0);
int dx[] = {1,0,0,-1};
int dy[] = {0,1,-1,0};
int a[2002][2002];
int n;
bool visited[2001][2001];
bool used[2001][2001];
int main()
{
    while(cin >> n and n)
    {
        queue<pii> v;
        memset(visited,false,sizeof(visited));
        memset(used,false,sizeof(used));
        for0(0,2001)
        {
            for1(0,2001)
            {
                a[i][j] = 0;
            }
        }
        for(int i = 0; i < n ; i++)
        {
            int x, y;
            cin >> x >> y;
            v.push({x,y});
            used[x][y] = true;
        }
        int m; cin >> m;
        for(int i = 0; i < m ; i++)
        {
            int x, y; cin >> x >> y;
            visited[x][y] = true;
        }
        int ans;
        while(!v.empty())
        {
            pii top = v.front();
            int i = top.first;
            int j = top.second;
            v.pop();
            if(visited[i][j])
            {
                ans = a[i][j];
                break;
            }
            else{
                for(int k = 0; k < 4 ; k++)
                {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if(ni >= 0 and ni <= 2000 and nj >= 0 and nj <= 2000 and !used[ni][nj])
                    {
                        a[ni][nj] = a[i][j] + 1;
                        v.push({ni,nj});
                        used[ni][nj] = true;
                    }
                }
            }

        }
        cout << ans  << endl;
    }
}