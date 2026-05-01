# include <iostream>
# include <string>
using namespace std;
class bankAccount{
	protected:
		string title;
		int accNo;
		int balance;
	public:
		bankAccount(string t="", int a=0, int b=0){
			title = t;
			accNo = a;
			balance = b;
		}
		virtual void deposit(int amount){
			balance +=amount;
		}
		virtual void withdraw(int amount){
			if(balance>=amount){
				balance -=amount;
			}
		}
};
class savingAccount:public bankAccount{
	private:
		int interestRate;
	public:
		savingAccount(string s, int a, int b, int i=0):bankAccount(s,a,b){
			interestRate = i;
		}
		int calculateInterest(){
			return (interestRate*balance)/100;
		}
};
class checkingAccount:public bankAccount{
	private:
		int fee;
	public:
		checkingAccount(string s, int a, int b, int f=0):bankAccount(s,a,b){
			fee = f;
		}
		void deposit(int amount)override{
			balance +=amount;
			balance -= fee;
			cout<<"balance: "<<balance<<endl;
		}
		void withdraw(int amount){
			if(balance >amount){
				balance -= amount;
				balance -=fee;
			}
			cout<<"balance: "<<balance<<endl;
		}
		
};
int main() {
	checkingAccount ac("abc", 123, 2000, 40);
	ac.deposit(500);
	ac.withdraw(500);
	savingAccount sa("abc", 123, 3000, 40);
	cout<<"interest: "<<sa.calculateInterest();
	
	return 0;
	   }
