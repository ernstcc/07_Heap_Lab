#include "Queue.h"
#include <utility>

//This should be the initial arrSize
#define START_SIZE 10

/*
 * This is a priority queue, which means that as items are removed in order
 * of decreasing priority.
 *
 * 
 */
template<class Pri, class T>
class Heap : public Queue<std::pair<Pri, T> > {
public:
  Heap();
  ~Heap();

  //Add a new item
  virtual void add(std::pair<Pri,T> toAdd);

  //Remove the item with lowest priority, and return it
  //If the queue is empty, throw a string exception
  virtual std::pair<Pri,T> remove();

  //Return the number of items currently in the queue
  virtual unsigned long getNumItems();

private:
  int arrSize;
  unsigned int numItems;
  std::pair<Pri, T>* backingArray;

  //Grow the backingArray by making a new array of twice the size,
  // and copying over the data
  void grow();

  //Check the item at index, and make sure it is in the right place.
  // If not, swap it up the "tree" of the heap until you find the right
  // place
  void bubbleUp(unsigned long index);

  //Check the item at index, and make sure it is in the right place.
  // If not, swap it down the "tree" of the heap until you find the right
  // place
  void trickleDown(unsigned long index);  
};
#include <string>

template<class Pri, class T>
Heap<Pri, T>::Heap(){
	arrSize = START_SIZE;
	numItems = 0;
	backingArray = new std::pair<Pri,T>[START_SIZE];
}

template<class Pri, class T>
Heap<Pri, T>::~Heap(){
	delete[] backingArray;
}

template<class Pri, class T>
void Heap<Pri, T>::grow(){
	int newArr = arrSize * 2;
	std::pair<Pri, T>* temp = new std::pair<Pri, T>[newArr];

	for (int x = 0; x < arrSize; x++){
		temp[x] = backingArray[x];
	}

	delete[] backingArray;
	backingArray = temp;
	arrSize = newArr;
}

template<class Pri, class T>
void Heap<Pri, T>::add(std::pair<Pri, T> toAdd){
	if (numItems == arrSize){
		grow();
	}

	backingArray[numItems] = toAdd;
	bubbleUp(numItems);
	numItems++;
}

template<class Pri, class T>
void Heap<Pri, T>::bubbleUp(unsigned long index){
	unsigned long p = (index - 1) / 2;
	while (index > 0 && backingArray[index] < backingArray[p]){
		swap(backingArray[index], backingArray[p]);
		index = p;
		p = (index - 1) / 2;
	}
}

template<class Pri, class T>
void Heap<Pri, T>::trickleDown(unsigned long index){
	bool madeChange;
	unsigned long r;
	unsigned long l;
	
	do{
		madeChange = false;
		r = (2 * index) + 2;
		l = (2 * index) + 1;

		if (r < numItems && backingArray[r].first < backingArray[index].first){
			if (backingArray[l].first < backingArray[r].first){
				swap(backingArray[index], backingArray[l]);
				index = l;
				madeChange = true;
			}
			else{
				swap(backingArray[index], backingArray[r]);
				index = r;
				madeChange = true;
			}
		}
		else{
			if (l < numItems && backingArray[l].first < backingArray[index].first){
				swap(backingArray[index], backingArray[l]);
				index = l;
				madeChange = true;
			}
		}
	} while (madeChange);
}

template<class Pri, class T>
std::pair<Pri, T> Heap<Pri, T>::remove(){
	std::pair<Pri, T> head = backingArray[0];
	numItems--;
	backingArray[0] = backingArray[numItems];
	trickleDown(0);
	return head;
}

template<class Pri, class T>
unsigned long Heap<Pri, T>::getNumItems(){
	return numItems;
}