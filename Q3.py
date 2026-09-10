def contains_duplicate(nums):
    seen = set()

    for i in nums:
        if i in seen:
            print("Duplicate found:",i)
            return True

        seen.add(i)

    return False


nums = [1,2,3,4,5,3]

print(contains_duplicate(nums))