# include <iostream>
# include <string>
# include <cstring>
using namespace std;
class employee{
	private:
		 char name[50];
		int number;
	public:
		employee(char n[]="", int no=0){
			strcpy(name, n);
			number = no;
		}
		void setName(char n[]=""){
			strcpy(name, n);
		}
		void setnumber(int no){
			number = no;
		}
		char* getname(){
			return name;
		}
		int getno(){
			return number;
		}
		void display(){
			cout<<"employee name: "<<name<<endl;
			cout<<"Employee number: "<<number<<endl;
		}
};
class productionWorker:public employee{
	private:
		int shift;
		double payrate;
	public:
		productionWorker(char n[], int no, int s=0, double p=0.0 ):employee(n,no){
			shift = s;
			payrate=p;
		}
		void setshift(int s){
			shift = s;
		}
		int getshift(){
			return shift;
		}
		void setpay(double p){
			payrate = p;
		}
		double getpay(){
			return payrate;
		}
		void display(){
			employee::display();
			cout<<"Shift: "<<shift<<endl;
			cout<<"hourly pay rate: "<<payrate<<endl;
		}
};
int main(){
	productionWorker p("iqbal", 123, 1, 50.45);
	p.display();
}