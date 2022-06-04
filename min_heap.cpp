#include<iostream>
#include<cmath>
#include <initializer_list>


template<typename T>
void swap(T &x, T &y);


template<typename T>
class MinHeap
{
	T *array_heap; 
	int capacity =  20;
	size_t heap_size = 0; 
public:


//constructor
    MinHeap();  //default constructor
    
    MinHeap(int capacity); //parameterized constructor
    
    MinHeap(const MinHeap&); //Copy constructor
    
    MinHeap(MinHeap&&); //Move constructor
    
    MinHeap(std::initializer_list <T> obj); //parameterized constructor + std::initalizer_list
   
   ~MinHeap()
   {
      
      std::cout << "delete constructor !"<<std::endl;
   }
   
  
  ///operator  
   MinHeap& operator=(const MinHeap<T>& heap); //copy operator
    
   MinHeap& operator=(const MinHeap<T>&& heap); // move operator
     
   bool  operator==( MinHeap<T> equal){
       
       if(heap_size != equal.heap_size || capacity != equal.capacity){
           return false;
       }
           for(int i = 0; i < heap_size;i++){
           if(array_heap[i] != equal.array_heap[i]  )
            return false;
           }
          return true;
           
   }
   //equal operator
   
   
   bool  operator!=( MinHeap<T> equal){
       if(heap_size != equal.heap_size && capacity  != equal.capacity){
              return true;
          }
          for(int i = 0 ; i < heap_size; i++){
              if(array_heap[i] != equal.array_heap[i])
              return true;
          }
          
              return false;
          
   };  //noequal operator
   

    MinHeap operator+=( MinHeap<T>& sumequal){
    MinHeap <T> tmp(20);
    for(int i = 0;i < heap_size;++i){
     array_heap[i] += sumequal.array_heap[i];
    }
    capacity += sumequal.capacity;
    std::cout << " sum "<<std::endl;
    return tmp;
    } //sumequal operator
    
  MinHeap operator+( MinHeap<T>& sum){
    MinHeap <T> tmp(20);
    for(int i = 0;i < heap_size;++i){
    tmp.array_heap[i] = array_heap[i] + sum.array_heap[i];
    }
   // tmp.heap_size = heap_size;
    tmp.capacity = capacity + sum.capacity;
    std::cout << " sum "<<std::endl;
    return tmp;
   }; // sum operator
    
    friend std::ostream& operator<<(std::ostream& out,  MinHeap<T>& obj){
          out << *obj.array_heap << " ostream operator " << std::endl;
      return out;
    }; //cout  << operator

	void MinHeapify(int);

	int parent(int i) { return (i-1)/2; }

	int left(int i) { return (2*i + 1); }

	int right(int i) { return (2*i + 2); }

	void extract_max_element();
	
	T parent_heap();
	
	int height();
	
	void left_heap();
	
	void right_heap();
	
	void delete_element(T value_delete);

	void insert(T value);
	
	int linear_search(T value_search);
	
	void print();
};
   template<typename T>
  MinHeap<T>&::MinHeap<T>::operator=(const MinHeap<T>&& heap_move){
      array_heap = heap_move.array_heap;
      heap_size = heap_move.heap_size;
      capacity =  heap_move.capacity;
      std::cout<< "Move assignment "<<std::endl;
   
      
      return *this;
  };
template <typename T>
MinHeap<T>::MinHeap() : heap_size(heap_size)
{
    
    array_heap ={}; 
    capacity ={1};
	heap_size={}; 
}
template<typename T>
 MinHeap<T>&::MinHeap<T>::operator= (const MinHeap<T>& heap_copy){
    heap_size = heap_copy.heap_size;
     array_heap = heap_copy.array_heap;
     capacity  = heap_copy.capacity;
     std::cout << "copy assignment " <<std::endl;
     return *this;
 };


template<typename T>
MinHeap<T>::MinHeap(MinHeap&& a)
	{   heap_size = a.heap_size;
	    a.heap_size = {};
	    array_heap = a.array_heap;
		a.array_heap = nullptr;
  
    std::cout << "move  constructor !"<<std::endl;
}
    

template <typename T>
MinHeap<T>::MinHeap(const MinHeap& heap1){
   
        heap_size = heap1.heap_size;
        capacity = heap1.capacity;
        array_heap = heap1.array_heap;
        std::cout << "Copy constructor"<<std::endl;
    
}

   template <typename T>
   MinHeap<T>::MinHeap( std::initializer_list<T> obj){
       for(auto it : obj){
          insert(it);
        
           }
       std::cout << "Initializer_list<int>Constructor"<<std::endl;
   }
    


template <typename T>
void MinHeap<T>::right_heap(){
      for(int i =  0; i < (MinHeap::heap_size/2)-1;++i){
        std::cout << 
        " right is  "<<array_heap[(2*i)+2] 
        <<std::endl;
    }
}
template <typename T>
void MinHeap<T>::left_heap(){
    for( int i =  0; i < MinHeap::heap_size/2;++i){
        std::cout << 
        " left is  "<<array_heap[(2*i)+1] 
        <<std::endl;
    }
}

template <typename T>
 int MinHeap<T>::height(){
    return (log2(MinHeap::heap_size + 1)+1);
}

template <typename T>
T MinHeap<T>::parent_heap(){
    return MinHeap::array_heap[0];
}


template <typename T>
int MinHeap<T>::linear_search(T value_search){
      for (int i = 0; i < MinHeap::heap_size; i++) {
      if (MinHeap::array_heap[i] == value_search) {
      
        return i;
      }
    }
    return -1;
}


template <typename T>
void MinHeap<T>::extract_max_element(){
    T max = array_heap[0];
    for(int i = 0 ; i < MinHeap::heap_size;i++){
        if(max <  MinHeap::array_heap[i]){
            max =  MinHeap::array_heap[i];
           
        }
    }
    std::cout<< "this is extract_max_element = " << max << std::endl;
}

template <typename T>
MinHeap<T>::MinHeap(int cap)
{    array_heap= new T[cap];
	
	capacity = cap;
	heap_size = 0;
}

template <typename T>
void MinHeap<T>::insert(T value)
{

    
	heap_size++;
	int i = heap_size - 1;
	array_heap[i] = value;


	while ( i != 0 && array_heap[parent(i)] > array_heap[i])
	{
	swap(array_heap[i], array_heap[parent(i)]);
	i = parent(i);
	}
}


template <typename T>
void MinHeap<T>::delete_element(T value_delete)
{
      for (int i = 0; i < MinHeap::heap_size; i++) {
      if (MinHeap::array_heap[i] == value_delete) {
           swap(MinHeap::array_heap[i] ,array_heap[MinHeap::heap_size-1]);
          MinHeap::heap_size--;
          MinHeapify(i);
        return;
      }
    }
    std::cout << "Value NOT Found!";
}


template <typename T>
void MinHeap<T>::MinHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && array_heap[l] < array_heap[i])
		smallest = l;
	if (r < heap_size && array_heap[r] < array_heap[smallest])
		smallest = r;
	if (smallest != i)
	{
		swap(array_heap[i], array_heap[smallest]);
		MinHeapify(smallest);
	}
}

template <typename T>
void MinHeap<T>::print(){
    for(int i = 0;i < heap_size;++i){
        std::cout << array_heap[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void swap(T &x, T &y)
{
	T temp = x;
	x = y;
	y = temp;
}  


int main()
{
    
	MinHeap<int>heap(20);
MinHeap<int>hp= {2,4,8,44,8,77,2};
// MinHeap<std::string>hp= {"FSAD","WEASDAS"};

   //heap.insert(1);
//	hp.insert("EWQSEADSEWDQSA");
		hp.print();

	heap.insert(11);
	heap.insert(2);
	heap.insert(66);
	heap.insert(4);
    heap.print();
	heap.insert(2);
	heap.insert(6);
	heap.insert(81);
    heap.insert(27);
	heap.insert(8);
	std::cout<<heap.linear_search(8)<<std::endl;
	//MinHeap<int> hs(20);
	//hs = heap;
//	std::cout << hs;
//	MinHeap<int>heap1 = std::move(heap); 
/*	MinHeap<int>heap2(20); 
//	MinHeap<int>heap3(30);
	heap2.insert(11);
	heap2.insert(3);
	heap2.insert(71);
	heap2.insert(2);
	heap2.insert(61);
	heap2.insert(4);*/
	//heap2.insert(8);
	//heap = std::move(heap2);
//	heap3.insert(14);
//	heap2 = heap;
	
//	heap2 = heap;
	heap.print();
	//std::cout << heap2;
//	heap3.print();
 /*   MinHeap<int> heap4(40);
	
	if(heap2 == heap){
	    std::cout << " equal "<<std::endl;
	}else{
	    std::cout << " no equal "<<std::endl;
	}
	
	if(heap2 != heap){
	    std::cout << " true "<<std::endl;
	}else{
	    std::cout << " false "<<std::endl;
	}*/
	//std::cout << MinHeap<int>::heap.capacity <<" capacity " << MinHeap<int>::heap.heap_size << " size "<<std::endl;
//	heap1 = std::move(heap);
//	heap1.insert(2);
 // MinHeap<int> hp{1,2};
/*	heap.insert("C");
	heap.insert("B");
	heap.insert("E");
	heap.insert("A");
	heap.insert("H");
	heap.insert("T");
	heap.insert("W");
	heap.insert("g");
	heap.insert("N");*/
/*	heap.insert("Anna");
	heap.insert("Ando");
	heap.insert("Aro");
	heap.insert("Gago");
	heap.insert("valod");
	heap.insert("Tiko");
	heap.insert("Jane");
	heap.insert("dod");
	heap.insert("Arman");
	heap.print();
	heap.linear_search("dod");
        heap.delete_element("Arman");*/
	
 /*	
    heap.insert(27);
	heap.insert(8);
	heap.insert(14);/*
	heap.print();
	heap.delete_element(7);
	heap.delete_element(41);
//	heap.delete_element(71);
	heap.delete_element(2);
	heap.delete_element(14);
	std::cout <<std::endl;
	heap.print();
	heap.insert(33);
  	//heap.insert(7);
	heap.insert(10);
	heap.print();
	heap.insert(3);
	heap.linear_search(4);
//	heap.delete_element(24);
    heap.print();
	heap.delete_element(3);
	heap.insert(31);
	heap.insert(30);
	heap.insert(75);
	heap.insert(23);
	heap.insert(47);
	heap.insert(41);
	heap.insert(27);
	heap.insert(67);
	heap.insert(81);
	heap.insert(77);
	heap.insert(11);
	heap.print();*/
    heap.extract_max_element();
  /*  std::cout<<"this is parent_heap " << heap.parent_heap()<<std::endl;
    std::cout <<"this is  height "<< heap.height()<<std::endl;
    heap.left_heap();
    std::cout <<std::endl;
    heap.right_heap();*/
  //  heap3.print();
    //heap4 = heap2 + heap;
   // heap.print();
    //heap2.print();
    //heap+= heap2;
   //std::cout << heap.height()<<" this is height "<<std::endl;
  // heap.print();
   
   
  // heap1.print();
	return 0;	

}


