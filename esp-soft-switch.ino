
#include <Homie.h>

const int PIN_SWITCH = 16;  // D0
Bounce debouncer = Bounce();

int lastSwitchValue=-1;

bool firstToggle = true;

HomieNode switchNode("switch","switch");

void loopHandler() {
  int switchValue = debouncer.read();

    if(switchValue != lastSwitchValue) {
      Homie.getLogger() << "Switch is now " << (switchValue ? "off" : "on") << endl;
      switchNode.setProperty("on").send(switchValue ? "false" : "true");
      lastSwitchValue = switchValue;

      
      if (firstToggle) {
        firstToggle = false;
      }
      else {
        switchNode.setProperty("toggle").setRetained(false).send(switchValue ? "false" : "true");
      }
      
    }

}


void setup() {

  Serial.begin(115200);
  Serial << endl << endl;
  pinMode(PIN_SWITCH, INPUT);
  digitalWrite(PIN_SWITCH, HIGH);
  debouncer.attach(PIN_SWITCH);
  debouncer.interval(50);
  
  Homie_setFirmware("soft-switch", "1.0.2");
  Homie.setLoopFunction(loopHandler);

  switchNode.advertise("on");
  switchNode.advertise("toggle");
  
  Homie.setup();

}


void loop() {

  Homie.loop();
  debouncer.update();
  
}

