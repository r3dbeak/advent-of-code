lefties = []
righties = []

# Read input
with open("input/day01.txt", "r") as file:
    for line in file:
        parts = line.strip().split()
        l, r = map(int, parts)
        lefties.append(l)
        righties.append(r)

# Process
lefties.sort()
righties.sort()
result = sum(abs(l - r) for l, r in zip(lefties, righties))
print(result)
