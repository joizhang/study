var str = 'He is a boy. This is a dog. Where is she?';

var reg = /\bis\b/;
console.log(str.replace(reg, 'IS'));

//g: global
reg = /\bis\b/g;
console.log(str.replace(reg, 'IS'));

reg = new RegExp('\\bis\\b', 'g');
console.log(str.replace(reg, 'IS'));

//i: ignore case
str = 'He Is a boy. This IS a dog.';
reg = /\bis\b/gi;
console.log(str.replace(reg, 'is'));

//m: multiple lines


//meta symbol
//* + ? $ ^ | \ ( ) { } [ ]


str = 'a1b2c3d4';
reg = /[abc]/g;
console.log(str.replace(reg, 'X'));

reg = /[^abc]/g;
console.log(str.replace(reg, 'X'));


//[a-z]
reg = /[a-z]/g
console.log(str.replace(reg, 'X'));
//[a-zA-Z]
reg = /[a-zA-Z]/g
console.log('A1b2C3d4kljKLJioasnn6'.replace(reg, 'X'));

//[0-9] [0-9-]
console.log('1999-10-10'.replace(/[0-9]/g, 'A'))
console.log('1999-10-10'.replace(/[0-9-]/g, 'A'))