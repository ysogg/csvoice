# csvoice
Uses TensorFlow.js voice recognition to capture and recognise input (ripped from https://www.youtube.com/watch?v=wzWcaLkCy1w).

Recognised input then executes different macros for moving and such to play CSGO

### RUNNING
- node server.js (backend)
- npm start (frontend react app)

# Notes
**Some known issues:**
>Sometimes commands will execute twice. This is due to the recogniser not having a delay / needing to be tuned better resulting in doubled output

>A command can not be called more than twice in a row. I think there's some filter on the recogniser that weeds out garbage input by setting the third consecutive same input to null. Say "stop" or another command to reset this filter.

>Occasionally when the input is "go" the go command will execute but not have an effect in game. To fix this just refresh the browser and maybe restart the server (this usually fixes the problem).

