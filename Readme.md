*This was also the repository for Camera Calibration, but was moved to `https://github.com/erickTornero/Camera-Calibration`, currently it is in the folder **Pattern_Recognizion** , but will be deleted in the future*

# Image processing repository

Some algorithms for *Image processing* was Develop

### Handling of BMP files.

* Reading differents formats of BMP files

### Global Operation with Images

* Handle of Contrast and Brightness & Contrast, and a General Polinomial Operation

### Local Filters

* Convolution was implemented in CPU & Cuda for optimization, diferent Kernells was apply
e.g. *Gaussian Kernel*, *Outline Kernell* Was applied in the application

### Geometric Transformation

* A LU descomposition was developed using Partial Pivot Gauss Method, this last for
compute the coefficients of **Bilinear** Transformation.

### Color Space

* RGB to Gray Scale

* RGB to HSV Color Scale

### Frequency Analysis

* Fourier Transform algorithm was developed, this was implement in *Cuda-GPGPU* & in *CPU*
A Brightness Global Operator was apply after the Fourer Transform to get an image more visible.



# Install Application

## Requirements

* QT Creator 5.11
* C++11
* Cuda (Tested with 9.0 Version)
* Git

## Compile the application

* Clone the repository

`git clone https://github.com/erickTornero/Image-Processing.git`


* Access To the Right Folder

`cd Image-Processing/ApplicationImPr/`

* Create the Makefile with *QMake*

`qmake ApplicationImPr.pro`

* Compile the project

`make`

## run the application

`./Aplication


# Examples of execution Aplication


![alt text](https://github.com/erickTornero/Image-Processing/blob/master/sample.png)


