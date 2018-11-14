from collections import deque

n = int(input())
inp = input()
k1 = int(inp[0])
p1 = [int(x) for x in inp.split()[1:]]
inp = input()
k2 = int(inp[0])
p2 = [int(x) for x in inp.split()[1:]]


player1 = deque(p1)
player2 = deque(p2)

# fight_map = [[0 for _ in range(n+1)] for __ in range(n+1)]
winnable = False
counter = 0

while counter < 1000:
    try:
        card1 = player1.popleft()
        card2 = player2.popleft()

        # print(f"{card1} {card2}")
    except IndexError:
        # one of the stack is empty
        winnable = True
        break

    if card1 > card2:
        # player 1 wins

        # add player2's card to player1's stack
        player1.append(card2)
        # add player1's card to player1's stack
        player1.append(card1)
    else:
        # player 2 wins

        player2.append(card1)
        player2.append(card2)

    # fight_map[card1][card2] = 1
    counter += 1

if not winnable:
    print(-1)
else:
    try:
        player1.pop()
    except IndexError:
        print(f"{counter} 2")
    try:
        player2.pop()
    except IndexError:
        print(f"{counter} 1")