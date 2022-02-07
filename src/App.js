import React, {useEffect, useState} from "react";
import logo from './burger.gif';
import './App.css';

const tf = require('@tensorflow/tfjs');
const speechCommands = require('@tensorflow-models/speech-commands');

const axios = require('axios');


const App = () => {
  // States //
  const [model, setModel] = useState(null)
  const [action, setAction] = useState(null)
  const [labels, setLabels] = useState(null)
  var lastAction;
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
    }, {includeSpectogram:true, probabilityThreshold:0.9})
  }


  // Stop //
  const stopModel = async () => {
    model.stopListening()
  }


  // MACRO STUFF //
  //Some of the commands get hung up, try implementing a thing that cancels any in progress posts.
  //If I say go and then up do a crouch jump otherwise everything else is single words
  //"two" will toggle shift walk
  if (action === "up" && lastAction === "go") {
    //Jump up
  } else if (action === "up" && lastAction !== "go") {
    //Look up
  } else if (action === "go") {
    lastAction = "go";
    axios.post('/express_backend', {cmd: 'go'}, {timeout: 100}).then(response => {
      console.log(response.data);
    }).catch(err => {
      console.log(err.code);
      console.log(err.message);
      console.log(err.stack);
    }); 
  } else if (action === "stop") {
    lastAction = "stop";
    axios.post('/express_backend', {cmd: 'stop'}, {timeout: 100}).then(response => {
      console.log(response.data);
    }).catch(err => {  
      console.log(err.code);
      console.log(err.message);
      console.log(err.stack);
    });
  } else if (action === "left") { 
    lastAction = "left";
      axios.post('/express_backend', {cmd: 'left'}, {timeout: 100}).then(response => {
        console.log(response.data);
      }).catch(err => {
        console.log(err.code);
        console.log(err.message);
        console.log(err.stack);
      });
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

