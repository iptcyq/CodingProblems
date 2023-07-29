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

  #attempt 1 - failed, still unsure why
  #if elf1 less than elf2 and overlap
  if (elf1[0] <= elf2[0]): #elf1 before 2
    if (int(elf1[1])>=int(elf2[0])):
      counter += 1
      print(elf1[0],elf1[1],elf2[0],elf2[1])
  #if elf2 less than elf1 and overlap
  elif (elf1[0] >= elf2[0]):
    if int(elf2[1])>=int(elf1[0]):
      counter += 1
      print(elf2[0],elf2[1],elf1[0],elf1[1])

  #attempt 2 - worked but bruteforce
  if int(elf1[0]) in range(int(elf2[0]), int(elf2[1]) + 1) or int(elf1[1]) in range(int(elf2[0]), int(elf2[1]) + 1) or int(elf2[0]) in range(int(elf1[0]), int(elf1[1]) + 1) or int(elf2[1]) in range(int(elf1[0]), int(elf1[1]) + 1):
                                                                                                              
    counter +=1
    
print(counter)