using System;

class EASY_MinimumWaitingTime
{
	public int MinimumWaitingTime(int[] queries)
	{
		Array.Sort(queries);

		int minWaitingTime = 0;
		int runningWaitingTime = 0;
		for (int i = 1; i < queries.Length; i++)
		{
			runningWaitingTime += queries[i-1];
			minWaitingTime += runningWaitingTime;
		}

		return minWaitingTime;
	}

}
