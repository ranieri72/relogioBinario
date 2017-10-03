const int minuto6 = 12;
const int minuto5 = 11;
const int minuto4 = 10;
const int minuto3 = 9;
const int minuto2 = 8;
const int minuto1 = 7;

const int hora4 = 6;
const int hora3 = 5;
const int hora2 = 4;
const int hora1 = 3;

const int atraso = 1000;

int minuto = 0;
int hora = 0;
int segundo = 0;

void setup() {
  Serial.begin(9600);

  pinMode(minuto6, OUTPUT);
  pinMode(minuto5, OUTPUT);
  pinMode(minuto4, OUTPUT);
  pinMode(minuto3, OUTPUT);
  pinMode(minuto2, OUTPUT);
  pinMode(minuto1, OUTPUT);

  pinMode(hora4, OUTPUT);
  pinMode(hora3, OUTPUT);
  pinMode(hora2, OUTPUT);
  pinMode(hora1, OUTPUT);
}

void loop() {

  if (segundo > 59) {
    segundo = 0;
    minuto++;
    for (int i = minuto1; i <= minuto6; i++) {

      if (digitalRead(i)) {
        digitalWrite(i, LOW);

      } else {
        digitalWrite(i, HIGH);
        break;
      }
    }
    Serial.println("");

    if (minuto > 59) {
      minuto = 0;
      hora++;
      digitalWrite(minuto6, LOW);
      digitalWrite(minuto5, LOW);
      digitalWrite(minuto4, LOW);
      digitalWrite(minuto3, LOW);
      digitalWrite(minuto2, LOW);
      digitalWrite(minuto1, LOW);

      for (int x = hora1; x <= hora4; x++) {

        if (digitalRead(x)) {
          digitalWrite(x, LOW);

        } else {
          digitalWrite(x, HIGH);
          break;
        }
      }

      if (hora > 23) {
        hora = 0;
        digitalWrite(hora4, LOW);
        digitalWrite(hora3, LOW);
        digitalWrite(hora2, LOW);
        digitalWrite(hora1, LOW);
      }
    }
  }

  Serial.print(hora);
  Serial.print(":");
  Serial.print(minuto);
  Serial.print(":");
  Serial.print(segundo);
  Serial.print(" ");


  delay(atraso);
  segundo++;
}
