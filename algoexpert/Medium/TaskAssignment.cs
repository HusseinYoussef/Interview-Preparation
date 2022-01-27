using System;
using System.Collections.Generic;

namespace AlgoExpert.Medium
{
    class Medium_TaskAssignment
    {
		public List<List<int>> TaskAssignment(int k, List<int> tasks)
		{
			int[][] valIndexes = new int[tasks.Count][];

			for (int i = 0; i < tasks.Count; i++)
				valIndexes[i] = new int[] { tasks[i], i };

			Array.Sort(valIndexes, (a, b) => a[0].CompareTo(b[0]));

			List<List<int>> results = new();
			for (int i = 0; i < k; i++)
				results.Add(new List<int> { valIndexes[i][1], valIndexes[tasks.Count - i - 1][1] });
			
			return results;
        }

	}
}
