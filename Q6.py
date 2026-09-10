def top_k_frequent(nums,k):
    frequency = {}

    for i in nums:
        if i in frequency:
            frequency[i] += 1
        else:
            frequency[i] = 1

    sorted_items = sorted(frequency.items(), key=lambda x:x[1], reverse=True)

    answer = []

    for i in range(k):
        answer.append(sorted_items[i][0])

    return answer


nums = [1,1,1,2,2,3]
k = 2

print("Top",k,"frequent elements:",top_k_frequent(nums,k))