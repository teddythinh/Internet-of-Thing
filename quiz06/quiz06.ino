#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

//***Set server***
const char* mqttServer = "broker.mqtt-dashboard.com"; 
int port = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

void wifiConnect() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" Connected!");
}

void mqttReconnect() {
  while(!client.connected()) {
    Serial.println("Attemping MQTT connection...");
    //***Change "123456789" by your student id***
    if(client.connect("20127335")) {
      Serial.println("connected");

      //***Subscribe all topic you need***
      client.subscribe("20127335");
    }
    else {
      Serial.println("try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(9600);
  Serial.print("Connecting to WiFi");

  wifiConnect();
  client.setServer(mqttServer, port);
  client.setCallback(callback);
}

//MQTT Receiver
void callback(char* topic, byte* message, unsigned int length) {
  Serial.println(topic);
  String strMsg;
  for(int i=0; i<length; i++) {
    strMsg += (char)message[i];
  }
  if(strMsg == "{\"mssv\":\"20127335\"}") {
    client.publish("MSSV-in", "Pham Huy Cuong Thinh");
  }
  if(strMsg == "{\"mssv\":\"20121234\"}") {
    client.publish("MSSV-in", "Nguyen Van A");
  }
  if(strMsg == "{\"mssv\":\"20124321\"}") {
    client.publish("MSSV-in", "Pham Van B");
  }

  Serial.println(strMsg);
}

void loop() {
  if(!client.connected()) {
    mqttReconnect();
  }
  client.loop();

  delay(100);
}
