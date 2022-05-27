#include<iostream>
#include<cmath>

template<typename T>
void swap(T &x, T &y);


template<typename T>
class MinHeap
{
	T *array_heap; 
	int capacity=28;
	int heap_size; 
public:

	MinHeap(int capacity);

	void MinHeapify(int );

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
	
	void linear_search(T value_search);
	
	void print();
};
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
void MinHeap<T>::linear_search(T value_search){
      for (int i = 0; i < MinHeap::heap_size; i++) {
      if (MinHeap::array_heap[i] == value_search) {
        std::cout << "Value Found! " << array_heap[i] << " index of " << i  << std::endl;
        return;
      }
    }
    std::cout << "Value NOT Found!"<<std::endl;
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
{
	heap_size = 0;
	capacity = cap;
	array_heap = new T[cap];
}

template <typename T>
void MinHeap<T>::insert(T value)
{
	if (heap_size == capacity)
	{
	std::cout << "Overflow: Could not insert "<<std::endl;
		return;
	}

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
    for(int i = 0;i < MinHeap::heap_size;++i){
        std::cout << MinHeap::array_heap[i] << " ";
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
	MinHeap<std::string>h(28);
/*	h.insert("C");
	h.insert("B");
	h.insert("E");
	h.insert("A");
	h.insert("H");
	h.insert("T");
	h.insert("W");
	h.insert("g");
	h.insert("N");*/
	h.insert("Anna");
	h.insert("Ando");
	h.insert("Aro");
	h.insert("Gago");
	h.insert("valod");
	h.insert("Tiko");
	h.insert("Jane");
	h.insert("dod");
	h.insert("Arman");
	h.print();
	h.linear_search("dod");
    h.delete_element("Arman");
	
/* 	h.insert(1);
	h.insert(3);
	h.insert(7);
	h.insert(25);
	h.insert(77);
	h.insert(41);
	h.insert(27);
	h.insert(67);
	h.insert(81);
    h.insert(27);
	h.insert(8);
	h.insert(14);
	h.print();
	h.delete_element(7);
	h.delete_element(41);
//	h.delete_element(71);
	h.delete_element(2);
	h.delete_element(14);
	std::cout <<std::endl;
	h.print();
	h.insert(33);
  	//h.insert(7);
	h.insert(10);
	h.print();
	h.insert(3);
	h.linear_search(4);
//	h.delete_element(24);
    h.print();
	h.delete_element(3);
	h.insert(31);
	h.insert(30);
	h.insert(75);
	h.insert(23);
	h.insert(47);
	h.insert(41);
	h.insert(27);
	h.insert(67);
	h.insert(81);
	h.insert(77);
	h.insert(11);*/
	h.print();
    h.extract_max_element();
    std::cout<<"this is parent_heap " << h.parent_heap()<<std::endl;
    std::cout <<"this is  height "<< h.height()<<std::endl;
    h.left_heap();
    std::cout <<std::endl;
    h.right_heap();
	return 0;
}

