//I got the source code from an old project that I found online and I finished it

#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

#ifndef nullptr
#define nullptr 0
#endif


#include "Double_node.h"


#ifndef nullptr
#define nullptr 0
#endif

template <typename Type>
class Double_list {
	private:
		Double_node<Type> *list_head;
		Double_node<Type> *list_tail;
		int list_size; 

	public:
		Double_list();
		Double_list( Double_list const & );
		~Double_list();

		// Accessors

		int size() const;
		bool empty() const;

		Type front() const;
		Type back() const;

		Double_node<Type> *head() const;
		Double_node<Type> *tail() const;

		int count( Type const & ) const;

		// Mutators

		void swap( Double_list & );
		Double_list &operator=( Double_list const & );

		void push_front( Type const & );
		void push_back( Type const & );

		Type pop_front();
		Type pop_back();

		int erase( Type const & );

	// Friends

	template <typename T>
	friend std::ostream &operator<<( std::ostream &, Double_list<T> const & );
};

template <typename Type>
Double_list<Type>::Double_list():
list_head( nullptr ),
list_tail( nullptr ),
list_size( 0 ) {
	// empty constructor
}

template <typename Type>
Double_list<Type>::Double_list( Double_list<Type> const &list ):
list_head( nullptr ),
list_tail( nullptr ),
list_size( 0 ) {
	Double_node<Type> *temp = list.head();
	while (temp != nullptr){
		push_back(temp->retrieve());
		temp = temp->next();
	}
}

template <typename Type>
Double_list<Type>::~Double_list() {
	
	Double_node<Type> *q, *p;
	q = p = head();
	cout << "inside destructor: " << endl;
	cout << *this << endl;
	while(q != nullptr){
		p = p->next();
		delete q;
		q = p;
	}
	list_size = 0;
	list_head = nullptr;
	list_tail = nullptr;
		
}

template <typename Type>
int Double_list<Type>::size() const {
	
	return list_size;
}

template <typename Type>
bool Double_list<Type>::empty() const {
	
	return (list_size == 0);
}

template <typename Type>
Type Double_list<Type>::front() const {
	if (!empty()){
		
		return list_head->retrieve();
		
	}
	return Type();
}

template <typename Type>
Type Double_list<Type>::back() const {
	if (!empty()){
		
		return list_tail->retrieve();
		
	}
	return Type();
}

template <typename Type>
Double_node<Type> *Double_list<Type>::head() const {
	
	return list_head;
}

template <typename Type>
Double_node<Type> *Double_list<Type>::tail() const {
	return list_tail;
}

template <typename Type>
int Double_list<Type>::count( Type const &obj ) const {
	
	int counter = 0;
	Double_node<Type> *temp = head();
	while (temp != nullptr){
		if (obj == temp->retrieve()){
			counter++;
		}
		temp = temp->next();
	}
	return counter;
}

template <typename Type>
void Double_list<Type>::swap( Double_list<Type> &list ) {
	std::swap( list_head, list.list_head );
	std::swap( list_tail, list.list_tail );
	std::swap( list_size, list.list_size );
	

}

template <typename Type>
Double_list<Type> &Double_list<Type>::operator=( Double_list<Type> const &rhs ) {
	Double_list<Type> copy( rhs );
	
	swap( copy );
	
	return *this;
}

template <typename Type>
void Double_list<Type>::push_front( Type const &obj ) {
	
	Double_node<Type> *node = new Double_node<Type>(obj);
	
	if (head() == nullptr){ //first case when list is empty
		list_head = node;
		list_tail = node;
		
	}
	else{ //when list has atleast one node already
		
		node->next_node = list_head;
		list_head->previous_node = node;
		list_head = node;
		
		
	}
	list_size++;
}

template <typename Type>
void Double_list<Type>::push_back( Type const &obj ) {
	
	Double_node<Type> *node = new Double_node<Type>(obj);
	
	if (head() == nullptr){ //first case when list is empty
		list_head = node;
		list_tail = node;
	}
	else{
		node->previous_node = list_tail;
		list_tail->next_node = node;
		list_tail = node;
	}
	list_size++;
}

template <typename Type>
Type Double_list<Type>::pop_front() {
	if (head()){
		Type e = list_head->retrieve();
		if (size() == 1){
			delete list_head;
			list_head = nullptr;
			list_tail = nullptr;
		}
		else{
			Double_node<Type> *temp = list_head;
			list_head = list_head->next_node ;
			list_head->previous_node = nullptr;
			delete temp;			
		}
		list_size--;
		return e;
	}
	return 0;
}

template <typename Type>
Type Double_list<Type>::pop_back() {
	if (head()){
		Type e = list_tail->retrieve();
		if (size() == 1){
			delete list_head;
			list_head = nullptr;
			list_tail = nullptr;
		}
		else{
			Double_node<Type> *temp = list_tail;
			list_tail = list_tail->previous_node ;
			list_tail->next_node = nullptr;
			delete temp;			
		}
		list_size--;
		return e;
	}
	return 0;
}

template <typename Type>
int Double_list<Type>::erase( Type const &obj ) {
	Double_node<Type> *temp = list_head;
	int count = 0;
	while (temp != nullptr){
		if (temp->retrieve() == obj){
			if (list_size == 1){ 
				delete list_head;
				list_head = list_tail = nullptr;
			}
			else if (temp == list_head){ 
				list_head = list_head->next_node;
				delete list_head->previous_node;
				list_head->previous_node = nullptr;
				temp = list_head;
			}
			else if (temp == list_tail){
				list_tail = list_tail->previous_node;
				delete list_tail;
				list_tail->next_node = nullptr;
				temp = list_tail;			
			}
			else{
				temp->previous_node->next_node = temp->next_node;
				temp->next_node->previous_node = temp->previous_node;
				temp = temp->next_node;
				delete temp->previous_node;
			}	
			list_size--;
			count++;
		}
		temp = temp->next_node;
	}
	return count;
}


template <typename T>
std::ostream &operator<<( std::ostream &out, Double_list<T> const &list ) {
	out << "head";

	for ( Double_node<T> *ptr = list.head(); ptr != nullptr; ptr = ptr->next() ) {
		out << "->" << ptr->retrieve();
	}

	out << "->0" << std::endl << "tail";

	for ( Double_node<T> *ptr = list.tail(); ptr != nullptr; ptr = ptr->previous() ) {
		out << "->" << ptr->retrieve();
	}

	out << "->0";

	return out;
}


#endif
