import React, {useEffect, useState} from "react";
import logo from './burger.gif';
import './App.css';

const tf = require('@tensorflow/tfjs');
const speechCommands = require('@tensorflow-models/speech-commands');

const axios = require('axios');
var lastAction = ""; // used for debug

const App = () => {
  // States //
  const [model, setModel] = useState(null)
  const [action, setAction] = useState(null)
  const [labels, setLabels] = useState(null)
  /* Available words: 
  * 1-9, up, down, left, right, yes, no, go, stop
  */

  // Recog //
  const loadModel = async () => {
  //   const recogniser = await speechCommands.create(
  //   'BROWSER_FFT', 
  //   null,
  //   'file://./model/my-model.json',
  //   'file://./model/metadata.json'
  // ); -> This should load a custom model but it does not `\_O_/`

    const recogniser = await speechCommands.create("BROWSER_FFT");
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
      console.log(action);
    }, {includeSpectogram:true, probabilityThreshold:0.9})
  }


  // Stop //
  const stopModel = async () => {
    model.stopListening()
  }


  // MACRO STUFF //
  if (action === "go") {
    lastAction = "go";
    axios.post('/express_backend', {cmd: 'go'}, {timeout: 100}).then(response => {
      console.log(response.data);
    }).catch(err => {
      console.log(err.code);
      console.log(err.message);
      console.log(err.stack);
    }); 
  } 
  
  else if (action === "stop") {
    lastAction = "stop";
    axios.post('/express_backend', {cmd: 'stop'}, {timeout: 100}).then(response => {
      console.log(response.data);
    }).catch(err => {  
      console.log(err.code);
      console.log(err.message);
      console.log(err.stack);
    });
  } 
  
  else if (action === "left") { 
    lastAction = "left";
    axios.post('/express_backend', {cmd: 'left'}, {timeout: 100}).then(response => {
      console.log(response.data);
    }).catch(err => {
      console.log(err.code);
      console.log(err.message);
      console.log(err.stack);
    });
  } 
  
  else if (action === "right") {
    lastAction = "right";
      axios.post('/express_backend', {cmd: 'right'}, {timeout: 100}).then(response => {
        console.log(response.data);
      }).catch(err => {
        console.log(err.code);
        console.log(err.message);
        console.log(err.stack);
      }); 
  } 
  
  else if (action === "yes") {
    lastAction = "yes";
    axios.post('/express_backend', {cmd: 'shoot'}, {timeout: 100}).then(response => {
      console.log(response.data);
    }).catch(err => {
      console.log(err.code);
      console.log(err.message);
      console.log(err.stack);
    }); 
  }

  else if (action === "up") {
    lastAction = "up";
    axios.post('/express_backend', {cmd: 'jump'}, {timeout: 100}).then(response => {
      console.log(response.data);
    }).catch(err => {
      console.log(err.code);
      console.log(err.message);
      console.log(err.stack);
    }); 
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

