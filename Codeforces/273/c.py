r, g, b = [int(x) for x in input().split()]

counter = 0

mn = min(r, g, b)
counter += mn

nr, ng, nb = r-mn, g-mn, b-mn

mx = max(nr, ng, nb)
other = nr + ng + nb - mx

remain = min(mx//2, other)
counter += remain

if mx%2==1 and other-remain >= 2:
    counter += 1

print(counter)
