const fs = require("fs");

fs.readFile("input/day03.in", "utf8", (err, data) => {
  let result = 0;
  let readInstruction = true;
  const pattern = /mul\((\d+),(\d+)\)|do\(\)|don't\(\)/g;
  const lines = data.split("\n");
  lines.forEach((line) => {
    const matches = line.matchAll(pattern);
    for (const match of matches) {
      if (match[0] === "do()") {
        readInstruction = true;
      } else if (match[0] === "don't()") {
        readInstruction = false;
      } else if (readInstruction) {
        result += Number(match[1]) * Number(match[2]);
      }
    }
  });
  console.log(result);
});
