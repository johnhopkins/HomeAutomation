//define the arrays thatdetermine how long to transmit/wait between pulses  
 //values are in on/off pairs, microseconds (1/1,000,000 of a second)  
 //1000 microseconds = 1 millisecond (ms)  
 //1ms = 1000/second  
   
 //192Hz = 192,000 times a second  
 //so each sample = 5.2083333 us long  
 //96 samples therefore = 500us  
 int comms_start[] = {  
  520,500,  
  520,500,  
  520,500,  
  520,500,  
  520,500,  
  520,500,
  1000,1000,
  500,1000,
  1000,500,
  500,1000,
  520,500,
  520,500,
  1000,1000,
  1000,1000,
  1000,1000,
  520,500,
  520,500,
  520,500 
 };  
   
 int comms_on[] = {  
  1000,1000,
  520,500,
  520,500,
  520,500,
  520,500,
  1000,1000,
  1000,500,
  500,500,
  500,1000,
  500, 
 };  
   
 int comms_off[] = {  
  520,500,
  520,500,
  520,500,
  520,500,
  520,500,
  1000,1000,
  500,500,
  1000,500,
  500,500,
  500,1000,
  500,
 };  
   
 #define INT_SIZE sizeof(int);  
   
 //define the digital pin the transmitter data pin is connected to  
 int txPin = 4;  
   
 void setup()  
 {  
  Serial.begin(9600);  
  pinMode(txPin, OUTPUT);  
 }  
   
 void loop()  
 {  
  if(Serial.available() > 0)  
  {  
   //something in the serial buffer  
   int incoming = Serial.read();  
     
   if(incoming == 49) //char code for 1  
   {  
    //turn the heating on  
    Serial.println("ON!");  
    turnHeatingOn();  
   }  
   else  
   {  
    //turn the heating off  
    Serial.println("OFF!");  
    turnHeatingOff();  
   }  
  }  
 }  
   
 void turnHeatingOn()  
 {  
  sendPreambleAndBoilerID();  
  sendOn();  
 }  
   
 void turnHeatingOff()  
 {  
  sendPreambleAndBoilerID();  
  sendOff();  
 }  
   
 void sendPreambleAndBoilerID()  
 {  
  Serial.println("Sending Preamble");  
  sendArray(comms_start, sizeof(comms_start));  
 }  
   
 void sendOn()  
 {  
  Serial.println("Sending On");  
  sendArray(comms_on, sizeof(comms_on));  
 }  
   
 void sendOff()  
 {  
  Serial.println("Sending Off");  
  sendArray(comms_off, sizeof(comms_off));  
 }  
   
 void sendArray(const int start[], int arrSize)  
 {  
  int arrLength = arrSize / INT_SIZE;  
  for(int i = 0; i < arrLength; i = i + 2)  
  {  
   transmit(start[i], start[i+1]);  
  }  
 }  
   
 void transmit(int uS_transmit,int uS_wait)  
 {  
  //turn on transmitter  
  bitWrite(PORTD,txPin, 1);  
    
  //wait the right amount of time  
  delayMicroseconds(uS_transmit);  
    
  //turn off the transmitter  
  bitWrite(PORTD,txPin, 0);  
    
  //and wait out its delay before the next 'on' can occur  
  delayMicroseconds(uS_wait);  
 }  
