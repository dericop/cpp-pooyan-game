#include "List.hpp"
#include <iostream>
List::List(){
	List::head = NULL;
}

List::~List(){
	Node *aux = List::head;
	while(aux!=NULL){
		List::head = List::head->getSig();
		delete aux;
		aux = List::head;
	}
}

string List::toString() const{
	Node *aux = List::head;
	stringstream out;
	
	while(aux!=NULL){
		out << "Arrow " << aux->getData().getId() << aux << "\n";
		aux = aux->getSig();
	}

	return out.str();
}

void List::add(Arrow ar){
	if(List::head==NULL){
		List::head = new Node(ar, NULL);
	}
	else{
		Node *aux = List::head;
		
		while(aux->getSig()!=NULL){
			aux=aux->getSig();
		}

		aux->setSig(new Node(ar, NULL));
	}
}

bool List::remove(int id){
	Node *aux=List::head;
	if(aux->getData().getId()==id){
		cout << "cabeza" << endl;
		List::head=List::head->getSig();
		delete aux;
		return true;
	}

	cout << "while" << endl;
	while(aux->getSig()!=NULL){
		cout << aux << endl;
		if (aux->getSig()->getData().getId()==id){
			cout << "dir a borrar " << aux << endl;
			Node *temp=aux->getSig();
			aux->setSig(temp->getSig());
			delete temp;
			return true;
		}
		cout << "aux->sig" << aux->getSig() << endl;
		aux=aux->getSig();
	}

	return false;
}

void List::removeFirst(){
	if(List::head != NULL){
		Node *aux=List::head;
		List::head=List::head->getSig();
		delete aux;
	}
}

int List::size(){
	int i = 0;
	Node *aux = List::head;

	while(aux!=NULL){
		i++;
		aux=aux->getSig();
	}

	return i;
}

void List::getElementAt(int pos, Arrow* ar){
	ar=NULL;
	if (pos>=0 && pos<List::size()){
		Node *aux=List::head;

		for(int i=0; i<pos; ++i){
			aux=aux->getSig();
		}
		*ar = aux->getData();
	}
}
