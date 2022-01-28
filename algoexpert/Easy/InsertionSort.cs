using System;

namespace AlgoExpert.Easy
{
    class Easy_InsertionSort
    {
		public static int[] InsertionSort(int[] array)
		{
			if (array.Length == 0) return Array.Empty<int>();

			for (int i = 1; i < array.Length; i++)
			{
				int j = i;
				while (j > 0 && array[j] < array[j - 1]) 
				{ 
					Swap(j, j - 1, array);
					j--;
				}
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
