#pre-processing
file = open("aoc22day4.txt",'r')
data = file.read()
file.close()

counter = 0
pairs = data.split("\n");
elves = []
for pair in pairs:
  elves += [pair.split(',')]

for elf in elves:
  elf1 = elf[0].split("-")
  elf2 = elf[1].split("-")

  #if elf1 fully encompasses elf2
  if (int(elf1[0])<=int(elf2[0]) and int(elf1[1])>=int(elf2[1])):
    counter += 1

  #if elf2 fully encompasses elf1
  elif (int(elf2[0]) <= int(elf1[0]) and int(elf2[1])>=int(elf1[1])):  
    counter += 1

print(counter)