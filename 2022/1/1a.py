with open('./input.txt') as fin:
    data = fin.read().strip()
    groups = data.split("\n\n")
    print(groups)

best = 0
for i, group in enumerate(groups): 
    group = [int(x) for x in group.split()]
    calories = sum(group)
    best = max(best, calories)

print(best)


    