n, m, d = [int(x) for x in input().split()]
break_time = [int(x) for x in input().split()]

break_sorted = set(break_time)

# print(break_sorted)

day = 1

def find_index(br, target):
  high = len(br)-1
  low = 0
  ans = -1
  while low<=high:
    mid = (low+high) // 2

    if br[mid][0] >= target:
      low = mid+1
      if br[mid][1] == False:
        ans = mid
    else:
      high = mid-1
  return ans

dayinfo = {}
found_today = False

x = break_sorted[0]
break_sorted.remove(x)

while len(break_sorted) > 0:
  '''if break_sorted[-1][1]:
    break_sorted.pop()
    continue'''
  # x = break_sorted[-1][0]
  target = x + d + 1

  val = find_index(break_sorted, target)

  print(x, val, target)
  print(break_sorted)

  if val == -1:
    day += 1
    x = break_sorted[0]
    dayinfo[x] = day
    break_sorted.remove(x)
  else:
    # dayinfo[break_sorted[-1][0]] = day
    dayinfo[break_sorted[idx]] = day
    # foundToday = True
    # print(break_sorted[idx])
    while len(break_sorted)>0 and break_sorted[-1][1]:
      break_sorted.pop()
    if len(break_sorted) == 0:
      break
    x = break_sorted[idx][0]
    break_sorted[idx][1] = True

print(day-1)
for i in break_time:
  print(dayinfo[i], end=" ")
