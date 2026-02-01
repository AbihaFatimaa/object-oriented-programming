# include <iostream>
# include <string>
using namespace std;
int main(){
	int arr[8] = {12, 8, 9, 5, 2, 20, 6, 3};
	for(int i=0; i<8; i++){
		for(int j=1; j<7; j++){
			if(arr[i]%arr[j]==0){
				if(arr[j]!=arr[i]){
				cout<<arr[i]<<" "<<arr[j]<<"-";
			}}
		}
	}
	return 0;
}