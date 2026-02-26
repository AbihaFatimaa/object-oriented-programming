# include <iostream>
# include <string>
using namespace std;
class bank{
	private:
		string accountNo;
		int balance;
	public:
		bank(){
			accountNo = "";
			balance = 0;
		}
		bank(string an, int b){
			accountNo = an;
			balance = b;
		}
		void deposit(int amount){
			balance+=amount;
		}
		void withdraw(int amount){
			if(balance >=amount){
				balance -=amount;
			}
		}
		void getBalance(){
			cout<<"your balance is: "<<balance;
		}
		~bank(){};
};
int main(){
	bank b;
	bank c("2345f", 8000);
	b.deposit(2000);
	b.withdraw(1000);
	c.getBalance();
	b.getBalance();
	return 0;
}