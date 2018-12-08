# include <vector>
unsigned char EvaluatePolynomial(const std::vector<int> & pol, unsigned char pixel);
unsigned char * PolinomialTransform(const std::vector<int> & coeff, unsigned char * data, int width, int height){
    int size = 3*height*width;
    if( size > 0){
        unsigned char * dataFiltered = new unsigned char[size];
        for(int i = 0; i < size; i++){
            dataFiltered[i] = EvaluatePolynomial(coeff, data[i]);
        }
        return dataFiltered;
    }
    else
        return nullptr;
}

int PowChar(unsigned char v, int potence){
    if(potence == 0 ){
        return 1;
    }
    return v*PowChar(v, potence -1);
}
unsigned char EvaluatePolynomial(const std::vector<int> & pol, unsigned char pixel){
    int val = 0;
    for(int i = 0, pot = pol.size() - 1; i < pol.size(); i++, pot--){
        val += pol[i]*PowChar(pixel, pot);
    }
    if( val > 255)
        val = 255;
    if (val < 0)
        val = 0;
    return (unsigned char) val;
}