text = """
machine learning is powerful
machine learning helps analyze data
data science uses machine learning
"""

text = text.lower()
words = text.split()

frequency = {}

for word in words:
    if word in frequency:
        frequency[word] += 1
    else:
        frequency[word] = 1

highest = 0
most_frequent = ""

for word in frequency:
    if frequency[word] > highest:
        highest = frequency[word]
        most_frequent = word

unique_words = set(words)

print("Word Frequency:")
print(frequency)
print("\n")

print("Most frequently occurring word:", most_frequent)
print("\n")
print("Unique words:")
print(unique_words)
print("\n")

print("Words appearing more than once:")

for word in frequency:
    if frequency[word] > 1:
        print(word)