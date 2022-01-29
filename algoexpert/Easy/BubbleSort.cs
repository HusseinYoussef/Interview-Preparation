namespace AlgoExpert.Easy
{
    class Easy_BubbleSort
    {
		public static int[] BubbleSort(int[] array)
		{
			if (array.Length == 0) return new int[] { };

			bool isSorted = false;
			int i = 0;
			while (!isSorted)
			{
				isSorted = true;
				for (int j = 0; j < array.Length - i - 1; j++)
				{
					if (array[j] > array[j + 1])
					{
						Swap(j, j + 1, array);
						isSorted = false;
					}
				}
				i++;
			}
			return array;
		}

		public static void Swap(int idxOne, int idxTwo, int[] array)
		{
			int temp = array[idxOne];
			array[idxOne] = array[idxTwo];
			array[idxTwo] = temp;
		}
	}
}
