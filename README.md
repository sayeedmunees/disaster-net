# Disaster-Net
A project on implementing LoRa-based communication, aimed at developing efficient, low-power networks.
## Keypad and Oled code 1
Established esp32 connection with a keypad and Oled, Fixed dialing activated for Keys 1 and 2. When a key is pressed respective message is printed on the console and a "Sent" text is shown in the Oled confirming the data transfer. If a number without fixed dialing is pressed or no number is typed it will show not send in Oled and print no message typed in console.
### Currently available fixed dialing:
* 1 - Help Me
* 2 - Not Feeling Well

The code is simulated in wokwi and is working fine. The circuit diagram I used in wokwe is given below:
![alt text](https://github.com/sayeedmunees/[reponame]/blob/[branch]/image.jpg?raw=true)
