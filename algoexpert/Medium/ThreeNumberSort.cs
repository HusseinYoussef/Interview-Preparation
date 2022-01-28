using System.Collections.Generic;

namespace AlgoExpert.Medium
{
    class Medium_ThreeNumberSort
    {
		// O(n) T | O(1) S
		public static int[] ThreeNumberSort(int[] array, int[] order)
		{
			Dictionary<int, int> frequencies = new();
			foreach (var num in array)
			{
				if (!frequencies.ContainsKey(num))
					frequencies[num] = 1;
				else
					frequencies[num] += 1;
			}

			int i = 0;
			foreach (var orderNum in order)
			{
				while (frequencies.ContainsKey(orderNum) && frequencies[orderNum] > 0 && i < array.Length)
				{
					array[i] = orderNum;
					i++;
					frequencies[orderNum] -= 1;
				}
			}

			return array;
		}
	}
}
