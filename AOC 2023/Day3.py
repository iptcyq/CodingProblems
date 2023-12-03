filepath = "data3.txt"

f = open(filepath, 'r')
data = f.read()
f.close()

def getaround(coords, bounds):
    dirs = [(-1,-1), (0,-1), (1,-1), (-1,0), (1,0), (-1,1), (0,1), (1,1)]
    around = []
    for dir in dirs:
        if 0 <= coords[0]+dir[0] < bounds[0] and 0<= coords[1]+dir[1] < bounds[1]:
            around.append((coords[0]+dir[0], coords[1]+dir[1]))
    return around

def partone(data):
    symbols = "!@#$%^&*()_+~`-=[]/?" # not sure if this includes all symbols

    rows = data.split("\n")
    bounds = (len(rows), len(rows[0])) # outer bounds of schematic

    around = []
    # get coords included
    for y, row in enumerate(rows):
        for x, char in enumerate(row): # look for symbol
            if char in symbols:
                coords = (x,y)
                all = getaround(coords, bounds)
                for coord in all: # check if its a number
                    if rows[coord[1]][coord[0]].isnumeric(): 
                        around.append(coord)

    # convert numbers into dict that are assigned to coords included
    sum = 0
    for y, row in enumerate(rows):
        num = "0"
        for x, char in enumerate(row):
            if char.isnumeric(): # is a number
                num += char
            elif num != "0": # new number ended
                digits = len(num) # number of digits
                for i in range(x-digits, x): # coords
                    if (i, y) in around and num != "0": # add number
                        sum += int(num)
                        num = "0"
                num = "0"
            
        if num != "0": # ended with a number
            digits = len(num)
            x = len(row)
            for i in range(x-digits, x): 
                if (i, y) in around and num != "0": 
                    sum += int(num)
                    num = "0"
            num = "0"
        
    print(sum) 
        
def parttwo(data):
    # A gear is any * symbol that is adjacent to exactly two part numbers.
    rows = data.split("\n")
    bounds = (len(rows), len(rows[0]))
    gears = {}

    for y, row in enumerate(rows):
        for x, char in enumerate(row):
            gearcoords = []
            if char == '*': # a gear
                gears[(x,y)] = [] # gears dict stores numbers

    # for each number found
    # if number found in coord
    for y, row in enumerate(rows):
        num = "0"
        for x, char in enumerate(row):
            if char.isnumeric(): # is a number
                num += char
            elif num != "0": # end of a number
                digits = len(num)-1
                for gearcoords in gears.keys(): # all gears
                    around = getaround(gearcoords,bounds)
                    for i in range(x-digits, x):
                        if (i,y) in around and num!="0": # coords found
                            gears[gearcoords].append(int(num))
                            num = "0"
                num = "0"
        
        if num != "0": # end of a number
            digits = len(num)-1
            for gearcoords in gears.keys(): # all gears
                around = getaround(gearcoords,bounds)
                for i in range(x-digits, x):
                    if (i,y) in around and num!="0": # coords found
                        gears[gearcoords].append(int(num))
                        num = "0"
            num = "0"

    # multiply both for gear ratio
    sum = 0
    for gearcoords in gears.keys():
        if len(gears[gearcoords]) == 2: # exactly 2 numbers
            ratio = gears[gearcoords][0]*gears[gearcoords][1]
            sum += ratio
    print(sum)

# partone(data)
parttwo(data)