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
			cout << "Y: " << y << '\n';
		}
};
int main(){
	A *a = new B(3, 5);
	a -> show();
	B *b = dynamic_cast<B*> (a);
	if (b)
		b -> test();
	else
		cout << "Object is different\n";
	return 0;
}