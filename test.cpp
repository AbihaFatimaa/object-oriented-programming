#include <iostream>

using namespace std;

class A{
		int x;
	public:
		A(int x = 10){	this -> x = x;		}
		virtual void show(){ cout << "X: " << x << '\n';}
};
class B:public A{
		int y;
	public:
		B(int x, int y):A(x){	this -> y = y;		}
		void show(){ 
			A::show();
			cout << "Y: " << y << '\n';
		}
		void test(){
			cout << "Test Funciton B Y: " << y << '\n';
		}
};
class C:public A{
		int y;
	public:
		C(int x, int y):A(x){	this -> y = y;		}
		void show(){ 
			A::show();
			cout << "Y: " << y << '\n';
		}
		void test(){
			cout << "Test Funciton C Y: " << y << '\n';
		}
};

int main(){
	A *a = new C(3, 5);
	a -> show();
	B *b = (B*) a;
	b -> test();
	return 0;
}