# include <iostream>
# include <vector>
# include <string.h>
# include <math.h>
void printm(float ** m, int nrows, int ncols){
    for(int i = 0; i < nrows; i++){
        for(int j = 0; j < ncols; j++){
            std::cout<<m[i][j]<<"\t";
        }
        std::cout<<std::endl;
    }
}
void printvector(float *m, int sz){
    for(int i = 0; i < sz; i++)
        std::cout<<m[i]<<std::endl;
}

float ** MultiplyMatrixes(float ** matrixA, float ** matrixB, int R1, int C, int C2){
    float ** ans = new float * [R1];
    //Initialize the matrix answer
    for(int m = 0; m < R1; m++)
        ans[m] = new float[C2];

    for(int i = 0; i < R1; i++){
        for(int j = 0; j < C2; j++){
            
            // For each element of matrix:
            float acumm = 0;
            for(int k = 0; k < C; k++){
                acumm += matrixA[i][k]*matrixB[k][j];
            }
            ans[i][j] = acumm;
        }
    }
    return ans;
}
int DotProduct(float * vec1, float * vec2, int sz){
    float acumm = 0.0;
    for(int i = 0; i < sz; i++){
        acumm += vec1[i]*vec2[i];
    }
    return (int) acumm;
}

void SwapRows(float ** matrix, int row1, int row2, int ncols){
    for(int i = 0; i < ncols; i++){
        float tmp = matrix[row1][i];
        matrix[row1][i] = matrix[row2][i];
        matrix[row2][i] = tmp; 
    }
}


void SwapVector(float * av, int pos1, int pos2){
    float tmp = av[pos1];
    av[pos1] = av[pos2];
    av[pos2] = tmp;
}

int GetMaxRowItem(float ** matrix, int currCol, int nrows){
    int maxRow = currCol;
    for(int i = currCol + 1; i < nrows; i++){
        maxRow = (std::abs(matrix[i][currCol]) > std::abs(matrix[maxRow][currCol])) ? i : maxRow;
    }
    return maxRow;
}
float * SolveTriangularUpperMatrix(float ** matrix, float * X, int nrows, int ncols){
    float * ans = new float[nrows];
    for(int i = nrows - 1; i >= 0; i--){
        float sum = X[i];
        for(int k = i + 1; k < ncols; k++){
            sum -= matrix[i][k]*ans[k];
        }
        ans[i] = sum/matrix[i][i];
    }
    return ans;
}

float * SolveTriangularLowerMatrix(float ** matrix, float * X, int nrows, int ncols){
    float * ans = new float[nrows];
    for(int i = 0; i < nrows; i++){
        float sum = X[i];
        for(int k = i - 1; k >= 0; k--){
            sum -= matrix[i][k]*ans[k];
        }
        ans[i] = sum/matrix[i][i];
    }
    return ans;
}
float * PartialPivotGauss(float ** matrix, float * X, int nrows, int ncols){
    int changearr[nrows];
    float ** Lmat = new float*[nrows];
    for(int p = 0; p < nrows; p++){
        Lmat[p] = new float[ncols];
        memset(Lmat[p], 0.0, ncols);
    }
    

    for(int i = 0; i < nrows; i++){
        int maxR = GetMaxRowItem(matrix, i, nrows);
        changearr[i] = maxR;
        if(maxR > i){
            SwapRows(matrix, i, maxR, ncols);
            SwapVector(X, i, maxR);
            SwapRows(Lmat, i, maxR, ncols);
            // Save Permutation
        }
        // Avoid division by 0;
        if(matrix[i][i] != 0){
            // Start Elimination in current col, from the item in diagonal
            // to the end.
            for(int j = i + 1; j < nrows; j++){
                float mm = - matrix[j][i]/matrix[i][i];
                matrix[j][i] = 0.0;
                for(int k = i+1; k < ncols; k++){
                    matrix[j][k] += matrix[i][k]*mm;
                }
                //X[j] += X[i]*mm;
                Lmat[j][i] = -mm;
            }
        }
        std::cout<<"**********************"<<std::endl;
        std::cout<<"Iteracion: "<<i<< ": matrix U:\n";
        printm(matrix, nrows, ncols);
        std::cout<<std::endl<<std::endl<<"Matrix L\n";
        printm(Lmat, nrows, ncols) ;   
        std::cout<<std::endl<<std::endl<<"Augment\n";
        printvector(X, nrows);
    }
    for(int i = 0; i < nrows; i++)
        Lmat[i][i] = 1.0;
    for(int i = 0; i < nrows; i++){
        if(changearr[i] > i){
            float tmp = X[changearr[i]];
            //X[changearr[i]] = X[i];
            //X[i] = tmp; 
        }
    }
    // The matrix is returned.
    float * solvematrix = SolveTriangularLowerMatrix(Lmat, X, nrows, ncols);
    std::cout <<"Solve L matrix\n";
    printvector(solvematrix, nrows);
    float * solution = SolveTriangularUpperMatrix(matrix, solvematrix, nrows, ncols);
    float **mat = MultiplyMatrixes(Lmat, matrix, nrows, ncols, nrows);
    
    printm(mat, nrows, ncols);
    delete [] solvematrix;
    return solution;
}
void ComputeBilinearCoeff(unsigned char * X1, unsigned char * Y1, unsigned char * X2, unsigned char * Y2, float * coefX, float * coefY, int nPairpoints){
    //Four points is espected
    //float * xTransform = new float[nPairpoints];
    float ** TransformX = new float * [nPairpoints];
    float ** TransformY = new float * [nPairpoints];
    for(int i = 0; i < nPairpoints; i++){
        TransformX[i] = new float[nPairpoints];
        TransformY[i] = new float[nPairpoints];
    }
    //Uses the same matrix of transformations
    for(int i = 0; i < nPairpoints; i++){
        TransformX[i][0] = (float)X1[i];
        TransformX[i][1] = (float)Y1[i];
        TransformX[i][2] = (float)X1[i]*(float)Y1[i];
        TransformX[i][3] = 1.0;
    }
    float * Bx = new float[nPairpoints];
    float * By = new float[nPairpoints];
    Bx[0] = X2[0]; Bx[1] = X2[1]; Bx[2] = X2[2]; Bx[3] = X2[3];
    By[0] = Y2[0]; By[1] = Y2[1]; By[2] = Y2[2]; By[3] = Y2[3];

    float * CoeffX = PartialPivotGauss(TransformX, Bx, nPairpoints, nPairpoints);
    float * CoeffY = PartialPivotGauss(TransformX, By, nPairpoints, nPairpoints);

    coefX = CoeffX;
    coefY = CoeffY;
    
    delete [] Bx;
    delete [] By;
    delete [] TransformX;
    delete [] TransformY;
    //printvector(CoeffX, nPairpoints);
    //printvector(CoeffY, nPairpoints);
    
}

int main(){
    int szM = 4;
    //float a[szM][szM] = {{2.0, 1.0, 1.0, 0.0}, {4.0, 3.0, 3.0, 1.0}, {8.0, 7.0, 9.0, 5.0},{6.0, 7.0, 9.0, 8.0}};
    float a[szM][szM] = {{0.0, 0.0, 0.0, 1.0}, {300.0, 0.0, 0.0, 1.0}, {0.0, 300.0, 0.0, 1.0},{300.0, 300.0, 90000.0, 1.0}};
    float ** m = new float*[szM];
    float * X = new float[szM];
    X[0] = 120.0; 
    X[1] = 292.0;
    X[2] = 0.0;
    X[3] = 300.0; 
    for( int i = 0; i < szM; i++){
        m[i] = new float[szM];
    }
    for(int i = 0; i < szM; i++){
        for(int j = 0; j < szM; j++){
            m[i][j] = a[i][j];
        }
    }
    printm(m, szM, szM);
    float * solution = PartialPivotGauss(m, X, szM, szM);
    std::cout<<std::endl<<std::endl;
    std::cout<<std::endl<<std::endl;
    for(int i = 0; i < szM; i++){
        std::cout<<X[i]<<"\t";
    }
    std::cout<<std::endl<<std::endl;
    for(int i = 0; i < szM; i++){
        std::cout<<solution[i]<<"\t";
    }
    std::cout<<std::endl;

    unsigned char * X1 = new unsigned char [4];
    unsigned char * Y1 = new unsigned char [4];
    unsigned char * X2 = new unsigned char [4];
    unsigned char * Y2 = new unsigned char [4];


}