#pre-processing
file = open("aoc22day1.txt",'r')
data = file.read()
file.close()

elves = data.split("\n\n")
calories = []
for elf in elves:
  calorie = elf.split("\n")
  calories.append(calorie)
  
#solution
e = []
for elf in calories:
  sum = 0
  for food in elf:
    sum += int(food)
  e += [int(sum)] #sum up and enter calories into e array for every new elf
  
mostCal = 0
for i in range(3): #find the top three values
  mostCal += max(e) #get the maximum from list
  e.pop(e.index(max(e))) #remove the maximum from list and repeat

print(mostCal)
