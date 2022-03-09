#include <iostream>
#include <vector>

using namespace std;

/* 
class Iterator
{
    *struct Data;
    *Data *data;
    *public : *Iterator(const vector<int> &nums);
    *Iterator(const Iterator &iter);
    ** // Returns the next element in the iteration.
     *int next();
    ** // Returns true if the iteration has more elements.
     *bool hasNext() const;
    *	};
 */

class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    
	}
	
    // Returns the next element in the iteration without advancing the iterator.
    // Create a copy then use next, it will change the iterator for the temp copy
	int peek() {
        return Iterator(*this).next(); 
	}

    // Needn't implement next and has_next
};