#include <iostream>
#include <string>

using namespace std;

void getdp(int *arry, int n, int *dp){
	//int dp[n];
	dp[0]=1;
	int auxiliary[n];
	auxiliary[0]=arry[0];
	int end=0;
	int left=0;
	int right=0;
	int middle=0;
	for(int i=1; i<n; ++i){
		left=0;
		right=end;
		while(left<=right){
			middle=(left+right)/2;
			if(auxiliary[middle]<arry[i]){
				left=middle+1;
			}
			else{
				right=middle-1;
			}
		}
		if(left>end){
			end=left;
		}
		auxiliary[left]=arry[i];
		dp[i]=left+1;
	}
	//return dp;
}

void printLIS(int *arry, int n, int *dp){
	int index=0;
	int len=0;
	for(int i=1; i<n; ++i){
		if(arry[i]>arry[index]){
			index=i;
		}
	}
	len=dp[index];
	int result[len];
	int j=len;
	result[--j]=arry[index];
	for(int i=index-1; i>=0; --i){
		if(arry[i]<arry[index]){
			if(dp[i]+1==dp[index]){
				index=i;
				result[--j]=arry[index];
			}
		}
	}
	for(int i=0; i<len; ++i){
		cout<<result[i]<<" ";
	}
	cout<<endl;
}


int main(){
	int arry[13]={12,34,6,4,8,4,6,9,46,89,45,33,24};
	int dp[13];
	//int auxiliary[13];
	getdp(arry,13,dp);
	printLIS(arry,13,dp);
	return 0;
}
