<h1>CPPLogo</h1>
<h2>Description</h2>
<p>CPPLogo is an interpreter for a logo-like language built using C++. Logo is a language that allows a user to draw images using code. Hence, given a text file with logo-like code (for specifics, please see below), CPPLogo will interpret the code and output the appropriate image.</p>

**This project is unfinished and a WIP! I plan to create a frontend that will contain a text editor to write logo-like code in order to produce images.**

<h2>Documentation</h2>

### 1. Value Types

#### 1.1 Literal Values
A literal value is prefixed with a ". This can denote a number or a raw string.

#### 1.2 Variables
A variable is prefixed by a :, which means the interpreter will look up the value associated with a variable with that name.

### 2. Pen Controls

#### 2.1 PENUP
```cpp
PENUP
```
Lifts the pen. This means that any movement of the pen will not draw anything to the image.

#### 2.2 PENDOWN
```cpp
PENDOWN
```
Places the pen down on the image. This means that as the pen moves, a line will be drawn onto the image with the current pen colour.

#### 2.3 FORWARD
```cpp
FORWARD <numpixels:int>
```
The pen moves forward in the direction that it is currently facing for `numpixels` amount.

#### 2.4 BACK
```cpp
BACK <numpixels:int>
```
The pen moves backwards with respect to the direction that it is currently facing for `numpixels` amount.

#### 2.5 LEFT
```cpp
LEFT <numpixels:int>
```
The pen moves left with respect to the direction that it is currently facing for `numpixels` amount.

#### 2.6 RIGHT
```cpp
RIGHT <numpixels:int>
```
The pen moves right with respect to the direction that it is currently facing for `numpixels` amount.

#### 2.7 SETPENCOLOR
```cpp
SETPENCOLOR <red:uint8_t> <green:uint8_t> <blue:uint8_t> <alpha:uint8_t>
```
The pen colour is set to the colour corresponding to **rgba**(red, green, blue, alpha).

#### 2.8 TURN
```cpp
TURN <degrees:int>
```
The pen turns `degrees` degrees clockwise relative to the direction they are currently facing. The pen initially faces true north which corresponds to 0 degrees.

#### 2.9 SETHEADING
```cpp
SETHEADING <degrees:int>
```
The pen faces in the direction of `degrees` relative to true north.

#### 2.10 SETX
```cpp
SETX <location:int>
```
The pen blinks to the coordinate (`location`, current y position) in the image. Top left corner of the image is denoted as (0, 0).

#### 2.11 SETY
```cpp
SETY <location:int>
```
The pen blinks to the coordinate (current x position, `location`) in the image. Top left corner of the image is denoted as (0, 0).

#### 2.12 FILL
```cpp
FILL
```
The pen flood fills the image starting from the current location with the current pen colour. This is comparable to the bucket fill tool in drawing software.

<h2>Examples</h2>

### 1. Drawings

#### 1.1 Heart
Let's draw a heart together.
To obtain the following picture of a heart:\
![image](https://github.com/user-attachments/assets/71bff86d-5349-41be-821e-111eb74bbb9d)

Write the following code:
```
// draw a heart

// make background skyblue
SETPENCOLOR "115 "187 "230 "255
FILL

// right side
PENDOWN
SETPENCOLOR "245 "61 "116 "255
SETY "60
TURN "45
FORWARD "28
TURN "45
FORWARD "20
TURN "45
FORWARD "28
TURN "45
FORWARD "20
TURN "45
FORWARD "85

// left side
SETHEADING "0
SETX "100
SETY "60
TURN "-45
FORWARD "28
TURN "-45
FORWARD "20
TURN "-45
FORWARD "28
TURN "-45
FORWARD "20
TURN "-45
FORWARD "85

// make heart red
PENUP
SETX "100
SETY "100
FILL

// Add highlights
PENDOWN
SETPENCOLOR "255 "255 "255 "255
SETX "60
SETY "60
SETHEADING "90
FORWARD "20
TURN "90
FORWARD "10
TURN "90
FORWARD "10
TURN "-90
FORWARD "10
TURN "90
FORWARD "10
TURN "90
FORWARD "20

PENUP
BACK "5
RIGHT "5
FILL
```

### Errors
#### Error: Unexpected Type
Suppose when drawing the heart, we write the following code instead:
```
// draw a heart

// make background skyblue
SETPENCOLOR "115 "187 "230 "300
FILL
...
```
Realise that we input a value above 255 for the alpha value, which is invalid. We get the following error:\
![image](https://github.com/user-attachments/assets/97f99fa6-4838-4caa-851b-0f85be889a0f)
Error messages highlight the line that contains the error along with surrounding lines. It also highlights the specific word causing the error in red and offers a suitable solution format in green.

#### Error: Too Few Arguments
When arguments are not provided for a command, an error is raised:\
![image](https://github.com/user-attachments/assets/42180f25-5cac-4bb7-b6ba-e53565d055fd)

```markdown
<span style="color: red;">This is red text</span>
