left_numbers, right_numbers = [], []

with open('input.txt') as fin:
    for line in fin.readlines():
        left, right = line.split()
        left_numbers.append(int(left))
        right_numbers.append(int(right))

left_numbers.sort()
right_numbers.sort()

NUM_LINES = len(left_numbers)
assert(NUM_LINES == len(right_numbers))

distance = 0

for i in range(NUM_LINES):
    distance += abs(left_numbers[i] - right_numbers[i])

print('Distance:', distance)
