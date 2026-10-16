#ifndef LIST_LINKED_H
#define LIST_LINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
		Node<T>* first;
		int n;
        

    public:
		ListLinked(){
			first=nullptr;
			n=0;
		}

		~ListLinked(){
			for(int i =0;i<n;i++){
				Node<T>* aux= first->next;
				delete first;
				first=aux;
			}
			n=0;
		}

		T operator[](int pos){
			if(pos<0 || pos>=n){
				throw std::out_of_range("Posición no válida");
			}
			return get(pos);

		}

		friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
			if(list.n==0){
				out<<"List => []";
			} else {
				out<<"List => [\n";
				Node<T>* aux =list.first;
				while (aux != nullptr){
					out<<"  "<< aux->data << "\n";
					aux = aux->next;
				}
				out<<"]";
			}
			return out;
		}

		void insert(int pos, T e) override{
			if(pos<0 || pos>n){
				throw std::out_of_range("No se puede insetar porque esta fuera de rango");
			}
			if(pos==0){
				first= new Node<T>(e,first);

			}else{
				Node<T>* prev=nullptr;
				Node<T>* aux=first;
				for(int i=0;i<pos;i++){
					prev=aux;
					aux=aux->next;
				}
			prev->next=new Node<T>(e,aux);
			}
			n++;
		}

		void append(T e) override {
			insert(n,e);
		}

		void prepend(T e) override {
			insert(0,e);
		}

		T remove(int pos) override {
			if(pos<0|| pos>=n){
				throw std::out_of_range("Posición Inválida");
			}
			Node<T>* eliminar;
			T elemento_eliminado;
			if(pos==0){
				eliminar=first;
				first=first->next;
			} else {
				Node<T>* aux = first;
				for(int i=0;i<pos - 1;i++){
					aux = aux->next;
				}
				eliminar = aux->next;
				aux->next= eliminar->next;
			}
			elemento_eliminado= eliminar->data;
			delete eliminar;
			n--;
			return elemento_eliminado;
		}

		T get(int pos) override {
			if(pos<0 || pos >=n){
				throw std::out_of_range("Posición Invalida");
			}
			Node<T>* aux=first;
			for(int i=0;i<pos;i++){
				aux=aux->next;
			}
			return aux->data;
			}

		int search(T e) override {
			Node<T>*aux = first;
			int posicion= 0;
			while (aux !=nullptr){
				if (aux->data==e){
					return posicion;
				}
				aux=aux->next;
				posicion++;
			}
			return -1;
		}

		bool empty() override {
			return n==0;
		}

		int size() override{
			return n;
		}
        // ...
};

#endif //LIST_LINKED_H
