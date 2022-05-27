#include<iostream>
#include<cmath>

template<typename T>
void swap(T &x, T &y);


template<typename T>
class MaxHeap
{
	T *array_heap; 
	int capacity=28;
	int heap_size; 
public:

	MaxHeap(int capacity);

	void MaxHeapify(int );

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
	
	void linear_search(T value_search);
	
	void print();
};
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
void MaxHeap<T>::linear_search(T value_search){
      for (int i = 0; i < MaxHeap::heap_size; i++) {
      if (MaxHeap::array_heap[i] == value_search) {
        std::cout << "Value Found! " << array_heap[i] << " index of " << i  << std::endl;
        return;
      }
    }
    std::cout << "Value NOT Found!"<<std::endl;
}


template <typename T>
void MaxHeap<T>::extract_min_element(){
    T min = array_heap[0];
    for(int i = 0 ; i < MaxHeap::heap_size;i++){
        if(min >  MaxHeap::array_heap[i]){
            min =  MaxHeap::array_heap[i];
           
        }
    }
    std::cout<< "this is extract_min_element = " << min << std::endl;
}

template <typename T>
MaxHeap<T>::MaxHeap(int cap)
{
	heap_size = 0;
	capacity = cap;
	array_heap = new T[cap];
}

template <typename T>
void MaxHeap<T>::insert(T value)
{
	if (heap_size == capacity)
	{
	std::cout << "Overflow: Could not insert "<<std::endl;
		return;
	}

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
	int least = i;
	if (l > heap_size && array_heap[l] > array_heap[i])
		least = l;
	if (r > heap_size && array_heap[r] > array_heap[least])
		least = r;
	if (least != i)
	{
		swap(array_heap[i], array_heap[least]);
		MaxHeapify(least);
	}
}

template <typename T>
void MaxHeap<T>::print(){
    for(int i = 0;i < MaxHeap::heap_size;++i){
        std::cout << MaxHeap::array_heap[i] << " ";
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
	MaxHeap<int>heap(28);
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
	
 	heap.insert(1);
	heap.insert(3);
	heap.insert(7);
	heap.insert(25);
	heap.insert(77);
	heap.insert(41);
	heap.insert(27);
	heap.insert(67);
	heap.insert(81);
    heap.insert(27);
	heap.insert(8);
	heap.insert(14);

//	heap.delete_element(7);
//	heap.delete_element(41);
//	heap.delete_element(71);
//	heap.delete_element(2);
//	heap.delete_element(14);
	std::cout <<std::endl;

	heap.insert(33);
  	//heap.insert(7);
	heap.insert(10);

	heap.insert(3);
	heap.linear_search(27);
//	heap.delete_element(24);
    
	heap.delete_element(7);
	heap.insert(31);
	heap.insert(30);
	heap.insert(75);
	heap.insert(23);
	heap.insert(47);
	heap.insert(41);
	heap.insert(27);
	heap.insert(67);
//	heap.insert(81);
	heap.insert(77);
	heap.insert(11);
	heap.print();
    heap.extract_min_element();
    std::cout<<"this is parent_heap " << heap.parent_heap()<<std::endl;
    std::cout <<"this is  height "<< heap.height()<<std::endl;
    heap.left_heap();
    std::cout <<std::endl;
    heap.right_heap();
	return 0;
}
