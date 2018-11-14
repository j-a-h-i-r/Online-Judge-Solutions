a, b, f, k = [int(x) for x in input().split()]

curpos = 0
possible = True
gas = b
refuelCount = 0

def dis(a, b):
  return abs(a-b)

while k>0:
  if dis(curpos, f) > gas:
    possible = False
    break
  
  dis_to_edge = dis(f, 0) if curpos==a else dis(f, a)

  if k>1 and dis(curpos, f) + dis_to_edge*2 > gas:
    # move to fuel and take gas
    gas -= dis(curpos, f)   # cost to reach f
    # curpos = f              # at 'f' now
    if gas<0:
        possible = False
        break
    gas = b                 # refueling tank
    refuelCount += 1

    # now move to an edge
    gas -= dis_to_edge
    if gas<0:
        possible = False
        break
    curpos = a - curpos
  elif k>1:
    # just move. no take fuel
    curpos = a - curpos
    gas -= a
    if gas<0:
        possible = False
        break
  else:
    # last trip
    if gas >= a:
      curpos = a - curpos
      gas -= a
    elif dis(curpos, f) <= gas:
        refuelCount += 1
        curpos = a - curpos
        gas = b
        gas -= dis(curpos, f)
        if gas < 0:
            possible = False
            break
    else:
        possible = False
        break

  
  # print(6-curpos, "->", curpos, gas, refuelCount)

  if curpos == 0 or curpos == a:
    k -= 1
  
if possible:
  print(refuelCount)
else:
  print(-1)