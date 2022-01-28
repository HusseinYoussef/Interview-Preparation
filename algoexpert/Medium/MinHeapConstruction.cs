using System;
using System.Collections.Generic;

namespace AlgoExpert.Medium
{
	public class MinHeap
	{
		public List<int> heap = new List<int>();
        public int Size { get; private set; }
        public int Capacity { get; private set; }

        private static int GetLeftChildIndex(int parentIndex) { return (parentIndex * 2) + 1; }
		private static int GetRightChildIndex(int parentIndex) { return (parentIndex * 2) + 2; }
		private static int GetParentIndex(int index) { return (index - 1) / 2; }

		private bool HasLeftChild(int parentIndex) { return GetLeftChildIndex(parentIndex) < Size; }
		private bool HasRightChild(int parentIndex) { return GetRightChildIndex(parentIndex) < Size; }
		private static bool HasParent(int index) { return GetParentIndex(index) > 0; }

		private int LeftChild(int parentIndex) { return heap[GetLeftChildIndex(parentIndex)]; }
		private int RightChild(int parentIndex) { return heap[GetRightChildIndex(parentIndex)]; }
		private int Parent(int childIndex) { return heap[GetParentIndex(childIndex)]; }

		private void Swap(int indexOne, int indexTwo)
        {
			int temp = heap[indexOne];
			heap[indexOne] = heap[indexTwo];
			heap[indexTwo] = temp;
        }

        public MinHeap(List<int> array)
		{
			heap = array;
			Size = array.Count;
			heap = BuildHeap(array);
		}

		public List<int> BuildHeap(List<int> array)
		{
			int startIdx = (array.Count / 2) - 1;
			for (int currentIndex = startIdx; currentIndex >= 0; currentIndex--)
				SiftDown(currentIndex, array.Count - 1, array);

			return array;
		}

		public void SiftDown(int currentIdx, int endIdx, List<int> heap)
		{
            while (HasLeftChild(currentIdx))
            {
				int smallerChildIndex = GetIndexOfChildsMinValue(currentIdx);

				if (heap[currentIdx] < heap[smallerChildIndex])
					break;
				else
					Swap(currentIdx, smallerChildIndex);

				currentIdx = smallerChildIndex; 
            }
		}

        private int GetIndexOfChildsMinValue(int currentIdx)
        {
			int smallerChildIndex = GetLeftChildIndex(currentIdx);
			if (HasRightChild(currentIdx))
            {
				if (RightChild(currentIdx) < LeftChild(currentIdx))
					smallerChildIndex = GetRightChildIndex(currentIdx);
			}

			return smallerChildIndex;
        }

        public void SiftUp(int currentIdx, List<int> heap)
		{
			while( HasParent(currentIdx) && (Parent(currentIdx) > heap[currentIdx]) )
            {
				Swap(GetParentIndex(currentIdx), currentIdx);
				currentIdx = GetParentIndex(currentIdx);
            }
		}

		public int Peek()
		{
			if (Size == 0) throw new NullReferenceException();
			return heap[0];
		}

		public int Remove() // pop -- Remove Root
		{
			if (Size == 0) throw new NullReferenceException();
			int rootValue = heap[0];
			Swap(0, Size - 1);
			heap.RemoveAt(Size - 1);
			SiftDown(0, Size - 1, heap);
			Size--;
			return rootValue;
		}

		public void Insert(int value)
		{
			heap.Add(value);
			SiftUp(Size, heap);
			Size++;
		}
	}
}
