int lasers[] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,22,23,24};
//int sensors[] = {25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41}; //6, 10, 12, 11, 14, 2, 16, 18, 15, 1. 5, 9, 4, 13. 3
int sensors[] = {34, 30, 40, 37, 35, 25, 38, 41, 36, 26, 28, 27, 39, 29, 33, 31, 42, 32}; //1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18 
int pointbutton = 43; //button for point
int score = 0;

// Green Lasers ///
int greenlaser1 = 23;
int greenlaser2 = 24;
int greensen1 = 42;
int greensen2 = 32;

bool greenpoint = false; //if green laser has been hit
bool hitflag = false; //checks if 'size' has already been minused

int micro_sensor = 46; //to detect if users are within the area

long int start = 0;
long int four_mins = 240000; //240000 = 4 mins
bool GreenLaserTime = false;
void setup() {
  Serial.begin(9600);
  pinMode(pointbutton, INPUT_PULLUP);
  pinMode(micro_sensor, INPUT);
  delay(1000);

  //initialise and turn all lasers off
  for (int x = 0; x < sizeof(sensors)/sizeof(sensors[0]); x++)
  {
      pinMode(sensors[x], INPUT);  
  }


  for (int x = 0; x < sizeof(lasers)/sizeof(lasers[0]); x++)
  {
      pinMode(lasers[x], OUTPUT);
      digitalWrite(lasers[x], HIGH);
  }
  delay(1000);
}


void loop()
{
  int size = 0;
  Serial.println("Start");

  start = millis(); //start timer

 // int levelone[] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,22,23,24}; //used for testing
 // int sen1[] = {30, greensen1}; //2 7

    //Level 1
    
  int levelone[] = {2, greenlaser1}; // 2 7
  int sen1[] = {34, greensen1}; // 2 7
  size = sizeof(levelone)/sizeof(levelone[0]);
  ExecuteLevel(levelone, size, sen1);

    //Level 1.1
  int level24[] = {2, 3, 8, greenlaser1}; // 
  int sen24[] = {34, 30, 38, greensen1}; // 
  size = sizeof(level24)/sizeof(level24[0]);
  ExecuteLevel(level24, size, sen24);


    //Level 4
 // Serial.println("Level 4");
  int levelfour[] = {7, 11, 15, greenlaser2}; // 6 10 14 18
  int sen4[] = {25, 26, 29, greensen2}; // 6 10 14 18
  size = sizeof(levelfour)/sizeof(levelfour[0]);
  ExecuteLevel(levelfour, size, sen4);

    //Level 3
  //Serial.println("Level 3");
  int levelthree[] = {3, 6, 9, greenlaser2}; // 2 5 8 18
  int sen3[] = {30, 35, 41, greensen2}; // 2 5 8 18
  size = sizeof(levelthree)/sizeof(levelthree[0]);
  ExecuteLevel(levelthree, size, sen3); 

//  
    //Level 2
  //Serial.println("Level 2");
  int leveltwo[] = {3, 8, 2, greenlaser1}; //2 7 1 17
  //int leveltwo[] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,22,23,24};
  int sen2[] = {30, 38, 34, greensen1}; //2 7 1 17
  size = sizeof(leveltwo)/sizeof(leveltwo[0]);
  ExecuteLevel(leveltwo, size, sen2);
 
//  
    //Level 5
  //Serial.println("Level 5");
  int levelfive[] = {2, 7, 8, 15, greenlaser1}; // 1 6 7 14 18
  int sen5[] = {34, 25, 38, 29, greensen1}; // 1 6 7 14 18
  size = sizeof(levelfive)/sizeof(levelfive[0]);
  ExecuteLevel(levelfive, size, sen5);
 
    //Level 6
  //Serial.println("Level 6");
  int levelsix[] = {6, 9, 11, 13, 15, greenlaser1}; // 5 8 10 12 14 17
  int sen6[] = {35, 41, 26, 27, 29, greensen1}; // 5 8 10 12 14 17
  size = sizeof(levelsix)/sizeof(levelsix[0]);
  ExecuteLevel(levelsix, size, sen6);
 
    //Level 7
  //Serial.println("Level 7");
  int levelseven[] = {3, 4, 7, 10, 11, greenlaser1}; // 3 8 9 10 17
  int sen7[] = {30, 40, 36, 25, 26, greensen1}; // 3 8 9 10 17
  size = sizeof(levelseven)/sizeof(levelseven[0]);
  ExecuteLevel(levelseven, size, sen7);
   
    //Level 7.1
  //Serial.println("Level 7");
  int level25[] = {2, 7, 11, 12, greenlaser1}; // 1 6 10 11 17
  int sen25[] = {34, 25, 26, 28, greensen1}; // 1 6 10 11 17
  size = sizeof(level25)/sizeof(level25[0]);
  ExecuteLevel(level25, size, sen25);

  //Level 8
  int level22[] = {10, 11, 12, 13, 14, greenlaser1}; // 9 10 11 12 13 17
  int sen22[] = {36, 26, 28, 27, 39, greensen1}; // 9 10 11 12 13 17
  size = sizeof(level22)/sizeof(level22[0]);
  ExecuteLevel(level22, size, sen22);

  //Level 8
  int level23[] = {2, 3, 4, 5, 6, 8, 9, greenlaser1}; // 1 2 3 4 5 7 8
  int sen23[] = {34, 30, 40, 37, 35, 38, 41, greensen1}; // 9 10 11 12 13 17
  size = sizeof(level23)/sizeof(level23[0]);
  ExecuteLevel(level23, size, sen23);
 
    //Level 8
  //Serial.println("Level 8");
  int leveleight[] = {11, 12, 13, 15, 16, 8, 2, greenlaser2}; // 10 11 12 14 15 18
  int sen8[] = {26, 28, 27, 29, 33, 38, 34, greensen2}; // 10 11 12 18 14 15  
  size = sizeof(leveleight)/sizeof(leveleight[0]);
  ExecuteLevel(leveleight, size, sen8);
 
    //Level 9
  //Serial.println("Level 9");
  int levelnine[] = {7, 8, 4, 9, 11, 14, 16, greenlaser2}; // 6 7 3 8 10 13 15
  int sen9[] = {25, 38, 40, 41, 26, 39, 33, greensen2}; // 6 7 3 8 10 13 15
  size = sizeof(levelnine)/sizeof(levelnine[0]);
  ExecuteLevel(levelnine, size, sen9);
 
    //Level 10
 // Serial.println("Level 10");
  int levelten[] = {7, 8, 9, 11, 14, 15, 16, greenlaser2}; // 6 7 8 10 18 13 14 15 18
  int sen10[] = {25, 38, 41, 26, 39, 29, 33, greensen2}; // 6 7 8 10 18 13 14 15 18
  size = sizeof(levelten)/sizeof(levelten[0]);
  ExecuteLevel(levelten, size, sen10);
 
    //Level 11
 // Serial.println("Level 11");
  int level11[] = {7, 8, 9, 6, 15, 11, 4, 10, greenlaser1}; // 6 7 8 5 14 10 3 9 17
  int sen11[] = {25, 38, 41, 35, 29, 26, 40, 36, greensen1}; //
  size = sizeof(level11)/sizeof(level11[0]); 
  ExecuteLevel(level11, size, sen11);

    //Level 12
 // Serial.println("Level 12");
  int level12[] = {22, 7, 15, 14, 8, 2, 6, 10, greenlaser2}; // 16 6 14 13 7 1 5 8 18
  int sen12[] = {31, 25, 29, 39, 38, 34, 35, 36, greensen2}; // 
  size = sizeof(level12)/sizeof(level12[0]);
  ExecuteLevel(level12, size, sen12);

    //Level 13
 // Serial.println("Level 13");
  int level13[] = {7, 8, 9, 6, 11, 14, 15, greenlaser2}; // 
  int sen13[] = {25, 38, 41, 35, 26, 39, 29, greensen2}; // 
  size = sizeof(level13)/sizeof(level13[0]);
  ExecuteLevel(level13, size, sen13);
//  
    //Level 13
  int level26[] = {2, 8, 3, 9, 10, 11, 16, 22, greenlaser2}; // 1 7 2 8 9 10 15 16
  int sen26[] = {34, 38, 30, 41, 36, 26, 33, 31, greensen2}; // 
  size = sizeof(level26)/sizeof(level26[0]);
  ExecuteLevel(level26, size, sen26);

    //Level 14
  int level14[] = {2, 8, 3, 9, 16, 13, 15, 11, greenlaser2}; // 
  int sen14[] = {34, 38, 30, 41, 33, 27, 29, 26, greensen2}; // 
  size = sizeof(level14)/sizeof(level14[0]);
  ExecuteLevel(level14, size, sen14);
 
    //Level 15
  int level15[] = {6, 7, 8, 4, 12, 13, 7, 14, 15, 16, greenlaser2}; // 
  int sen15[] = {35, 25, 38, 40, 28, 27, 25, 39, 29, 33, greensen2}; // 
  size = sizeof(level15)/sizeof(level15[0]);
  ExecuteLevel(level15, size, sen15);

    //Level 15.1
  int level27[] = {7, 8, 2, 12, 13, 11, 16, 15, 14, 22, greenlaser2}; // 6 7 1 11 12 10 15 14 13 16
  int sen27[] = {25, 38, 34, 28, 27, 26, 33, 29, 39, 31, greensen2}; // 
  size = sizeof(level27)/sizeof(level27[0]);
  ExecuteLevel(level27, size, sen27);

    //Level 16
  int level16[] = {2, 4, 6, 5, 9, 10, 7, 11, 22, 13, 14, 15, 16, greenlaser1}; // 
  int sen16[] = {34, 40, 35, 37, 41, 36, 25, 26, 31, 27, 39, 29, 33, greensen1}; // 
  size = sizeof(level16)/sizeof(level16[0]);
  ExecuteLevel(level16, size, sen16);

      //Level 17
  int level17[] = {2, 3, 5, 6, 8, 9, 10, 11, 7, 12, 13, 14, 15, 16, 22, greenlaser2}; // 
  int sen17[] = {34, 30, 37, 35, 38, 41, 36, 26, 25, 28, 27, 39, 29, 33, 31, greensen2}; // 
  size = sizeof(level17)/sizeof(level17[0]);
  ExecuteLevel(level17, size, sen17);

      //Level 18
  int level18[] = {2, 3, 4, 5, 6, 8, 9, 10, 11, 7, 12, 13, 14, 15, 16, 22, greenlaser2}; // 
  int sen18[] = {34, 30, 40, 37, 35, 38, 41, 36, 26, 25, 28, 27, 39, 29, 33, 31, greensen2}; // 
  size = sizeof(level18)/sizeof(level18[0]);
  ExecuteLevel(level18, size, sen18);

      //Level 19
  int level19[] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,22, greenlaser2}; // 
  int sen19[] = {34, 30, 40, 37, 35, 25, 38, 41, 36, 26, 28, 27, 39, 29, 33, 31, greensen2}; // 
  size = sizeof(level19)/sizeof(level19[0]);
  ExecuteLevel(level19, size, sen19);

      //Level 20
  int level20[] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,22, greenlaser1}; // 
  int sen20[] = {34, 30, 40, 37, 35, 25, 38, 41, 36, 26, 28, 27, 39, 29, 33, 31, greensen1}; // 
  size = sizeof(level20)/sizeof(level20[0]);
  ExecuteLevel(level20, size, sen20);

      //Level 21
  int level21[] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,22, greenlaser2}; // 
  int sen21[] = {34, 30, 40, 37, 35, 25, 38, 41, 36, 26, 28, 27, 39, 29, 33, 31, greensen2}; // 
  size = sizeof(level21)/sizeof(level21[0]);
  ExecuteLevel(level21, size, sen21);

  Serial.println("Game Over");
  while(true)
  {

  } 
//  
}

void ExecuteLevel(int l_array[], int _size, int sen[])
{
  hitflag = false;
  int isLaserOn = false;
  bool flag2 = false;

  bool timecheck = checkTime();
  if(!timecheck) //remove green laser if not >=4mins
  {
    _size = _size - 1;
    flag2 = true;
  }
////// LOW = 1, HIGH = 0
  for(int i = 0; i < _size; i++) //laser
  {
    digitalWrite(l_array[i], LOW);
    //Serial.println(l_array[i]);
    isLaserOn = true;
  }
  //delay(3000000000);
  delay(2000);


  bool FLAG = false;
  //int r = 0;

  while(FLAG == false)
  {
    for(int x = 0; x < _size; x++) //sensor
    {

      int r = digitalRead(sen[x]);
     // Serial.print(r);
      
      if(r == 1 && (sen[x] == greensen1 || sen[x] == greensen2))
      {
        greenpoint = true;
        hitflag = true; 
        digitalWrite(l_array[x], HIGH);
        delay(150);
        _size = _size - 1;
      }

      else if(r == 1) //red laser has been touched
      {
        greenpoint = false; //loses green point if touched or entirely
        //Serial.println("Detected");
       //Serial.println(sen[x]);

        if(hitflag == false) //green laser no longer active for current level
        {
          if(timecheck) 
          {
            _size = _size - 1;
            digitalWrite(l_array[_size], HIGH);
            hitflag = true;
          }
        }

        for(int Y = 0; Y < _size; Y++) //switch off laser
        {
          //Serial.print(l_array[Y]);
          digitalWrite(l_array[Y], HIGH);
        }
        delay(10000); //10 sec wait
        //isClear();

        for(int i = 0; i < _size; i++) //laser on
        {
          //Serial.print(l_array[i]);
          digitalWrite(l_array[i], LOW);
        }
        wait(150);
      }

      if(digitalRead(pointbutton) == 0) //button pressed
      {
        if(greenpoint)
        {
          score++;
          greenpoint = false;
          hitflag = false;
        }
        score++;

        Serial.println(score);
       
        for(int Y = 0; Y < _size; Y++) //switch off laser
        {
          digitalWrite(l_array[Y], HIGH);
        }

        //// -- Remembers previous array when the next level starts which the sensors trigger. The code below prevents this -------///////

        for (int i = 0; i < _size; i++) //modifies every element in array to an abitary value to prevent false triggers in the next level(s)
        {
          sen[i] = 87;     
          l_array[i] = 88;  
        }
        wait(10000);
        //isClear();
        FLAG = true;
      }      
    }
    
  }
  //delay(4000);


  //delay(4000);
}

bool checkTime()
{
  
  if(millis() - start >= four_mins)
  {
    //Serial.println("over 4 son");
    return true;
  }
  return false;
}

bool isClear()
{
  //------ a 5 second delay will happen before this function is executed ------ //

  int start = millis();

  while (true)
  {
    //if nothing detected and >=2 seconds
    int end = millis();
    if(digitalRead(micro_sensor) == 1 && (end - start) >= 2000)
    {
      Serial.println(score);
      return false;
    }
    else
    {
      //if human is detected within area
      if(digitalRead(micro_sensor) == 0)
      {
        Serial.println("Return to Start");
        delay(5000); //5 seconds
        start = millis();
      }
    }
  }
}

void wait(int sec)
{
  //delay(10000);

  int start = millis();
  int end = 0;

  while(true)
  {
    end = millis();

    if(end - start >= sec)
    {
      return true;
    }
  }
  return false;
}