三角函数类
double sin (double);正弦
double cos (double);余弦
double tan (double);正切
double asin (double);反正弦,结果介于[-PI/2, PI/2]
double acos (double);反余弦,结果介于[0, PI]
double atan (double); 反正切(主值), 结果介于[-PI/2, PI/2]
double atan2 (double, double); 反正切(整圆值), 结果介于[-PI, PI]
double sinh (double);双曲线正弦
double cosh (double);双曲线余弦
double tanh (double);双曲线正切

指数对数类
double exp (double);指数函数
double sqrt (double);开平方
double log (double);自然对数
double log10 (double);常用对数
double pow(double x, double y）;计算以x为底数的y次幂
float powf(float x, float y);功能等同于pow，只是输入参数与输出参数皆为单浮点数

取整函数
double ceil (double);取上整
double floor (double);取下整

绝对值
int abs(int); 求整型的绝对值
double fabs (double);求绝对值
double cabs(struct complex znum) ;求复数的绝对值

标准化浮点数
double frexp (double f, int *p); 标准化浮点数, f = x * 2^p, 已知f求x, p ( x介于[0.5, 1] )
double ldexp (double x, int p); 与frexp相反, 已知x, p求f

取整与取余数
double modf (double, double*); 将参数的整数部分通过指针回传, 返回小数部分
double fmod (double, double); 返回两参数相除的余数

其他
double hypot(double x, double y);已知直角三角形两个直角边长度，求斜边长度
double ldexp(double x, int exponent);计算x*(2的exponent次幂)
double poly(double x, int degree, double coeffs [] );计算多项式
int matherr(struct exception *e);数学错误计算处理程序