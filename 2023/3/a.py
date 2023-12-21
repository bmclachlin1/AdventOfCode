with open('input.txt') as fin:
    data = [line.rstrip() for line in fin]

N_ROWS, N_COLS = len(data), len(data[0])

def inBounds(r, c):
    return r >= 0 and r < N_ROWS and c >= 0 and c < N_COLS
    
def isSymbol(ch):
    return not ch.isnumeric() and ch != '.'

def solve(r, c):
    ans = ''
    len = 0
    while c + len < N_COLS and data[r][c+len].isnumeric():
        ans += data[r][c+len]
        len += 1

    ans = int(ans)
    print(ans)

    for rr in range(r-1, r+2):
        for cc in range(c-1, c+len+1):
            print(rr, cc)
            if inBounds(rr, cc) and isSymbol(data[rr][cc]):
                return ans
            
    return 0

sum = 0

for x, row in enumerate(data):
    for y, col in enumerate(row):
        if not data[x][y].isnumeric():
            continue
        if y > 0 and data[x][y-1].isnumeric():
            continue 
        num = solve(x, y)
        sum += num

print(sum)




