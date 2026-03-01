# include <cstring>
# include <iostream>
# include <string>
# include <iomanip>
using namespace std;
class SaleItem{
	private:
		int id;
		char name[41];
		int quantity;
		double price;
	public:
		void setId(int i){
			id = i;
		}
		void setName(char n[41]){
		strcpy(name,n);
		}
		void setQuantity(int q){
			quantity = q;
		}
		void setprice(double p){
			price = p;
		}
		int getId()const{
			return id;
		}
		const char* getName()const{
			return name;
		}
		int getQuantity()const{
			return quantity;
		}
		double getprice()const{
			return price;
		}
		void incrementQuantity(int q){
			quantity+=q;
		}
		void decrementQuantity(int d){
			quantity -= d;
		}
		void displayInformation(){
			 cout << setw(8)<< left<< id
             << setw(15) << left  << name
             << setw(12) << left  << quantity 
             << setw(10) << right << price<< endl;
		}
};
int main(){
	int size;
	cout<<"how many saleItems you want to create: ";
	cin>>size;
	SaleItem* item = new SaleItem[size];
	for(int i=0; i<size; i++){
		int id, quantity;
		char name[41];
		double price;
		cout<<"enter the details of saleItem # "<<i+1<<": ";
  	cin>>id>>name>>price>>quantity;
  		item[i].setId(id);
		item[i].setName(name);
		item[i].setprice(price);
		item[i].setQuantity(quantity);
	}
	int choice;
	do{
	cout<<setw(12)<<right<<"MENU"<<endl;
	for(int i=0; i<size;i++){
		item[i].displayInformation();
	}
	cout<<"enter the id of item you want to buy(-1 to exit): ";
	cin>>choice;
	if(choice == -1){
		cout<<"Bye Bye!!";
		break;
	}
	bool flag = false;
	for(int i=0; i<size; i++){
		if(item[i].getId()==choice){
			flag = true;
			int qty;
			cout<<"enter the quantity to buy: ";
			cin>>qty;
			if(qty<0){
				cout<<"invalid quantity";
			}
			else if(qty>item[i].getQuantity()){
				cout<<"not enough quantity";
			}
			else{
				double total = qty*item[i].getprice();
				item[i].decrementQuantity(qty);
				cout << setw(8)  << left  << "ID"
             << setw(15) << left  << "Name"
             << setw(12) << left  << "Quantity"
             << setw(10) << right << " Unit Price" << endl;
             cout<<"------------------------------------------------------------"<<endl;
             item[i].displayInformation();
             cout<<setw(20)<<right<<"Total amount: "<<total<<endl;
			}
		}
	}
	if(!flag){
		cout<<"invalid item id";
	}
	 cout << "Press any key then Enter to return to menu...";
        char temp[10];
        cin >> temp;

	}	while(true);
	delete []item;
	return 0 ;
}

