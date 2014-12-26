// Load required modules
var http    = require("http");              // http server core module
var express = require("express");           // web framework external module
var io      = require("socket.io");         // web socket external module

var httpApp = express();
httpApp.use(express.static(__dirname + "/static/"));

var webServer = http.createServer(httpApp).listen(3000);
console.log('listening on *:3000');

var socketServer = io.listen(webServer, {"log level":1});

socketServer.on('connection', function(socket){
  console.log('a user connected');
  socket.on('disconnect', function(){
    console.log('user disconnected');
  });

  socket.on('angle', function(msg){
    console.log('message: ' + msg);
  });
});

var SerialPort = require("serialport").SerialPort
var serialPort = new SerialPort("/dev/ttyACM0", {
  baudrate: 9600
});

serialPort.on("open", function () {
  console.log('open');

  serialPort.on('data', function(data) {

  	
  	var encoded = new Buffer(data, 'binary').toString('utf8');
  	socketServer.emit('radarData', encoded);
  	console.log('data is ' +encoded);
  	//var arr = encoded.split(",");
  	//console.log('Distance : ' + arr[0]);
    //console.log('Angle : '+ arr[1]);
  });
  serialPort.write("ls\n", function(err, results) {
    console.log('err ' + err);
    console.log('results ' + results);
  });
});