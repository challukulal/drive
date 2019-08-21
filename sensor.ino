int x;
int i;
int led=13;
int sensor=4;
void setup() 
{
  pinMode(led,OUTPUT);
  pinMode(sensor,INPUT);
  Serial.begin(9600);

wifi_init();
  
  // put your setup code here, to run once:

}

void loop() {
x=digitalRead(sensor);
Serial.print("x=");
Serial.print(x);
  if(x==0)
  {
    digitalWrite(led,HIGH);
    Serial.print("led on\n");
    
  }
  else
  {
    digitalWrite(led,LOW);
    Serial.print("led off\n");
 
  }
  i++;
  if(i>=1)
{
Serial.println(" sending to server");

 sendtoserver();
 i=0;
}
}

  // put your main code here, to run repeatedly:

  void sendtoserver()
{
        
                       Serial.print("sending");
                       // sensorValue = analogRead(A0);
                        //sensorValue1 =analogRead(A1);
                        serial_wifi_baud();
                        delay(100);
                        String temp="GET https://184.106.153.149/update?api_key=TG3S1X8MEFHOA9Z8&field1=";
                     // String temp="GET https://184.106.153.149/update?api_key=V11Z1QYWSQ0JVWG9&field1=";
                             temp+=String(10);
//                             Serial.print();
  //                           Serial.print(x);
//                             temp+="&field2=";
//                             temp+=String(x);//temp1
//                             temp+="&field3=";
//                             temp+=String(x);//temp1
//                           temp+="&field4=";
//                            temp+=String(x);//temp1
                             temp+="\r\n";
                    
                             temp+="\r\n\r\n\r\n";
                      Serial.println("AT+CIPSTART=\"TCP\",\"184.106.153.149\",80\r\n");
                      delay(2000);
                      //Serial.println("AT+CIPSEND=0,"+String(temp.length()));
                       //Serial.println("\r\n");
                     
                      Serial.println("AT+CIPSEND=x\r\n");
                      delay(2000);
                      Serial.println(temp);
                      //Serial.println("GET https://184.106.153.149/update?api_key=TG3S1X8MEFH0A9Z8&field1=70&field2=90\r\n");
                      //Serial.print("GET https://184.106.153.149/update?api_key=9FUQ5PCW9XIL6A2G&field1=");
                      //Serial.print(temp); 
                       Serial.print("\r\n");
                      delay(2000);
                      Serial.println("\r\n\r\n\r\n\r\n\r\n\r\n");
                      delay(2000); 
                      delay(2000); 
                      delay(2000); 
                       delay(2000); 
                      delay(2000); 
                      delay(2000); 

                     // temp='0';

}

void wifi_init()
{
  Serial.println("wifi");
   serial_wifi_baud();
  Serial.println("AT");
  delay(2000);
  Serial.println("AT+CWMODE=1");
  delay(2000);
  Serial.println("AT+CWLAP");
  delay(2000);  delay(2000);  delay(2000);
  Serial.println("AT+CWJAP=\"FD-29\",\"challukulal\"\r\n");     //change your user name and password here
  //Serial.println("AT+CWJAP=\"amrutha\",\"ammaappa\"\r\n");     //change your user name and password here
 
  delay(2000);
}
void serial_wifi_baud()
{
  Serial.begin(115200);
}
