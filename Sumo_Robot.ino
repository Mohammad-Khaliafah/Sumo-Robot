
//right side motors

#define RPWM 7
#define LPWM 6
#define R_EN 2

//left side motors

#define R2PWM 9
#define L2PWM 8
#define R2_EN 3


//infra red sensors
#define ir_right 27

#define ir_left 33

#define ir_front_right 28

#define ir_front_left 31

#define ir_front 30

 
//line followers sensor
#define line_front_right  25

#define line_front_left 29

#define line_back_right 260

#define line_back_left 141


int detect = 0;
int not_detect = 1;

//strategy pins
     
       #define  button1  35
       #define  button2  37
       #define  button3  81
       #define  button4  91
       #define  button5  101
       #define  button6  112


void setup() {

Serial.begin(9600); // Serial Iterface Started at 9600 bps baudrate.


  
  pinMode(R_EN, OUTPUT);
  pinMode(RPWM, OUTPUT);
  pinMode(LPWM, OUTPUT);

  pinMode(R2_EN, OUTPUT);
  pinMode(R2PWM, OUTPUT);
  pinMode(L2PWM, OUTPUT);



pinMode(ir_right, INPUT); 
pinMode(ir_left, INPUT); 
pinMode(ir_front_right, INPUT); 
pinMode(ir_front_left, INPUT); 
pinMode(ir_front, INPUT); 

pinMode(line_front_right, INPUT); 
pinMode(line_front_left, INPUT); 
pinMode(line_back_right, INPUT); 
pinMode(line_back_left, INPUT); 


//Strategy switch
  pinMode(button1,INPUT_PULLUP);
  pinMode(button2,INPUT_PULLUP);
  pinMode(button3,INPUT_PULLUP);
  pinMode(button4,INPUT_PULLUP);
  pinMode(button5,INPUT_PULLUP);
  pinMode(button6,INPUT_PULLUP);
//PIN 52 FOR DELSY


delay(3900); // Delay for 5 Second.



}

void loop() {

searching();
}



/////////////////////////////////////////////////// motors functions /////////////////////////////////////////////////////////////////////////

void forward(int speed){
  /*
  Serial.println("FORWARD =");  
  Serial.println(speed); 
  */

// when speed=s

//right side
  digitalWrite(R_EN, 1 );
  analogWrite(RPWM, speed);
  analogWrite(LPWM, 0);

//left side
  digitalWrite(R2_EN, 1);
  analogWrite(R2PWM, speed);
  analogWrite(L2PWM, 0);
}

void backward(int speed){
 /* Serial.println("BACKWARD =");  
  Serial.println(speed); 
  */
// when speed=s
 
//right side
  digitalWrite(R_EN, 1 );
  analogWrite(RPWM, 0);
  analogWrite(LPWM, speed);

//left side
  digitalWrite(R2_EN, 1);
  analogWrite(R2PWM,0);
  analogWrite(L2PWM, speed);
}

void rotate_r(int rs,int ls){
  
 digitalWrite(R_EN, 1 );
  analogWrite(RPWM, 0);
  analogWrite(LPWM, rs);

//left side
  digitalWrite(R2_EN, 1);
  analogWrite(R2PWM,ls);
  analogWrite(L2PWM, 0);
}

void rotate_l(int ls,int rs){
 
//right side
  digitalWrite(R_EN, 1 );
  analogWrite(RPWM, rs);
  analogWrite(LPWM, 0);

//left side
  digitalWrite(R2_EN, 1);
  analogWrite(R2PWM,0);
  analogWrite(L2PWM, ls);
  
}

void m_left(int s1,int s2){


//right side
  digitalWrite(R_EN, 1 );
  analogWrite(RPWM, s1);
  analogWrite(LPWM, 0);

//left side
  digitalWrite(R2_EN, 1);
  analogWrite(R2PWM,s2);
  analogWrite(L2PWM, 0);

   
}

void m_right(int s1,int s2){


 digitalWrite(R_EN, 1 );
  analogWrite(RPWM, s1);
  analogWrite(LPWM, 0);

//left side
  digitalWrite(R2_EN, 1);
  analogWrite(R2PWM,s2);
  analogWrite(L2PWM, 0);

}


void brake(){

//right side
  digitalWrite(R_EN, 0 );
  analogWrite(RPWM, 0);
  analogWrite(LPWM, 0);

//left side
  digitalWrite(R2_EN, 0);
  analogWrite(R2PWM, 0);
  analogWrite(L2PWM, 0);



}


//////////////////////////////////////////////////////////////// searching function //////////////////////////////////////////////


void searching(){
while (true) {

 
// line follower not detect 
  if(digitalRead(line_front_right)==0 && digitalRead(line_front_left)==0 && digitalRead(line_back_right)==0 && digitalRead(line_back_left)==0 ){

//ir not detect 
  if( digitalRead(ir_front_right)== not_detect && digitalRead(ir_front)== not_detect && digitalRead(ir_front_left)== not_detect && digitalRead(ir_right)== not_detect && digitalRead(ir_left)== not_detect){
   rotate_l(255,255);
    delay(400);
   forward(255);
    delay(200);
   rotate_l(255,255);
    delay(200);

  }

///////////////////////////////////////////////////////////////// front ir ///////////////////////////////////////////////////////////////////////
// 3 ir front detected
  if (digitalRead(ir_front_right)== detect && digitalRead(ir_front)== detect && digitalRead(ir_front_left)== detect && digitalRead(ir_right)== not_detect && digitalRead(ir_left)== not_detect){
    forward(255);
  }

//  ir_front detected
  if (digitalRead(ir_front_right)== not_detect && digitalRead(ir_front)== detect && digitalRead(ir_front_left)== not_detect && digitalRead(ir_right)== not_detect && digitalRead(ir_left)== not_detect ){
    forward(255);
  }
////////////////////////////////////////////////////////////////// right ir /////////////////////////////////////////////////////////////

// right ir side detected  
  if( digitalRead(ir_right)== detect && digitalRead(ir_front_right)== detect  && digitalRead(ir_front)== not_detect  && digitalRead(ir_front_left)== not_detect && digitalRead(ir_left)== not_detect){
    rotate_r(180,180);
  }
  
// wide_right_detect
  if(digitalRead(ir_right)== detect && digitalRead(ir_front_right)== not_detect && digitalRead(ir_front)== not_detect  && digitalRead(ir_front_left)== not_detect && digitalRead(ir_left)== not_detect){
    m_right(180,255);
  }

// front_right_detect
  if(digitalRead(ir_right)== not_detect && digitalRead(ir_front_right)== detect && digitalRead(ir_front)== detect  && digitalRead(ir_front_left)== not_detect && digitalRead(ir_left)== not_detect){
    forward(255);
  }

// narrow_right_detect 
  if( digitalRead(ir_right)== not_detect && digitalRead(ir_front_right)== detect  && digitalRead(ir_front)== not_detect  && digitalRead(ir_front_left)== not_detect && digitalRead(ir_left)== not_detect){
    rotate_r(180,180);

  }
 
 //////////////////////////////////////////////// left ir //////////////////////////////////////////////////////////////////////


// ir left detect 
  if( digitalRead(ir_right)== not_detect && digitalRead(ir_front_right)== not_detect  && digitalRead(ir_front)== not_detect  && digitalRead(ir_front_left)== detect && digitalRead(ir_left)== detect){
    rotate_l(180,180);
  }
  
//wide_leftt_detect
  if(digitalRead(ir_right)== not_detect && digitalRead(ir_front_right)== not_detect && digitalRead(ir_front)== not_detect  && digitalRead(ir_front_left)== not_detect && digitalRead(ir_left)== detect){
    m_left(255,180);
  }

//front_left_detect
  if(digitalRead(ir_right)== not_detect && digitalRead(ir_front_right)== not_detect && digitalRead(ir_front)== detect  && digitalRead(ir_front_left)== detect && digitalRead(ir_left)== not_detect){
    forward(255);
  }

// narrow_left_detect
if( digitalRead(ir_right)== not_detect && digitalRead(ir_front_right)== not_detect  && digitalRead(ir_front)== not_detect  && digitalRead(ir_front_left)== detect && digitalRead(ir_left)== not_detect){
    m_left(255,180);
}else{
    forward(255);
}

}


////////////////////////////////////////////////////////////////// line follower detected /////////////////////////////////////////////////////////////////////////////

// front line follower detect 
  else if(digitalRead(line_front_right)==1 && digitalRead(line_front_left)==1 && digitalRead(line_back_right)==0 && digitalRead(line_back_left)==0 ){
   backward(255);
  }

// front right line follower detect 
  else  if( digitalRead(line_front_right)==1 && digitalRead(line_front_left)==0 && digitalRead(line_back_right)==0 && digitalRead(line_back_left)==0 ){
    backward(255);
  }

    // front left line follower detect 
  else if(digitalRead(line_front_right)==0 && digitalRead(line_front_left)==1 && digitalRead(line_back_right)==0 && digitalRead(line_back_left)==0 ){
    backward(255);
  }

// back line follower detect 
  else if( digitalRead(line_front_right)==0 && digitalRead(line_front_left)==0 && digitalRead(line_back_right)==1 && digitalRead(line_back_left)==1 ){
    forward(255);
  }

// back right line follower detect 
  else  if( digitalRead(line_front_right)==0 && digitalRead(line_front_left)==0 && digitalRead(line_back_right)==1 && digitalRead(line_back_left)==0 ){
    forward(255);
  }

// back left line follower detect 
  else if(digitalRead(line_front_right)==0 && digitalRead(line_front_left)==0 && digitalRead(line_back_right)==0 && digitalRead(line_back_left)==1 ){
    forward(255);
  }

// right side line follower detect 
  else if(digitalRead(line_front_right)==1 && digitalRead(line_front_left)==0 && digitalRead(line_back_right)==1 && digitalRead(line_back_left)==0 ){
    m_left(255,180);
  }

// left side line follower detect 
  else if(digitalRead(line_front_right)==0 && digitalRead(line_front_left)==1 && digitalRead(line_back_right)==0 && digitalRead(line_back_left)==1 ){
    m_right(180,255);
  }

}

}

///////////////////////////////////////////////////////////// right attack strategy ///////////////////////////////////////////////////////////////////


void Right_Attack(){
while (true) {



if(digitalRead(line_front_right)==0 && digitalRead(line_front_left)==0 && digitalRead(line_back_right)==0 && digitalRead(line_back_left)==0 ){

  forward(230);
  delay(500);
  brake();
  delay(100);
  m_right(190,150);
  delay(500);

  searching();


}




// front line follower detect 
else if(digitalRead(line_front_right)==1 && digitalRead(line_front_left)==1 && digitalRead(line_back_right)==0 && digitalRead(line_back_left)==0 
){
  backward(200);

}

    // front right line follower detect 
  else  if( digitalRead(line_front_right)==1 && digitalRead(line_front_left)==0 && digitalRead(line_back_right)==0 && digitalRead(line_back_left)==0 
){
     backward(200);

    }



    // front left line follower detect 
   else if(digitalRead(line_front_right)==0 && digitalRead(line_front_left)==1 && digitalRead(line_back_right)==0 && digitalRead(line_back_left)==0 
){
       backward(200);

    }


// back line follower detect 
else if( digitalRead(line_front_right)==0 && digitalRead(line_front_left)==0 && digitalRead(line_back_right)==1 && digitalRead(line_back_left)==1 
){
   forward(252);


}

    // back right line follower detect 
   else  if( digitalRead(line_front_right)==0 && digitalRead(line_front_left)==0 && digitalRead(line_back_right)==1 && digitalRead(line_back_left)==0 
){
     forward(252);
    }



    // back left line follower detect 
   else if(digitalRead(line_front_right)==0 && digitalRead(line_front_left)==0 && digitalRead(line_back_right)==0 && digitalRead(line_back_left)==1 
){
   forward(252);

    }
       // right side line follower detect 
   else if(digitalRead(line_front_right)==1 && digitalRead(line_front_left)==0 && digitalRead(line_back_right)==1 && digitalRead(line_back_left)==0 
){
  m_left(252,180);

    }

    // left side line follower detect 
   else if(digitalRead(line_front_right)==0 && digitalRead(line_front_left)==1 && digitalRead(line_back_right)==0 && digitalRead(line_back_left)==1 
){
   m_right(180,252);

    }


}

}












