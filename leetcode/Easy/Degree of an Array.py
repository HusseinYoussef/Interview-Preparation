def findShortestSubArray(self, nums: List[int]) -> int:
        
    mx = 1
    freq = {}
    indices = {}
    for idx, num in enumerate(nums):
        if num not in freq:
            freq[num] = 1
        else:
            freq[num] += 1
            mx = max(mx, freq[num])

        if num not in indices:
            indices[num] = [idx, idx]
        else:
            indices[num][-1] = idx

    mn = len(nums)
    for num in nums:
        if freq[num] == mx:
            mn = min(mn, indices[num][-1] - indices[num][0] + 1)
    return mn
