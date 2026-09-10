def majority_element(nums):
    frequency = {}

    for i in nums:
        if i in frequency:
            frequency[i] += 1
        else:
            frequency[i] = 1

    n = len(nums)

    for i in frequency:
        if frequency[i] > n/2:
            return i


nums = [2,2,1,1,1,2,2]

print("Majority element:",majority_element(nums))