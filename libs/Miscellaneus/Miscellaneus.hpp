
unsigned char * RGB2Gray(unsigned char * dataRGB, int size){
    int szGray = size/3;
    // Since human is more sensible to Green value it have more predominance 
    double Rp = 0.2126;
    double Gp = 0.7152;
    double Bp = 0.0722;
    unsigned char * dataGray = new unsigned char[szGray];
    for(int i = 0, k = 0; i < size; i+=3, k++){
        double val= Rp*dataRGB[i] + Gp*dataRGB[i+1] + Bp*dataRGB[i+2];
        dataGray[k] = (unsigned char)val;
    }
    return dataGray;
}