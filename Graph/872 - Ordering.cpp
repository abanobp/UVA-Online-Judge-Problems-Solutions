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
vector<vector<int> > gr (30);
bool vis [ 50 ],check;
vector<char>var;

bool YES (int v)
{
    for (int i = 0 ; i<gr[v].size() ; i++ )
        if (vis[gr[v][i]])
            return 0;
    return 1;
}
void print (int sz,string a)
{
 if (sz==var.size()){
        a.erase(a.size()-1,1);
        cout<< a <<"\n";
        check = 1 ;
    return ;
 }
    for ( int i = 0 ; i <var.size() ; i++ )
    {
     if (!vis[ var[i]-65 ] ){
          if (YES(var[i]-65)){
            vis[var[i]-65] = 1 ;
         print(sz+1,a + var [ i ] + " ");
            vis[var[i]-65] = 0 ;
                }
                else
                    return;
     }
    }
}

int main()
{
     //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T ;
    scanf("%d",&T);
    string lin ,a;
    getline(cin,lin);
    int f =1;
    while (getline(cin,a),T--){
            if (f==0)
            printf("\n");
            f=0;
            memset(vis,0,sizeof vis);
            gr.clear();
            gr.resize(30);
            var.clear();
            check = 0;
    string b ,con;

    getline(cin,a);

    getline(cin,b);

    stringstream aa(a);
    char res;
    while (aa>>res)
        var.push_back(res);
    stringstream ss (b);
    while (ss>>con)
       gr[con[0]-65].push_back(con[2]-65);

    sort(var.begin(),var.end());

    print(0,"");
    if (!check)
    printf("NO\n");
    }
}
