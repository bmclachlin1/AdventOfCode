from collections import deque


with open('input.txt') as fin:
    data = [line.rstrip() for line in fin]

total_of_each_card = [0] * 214

for row in data:
    scratchcards = row.split(': ')
    card_number = int(scratchcards[0].split()[1])
    print(scratchcards[0].split()[1])
    rhs = ''.join(scratchcards[1])
    winning_numbers, my_numbers = rhs.split(" | ")
    winning_numbers = winning_numbers.split()
    my_numbers = my_numbers.split()
    winning_numbers = [int(n) for n in winning_numbers]
    my_numbers = [int(n) for n in my_numbers]
    print("winning numbers", winning_numbers)
    print("my numbers", my_numbers)

    total_of_each_card[card_number] += 1
    
    winning_set = set(winning_numbers)
    
    wins = 0
    for num in my_numbers:
        if num in winning_set:
            wins += 1
    
    for i in range(wins):
        total_of_each_card[card_number + i + 1] += total_of_each_card[card_number]

print(total_of_each_card)
print(sum(total_of_each_card))