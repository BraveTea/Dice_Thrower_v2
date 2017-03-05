//Dice Thrower v2
// in this version it will show the correct form of the pips on the dice

const int ROW_COUNT = 3;
const int COL_COUNT = 3;
int ledMatrix[ROW_COUNT][COL_COUNT] =
{
  {2, 3, 4},
  {5, 6, 7},
  {8, 9, 10}
};

/*  show & tell of array addresses
      {[0][0], [0][1], [0][2]},

      {[1][0], [1][1], [1][2]},

      {[2][0], [2][1], [2][2]}
*/


void setup()
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      pinMode(ledMatrix[i][j], OUTPUT);
    }
  }
  Serial.begin(9600);
  randomSeed(analogRead(A0));
}


void loop()
{
  int num;
  int mapChange;
  num = random(9999) + 1;
  mapChange = map(num, 1, 10000, 1, 6);

  if (mapChange == 1)
    one();
  
  if (mapChange == 2)
    two();

  if (mapChange == 3)
    three();
  
  if (mapChange == 4)
    four();
  
  if (mapChange == 5)
    five();
  
  if (mapChange == 6)
    six();
  

  Serial.print(mapChange);
  Serial.print("\t mapped from: ");
  Serial.println(num);
  delay(2000);
  allOff();
}


void one()
{
  digitalWrite(ledMatrix[1][1], HIGH);
}

void two()
{
  digitalWrite(ledMatrix[2][0], HIGH);
  digitalWrite(ledMatrix[0][2], HIGH);
}

void three()
{
  digitalWrite(ledMatrix[1][1], HIGH);
  digitalWrite(ledMatrix[2][0], HIGH);
  digitalWrite(ledMatrix[0][2], HIGH);
}

void four()
{
  digitalWrite(ledMatrix[0][0], HIGH);
  digitalWrite(ledMatrix[2][0], HIGH);
  digitalWrite(ledMatrix[0][2], HIGH);
  digitalWrite(ledMatrix[2][2], HIGH);
}

/* different way of writing four()
void four()
{
  for (int row = 0; row < 3; row++)
  {
    if (row == 1)
    {
      continue;
    }
    digitalWrite(ledMatrix[row][0], HIGH);
    digitalWrite(ledMatrix[row][2], HIGH);
  }
}
*/

void five()
{
  digitalWrite(ledMatrix[0][0], HIGH);
  digitalWrite(ledMatrix[2][0], HIGH);
  digitalWrite(ledMatrix[0][2], HIGH);
  digitalWrite(ledMatrix[2][2], HIGH);
  digitalWrite(ledMatrix[1][1], HIGH);
}

void six()
{
  for (int row = 0; row < 3; row++)
  {
    digitalWrite(ledMatrix[row][0], HIGH);
    digitalWrite(ledMatrix[row][2], HIGH);
  }
}

void seven()
{
  for (int row = 0; row < 3; row++)
  {
    digitalWrite(ledMatrix[row][0], HIGH);
    digitalWrite(ledMatrix[row][2], HIGH);
  }
  digitalWrite(ledMatrix[1][1], HIGH);
}

void eight()
{
  for (int row = 0; row < 3; row++)
  {
    digitalWrite(ledMatrix[row][0], HIGH);
    digitalWrite(ledMatrix[row][2], HIGH);
  }
  digitalWrite(ledMatrix[0][1], HIGH);
  digitalWrite(ledMatrix[2][1], HIGH);
}

void nine()
{
  for (int row = 0; row < 3; row++)
  {
    for (int col = 0; col < 3; col++)
    {
      digitalWrite(ledMatrix[row][col], HIGH);
    }
  }
}

void allOff() //All LEDs off for 1 second
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      digitalWrite(ledMatrix[i][j], LOW);
    }
  }
  delay(1000);
}

void allOn() //All LEDs on for 1 second
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      digitalWrite(ledMatrix[i][j], HIGH);
    }
  }
  delay(1000);
}
