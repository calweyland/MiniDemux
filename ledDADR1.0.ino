// LedDADR v1.0 

int addr = 0;
int en = 1;
int dig1 = 0;
int dig2 = 0;
int dig3 = 0;
int ondisplay = 0;
void setup() {
   pinMode(2, OUTPUT); // Logic Data A
  pinMode(3, OUTPUT); // Logic Data B
  pinMode(4, OUTPUT); // Logic Data C
  pinMode(5, OUTPUT); // Logic Data D

  pinMode(6, OUTPUT); // Chip Latch 1
  pinMode(7, OUTPUT); // Chip Latch 2
  pinMode(8, OUTPUT); // Chip Latch 3

  pinMode(9, OUTPUT); // Blanking Signal
  
  pinMode(10, INPUT); //up button
  pinMode(13, INPUT); //up button
  pinMode(12, INPUT); //fine up button

}

void loop() {
  if (digitalRead(10)==HIGH){//if the up button is pressed
    addr = addr + 1;
    if (addr > 512){
    addr = 1;}
   if (addr < 1){
    addr = 512;}
     en = 1;
     delay(70);
   }
   if (digitalRead(12)==HIGH){//if the fine up button is pressed
    addr = addr + 1;
    if (addr > 512){
    addr = 1;}
   if (addr < 1){
    addr = 512;}
     en = 1;
     delay(200);
   }

      
    if (digitalRead(13)==HIGH){// if the down button is pressed
    addr = addr - 1;
    if (addr > 512){
    addr = 1; }
   if (addr < 1){
    addr = 512;}
    en = 1;
    delay(70 );
   }
 
if (en == 1){//begin  the ritual of writing to the displays
   if (ondisplay != addr){//is the address already on the display?
  //and now some maths
  dig1 = addr/100;
  dig2 = addr%100/10;
  dig3 = addr%10;

  
  digitalWrite(6,LOW); //select display 1
  digitalWrite(7,HIGH);//deselect display 2
  digitalWrite(8,HIGH);//deselect display 3
  
  if(dig1==0) // Set to digit 0
    {digitalWrite(2,LOW); digitalWrite(3,LOW); digitalWrite(4,LOW); digitalWrite(5,LOW);}
   
  if(dig1==1) // Set to digit 1
    {digitalWrite(2,HIGH); digitalWrite(3,LOW); digitalWrite(4,LOW); digitalWrite(5,LOW);}
  
  if(dig1==2) // Set to digit 2
    {digitalWrite(2,LOW); digitalWrite(3,HIGH); digitalWrite(4,LOW); digitalWrite(5,LOW);}  

  if(dig1==3) // Set to digit 3
    {digitalWrite(2,HIGH); digitalWrite(3,HIGH); digitalWrite(4,LOW); digitalWrite(5,LOW);}

  if(dig1==4) // Set to digit 4
    {digitalWrite(2,LOW); digitalWrite(3,LOW); digitalWrite(4,HIGH); digitalWrite(5,LOW);}
   
  if(dig1==5) // Set to digit 5
    {digitalWrite(2,HIGH); digitalWrite(3,LOW); digitalWrite(4,HIGH); digitalWrite(5,LOW);}
  
  if(dig1==6) // Set to digit 6
    {digitalWrite(2,LOW); digitalWrite(3,HIGH); digitalWrite(4,HIGH); digitalWrite(5,LOW);}  

  if(dig1==7) // Set to digit7
    {digitalWrite(2,HIGH); digitalWrite(3,HIGH); digitalWrite(4,HIGH); digitalWrite(5,LOW);}

  if(dig1==8) // Set to digit 8
    {digitalWrite(2,LOW); digitalWrite(3,LOW); digitalWrite(4,LOW); digitalWrite(5,HIGH);}
   
  if(dig1==9) // Set to digit 9
    {digitalWrite(2,HIGH); digitalWrite(3,LOW); digitalWrite(4,LOW); digitalWrite(5,HIGH);}

    
  digitalWrite(6,HIGH); //deselect display 1
  digitalWrite(7,LOW);//select display 2
  digitalWrite(8,HIGH);//deselect display 3
  
  
  if(dig2==0) // Set to digit 0
    {digitalWrite(2,LOW); digitalWrite(3,LOW); digitalWrite(4,LOW); digitalWrite(5,LOW);}
   
  if(dig2==1) // Set to digit 1
    {digitalWrite(2,HIGH); digitalWrite(3,LOW); digitalWrite(4,LOW); digitalWrite(5,LOW);}
  
  if(dig2==2) // Set to digit 2
    {digitalWrite(2,LOW); digitalWrite(3,HIGH); digitalWrite(4,LOW); digitalWrite(5,LOW);}  

  if(dig2==3) // Set to digit 3
    {digitalWrite(2,HIGH); digitalWrite(3,HIGH); digitalWrite(4,LOW); digitalWrite(5,LOW);}

  if(dig2==4) // Set to digit 4
    {digitalWrite(2,LOW); digitalWrite(3,LOW); digitalWrite(4,HIGH); digitalWrite(5,LOW);}
   
  if(dig2==5) // Set to digit 5
    {digitalWrite(2,HIGH); digitalWrite(3,LOW); digitalWrite(4,HIGH); digitalWrite(5,LOW);}
  
  if(dig2==6) // Set to digit 6
    {digitalWrite(2,LOW); digitalWrite(3,HIGH); digitalWrite(4,HIGH); digitalWrite(5,LOW);}  

  if(dig2==7) // Set to digit7
    {digitalWrite(2,HIGH); digitalWrite(3,HIGH); digitalWrite(4,HIGH); digitalWrite(5,LOW);}

  if(dig2==8) // Set to digit 8
    {digitalWrite(2,LOW); digitalWrite(3,LOW); digitalWrite(4,LOW); digitalWrite(5,HIGH);}
   
  if(dig2==9) // Set to digit 9
    {digitalWrite(2,HIGH); digitalWrite(3,LOW); digitalWrite(4,LOW); digitalWrite(5,HIGH);}


  digitalWrite(6,HIGH); //deselect display 1
  digitalWrite(7,HIGH);//deselect display 2
  digitalWrite(8,LOW);//select display 3
  
  
  if(dig3==0) // Set to digit 0
    {digitalWrite(2,LOW); digitalWrite(3,LOW); digitalWrite(4,LOW); digitalWrite(5,LOW);}
   
  if(dig3==1) // Set to digit 1
    {digitalWrite(2,HIGH); digitalWrite(3,LOW); digitalWrite(4,LOW); digitalWrite(5,LOW);}
  
  if(dig3==2) // Set to digit 2
    {digitalWrite(2,LOW); digitalWrite(3,HIGH); digitalWrite(4,LOW); digitalWrite(5,LOW);}  

  if(dig3==3) // Set to digit 3
    {digitalWrite(2,HIGH); digitalWrite(3,HIGH); digitalWrite(4,LOW); digitalWrite(5,LOW);}

  if(dig3==4) // Set to digit 4
    {digitalWrite(2,LOW); digitalWrite(3,LOW); digitalWrite(4,HIGH); digitalWrite(5,LOW);}
   
  if(dig3==5) // Set to digit 5
    {digitalWrite(2,HIGH); digitalWrite(3,LOW); digitalWrite(4,HIGH); digitalWrite(5,LOW);}
  
  if(dig3==6) // Set to digit 6
    {digitalWrite(2,LOW); digitalWrite(3,HIGH); digitalWrite(4,HIGH); digitalWrite(5,LOW);}  

  if(dig3==7) // Set to digit7
    {digitalWrite(2,HIGH); digitalWrite(3,HIGH); digitalWrite(4,HIGH); digitalWrite(5,LOW);}

  if(dig3==8) // Set to digit 8
    {digitalWrite(2,LOW); digitalWrite(3,LOW); digitalWrite(4,LOW); digitalWrite(5,HIGH);}
   
  if(dig3==9) // Set to digit 9
    {digitalWrite(2,HIGH); digitalWrite(3,LOW); digitalWrite(4,LOW); digitalWrite(5,HIGH);}
  digitalWrite(9,LOW);//make sure the diaplays are actually turned on!
  digitalWrite(6,HIGH); //deselect display 1
  digitalWrite(7,HIGH);//deselect display 2
  digitalWrite(8,HIGH);//deselect display 3
  ondisplay = addr;//the address is now on the display
}
    
}//end the ritual of writing to the displays

}
