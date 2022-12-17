/* 
----------- Vector 2 struct ---------------
----------- Vector 2 because it has 2 inputs, x & y
*/
struct Vector2 {
  float x;
  float y;
};

extern const double uZero;

/* 
----------- Vector 3 class ---------------
----------- Vector 3 because it has 3 inputs, x, y & z
*/
class Vector3 {
public:
  float x;
  float y;
  float z;
  Vector3() : x(0), y(0), z(0) {}
  Vector3(float x1, float y1, float z1) : x(x1), y(y1), z(z1) {}
  Vector3(const Vector3 &v);
  ~Vector3();
  void operator=(const Vector3 &v);
  Vector3 operator+(const Vector3 &v);
  Vector3 operator-(const Vector3 &v);
  Vector3 operator/(const Vector3 &v);
  Vector3 operator*(const Vector3 &v);
  Vector3 operator+(float f);
  Vector3 operator-(float f);
  Vector3 operator/(float f);
  Vector3 operator*(float f);
  Vector3 static Normalize(Vector3 vec);
  Vector3 static Cross(Vector3 a, Vector3 b);
  float dot(const Vector3 &v);
  float length();
  void clear();
  void normalized();
  Vector3 static Lerp(Vector3 start, Vector3 end, float percent);
  Vector3 cross(const Vector3 &v);
  static float distance(const Vector3 &a, const Vector3 &b);
};


const double uZero = 1e-6;

Vector3 Vector3::Lerp(Vector3 start, Vector3 end, float percent) {
  return (start + (end - start) * percent);
}

Vector3::Vector3(const Vector3 &v) : x(v.x), y(v.y), z(v.z) {

}



Vector3::~Vector3() {

}

void Vector3::operator=(const Vector3 &v) {
  x = v.x;
  y = v.y;
  z = v.z;
}

Vector3 Vector3::operator+(const Vector3 &v) {
  return Vector3(x + v.x, y + v.y, z + v.z);
}

Vector3 Vector3::operator-(const Vector3 &v) {
  return Vector3(x - v.x, y - v.y, z - v.z);
}

Vector3 Vector3::operator/(const Vector3 &v) {
  if (fabsf(v.x) <= uZero || fabsf(v.y) <= uZero || fabsf(v.z) <= uZero) {
    return *this;
  }
  return Vector3(x / v.x, y / v.y, z / v.z);
}

Vector3 Vector3::operator*(const Vector3 &v) {
  return Vector3(x * v.x, y * v.y, z * v.z);
}

Vector3 Vector3::operator+(float f) {
  return Vector3(x + f, y + f, z + f);
}

Vector3 Vector3::operator-(float f) {
  return Vector3(x - f, y - f, z - f);
}

void Vector3::clear() {
  x = y = z = 0;
}

Vector3 Vector3::operator/(float f) {
  if (fabsf(f) < uZero) {
    return *this;
  }
  return Vector3(x / f, y / f, z / f);
}

Vector3 Vector3::operator*(float f) {
  return Vector3(x * f, y * f, z * f);
}

float Vector3::dot(const Vector3 &v) {
  return x * v.x + y * v.y + z * v.z;
}

float Vector3::length() {
  return sqrtf(dot(*this));
}

void Vector3::normalized() {
  float len = length();
  if (len < uZero) len = 1;
  len = 1 / len;

  x *= len;
  y *= len;
  z *= len;
}

Vector3 Vector3::Normalize(Vector3 vec) {
  vec.normalized();
  return vec;
}


float Vector3::distance(const Vector3 &point1, const Vector3 &point2) {
  float distance = sqrt((point1.x - point2.x) * (point1.x - point2.x) +
                        (point1.y - point2.y) * (point1.y - point2.y) +
                        (point1.z - point2.z) * (point1.z - point2.z));
  return distance;
}


/*
Cross Product²æ³Ë¹«Ê½
aXb = | i,  j,  k  |
| a.x a.y a.z|
| b.x b.y b.z| = (a.x*b.z -a.z*b.y)i + (a.z*b.x - a.x*b.z)j + (a.x+b.y - a.y*b.x)k
*/
Vector3 Vector3::cross(const Vector3 &v) {
  return Vector3(y * v.z - z * v.y,
                 z * v.x - x * v.z,
                 x * v.y - y * v.x);
}

Vector3 Vector3::Cross(Vector3 a, Vector3 b) {
  return a.cross(b);
}