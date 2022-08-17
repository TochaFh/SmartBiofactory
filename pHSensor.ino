#define SENSORPH A0

void setup()  {
  Serial.begin(9600);
}
 
void loop() {

  Serial.println(readpH());
  delay(2000);
}

float readpH()
{
  float entrada_A0 = analogRead(A0);
  float tensao = (entrada_A0 * 5.0) / 1024.0;
  float pH = 14 - (tensao * 2.8);

  float soma_tensao = 0;

  for (int i = 0; i < 10; i ++){
    entrada_A0 = analogRead(A0);
    tensao = (entrada_A0 * 5.0) / 1024.0;
    soma_tensao += tensao;
    delay(100);
  }

  float tensao_media = soma_tensao / 10;
  pH = 14 - (tensao_media * 2.8);
  return pH;
}
