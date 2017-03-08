//Dice Thrower v2
// in this version it will show the correct form of the pips on the dice

// give dNum the max number of pips you want on your dice
const int dNum = 6; //as in d8 or d6 or d4

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
  
  randomSeed(analogRead(A0));
}


void loop()
{
  int num;  
  num = random(1, dNum + 1);


  if (num == 1)
  {
    one();
    delay(3000);
    allOff();
    delay(30);
  }
  
  if (num == 2)
  {
    two();
    delay(3000);
    allOff();
    delay(30);
  }

  if (num == 3)
  {
    three();
    delay(3000);
    allOff();
    delay(30);
  }

  if (num == 4)
  {
    four();
    delay(3000);
    allOff();
    delay(30);
  }

  if (num == 5)
  {
    five();
    delay(3000);
    allOff();
    delay(30);
  }

  if (num == 6)
  {
    six();
    delay(3000);
    allOff();
    delay(30);
  }

  if (num == 7)
  {
    seven();
    delay(3000);
    allOff();
    delay(30);
  }

  if (num == 8);
  {
    eight();
    delay(3000);
    allOff();
    delay(30);
  }

  if (num == 9);
  {
    nine();
    delay(3000);
    allOff();
    delay(30);
  }



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

/*void four() //one of two ways to write four()
  {
  digitalWrite(ledMatrix[0][0], HIGH);
  digitalWrite(ledMatrix[2][0], HIGH);
  digitalWrite(ledMatrix[0][2], HIGH);
  digitalWrite(ledMatrix[2][2], HIGH);
  }*/

//different way of writing four()
void four()
{
  for (int row = 0; row < 3; row++)
  {
    if (row == 1) continue;

    digitalWrite(ledMatrix[row][0], HIGH);
    digitalWrite(ledMatrix[row][2], HIGH);
  }
  
  
}


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

/*void eight() //different way of writing eight()
  {
  for (int row = 0; row < 3; row++)
  {
    for (int col = 0; col < 3; col++)
    {
      if (col == 1 && row == 1) continue;

      digitalWrite(ledMatrix[row][col], HIGH);
    }
  }
  }*/

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

void allOff() //All LEDs off 
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      digitalWrite(ledMatrix[i][j], LOW);
    }
  }
  delay(30);
}

void allOn() //All LEDs on 
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      digitalWrite(ledMatrix[i][j], HIGH);
    }
  }
 
}
