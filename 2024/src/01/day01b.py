lefties = []
righties = []

# Read input
with open("input/day01.in", "r") as file:
    for line in file:
        parts = line.strip().split()
        l, r = map(int, parts)
        lefties.append(l)
        righties.append(r)

# Process
result = sum(righties.count(l) * l for l in lefties)
print(result)
