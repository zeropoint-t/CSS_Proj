

#include <iostream>
#include <string>

using namespace std;

template <typename Comparable>
class Heap {
	public:
		// Constructor, copy constructor, destructor, as usual…
		void insert(Comparable *c);
		const Comparable * findMin() const;
		bool deleteMin();
private:
		int size;
		vector<Comparable *> items;
        void heapify();
        void percolateDown(int position);
};

template <typename Comparable>
void Heap<Comparable>::insert(Comparable *c)
{
	if (c == NULL) return;

    //Add item in position 0 (dummy position) to prevent percolating up from root 
	items[0] = c;

    // Ensure we have enough space
	size++;
    if (items.size() == size)
    {
        items.push_back(NULL);
    }
		
    // Percolate up
    int position = size;
    while (*c < *items[position / 2])
    {
        items[position] = items[position / 2];
        position = position / 2;
    }
    
    items[position] = c;
}

template <typename Comparable>
bool Heap<Comparable>::deleteMin()
	{
		if (size == 0) return false;
		delete items[1];
		items[1] = items[size];
		size--;

		percolateDown(1);
		return true;
	}

template <typename Comparable>
void Heap<Comparable>::percolateDown(int position)
{
    int child = position * 2;
    if (child > size) return;
    if (child != size && *items[child] > *items[child + 1]) child++;
    if (*items[child] < *items[position]) 
    {
        swap(items[child], items[position]);
        percolateDown(child);
    }
}

// This routine assumes that the objects and size have already been loaded into the heap data
template <typename Comparable>
void Heap<Comparable>::heapify()
{
    for (int i = size / 2; i > 0; i--)
        percolateDown(i);
}

int main(){

}