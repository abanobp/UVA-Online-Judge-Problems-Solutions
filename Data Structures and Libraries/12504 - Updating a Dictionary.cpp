#include<bits/stdc++.h>
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
#define BIG  1000000007
#define ii pair<int,int>
#define iii pair<int,pair<int,int> >
#define MP(a,b) make_pair(a,b)
#define fr first
#define sc second

using namespace std;

//--------------------- This code Written by " Abanob Ashraf " ----------------------------------
//------------------ I Hope To Learn Or Understand Any Thing from it ----------------------------
//----------------------------------- START -----------------------------------------------------


int main()
{
   //   freopen("in.txt","r",stdin);
  //    freopen("out.txt","w",stdout);
    int T ;
    cin >> T ;

    while(T--)
    {

        string old, New ;

        cin >> old >> New ;
        map<string, string> mp ;

        string key, value = "";

        for (int i =  1 ; i < (int) old.size() ; i++)
        {
            if (old[i] == ',')
                mp [key] = value, value = "" ;
            else if (old[i] == '}' && value.size())
                mp [key] = value, value = "";
            else if (old[i] == ':')
                key = value, value = "" ;
            else
                value += old[i] ;
        }

        vector<string> v1, v2, v3 ;

        map<string,string> mp2  ;

         key = value = "" ;
        for (int i =  1 ; i < (int) New.size() ; i++)
        {
            if (New[i] == ',' || (New[i] == '}' && value.size()))
                mp2 [key] = value, value = "" ;
            else if (New[i] == ':')
                key = value, value = "" ;
            else
                value += New[i] ;
        }

        for (map<string,string>::iterator it = mp.begin() ; it != mp.end() ; it++)
        {
            pair<string,string> pr = *it ;

            if (mp2.find(pr.first) == mp2.end())
                v2.push_back(pr.first) ;
            else if (mp2[pr.first] != pr.second)
                v3.push_back(pr.first) ;
        }

        for (map<string,string>::iterator it = mp2.begin() ; it != mp2.end() ; it++)
        {
            pair<string,string> pr = *it ;

            if (mp.find(pr.first)== mp.end())
                v1.push_back(pr.first) ;
        }

        sort(v1.begin(),v1.end()) ;
        sort(v2.begin(),v2.end());
        sort(v3.begin(),v3.end()) ;

        if (!v1.size() && !v2.size() && !v3.size())
            printf("No changes\n") ;
        else
        {
            if (v1.size())
            {
                for (int i = 0 ; i < v1.size() ; i++)
                {
                    if (i)
                        printf(",") ;
                    else
                        printf("+") ;

                    cout << v1[i] ;
                }
                printf("\n");
            }
            if (v2.size())
            {
                for (int i = 0 ; i < v2.size() ; i++)
                {
                    if (i)
                        printf(",") ;
                    else
                        printf("-") ;

                    cout << v2[i] ;
                }
                printf("\n");
            }
            if (v3.size())
            {
                for (int i = 0 ; i < v3.size() ; i++)
                {
                    if (i)
                        printf(",") ;
                    else
                        printf("*") ;

                    cout << v3[i] ;
                }
                printf("\n");
            }
        }
            printf("\n") ;
    }
}
//------------------------------------ DONE -----------------------------------------------------
