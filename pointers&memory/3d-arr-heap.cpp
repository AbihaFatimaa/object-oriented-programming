# include <iostream>
# include <string>
using namespace std;
int main(){
	int rows = 3;
	int cols = 2;
	int depth = 3;
	int *** arr = new int**[depth];
	for(int i=0; i<depth; i++){
		arr[i] = new int*[rows];
		for(int j=0; j<rows; j++){
			arr[i][j] = new int[cols];
		}
	}
	for(int i=0; i<depth; i++){
		for(int j=0; j<rows; j++){
			for(int k=0; k<cols; k++){
				cin>>arr[i][j][k];
			}
		}
	}
	for(int i=0; i<depth; i++){
		for(int j=0; j<rows; j++){
			for(int k=0; k<cols; k++){
				cout<<arr[i][j][k]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	for(int i=0; i<depth; i++){
		for(int j=0; j<rows; j++){
			delete []arr[i][j];
		}
		delete []arr[i];
	}
	delete[] arr;
	return 0;
}