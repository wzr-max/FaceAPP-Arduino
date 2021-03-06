/*******************************************
  一个个人小项目，配套APP下载以及相关教程见
 http://pengzhihui.xyz/2017/02/22/faceapp/
*******************************************/
#include <FaceApp.h>

SoftwareSerial mySerial(10, 11); // RX为D10, TX为D11，可以自己任意修改
FaceApp obj((SoftwareSerial&)mySerial, 9600);  //实例化检测对象

void setup()
{
  obj.begin();      //初始化
  Serial.begin(9600);  //硬件串口用于调试
}

void loop()
{
  obj.routine();    //尽可能让这一句频繁运行

  if (obj.valid())  //检测数据是否更新
  {
    //获取面部表情
    Serial.print("Face type is:");
    switch (obj.getFace())
    {
      case 1://代表面无表情
        Serial.print("Common");
        break;
      case 2://代表开心
        Serial.print("Happy");
        break;
      case 3://代表难过
        Serial.print("Upset");
        break;
      case 4://代表惊讶
        Serial.print("Surprised");
        break;
    }

    //获取头部姿态 -- roll，yaw，pitch
    Serial.print("  Head orientation is:");
    Serial.print(obj.getRoll());
    Serial.print(",");
    Serial.print(obj.getYaw());
    Serial.print(",");
    Serial.print(obj.getPitch());

    //获取人脸坐标 -- x，y
    Serial.print("  Head position is:");
    Serial.print(obj.getX());
    Serial.print(",");
    Serial.println(obj.getY());
  }
  else
    Serial.println("Data not ready.");

  delay(100);
}