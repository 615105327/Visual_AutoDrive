#include <Servo.h>   
#define SER1_BAUD 115200

#define PWMB_IN1  11       
#define PWMB_IN2 6       
#define PWMA_IN1 5        
#define PWMA_IN2 3       
#define Servor_Pin    7
#define  BEEP_PIN    12            
#define  NLED_PIN    13          
#define  NLED_MS_BETWEEN        500
#define  DUOJI_MS_BETWEEN       20.000
int pwm_value=1500;
char val=0;
Servo myservo;           
unsigned char handle_ms_between( unsigned long *time_ms, unsigned int ms_between);
void handle_nled();
void dida(u8 times, u8 frequency);
void Motor_Forward(char motor,char pwm);
void Motor_Back(char motor,char pwm);
void Motor_Left(char motor,char pwm);
void Motor_Right(char motor,char pwm);
void Motor_Turn_Left(char motor,char pwm);
void Motor_Turn_Right(char motor,char pwm);
void Motor_Stop(char motor);
void setup() {
   pinMode(BEEP_PIN, OUTPUT);
   pinMode(NLED_PIN, OUTPUT);
   Serial.begin(SER1_BAUD); 
   myservo.attach(Servor_Pin);
   myservo.writeMicroseconds(1350);
   dida(1, 1000);
   delay(1000);
}

void loop() {
    Motor_Forward(1,150);
    Motor_Forward(2,150);
    myservo.writeMicroseconds(1350);
    delay(2000);  
    
//    Motor_Back(1,150);
//    Motor_Back(2,150);
//    delay(2000);  
//    myservo.writeMicroseconds(1800);  
//    
//    Motor_Turn_Left(1,150);
//    Motor_Turn_Left(2,150); 
//    myservo.writeMicroseconds(1800);  
//    delay(2000); 
//    Motor_Turn_Right(1,150);
//    Motor_Turn_Right(2,150);
//    myservo.writeMicroseconds(1200);  
//    delay(2000); 
//    
}

unsigned char handle_ms_between( unsigned long *time_ms, unsigned int ms_between) {
    if(millis() - *time_ms < ms_between) {
        return 0;  
    } else{
         *time_ms = millis();
         return 1;
    }
}
void handle_nled() {
    static unsigned long systick_ms_bak = 0;
    if(!handle_ms_between(&systick_ms_bak, NLED_MS_BETWEEN))return;  
    digitalWrite(NLED_PIN, val);
    val = ~val;
}
void dida(u8 times, u8 frequency) {
    for(byte i = 0; i < times; i++ ) {
        digitalWrite(BEEP_PIN, LOW);
        delay(frequency);
        delay(frequency);
        digitalWrite(BEEP_PIN, HIGH );
        delay(frequency);
        delay(frequency);  
    }
}

void Motor_Forward(char motor,char pwm) 
{
  if(motor==1)
  {
     analogWrite(PWMA_IN1,255);
     analogWrite(PWMA_IN2,pwm);
  }
  else if(motor==2)
  {
     analogWrite(PWMB_IN1,255);
     analogWrite(PWMB_IN2,pwm); 
  }
}

void Motor_Back(char motor,char pwm)
{
  if(motor==1)
  {
     analogWrite(PWMA_IN1,pwm);
     analogWrite(PWMA_IN2,255);
  }
  else if(motor==2)
  {
     analogWrite(PWMB_IN1,pwm);
     analogWrite(PWMB_IN2,255); 
  }
}

void Motor_Right(char motor,char pwm)
{
    if(motor==1)
  {
     analogWrite(PWMA_IN1,pwm);
     analogWrite(PWMA_IN2,255);
  }
  else if(motor==2)
  {
     analogWrite(PWMB_IN1,255);
     analogWrite(PWMB_IN2,255); 
  }
}
void Motor_Left(char motor,char pwm) 
{
    if(motor==1)
  {
     analogWrite(PWMA_IN1,255);
     analogWrite(PWMA_IN2,255);
  }
  else if(motor==2)
  {
     analogWrite(PWMB_IN1,pwm);
     analogWrite(PWMB_IN2,255); 
  }
}

void Motor_Turn_Right(char motor,char pwm)
{
    if(motor==1)
  {
     analogWrite(PWMA_IN1,pwm);
     analogWrite(PWMA_IN2,255);
  }
  else if(motor==2)
  {
     analogWrite(PWMB_IN1,255);
     analogWrite(PWMB_IN2,pwm); 
  }
}

void Motor_Turn_Left(char motor,char pwm)
{
    if(motor==1)
  {
     analogWrite(PWMA_IN1,255);
     analogWrite(PWMA_IN2,pwm);
  }
  else if(motor==2)
  {
     analogWrite(PWMB_IN1,pwm);
     analogWrite(PWMB_IN2,255); 
  }
}
void Motor_Stop(char motor)
{
    if(motor==1)
  {
     analogWrite(PWMA_IN1,255);
     analogWrite(PWMA_IN2,255);
  }
  else if(motor==2)
  {
     analogWrite(PWMB_IN1,255);
     analogWrite(PWMB_IN2,255); 
  }
}
