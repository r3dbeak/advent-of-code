# Read data
with open("input/day09.in") as file:
    numbers = [int(num) for num in file.read()]
    memory = [
        (idx // 2 if idx % 2 == 0 else ".", num) for idx, num in enumerate(numbers)
    ]

for idx in range(len(memory)):
    back = len(memory) - 1 - idx
    front = 0
    if memory[back][0] != ".":
        while front != back:
            if memory[front][0] == "." and memory[front][1] >= memory[back][1]:
                diff = memory[front][1] - memory[back][1]
                memory.insert(front, memory[back])
                memory[back + 1] = (".", memory[back + 1][1])
                memory[front + 1] = (".", diff)
                if memory[front + 1][1] == 0:
                    memory.pop(front + 1)
                break
            front += 1
memory = [[symbol for i in range(num)] for (symbol, num) in memory]
memory = [num for sublist in memory for num in sublist]
check_sum = sum([idx * num for idx, num in enumerate(memory) if num != "."])
print(check_sum)
