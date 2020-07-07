#include<bits/stdc++.h>

using namespace std;

int main(){
 	#ifndef ONLINE_JUDGE
 	    freopen("in.txt","r",stdin);
 	    freopen("out.txt","w",stdout);
 	#endif

 	ios::sync_with_stdio(false);
 	cin.tie(0);cout.tie(0);

	string s;
    while(cin>>s){
        list <char> sen;
     
        int i=0;
        while(i<s.size()){
            if(s[i]=='[')
                it = sen.begin();
            else if(s[i] == ']')
                it = sen.end();
            else
                sen.insert(it,s[i]);
                i++;
        }
        for(auto it: sen)
        	cout<<it;
        
        cout<<endl;
    }
    return 0;
}
