## What is this?
This is a C++ program for Windows Operating System. Once compiled into EXE, it can **change the wallpapers of your desktop according to current time of the day.**

## How to use it?
### Step 1(optional): Edit `wall.cpp` file and generate wall.exe file
By default the precompiled exe file present in this repo, will set **'img1.jpg'** for **Daytime**('6 AM' to '9 PM'). And **'img2.jpg'** for night time **(9PM to 6AM)**.

If you want to change this behaviour then edit `wall.cpp` file:
![Edit wall.cpp file](/images/edit_wall_cpp.JPG)

Now to compile this, you must have a C++ compiler like MINGW installed. Here is a [quick guide to install MINGW in Windows 10](https://drive.google.com/open?id=1zRMhIJExoR-UW9T7gbtYwtaQzx1Kghwp).

Compile wall.cpp and generate wall.exe using these commands:
`cd "<here enter path of the folder which is contains wall.cpp>"` and then `g++ wall.cpp -o wall`
It will generate wall.exe in to same folder.

### Step 2: Create schedule task
Open start menu, and search and open "task scheduler". And follow these steps:
![step_1_6.JPG](/images/step_1_6.JPG)
![step_7_9.JPG](/images/step_7_9.JPG)
![step_10_12.JPG](/images/step_10_12.JPG)
![step_13_16.JPG](/images/step_13_16.JPG)
![step_17_20.jpg](/images/step_17_20.jpg)
![step_21.JPG](/images/step_21.JPG)
![step_22_23.JPG](/images/step_22_23.JPG)

Now windows 10 will run this task whenever user unlocks the PC, everyday at 6AM and everyday at 9PM. In this task, wall.exe file will be executed. Logic changing wallpaper according to time is already there in it. Now you are good to go. Enjoy.

-- [Maulik Raviya](http://twitter.com/MaulikRaviya)