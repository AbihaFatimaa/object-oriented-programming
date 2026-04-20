#include <iostream>
#include "course.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv){
	course a;
	course b("pf", "sir idrees", "C++");
	b.print();
	a.print();
	return 0;
}