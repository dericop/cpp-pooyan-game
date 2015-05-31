#ifndef LIST_H
#define LIST_H value

#include "Node.hpp"

class List
{
	public:
		List();
		virtual ~List();

		string toString() const;

		void add(Arrow *ar);
		bool remove(int id);
		void removeFirst();
		int size();
		Arrow *getElementAt(int pos);
		List *copy();
	private:
		Node *head;
};

#endif