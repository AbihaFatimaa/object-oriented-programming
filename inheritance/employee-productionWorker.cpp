# include <iostream>
# include <string>
using namespace std;
class employee{
	private:
		string name;
		int number;
		string hiredate;
	public:
		employee(string n="", int no=0, string h=""){
			name=n;
			number = no;
			hiredate = h;
		}
		void setName(string n){
			name = n;
		}
		void setnumber(int no){
			number = no;
		}
		void sethiredate(string h){
			hiredate = h;
		}
		string getname(){
			return name;
		}
		int getno(){
			return number;
		}
		string gethirenumber(){
			return hiredate;
		}
};
class productionWorker:public employee{
	private:
		int shift;
		double payrate;
	public:
		productionWorker(string n, int no, string h, int s=0, double p=0.0 ):employee(n,no,h){
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
};
class shiftsupervisor:public employee{
	private:
		int salary;
		int bonus;
	public:
		shiftsupervisor(string n, int no, string h, int s=0, int b=0):employee(n,no,h){
			salary = s;
			bonus = b;
		}
		void setsalary(int s){
			salary = s;
		}
		void setbonus(int b){
			bonus = b;
		} 
		int getsalary(){
			return salary;
		}
		int getbonus(){
			return bonus;
		}
};
class teamleader:public productionWorker{
	private:
		int mbonus;
		int rthours;
		int pthours;
	public:
		teamleader(string n, int no, string h,int s, double p, int m=0, int r=0, int y=0):productionWorker(n,no,h,s,p){
			mbonus = m;
			rthours = r;
			pthours = y;
		}
		void setbonus(int b){
			mbonus = b;
		}
		int getbonus(){
			return mbonus;
		}
		void setrthours(int r){
			rthours = r;
		}
		int getrhours(){return rthours;
		}
		void setpthours(int r){
			pthours =r;
		}
		int getphours(){
			return rthours;
		}
};
int main() {
	productionWorker a("abc", 123, "12/1/25", 1,50.45);
	cout<<a.getname()<<endl<<a.getno()<<endl<<a.gethirenumber()<<endl<<a.getshift()<<endl<<a.getpay()<<endl;
	shiftsupervisor b("xyz", 12, "12/5/23", 1, 20);
	cout<<b.getname()<<endl<<b.getbonus()<<b.getsalary()<<endl;
	teamleader tl("Ahmed", 303, "2022-09-15",
                  2, 400.0, 1000, 40, 35);
    cout<<tl.getname()<<tl.gethirenumber()<<tl.getpay()<<tl.getphours()<<endl;
	return 0;
	   }
