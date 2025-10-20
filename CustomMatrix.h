#ifndef CUSTOMMATRIX_H
#define CUSTOMMATRIX_H

#include <iostream>
#include <array>

using namespace std;

class CustomMatrix{
public:
    std::array<std::array<bool,3>,3> mat = {std::array<bool,3>{false,false,false},std::array<bool,3>{false,false,false},std::array<bool,3>{false,false,false}};
    CustomMatrix(){
    }

    //alternate way to instantiate the class
    CustomMatrix(std::array<std::array<bool,3>,3> m){
        const int m_size = m.size();
        for (int i=0;i< m_size;i++) {
            for(int j=0; j < sizeof(m[0]);j++){
                //cout << i << " " << j << endl;
                mat[i][j] = m[i][j];
            }
        }
    }

    void fillMatrix(std::array<std::array<bool,3>,3> m){
        const int m_size = m.size();
        for (int i=0;i< m_size;i++) {
            for(int j=0; j < sizeof(m[0]);j++){
                //cout << i << " " << j << endl;
                mat[i][j] = m[i][j];
            }
        }
    }
};

#endif // CUSTOMMATRIX_H
