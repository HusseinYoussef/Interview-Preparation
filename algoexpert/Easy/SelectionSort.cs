using System;

namespace AlgoExpert.Easy
{
    class Easy_SelectionSort
    {
		// O(n^2) | O(1) - Best, Avearge, Worst. 
		public static int[] SelectionSort(int[] array)
		{
			if (array.Length == 0) return Array.Empty<int>();

			for (int i = 0; i < array.Length - 1; i++)
			{
				int smallestNumIdx = i;
				for (int j = i + 1; j < array.Length; j++)
				{
					if (array[smallestNumIdx] > array[j])
						smallestNumIdx = j;
				}
				Swap(i, smallestNumIdx, array);
			}
			return array;
		}

		public static void Swap(int idxOne, int idxTwo, int[] array)
		{
			int tmp = array[idxOne];
			array[idxOne] = array[idxTwo];
			array[idxTwo] = tmp;
		}
	}
}
