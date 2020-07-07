#include <bits/stdc++.h>

using namespace std;
#define deb(x) cout << #x << " " << x << endl;

int main(){
	
	#ifndef ONLINE_JUDGE
	    freopen("in.txt","r",stdin);
	    freopen("out.txt","w",stdout);
	#endif
	
	int n,m;
	while(scanf("%d%d",&n,&m) and n and m){
		vector<int> head, knight;
		long long gold(0);

		for(int i=0,p; i<n; ++i)
			scanf("%d",&p),head.push_back(p);

		for(int i=0,p; i<m; ++i)
			scanf("%d",&p),knight.push_back(p);
		if(n>m){
			printf("Loowater is doomed!\n");
			continue;
		}

		sort(knight.begin(), knight.end());
		sort(head.begin(), head.end());
		bool chk = true;


		for(int i=0, j=0; i<n and chk; ++i){
			while(knight[j]<head[i] and j<m)
				j++;
			
			if(j==m) {
				chk = false;
				break;
			}
			gold += knight[j];
			++j;
		}

		(chk)?
			printf("%lld\n",gold):printf("Loowater is doomed!\n");
			
	}

	return 0;
}
