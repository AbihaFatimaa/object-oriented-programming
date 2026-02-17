# include <iostream>
# include <string>
using namespace std;
int main(){
	int row = 2;
	int cols = 3;
	int** arr = new int* [row];
	for(int i=0; i<cols; i++){
		arr[i] = new int[cols];
	}
	for(int i=0; i<row; i++){
		for(int j=0; j<cols; j++){
			cin>>arr[i][j];
		}
	}
	for(int i=0; i<row; i++){
		for(int j=0; j<cols; j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=0; i<cols; i++){
		delete [] arr[i];
	}
	delete [] arr;
	return 0;
}