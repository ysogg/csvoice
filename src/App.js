import React, {useEffect, useState} from "react";
import logo from './burger.gif';
import './App.css';

const tf = require('@tensorflow/tfjs');
const speechCommands = require('@tensorflow-models/speech-commands');

const axios = require('axios');

//Doesn't work well
// const sendPost = async (url, post) => {
//   await axios.post(url, {
//     cmd: post,
//     timeout: 2
//   })
// }


const App = () => {
  // States //
  const [model, setModel] = useState(null)
  const [action, setAction] = useState(null)
  const [labels, setLabels] = useState(null)
  var lastAction;
  //2: down, 6: go, 9: no, 11: right, 14: stop, 17: up, 18: yes
  //left right, down (crouch), and then stop / go for forward
  //shoot by either determine mouse1_pressed or rebinding shoot ingame

  // Recog //
  const loadModel = async () => {
    const recogniser = await speechCommands.create("BROWSER_FFT")
    console.log('Model Loaded')
    await recogniser.ensureModelLoaded();
    console.log(recogniser.wordLabels())
    setModel(recogniser)
    setLabels(recogniser.wordLabels())
  }

  useEffect(()=>{loadModel()}, []);

  function argMax(arr) {
    return arr.map((x, i) => [x, i]).reduce((r, a) => (a[0] > r[0] ? a : r))[1];
  }

  // Listener //
  const recogniseCommands = async () => {
    console.log('Listening for commands')
    model.listen(result=>{
      console.log(result)
      setAction(labels[argMax(Object.values(result.scores))])
    }, {includeSpectogram:true, probabilityThreshold:0.9})
  }


  // Stop //
  const stopModel = async () => {
    model.stopListening()
  }


// //MACRO STUFF
//Some of the commands get hung up, try implementing a thing that cancels any in progress posts.
if (action === "look") {
  lastAction = "look";
} else if (lastAction === "look") {
  switch (action) {
    case "up":

    break;
    case "down":

    break;
    case "left":

    break;
    case "right":

    break;
  }
} else if (action === "go") {
  lastAction = "go";
  //post
} else if (action === "stop") {
  lastAction = "stop";
  //post
}


if (action === "go") {
    axios.post('/express_backend', {cmd: 'go'}, {timeout: 100}).then(response => {
      console.log(response.data);
    }).catch(err => {
      console.log(err.code);
      console.log(err.message);
      console.log(err.stack);
    });
    // sendPost('/express_backend', 'go'); 

  } else if (action === "stop") {
    axios.post('/express_backend', {cmd: 'stop'}, {timeout: 100}).then(response => {
      console.log(response.data);
    }).catch(err => {
      console.log(err.code);
      console.log(err.message);
      console.log(err.stack);
    });
    // sendPost('/express_backend', 'stop');
  } else {
    
  }


  return (
    <div className="App">
      <header className="App-header">
        <img src={logo} className="App-logo" alt="logo" />
        <h1>
          Really cool voice recognition
        </h1>
        <button onClick={recogniseCommands}>Start</button>
        {action ? <div>{action}</div>:<div>No Action</div>}
        <button onClick={stopModel}>Stop</button>
      </header>
    </div>
  );
}

export default App;

