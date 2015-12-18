var frownImg;
var minionImg;
var transparentImg;
var normalHeartImg;
var brokenHeartImg;


function setup() {
  // uncomment this line to make the canvas the full size of the window
  createCanvas(windowWidth, windowHeight);
  frownImg = loadImage("images/minionFrown.png");
  minionImg = loadImage("images/croppedMinion.png");
  normalHeartImg = loadImage("images/minionheart.png");
  brokenHeartImg = loadImage("images/brokenheart.png");
}//END OF SETUP


function draw() {
  // draw stuff here
  // ellipse(width/2, height/2, 50, 50);
  rect(1120,20, 25,500);
  

}//END OF DRAW


// function keyPressed(){
// 	if (keyCode===UP_ARROW){
// 		//THIS IS THE SMILING MINION
// 		image(minionImg,-50,0);
// 		//THIS IS THE NORMAL HEART
// 		image(normalHeartImg, 715, 355, normalHeartImg.width/10, normalHeartImg.height/10);
// 		console.log("UP");


// 	}

// 	if (keyCode===LEFT_ARROW){
// 		//THIS IS THE FROWN
// 		image(frownImg,195,400);
// 		//THIS IS THE BROKEN HEART
// 		image(brokenHeartImg, 715, 355, brokenHeartImg.width/10, brokenHeartImg.height/10);
// 	} 
// }

	var socket = io.connect('http://159.203.65.5:1025/');

	socket.on('connect', function() {
		console.log("Connected");

		//socket.emit('hello',"blah blahb blah");
		//console.log("sent hello");

	});

	// var context;
	// var count = 0;

	socket.on('sensor', function(data) {
		// console.log(data);
		if(data == 1){
			// console.log("circuit is complete.");
			image(minionImg,-50,0);
			//THIS IS THE NORMAL HEART
			image(normalHeartImg, 715, 355, normalHeartImg.width/10, normalHeartImg.height/10);
		}
		else if(data == 0){
			// console.log("circuit is broken.");
			image(frownImg,195,400);
			//THIS IS THE BROKEN HEART
			image(brokenHeartImg, 715, 355, brokenHeartImg.width/10, brokenHeartImg.height/10);
		}
		// context.clearRect(0,0,600,600);
		// context.fillRect(100, 100, data,data);
	});

