using System;

namespace AlgoExpert.Easy
{
    class Easy_TandemBicycle
    {
		// O(nlogn) T, O(1) S
		public int TandemBicycle(int[] redShirtSpeeds, int[] blueShirtSpeeds, bool fastest)
		{
			Array.Sort(redShirtSpeeds);
			if (fastest)
				Array.Sort(blueShirtSpeeds, new Comparison<int>((a, b) => b.CompareTo(a)));
			else
				Array.Sort(blueShirtSpeeds);

			int totalSpeed = 0;
			for (int i = 0; i < redShirtSpeeds.Length; i++)
				totalSpeed += Math.Max(redShirtSpeeds[i], blueShirtSpeeds[i]);

			return totalSpeed;
		}
	}
}
