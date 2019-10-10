# Digital Timer
 
Include your responses to the bold questions below. Include snippets of code that explain what you did. Deliverables are due next Tuesday. Post your lab reports as README.md pages on your GitHub, and post a link to that on your main class hub page.

## Part A. Solder your LCD panel

<img src="/Soldered LCD.jpeg">

## Part B. Writing to the LCD
 
**a. What voltage level do you need to power your display?**

5V

**b. What voltage level do you need to power the display backlight?**

3V or 3.3V 
  
**c. What was one mistake you made when wiring up the display? How did you fix it?**

Forgot to connect the long breadboard vertically on both sides, saw the note in the page and fixed it right away.

**d. What line of code do you need to change to make it flash your name instead of "Hello World"?**

The line "lcd.print("hello, world!");", change the content to my name!


**e. Include a copy of your Lowly Multimeter code in your lab write-up.**

[Rei_Multimeter](//github.com/wendy039474/IDD-Fa19-Lab2/blob/master/Rei_s_Multimeter.ino)

## Part C. Using a time-based digital sensor

[Rei_Rotary Encoder](//youtu.be/vLo9KCTesTw)


## Part D. Make your Arduino sing!

**a. How would you change the code to make the song play twice as fast?**

There are two ways to do so :

1.Changing the line "int noteDuration = 1000 / noteDurations[thisNote];" to "int noteDuration = 500 / noteDurations[thisNote];".
 
2.Changing the line "int pauseBetweenNotes = noteDuration * 1.30;" to "int pauseBetweenNotes = noteDuration * 1.30 / 2;"

Both ways will make the delay of the system half time and make the song play twice as fast.

**b. What song is playing?**

Star Wars!!

## Part E. Make your own timer

**a. Make a short video showing how your timer works, and what happens when time is up!**

**b. Post a link to the completed lab report your class hub GitHub repo.**
