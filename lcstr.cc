#include <iostream>
#include <string>

using namespace std;

int table[100][100];
int max_len=0,tail=0;
void lcstr(string s1, string s2) {
	max_len=0,tail=0;
	for(int i=0; i<=s1.size(); ++i) {
		table[i][0]=0;
	}
	for(int j=0; j<=s2.size(); ++j) {
		table[0][j]=0;
	}
	for(int i=1; i<=s1.size(); ++i) {
		for(int j=1; j<=s2.size(); ++j) {
			if(s1[i]==s2[j]) {
				table[i][j]=table[i-1][j-1]+1;
			}
			if(table[i][j]>max_len) {
				max_len=table[i][j];
				tail=i;
			}
		}
	}
}

void printlcstr(string &s1, int head, int tail) {
	for(int i=head; i<=tail; ++i) {
		cout<<s1[i];
	}
}

int main() {
	string s1,s2;
	while(1) {
		//s1="ACCGGTCGAGTGCGCGGAAGCCGGCCGAA";
		//s2="GTCGTTCGGAATGCCGTTGCTCTGTAAA";
		cout<<"字符串s1=";
		cin>>s1;
		if("-1"==s1) {
			break;
		}
		cout<<"字符串s2="; 
		cin>>s2; 
		lcstr(s1,s2);
		printlcstr(s1, tail-max_len+1, tail);
		cout<<endl;
		for(int i=0; i<=s1.size(); ++i) {
			for(int j=0; j<=s2.size(); ++j) {
				cout<<table[i][j];
				if(table[i][j]<=9) {
					cout<<"  ";
				}
				else {
					cout<<" ";
				}
			}
			cout<<endl;
		}
	}
}
