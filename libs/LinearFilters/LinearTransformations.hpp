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

//Save computacional time
// void DFT image

unsigned char * DFTimageS(unsigned char * data, int width, int height){
    double *PkbReal = new double[width*height];
    double *PkbIm = new double[width*height];
    for(int k = 0; k < height; k++){
        for(int b = 0; b < width; b++){
            double sumReal = 0.0;
            double sumIm = 0.0;
            for(int a = 0; a < height; a++){
                double theta = -2.0*3.1416*k*a/height;
                sumReal += (double)data[b + width*a]*cosf(theta);
                sumIm += (double)data[b + width*a]*sinf(theta);
            }
            PkbReal[b + width*k] = sumReal/(double)height;
            PkbIm[b + width*k] = sumIm/(double)height;
        }
    }
    unsigned char * Dft = new unsigned char[width*height];
    for(int k = 0; k < height; k++){
        for(int l = 0; l < width; l++){
            double sumReal = 0.0;
            double sumIm = 0.0;
            for(int b = 0; b < width; b++){
                double theta = -2.0*3.1416*l*b/width;
                sumReal += (double)PkbReal[b + k*width]*cosf(theta) - (double)PkbIm[b+k*width]*sinf(theta);
                sumIm += (double)PkbReal[b + k*width]*sinf(theta) + (double)PkbIm[b+k*width]*cos(theta);
            }
            sumReal = sumReal/width;
            sumIm += sumIm/width;
            sumReal = sqrtf(sumReal*sumReal + sumIm*sumIm);
            Dft[k*width + l] = (unsigned char) sumReal;
        }
    }
    delete [] PkbReal;
    delete [] PkbIm;
    return Dft;
}