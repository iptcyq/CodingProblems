filepath = "data1.txt"

f = open(filepath, 'r')
data = f.read()
f.close()

def partone(data):
    sortd = ""
    for char in data:
        if char == "\n" or char.isnumeric():
            sortd += char

    sum = 0
    for line in sortd.split('\n'):
        sum += int(line[0] + line[-1])
        # print(int(line[0] + line[-1]))

    print(sum)

def parttwo(data): # not done - this is frustrating
    single = ["zero","one", "two","three","four","five","six","seven","eight","nine"]

    sum = 0
    for line in data.split('\n'):
        counter, firstnum = 0, "a"
        while firstnum.isalpha() and counter < len(line):
            firstnum += line[counter]
            for num in single:
                if num in firstnum:
                    firstnum = firstnum.replace(num, str(single.index(num)))
            counter += 1
            # print(firstnum)
            
        for char in firstnum:
            if char.isnumeric():
                firstnum = char

        counter, lastnum = len(line)-1, "a"
        while lastnum.isalpha() and counter >= 0:
            lastnum = line[counter] + lastnum
            for num in single:
                if num in lastnum:
                    lastnum = lastnum.replace(num, str(single.index(num)))
            counter -= 1
            # print(lastnum)
            
        for char in lastnum:
            if char.isnumeric():
                lastnum = char

        sum += int(firstnum + lastnum)

    print(sum)

partone(data)
parttwo(data)
