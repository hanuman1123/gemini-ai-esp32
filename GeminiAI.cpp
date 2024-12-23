#include "GeminiAI.h"

GeminiAI::GeminiAI(const char* ssid, const char* password, const char* token, int maxTokens) 
    : ssid(ssid), password(password), token(token), maxTokens(maxTokens) {}

void GeminiAI::connectWiFi() {
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);

    Serial.print("Connecting to ");
    Serial.println(ssid);

    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }

    Serial.println("\nConnected to WiFi");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
}

String GeminiAI::askQuestion(const String& question) {
    HTTPClient https;
    String payload = String("{\"contents\": [{\"parts\":[{\"text\":\"" + question + "\"}]}],\"generationConfig\": {\"maxOutputTokens\": ") 
                     + String(maxTokens) + "}}";

    if (https.begin("https://generativelanguage.googleapis.com/v1beta/models/gemini-1.5-flash:generateContent?key=" + String(token))) {
        https.addHeader("Content-Type", "application/json");

        int httpCode = https.POST(payload);

        if (httpCode == HTTP_CODE_OK) {
            String response = https.getString();
            DynamicJsonDocument doc(1024);
            deserializeJson(doc, response);
            String rawAnswer = doc["candidates"][0]["content"]["parts"][0]["text"];
            return cleanAnswer(rawAnswer);
        } else {
            Serial.printf("HTTP POST failed, error: %s\n", https.errorToString(httpCode).c_str());
        }

        https.end();
    } else {
        Serial.println("Unable to connect to API endpoint.");
    }

    return "Error in getting response.";
}

String GeminiAI::cleanAnswer(const String& rawAnswer) {
    String filteredAnswer;
    for (char c : rawAnswer) {
        if (isalnum(c) || isspace(c)) {
            filteredAnswer += c;
        } else {
            filteredAnswer += ' ';
        }
    }
    return filteredAnswer;
}
