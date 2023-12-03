filepath = "data2.txt"

f = open(filepath, 'r')
data = f.read()
f.close()

def partone(data):
    # 12 red cubes, 13 green cubes, and 14 blue cubes
    all = {"red":12, "green":13, "blue":14}
    possible = True
    solution = 0

    games = data.split("\n")
    for i, game in enumerate(games): # each possible game
        if i+1 <= 9: # one digit game
            instances = game[7:].split(";")
        elif i+1 <= 99: # two digit game
            instances = game[8:].split(";")
        else: # three digit game
            instances = game[9:].split(";")
        
        for instance in instances: # each instance in a game
            for item in instance.split(","):
                num, colour = item[1:].split(" ")
                if all[colour] < int(num): # impossible game
                    possible = False
        print(i, possible)
        if possible:
            solution += 1+i
        possible = True

    print(solution)

def parttwo(data):
    games = data.split("\n")
    solution = 0

    for i, game in enumerate(games): # each possible game
        all = {"red":0, "green":0, "blue":0}

        if i+1 <= 9: # one digit game
            instances = game[7:].split(";")
        elif i+1 <= 99: # two digit game
            instances = game[8:].split(";")
        else: # three digit game
            instances = game[9:].split(";")

        for instance in instances: # each instance in a game
            for item in instance.split(","):
                num, colour = item[1:].split(" ")
                if all[colour] < int(num): # impossible game
                    all[colour] = int(num)
    
        power = all["red"] * all["green"] * all["blue"]
        print(i, power)
        solution += power

    print(solution)

partone(data)
parttwo(data)