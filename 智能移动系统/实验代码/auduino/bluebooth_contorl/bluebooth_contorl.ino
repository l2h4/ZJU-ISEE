//============================亚博智能========================================
//  智能小车蓝牙遥控实验
//=============================================================================
#include <SoftwareSerial.h>
SoftwareSerial BT(0,1);
char command;
#define run_car     1//按键前
#define back_car    2//按键后
#define left_car    3//按键左
#define right_car   4//按键右
#define stop_car    0//按键停
#define left_turn   0x06//按键左旋转
#define right_turn  0x07//按键右旋转
/*小车运行状态枚举*/
enum{
  enSTOP = 0,
  enRUN,
  enBACK,
  enLEFT,
  enRIGHT
}enCarState;
//==============================
//
//车速控制量 control
#define level1  0x08//速度控制标志位1
#define level2  0x09//速度控制标志位2
#define level3  0x0A//速度控制标志位3
#define level4  0x0B//速度控制标志位4
#define level5  0x0C//速度控制标志位5
#define level6  0x0D//速度控制标志位6
#define level7  0x0E//速度控制标志位7
#define level8  0x0F//速度控制标志位8
//==============================
//==============================
int Left_motor_go=5;     //左电机后退(IN1)
int Left_motor_back=9;     //左电机前进(IN2)

int Right_motor_go=6;    // 右电机前进(IN3)
int Right_motor_back=10;    // 右电机后退(IN4)
//int buzzer = 8;//设置控制蜂鸣器的数字IO脚

const int SensorRight_2 = 2;   	//右红外传感器(P3.5 OUT4)
const int SensorLeft_2 = 4;     //左红外传感器(P3.4 OUT3)
const int SensorRight = 8;   	//右循迹红外传感器(P3.2 OUT1)
const int SensorLeft = 7;     	//左循迹红外传感器(P3.3 OUT2)
int SL_2;    //左红外传感器状态
int SR_2;    //右红外传感器状态
int SL;    //左循迹红外传感器状态
int SR;    //右循迹红外传感器状态

int control = 100;//PWM控制量
int incomingByte = 0;          // 接收到的 data byte
int inputString=0 ;         // 用来储存接收到的内容
boolean newLineReceived = false; // 前一次数据结束标志
boolean startBit  = false;  //协议开始标志
int g_carstate = enSTOP; //  1前2后3左4右0停止
/*超声波*/
int Echo = A5;  // Echo回声脚(P2.0)
int Trig =A4;  //  Trig 触发脚(P2.1)
int Distance = 0;
int Front_Distance = 0;//
int Left_Distance = 0;
int Right_Distance = 0;
String returntemp = ""; //存储返回值 

int myangle;//定义角度变量
int pulsewidth;//定义脉宽变量
int val;

/*舵机*/
int servopin = 3;  //设置舵机驱动脚到数字口2

/*后退*/
int Led = 13;
/*前进*/
int Fire = 12;

/*唱歌*/
//int speakerPin= 11;

/*所有音调*/
#define BL1 248
#define BL2 278
#define BL3 294
#define BL4 330
#define BL5 371
#define BL6 416
#define BL7 467

#define B1 495
#define B2 556
#define B3 624
#define B4 661
#define B5 742
#define B6 833
#define B7 935

#define BH1 990
#define BH2 1112
#define BH3 1178
#define BH4 1322
#define BH5 1484
#define BH6 1665
#define BH7 1869

#define NTC1 262
#define NTC2 294
#define NTC3 330
#define NTC4 350
#define NTC5 393
#define NTC6 441
#define NTC7 495

#define NTCL1 131
#define NTCL2 147
#define NTCL3 165
#define NTCL4 175
#define NTCL5 196
#define NTCL6 221
#define NTCL7 248

#define NTCH1 525
#define NTCH2 589
#define NTCH3 661
#define NTCH4 700
#define NTCH5 786
#define NTCH6 882
#define NTCH7 990

#define NTD0 -1
#define NTD1 294
#define NTD2 330
#define NTD3 350
#define NTD4 393
#define NTD5 441
#define NTD6 495
#define NTD7 556

#define NTDL1 147
#define NTDL2 165
#define NTDL3 175
#define NTDL4 196
#define NTDL5 221
#define NTDL6 248
#define NTDL7 278

#define NTDH1 589
#define NTDH2 661
#define NTDH3 700
#define NTDH4 786
#define NTDH5 882
#define NTDH6 990
#define NTDH7 1112

#define NTE1 330
#define NTE2 350
#define NTE3 393
#define NTE4 441
#define NTE5 495
#define NTE6 556
#define NTE7 624

#define NTEL1 165
#define NTEL2 175
#define NTEL3 196
#define NTEL4 221
#define NTEL5 248
#define NTEL6 278
#define NTEL7 312

#define NTEH1 661
#define NTEH2 700
#define NTEH3 786
#define NTEH4 882
#define NTEH5 990
#define NTEH6 1112
#define NTEH7 1248

//列出所有节拍
/*两只老虎C*/
/*int tune[]=                 //根据简谱列出各频率
{
 NTC1,NTC2,NTC3,NTC1,
 NTC1,NTC2,NTC3,NTC1,
 NTC3,NTC4,NTC5,
 NTC3,NTC4,NTC5,
 NTC5,NTC6,NTC5,NTC4,NTC3,NTC1,
 NTC5,NTC6,NTC5,NTC4,NTC3,NTC1,
 NTC2,NTCL5,NTC1,
 NTC2,NTCL5,NTC1
};
float durt[]=                   //根据简谱列出各节拍
{
  1,1,1,1,
  1,1,1,1,
  1,1,2,
  1,1,2,
  0.75,0.25,0.75,0.25,1,1,
  0.75,0.25,0.75,0.25,1,1,
  1,1,2,
  1,1,2
};*/

//小苹果
int tune[]=                 //根据简谱列出各频率
{
  B3, B1, B2, BL6,
  B3,B2,B1,B2,BL6,
  B3,B1,B2,B2,
  B5,B3,BL7,B1,B1,BL7,
  BL6,BL7,B1,B2,BL5,
  B6,B5,B3,B3,B2,
  B1,B2,B3,B2,B3,B2,B3,B5,
  B5,B5,B5,B5,B5,B5,
//  B3,B1,B2,BL6,
//  B3,B2,B1,B2,BL6,
//  B3,B1,B2,B2,B2,
//  B5,B3,BL7,B1,B1,BL7,
//  BL6,BL7,B1,B2,BL5,
//  B6,B5,B3,B3,B2,
//  B1,B2,B3,B2,BL5,
//  BL6,BL6,B1,BL6,B1
  
};
float durt[]=                   //根据简谱列出各节拍
{
  1,1,1,1,
  0.5,0.5,0.5,0.5,2,
  1,1,1,1,
  0.5,0.5,1,1,0.5,0.5,
  
  1,0.5,0.5,1,1,
  0.5,0.5,1,1.5,0.5,
  1,0.5,0.5,0.5,0.5,0.5,0.25,0.25,
  1,0.5,0.5,0.5,0.5,1,
  
//  1,1,1,1,
//  0.5,0.5,0.5,0.5,2,
//  1,1,1,0.5,0.5,
//  0.5,0.5,1,1,0.5,0.5,
//  
//  1,0.5,0.5,1,1,
//  0.5,0.5,1,1.5,0.5,
//  1,0.5,0.5,1,1,
//  1,0.5,0.5,1,1,1
};

void setup()
{
  //初始化电机驱动IO为输出方式
  BT.begin(9600);
  pinMode(Left_motor_go, OUTPUT); // PIN 5 (PWM)
  pinMode(Left_motor_back, OUTPUT); // PIN 9 (PWM)
  pinMode(Right_motor_go, OUTPUT); // PIN 6 (PWM)
  pinMode(Right_motor_back, OUTPUT); // PIN 10 (PWM)
  //pinMode(buzzer,OUTPUT);//设置数字IO脚模式，OUTPUT为输出 
  pinMode(Echo, INPUT);    // 定义超声波输入脚
  pinMode(Trig, OUTPUT);   // 定义超声波输出脚
  pinMode(SensorRight_2, INPUT);    // 定义右循迹输入脚
  pinMode(SensorLeft_2, INPUT);   // 定义左循迹输出脚
  pinMode(SensorRight, INPUT);    // 定义右红外输入脚
  pinMode(SensorLeft, INPUT);   // 定义左红外输出脚
  
  //Serial.begin(9600);	//波特率9600 （蓝牙通讯设定波特率）
 
  pinMode(servopin,OUTPUT);      //设定舵机接口为输出接口
  pinMode(Led, OUTPUT);   // 定义黄灯输出脚
  pinMode(Fire, OUTPUT);   // 定义红灯输出
  //pinMode(speakerPin, OUTPUT); //定义唱歌引脚
   
  //digitalWrite(buzzer,HIGH);    //不发声
 // digitalWrite(Led,HIGH);    
 // digitalWrite(Fire,HIGH);   

  
}

float Distance_test()   // 量出前方距离 
{
  digitalWrite(Trig, LOW);   // 给触发脚低电平2μs
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);  // 给触发脚高电平10μs，这里至少是10μs
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);    // 持续给触发脚低电
  float Fdistance = pulseIn(Echo, HIGH);  // 读取高电平时间(单位：微秒)
  Fdistance= Fdistance/58;       //为什么除以58等于厘米，  Y米=（X秒*344）/2
  // X秒=（ 2*Y米）/344 ==》X秒=0.0058*Y米 ==》厘米=微秒/58
  //Serial.print("Distance:");      //输出距离（单位：厘米）
  //Serial.println(Fdistance);         //显示距离
  return Fdistance;
}  

void run()     // 前进
{
   digitalWrite(Right_motor_back,LOW);        
   digitalWrite(Left_motor_back,LOW);
   digitalWrite(Right_motor_go,HIGH);  // 右电机前进
   digitalWrite(Left_motor_go,HIGH);  // 左电机前进
   digitalWrite(Led,HIGH);
   digitalWrite(Fire,LOW);
   analogWrite(Right_motor_go,control);//PWM比例0~255调速，左右轮差异略增减
   analogWrite(Left_motor_go,control);//PWM比例0~255调速，左右轮差异略增减
  //  delay(100);   //执行时间，可以调整
  //  digitalWrite(Right_motor_back,LOW);        
  //  digitalWrite(Left_motor_back,LOW);
  //  digitalWrite(Right_motor_go,LOW);  // 右电机前进
  //  digitalWrite(Left_motor_go,LOW);  // 左电机前进
  //  analogWrite(Right_motor_go,0);//PWM比例0~255调速，左右轮差异略增减
  //  analogWrite(Left_motor_go,0);//PWM比例0~255调速，左右轮差异略增减
}

void brake()         //刹车，停车
{
  digitalWrite(Left_motor_back, LOW);
  digitalWrite(Left_motor_go, LOW);
  digitalWrite(Right_motor_go, LOW);
  digitalWrite(Right_motor_back, LOW);
  digitalWrite(Led,LOW);
  digitalWrite(Fire,LOW);
  // delay(100);//执行时间，可以调整
}

void spin_left(int time)         //左转(左轮后退，右轮前进)
{
  digitalWrite(Right_motor_go,HIGH);	// 右电机前进
  digitalWrite(Right_motor_back,LOW);
  analogWrite(Right_motor_go,150); 
  analogWrite(Right_motor_back,0);//PWM比例0~255调速
  digitalWrite(Left_motor_go,LOW);   //左轮后退
  digitalWrite(Left_motor_back,HIGH);
  analogWrite(Left_motor_go,0); 
  analogWrite(Left_motor_back,150);//PWM比例0~255调速
  delay(time * 100);	//执行时间，可以调整  
}

void left()         //左转(左轮不动，右轮前进)
{
  digitalWrite(Right_motor_go, HIGH);	// 右电机前进
  digitalWrite(Right_motor_back, LOW);
  analogWrite(Right_motor_go, 150);//control);
  analogWrite(Right_motor_back,0);//PWM比例0~255调速
  digitalWrite(Left_motor_go, LOW);  //左轮不动
  digitalWrite(Left_motor_back, LOW);
  digitalWrite(Led,HIGH);
  digitalWrite(Fire,LOW);
  analogWrite(Left_motor_go,0);
  analogWrite(Left_motor_back,0);//PWM比例0~255调速
  // delay(100);	//执行时间，可以调整
  // digitalWrite(Right_motor_go, LOW);	//全部停止
  // analogWrite(Right_motor_go,0);
  // delay(100);	//执行时间，可以调整
}

void right()        //右转(右轮不动，左轮前进)
{
  digitalWrite(Right_motor_go, LOW);  //右电机不动
  digitalWrite(Right_motor_back, LOW);
  analogWrite(Right_motor_go,0);
  analogWrite(Right_motor_back,0);//PWM比例0~255调速
  digitalWrite(Left_motor_go, HIGH); //左电机前进
  digitalWrite(Left_motor_back, LOW);
  analogWrite(Left_motor_go,150);  //control);
  analogWrite(Left_motor_back,0);
  digitalWrite(Led,HIGH);
  digitalWrite(Fire,LOW);
  // delay(100);	//执行时间，可以调整
  // digitalWrite(Left_motor_go, LOW);	//全部停止
  // analogWrite(Left_motor_go,0);
  // delay(100);	//执行时间，可以调整
}

void spin_right(int time)        //右转(右轮后退，左轮前进)
{
  digitalWrite(Right_motor_go,LOW);   //右电机后退
  digitalWrite(Right_motor_back,HIGH);
  analogWrite(Right_motor_go,0); 
  analogWrite(Right_motor_back,100);//PWM比例0~255调速
  digitalWrite(Left_motor_go,HIGH);//左电机前进
  digitalWrite(Left_motor_back,LOW);
  analogWrite(Left_motor_go,100); 
  analogWrite(Left_motor_back,0);//PWM比例0~255调速
  delay(time * 100);	//执行时间，可以调整    
}

void back()          //后退
{
  digitalWrite(Right_motor_back, HIGH);
  digitalWrite(Left_motor_back, HIGH);
  digitalWrite(Right_motor_go, LOW); //右轮后退
  digitalWrite(Left_motor_go, LOW); //左轮后退

  analogWrite(Right_motor_back,control);//PWM比例0~255调速
  analogWrite(Left_motor_back,control);//PWM比例0~255调速
  digitalWrite(Led,LOW);
  digitalWrite(Fire,HIGH);
  // delay(100);     //执行时间，可以调整

  // digitalWrite(Right_motor_back, LOW);
  // digitalWrite(Left_motor_back, LOW);
  // analogWrite(Right_motor_back,0);//PWM比例0~255调速
  // analogWrite(Left_motor_back,0);//PWM比例0~255调速
  // delay(100);

}
// void whistle()   //鸣笛
// {
//     int i;
//     for(i=0;i<80;i++)//输出一个频率的声音
//     { 
//       digitalWrite(buzzer,HIGH);//发声音
//       delay(10);//延时1ms 
//       digitalWrite(buzzer,LOW);//不发声音
//       delay(1);//延时ms 
//     } 
//     for(i=0;i<100;i++)//输出另一个频率的声音 
//     { 
//       digitalWrite(buzzer,HIGH);//发声音
//       delay(20);//延时2ms 
//       digitalWrite(buzzer,LOW);//不发声音
//       delay(2);//延时2ms 
//     } 
// }

/*舵机控制*/
void servopulse(int servopin,int myangle)/*定义一个脉冲函数，用来模拟方式产生PWM值*/
{
  int pulsewidth;    //定义脉宽变量
  pulsewidth=(myangle*11)+500;//将角度转化为500-2480 的脉宽值
  digitalWrite(servopin,HIGH);//将舵机接口电平置高
  delayMicroseconds(pulsewidth);//延时脉宽值的微秒数
  digitalWrite(servopin,LOW);//将舵机接口电平置低
  delay(20-pulsewidth/1000);//延时周期内剩余时间
}
// void front_detection()
// {
//   //此处循环次数减少，为了增加小车遇到障碍物的反应速度
//   for(int i=0;i<=5;i++) //产生PWM个数，等效延时以保证能转到响应角度
//   {
//     servopulse(servopin,90);//模拟产生PWM
//   }
// }

void left_detection()
{
  for(int i=0;i<=15;i++) //产生PWM个数，等效延时以保证能转到响应角度
  {
    servopulse(servopin,175);//模拟产生PWM
  }
  Left_Distance=Distance_test();
}

void right_detection()
{
  for(int i=0;i<=15;i++) //产生PWM个数，等效延时以保证能转到响应角度
  {
    servopulse(servopin,5);//模拟产生PWM
  }
  Right_Distance=Distance_test();
}

/*唱歌相关*/
// void PlayTest()
// {
//  int length = sizeof(tune)/sizeof(tune[0]);   //计算长度
//  for(int x=0; x < length;x++)
//   {
//     tone(speakerPin,tune[x]);
//     delay(500*durt[x]);   //这里用来根据节拍调节延时，500这个指数可以自己调整，在该音乐中，我发现用500比较合适。
//     noTone(speakerPin);
//   }
  
// }

void tracking()
{
  while(1)
  {
  //有信号为LOW  没有信号为HIGH
    SR = digitalRead(SensorRight);//有信号表明在白色区域，车子底板上L3亮；没信号表明压在黑线上，车子底板上L3灭
    SL = digitalRead(SensorLeft);//有信号表明在白色区域，车子底板上L2亮；没信号表明压在黑线上，车子底板上L2灭

      if (SL == LOW&&SR==LOW){
        run();
      }   //调用前进函数
      else if (SL == HIGH & SR == LOW){// 左循迹红外传感器,检测到信号，车子向右偏离轨道，向左转 
        left();
      }
      else if (SR == HIGH & SL == LOW){ // 右循迹红外传感器,检测到信号，车子向左偏离轨道，向右转  
        right();
      }
      else{ // 都是白色, 停止
        brake();
      }
    
    if (BT.available())
    {
      command=BT.read();
      if(command=='p'){
        brake();break;
      }
    }
  }
  
}

void backs(int time)          //后退
{
  digitalWrite(Right_motor_go,LOW);  //右轮后退
  digitalWrite(Right_motor_back,HIGH);
  analogWrite(Right_motor_go,0);
  analogWrite(Right_motor_back,200);//PWM比例0~255调速
  digitalWrite(Left_motor_go,LOW);  //左轮后退
  digitalWrite(Left_motor_back,HIGH);
  analogWrite(Left_motor_go,0);
  analogWrite(Left_motor_back,200);//PWM比例0~255调速
  delay(time * 100);     //执行时间，可以调整  
}

void front_detection()
{
  //此处循环次数减少，为了增加小车遇到障碍物的反应速度
  for(int i=0;i<=5;i++) //产生PWM个数，等效延时以保证能转到响应角度
  {
    servopulse(servopin,90);//模拟产生PWM
  }
  Front_Distance = Distance_test();
  //Serial.print("Front_Distance:");      //输出距离（单位：厘米）
 // Serial.println(Front_Distance);         //显示距离
 //Distance_display(Front_Distance);
}

void brakes(int time)  //刹车，停车
{
  digitalWrite(Right_motor_go,LOW);
  digitalWrite(Right_motor_back,LOW);
  digitalWrite(Left_motor_go,LOW);
  digitalWrite(Left_motor_back,LOW);
  delay(time * 100);//执行时间，可以调整  
}



void lefts(int time)         //左转(左轮不动，右轮前进)
//void left()         //左转(左轮不动，右轮前进)
{
  digitalWrite(Right_motor_go,HIGH);	// 右电机前进
  digitalWrite(Right_motor_back,LOW);
  analogWrite(Right_motor_go,200); 
  analogWrite(Right_motor_back,0);//PWM比例0~255调速
  digitalWrite(Left_motor_go,LOW);   //左轮后退
  digitalWrite(Left_motor_back,LOW);
  analogWrite(Left_motor_go,0); 
  analogWrite(Left_motor_back,0);//PWM比例0~255调速
  delay(time * 100);	//执行时间，可以调整  
}

void rights(int time)
//void right()        //右转(右轮不动，左轮前进)
{
  digitalWrite(Right_motor_go,LOW);   //右电机后退
  digitalWrite(Right_motor_back,LOW);
  analogWrite(Right_motor_go,0); 
  analogWrite(Right_motor_back,0);//PWM比例0~255调速
  digitalWrite(Left_motor_go,HIGH);//左电机前进
  digitalWrite(Left_motor_back,LOW);
  analogWrite(Left_motor_go,200); 
  analogWrite(Left_motor_back,0);//PWM比例0~255调速
  delay(time * 100);	//执行时间，可以调整  
}

void servo(){
  while(1)
  {
    front_detection();//测量前方距离
    if(Front_Distance < 32)//当遇到障碍物时
    {
      backs(2);//后退减速
      brakes(2);//停下来做测距
      left_detection();//测量左边距障碍物距离
      right_detection();//测量右边距障碍物距离
      if((Left_Distance < 35 ) &&( Right_Distance < 35 ))//当左右两侧均有障碍物靠得比较近
        spin_left(0.7);//旋转掉头
      else if(Left_Distance > Right_Distance)//左边比右边空旷
      {      
        lefts(3);//左转
        brakes(1);//刹车，稳定方向
      }
      else//右边比左边空旷
      {
        rights(3);//右转
        brakes(1);//刹车，稳定方向
      }
    }
    else
    {
      run(); //无障碍物，直行     
    }

    if (BT.available())
    {
      command=BT.read();
      if(command=='e'){
        brake();break;
      }
    }
  }

}

void redfollow()
{
  while(1)
  {
    //有信号为LOW  没有信号为HIGH
    SR_2 = digitalRead(SensorRight_2);
    SL_2 = digitalRead(SensorLeft_2);
    if (SL_2 == LOW && SR_2==LOW)
      run();   //调用前进函数
    else if (SL_2 == LOW && SR_2 == HIGH)// 左边探测到有障碍物，有信号返回，向左转 
        left();
    else if (SR_2 == LOW && SL_2 == HIGH) //右边探测到有障碍物，有信号返回，向右转  
      right();
    else // 未检测到物体，停止运动
    {
      brake();
    }
    
    if (BT.available())
    {
      command=BT.read();
      if(command=='h'){
        brake();break;
      }
    }

  }
}
    
void loop() 
{  
  if (BT.available())
  {
    command=BT.read();
    switch(command)
    {
      case 'w':   g_carstate = enRUN; Serial.print("run\r\n"); break;
      case 's':  g_carstate = enBACK;  Serial.print("back\r\n");break;
      case 'a':  g_carstate = enLEFT; Serial.print("left\r\n");break;
      case 'd': g_carstate = enRIGHT; Serial.print("right\r\n");break;
      case 'x':  g_carstate = enSTOP; Serial.print("brake\r\n");break;
      case 't': tracking();g_carstate = enSTOP; break;
      case 'c': servo();g_carstate = enSTOP;break;
      case 'r': redfollow();g_carstate = enSTOP;break;
      default:g_carstate = enSTOP;break;
    }

    switch(g_carstate)
    {
      case enSTOP: brake();break;
      case enRUN:run();break;
      case enLEFT:left();break;
      case enRIGHT:right();break;
      case enBACK:back();break;
      default:brake();break;
    }
  }
}
  
//serialEvent()是IDE1.0及以后版本新增的功能，不清楚为什么大部份人不愿意用，这个可是相当于中断功能一样的啊!  
// void serialEvent()
// {
//   while (Serial.available()) 
//   {    
//     incomingByte = Serial.read();              //一个字节一个字节地读，下一句是读到的放入字符串数组中组成一个完成的数据包
//     if(incomingByte == '$')
//     {
//       startBit= true;
//     }
//     if(startBit == true)
//     {
//        inputString += (char) incomingByte;     // 全双工串口可以不用在下面加延时，半双工则要加的//
//     }  
//     if (incomingByte == '#') 
//     {
//        newLineReceived = true; 
//        startBit = false;
//     }
//   }
// }



