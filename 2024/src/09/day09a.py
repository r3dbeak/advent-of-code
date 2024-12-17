# Read data
with open("input/day09.in") as file:
    numbers = [int(num) for num in file.read()]
    memory = [
        [idx // 2 if idx % 2 == 0 else "." for i in range(num)]
        for idx, num in enumerate(numbers)
    ]
    memory = [num for sublist in memory for num in sublist]

# Iterate through memory from front and back
front = 0
back = len(memory) - 1
while front != len(memory) - 1:
    if memory[front] == ".":  # first candidate for swap found
        while memory[back] == ".":
            back -= 1
        if front < back:
            memory[front], memory[back] = memory[back], memory[front]
    front += 1
# Calculate checksum
memory
checksum = sum([idx * num for idx, num in enumerate(memory) if num != "."])
print(checksum)
