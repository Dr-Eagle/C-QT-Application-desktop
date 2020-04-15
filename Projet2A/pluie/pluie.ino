//#define pin_bip 7
const int capteur_D = 4; // pin connecté à la sortie digital du capteur
const int capteur_A = A0; // pin connecté à la sortie analogique du capteur
void led()
{
  digitalWrite(7, HIGH);
  delay(100);
  digitalWrite(7, LOW);
  delay(50);
}



void bip()
{
  digitalWrite(9, HIGH);
  delay(100);
  digitalWrite(9, LOW);
  delay(50); 
}
int val_analogique;
void setup()
{
  pinMode(capteur_D, INPUT);
  pinMode(9, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);

  pinMode(capteur_A, INPUT);
  Serial.begin(9600);
}

void loop()
{
 val_analogique=analogRead(capteur_A); // on lit la broche capteur "analogique"
if(val_analogique>200)
  {
      digitalWrite(7, LOW);

    Serial.println("Valeur digital : Pas mouille");
    delay(10); // Tempo
    digitalWrite(6, HIGH);
  delay(100);
  }
else if (val_analogique<100)
  {
    
  digitalWrite(6, LOW);
        bip(); 
        led();
    Serial.println("Valeur digital : Pluie");
   // delay(10); // Tempo
  }else
  {
    Serial.println("Valeur digital : mouille"); 
    delay(10); // Tempo
    digitalWrite(7, HIGH);
  delay(100);
    digitalWrite(6, LOW);

  //digitalWrite(7, LOW);
  //delay(50);
  }

}
