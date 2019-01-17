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
#include<iomanip>
#include<bitset>
#include<limits.h>
#define INF  -1
#define MOD  1000000007
#define ii pair<int,int>
#define iii pair<int,pair<int,int> >
#define MP(a,b) make_pair(a,b)
#define fr first
#define sc second
using namespace std;

//--------------------- This code Written by " Abanob Ashraf " ----------------------------------
//------------------ I Hope To Learn Or Understand Any Thing from it ----------------------------
//----------------------------------- START -----------------------------------------------------
vector<vector<int> > adj ;
int res [50][50], flow, S, T;
vector<int> per ;
string cop ;

int ix (char xx)
{
    return (xx - 'A' + 11 ) ;
}
void path (int u, int mimi)
{
   //  cout << u << " " ;
    if (u == S)
    {
        flow = mimi ;
        return ;
    }
    else if (per [u] != -1)
    {
        if (per[u] > 10)
        {
            char ss = per [u] + 'A' - 11 ;
            cop [u] = ss ;
        }

        path(per [u], min(mimi, res [per[u]][u])) ;
        res [per[u]][u] -= flow ;
        res [u][per[u]] += flow ;
    }
}

bool yes (int sour)
{
    S = sour ;
    T = 10 ;
    flow = 0 ;
    queue<int> q ;
    vector <bool> vis (50, 0) ;
    q.push(S) ;
    vis [S] = 1 ;
    per.clear() ;
    per.assign(50, -1) ;
    while(!q.empty())
    {
        int v = q.front() ;
        q.pop() ;

        if (v == T)
            break ;
        for (int i = 0 ; i < adj[v].size() ; i++)
        {
            int ch = adj[v][i] ;
            //cout << res [v][ch] << " " << vis [ch] <<  "\n" ;
            if (res [v][ch] > 0 && !vis [ch])
            {
                //  cout << ch << " c\n" ;

                q.push(ch), vis [ch] = 1, per [ch] = v ;
            }
        }
    }

    path(T, INT_MAX) ;
    return flow ;
}
int main()
{
    //   freopen("in.txt","r",stdin);
     //   freopen("out.txt","w",stdout);

    string a ;

    vector<pair<int,int> > is ;
    int e = 1 ;
    bool gg = 1 ;

    while (getline(cin, a))
    {
         // cout << "dd" ;
        if (a == "" || gg)
        {
            if (!gg)
            {
                bool f = 1;
                for (int i = 0 ; i < is.size() && f ; i++)
                {
                    int w = is [i].second ;

                    while (w--)
                    {
                        if (!yes(is[i].first))
                        {
                            f = 0 ;
                            break ;
                        }
                       //cout << "\n" ;
                    }
                    //cout << cop << "\n" ;
                }
                if (f)
                    cout << cop << "\n" ;
                else
                    cout << "!\n";
            }

            cop = "__________" ;
            adj.clear() ;
            adj.resize(50) ;
            is.clear() ;
            memset(res, 0, sizeof res) ;

            for (int i = 0  ; i < 10 ; i++)
            {
                res [i][10] = 1 ;
                adj[i].push_back(10) ;
                adj[10].push_back(i) ;
            }

            if (!gg)
                continue ;
            gg = 0 ;
        }


        int p = 3, w = a[1] - '0' ;
        while (a [p] != ';')
        {
            int xx = ix(a[0]) ;
            res [xx][a[p] - '0'] = 1 ;
            adj[xx].push_back(a[p] - '0') ;
            adj[a[p] - '0'].push_back(xx) ;
            p++;
        }

        is.push_back(make_pair(ix(a[0]), w)) ;

    }

    if (!is.size())
        return 0 ;
    bool f = 1;
    for (int i = 0 ; i < is.size() && f ; i++)
    {
        int w = is [i].second ;

        while (w--)
        {
            if (!yes(is[i].first))
            {
                f = 0 ;
                break ;
            }
            // cout << "\n" ;
        }
        //cout << cop << "\n" ;
    }

    if (f)
        cout << cop << "\n" ;
    else
        cout << "!\n";
}
//------------------------------------ DONE -----------------------------------------------------
