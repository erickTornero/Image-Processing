# include <cuda.h>
# include <cuda_runtime.h>
extern "C"
unsigned char * DFTimageCuda(unsigned char * data, int width, int height);

__global__ void processPixelVertical(unsigned char * data_dev, double * PkbReal_dev, double * PkbIm_dev, int width, int height){
    int posThread = blockIdx.x*blockDim.x + threadIdx.x;
    if(posThread < width*height){
        int k = posThread/width;
        int b = posThread - k*width;
        double sumReal = 0.0;
        double sumIm = 0.0;
        for(int a = 0; a < height; a++){
            double theta = -2.0*3.1416*k*a/height;
            sumReal += (double)data_dev[b + width*a]*cosf(theta);
            sumIm += (double)data_dev[b + width*a]*sinf(theta);
        }
        PkbReal_dev[b + width*k] = sumReal/(double)height;
        PkbIm_dev[b + width*k] = sumIm/(double)height; 
    }
}
__global__ void processPixelHorizontal(unsigned char *data_dev, double * PkbReal_dev, double * PkbIm_dev, int width, int height){
    int posThread = blockIdx.x*blockDim.x + threadIdx.x;
    if(posThread < width*height){
        int k = posThread/width;
        int l = posThread - k*width;
        double sumReal = 0.0;
        double sumIm = 0.0;
        for(int b = 0; b < width; b++){
            double theta = -2.0*3.1416*l*b/width;
            sumReal += (double)PkbReal_dev[b + k*width]*cosf(theta) - (double)PkbIm_dev[b+k*width]*sinf(theta);
            sumIm += (double)PkbReal_dev[b + k*width]*sinf(theta) + (double)PkbIm_dev[b+k*width]*cos(theta);
        }
        sumReal = sumReal/width;
        sumIm += sumIm/width;
        sumReal = sqrtf(sumReal*sumReal + sumIm*sumIm);
        data_dev[k*width + l] = (unsigned char) sumReal;
    }
}

unsigned char * DFTimageCuda(unsigned char * data, int width, int height){
    unsigned char * dataDev;
    cudaMalloc((void**)&dataDev, width*height*sizeof(unsigned char));
    double * PkbRealDev;
    double * PkbImDev;
    cudaMalloc((void**)&PkbRealDev, width*height*sizeof(double));
    cudaMalloc((void**)&PkbImDev, width*height*sizeof(double));
    cudaMemcpy(dataDev, data, width*height*sizeof(unsigned char), cudaMemcpyHostToDevice);
    int nthreads = 1024;
    int nblocks = width*height/nthreads;
    if(width*height % nthreads > 0)
        nblocks++;
    processPixelVertical<<<nblocks, nthreads>>>(dataDev, PkbRealDev, PkbImDev, width, height);
    processPixelHorizontal<<<nblocks, nthreads>>>(dataDev, PkbRealDev, PkbImDev, width, height);
    unsigned char * Dft = new unsigned char[width*height];
    cudaMemcpy(Dft, dataDev, width*height*sizeof(unsigned char), cudaMemcpyDeviceToHost);
    cudaFree(dataDev);
    cudaFree(PkbRealDev);
    cudaFree(PkbImDev);
    return Dft;
}
int main(){
    
}
