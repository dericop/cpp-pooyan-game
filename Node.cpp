#include "Node.hpp"

Node::Node(Arrow ar, Node *sig){
	Node::data = ar;
	Node::sig = sig;
}

Node::~Node(){
	//delete Node::data;
}

void Node::setSig(Node *sig){
	Node::sig = sig;
}

void Node::setData(Arrow ar){
	Node::data = ar;
}

Node *Node::getSig(){
	return Node::sig;
}

Arrow Node::getData(){
	return Node::data;
}
