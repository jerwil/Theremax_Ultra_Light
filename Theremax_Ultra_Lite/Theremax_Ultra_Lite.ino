// Simplified version of Theremax

int analogPin = 0;
int redPin = 9;
int greenPin = 10;
int bluePin = 11;

int analog_val; // Analog input from sensor
int note_val; // The current note to play and light color to choose
int sensor_limit = 1024; // The max analog value we look for in the sensor
int divisions = 8; // Number of notes in the range

void setup()
{
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
    Serial.begin(9600);
}

int color_array[][3] = {
{255,0,0},       // Red
{250,40,0},      // Orange
{250, 105, 0},   // Yellow
{0, 255, 0},     // Green
{10, 10, 255},   // Blue
{255, 0, 100},   // Pink
{200, 0, 255},   // Violet
{255, 255, 255}  // White
};

void loop()
{

analog_val = analogRead(analogPin);

note_val = analog_val/(sensor_limit / 8); 

Serial.println(analog_val);
Serial.println(note_val);

setColor(color_array[note_val]);
  
//int i;
//for (i = 0; i < 8; i = i + 1){
//  setColor(color_array[i]);     
//    delay(1000);
//}

}

void setColor(int input_array[3])
{
    analogWrite(redPin, 255-input_array[0]);
    analogWrite(greenPin, 255-input_array[1]);
    analogWrite(bluePin, 255-input_array[2]);
}
