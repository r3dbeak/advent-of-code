import re

pattern = re.compile(r"mul\((\d+),(\d+)\)")

result = 0
with open("input/day03.in", "r") as file:
    for line in file:
        for match in pattern.finditer(line):
            result += int(match[1]) * int(match[2])
print(result)
