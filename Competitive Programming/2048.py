# Given a 4x4 2048 puzzle (which is in a valid state)
# Produce the new state of the puzzle when the user
# performs a certain move
def solver(puzzle,move):
    # Make a left move
    if move == 0:
       c = len(puzzle)-1
       while c > 0:
            for r in range(len(puzzle)):
               if puzzle[r][c-1] == puzzle[r][c] or puzzle[r][c-1] == 0:
                   puzzle[r][c-1] += puzzle[r][c]
                   puzzle[r][c] = 0
                   if c < len(puzzle)-1:
                       if puzzle[r][c+1] != 0:
                           puzzle[r][c] = puzzle[r][c+1]
                           puzzle[r][c+1] = 0
            c = c-1


    # Make an up move
    if move == 1:
       r = len(puzzle)-1
       while r > 0:
            for c in range(len(puzzle)):
               if puzzle[r-1][c] == puzzle[r][c] or puzzle[r-1][c] == 0:
                   puzzle[r-1][c] += puzzle[r][c]
                   puzzle[r][c] = 0
                   x = 0
                   while x > len(puzzle)-1:
                       if puzzle[x][c] == 0:
                            puzzle[x][c] = puzzle[x+1][c]
                            puzzle[x+1][c] = 0
                       x = x+1
            r = r-1
    # Make a right move
    if move == 2:
       c = 0
       while c < len(puzzle)-1:
            for r in range(len(puzzle)):
               if puzzle[r][c+1] == puzzle[r][c] or puzzle[r][c+1] == 0:
                   puzzle[r][c+1] += puzzle[r][c]
                   puzzle[r][c] = 0
                   x = 0
                   while x < c:
                       print(x)
                       if puzzle[r][x] != 0 and puzzle[r][x+1]==0:
                            puzzle[r][x+1] = puzzle[r][x]
                            puzzle[r][x] = 0
                       x = x+1
            c = c+1

            
    
    
puzzle1 = [[2,0,0,2],[4,16,8,2],[2,64,32,4],[1024,1024,64,0]]
solver(puzzle1,1)
print(puzzle1)
