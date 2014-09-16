#ifndef DOUBLE_NODE_H
#define DOUBLE_NODE_H

#ifndef nullptr
#define nullptr 0
#endif

//I got the source code from an old project that I found online and I finished it
template <typename Type>
class Double_list;


template <typename Type>
class Double_node {
	private:
		Type       element;
		Double_node *previous_node;
		Double_node *next_node;

	public:
		Double_node( Type const & = Type(), Double_node * = nullptr, Double_node * = nullptr );

		Type retrieve() const;
		Double_node *previous() const;
		Double_node *next() const;
		void set_previous(Double_node<Type> *p);
		void set_next(Double_node<Type> *n);
		
		
		friend class Double_list<Type>;
//		friend class Cyclic_double_list<Type>;
//		friend class Double_sentinel_list<Type>;
//		friend class Cyclic_double_sentinel_list<Type>;

	
};

template <typename Type>
Double_node<Type>::Double_node( Type const &e, Double_node<Type> *p, Double_node<Type> *n ):
element( e ),
previous_node( p ),
next_node( n ) {
	// empty constructor
}


template <typename Type>
Type Double_node<Type>::retrieve() const {
	return element;
}

template <typename Type>
Double_node<Type> *Double_node<Type>::previous() const {
	return previous_node;
}

template <typename Type>
Double_node<Type> *Double_node<Type>::next() const {
	return next_node;
}

template <typename Type>
void Double_node<Type>::set_previous(Double_node<Type> *p){
	
	previous_node = p; 
	
}

template <typename Type>
void Double_node<Type>::set_next(Double_node<Type> *n){
	
	next_node = n;
	
}

#endif







