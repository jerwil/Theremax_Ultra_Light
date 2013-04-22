// Simplified version of Theremax

int analogPin = 0;
int redPin = 9;
int greenPin = 10;
int bluePin = 11;

int analog_val;
int sensor_limit = 1024;

void setup()
{
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
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
  
int i;
for (i = 0; i < 8; i = i + 1){
  setColor(color_array[i]);     
    delay(1000);
}

}

void setColor(int input_array[3])
{
    analogWrite(redPin, 255-input_array[0]);
    analogWrite(greenPin, 255-input_array[1]);
    analogWrite(bluePin, 255-input_array[2]);
}
