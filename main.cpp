#include <iostream>
#include "swap.h.cpp"
#include "add.h.cpp"
using namespace std;
int main(){
   int a= 1, b = 5;
   cout << a << " this is a " << b << " this is b ";
   swap(&a,&b);
   cout << a << "\nthis is swapped a " << b<<" This is swapped b ";
   cout << "this is a added b" << add(a,b);
   return 0;
}
int add(int a,int b)
{
	return a+b;
}
void swap(int* a,int* b)
{
int temp =*a;
*a = *b;
*b = temp;
}
