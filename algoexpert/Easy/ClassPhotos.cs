using System.Collections.Generic;

namespace AlgoExpert.Easy
{
    class Easy_ClassPhotos
    {
		// O(nlogn) T, O(1) S
		public bool ClassPhotos(List<int> redShirtHeights, List<int> blueShirtHeights)
		{
			bool redBlue = false; // red > blue
			bool blueRed = false; // blue > red

			redShirtHeights.Sort();
			blueShirtHeights.Sort();

			for (int i = 0; i < redShirtHeights.Count; i++)
			{
				if (redBlue == blueRed && (redBlue != false && blueRed != false)) // right check to ignore first iteration
					return false;

				if (redShirtHeights[i] < blueShirtHeights[i])
					blueRed = true;
				else if (redShirtHeights[i] > blueShirtHeights[i])
					redBlue = true;
				else // same height 
					return false;
			}
			return redBlue != blueRed;
		}
	}
}
