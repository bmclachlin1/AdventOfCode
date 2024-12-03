left_numbers = []
dict = {}

with open('input.txt') as fin:
    for line in fin.readlines():
        left, right = line.split()
        left_numbers.append(int(left))
        dict[int(right)] = dict.get(int(right), 0) + 1

score = 0

for number in left_numbers:
    score += number * dict.get(number, 0)

print('Similarity score:', score)