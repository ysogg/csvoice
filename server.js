const express = require ('express');
const server = express();
const port = process.env.PORT || 5000;

const macro = require('./build/Release/macro.node');

const jumpReturn = macro.jumpUp();
const goReturn = macro.goForward();

server.listen(port, () => console.log('Listening on port', port));

server.use(express.urlencoded({extended: true}))

server.use(express.json())

server.post('/express_backend', (req, res) => {
    console.log(req.body.cmd);
    switch(req.body.cmd) {
        case 'up':
        break;
        case 'down':
        break;
        case 'left':
        break;
        case 'right':
        break;
        case 'shoot':
        break;
        case 'spray':
        break;
        case 'stop':
            macro.stopMovement();
            console.log("Stopped")
        break;
        case 'jump':
            macro.jumpUp();
            console.log("Jumped");
        break;
        case 'go':
            macro.goForward();
            console.log("Executed: go");
        break;
    }

    
});