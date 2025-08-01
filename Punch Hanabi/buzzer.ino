//buzzer.ino  Designed By @kid_Ocelot for Arduino Uno Boards
//Explanation: pn(999,nT) constructs an vibration that is clearly unhearable to "delay"



//Function    Translate Frequency Based on Half notes   0,2,4,6,7,9,11,12
#define tF(base,n) (base * pow(2, (n)/12.0))


const int outputPin = 3;  // 可以使用数字引脚3,5,6,9,10,11
const int outputPin1 = 9;
const int outputPin2 = 10;
const float bpm = 96; // for 四分音符

//Function   Calculate Duration Based on bpm and Notetype(For 四分音符 use noteType=4)
float nd(int bpm, float noteType) {
    return (240000.0f / bpm) / noteType; // 返回毫秒时间
}

//Legacy   input Frequency,Duration
void pnfd(float freq, float duration, float delay_before = 0, int pin = outputPin) {
  
  //if(delay_before > 0) {
  //  delay(delay_before * 1000);
  //}
  
  if(freq > 0) {
    tone(pin, freq, duration * 1000);
    delay(duration * 1000);
    noTone(pin);
  } else {
    delay(duration * 1000);
  }
}

//Legacy  input Distance from Base,Duration(s)
void pnd(int dist, float duration, float delay_before = 0, int pin = outputPin) {

    tone(pin, tF(216.63,dist), duration * 1000);
    delay(duration * 1000);
    noTone(pin);
}

//Method 1:Single Thread   Buzzer No.1 (tF(BaseFreq,distance),as C4=216.63)   eg:pn(0,4)
void pn(int dist, float noteType, int pin = outputPin, float bpm_i=bpm) {
    if(dist<100 and dist>-100){tone(pin, tF(216.63,dist), nd(bpm_i,noteType));}
    delay(nd(bpm_i,noteType));
    if(dist<100 and dist>-100){noTone(pin);}
}


//Method 2:Multiple Notes For Chords

//Play 2 notes p2n(0,4,4,4)   Issue:Unable to play Chord on A.Uno
void p2n(int dist1, int dist2, 
                     int noteType1, int noteType2,
                     int pin1 = outputPin, int pin2 = outputPin1, float bpm_i = bpm) {
    // 计算各音符持续时间
    float duration1 = nd(bpm_i, noteType1);
    float duration2 = nd(bpm_i, noteType2);
    
    // 取最长持续时间作为和弦总时长
    float maxDuration = max(duration1, duration2);
    
    // 开始播放所有音符
    tone(pin1, tF(216.63, dist1));
    tone(pin2, tF(216.63, dist2));
    
    // 等待和弦持续时间
    delay(maxDuration); // 转换为毫秒
    
    // 停止所有音符
    noTone(pin1);
    noTone(pin2);
}

//Play 3 Notes p3n(0,2,4,4,4,4)
void p3n(int dist1, int dist2, int dist3, 
                     int noteType, int noteType1, int noteType2,
                     int pin1 = outputPin, int pin2 = outputPin1, int pin3 = outputPin2,float bpm_i = bpm) {
    // 计算各音符持续时间
    float duration1 = nd(bpm_i, noteType);
    float duration2 = nd(bpm_i, noteType1);
    float duration3 = nd(bpm_i, noteType2);
    
    // 取最长持续时间作为和弦总时长
    float maxDuration = max(duration1, max(duration2, duration3));
    
    // 开始播放所有音符
    tone(pin1, tF(216.63, dist1));
    tone(pin2, tF(216.63, dist2));
    tone(pin3, tF(216.63, dist3));
    
    // 等待和弦持续时间
    delay(maxDuration); // 转换为毫秒
    
    // 停止所有音符
    noTone(pin1);
    noTone(pin2);
    noTone(pin3);
}


void setup() {
  pinMode(outputPin, OUTPUT);
  pinMode(outputPin1, OUTPUT);
  pinMode(outputPin2, OUTPUT);
}

void loop() {
  
//1
  pn(14,8);
  pn(16,8);
  pn(19,8); 
  pn(12,8); 
  pn(14,8);
  pn(16,8);
  pn(19,8); 
  pn(12,8); 

  pn(14,8); 
  pn(16,8); 
  pn(19,8); 
  pn(21,8); 
  pn(14,8); 
  pn(16,8); 
  pn(9,8); 
  pn(12,8); 

  pn(14,8);
  pn(16,8);
  pn(19,8); 
  pn(12,8); 
  pn(14,8);
  pn(16,8);
  pn(19,8); 
  pn(12,8); 

  pn(14,8); 
  pn(16,8); 
  pn(19,8); 
  pn(21,8); 
  pn(14,8); 
  pn(16,8); 
  pn(9,8); 
  pn(12,8); 

//5
  pn(2,8);
  pn(4,8);
  pn(7,8);
  pn(0,8);
  pn(2,8);
  pn(4,8);
  pn(7,8);
  pn(0,8);

  pn(2,8);
  pn(4,8);
  pn(7,8);
  pn(9,8);
  pn(2,8);
  pn(4,8);
  pn(-3,8);
  pn(0,8);

  pn(2,8);
  pn(4,8);
  pn(7,8);
  pn(0,8);
  pn(2,8);
  pn(4,8);
  pn(7,8);
  pn(0,8);

  pn(2,8);
  pn(4,8);
  pn(7,8);
  pn(9,8);
  pn(2,8);
  pn(6,8);
  pn(6,8);
  pn(7,8);

//9
  pn(9,4);
  pn(12,8);
  pn(14,4);
  pn(11,8);
  pn(7,8);
  pn(5,8);
  
  pn(4,8);
  pn(7,8);
  pn(11,8);
  pn(12,8);
  pn(999,4);
  pn(12,8);
  pn(11,8);

  pn(9,4);
  pn(12,4);
  pn(11,8);
  pn(7,4);
  pn(7,8);

  pn(999,2);
  pn(999,4);
  pn(4,8);
  pn(7,8);

//13
  pn(9,4);
  pn(12,8);
  pn(14,4);
  pn(11,8);
  pn(7,8);
  pn(5,8);
  pn(4,8);
  pn(7,8);
  pn(11,8);
  pn(12,8);
  pn(999,4);
  pn(12,8);
  pn(11,8);
  pn(9,4);
  pn(12,4);
  pn(11,8);
  pn(7,8);
  pn(7,8);
  pn(7,8);
  pn(9,4);
  pn(999,2);
  pn(9,8);
  pn(11,8);

//17
  pn(12,2.66666);
  pn(11,8);
  pn(9,8);
  pn(11,8);
  pn(12,4);
  pn(999,8);
  pn(11,8);
  pn(9,8);
  pn(11,8);
  pn(12,8);
  pn(11,8);
  pn(7,8);
  pn(9,8);
  pn(7,8);
  pn(0,8);
  pn(0,8);
  pn(9,8);
  pn(7,8);
  pn(0,8);
  pn(2,8);
  pn(4,8);
  pn(999,2);
  pn(999,4);
  pn(9,8);
  pn(11,8);

//21
  pn(12,2.66666);
  pn(11,8);
  pn(9,8);
  pn(11,8);
  pn(12,4);
  pn(999,8);
  pn(11,8);
  pn(9,8);
  pn(11,8);
  pn(12,8);
  pn(14,8);
  pn(16,8);
  pn(17,8);
  pn(999,8);
  pn(12,8);
  pn(12,8);
  pn(16,8);
  pn(14,8);
  pn(12,8);
  pn(12,4);
  pn(999,1.33333);
  pn(16,8);
  pn(19,16);
  pn(16,16);
  
//25
  pn(14,8);
  pn(0,8);
  pn(9,16);
  pn(12,8);
  pn(14,16);
  pn(999,4);
  pn(16,8);
  pn(19,16);
  pn(16,16);
  pn(14,8);
  pn(12,8);
  pn(9,16);
  pn(12,8);
  pn(12,16);
  pn(999,4);
  pn(16,8);
  pn(19,16);
  pn(16,16);
  pn(14,4);
  pn(16,16);
  pn(19,8);
  pn(19,16);
  pn(999,16);
  pn(21,5.33333);
  pn(19,16);
  pn(17,16);
  pn(16,8);
  pn(999,8);
  pn(14,16);
  pn(16,16);
  pn(19,16);
  pn(21,16);
  pn(16,16);
  pn(14,16);
  pn(16,4);
  pn(16,8);
  pn(19,16);
  pn(16,16);

//29
  pn(14,8);
  pn(12,8);
  pn(9,16);
  pn(12,8);
  pn(14,16);
  pn(999,4);
  pn(16,8);
  pn(19,16);
  pn(16,8);
  pn(14,8);
  pn(12,8);
  pn(7,16);
  pn(12,8);
  pn(12,16);
  pn(999,4);
  pn(12,16);
  pn(11,16);
  pn(9,16);
  pn(11,16);
  pn(9,4);
  pn(14,4);
  pn(11,8);
  pn(9,8);
  pn(11,8);
  pn(11,8);
  pn(999,8);
  pn(12,8);
  pn(999,2);
  pn(999,4);

//33
  pn(2,8);
  pn(4,8);
  pn(7,8);
  pn(0,8);
  pn(2,8);
  pn(4,8);
  pn(7,8);
  pn(0,8);
  pn(2,8);
  pn(4,8);
  pn(7,8);
  pn(0,8);
  pn(2,8);
  pn(4,8);
  pn(7,8);
  pn(0,8);
  pn(2,8);
  pn(4,8);
  pn(7,8);
  pn(0,8);
  pn(2,8);
  pn(4,8);
  pn(7,8);
  pn(0,8);
  pn(2,8);
  pn(4,8);
  pn(7,8);
  pn(0,8);
  pn(2,8);
  pn(4,8);
  pn(999,8);
  pn(12,16);
  pn(14,16);

//37
  pn(16,8);
  pn(14,16);
  pn(12,16);
  pn(12,8);
  pn(9,16);
  pn(11,16);
  pn(12,8);
  pn(11,16);
  pn(9,16);
  pn(7,8);
  pn(4,16);
  pn(7,16);
  pn(9,8);
  pn(11,16);
  pn(12,16);
  pn(11,16);
  pn(7,16);
  pn(7,16);
  pn(9,16);
  pn(7,4);
  pn(4,16);
  pn(4,16);
  pn(5,16);
  pn(7,16);
  pn(9,8);
  pn(11,16);
  pn(12,16);
  pn(11,8);
  pn(12,16);
  pn(14,16);
  pn(16,8);
  pn(14,16);
  pn(12,16);
  pn(11,8);
  pn(7,16);
  pn(7,16);
  pn(999,8);
  pn(12,16);
  pn(14,16);
  pn(16,8);
  pn(14,16);
  pn(16,16);
  pn(19,16);
  pn(21,16);
  pn(16,16);
  pn(14,16);
  pn(16,8);
  pn(12,16);
  pn(14,16);

//41
  pn(16,8);
  pn(14,16);
  pn(12,16);
  pn(12,8);
  pn(9,16);
  pn(11,16);
  pn(12,8);
  pn(11,16);
  pn(9,16);
  pn(7,8);
  pn(7,16);
  pn(7,16);
  //42
}