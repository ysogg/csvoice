const macro = require('./src/build/Release/macro.node');


console.log('exported: ', macro);

console.log('exports: ', macro.greetHello());
console.log('exports: ', macro.stopMovement());