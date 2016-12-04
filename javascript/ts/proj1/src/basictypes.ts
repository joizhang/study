//Boolean
let isDone: boolean = false;

//Number
let decimal: number = 6;
let hex: number = 0xf00d;
let binary: number = 0b1010;
let octal: number = 0o744;

//String
let color: string = "blue";
color = 'red';

let fullName: string = `Bob Bobbington`;
let age: number = 37;
let sentence: string = `Hello, my name is ${fullName}
I'll be ${age + 1} years old next month`;
console.log(sentence);

//Array
let list: number[] = [1, 2, 3];
let list1: Array<Number> = [1, 2, 3];

//Tuple
let x: [string, number];

x = ["hello", 10];
// Initialize it incorrectly
//x = [10, "hello"]; // Error 
console.log(x[0].substr(1)); // OK
//console.log(x[1].substr(1)); // Error, 'number' does not have 'substr'

x[3] = "world"; // OK, 'string' can be assigned to 'string | number'
console.log(x);
//Cannot read property 'toString' of undefined
//console.log(x[5].toString());
console.log(x);


//enum
enum Color{Red, Green, Blue};
let c; Color = Color.Green;

//Any
let notSure: any = 4;
notSure = "Maybe a string instead"
notSure = false;

//Void
function warUser():void {
    console.log("This is my warning message");
}

//NULL and Undefined
let u:undefined = undefined;
let n:null = null;
