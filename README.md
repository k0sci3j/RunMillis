# RunMillis
Small arduino library to run specific function after time period elapsed.


Usage:
1. Include RunMillis.h file into your project
2. Create new pointer to variable of RunMillis
3. In your setup() create new object of class RunMillis. First parameter is time after which function can be called. Second is pointer to function which should be called.
4. In your loop() to run RunMillis object call run() on your object. If time period elapased your function will run.

Example:

```C++
#include "Arduino.h"
#include "RunMillis.h"

RunMillis *ledRunner;

volatile bool state = false;

void blinkLed() {
   if(state){
      digitalWrite(LED_BUILTIN, LOW);
      state = false;
      return;
   }
   digitalWrite(LED_BUILTIN, HIGH);
   state = true;
}

void setup() {
   pinMode(LED_BUILTIN, OUTPUT);
   ledRunner = new RunMillis(1000, blinkLed);
}

void loop() {
   ledRunner->run();
}
```

Will blink built-in LED with 1s ON and 1s OFF.
