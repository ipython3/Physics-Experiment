/*	目录：	
一、相对误差E的计算			
二、随机误差Sx的估算		
三、异常数据的判别与剔除	
四、A类不确定度的测量		
五、B类不确定度的测量		
六、合成标准不确定度u		
七、最小二乘法拟合直线
八、逐差法处理数据
九、角度制换弧度值
*/

#include <iostream>
#include <cmath>
using namespace std;

//一、相对误差E的计算
void basic1(double measurex, double truex)//measurex为测量值，truex为真值（或平均值）
{
	cout<<"相对误差E="<<fabs(measurex - truex) * 100 / truex << "%"<<endl;
}

//二、随机误差Sx的估算
void basic2(double * p, int n)//*p为数据数组，n为数组长度
{
	double average=0;
	for (int i = 0; i < n; i++)
	{
		average += p[i];
	}
	average /= n;//求出平均值average
	double Sx = 0;
	for (int i = 0; i < n; i++)
	{
		Sx += pow(p[i] - average, 2);
	}
	Sx /= n - 1;
	Sx = sqrt(Sx);//求出随机误差Sx
	cout << "随机误差Sx=" << Sx << endl;
}

//三、异常数据的判别与剔除
void basic3(double * p, int & n)//*p为数据数组，n为数组长度
{	
	double g0;
	double a;//判为异常数据的概率
J:
	cout << "请输入判为异常数据的概率a（0.05或者0.01）:" << endl;
	cin >> a;
K:
	if (a == 0.05)
	{
		switch (n)
		{
			case 4:g0 = 1.45; break;
			case 5:g0 = 1.67; break;
			case 6:g0 = 1.82; break;
			case 7:g0 = 1.94; break;
			case 8:g0 = 2.03; break;
			case 9:g0 = 2.11; break;
			case 10:g0 = 2.18; break;
			case 11:g0 = 2.23; break;
			case 12:g0 = 2.28; break;
			default:cout << "测量次数超过12或小于4，无法判别。" << endl; goto L;
		}
	}
	else if (a == 0.01)
	{
		switch (n)
		{
			case 4:g0 = 1.49; break;
			case 5:g0 = 1.75; break;
			case 6:g0 = 1.94; break;
			case 7:g0 = 2.10; break;
			case 8:g0 = 2.22; break;
			case 9:g0 = 2.32; break;
			case 10:g0 = 2.41; break;
			case 11:g0 = 2.48; break;
			case 12:g0 = 2.55; break;
			default:cout << "测量次数超过12或小于4，无法判别。" << endl; goto L;
		}
	}
	else { cout << "a必须为0.05或者0.01!" << endl; goto J; }//g0的初始化

	double average = 0;
	for (int i = 0; i < n; i++)
	{
		average += p[i];
	}
	average /= n;//求出平均值average
	double Sx = 0;
	for (int i = 0; i < n; i++)
	{
		Sx += pow(p[i] - average, 2);
	}
	Sx /= n - 1;
	Sx = sqrt(Sx);//求出随机误差Sx
	
	for (int i = 0; i < n; i++)	//剔除异常数据，如果有异常数据，抛弃并跳回K，n=n-1
	{
		double gi;
		gi = (p[i] - average)/Sx;
		if (gi >= g0) 
		{
			cout <<"第" << i+1 << "个数据" <<p[i] << "是异常数据，已剔除。" << endl;
			for (int j = i; j < n - 1; j++)
			{
				p[j] = p[j + 1];
			}
			n -= 1;
			goto K;
		}
	}
	cout << "剔除异常数据完毕，剩余数据为：";
	for (int i = 0; i < n; i++)
	{
		cout << p[i] << " ";
	}
L:
	cout << endl;

}

//四、A类不确定度的测量
void basic4(double * p, int n)
{	
	if (n>1)
	{
		double average = 0;
		for (int i = 0; i < n; i++)
		{
			average += p[i];
		}
		average /= n;//求出平均值average
		double uA = 0;
		for (int i = 0; i < n; i++)
		{
			uA += pow(p[i] - average, 2);
		}
		uA /= n*(n - 1);
		uA = sqrt(uA);//A类不确定度uA
		cout << "A类不确定度uA=" << uA << endl;
		cout << "待测量结果表示为" << average << "±" << uA << endl;
	}
	else 
	{
		cout << "数据个数必须大于1。" << endl;
	}
}

//五、B类不确定度的测量
void basic5(double deltayi)
{
	cout << "B类不确定度uB=" << deltayi/1.732<< endl;
}

//六、合成标准不确定度u
void basic6(double * p, int n, double deltayi)
{
	double uA = 0;
	double average = 0;
	if (n > 1)
	{
		for (int i = 0; i < n; i++)
		{
			average += p[i];
		}
		average /= n;//求出平均值average
		for (int i = 0; i < n; i++)
		{
			uA += pow(p[i] - average, 2);
		}
		uA /= n*(n - 1);
		uA = sqrt(uA);//A类不确定度uA

		double uB;
		uB = deltayi / 1.732;
		double u;
		u = sqrt(pow(uA, 2) + pow(uB, 2));
		cout << "合成标准不确定度u=" << u << endl;
		cout << "待测量结果表示为" << average << "±" << u << endl;
	}
	else
	{
		cout << "数据个数必须大于1。" << endl;
	}
}

//七、最小二乘法拟合直线
void basic7(double * x, double * y, int n)
{
	double a, b, Lxx, Lyy, Lxy, avex = 0, avey = 0, avexy = 0, avex2 = 0, avey2 = 0, R;
	if (n == 1){ cout << "ERROR：数据组数不能为1！" << endl; exit(0); }
	else
	{
		for (int i = 0; i < n; i++)
		{
			avex += x[i];
			avey += y[i];
			avexy += x[i] * y[i];
			avex2 += x[i] * x[i];
			avey2 += y[i] * y[i];
		}
		avex /= n;
		avey /= n;
		avexy /= n;
		avex2 /= n;
		avey2 /= n;
		//求斜率a和截距b
		a = (avexy - avex*avey) / (avex2 - (avex*avex));
		b = avey - a*avex;
		//求相关系数R，检验y和x的线性关系
		Lxy = avexy - avex*avey;
		Lxx = avex2 - avex*avex;
		Lyy = avey2 - avey*avey;
		R = Lxy / sqrt(Lxx*Lyy);
		//输出x,y数据列表
		cout << "序号i\txi\t\tyi\t\txi^2\t\tyi^2\t\txiyi" << endl;
		for (int i = 0; i < n; i++)
		{
			cout << i + 1 << "\t" << x[i] << "\t\t" << y[i] << "\t\t" << x[i] * x[i] << "\t\t" << y[i] * y[i] << "\t\t" << x[i] * y[i] << endl;
		}
		cout << "∑\t" << avex*n << "\t\t" << avey*n << "\t\t" << avex2*n << "\t\t" << avey2*n << "\t\t" << avexy*n << endl;
		cout << "平均值\t" << avex << "\t\t" << avey << "\t\t" << avex2 << "\t\t" << avey2 << "\t\t" << avexy << endl;
		//输出算式
		cout << "①根据最小二乘法公式求斜率和截距：" << endl;
		cout << "斜率a=" << a << endl;
		cout << "截距b=" << b << endl;
		cout << "②求相关系数，检验y和x的线性关系：" << endl;
		cout << "Lxy=" << Lxy << endl;
		cout << "Lxx=" << Lxx << endl;
		cout << "Lyy=" << Lyy << endl;
		cout << "相关系数R=Lxy / sqrt(Lxx*Lyy)=" << R << endl;
		cout << "根据所求得的回归直线的斜率和截距，得回归方程：y =" << a << "x+" << b << endl;
	}
}

//八、逐差法处理数据
void basic8(double * p, int n)
{
	int jiange;//每组数据两个数之间的间隔
	double total=0, average;
	if (n % 2 == 0)
	{
		jiange = n / 2;
		for (int i = 0; i < jiange; i++)
		{
			total += p[i + jiange] - p[i];
		}
		average = total / (jiange * jiange);
	}
	else
	{
		cout << "数据个数为奇数，将舍弃第一个数据：" << endl;
		jiange = n / 2;
		for (int i = 1; i < jiange;i++)
		{
			total += p[i + jiange] - p[i];
		}
		average = total / (jiange * jiange);
	}
	cout << "逐差法结果为：" << average << endl;
}

//九、角度制换弧度制
void basic9()
{
	int a, b, c;
J:
	cout << "请输入角度（°）：" << endl;
	cin >> a;
	cout << "请输入角度（’）：" << endl;
	cin >> b;
	cout << "请输入角度（”）：" << endl;
	cin >> c;
	cout << "转换后的弧度为（rad）：" << a*0.01745 + b*0.01745 / 60 + c*0.01745 / 360 << endl;
K:
	cout << "再算一组？（Y/N）" << endl;
	char again;
	cin >> again;
	if (again == 'Y' || again == 'y'){ goto J; }
	else if (again == 'N' || again == 'n'){ ; }
	else { goto K; }
}