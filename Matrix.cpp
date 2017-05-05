// This program needs you to finish!
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include "Matrix.h"

using namespace std;

Matrix::Matrix(){
  // the default comstructor
  row = 0;
  column = 0;
  bool flag = true;
}

Matrix::Matrix(int r, int c):Matrix(){
  if (not(r > 0) || not(c > 0)){
    cout << "Invalid number of rows or columns!" << endl;
  }else{
    matx_entries = new float *[r];
    for (int i = 0; i < r; i++){
      matx_entries[i] = new float[c];
      for (int j = 0; j < c; j++){
        matx_entries[i][j] = 0;
      }
    }
  }
  bool flag = true;
  this->row = r;
  this->column = c;
}

Matrix::Matrix(const Matrix& m){
  this->row = m.row;
  this->column = m.column;
  matx_entries = new float *[row];
  for (int i = 0; i < row; i++){
    matx_entries[i] = new float[column];
    for (int j = 0; j < column; j++) {
      matx_entries[i][j] = m.matx_entries[i][j];
    }
  }
}

Matrix::Matrix(Matrix&& m){
  this->row = m.row;
  this->column = m.column;
  this->flag = m.flag;
  matx_entries = m.matx_entries;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < column; j++) {
      matx_entries[i][j] = m.matx_entries[i][j];
    }
  }
  m.matx_entries = nullptr;
  m.row = 0;
  m.column = 0;
}

Matrix::~Matrix(){
  // the destructor
  for (int i=0; i < row; i++)
    delete[] matx_entries[i];
  delete[] matx_entries;
}


int Matrix::get_row_dimension() const{
  return this->row;
}

int Matrix::get_column_dimension() const{
  return this->column;
}

float Matrix::get_entry(int r, int c) const{
    if ((r + 1 > this->row) or (c + 1 > this->column)){
      cout << "Index out of range!" << endl;
      return 0;
    }

    else return this->matx_entries[r][c];
}

void Matrix::row_switching(int i, int j){
    if ((i + 1 > this->row) or (j + 1> this->row))
        cout << "Index out of range!" << endl;
    else{
        float temp[this->column-1];
        for (int m = 0; m < this->column; m++){
            temp[m] = this->matx_entries[i][m];
            this->matx_entries[i][m] = this->matx_entries[j][m];
            this->matx_entries[j][m] = temp[m];
        }
    }
}

void Matrix::row_multiplication(int i, float k){
    if (k == 0){
        cout << "Cannot be multiplied by a zero constant!" << endl;
    }
    else{
        for (int m = 0; m < this->column; m++){
            this->matx_entries[i][m] = this->matx_entries[i][m]*k;
        }
    }
}

void Matrix::row_addition(int i, int j, float k){
    if (i == j){
        cout << "Cannot be the same row!" << endl;
    }else{
        for (int m = 0; m < this->column; m++){
            this->matx_entries[i][m] = this->matx_entries[i][m] + this -> matx_entries[j][m]*k;
        }
    }
}

void Matrix::transpose(){
    int row_new = this->column;
    int column_new = this->row;
    float **new_matx_entries;
    new_matx_entries = new float *[row_new];
    for (int i = 0; i < row_new; i++) {
        new_matx_entries[i] = new float[column_new];
    }
    for (int i = 0; i < row_new; i++) {
        for (int j = 0; j < column_new; j++) {
            new_matx_entries[i][j] = this->matx_entries[j][i];
        }
    }
    this->matx_entries = new_matx_entries;
    this->row = row_new;
    this->column = column_new;
}


void Matrix::transpose_prime(){
    if(flag == true){
        flag = false;
    } else{
        flag = true;
    }
    swap(row, column);
}

Matrix& Matrix::operator= (const Matrix& m){
  // overload =
  if (this != &m){
    if ((m.row != this->row) || (m.column != this->column)){
      delete[] matx_entries;
      this->row = m.row;
      this->column = m.column;
      matx_entries = new float *[m.row];
      for (int i = 0; i < m.row; i++){
        matx_entries[i] = new float [m.column];
        for (int j = 0; j < m.column; j++){
          if(m.flag == true){
              this->matx_entries[i][j] = m.matx_entries[i][j];
          } else {
              this->matx_entries[i][j] = m.matx_entries[j][i];
          }
        }
      }
    }else{
      for (int i = 0; i < m.row; i++){
        for (int j = 0; j < m.column; j++){
          this->matx_entries[i][j] = m.matx_entries[i][j];
        }
      }
    }
  }
  return *this;
}

ostream & operator<<(ostream & cout, const Matrix &m){
    for (int i = 0; i < m.row; i++) {
        for (int j = 0; j < m.column; j++) {
          if(m.flag == false){
            cout << m.matx_entries[j][i] << " ";
          } else {
            cout << m.matx_entries[i][j] << " ";
          }
        }
        cout << endl;
    }
    return cout;
}

istream & operator>> (istream& cin, Matrix& m){

    for (int i = 0; i < m.row; i++) {
        for (int j = 0; j < m.column; j++) {
            cin >> m.matx_entries[i][j];
        }
    }
    return cin;
}

Matrix operator+(const Matrix & m, const Matrix & n){
    Matrix temp(m.row,m.column);
    if ((m.row == n.row) && (m.column == n.column )){
      for (int i = 0; i < m.row; i++) {
          for (int j = 0; j < m.column; j++) {
              temp.matx_entries[i][j] = m.matx_entries[i][j] + n.matx_entries[i][j];
          }
      }
    }else{
      cout << "Cannot do the matrix addition!" << endl;
    }
    return temp;
}

Matrix operator*(const float & c, const Matrix & m){
    Matrix temp(m.row,m.column);
    for (int i = 0; i < m.row; i++) {
        for (int j = 0; j < m.column; j++) {
          if(m.flag == true){
              temp.matx_entries[i][j] = m.matx_entries[i][j] *c;
          }else{
              temp.matx_entries[i][j] = m.matx_entries[j][i] *c;
          }
        }
    }
    return temp;
}

Matrix operator*(const Matrix & m, const float & c){
    Matrix temp(m.row,m.column);
    for (int i = 0; i < m.row; i++) {
        for (int j = 0; j < m.column; j++) {
          if(m.flag == true){
              temp.matx_entries[i][j] = m.matx_entries[i][j] *c;
          }else{
              temp.matx_entries[i][j] = m.matx_entries[j][i] *c;
          }
        }
    }
    return temp;
}

Matrix operator*(const Matrix & m1, Matrix & m2){
    Matrix temp(m1.row,m2.column);
    for(int i = 0; i < m1.row; i++){
        for(int j = 0; j < m2.column; j++){          // position
            float sum = 0;
                if(m1.flag == true && m2.flag == true){
                    for(int x = 0; x < m2.row; x++){
                        sum += m1.matx_entries[i][x] * m2.matx_entries[x][j];
                    }
                }else if(m1.flag == false && m2.flag == true){
                    for(int x = 0; x < m2.row; x++){
                        sum += m1.matx_entries[x][i] * m2.matx_entries[x][j];
                    }
                }else if(m1.flag == true && m2.flag == false){
                    for(int x = 0; x < m2.row; x++){
                        sum += m1.matx_entries[i][x] * m2.matx_entries[j][x];
                    }
                } else if(m1.flag == false && m2.flag == false){
                    for(int x = 0; x < m2.row; x++){
                        sum += m1.matx_entries[x][i] * m2.matx_entries[j][x];
                    }
                }
            temp.matx_entries[i][j] = sum;
        }
    }
    return temp;
}
