function fact(x) {
  if (x == 1) {
    return 1;
  } else {
    return x * fact(x - 1);
  }
  // 5 * 4 * 3 * 2 * 1
}

console.log(fact(5));

// demonstration
function main(n) {
  // n = 5
  return n * one(n - 1);
}

function one(n) {
  // n = 4
  return n * two(n - 1);
}

function two(n) {
  // n = 3
  return n * three(n - 1);
}

function three(n) {
  // n = 2
  return n * four(n - 1);
}

function four() {
  return 1;
}

console.log(main(5));
