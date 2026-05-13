# include <iostream>
# include <string>
using namespace std;
template <typename T>
T divide(T a, T b){
	return a/b;
}
template<typename T>
T multiply (T a, T b){
	return a*b;
}
int main() {
	int a = divide(4,2);
	cout<<a<<endl;
	a = multiply(2,4);
	cout<<a<<endl;
	return 0;
	   }
