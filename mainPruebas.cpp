#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include "Arrow.hpp"
#include "Balloon.hpp"
#include "Character.hpp"
#include "Node.hpp"
#include "List.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
	List *l = new List();
	for(int i =0;i<5; ++i){
		cout << i << endl;
	}
	for (int i =0;i<5; ++i){
		Arrow *a=new Arrow(i,0,0);
		l->add(a);
	}

	cout << l->toString() << endl;

	cout << "eliminar 2" << endl;
	cout << l->remove(2) << endl;
	cout << "eliminar 4" << endl;
	cout << l->remove(4) << endl;
	
	cout << l->toString() << endl;

	cout << "eliminar 0" << endl;
	cout << l->remove(0) << endl;
	
	cout << l->toString() << endl;

	cout << "eliminar 0" << endl;
	cout << l->remove(0) << endl;

	cout << l->toString() << endl;

	List *l2=NULL;
	l2 = l->copy();
	if (l2==NULL){
		cout << "null" << endl;
	}
	cout << l2->toString() << endl;

	Arrow *ar=NULL; 
	cout << "*ar" << endl;
	ar = l->getElementAt(1);
	if(ar!=NULL){
		cout << "getElementAt" << endl;
		cout << ar->toString() << endl;
		ar->setId(6);
		cout << ar->toString() << endl;
	
		cout << l->toString() << endl;
	}
	else{
		cout << "ar==NULL" << endl;
	}
	cout << l2->toString() << endl;
	delete l;
	delete l2;
	return 0;
}