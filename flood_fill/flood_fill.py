with open(0) as file:
    lines = file.readlines()

def print_grid(grid):
    for row in grid:
        print(*row)

grid = []
for line in lines:
    if line[-1]=='\n':
        line = line[:-1]
    line = [c for c in line]
    grid.append(line)

symbols = []

def fill(ir,ic):
    directions = [(-1,0),(1,0),(0,-1),(0,1)]
    symbol = grid[ir][ic]
    for dr,dc in directions:
        index_r,index_c = dr+ir, dc+ic
        if grid[index_r][index_c] == '.':
            grid[index_r][index_c] = symbol
            symbols.append((index_r,index_c))

for ir,row in enumerate(grid):
    for ic,col in enumerate(row):
        if col not in '.#':
            symbols.append((ir,ic))
            while symbols:
                fill(*symbols.pop())
print_grid(grid)
