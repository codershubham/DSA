#include <iostream>
#include <stdio.h>
using namespace std;
enum heap_type {
	MIN_HEAP,
	MAX_HEAP
};
class BHeap{	// considering this as Max heap
public:
	int *array;
	int capacity;
	int count;
	heap_type heapType;
	

	BHeap(heap_type type, int fcapacity) {
	    heapType = type;
	    capacity = fcapacity;
		array = new int[capacity];
		for(int i = 0; i < capacity; i++) {
		    array[i] = 0;
		}
	}
	
	void ResizeHeap();
	void Insert(int data);
	int DeleteMax();
	int LeftChild(int root);	// Clarify : to not to be confused root is not the root node of tree
	int RightChild(int root);
	int GetMaximum();
	void PercolateDown(int node);
};

int BHeap::GetMaximum() {
	
	if(count == 0) {	// handle corner case
		return -1;
	}
	
	return array[0];
} // O(1)

int BHeap::LeftChild(int rootNode) {
	int leftChild = 2*rootNode + 1;
	if(leftChild >= count) {
		return -1;
	} else {
		return leftChild;
	}
}	// Time Complexity O(1)

int BHeap::RightChild(int rootNode) {
	int rightChild = 2*rootNode + 2;
	if(rightChild >= count) {
		return -1;
	} else {
		return rightChild;
	}
}	// Time Complexity O(1)

void BHeap::ResizeHeap() {
	int *temp = array;
	int *newArray = new int[2*capacity];	// create a new array with twice capacity
	
	if(newArray == nullptr) {
		return;
	}
	
	for(int i = 0; i < 2*capacity; i++) {
	    newArray[i] = 0;
	}
	
	for(int i = 0; i < capacity; i++) {			// copy previous array
		newArray[i] = array[i];
	}
	array = newArray;		// update member variable array
	capacity *= 2;			// twice capacity
	delete [] temp;			// free old array memory
} // O(count)

void BHeap::PercolateDown(int node) {
	int left, right, temp, max;
	
	left = LeftChild(node);
	right = RightChild(node);
	if(left != -1 && array[left] > array[node]) {
		max = left;
	} else {
		max = node;
	}
	
	if(right != -1 && array[right] > array[node]) {
		max = right;
	} else {
		max = node;
	}

	if(max != node) {	// swap value with child
		temp = array[max];
		array[max] = array[node];
		array[node] = temp;
		PercolateDown(max);
	}
}	// Time Complexity O(logn)

int BHeap::DeleteMax() {
	if(count == 0) {	// heap is empty hence nothing to delete
		return -1;
	}
	int data = array[0];
	array[0] = array[count -1];
	array[count-1] = 0;
	count--;
	PercolateDown(0);
	return data;
}

void BHeap::Insert(int data) {
	if(count == capacity) {
		ResizeHeap();
	}
	
	count++;
	
	int i = count -1;
	while(i>0 && data > array[i]) {
		array[i] = array[(i-1)/2];
		i = (i-1)/2;
	}
	array[i] = data;
}

int main() {
	BHeap heap(heap_type::MAX_HEAP, 5);	// Max heap with capacity 5
	heap.Insert(1);
	heap.Insert(2);
	heap.Insert(3);
	heap.Insert(4);
	heap.Insert(5);
	heap.Insert(6);
	heap.Insert(7);
	heap.Insert(8);
	for(int i = 0; i < heap.count; i++) {
	    cout << heap.array[i] << endl;
	}
	//cout << "deleteMax : " << heap.DeleteMax() << endl;
	//cout << "deleteMax : " << heap.DeleteMax() << endl;
}