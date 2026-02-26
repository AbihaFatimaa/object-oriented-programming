//bsdsf25m053

# include<iostream>
# include <string>
using namespace std;
int** createPascalTriangle(int n){
	int** arr = new int*[n];
	for(int i=0; i<n; i++){
		arr[i] = new int [i+1];
		arr[i][0] = 1;
		arr[i][i] = 1;
		for(int j=1; j<i; j++){
			arr[i][j] = arr[i-1][j]+arr[i-1][j-1];
		}
	}
	return arr;
}
void displayPascalTriangle (int** pt, int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<=i; j++){
			cout<<pt[i][j]<< " ";
		}
		cout<<endl;
	}
}
void deallocatepascalTriangle (int** pt, int n){
	for(int i=0; i<n; i++){
		delete[] pt[i];
	}
	delete[] pt;
}
int main(){
	int** arr;
	int n=6;
	arr = createPascalTriangle(n);
	displayPascalTriangle(arr, n);
	deallocatepascalTriangle(arr, n);
	return 0;
}