const height = prompt('Height?'); // prompt only run on browser so run html file on browser instead of running with nodejs.

draw(height);

function draw(number) {
  if (number <= 0) return;

  draw(number - 1);

  let arr = [];
  for (let i = 0; i < number; i++) {
    arr.push('#');
  }

  console.log(arr);
}
