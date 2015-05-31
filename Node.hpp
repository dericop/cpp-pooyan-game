#ifndef NODE_H
#define NODE_H value

#include "Arrow.hpp"

class Node
{
	public:
		Node(Arrow *ar, Node *sig);
		virtual ~Node();

		void setSig(Node *sig);
		void setData(Arrow *ar);
		Node *getSig();
		Arrow *getData();

	private:
		Arrow *data;
		Node *sig;
};

#endif