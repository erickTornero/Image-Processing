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
    double *Pkb = new double[width*height];
    
    for(int k = 0; k < height; k++){
        for(int b = 0; b < width; b++){
            double sum = 0;
            for(int a = 0; a < height; a++){
                double theta = -2.0*3.1416*k*a/height;
                sum += (double)data[b + width*a]*cosf(theta);;
            }
            Pkb[b + width*k] = sum/(double)height;
        }
    }
    unsigned char * Dft = new unsigned char[width*height];
    for(int k = 0; k < height; k++){
        for(int l = 0; l < width; l++){
            double sum = 0;
            for(int b = 0; b < width; b++){
                double theta = -2.0*3.1416*l*b/width;
                sum += (double)data[b + k*width]*cosf(theta);
            }
            sum = sum/width;
            Dft[k*width + l] = (unsigned char) sum;
        }
    }
    delete [] Pkb;
    return Dft;
}