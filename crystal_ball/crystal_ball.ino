#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3 ,2);

constexpr int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply = 0;

String answers[] = {
  "hello there", 
  "General Kenobi", 
  "This is where the fun begins", 
  "Do or do not. There is no try.",
  };

// risky to do, better define an predefined array length
constexpr int LENGTH_ANSWERS = sizeof(answers)/sizeof(answers[0]);

/*
 * @brief print answer to lcd screen and split if necessary
 */
void printAnswer(String string) {
  if (string.length() >= 16 && string.length() <= 32) {
    String partOne = string.substring(0, 16);
    String partTwo = string.substring(16, 31);
    lcd.setCursor(0, 0);
    lcd.print(partOne);
    lcd.setCursor(0, 1);
    lcd.print(partTwo);

  } else if (string.length() < 16) {
    lcd.print(string);
  } else if (string.length() > 32) {
    lcd.print("the wisdom of");
    lcd.print("the ball too great");
  }
}

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  pinMode(switchPin, INPUT);
  lcd.print("Ask the Crystal ");
  lcd.setCursor(0, 1);
  lcd.print("Ball");
}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(switchPin);
  if (switchState != prevSwitchState) {
    if (switchState == LOW) {
      reply = random(LENGTH_ANSWERS);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("The ball says");
      delay(500);
      lcd.print(".");
      delay(500);
      lcd.print(".");
      delay(500);
      lcd.print(".");
      delay(500);
      lcd.clear();
      lcd.setCursor(0, 0);
      printAnswer(answers[reply]);
    }
  }
  prevSwitchState = switchState;
}
