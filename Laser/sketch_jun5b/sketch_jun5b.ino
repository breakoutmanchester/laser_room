int lasers[] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,22,23,24};
//int sensors[] = {25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41}; //6, 10, 12, 11, 14, 2, 16, 18, 15, 1. 5, 9, 4, 13. 3
int sensors[] = {34, 30, 40, 37, 35, 25, 38, 41, 36, 26, 28, 27, 39, 29, 33, 31, 42, 32}; //1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18 (17 missing (50))
String list = "";
void setup() {
  
  Serial.begin(9600);
  for (int x = 0; x < sizeof(sensors)/sizeof(sensors[0]); x++)
  {
      pinMode(sensors[x], INPUT);  
  }

  for (int x = 0; x < sizeof(lasers)/sizeof(lasers[0]); x++)
  {
      pinMode(lasers[x], OUTPUT);
      digitalWrite(lasers[x], LOW);
  }
  delay(1000);

}

void loop() 
{
  for (int x = 0; x < sizeof(lasers)/sizeof(lasers[0]); x++)
  {
    if(digitalRead(sensors[x]) == 1)
    {
      
      if(list == "")
      {
        list = x + 1;
      }
      
      else
      {
        list = list + ",";
        list = list + (x + 1);
      }
    }
  }

  Serial.println(list);
  delay(6);
  list = "";
}
