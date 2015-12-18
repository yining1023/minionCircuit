/*
  var socket = require('socket.io-client')('http://localhost');
  socket.on('connect', function(){});
  socket.on('event', function(data){});
  socket.on('disconnect', function(){});
*/

var SerialPort = require("serialport");
// var serialPort = new SerialPort.SerialPort("/dev/cu.usbmodem1411", {
var serialPort = new SerialPort.SerialPort("/dev/cu.LightBlue-Bean", {
  baudrate: 9600, parser: SerialPort.parsers.readline("\n")
});

serialPort.on("open", function () {
  console.log('open');

  // serialPort.on('data', function(data) {
  //     console.log(data.toString());
  //     socket.emit('sensor',data.toString());
  //   });

  var socket = require('socket.io-client')('http://45.55.228.139:1025');
  socket.on('connect', function(){
  	 console.log("Socket COnnected");

	  serialPort.on('data', function(data) {
	    console.log('data received: ' + data);
	    socket.emit('sensor',data.toString());
	  });
  });
});