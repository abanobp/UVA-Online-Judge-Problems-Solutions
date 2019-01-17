#include <iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
#include<math.h>
#include<map>
#include<stack>
#include<sstream>
#include<queue>
#include<list>
using namespace std;
vector<vector <int> > adj ;
int dis [205][205];

void BFS (int u)
{
    queue<int> q ;

    q.push(u);
    int level = 0 , sz = 1 ;
    bool vis [205] ;
    memset(vis , 0 , sizeof vis);
    vis [u] = 1;
    while(!q.empty())
    {
        int top = q.front();
        q.pop();
        sz--;
        for (int i = 0 ; i < adj[top].size() ; i++)
        {
            if (!vis [adj[top][i]])
            {
                q.push(adj[top][i]);
                vis [adj[top][i]] = 1 ;
                dis [u][adj[top][i]]= level + 1 ;
            }
        }
        if ( sz == 0 )
        {
            level++ ;
            sz = q.size();
        }
    }
}

int main()
{
        freopen("in.txt","r",stdin);
       // freopen("out.txt","w",stdout);

        int N ;
        scanf( "%d" , &N ) ;
        string b ;
        getline(cin , b) ;
         getline(cin , b) ;

        while (N--)
        {
            string a ;
            vector<string> v ;
            map<string , int> mp ;
            memset(dis , 0 , sizeof dis ) ;
            adj.clear();

            while ( cin >> a )
            {
                if (a == "*")
                    break;
                v.push_back(a);
                mp[a] = v.size() - 1 ;
            }

            adj.resize(v.size()+5);

            for (int i = 0 ; i < v.size() ; i++)
            {
                for (int j = 0 ; j < v.size() ; j++)
                {
                    if (v[i].size() == v[j].size()){
                    int c = 0 ;
                    for (int k = 0 ; k < v[i].size() ; k++)
                    {
                        if (v[i][k] != v[j][k])
                            c++;
                    }
                    if (c == 1)
                        adj [i].push_back(j);
                    }
                }
            }

            for (int i = 0 ; i < v.size() ; i++)
            {
                BFS(i);
            }

            string line ;
            getline(cin , line);
            while (getline(cin , line))
            {
                if (line=="")
                    break;

                stringstream ss (line);
                string x , y ;
                ss >> x >> y;

                cout << line <<" " << dis [mp [x]] [mp [y]] << "\n";
            }
           if (N)
                cout<<"\n";
        }
}
