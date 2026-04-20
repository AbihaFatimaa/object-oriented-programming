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
		time start;
		time end;
		string name;
	public:
		event(int a, int b, int c, int d, string e):start(a,b),end(c,d),name(e){
		}
		int duration(){
		 return end.tominutes()-start.tominutes();
		}
		void display() {
        cout << "Event: " << name << endl;
        cout << "Start: ";
        start.display();
        cout << "End: ";
        end.display();
        cout << "Duration: " << duration() << " minutes\n";
    }
};
int main() {
	event abc(1,20,3,70,"day");
	abc.duration();
	abc.display();
	return 0;
	   }
