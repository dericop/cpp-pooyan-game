#ifndef LIST_H
#define LIST_H value

#include "Node.hpp"

class List
{
	public:
		List();
		virtual ~List();

		string toString() const;

		void add(Arrow ar);
		bool remove(int id);
		void removeFirst();
		int size();
		void getElementAt(int pos, Arrow* ar);

	private:
		Node *head;
};

#endif