Đây là mạch điều khiển động cơ DC dựa trên nhiệt độ
(Yêu cầu proteus 8.17)

Mạch  này gồm
	+ Arduino UNO (AU) giao tiếp với LCD qua module I2C
	+ AU kết nối với DHT11 qua chân 2 để đo 
	+ AU kết nối với relay qua chân 9

Cách chạy file:
Add 2 file zip thư viện trong thư mục "Library" - Sketch/Include Library/Add .ZIP Library...
Thêm thư viện Arduino vào proteus (Google có)
Chạy file code, sau đó trong phần terminal (chạy code), copy tên file có đuôi .ino.elf ở gần cuối
Vào proteus, nhấn vào Arduino và dán đường dẫn vào dòng Program File
Chạy Proteus

Tệp sẽ được cập nhật khi có thay đổi về mạch.