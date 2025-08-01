//buzzer.ino  Designed By @kid_Ocelot for Arduino Uno Boards
//Explanation: pn(999,nT) constructs an vibration that is clearly unhearable to "delay"


//Song:死别


//Function    Translate Frequency Based on Half notes   0,2,4,6,7,9,11,12
#define tF(base,n) (base * pow(2, (n)/12.0))


const int outputPin = 3;  // 可以使用数字引脚3,5,6,9,10,11
const int outputPin1 = 9;
const int outputPin2 = 10;
const float bpm = 90; // for 四分音符
const int offset_halfnotes = -12;


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
    dist = dist + offset_halfnotes;
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
pn(28,5.33333);
pn(26,5.33333);
pn(999,16);
pn(28,32);
pn(26,32);
pn(24,4);
pn(31,4);
pn(33,8);
pn(31,8);
pn(28,16);
pn(31,32);
pn(28,32);
pn(24,8);
pn(26,8);
pn(28,16);
pn(26,16);
pn(24,8);
pn(26,8);
pn(28,8);
pn(999,8);
pn(24,8);
pn(23,8);
pn(24,8);
pn(999,8);
pn(28,8);
pn(999,8);
pn(29,8);
pn(28,8);
pn(26,8);
pn(24,8);
pn(26,8);
pn(28,16);
pn(26,16);
pn(24,8);
pn(23,8);


pn(24,4);
pn(28,8);
pn(26,8);
pn(24,8);
pn(31,8);
pn(999,8);
pn(33,8);
pn(31,8);
pn(28,10.66666);
pn(31,32);
pn(28,32);
pn(24,8);
pn(26,8);
pn(28,16);
pn(26,16);
pn(24,8);
pn(26,8);
pn(28,8);
pn(999,8);
pn(21,8);
pn(23,8);
pn(24,8);
pn(999,8);
pn(28,8);
pn(999,8);
pn(29,8);
pn(28,8);
pn(26,8);
pn(24,8);
pn(26,8);
pn(28,16);
pn(26,16);
pn(24,8);
pn(23,8);
pn(24,5.3333);

delay(9999999999);
}