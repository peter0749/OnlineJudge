#include <bits/stdc++.h>
#define MAXL 100010
#define LL long long
using namespace std;

typedef pair<LL int,int> PP;
priority_queue< PP, vector<PP>, greater<PP> > nearest; //length -- vertice.no
vector<int> graph[MAXL]; // vertice-no. -- cost -- wis ;
LL int dist[MAXL];

inline bool dij( int from, int to, int tar_wis, LL int tar_cost)
{
	PP u;
	int v, c, w;
	LL int temp;
	for(int i=0; i<MAXL; i++) dist[i] = 2000000000;
	while(!nearest.empty()) nearest.pop();
	dist[from] = 0;
	nearest.push(make_pair(0, from));
	while(!nearest.empty())
	{
		u = nearest.top(); nearest.pop();
		//cout<<"POP: "<<u.second<<'\n';
		//cout<<"LEN: "<<u.first<<'\n';
		if( u.first > dist[u.second] ) continue;
		if( u.first >= tar_cost ) return false;
		if( u.second == to ) return true;
		for(int i=0; i<graph[u.second].size(); i+=3)
		{
			v = graph[u.second].at(i);
			c = graph[u.second].at(i+1);
			w = graph[u.second].at(i+2);
			if( w > tar_wis ) continue;
			temp = c+u.first;
			if( temp < dist[v] )
			{
				dist[v] = temp; 
				nearest.push(make_pair(dist[v],v));
			}
		}
	}
	//cout<<"From "<<from<<" to "<<to<<" : "<<dist[to]<<'\n';
	return dist[to] < tar_cost;
}

int main(void)
{
	ios::sync_with_stdio(false);
	int T, N, M, K;
	int s1, s2, c, W;
	int min_W, max_W;
	int lp, rp, m;
	//bool flag;
	cin>>T;
	while(T--)
	{
		cin>>N>>M>>K;
		min_W = 2000000000;
		max_W = 0;
		while(M--)
		{
			cin>>s1>>s2>>c>>W;
			s1--; s2--;
			max_W = max(max_W, W);
			min_W = min(min_W, W);
			//Undirected;;
			graph[s1].push_back(s2);
			graph[s1].push_back(c);
			graph[s1].push_back(W);
			graph[s2].push_back(s1);
			graph[s2].push_back(c);
			graph[s2].push_back(W);
		}
		lp = min_W; rp = max_W+1;
		//flag = false;
		while(lp<rp)
		{
			m = (lp+rp)>>1;
			if( dij(0, N-1, m, K) )
			{
				rp = m;
				//cout<< m << " passed\n";
				//flag = true;
			}
			else lp = m+1;
		}
		if(lp<=max_W)
			cout<<lp<<'\n';
		else
			cout<<-1<<'\n';
		for(int i=0; i<MAXL; i++) graph[i].clear();
		while(!nearest.empty()) nearest.pop();
	}
	return 0;
}
