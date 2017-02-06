#include <bits/stdc++.h>
#define MAXN 10100
#define STRL 1000
using namespace std;
typedef pair<int, int>PII;
vector< PII > lines;

int main(void)
{
	int T;
	char temp[STRL];
	int x, y, tag, i, j, l, r;
	bool flag;
	fgets(temp,STRL,stdin);
	T = atoi(temp);
	while(T--)
	{
		flag = true;
		lines.clear();
		tag = 0;
		while(1)
		{
			fgets(temp,STRL,stdin);
			if(strncmp(temp,"END",3)==0) break;
			else if(temp[0]=='i')
			{
				sscanf(temp,"if \(expr_%d\(\)\) goto line_%d", &x, &y);
				if(x<y)
				{
					flag = false;
				}
				else
				{
					lines.push_back(make_pair(y,x));
				}
			}
		}
		if(flag)
		{
			// code area;
			//sort(lines.begin(), lines.end(), less< PII >() );
			//for(int i=0; i<lines.size(); i++) lines[i].second=-lines[i].second;
			//for(int i=0; i<lines.size(); i++)
			//	cout<<lines[i].first<<' '<<lines[i].second<<endl;
			//l = lines[0].first; r = lines[0].second;
			for(i=lines.size()-1; i>=1&&flag; --i)
			{
				if( lines[i].first > lines[i-1].first && lines[i].first <= lines[i-1].second ) flag=false;
			}
		}
		cout<< (flag?"good":"bad") << '\n';
		
	}
	return 0;
}
