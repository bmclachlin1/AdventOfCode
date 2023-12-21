with open('./input.txt') as fin:
    data = fin.read().strip()
    groups = data.split("\n\n")
    print(groups)


sums = []
for group in (groups): 
    group = [int(x) for x in group.split()]
    sums.append(sum(group))

sums.sort(reverse=True)

print(sums[0]+sums[1]+sums[2])




