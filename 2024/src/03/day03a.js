const fs = require("fs");

fs.readFile("input/day03.in", "utf8", (err, data) => {
  let result = 0;
  const pattern = /mul\((\d+),(\d+)\)/g;
  const lines = data.split("\n");
  lines.forEach((line) => {
    const matches = line.matchAll(pattern);
    for (const match of matches) {
      result += Number(match[1]) * Number(match[2]);
    }
  });
  console.log(result);
});
