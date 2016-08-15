<h1>Arduino Clock</h1>
Clock using an Arduino UNO R3, LCD1602, &amp; RTC DS3231

<!--- Parts List !--->
<h2>Parts List</h2>
<ul>
  <li>Arduino UNO R3</li>
  <li>LCD1602 16x2</li>
  <li>RTC DS3132</li>
  <li>Push Buttons (5)</li>
  <li>On/Off Switch</li>
  <li>10k&Omega; Resistor (6)</li>
</ul>
<!--- Schematic Diagram !--->
<h2>Schematic</h2>
<img src = "https://4.bp.blogspot.com/yGKnDue2d4s/V7FKZIpT_aI/AAAAAAAAAjM/x6ymeUM7dPQIYxDF7Zf0gHShdZVsBk6eQCLcB/s1600/Arduino_Clock.jpg" alt="Breadboard Schematic" width="600" height="400">
<!-- Description !--->
<h2>Description</h2>
<p>
    The purpose of this project is to create a functional clock that displays the current time and date.
    In order for the program to function properly changes were made to the DS3231.h library, since they 
    did not contain functions to set the hours, minutes, day, and month separately. I uploaded the library
    with the changes to this repository. After compiling and uploading the code to the Arduino UNO, the
    user will have to set the date and time using the appropriate push buttons (See description on the next section
    for complete pin description). The on/off button is used to enable (on) or disable (off) the backlight of the LCD1602.
    <br />
    The first row of the LCD1602 16x2 displays the date in the following format: MM/DD/YYYY.<br />
    The second row of the LCD1602 16x2 displays the current time in the following format: HH:MM:SS.<br />
    This clock system is able to determine if the current year is a leap year or not.<br />
    The clock system updates the date automatically.<br />
</p>
<h2>Arduino Pin Description</h2>
<ul>
  <li>Digital Pin 8 is connected to the On/Off Switch to turn On/Off of the backlight of the LCD1602.</li>
  <li>Digital Pin 9 is connected to a push button used to reset the seconds on the clock.</li>
  <li>Digital Pin 10 is connected to a push button used to increment the minutes on the clock.</li>
  <li>Digital Pin 11 is connected to a push button used to increment the hours on the clock.</li>
  <li>Digital Pin 12 is connected to a push button used to increment the days on the clock.</li>
  <li>Digital Pin 13 is connected to a push button used to increment the months on the clock.</li>
  <li>Analog Pin 4 (SDA) is connected to the SDA of the RTC DS3132.</li>
  <li>Analog Pin 5 (SCL) is connected to the SCL of the RTC DS3132.</li>
  <li>Arduino Pin SCL is connected to the SCL of the LCD1602.</li>
  <li>Arduino Pin SDA is connected to the SDA of the LCD1602.</li>
</ul>
