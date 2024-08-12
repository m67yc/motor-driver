#include <SPI.h>
#include <mcp2515.h>

struct can_frame canMsg1;
MCP2515 mcp2515(10);


void setup() {
  
  while (!Serial);
  Serial.begin(115200);
  
  mcp2515.reset();
  mcp2515.setBitrate(CAN_125KBPS);
  mcp2515.setNormalMode();
  
  Serial.println("Example: Write to CAN");
}

void loop() {
  int angle[3];
  int speed[3];
  int current[3];
  int temperature;

  if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK) {
    angle = int(word(canMsg.data[0],canMsg.data[1]));
    speed = int(word(canMsg.data[2],canMsg.data[3]));
    current = int(word(canMsg.data[4],canMsg.data[5]));
    temperature =  = int(canMsg.data[6]);
  }

  Serial.print("ID = ");
  Serial.println(canMsg.can_id, HEX);
  Serial.print("angle = ");
  Serial.println(angle);
  Serial.print("speed = ");
  Serial.println(speed);
  Serial.print("current = ");
  Serial.println(current);
  Serial.print("temperature = ");
  Serial.print(temperature);
  
  delay(100);
}
