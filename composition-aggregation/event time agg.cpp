# include <iostream>
# include <string>
using namespace std;
class time{
	private:
		int hours;
		int minutes;
	public:
		time(int a, int b){
			hours = a;
			minutes = b;
		}
		 void display(){
		 	cout<<hours<<":"<<minutes<<endl;
		 }
		 void normalizetime(){
		 	if (minutes>60){
		 		minutes = minutes-60;
		 		hours++;
			 }
		 }
		 int tominutes(){
		 	return hours*60+minutes;
		 }
};
class event{
	private:
		time *start;
		time *end;
		string name;
	public:
		event(time *t1, time *t2 ,string e):start(t1),end(t2),name(e){
		}
		int duration(){
		 return end->tominutes()-start->tominutes();
		}
		void display() {
        cout << "Event: " << name << endl;
        cout << "Start: ";
        start->display();
        cout << "End: ";
        end->display();
        cout << "Duration: " << duration() << " minutes\n";
    }
};
int main() {
	time t1(1,20);
	time t2(4,30);
	event abc(&t1,&t2,"day");
	abc.duration();
	abc.display();
	return 0;
	   }
