#include <vector>
using namespace std;

// Do not edit the class below except for the buildHeap,
// siftDown, siftUp, peek, remove, and insert methods.
// Feel free to add new properties and methods to the class.
class MinHeap {
public:
  vector<int> heap;

  MinHeap(vector<int> vector) { heap = buildHeap(vector); }

	vector<int> buildHeap(vector<int> &vector)
	{
        int n = vector.size();

        for (int i = 0; i < n;++i)
        {
            insert(vector[i]);
        }
		return heap;
	}

	void siftDown(int currentIdx, int endIdx, vector<int> &heap)
	{
        while(true)
        {
            int left = 2 * currentIdx + 1;
            int right = 2 * currentIdx + 2;
            int lowest = currentIdx;
            if(left <= endIdx && heap[left] < heap[lowest])
                    lowest = left;
            if(right <= endIdx && heap[right] < heap[lowest])
                    lowest = right;

            if(lowest == currentIdx)
                    break;
            swap(heap[currentIdx], heap[lowest]);
            currentIdx = lowest;
        }
	}

	void siftUp(int currentIdx, vector<int> &heap)
	{
        while(true)
        {
            int parentIdx = (currentIdx - 1) / 2;
            if(parentIdx < 0 || heap[currentIdx] >= heap[parentIdx])
                break;
            swap(heap[currentIdx], heap[parentIdx]);
            currentIdx = parentIdx;
        }
	}

	int peek()
	{
        if(!heap.empty())
                return heap[0];
        return -1;
	}

	int remove()
	{
        if(heap.empty())
                return -1;

        int val = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        siftDown(0, heap.size() - 1, heap);
        return val;
	}

	void insert(int value)
	{
        heap.push_back(value);
        siftUp((int)heap.size() - 1, heap);
	}
};