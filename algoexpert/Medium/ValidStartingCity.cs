using System;

namespace AlgoExpert.Medium
{
    class Medium_ValidStartingCity
    {
		// O(n^2) T, O(1) S
		public int ValidStartingCity(int[] distances, int[] fuel, int mpg)
		{
			// O(n2) T, O(1) S
			for (int i = 0; i < distances.Length; i++)
			{
				int circle = 0;
				int consumption = 0;
				bool valid = true;
				int j = i;
				while (circle < distances.Length)
				{
					consumption += (fuel[j] * mpg) - distances[j];
					if (consumption < 0)
					{
						valid = false;
						break;
					}
					j++;
					j %= distances.Length;
					circle++;
				}

				if (valid)
					return i;

			}
			return -1; // will not reach it.
					   // assuming that there will always be a possible solution.
		}

		// O(n) T, O(1) S
		public int Optimal_ValidStartingCity(int[] distances, int[] fuel, int mpg)
		{
			int mn = Int32.MaxValue;
			int idx = 0;
			int consumption = 0;
			for (int i = 1; i <= distances.Length; i++)
			{
				consumption += (fuel[i - 1] * mpg) - distances[i - 1];
				if (mn > consumption)
				{
					idx = i;
					mn = consumption;
				}
			}
			return idx % distances.Length;
		}
	}
}
