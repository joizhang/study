//Boolean
var isDone = false;
//Number
var decimal = 6;
var hex = 0xf00d;
var binary = 10;
var octal = 484;
//String
var color = "blue";
color = 'red';
var fullName = "Bob Bobbington";
var age = 37;
var sentence = "Hello, my name is " + fullName + "\nI'll be " + (age + 1) + " years old next month";
console.log(sentence);
//Array
var list = [1, 2, 3];
var list1 = [1, 2, 3];
//Tuple
var x;
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
var Color;
(function (Color) {
    Color[Color["Red"] = 0] = "Red";
    Color[Color["Green"] = 1] = "Green";
    Color[Color["Blue"] = 2] = "Blue";
})(Color || (Color = {}));
;
var c;
Color = Color.Green;
//Any
var notSure = 4;
notSure = "Maybe a string instead";
notSure = false;
//Void
function warUser() {
    console.log("This is my warning message");
}
//NULL and Undefined
var u = undefined;
var n = null;
