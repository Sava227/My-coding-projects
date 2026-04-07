//variables
let num1 = 4;
let num2 = 3;
const num3 = 2.5;
const num4 = -1.5;

const myVar = 'A String';
const myVar2 = 'Another String';

//basic math
console.log(num1 + num2);
console.log(num1 - num2);
console.log(num1 * num2);
console.log(num1 / num2);

//floating point inaccuracy
console.log(0.1 + 0.2);
console.log(0.2 + 0.4);

//other operations
console.log(13 % 5);
console.log(4 % 2);
console.log(2 ** 2); //** makes the number in power of something

//increment and decrement
// num = num1 + 1;
// num1++;
// num1 = num1 + 2;
// num1 += 2;
// num = num1 - 1
// num1--;

//booleans
console.log(num1 > num2);
console.log(num1 >= num2);
console.log(num1 < num2);
console.log(num1 <= num2);
console.log(num1 == num2);
console.log(num1 === num2);
console.log(num1 != num2);
console.log(num1 !== num2);

// NaN
console.log(num1 * 'A string');

//infinity
console.log(9_000_000 ** 9_000_000);
console.log(Number.NEGATIVE_INFINITY);

//Math object
console.log(Math.PI);
console.log(Math.sqrt(25));
console.log(Math.pow(2, 3));
console.log(Math.round(6.6));
console.log(Math.ceil(6.3));
console.log(Math.floor(6.7));

//converting
console.log(myVar + myVar2);
console.log(myVar + num1);

//string to number
console.log(parseInt(('2') + 2));

//number to string
console.log(2 + '');
console.log(`${2}`);

//big int
let maxInt = BigInt(Number.MAX_SAFE_INTEGER);
console.log(maxInt);
maxInt++;
console.log(maxInt);
maxInt++;
console.log(maxInt);

let bigNumber = 9007199254740993n;
bigNumber = bigNumber * 4n;
console.log(bigNumber);
