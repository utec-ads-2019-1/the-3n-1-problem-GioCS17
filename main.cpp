#include <iostream>
#include<unordered_map>

using namespace std;

long long int cycles(unordered_map<long long int,long long int> &arr,long long int num){
	long long int cont=0;
	if(num==1)
		return 1;
	if(arr.count(num)!=0)
		return arr[num];
	if(num & 1)
		cont=cycles(arr,num*3+1)+1;
	else
		cont=cycles(arr,num>>1)+1;

	arr[num]=cont;
	return cont;
}
int main(int argc, char *argv[]) {

	long long int i,j;
	unordered_map<long long int,long long int> arr;
	for(long long int i=1;i<1000000;i++)
		long long aux=cycles(arr,i);
		
	arr[1]=1;
	while(cin>>i>>j){
		long long int maxi=0;
		long long int ini=i>j?j:i;
		long long int fin=i<j?j:i;
		for(long long int k=ini;k<=fin;k++){
			if(arr[k]>maxi)
				maxi=arr[k];
		}
		cout<<i<<" "<<j<<" "<<maxi<<endl;
	}
    return 0;
}
