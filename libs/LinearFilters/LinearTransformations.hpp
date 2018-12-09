# include <math.h>
# define MYPI 3.1416

//TODO: implement for any numbers of channels
void DFTimage(unsigned char * data, unsigned char * realPart, unsigned char * imPart, int width, int height){
    realPart = new unsigned char[width*height];
    imPart = new unsigned char[width*height];
    for( int u = 0; u < width; u++){
        for(int v = 0; v < height; v++){
            int sumReal = 0;
            int sumIm = 0;
            for(int c = 0; c < width; c++){
                for(int f = 0; f < height; f++){
                    float theta = 2*MYPI*(u*c/width + v*f/height);
                    sumReal += data[u + v*width]*cos(theta);
                    sumIm += data[u + v*width]*sin(theta);
                }
            }
            realPart[u + v*width] = (unsigned char)(sumReal/(width*height));
            imPart[u + v*width] = (unsigned char)(sumIm/(width*height));
        }
    }
}