#include <iostream>
#include <string>

using namespace std;

void getNext(string patt, int next[]) {//未传递next数组的长度,其长度由patt的长度决定
	int k = -1;
	int j = 0;
	next[0] = -1;
	while (j < patt.size() - 1) {
		//将字符串的第j位和第next[j]位比较是否相等.比较的是前缀和后缀的最后一位
	    	//p[k]表示前缀，p[j]表示后缀
		//k表示已经匹配的字符个数,(由于数组从0开始,所以比较patt[k]和patt[j]是否相等正好是在比较前缀和后缀的第k+1位是否相等)
		if (-1 == k || patt[k] == patt[j]) {
			++k;//只在存在匹配字符时加加
			++j;//j在循环里面不会减少
			//不允许patt[j]==patt[next[j]],因为如果patt[j]匹配失败,下一步必然匹配patt[next[j]],而这必然也会匹配失败
			if(patt[j]!=patt[k]){
				next[j] = k;
			}
			else{
				next[j]=next[k];
			}
		}
		else {
			k = next[k];//若字符不相同,K值回溯
		}
	}
}

int KMP(string S, string P) {
	int next[S.size()];
	getNext(P,next);
	int i=0, j=0;
	int s_len=S.size();
	int p_len=P.size();
	while(i<s_len && j<p_len) {
		if(-1==j || S[i]==P[j]) {
			++i;
			++j;
		}
		else {
			j=next[j];
		}
	}
	if(j==P.size()) {
		return i-j;
	}
	else {
		return -1;
	}
}

int main() {
	while(1) {
		string s1;
		string s2;
		cout<<"请输入字符串1:";
		cin>>s1;
		if(s1=="-1"){
			break;
		}
		cout<<"请输入字符串2:";
		cin>>s2;
		cout<<"result:"<<KMP(s1,s2)<<endl;
	}

	return 0;
}
