/***************************************\
** Projeto Alarme **
\***************************************/
const int LM35 = 0;
float temperatura = 0;
int ADClido = 0;
const int Buzzer = 8;
const int cooler = 9;

void setup() {
  Serial.begin(9600);
  analogReference(INTERNAL); //No Mega, use INTERNAL1V1, no Leonardo remova essa linha
  pinMode(Buzzer, OUTPUT);
  pinMode(cooler, OUTPUT);
}
void loop() {
  ADClido = analogRead(LM35);
  temperatura = ADClido * 0.1075268817204301; //no Leonardo use 0.4887585532
  if (temperatura > 28) { // setei como 28ºC
    digitalWrite(Buzzer, HIGH);
    digitalWrite(cooler, HIGH);
  }
  else {
    digitalWrite(Buzzer, LOW);
    digitalWrite(cooler, LOW);
  }
  Serial.print("Temperatura = ");
  Serial.print(temperatura);
  Serial.println(" *C");
  delay(1000);
}
