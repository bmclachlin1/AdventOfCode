with open('input.txt') as fin:
    data = [line.rstrip('\n') for line in fin]

sum = 0
for record in data:
    digits = [char for char in record if char.isdigit()]
    first, last = digits[0], digits[-1]
    sum += int(first + last)

print(sum)

