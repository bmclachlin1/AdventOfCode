with open('input.txt') as fin:
    data = [line.rstrip('\n') for line in fin]

ans = 0

for line in data:
    game, parts = line.split(": ")
    game_id = game.split(" ")[1]

    min_red = 0
    min_green = 0
    min_blue = 0

    for round in parts.split("; "):
        for cube in round.split(", "):
            quantity, color = cube.split(" ")

            if color == "red":
                min_red = max(min_red, int(quantity))
            elif color == "green":
                min_green = max(min_green, int(quantity))
            else:
                min_blue = max(min_blue, int(quantity))
    
    power = min_red * min_green * min_blue 

    ans += power

print(ans)
 