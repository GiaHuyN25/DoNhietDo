#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT11.h>

LiquidCrystal_I2C lcd(0x27,16,2);

#define DHTPIN 2
#define DHTTYPE DHT11

DHT11 dht11(2);

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Connected");
  pinMode(9, OUTPUT);
}

void loop() {
  delay(1000);
  lcd.clear();

  //Lấy thông số nhiệt độ độ ẩm
  int h = dht11.readHumidity();
  int t = dht11.readTemperature();

  //Nếu Nhiệt độ lớn hơn 30 độ thì bật động cơ
  if(t > 30){
    digitalWrite(9,HIGH);
  }else{
    digitalWrite(9,LOW);
  }

  //Hiển thị Nhiệt độ (Kệ mấy dòng điều kiện ở if - else, chỉ quan tâm dòng lệnh nếu if đúng)
  if (t != DHT11::ERROR_CHECKSUM && t != DHT11::ERROR_TIMEOUT) {
    lcd.setCursor(0,0);
    lcd.print("Nhiet do: ");
    lcd.print(t);
    lcd.print(" C");
  } else {
    lcd.print(DHT11::getErrorString(t));
  }


  //Hiển thị Độ ẩm
  if (h != DHT11::ERROR_CHECKSUM && h != DHT11::ERROR_TIMEOUT) {
    lcd.setCursor(0,1);
    lcd.print("Do am: ");
    lcd.print(h);
    lcd.println(" %");
    } else {
    lcd.println(DHT11::getErrorString(h));
    }

  
}
