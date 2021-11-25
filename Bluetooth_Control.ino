#define ledpin 3
#define led1 4
#define led2 5
#define led3 6
#define led4 7
#define led5 8
#define fan1 9
#define fan2 10
#define fan3 11
#define fan4 12
#define fan5 13
struct Bluetooth_Control
{
    byte devices[10] = {
        led1,
        led2,
        led3,
        led4,
        led5,
        fan1,
        fan2,
        fan3, 
        fan4,
        fan5
    };
    void initializeDevice()
    {
        for(byte i = 0; i < 10; ++i)
        {
            pinMode(devices[i], 1);
            digitalWrite(devices[i], 0);
        }
        pinMode(ledpin, 1);
        for(byte i = 0; i < 3; ++i)
        {
            digitalWrite(ledpin, 1);
            delay(200);
            digitalWrite(ledpin, 0);
            delay(200);
        }
        Serial.begin(9600);
    }
    void runLoop()
    {
        if(Serial.available())
        {
            char data = Serial.read();
            if(data == 'A')
            {
                digitalWrite(led1, 1);
            }
            else if(data == 'a')
            {
                digitalWrite(led1, 0);
            }
            else if(data == 'B')
            {
                digitalWrite(led2, 1);
            }
            else if(data == 'b')
            {
                digitalWrite(led2, 0);
            }
            else if(data == 'C')
            {
                digitalWrite(led3, 1);
            }
            else if(data == 'c')
            {
                digitalWrite(led3, 0);
            }
            else if(data == 'D')
            {
                digitalWrite(led4, 1);
            }
            else if(data == 'd')
            {
                digitalWrite(led4, 0);
            }
            else if(data == 'E')
            {
                digitalWrite(led5, 1);
            }
            else if(data == 'e')
            {
                digitalWrite(led5, 0);
            }
            else if(data == 'F')
            {
                digitalWrite(fan1, 1);
            }
            else if(data == 'f')
            {
                digitalWrite(fan1, 0);
            }
            else if(data == 'G')
            {
                digitalWrite(fan2, 1);
            }
            else if(data == 'g')
            {
                digitalWrite(fan2, 0);
            }
            else if(data == 'H')
            {
                digitalWrite(fan3, 1);
            }
            else if(data == 'h')
            {
                digitalWrite(fan3, 0);
            }
            else if(data == 'I')
            {
                digitalWrite(fan4, 1);
            }
            else if(data == 'i')
            {
                digitalWrite(fan4, 0);
            }
            else if(data == 'J')
            {
                digitalWrite(fan5, 1);
            }
            else if(data == 'j')
            {
                digitalWrite(fan5, 0);
            }
            else {
                Serial.flush();
            }

        }
    }
};
Bluetooth_Control bControl;

void setup()
{
    bControl.initializeDevice();
    
}

void loop()
{
    bControl.runLoop();
}