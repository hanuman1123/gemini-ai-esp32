# GeminiAI Library for Arduino

GeminiAI is a lightweight and user-friendly Arduino library designed to interact seamlessly with Gemini AI. With this library, you can send questions to Gemini AI and receive meaningful responses, simplifying AI integration into your Arduino projects.

---

## Features

- **Easy Integration**: Simple methods to interact with Gemini AI using HTTP requests.
- **Response Filtering**: Automatically filters out special characters and unnecessary whitespaces from the AI responses.
- **Optimized for Arduino**: Lightweight code designed to run efficiently on Arduino-compatible devices.

---

## Table of Contents

1. [Installation](#installation)
2. [Usage](#usage)
3. [Examples](#examples)
4. [License](#license)
5. [Contributing](#contributing)
6. [Contact](#contact)

---

## Installation

### Using Git

1. Clone this repository:
   ```bash
   git clone https://github.com/your-username/GeminiAI.git
   ```
2. Copy the `GeminiAI` folder into your Arduino libraries folder:
   - **Windows**: `Documents > Arduino > libraries`
   - **Mac/Linux**: `~/Arduino/libraries`

### Manual Installation

1. Download the repository as a ZIP file.
2. Extract the ZIP file and copy the `GeminiAI` folder into your Arduino libraries folder as mentioned above.

---

## Usage

### Library Initialization

1. Include the GeminiAI library in your Arduino sketch:
   ```cpp
   #include <GeminiAI.h>
   ```

2. Initialize the library with your WiFi credentials and Gemini AI token:
   ```cpp
   GeminiAI gemini("YourSSID", "YourPassword", "YourGeminiToken", "MaxTokens");
   ```

3. Connect to WiFi:
   ```cpp
   gemini.connectWiFi();
   ```

4. Send a question to Gemini AI:
   ```cpp
   String answer = gemini.askQuestion("What is Arduino?");
   Serial.println(answer);
   ```

---

## Examples

### Basic Example

```cpp
#include <GeminiAI.h>

const char* ssid = "YourSSID";
const char* password = "YourPassword";
const char* token = "YourGeminiToken";
const char* maxTokens = "1000";

GeminiAI gemini(ssid, password, token, maxTokens);

void setup() {
    Serial.begin(9600);
    gemini.connectWiFi();
}

void loop() {
    Serial.println("Ask your question: ");
    while (!Serial.available()) ;
    String question = Serial.readStringUntil('\n');

    String answer = gemini.askQuestion(question);
    Serial.println("AI Response: " + answer);
    delay(5000);
}
```

---

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

---

## Contributing

We welcome contributions to enhance this library! Here's how you can contribute:

1. Fork the repository.
2. Create a feature branch:
   ```bash
   git checkout -b feature-name
   ```
3. Commit your changes:
   ```bash
   git commit -m "Description of your changes"
   ```
4. Push to your branch:
   ```bash
   git push origin feature-name
   ```
5. Open a Pull Request on GitHub.

---

## Contact

Created by **Jagadeesh Tadi**  
Email: jagguh1123@gmail.com  
GitHub: [Your GitHub Profile](https://github.com/your-username)  

Feel free to reach out for feedback, suggestions, or questions!

---

