filepath = "data4.txt"

f = open(filepath, 'r')
data = f.read()
f.close()

def partone(data):
    cards = data.split('\n')
    divider = cards[0].index('|')

    sum = 0
    for i, card in enumerate(cards):
        nums = []
        score = 0
        
        for j in range(10, divider-1, 3):
            nums.append(int(card[j:j+2]))
        
        for k in range(divider + 2, len(cards[0]), 3):
            number = card[k:k+2]
            if int(number) in nums and score != 0:
                score *= 2
            elif int(number) in nums:
                score = 1
        sum += score
    print(sum)

def parttwo(data):
    cards = data.split('\n')
    divider = cards[0].index('|')
    cards_stored = {}

    for i, card in enumerate(cards):
        if i+1 not in cards_stored.keys():
            cards_stored[i+1] = 1
        else:
            cards_stored[i+1] += 1

        nums = []
        for j in range(10, divider-1, 3): # change to 10 later
            nums.append(int(card[j:j+2]))

        matching = 0
        for k in range(divider + 2, len(cards[0]), 3): # match
            number = card[k:k+2]
            if int(number) in nums:
                matching += 1

        for l in range(i+2,matching+i+2):
            if l not in cards_stored.keys():
                cards_stored[l] = cards_stored[i+1]
            else:
                cards_stored[l] += cards_stored[i+1]
        
    total = 0
    for c in cards_stored.keys():
        total += cards_stored[c]
    print(total)

partone(data)
parttwo(data)