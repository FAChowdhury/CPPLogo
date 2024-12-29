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
