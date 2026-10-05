#ifndef NODE_H
#define NODE_H

#include <ostream>

template <typename T> 
class Node {
    public:
        // miembros públicos
    T data;
	Node<T>* next;

	Node(T data, Node<T>* next=nullptr){
		this->data=data;
		this->next=next;
	}

	friend std::ostream& operator<<(std::ostream &out, const Node<T> &node){
		out<<node.data;
		return out;
	}
};

#endif
