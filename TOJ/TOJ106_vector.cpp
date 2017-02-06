#include <bits/stdc++.h>
#define MAX 3010
using namespace std;

typedef vector<int> V;
typedef vector< V > G;

G nodes;

inline bool dfs(const int n)
{
    if(nodes.at(n).at(0))return true;/*Visited*/
    int len=nodes.at(n).size();
    if(len<=1){/*nodes.at(n).at(0)=1;*/return false;}
    /*The nth node is empty. This means that no one connect with it. Return not visited.*/
    nodes.at(n).at(0)=1;
    for(int i=1; i<len; i++)
        dfs(nodes.at(n).at(i));/*Find the connected nodes. And mark them.*/
    return false;/*Return unvisited.*/
}

int main(void)
{
    int term;
    int p, q;
    int n,e;
    //V temp;
    int ans=0;
    ios::sync_with_stdio(false);
    //temp.push_back(0);/*First element represent status of visit. At first, all nodes are not visited*/
    cin>>term;
    while(term--)
    {
        cin>>n>>e;
        nodes.resize(n);
        for(int i=0; i<n; i++)
        {
            nodes.at(i).push_back(0);
        }/*There are 'n' nodes.*/
        for(int i=0; i<e; i++)/* and 'e' edges.*/
        {
            cin>>p>>q;/*Enter a edge.*/
            nodes.at(p).push_back(q);
            nodes.at(q).push_back(p);/*Undirected Graph*/
        }

        ans = 0;
        for(int i=0; i<n; i++)
            if(!dfs(i))ans++;/*Count the connected nodes. Which has not visited.*/
        cout<<ans<<'\n';
        nodes.clear();
    }
    //temp.clear();
    return 0;
}
