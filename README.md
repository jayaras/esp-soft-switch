# esp-soft-switch

## Wiring
I don't have any diagrams handy but you just need a switch between D0 and Ground and a pullup between D0 and 3.3v.

## Known Working on...
* Wemos mini D1 knockoff https://amzn.to/2VX5C09
* NodeMCU https://amzn.to/2SZWLJ6
* Adafruit Feather Huzzah https://amzn.to/2MfymN9

## Installing
Right now this needs Arduino/esp8266, Homie 2.0 and its web assets on the spif.  tl;dr - If anyone actually had interest in a binary they could burn on I would be happy to provide it.

## ToDo
Maybe move away from Homie to something that supports HASS's MQTT detection. Unles someone makes a HASS plugin for Homie.

## Example of using with HomeAssistant
```yaml
homeassistant@hass:~/.homeassistant/automations$ cat toggle_fireplace.yaml 
alias: "Toggle Fireplace Status"
trigger:
  - platform: mqtt
    topic: homie/fireplace-soft-switch/switch/toggle
action:
  service: switch.toggle
  data:
    entity_id: switch.fireplace_63
```
