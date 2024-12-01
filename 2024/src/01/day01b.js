const fs = require("fs");

lefties = [];
righties = [];
// Open the file and read it line by line
fs.readFile("input/day01.in", "utf8", (err, data) => {
  if (err) throw err;
  const lines = data.split("\n");
  lines.forEach((line) => {
    let parts = line.trim().split();
    let [l, r] = parts[0].split("  ").map(Number);
    lefties.push(l);
    righties.push(r);
  });

  // Process
  let result = 0;
  lefties.forEach((l) => {});
  lefties.forEach((l) => {
    const count = righties.filter((r) => r === l).length;
    result += count * l;
  });
  console.log(result);
});
