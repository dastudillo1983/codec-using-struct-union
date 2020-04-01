/*
  StructRecibir

  created 26 Jun 2020
  by Fabian Astudillo-Salinas 
     <fabian.astudillos@ucuenca.edu.ec>
*/

#define SIZE_SENSOR 3

typedef struct {
  uint8_t id:8;
  uint16_t temperatura:9;
  uint8_t humedad:7;
} sensor;

typedef union {
  sensor data;
  uint8_t serializado[SIZE_SENSOR];
} usensor;

usensor data;

char buf[SIZE_SENSOR];

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  //pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial3.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  int len = Serial3.readBytes(buf,SIZE_SENSOR);
  //int len = Serial3.readBytes(data.serializado,SIZE_SENSOR);
  if (len > 0) {
    memcpy(&data.serializado, &buf, SIZE_SENSOR);
    Serial.println(String(len));
    Serial.print("id:");
    Serial.println(data.data.id);
    Serial.print("temperatura:");
    Serial.println(data.data.temperatura);
    Serial.print("humedad:");
    Serial.println(data.data.humedad);
    Serial.println();
  }
}
