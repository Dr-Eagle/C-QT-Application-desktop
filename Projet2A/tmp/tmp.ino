#include <dht11.h>
#define DHT11PIN 4 // broche DATA -> broche 4 
#define l_v 10
#define l_r 9
#define l_b 8
dht11 DHT11;

void led_V()
{
  digitalWrite(l_v, HIGH);
  delay(100);
  
}
void led_B()
{
  digitalWrite(l_b, HIGH);
  delay(100);
}
void led_R()
{
  digitalWrite(l_r, HIGH);
  delay(100);
}
void low_led()
{
    digitalWrite(l_v, LOW);
    digitalWrite(l_r, LOW);
    digitalWrite(l_b, LOW);
}

 
void setup()
{
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
  while (!Serial) {

  }
  /*Serial.println("DHT11 programme d'essai ");
  Serial.print("LIBRARY VERSION: ");
  Serial.println(DHT11LIB_VERSION);
  Serial.println();*/
  
}
 
void loop()
{
  low_led();
  DHT11.read(DHT11PIN);
  if ((float)DHT11.temperature>=30)
  {
    led_R();
  }else if ((float)DHT11.temperature<=15)
  {
    led_B();
  }else
  {
    led_V();
  }
  Serial.print("Température (°C): ");
  Serial.println((float)DHT11.temperature, 2);
  delay(2000);
}
