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
map<pair<int,int> , int> edg ;
vector<vector<int> > adj ;
int flow , S , T ;
vector<int>  aa , bb;
vector<set<int> > is ;
int vis [50200] , per [50200] ;
void path (int u, int mimi)
{
      // cout << u << " " ;
    if (u == S)
    {
        flow = mimi ;
        return ;
    }
    else if (per [u] != -1)
    {
        path(per[u] , min(mimi , edg[make_pair(per[u],u)]));
        edg[make_pair(per[u],u)] -= flow ;
        edg[make_pair(u,per[u])] += flow ;

        if (flow){
        if (u > 100)
            is [u].insert(per[u]) ;
        else
            is[per[u]].erase(u) ;
        }
    }
}

int yes (int sour)
{
    S = sour ;
    T = 100 ;
    flow = 0 ;
    queue<int> q ;
    memset(vis , -1 , sizeof vis)  ;
     memset(per , -1 , sizeof per)  ;

    q.push(S) ;
    vis [S] = 0 ;

    while(!q.empty())
    {
        int v = q.front() ;
        q.pop() ;

        if (v == T)
            break ;
        for (int i =0 ; i < adj[v].size(); i++)
        {
            int ch =  adj[v][i]  ;

            if ( edg [make_pair(v,ch)] > 0 && vis [ch] == -1)
            {
                q.push(ch), vis [ch] = 1, per [ch] = v , vis [ch] = vis [v] + 1 ;
            }
        }
    }

    if (vis [T] == -1)
        return 0 ;
    int MF = 0 ;
    for (int i = 102 ; i < 50105 ; i++)
    {
        if (vis [T] - 1 == vis [i] && edg [make_pair(i,T)] > 0 )
        {
            flow = 0 ;
            path(i,edg [make_pair(i,T)] ) ;
         //   cout << flow << " \n";
            MF += flow ;
            edg [make_pair(i,T)] -= flow ;
            edg [make_pair(T,i)] += flow ;
        }
    }
    return MF ;
}
int main()
{
       freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);


    int N , tes = 1 ;
    adj.resize(50200) ;
    vector<int> vv (100) ;
    is.resize(50200);
    aa.resize(100) , bb.resize(100) ;

    while (scanf("%d" , &N) && N)
    {

        int M ;
        scanf("%d" , &M) ;

        edg.clear() ;

        for (int i = 0 ; i < 50200 ; i++)
            is[i].clear() , adj[i].clear() ;

        int tot = 0 ;

        for (int i = 0 ; i < N ; i++)
        {
            int a , b ;
            scanf("%d%d%d" , &vv[i] , &a , &b);
             a += 102 , b += 102 ;
             aa [i] = a , bb [i] = b ;
             tot += vv[i] ;
             edg[make_pair(101 , i)] = vv[i] , adj[101].push_back(i) ,adj[i].push_back(101);

            for (int j = a ; j < b ; j++){
                edg[make_pair(i , j)] = 1 , adj[i].push_back(j) ,adj[j].push_back(i);
                if (!edg [make_pair(j , 100)]){
                edg [make_pair(j , 100)] = M ;
                adj[j].push_back(100) ;
                adj[100].push_back(j);
                }
            }
        }
        bool f = 1 ;

        while(tot && f)
        {
           int res =  yes(101) ;
           f= res ;
           tot -= res ;
        }

        printf("Case %d: " , tes++) ;

        if (!f)
            cout << "No\n" ;
        else
        {
            cout << "Yes\n" ;

            for (int i = 0 ; i < N ; i++)
            {
                int a , b , c = 0 ;
                vector <pair<int,int> > pp ;
                for (int j = aa[i] ; j < bb[i] ; j++)
                {
                    if (is[j].find(i) != is[j].end())
                    {
                        if (!c)
                            a =  b = j ;
                        else
                            b = j ;
                        c++;
                    }
                    else
                    {
                        if (c)
                           pp.push_back(make_pair(a - 102,b - 102 + 1)) ;
                        c = 0 ;
                    }
                }
                 if (c)
                   pp.push_back(make_pair(a - 102,b - 102 + 1)) ;

                printf("%d" , pp.size()) ;
                for (int j = 0 ; j < pp.size() ; j++)
                {
                    printf(" (%d,%d)",pp[j].first,pp[j].second) ;
                }

                printf("\n") ;
            }
        }

    }
}
//------------------------------------ DONE -----------------------------------------------------
