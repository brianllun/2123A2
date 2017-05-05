// The code needs you to finish it

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;

class Matrix
{
  float **matx_entries;
  int row;
  int column;
  bool flag = true;
public:
  Matrix();
  Matrix(int r, int c);
  Matrix(const Matrix& m);
  Matrix(Matrix&& m);
  Matrix& operator= (const Matrix& m);
  ~Matrix();

  // Member functions like
  /* int get_row_dimension() const; // the number of rows; */
  /* void transpose_prime(); */
  float get_entry(int r, int c) const;
  int get_row_dimension() const;
  int get_column_dimension() const;
  void row_switching(int i, int j);
  void row_multiplication(int i, float k);
  void row_addition(int i, int j, float k);
  void transpose();
  void transpose_prime();

  // Overloaded operators
  /* friend std::istream & operator>> (std::istream& cin, Matrix& m); // overload ">>", the input format: a list of float numbers delimited by ',', no space between the numbers */
  friend ostream & operator<<(ostream& cout, const Matrix& m);
  friend istream & operator>>(istream& cin, Matrix& m);
  friend Matrix operator+(const Matrix& m, const Matrix& n);
  friend Matrix operator*(const Matrix& m, const float& c);
  friend Matrix operator*(const float& c, const Matrix& m);
  friend Matrix operator*(const Matrix& m1, Matrix & m2);


};

#endif
