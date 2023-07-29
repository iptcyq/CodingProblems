#pre-processing
file = open("aoc22day2.txt",'r')
data = file.read()
file.close()

round = data.split("\n")
decisions = []
for r in round:
  decisions.append(r.split(" "))

ref = ['X','A','Y','B','Z','C']
points = 0

#mild bruteforce
for round in decisions:
  opp, s = round
  o= ref.index(opp)
  p=0
  if s == 'X':
    #lose
    p = o-3
  elif s == 'Z':
    #win
    p = o+1
    points += 6
  elif s=='Y':
    #draw
    p = o-1
    points += 3

  if p>5:
    p -= 6
  elif p<0:
    p+=5
    
  if p == 0:
    points += 1
  elif p==2:
    points +=2
  else:
    points += 3
    
print(points)