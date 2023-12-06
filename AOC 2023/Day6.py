filepath = "data6.txt"

f = open(filepath, 'r')
data = f.read()
f.close()

def partone(data):
    a = 1 # +1 mm/s
    result = 1

    time, dist = data.split("\n")[0][11:].split(), data.split("\n")[1][11:].split()
    for count, race in enumerate(time): # for each race
        t = int(race) # max time
        ways = 0

        for i in range(t+1): # for each tick of time
            s = a*(t - i) * i # a*t + u = v 
            if s > int(dist[count]):
                ways += 1
        print(t, dist[count], ways)
        result *= ways
    print(result)

def quadFormula(a, b, c):
    # x = (-b +- sqrt(b^2 - 4ac))/2a
    return (-b/(2*a) + ((b*b - 4*a*c) ** 0.5)/(2*a), -b/(2*a) - ((b*b - 4*a*c) ** 0.5)/(2*a))

def parttwo(data):
    time, dist = data.split("\n")[0][11:].replace(' ',''), data.split("\n")[1][11:].replace(' ','')
    # s = (t-i)*i, i*i - t*i + s
    x1, x2 = quadFormula(1, -int(time), int(dist))
    print(x1, x2, x1-x2)

partone(data)
parttwo(data)