TCPClient client;

bool makeRequest = true;
bool waitForResponse = false;
bool getResponse = false;
int lastStepTime = 0;
char response[200];
int responseIndex = 0;

void setup() {
  Serial.begin(9600);
    Serial.println("setup");
    pinMode(D0, OUTPUT);
}

void loop() {
    if (makeRequest) {
        Serial.println("connecting...");
        if (client.connect("sebastiannilsson.com", 80)) {
            Serial.println("connected");
            client.println("GET /will-it-rain/ HTTP/1.0");
            client.println("Host: sebastiannilsson.com");
            client.println();
        } 
        else {
            Serial.println("connection failed");
        }
        makeRequest = false;
        waitForResponse = true;
        lastStepTime = millis();
    }
    if (waitForResponse) {
        
        //Serial.print(".");
        if (client.available()) {
            waitForResponse = false;
            getResponse = true;
            responseIndex = 0;
            lastStepTime = millis();
        }
        else if (millis() - lastStepTime > 5000) {
            // timeout
            Serial.println("timeout waiting for response");
            makeRequest = true;
            waitForResponse = false;
            getResponse = false;
            
            client.stop();
        }
    }
    if (getResponse) {
        if (millis() - lastStepTime > 5000) {
            // timeout
            Serial.println("timeout fetching response");
            makeRequest = true;
            waitForResponse = false;
            getResponse = false;
            client.stop();
        }
        
        if (client.available()) {
            response[responseIndex++] = client.read();
            //Serial.print(response[responseIndex-1]);
        }
        else {
            Serial.println(" done sending!");
            makeRequest = true;
            waitForResponse = false;
            getResponse = false;
            client.stop();
            
            // OK the whole http request is done. do something with the result!
            for (int j=0; j<responseIndex; j++){
                Serial.print(response[j]);
            }
            
            if (response[responseIndex-1] == '1') {
                Serial.println("Bring umbrealla");
                digitalWrite(D0, HIGH);
            }
            else if (response[responseIndex-1] == '0') {
                Serial.println("leave umbrealla at home");
                digitalWrite(D0, LOW);
            }
            Serial.print("new request is requested. wait 10s...");
            delay(10000);
        }
    
        if (!client.connected()) {
            Serial.println();
            Serial.println("disconnecting.");
            client.stop();

            makeRequest = true;
        }
    }
}