import re

pattern = re.compile(r"mul\((\d+),(\d+)\)|do\(\)|don't\(\)")

result = 0
readInstruction = True
with open("input/day03.in", "r") as file:
    for line in file:
        for match in pattern.finditer(line):
            if match[0] == "don't()":
                readInstruction = False
            elif match[0] == "do()":
                readInstruction = True
            else:
                if readInstruction:
                    result += int(match[1]) * int(match[2])
print(result)
