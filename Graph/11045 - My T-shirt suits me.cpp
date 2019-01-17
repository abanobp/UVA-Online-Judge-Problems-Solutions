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
int res [50][50] , flow , S , T;
vector<int> per ;
int T_sh (string a)
{
    return (a == "XS")?0:(a == "S")?1:(a == "M")?2:(a == "L")?3:(a == "XL")?4:5 ;
}

void path (int u , int mimi)
{
    //cout << u << " " ;
    if (u == S)
    {
        flow = mimi ;
        return ;
    }
    else if (per [u] != -1)
    {
        path(per [u] , min(mimi , res [per[u]][u])) ;
        res [per[u]][u] -= flow ;
        res [u][per[u]] += flow ;
    }
}

bool yes (int sour)
{
    S = sour ;
    T = 6 ;
    flow = 0 ;
    queue<int> q ;
    vector <bool> vis (50 , 0) ;
    q.push(S) ;
    vis [S] = 1 ;
    per.clear() ;
    per.assign(50 , -1) ;
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

                q.push(ch) , vis [ch] = 1 , per [ch] = v ;
            }
        }
    }

    path(T , INT_MAX) ;
    return flow ;
}
int main()
{
    //  freopen("in.txt","r",stdin);
    //  freopen("out.txt","w",stdout);

    int tes  ;
    cin >> tes ;

    while (tes--)
    {
        int N , M ;
        scanf("%d%d" , &N, &M) ;
        adj.clear() ;
        adj.resize(50) ;
        memset(res , 0 , sizeof res) ;

        for (int i = 0 ; i < M ; i++)
        {
            string a , b ;
            cin >> a >> b ;
            res[i + 7][T_sh(a)] = 1 ;
            res[T_sh(a)][i + 7] = 1 ;
            res[i + 7][T_sh(b)] = 1 ;
            res[T_sh(b)][i + 7] = 1 ;
            adj[i + 7].push_back(T_sh(a)) ;
            adj[T_sh(a)].push_back(i + 7) ;
            adj[i + 7].push_back(T_sh(b)) ;
            adj[T_sh(b)].push_back(i + 7) ;
        }

        for (int i = 0 ; i < 6 ; i++)
        {
            res [6][i] = N / 6 ;
            res [i][6] = N / 6 ;
            adj[6].push_back(i) ;
            adj[i].push_back(6) ;
        }

        bool f = 1;
        for (int i = 7 ; i < M + 7 ; i++)
        {

            if (!yes(i)){
                f = 0 ;
                break ;
            }
           // cout << "\n" ;
        }

        if (f)
            printf("YES\n");
        else
            printf("NO\n");

    }
}
//------------------------------------ DONE -----------------------------------------------------
