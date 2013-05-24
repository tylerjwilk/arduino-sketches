/*
  Morse Code Translator
  Converts Serial input into morse code light flashes
*/

// alphabet in morse code
char* letters[] =
{
  ".-",    // a
  "-...",  // b
  "-.-.",  // c
  "..",    // d
  ".",     // e
  "..-.",  // f
  "-.",    // g
  "....",  // h
  "..",    // i
  ".---",  // j
  "-.-",   // k
  ".-..",  // l
  "--",    // m
  "-.",    // n
  "---",   // o
  ".--.",  // p
  "--.-",  // q
  ".-.",   // r
  "...",   // s
  "-",     // t
  "..-",   // u
  "...-",  // v
  ".--",   // w
  "--..-", // x
  "-.--",  // y
  "--..",  // z
};

// numbers in morse code
char* numbers[] =
{
  "-----",  // 0
  ".----",  // 1
  "..---",  // 2
  "...--",  // 3
  "....-",  // 4
  ".....",  // 5
  "-....",  // 6
  "--...",  // 7
  "---..",  // 8
  "----.",  // 9
};

// vars
int dotDelay = 500;
int ledPin = 13; 

// setup the board
void setup()
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  welcomeScreen();
}

// show a nice welcome screen
void welcomeScreen()
{
  delay(1000);
  Serial.println("  Morse Code Translater");
  Serial.println("-------------------------");  
  Serial.println("");
}

// main loop
void loop()
{
  char ch;
  if (Serial.available() > 0)
  {
    // get the input in lowercase
    ch = tolower(Serial.read());
    // use letters 
    if (ch >= 'a' && ch <= 'z')
    {
      flashLetter(ch);
    }
    // use numbers
    else if(ch >= '0' && ch <= '9')
    {
      flashNumber(ch);
    }
    // space between words / numbers
    else if(ch == ' ')
    {
      delay(dotDelay * 4);
    }
  }
}

// flash from letter char
void flashLetter(char ch)
{
  //Serial.println("Received char: " + (String)ch);
  char* l;
  l = letters[ch - 'a'];
  //Serial.println("Code Letter : " + (String)l);
  // loop dot and dash
  int i = 0;
  while (l[i] != '\0')
  {
    flashCode(l[i]);
    i++;
  }
}

// flash from number char
void flashNumber(char ch)
{
   //Serial.println("Received number : " + (String)ch);
   char* n;
   n = numbers[ch - '0'];
   //Serial.println("Code Number : " + (String)n);
   // loop dot and dash
   int i = 0;
   while (n[i] != '\0')
   {
     flashCode(n[i]);
     i++;
   }   
}

// flash based on the code . or -
void flashCode(char code)
{
    // led on
    digitalWrite(ledPin, HIGH);
    // dot code
    if (code == '.')
    {
      delay(dotDelay);
    }
    // dash code
    else  
    {
      delay(dotDelay * 3);
    }
    // led off
    digitalWrite(ledPin, LOW);
    // delay between next flash
    delay(dotDelay);
}

