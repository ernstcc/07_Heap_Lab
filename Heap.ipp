#include <string>

template<class Pri, class T>
Heap<Pri,T>::Heap(){
  backingArray = new std::pair<Pri, T>[START_SIZE];
  arrSize = START_SIZE;
  numItems = 0;
}

template<class Pri, class T>
Heap<Pri,T>::~Heap(){
  delete[] backingArray;
}

template<class Pri, class T>
void Heap<Pri,T>::grow(){
  //TODO
}

template<class Pri, class T>
void Heap<Pri,T>::add(std::pair<Pri,T> toAdd){
	if(numItems == arrSize){
		grow();
	}
	backingArray[numItems] = toAdd;
	bubbleUp(static_cast<unsigned long>(numItems));
	numItems++; 
}

template<class Pri, class T>
void Heap<Pri,T>::bubbleUp(unsigned long index){
	int mom = (numItems - 1)/2;
	if(numItems != 0){
		while(index != 0 && backingArray[mom].first >
			backingArray[numItems].first){
			index = static_cast<unsigned long>(mom);
			mom = (mom - 1) / 2;
			}
	}
}

template<class Pri, class T>
void Heap<Pri,T>::trickleDown(unsigned long index){
  //TODO
}

template<class Pri, class T>
std::pair<Pri,T> Heap<Pri,T>::remove(){
  //TODO
  std::pair<Pri,T> tmp;
  return tmp;
}

template<class Pri, class T>
unsigned long Heap<Pri,T>::getNumItems(){
  return numItems;
}
