#include<bits/stdc++.h>

using namespace std;

map<char,string>enc;
map<string,char>dc;

void encode(string s){
	string msg = "";
	for(int i=0; s[i]; ++i){
		msg = enc[s[i]]+msg;
	}
	cout<<msg<<endl;
}

void decode(string s){
	string msg = "";
	for(int i=0; s[i]; ){
		string t="";t += s[i];t += s[i+1];
		string t1; t1 += s[i];t1 += s[i+1]; t1 += s[i+2];
		//cout<<dc[t1]<<endl;
		if(dc[t]){	
			msg = dc[t]+msg;
			i += 2;
		}else{
			msg = dc[t1]+msg;
			i += 3;
		}
	}
	cout<<msg<<endl;

}

string rev(int a){
	string b = to_string(a);
	reverse(b.begin(), b.end());
	return b;
}

void init(){
	for(char i = 'a'; i<='z'; ++i){
		string s = rev((int)i);
		enc[i]=s;
		dc[s] =i;
	}
	for(char i = 'A'; i<='Z'; ++i){
		string s = rev((int)i);
		enc[i]=s;
		dc[s] =i;
	}
	enc[' ']="23";
	enc['!']="33";
	enc[',']="44";
	enc['.']="64";
	enc[':']="85";
	enc[';']="95";
	enc['?']="36";

	dc["23"]=' ';
	dc["33"]='!';
	dc["44"]=',';
	dc["64"]='.';
	dc["85"]=':';
	dc["95"]=';';
	dc["36"]='?';
}

int main(){
	
	#ifndef DEAD_MAN
	    freopen("in.txt","r",stdin);
	    freopen("out.txt","w",stdout);
	#endif

	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	init();

	string s;
	while(getline(cin,s)){
		s[0]<='9' and s[0]>='1'?decode(s):encode(s);
	}

	
return 0;
}
