# include <iostream>
# include <fstream>
unsigned char * ReadBMP(const std::string filename,  unsigned char * rawdata, int & height, int & width, int & size);

int main(){
    std::cout<<"Hola\n"<<std::endl;
    unsigned char * data;
    int lengthImg, widthImg, sizeImg;
    ReadBMP("cat10x20.bmp", data, lengthImg, widthImg, sizeImg);
    return 0;
}


unsigned char *  ReadBMP(const std::string filename, int & height, int & width, int & size){
    std::ifstream inputfile;
    inputfile.open(filename, std::ios::binary);
    unsigned char info[54];
    inputfile.read((char*)info, 54);

    // extract image height and width from header
    width = *(int*)&info[18];
    height = *(int*)&info[22];
    int datapaddSZ = *(int*)&info[34];
    // Read just RGB colors
    size = 3 * width * height;
    int padding = (datapaddSZ - size)/height;
    int offset = *(int*)&info[10];
    unsigned short bitsperpixel = *(unsigned short*)&info[28];


    inputfile.seekg(offset);
    unsigned char * data = new unsigned char[size];
    // Reading avoiding the padding:
    int position = 0;
    for(int h = 0; h < height; h++){
        inputfile.read((char*)data + position, width*3);
        position += width*3 + padding;
    }
    
    // Set to RGB from BGR
    for(int i = 0; i < size; i += 3){
            unsigned char tmp = data[i];
            data[i] = data[i+2];
            data[i+2] = tmp;
    }

    int a = 1;
    return data;
}