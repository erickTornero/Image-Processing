# include <vector>
unsigned char EvaluatePolynomial(const std::vector<double> & pol, unsigned char pixel);
unsigned char * PolinomialTransform(const std::vector<double> & coeff, unsigned char * data, int width, int height){
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

double PowChar(unsigned char v, int potence){
    if(potence == 0 ){
        return 1.0;
    }
    return (double)v*PowChar(v, potence -1);
}
unsigned char EvaluatePolynomial(const std::vector<double> & pol, unsigned char pixel){
    double val = 0;
    for(int i = 0, pot = pol.size() - 1; i < pol.size(); i++, pot--){
        val += pol[i]*PowChar(pixel, pot);
    }
    int ans = (int) val;
    if( ans > 255)
        ans = 255;
    if (ans < 0)
        ans = 0;
    return (unsigned char)ans;
}
