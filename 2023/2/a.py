with open('input.txt') as fin:
    data = [line.rstrip('\n') for line in fin]

NUM_RED = 12
NUM_GREEN = 13
NUM_BLUE = 14

ans = 0

for line in data:
    game, parts = line.split(": ")
    print(parts)
    game_id = game.split(" ")[1]

    possible = True

    for round in parts.split("; "):
        for cube in round.split(", "):
            print(cube)
            quantity, color = cube.split(" ")

            if color == "red" and int(quantity) > NUM_RED:
                possible = False 
            elif color == "green" and int(quantity) > NUM_GREEN:
                possible = False 
            elif color == "blue" and int(quantity) > NUM_BLUE:
                possible = False 
    
    if possible:
        ans += int(game_id) 

print(ans)
 