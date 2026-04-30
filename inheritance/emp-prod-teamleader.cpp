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
class teamleader:public productionWorker{
	private:
		double monthlybonus;
		int rthours;
		int athours;
	public:
		teamleader(char n[], int no, int s, double p, double m=0, int r=0, int y=0):productionWorker(n,no,s,p){
			monthlybonus = m;
			rthours = r;
			athours = y;
		}
		void setbonus(double b){
			monthlybonus = b;
		}
		int getbonus(){
			return monthlybonus;
		}
		void setrthours(int r){
			rthours = r;
		}
		int getrhours(){return rthours;
		}
		void setpthours(int r){
			athours =r;
		}
		int getahours(){
			return athours;
		}
		void display(){
			productionWorker::display();
			cout<<"monthly bonus: "<<monthlybonus<<endl;
			cout<<"required training hours: "<<rthours<<endl;
			cout<<"attended training hours: "<<athours<<endl;
		}
};
int main() {
	productionWorker a("abc", 123, 1,50.45);
	cout<<"production worker: "<<endl;
	a.display();
	teamleader tl("Ahmed", 303, 2, 400.0, 1000, 40, 35);
	cout<<"team leader: "<<endl;
	tl.display();
	return 0;
	   }
