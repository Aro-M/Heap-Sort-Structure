
#include<iostream>
#include<cmath>
#include <initializer_list>


template<typename T>
void swap(T &x, T &y);


template<typename T>
class MaxHeap
{
	T *array_heap; 
	int capacity =  20;
	size_t heap_size = 0; 
public:


//constructor
    MaxHeap();  //default constructor
    
    MaxHeap(int capacity); //parameterized constructor
    
    MaxHeap(const MaxHeap&); //Copy constructor
    
    MaxHeap(MaxHeap&&); //Move constructor
    
    MaxHeap(std::initializer_list <T> obj); //parameterized constructor + std::initalizer_list
   
   ~MaxHeap()
   {
      
      std::cout << "delete constructor !"<<std::endl;
   }
   
  
  ///operator  
   MaxHeap& operator=(const MaxHeap<T>& heap); //copy operator
    
   MaxHeap& operator=(const MaxHeap<T>&& heap); // move operator
     
   bool  operator==( MaxHeap<T> equal){
       
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
   
   
   bool  operator!=( MaxHeap<T> equal){
       if(heap_size != equal.heap_size && capacity  != equal.capacity){
              return true;
          }
          for(int i = 0 ; i < heap_size; i++){
              if(array_heap[i] != equal.array_heap[i])
              return true;
          }
          
              return false;
          
   };  //noequal operator
   

    MaxHeap operator+=( MaxHeap<T>& sumequal){
    MaxHeap <T> tmp(20);
    for(int i = 0;i < heap_size;++i){
     array_heap[i] += sumequal.array_heap[i];
    }
    capacity += sumequal.capacity;
    std::cout << " sum "<<std::endl;
    return tmp;
    } //sumequal operator
    
  MaxHeap operator+( MaxHeap<T>& sum){
    MaxHeap <T> tmp(20);
    for(int i = 0;i < heap_size;++i){
    tmp.array_heap[i] = array_heap[i] + sum.array_heap[i];
    }
   // tmp.heap_size = heap_size;
    tmp.capacity = capacity + sum.capacity;
    std::cout << " sum "<<std::endl;
    return tmp;
   }; // sum operator
    
    friend std::ostream& operator<<(std::ostream& out,  MaxHeap<T>& obj){
          out << *obj.array_heap << " ostream operator " << std::endl;
      return out;
    }; //cout  << operator

	void MaxHeapify(int);

	int parent(int i) { return (i-1)/2; }

	int left(int i) { return (2*i + 1); }

	int right(int i) { return (2*i + 2); }

	void extract_min_element();
	
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
  MaxHeap<T>&::MaxHeap<T>::operator=(const MaxHeap<T>&& heap_move){
      array_heap = heap_move.array_heap;
      heap_size = heap_move.heap_size;
      capacity =  heap_move.capacity;
      std::cout<< "Move assignment "<<std::endl;
   
      
      return *this;
  };
template <typename T>
MaxHeap<T>::MaxHeap() : heap_size(heap_size)
{
    
    array_heap ={}; 
    capacity ={1};
	heap_size={}; 
}
template<typename T>
 MaxHeap<T>&::MaxHeap<T>::operator= (const MaxHeap<T>& heap_copy){
    heap_size = heap_copy.heap_size;
     array_heap = heap_copy.array_heap;
     capacity  = heap_copy.capacity;
     std::cout << "copy assignment " <<std::endl;
     return *this;
 };


template<typename T>
MaxHeap<T>::MaxHeap(MaxHeap&& a)
	{   heap_size = a.heap_size;
	    a.heap_size = {};
	    array_heap = a.array_heap;
		a.array_heap = nullptr;
  
    std::cout << "move  constructor !"<<std::endl;
}
    

template <typename T>
MaxHeap<T>::MaxHeap(const MaxHeap& heap1){
   
        heap_size = heap1.heap_size;
        capacity = heap1.capacity;
        array_heap = heap1.array_heap;
        std::cout << "Copy constructor"<<std::endl;
    
}

   template <typename T>
   MaxHeap<T>::MaxHeap( std::initializer_list<T> obj){
       for(auto it : obj){
          insert(it);
        
           }
       std::cout << "Initializer_list<int>Constructor"<<std::endl;
   }
    


template <typename T>
void MaxHeap<T>::right_heap(){
      for(int i =  0; i < (MaxHeap::heap_size/2)-1;++i){
        std::cout << 
        " right is  "<<array_heap[(2*i)+2] 
        <<std::endl;
    }
}
template <typename T>
void MaxHeap<T>::left_heap(){
    for( int i =  0; i < MaxHeap::heap_size/2;++i){
        std::cout << 
        " left is  "<<array_heap[(2*i)+1] 
        <<std::endl;
    }
}

template <typename T>
 int MaxHeap<T>::height(){
    return (log2(MaxHeap::heap_size + 1)+1);
}

template <typename T>
T MaxHeap<T>::parent_heap(){
    return MaxHeap::array_heap[0];
}


template <typename T>
int MaxHeap<T>::linear_search(T value_search){
      for (int i = 0; i < MaxHeap::heap_size; i++) {
      if (MaxHeap::array_heap[i] == value_search) {
        return i;
      }
    }
    return -1;
}


template <typename T>
void MaxHeap<T>::extract_min_element(){
 T min = array_heap[0];
    for(int i = 0 ; i < MaxHeap::heap_size;i++){
        if(min >  MaxHeap::array_heap[i]){
            min =  MaxHeap::array_heap[i];
           
        }
    }
   
    std::cout<< "this is extract_min_element = " <<min << std::endl;
}

template <typename T>
MaxHeap<T>::MaxHeap(int cap)
{    array_heap= new T[cap];
	
	capacity = cap;
	heap_size = 0;
}

template <typename T>
void MaxHeap<T>::insert(T value)
{
    
	heap_size++;
	int i = heap_size - 1;
	array_heap[i] = value;


	while ( i != 0 && array_heap[parent(i)] < array_heap[i])
	{
	swap(array_heap[i], array_heap[parent(i)]);
	i = parent(i);
	}
}


template <typename T>
void MaxHeap<T>::delete_element(T value_delete)
{
      for (int i = 0; i < MaxHeap::heap_size; i++) {
      if (MaxHeap::array_heap[i] == value_delete) {
           swap(MaxHeap::array_heap[i] ,array_heap[MaxHeap::heap_size-1]);
          MaxHeap::heap_size--;
          MaxHeapify(i);
        return;
      }
    }
    std::cout << "Value NOT Found!";
}


template <typename T>
void MaxHeap<T>::MaxHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && array_heap[l] > array_heap[i])
		smallest = l;
	if (r < heap_size && array_heap[r] > array_heap[smallest])
		smallest = r;
	if (smallest != i)
	{
		swap(array_heap[i], array_heap[smallest]);
		MaxHeapify(smallest);
	}
}

template <typename T>
void MaxHeap<T>::print(){
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
    
	MaxHeap<int>heap(20);
MaxHeap<int>hp= {2,4,8,44,8,77,2};
// MaxHeap<std::string>hp= {"FSAD","WEASDAS"};

   //heap.insert(1);
//	hp.insert("EWQSEADSEWDQSA");
		hp.print();

	heap.insert(11);
	heap.insert(2);
	heap.insert(66);
	heap.insert(4);
    
	heap.insert(2);
	heap.insert(6);
	heap.insert(81);
    heap.insert(27);
	heap.insert(8);
	std::cout<<std::endl;
	std::cout<<	heap.linear_search(2)<<std::endl;
heap.print();
	//MaxHeap<int> hs(20);
	//hs = heap;
//	std::cout << hs;
//	MaxHeap<int>heap1 = std::move(heap); 
/*	MaxHeap<int>heap2(20); 
//	MaxHeap<int>heap3(30);
	heap2.insert(11);
	heap2.insert(3);
	heap2.insert(4);*/
	//heap2.insert(8);
	//heap = std::move(heap2);
//	heap3.insert(14);
//	heap2 = heap;
	
//	heap2 = heap;
	heap.print();
	//std::cout << heap2;
//	heap3.print();
 /*   MaxHeap<int> heap4(40);
	
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
	//std::cout << MaxHeap<int>::heap.capacity <<" capacity " << MaxHeap<int>::heap.heap_size << " size "<<std::endl;
//	heap1 = std::move(heap);
//	heap1.insert(2);
 // MaxHeap<int> hp{1,2};
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
/*	heap.print();
	heap.delete_element(7);
	heap.linear_search(4);
//	heap.delete_element(24);
    heap.print();
	heap.delete_element(3);
	heap.insert(11);
	heap.print();*/
    heap.extract_min_element();
   /* std::cout<<"this is parent_heap " << heap.parent_heap()<<std::endl;
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
