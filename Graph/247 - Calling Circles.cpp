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
int counter  = 1 , circls = 0 ;
vector<vector<int> > calls;
int num [30] , low [ 30 ] , vis [30];
vector<int> stac ;
vector<string>names ;
vector<vector<string> > sets;

void strong (int v )
{
    low [v] = num [v] = counter++;
    stac.push_back(v) ;
    vis [v] = 1;

    for (int i = 0 ; i < calls[v].size() ; i++ )
    {
        int ch = calls [v][i];
        if (num [ch] == -1 )
            strong(ch);

        if (vis[ch]!=-1)
            low [v] = min(low[v] , low[ch]);
    }

    if (low[v] == num [v])
    {
        vector<string>a;
        vis [v] = -1;
        while (v != stac.back())
        {
            vis [stac.back()] = -1 ;
          a.push_back(names[stac.back()]);
            stac.pop_back();
        }
        a.push_back(names[stac.back()]);
        stac.pop_back();
        sets.push_back(a);

    }
}

int main()
{
      freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int N , M , T = 1;

    while (scanf("%d%d",&N,&M) && N )
    {
         //cout<<N <<" " << M <<"\n";
         if (T != 1)
            cout<<"\n";

        counter = 1, circls = 0;
        memset(vis, -1 , sizeof vis );
        memset(num , -1 , sizeof num ) ;
        memset(low , -1 , sizeof low) ;
        calls.clear();
        calls.resize(N) ;
        sets.clear();
        map<string , int > in ;
        names.clear();
        int c = 0 ;

        for (int i = 0 ; i < M ; i++ )
        {
            string a , b ;
            cin >> a >> b;

             if (in.find(a)==in.end())
               names.push_back(a),in[a] = names.size() - 1 ;

             if (in.find(b)==in.end())
               names.push_back(b),in[b] = names.size() - 1 ;
            calls [in[a]].push_back(in [b]);
        }

        for (int i = 0 ; i < N ; i++)
        {
            if (num [i] == -1)
                strong(i);

        }

        cout<<"Calling circles for data set "<<T++<<":\n";
        for (int i = 0 ; i < sets.size() ; i++ )
        {
            for (int j = 0 ; j<sets[i].size() ; j++)
            {
                cout << sets[i][j];
            if (j != sets[i].size()-1)
                cout << ", ";
            }
            cout<< "\n";
        }

    }

}
