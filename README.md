<h1>CPPLogo</h1>
<h2>Description</h2>
<p>CPPLogo is an interpreter for a logo-like language built using C++. Logo is a language that allows a user to draw images using code. Hence, given a text file with logo-like code (for specifics, please see below), CPPLogo will interpret the code and output the appropriate image.</p>

<h2>Documentation</h2>

### 1. Pen Controls

#### 1.1 PENUP
```cpp
PENUP
```
Lifts the pen. This means that any movement of the pen will not draw anything to the image.

#### 1.2 PENDOWN
```cpp
PENDOWN
```
Places the pen down on the image. This means that as the pen moves, a line will be drawn onto the image with the current pen colour.

#### 1.3 FORWARD
```cpp
FORWARD <numpixels:int>
```
The pen moves forward in the direction that it is currently facing for `numpixels` amount.

#### 1.4 BACK
```cpp
BACK <numpixels:int>
```
The pen moves backwards with respect to the direction that it is currently facing for `numpixels` amount.

#### 1.5 LEFT
```cpp
LEFT <numpixels:int>
```
The pen moves left with respect to the direction that it is currently facing for `numpixels` amount.

#### 1.6 RIGHT
```cpp
RIGHT <numpixels:int>
```
The pen moves right with respect to the direction that it is currently facing for `numpixels` amount.

#### 1.7 SETPENCOLOR
```cpp
SETPENCOLOR <red:uint8_t> <green:uint8_t> <blue:uint8_t> <alpha:uint8_t>
```
The pen colour is set to the colour corresponding to **rgba**(red, green, blue, alpha).

#### 1.8 TURN
```cpp
TURN <degrees:int>
```
The pen turns `degrees` degrees clockwise relative to the direction they are currently facing. The pen initially faces true north which corresponds to 0 degrees.

#### 1.9 SETHEADING
```cpp
SETHEADING <degrees:int>
```
The pen faces in the direction of `degrees` relative to true north.

#### 1.10 SETX
```cpp
SETX <location:int>
```
The pen blinks to the coordinate (`location`, current y position) in the image. Top left corner of the image is denoted as (0, 0).

#### 1.11 SETY
```cpp
SETY <location:int>
```
The pen blinks to the coordinate (current x position, `location`) in the image. Top left corner of the image is denoted as (0, 0).
