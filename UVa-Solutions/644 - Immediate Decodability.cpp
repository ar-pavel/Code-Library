#include <bits/stdc++.h>

using namespace std;

bool chk(string a, string b){
	if(a.size()<b.size())	swap(a,b);
	return(a.substr(0,b.size())==b);

}

int main(){
	#ifndef ONLINE_JUDGE
	    freopen("in.txt","r",stdin);
	    freopen("out.txt","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t(0);

	vector<string>lst;
	string s;
	while(cin>>s){

		if(s!="9")
			lst.push_back(s);
			
		while(cin>>s and s!="9")
			lst.push_back(s);

		cout<<"Set "<<++t<<" is ";

		for(int i=0; i<lst.size(); ++i)
			for(int j=0; j<lst.size(); ++j){
				if(i==j) continue;

				if(chk(lst[i],lst[j])){
					cout<<"not ";
					goto end5;
				}
			}

		end5: 
			cout<<"immediately decodable"<<endl;
			lst.clear();
	}

	return 0;
}
