const express = require ('express');
const server = express();
const port = process.env.PORT || 5001;

const macro = require('./build/Release/macro.node');


server.listen(port, () => console.log('Listening on port', port));

server.use(express.urlencoded({extended: true}))

server.use(express.json())

server.post('/express_backend', (req, res) => {
    console.log(req.body.cmd);
    switch(req.body.cmd) {
        case 'up':
            macro.jumpUp();
            console.log("Jumped");
        break;
        case 'down':
            macro.crouchDown();
            console.log("Crouched");
        break;
        case 'left':
            macro.lookLeft();
            console.log("Looked left");
        break;
        case 'right':
            macro.lookRight();
            console.log("Looked right");
        break;
        case 'shoot':
            macro.sprayDown(); 
            console.log("Shot");
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
        default:
        break;
    }

    
});