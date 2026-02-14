# include <iostream>
# include <string>
using namespace std;
struct Item
{
char name[50];
int quantity;
float unitPrice;
};
struct Cart
{
Item * data;
int noOfItems;
int capacity;
};
Cart c;
void initializeCart( Cart & c, int capacity){
	c.capacity = capacity;
	c.noOfItems = 0;
	c.data =new Item[capacity];
}
bool addItem( Cart & c, const Item & it){
	c.data[c.noOfItems] = it;
    c.noOfItems++;
    return true;
}
bool removeItem( Cart & c, char * itemName, int count = 1 ){
		int rem =0;
	for(int i=0; i<c.noOfItems && rem<count; i++){
		if(strcmp(itemName,c.data[i].name)==0){
			for(int j=0; j<c.noOfItems; j++){
				c.data[j] = c.data[j+1];
			}
			c.noOfItems--;
			rem++;
			i--;
		}
	}
	if(rem>0){
		return true;
	}
	return false;
}
void checkOut( Cart & c){
	for(int i=0; i<c.noOfItems; i++){
		cout<<"ITEM NO.: "<<i+1<<endl;
		cout<<"Name: "<<c.data[i].name<<endl;
		cout<<"Quantity: "<<c.data[i].quantity<<endl;
		cout<<"Unit Price : "<<c.data[i].unitPrice<<endl;
	}
}
void resize(int s=5){
	int newCap = c.capacity+s;
	Item* newdata = new Item [newCap];
	for(int i=0; i<newCap; i++){
		newdata[i] = c.data[i];
	}
	delete c.data;
	c.data = newdata;
	c.capacity = newCap;
}
int main(){
	 Cart c;
    initializeCart(c, 2);

   Item b1 = {"milk", 2, 280};
   Item b2 = {"Crackers", 3 , 550};

    addItem(c, b1);
    addItem(c, b2); 

   checkOut(c);

    removeItem(c, (char*)"milk");

    cout << "After Removing: "<<endl;
    checkOut(c);

    delete[] c.data; 
    return 0;
}