/*

Arduino Sketch to show how encode and Decode Cbor package

Author: Juanjo Tara 
email:  j.tara@arduino.cc
date:	24/04/2015
*/




#include "CborEncoder.h"
#include "CborDecoder.h"

void setup() {

  Serial.begin(9600);
  //Serial.print("hola");
  test1();
}

void loop() {


}



void test1() {
    CborStaticOutput output(32);
    CborWriter writer(output);

    //Write a Cbor Package with a number and String 
    writer.writeInt(124);
    writer.writeString("I");

    unsigned int sizeee = output.getSize();
    Serial.print("datalength:");
    Serial.println(sizeee);
    delay(1000);
    
    
    CborInput input(output.getData(), output.getSize());
    CborDebugListener listener;
    CborReader reader(input);
    reader.SetListener(listener);
    reader.Run();
    
}
