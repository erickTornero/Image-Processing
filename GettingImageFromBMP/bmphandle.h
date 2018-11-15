#ifndef BMPHANDLE_H
#define BMPHANDLE_H
# include <stdio.h>
# include <iostream>
# include <vector>
# include <fstream>
#include <string>
void writeBMP(const char * name);
struct ImageFormatHeader{
    int heigh;
    int width;
    int totalSize;
    void set(int h, int w, int t){
        heigh = h;
        width = w;
        totalSize = t;
    }
};
struct RGB_{
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    RGB_(unsigned char r, unsigned char g, unsigned char b):red(r), green(g), blue(b){}
    RGB_(){}
};

unsigned char* readBMP(std::string filename, ImageFormatHeader & head)
{
    int i;
    std::ifstream inputfile;
    try {
        inputfile.open(filename, std::ios::binary);
        //FILE* f = fopen(filename, "rb");
        unsigned char info[138];
        //fread(info, sizeof(unsigned char), 138, f); // read the 54-byte header
        inputfile.read((char*)info, 138);
        // extract image height and width from header
        int width = *(int*)&info[18];
        int height = *(int*)&info[22];

        int size = 3 * width * height;
        unsigned char* data = new unsigned char[size]; // allocate 3 bytes per pixel
        //fread(data, sizeof(unsigned char), size, f); // read the rest of the data at once
        //fclose(f);
        inputfile.read((char*)data, size);
        inputfile.close();
        //std::fstream outputfile("newIm.bmp", std::ios::out | std::ios::binary);
        //outputfile.write((char*)info, 138);
        //outputfile.write((char*)data, size);
        //outputfile.close();
        for(i = 0; i < size; i += 3)
        {
                unsigned char tmp = data[i];
                data[i] = data[i+2];
                data[i+2] = tmp;
        }
        head.set(height,width,size);
        return data;
    } catch (std::ios_base::failure & e) {
        std::cerr<<e.what()<<'\n';
        return nullptr;
    }

}
RGB_ ** getImageMatrix(std::string filename, ImageFormatHeader & head){
    std::ifstream inputfile;
    try {
        inputfile.open(filename, std::ios::binary);
        //FILE* f = fopen(filename, "rb");
        unsigned char info[138];
        //fread(info, sizeof(unsigned char), 138, f); // read the 54-byte header
        inputfile.read((char*)info, 138);
        // extract image height and width from header
        int width = *(int*)&info[18];
        int height = *(int*)&info[22];

        int size = 3 * width * height;
        unsigned char* data = new unsigned char[size]; // allocate 3 bytes per pixel
        //fread(data, sizeof(unsigned char), size, f); // read the rest of the data at once
        //fclose(f);
        inputfile.read((char*)data, size);
        inputfile.close();
        //std::fstream outputfile("newIm.bmp", std::ios::out | std::ios::binary);
        //outputfile.write((char*)info, 138);
        //outputfile.write((char*)data, size);
        //outputfile.close();
        for(int i = 0; i < size; i += 3)
        {
                unsigned char tmp = data[i];
                data[i] = data[i+2];
                data[i+2] = tmp;
        }
        head.set(height,width,size);
        RGB_ ** MatrixI;
        RGB_ ** RetMatrix;
        MatrixI = new RGB_*[width];
        RetMatrix = new RGB_ * [height];
        for(int j = 0; j < width; j++){
            MatrixI[j] = new RGB_[height];
        }
        for( int j = 0; j < height; j++)
            RetMatrix[j] = new RGB_[width];

        for(int x = 0; x < width; x++){
            for(int y = 0; y < height; y++){
                MatrixI[x][y] = RGB_(data[x*height*3 + y*3 +0],data[x*height*3+y*3 +1],data[x*height*3+y*3 +2]);
            }
        }
        for(int i = 0; i < width; i++){
            for(int j = 0; j < height; j++){
                RetMatrix[height - j - 1][i] = MatrixI[i][j];
            }
        }
        return RetMatrix;
    } catch (std::ios_base::failure & e) {
        std::cerr<<e.what()<<'\n';
        return nullptr;
    }

}

#endif // BMPHANDLE_H
