# include <iostream>
# include <string>
using namespace std;
class Date{
	private:
		int day;
		int month;
		int year;
	public:
		void setDay(int d){
			day = d;
		}
		void setMonth(int m){
			month = m;
		}
		void setYear(int y){
			year = y;
		}
		int getDay()const{
			return day;
		}
		int getMonth()const{
			return month;
		}
		int getYear()const{
			return year;
		}
		void displayDate(){
			cout<<day<<'/'<<month<<'/'<<year<<endl;
		}
};
int main(){
	int day,month,year;
//date using array.
	Date d[5];
	for(int i=0; i<5; i++){
	cout<<"enter the day: ";
	cin>>day;
	cout<<"enter the month: ";
	cin>>month;
	cout<<"enter the year: ";
	cin>>year;
	d[i].setDay(day);
	d[i].setMonth(month);
	d[i].setYear(year);
	}
	for(int j=0; j<5; j++){
	cout<<"date is: "<<endl;
	d[j].displayDate();
    }
//date using dynamic meomory.
int size;
	cin>>size;
	Date* arr = new Date[size];
	for(int i=0; i<size; i++){
		cout<<"enter the day:"<<i+1<<" ";
	cin>>day;
	cout<<"enter the month:"<<i+1<<" ";
	cin>>month;
	cout<<"enter the year:"<<i+1<<" ";
	cin>>year;
	arr[i].setDay(day);
 	arr[i].setMonth(month);
	arr[i].setYear(year);
	}
	cout<<"all entered dates: "<<endl;
    for(int i=0; i<size; i++){
    	arr[i].displayDate();
    	
	}
	delete []arr;
	return 0;
	
}