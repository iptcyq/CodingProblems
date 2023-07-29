#pre-processing
file = open("aoc22day2.txt",'r')
data = file.read()
file.close()

round = data.split("\n")
decisions = []
for r in round:
  decisions.append(r.split(" "))

#decisions = [["C","X"],["A","Y"],["B","X"],["C","Z"]]
#solution
ref = ['X','A','Y','B','Z','C']
points = 0

for round in decisions:
  opp, plyr = round
  o, p = ref.index(opp), ref.index(plyr)
  if (o == 5 and p == 0):
    #avoid winning edge case
    points += 6
  elif (p-o)==1:
    #win
    points += 6
  elif (o-p)==1:
    #draw
    points += 3
  
  if p == 0:
    points += 1
  elif p==2:
    points +=2
  else:
    points += 3
    
print(points)