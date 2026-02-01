# include <iostream>
# include <string>
using namespace std;
const int r = 3, c = 3;
void getTotal(int arr[r][c]){
	int sum =0;
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			sum +=arr[i][j];
		}
	}
	cout<<"sum is: "<< sum<<endl;
}
void getAverage(int arr[r][c]){
	int sum = 0;
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			sum+=arr[i][j];
		}
	}
	float avg = float(sum)/3/3;
	cout<<"Average is: "<< avg<<endl;
}
void getRowTotal(int arr[r][c], int s){

	
		int sum =0;
	for(int j=0; j<c; j++){
		sum+=arr[s][j];
	}	
	cout<<"sum of row "<<s<<": "<<sum<<endl;
	
}
void getColTotal(int arr[r][c], int s){
	
		int sum = 0;
		for(int j=0; j<r; j++){
			sum+=arr[s][j];
		}
		cout<<"sum of col "<<s<<": "<<sum<<endl;
	
}
void getHighestInRow(int arr[r][c], int s){
	
		int max = arr[s][0];
		for(int j=0; j<c; j++){
			if(arr[s][j]>max){
				max = arr[s][j];
			}
		}
		cout<<"max of row "<<s<<" : "<<max<<endl;
	
}
void getLowestInRow(int arr[r][c], int s){
	
		int min = arr[s][0];
		for(int j=0; j<c; j++){
			if(arr[s][j]<min){
				min = arr[s][j];
			}
		}
		cout<<"min of row "<<s<<" : "<<min<<endl;
}
int main(){
	int arr[r][c] = {{9,8,7},{6,5,4},{3,2,1}};
	getTotal(arr);
	getAverage(arr);
	getRowTotal(arr, 2);
	getColTotal(arr, 0);
	getHighestInRow(arr, 1);
	getLowestInRow(arr, 2);
	return 0;
}