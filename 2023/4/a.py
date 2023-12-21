with open('input.txt') as fin:
    data = [line.rstrip() for line in fin]

sum = 0


for row in data:
    scratchcards = row.split(': ')
    rhs = ''.join(scratchcards[1])
    winning_numbers, my_numbers = rhs.split(" | ")
    winning_numbers = winning_numbers.split()
    my_numbers = my_numbers.split()
    winning_numbers = [int(n) for n in winning_numbers]
    my_numbers = [int(n) for n in my_numbers]
    print("winning numbers", winning_numbers)
    print("my numbers", my_numbers)
    winning_set = set(winning_numbers)
    
    curr = 0
    for num in my_numbers:
        if num in winning_set:
            if curr == 0:
                curr = 1
            else:
                curr *= 2
    
    sum += curr
    
print(sum)