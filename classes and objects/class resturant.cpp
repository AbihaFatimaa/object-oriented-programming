#include <iostream>

using namespace std;

class Restaurant {
private:
    // Enter code here
    string name;
    int capacity;
    float average_price;
    int waiters;
public:
    // Enter constructors
    Restaurant(string name="", int capacity=0, float average_price=0, int waiters=0){
        this->name=name;
        this->capacity=capacity;
        this->average_price=average_price;
        this->waiters=waiters;
    }
    Restaurant(const Restaurant &c){
        name=c.name;
        capacity=c.capacity;
        average_price=c.average_price;
        waiters=c.waiters;
    }
    // Enter methods
    void printInfo(){
        cout<<name<<" has a capacity of "<<capacity<<" and "<<waiters<<" waiters"<<endl;
    }
    void updateWaiters(int new_waiters){
        waiters=new_waiters;
    }
    ~Restaurant(){};
};
int main(){
	Restaurant r;
	Restaurant r2(r);
	r.printInfo();
	r.updateWaiters(23);
	r.printInfo();
	return 0;
	
}