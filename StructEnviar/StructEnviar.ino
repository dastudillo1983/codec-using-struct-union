/*
  StructEnviar

  created 26 mar 2020
  by Fabian Astudillo-Salinas 
     <fabian.astudillos@ucuenca.edu.ec>
*/


#define SIZE_SENSOR 3

// Se envian 3 bytes
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

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  //pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial3.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  data.data.id = 1;
  data.data.temperatura = 40;
  data.data.humedad = 50;
  
  
  
  Serial3.write(data.serializado, SIZE_SENSOR);
  Serial.println("Transmitting");
  Serial.print(String(data.serializado[0]));
  Serial.print("-");
  Serial.print(String(data.serializado[1]));
  Serial.print("-");
  Serial.println(String(data.serializado[2]));
  
  delay(1000);
}
