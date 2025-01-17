#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
int n, m;
int x[4] = {-1, 0, 1, 0}, y[4] = {0, -1, 0, 1};
char d[4] = {'U', 'L', 'D', 'R'};

struct custom 
{
    char dir;
    int i;
    int j;
};

int main() 
{
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    vector<vector<custom>> s(n, vector<custom>(m));
    queue<vector<int>> q;
    vector<int> temp;
    
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            cin >> v[i][j];
            if (v[i][j] == 'A') 
            {
                temp = {i, j, 0};
                v[i][j] = '*';
                s[i][j].i = -1;
                s[i][j].j = -1;
            }
            else if (v[i][j] == 'M') 
            {
                q.push({i, j, -1});
                v[i][j] = '#';
            }
        }
    }
    q.push(temp);
    if (!temp[0] || temp[0] == n - 1 || !temp[1] || temp[1] == m - 1) 
    {
        cout << "YES" << '\n';
        cout << 0 << '\n';
        return 0;
    }

    while (!q.empty()) 
    {
        auto it = q.front();
        q.pop();
        int i = it[0], j = it[1], type = it[2];
        for (int k = 0; k < 4; k++) 
        {
            int ni = i + x[k], nj = j + y[k];
            if (ni < 0 || ni >= n || nj < 0 || nj >= m || v[ni][nj] == '#' || v[ni][nj] == '*') continue;
            if(type) 
            {
                v[ni][nj] = '#';
                q.push({ni, nj, type});
                continue;
            }

            if (!ni || ni == n - 1 || !nj || nj == m - 1) 
            {
                cout << "YES" << '\n';
                string path = "";
                path += d[k];
                while (s[i][j].i != -1 && s[i][j].j != -1) 
                {
                    path += s[i][j].dir;
                    int pi = s[i][j].i, pj = s[i][j].j;
                    i = pi;
                    j = pj;
                }
                reverse(path.begin(), path.end());
                cout << path.size() << '\n';
                cout << path << '\n';
                return 0;
            }
            s[ni][nj].dir = d[k];
            s[ni][nj].i = i;
            s[ni][nj].j = j;
            v[ni][nj] = '*';
            q.push({ni, nj, 0});
        }
    }

    cout << "NO" << '\n';
}