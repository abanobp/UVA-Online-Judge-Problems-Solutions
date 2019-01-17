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
#define INF  1000000007
#define MOD  1000000007
#define ii pair<int,int>
#define iii pair<int,pair<int,int> >
#define fr first
#define sc second
using namespace std;
vector<vector<int> > en ;
vector<int> col ;

int enemy (int ix)
{
    queue<int> q ;
    q.push(ix) ;
    col [ix] = 1 ;
    int ans1 = 1 , ansz = 0 , p = 0;

    while (!q.empty())
    {
        int ch = q.front() ;
        q.pop() ;

        for (int i = 0 ; i < en [ch].size() ; i++)
        {
            if (col [en [ch][i]] == -1)
            {
                col [en [ch][i]] = abs (col [ch] - 1 ) ;
                q.push(en [ch][i]) ;
                ( col [en [ch][i]])?ans1++:ansz++;
            }
            else if (col [en [ch][i]] == col [ch])
                p = 1 ;
        }
    }

    if (p)
        ans1 = ansz = 0 ;
    return max(ans1,ansz) ;
}
int main()
{
         freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);

    int M ;
    scanf("%d" , &M) ;

    while (M--)
    {
        int N ;
        cin >> N ;
        en.clear() ;
        en.resize(N + 5) ;
        col.assign(N + 5 , -1) ;

        for (int i = 1 ; i <= N ; i++)
        {
            int a ;
            cin >> a ;

            while (a--)
            {
                int b ;
                scanf("%d" , &b) ;
                if (b <= N){
                en [i].push_back(b) ;
                en [b].push_back(i) ;
                }
            }
        }

        int tot = 0 ;

        for (int i = 1 ; i <= N ; i++)
        {
            if (col [i] == -1)
                tot += enemy(i) ;
                //cout << tot << "\n" ;
        }

        printf("%d\n" , tot) ;
    }
}
