# ⌨ Ladispad
[![Visits Badge](https://badges.pufler.dev/visits/ajmandourah/Ladispad)](https://badges.pufler.dev) [![GitHub license](https://img.shields.io/github/license/ajmandourah/Ladispad)](https://github.com/ajmandourah/Ladispad/blob/main/LICENSE) [![GitHub forks](https://img.shields.io/github/forks/ajmandourah/Ladispad)](https://github.com/ajmandourah/Ladispad/network) ![GitHub all releases](https://img.shields.io/github/downloads/ajmandourah/Ladispad/total)

Ladispad is a custom-made 11 key macropad with 2 rotary encoders designed for the **simplicity** and the **ease of assembly to non technical users**. 
Macropad are not a new thing. Browsing the internet will lead to to dozens of open-source macropads that let you print your own PCB and assemble it at home, but most of these macropads uses matrixes which will force you to solder diodes adding a little complexity to the process.

Ladispad uses a **direct pin** approach , that means you **don't need to solder diodes**. Additionally I managed to add 2 rotary encoders and a fully customizable OLED screen which can be omitted if you choose so.

Ladispad uses a Pro Micro as its main controller. Its very affordable and have many varients with different USB ports and sizes. **I designed the PCB so it will be compatible which whatever you choose**.

![Ladispad PCB showing promicro compatibility](/images/IMG-20211108-WA0001.jpg) 

The macropad is QMK/Via and soon Vial compatible which will add to the ease of use in case you want to program your encoders on the fly without the need to flash the firmware everytime you do so.

Included even the SVG files for the acrylic cases I made for the pad. you can laser cut it using any of the online service providers you choose.

## 👍 What make Ladispad unique: 

- Minimal  components needed to have a fully functional macropad.
- 2 Rotary encoders implemented with extra function with layer switching.
- Compatible with different Pro Micros sizes,
- Acrylic case cutout included.

## 📃 Things you need to get the whole experience:

- Pro Micro. (micro USB, mini USB, USB-C).
- 9 cherry MX style switches.
- 2 Rotary Encoders (EC11)
- OLED display 128x32 (SSD1306)
- The laser cut acrylic case.
- 4 M3 screws.

## ⁉ How to make your own:

- Ordering the PCB.
  - Download the gerber.zip file from the release page.
  - Order the PCB from a PCB manifacture site, I have used PCBway and it cost 5$ + shipping for 5 PCBs.
- Making the Case
  - Download the case.zip file from the release page.
  - submit the files to a laser cutting service provider, or cut it yourself if you are blissed with a laser cutter. I can recommend Elecrow. pretty cheap and reliable.
  - The thickness of the parts is as follow:
    - The Top and bottom layers are **3 mm**
    - The middle layers (middle layer 1 and middle layer 2) are **8 mm**.
- Buy the parts listed above.
- Solder the promicro, switches, rotary encoders and the Oled screen.
- Either download the hex file from the release page and flash it before assembling the case. short the RESET and GND pins as i have not added a dedicated reset button, will be added in the future. you can also edit the QMK keymap file in the rep for more customizability. clone the repo if that is the case.
- Enjoy your new macropad.

## 📷 Images:

![](/images/20211129_065114-01.jpeg) 
![](/images/20211129_065213-01.jpeg)
![](/images/20211129_065248-01.jpeg)
