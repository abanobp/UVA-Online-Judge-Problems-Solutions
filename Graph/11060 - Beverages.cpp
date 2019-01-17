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
using namespace std;
map<string , vector<string > > alco;
map<string , int> in;
vector<string>bev;
int yes [105],sz = 0,N;
void print ()
{
    if (sz==N)
      return;
    for (int j = 0 ; j < N ; j++)
    {
        if (yes [j] == 0)
            {
                if (sz==N-1)
                    cout<<bev [j];
                else
                    cout<<bev [j] << " ";
                for (int i = 0 ; i < alco [bev[j]].size() ; i ++)
                    yes [in [alco [bev[j]][i]]]--;
                    sz++;
                yes [j] = -1;
                break;
            }
    }
    print ();
}
int main()
{
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int f = 0;

    while (scanf("%d",&N)!=EOF)
        {

            sz = 0;
            f++;
            memset(yes,0,sizeof yes);
            alco.clear();
            in.clear();
            bev.clear();
            bev.resize(N);
            for (int i = 0 ; i < N ; i++){
                cin>>bev [ i ];
                in.insert(make_pair(bev [i] , i ));
            }
            int T ;
            scanf("%d",&T);

            for (int i = 0 ; i < T ; i++)
            {
                string a , b;
                cin >> a >> b ;

                if ( alco.find(a) == alco.end() )
                {
                    vector<string >v;
                    v.push_back(b);
                    alco.insert(make_pair(a,v));
                }
                else
                    alco[a].push_back(b);
                    yes [in [b]]++;
                }

            printf("Case #%d: Dilbert should drink beverages in this order: ",f);

            print();
            printf(".\n\n");

        }
}

