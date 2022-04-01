//-----------------------------------------------//
//                    Matrix                     //
//-----------------------------------------------//
#define ele_maxtrix ll
struct Matrix{
  int n, m;
  vector<vector<ele_maxtrix>> ma;
  Matrix(){}
  Matrix(int _n){
    n = _n; m = _n;
    ele_maxtrix ei;
    ei.set(0,0);
    ma = vector<vector<ele_maxtrix>>(n, vector<ele_maxtrix>(m, ei));
    for(int i = 0; i<n; i++){
      ma[i][i].set(0, 1);
    }
  }
  Matrix(int _n, int _m){
    n = _n; m = _m;
    ele_maxtrix ei;
    ei.set(0,0);
    ma = vector<vector<ele_maxtrix>>(n, vector<ele_maxtrix>(m, ei));
  }
};
Matrix operator*(Matrix ax, Matrix bx){
  if(ax.m != bx.n) return Matrix(0,0);
  Matrix cx = Matrix(ax.n, bx.m);
  for(int i = 0; i<ax.n; i++){
    for(int j = 0; j<bx.m; j++){
      for(int c = 0; c<ax.m; c++){
        cx.ma[i][j] = cx.ma[i][j] + (ax.ma[i][c]*bx.ma[c][j]);
      }
    }
  }
  return cx;
}
void print_matrix(Matrix ax){
  for(int i = 0; i<ax.n; i++){
    for(int j = 0; j<ax.m; j++){
      cout << ax.ma[i][j] << " ";
    }
    cout << "\n";
  }
}