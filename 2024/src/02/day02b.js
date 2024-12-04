const fs = require("fs");

let valids = 0;
fs.readFile("input/day02.in", "utf8", (err, data) => {
  if (err) throw err;
  const lines = data.split("\n");
  lines.forEach((line) => {
    numbers = line.trim().split(/[\s,]+/);
    if (isSafe(numbers)) valids++;
    else {
      // Try removing any number and check if its safe
      for (let i = 0; i < numbers.length; i++) {
        let numbersAlt = numbers.slice();
        numbersAlt.splice(i, 1);
        if (isSafe(numbersAlt)) {
          valids++;
          break;
        }
      }
    }
  });
  console.log(valids);
});

function isSafe(numbers) {
  let dx = [];
  for (let i = 0; i < numbers.length - 1; i++) {
    dx.push(numbers[i + 1] - numbers[i]);
  }
  let incValid = true;
  let decValid = true;
  for (let i = 0; i < dx.length; i++) {
    if (dx[i] < 1 || dx[i] > 3) incValid = false;
    if (dx[i] > -1 || dx[i] < -3) decValid = false;
  }
  return incValid || decValid;
}
