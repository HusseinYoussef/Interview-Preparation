using System;
using System.Collections.Generic;

public class Medium_MinimumCharactersForWords
{
	public char[] MinimumCharactersForWords(string[] words)
	{
		Dictionary<char, int> maxFreqs = new();
		List<char> results = new();
		foreach (var word in words)
		{
			Dictionary<char, int> charFreqs = CountCharFrequencies(word);
			UpdateMaxFreqs(charFreqs, maxFreqs);
		}

		foreach (var charFreq in maxFreqs)
		{
			for (int i = 0; i < charFreq.Value; i++)
			{
				results.Add(charFreq.Key);
			}
		}
		return results.ToArray();
	}

	private void UpdateMaxFreqs(Dictionary<char, int> charFreqs, Dictionary<char, int> maxFreqs)
	{
		foreach (var charFreq in charFreqs)
		{
			if (!maxFreqs.ContainsKey(charFreq.Key))
				maxFreqs[charFreq.Key] = charFreq.Value;
			else
				maxFreqs[charFreq.Key] = Math.Max(charFreq.Value, maxFreqs[charFreq.Key]);
		}
	}

	private static Dictionary<char, int> CountCharFrequencies(string word)
	{
		Dictionary<char, int> charFreq = new();
		for (int i = 0; i < word.Length; i++)
		{
			if (!charFreq.ContainsKey(word[i]))
				charFreq[word[i]] = 1;
			else
				charFreq[word[i]] += 1;
		}

		return charFreq;
	}
}
