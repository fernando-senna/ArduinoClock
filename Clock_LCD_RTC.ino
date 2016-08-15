/*
 *  Author:       Fernando Do Nascimento
 *  Project:      Arduino Clock
 *  Date:         August 8, 2016
 *  Description:  Arduino Clock using a LCD 1602 & a RTC DS3231
 */

//Included Libraries
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DS3231.h>

//Button Configuration
const int lightPin = 8; 
const int secResetPin = 9;   
const int minPin = 10;
const int hourPin = 11;
const int dayPin = 12;
const int monthPin = 13;

//Initialize the LiquidCrystal_I2C library with the numbers of the interface pins
LiquidCrystal_I2C lcd(0x27,16,2); //Set the LCD address to 0x27 for a 16 chars and 2 line display

//Initialize the DS3231 using the hardware interface
DS3231 rtc(SDA, SCL);
int sec = 0;
int min = 0;
int hour = 0;
int day = 31;
int month = 12;
int year = 2015;

void setup() 
{
    //Setup serial connection
    Serial.begin(115200);

    //Initialize rtc object
    rtc.begin();

    rtc.setDate(day,month,year);
    rtc.setTime(hour,min,sec);
 
    Serial.println(rtc.getDateStr());
    
    lcd.init();
    lcd.backlight();

    pinMode(lightPin, INPUT);
    pinMode(secResetPin, INPUT);
    pinMode(minPin, INPUT);
    pinMode(hourPin, INPUT);
    pinMode(dayPin, INPUT);
    pinMode(monthPin, INPUT);
}

void loop() 
{
    //Set the cursor to column 15, row 0
    lcd.setCursor(3,0);
    
    lcd.print(rtc.getDateStr());

    lcd.setCursor(4,1);
    lcd.print(rtc.getTimeStr());

    //Resets the seconds on the clock
    if(digitalRead(secResetPin) == HIGH)
       rtc.setSeconds(0);

    //Increments the minutes on the clock
    if(digitalRead(minPin) == HIGH)
    {
        delay(200);
        
        min++;

        //Increment hour and reset minute on the clock
        if(min == 60)
        {
            min = 0;
            hour++;

            rtc.setHours((uint8_t)hour);
        }
        
        rtc.setMinutes((uint8_t) min);
    }

    //Increment the hours on the clock
    if(digitalRead(hourPin) == HIGH)
    {
        delay(200);

        hour++;

        if(hour == 24)
        {  
            day++;
            
            setDate();

            hour = 0;
        }   
        
        rtc.setHours((uint8_t) hour);
    }

    if(digitalRead(dayPin) == HIGH)
    {
        delay(200);

        day++;

        setDate();

        rtc.setDay((uint8_t)day);
    }

    if(digitalRead(monthPin) == HIGH)
    {
        delay(200);
        
        month++;

        if(month <= 12)
          setDate();

        else
        {
            year++;
            month = 1;
            setDate();
        }
    }
    
    //Turns backlight on & off based on the state of the switch
    if(digitalRead(lightPin) == HIGH)
        lcd.backlight();

    else
        lcd.noBacklight();
}

void setDate()
{
    //Determine if the current year is a leap year or not
    if(year % 4 == 0)
    {
        if(month == 2)
        {
            if(day == 30)
            {
                day = 1;
                month++;
            }
        }

        //Checks if the month has 31 days
        if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {   
            if(day == 32 && month != 12)
            {
                day = 1;
                month++;
            }

            if(day == 32 && month == 12)
            {
                day = 1;
                month = 1;
                year++;
            }
        }

        //Month has 30 days
        if(month == 4 || month == 6 || month == 9 || month == 11)
        {
            if(day == 31)
            {
                day = 1;
                month++;
            }
        }
    }

    else
    {
        //Checks if the month has 31 days
        if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {   
            if(day == 32 && month != 12)
            {
                day = 1;
                month++;
            }

            if(day == 32 && month == 12)
            {
                day = 1;
                month = 1;
                year++;
            }
        }

        if(month == 2)
        {
            if(day == 29)
            {
                day = 1;
                month++;
            }
        }

        if(month == 4 || month == 6 || month == 9 || month == 11)
        {
            if(day == 31)
            {
                day = 1;
                month++;
            }
        }
    }

    rtc.setDay((uint8_t)day);
    rtc.setMonth((uint8_t)month);
    rtc.setYear((uint8_t)year);
}

