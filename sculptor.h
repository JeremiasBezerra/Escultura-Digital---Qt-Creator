#ifndef SCULPTOR_H
#define SCULPTOR_H
#include <iostream>
#include <vector>

using namespace std;

struct Voxel
{

    int r,g,b,a;
    bool isOn = false;
};

class Sculptor {
private:
  Voxel ***v;
  int nc,nl,np,r,g,b,a;
public:

  Sculptor(int nx, int ny, int nz);
  ~Sculptor();
  void setColor(int _r, int _g, int _b, int _a);
  vector<int> getColor(int x, int y, int z);
  void print();
  void printMatriz();
  void putVoxel(int x, int y, int z);
  void cutVoxel(int x, int y, int z);
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
  void putSphere(int xcenter, int ycenter, int zcenter, int radius);
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  void writeOFF(string filename);
  bool getIsOn(int x, int y, int z);
  void setIsOn(int x, int y, int z, bool b);
};

#endif // SCULPTOR_H
