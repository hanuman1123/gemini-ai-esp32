#ifndef GEMINI_AI_H
#define GEMINI_AI_H

#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

class GeminiAI {
public:
    GeminiAI(const char* ssid, const char* password, const char* token, int maxTokens);
    void connectWiFi();
    String askQuestion(const String& question);

private:
    const char* ssid;
    const char* password;
    const char* token;
    int maxTokens;

    String cleanAnswer(const String& rawAnswer);
};

#endif // GEMINI_AI_H
