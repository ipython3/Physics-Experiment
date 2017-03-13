/*目录：

第三章 力学与热学实验
3.2 液体粘滞系数的测量及其温度特性研究	√测试完成
3.4 弯曲法测定杨氏模量					√测试完成

第四章 电磁学实验
4.1 PN结正向电压温度特性研究			√测试完成
4.2 用电流场模拟静电场、温度场			×
4.3 惠斯登电桥测电阻					√测试完成	
4.4 非平衡电桥电压输出特性研究			√测试完成
4.6 模拟示波器的使用					√
4.7 数字示波器的使用					×

第五章 光学实验
5.2 偏振光特性研究						√测试完成
5.3 光的等厚干涉现象					√测试完成
5.4 光的衍射							√测试完成
5.5 分光计的调整与使用					√

第六章 综合性实验
6.9 物质旋光率的测量					√测试完成
*/

#include <iostream>
#include <cmath>
#include "基本数据处理.h"
#include <windows.h>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>
#include "颜色.h"
using namespace std;

//3.2 液体粘滞系数的测量及其温度特性研究
class Class3_2
{
	double h, D, d, rho, rho0, g, *T, **t, *avet, *v, *eta;//η->eta
	int nT;
public:
	void initialize()
	{
		double K = 2.4;
		cout << "请输入小球下落的距离h(单位：m)(默认为0.15)：" << endl;
		cin >> h;
		cout << "请分别输入小球的密度ρ与液体的密度ρ0/ρL(单位：kg/m^3)(默认为7800与950)：" << endl;
		cin >> rho >> rho0;
		cout << "请分别输入圆筒的内径D与小球的直径d(单位：m)(默认为0.02与0.001)：" << endl;
		cin >> D >> d;
		cout << "请输入重力加速度g(单位m/s^2)(默认为9.8)" << endl;
		cin >> g;
		cout << "请输入不同温度环境的个数(默认为3)：" << endl;
		cin >> nT;

		T = new double[nT];
		t = new double *[nT];
		for (int i = 0; i < nT; i++)
		{
			t[i] = new double[5];
		}
		avet = new double[nT];
		v = new double[nT];
		eta = new double[nT];

		cout << "请从小到大输入温度的数值(单位：°C)：" << endl;
		for (int i = 0; i < nT; i++)
		{
			cin >> T[i];
		}
		for (int i = 0; i < nT; i++)
		{
			cout << "请输出温度T=" << T[i] << "°C时的5个时间测量值t：" << endl;
			cin >> t[i][0] >> t[i][1] >> t[i][2] >> t[i][3] >> t[i][4];
			avet[i] = (t[i][0] + t[i][1] + t[i][2] + t[i][3] + t[i][4]) / 5;
			v[i] = h / avet[i];
			eta[i] = (rho - rho0)*g*d*d / (18.0 * v[i] * (1.0 + K*d / D));
		}
	}
	void print()
	{
		cout.precision(3);
		cout << lightblue;
		cout << "温度\\组别\t1\t2\t3\t4\t5\t平均值t\tv(m/s)\tη" << endl;
		for (int i = 0; i < nT; i++)
		{
			cout << T[i] << "\t\t" << t[i][0] << "\t" << t[i][1] << "\t" << t[i][2] << "\t" << t[i][3] << "\t" << t[i][4] << "\t" << avet[i] << "\t" << v[i] << "\t" << eta[i] << endl;
		}
		cout << "（其中η的计算公式为η=（ρ-ρ0）*g*d^2/(18*(1+2.4d/D)*V)）（单位：Pa）" << endl<<endl<<white;
	}
	void randdata()
	{
		double K = 2.4;
		cout << "小球下落的距离h=0.15m。" << endl;
		h=0.15;
		cout << "小球的密度ρ与液体的密度ρ0/ρL分别为7800与950 kg/m^3。：" << endl;
		rho=7800;rho0=950;
		cout << "圆筒的内径D与小球的直径d为0.02m与0.001m。" << endl;
		D=0.02;d=0.001;
		cout << "重力加速度g=9.8m/s^2。" << endl<<endl;
		g=9.8;
		nT=3;

		T = new double[nT];
		t = new double *[nT];
		for (int i = 0; i < nT; i++)
		{
			t[i] = new double[5];
		}
		avet = new double[nT];
		v = new double[nT];
		eta = new double[nT];

		T[0]=30;T[1]=35;T[2]=40;

		srand(time(0));
		for(int i=0;i<5;i++)
		{
			t[0][i] = 27 + rand() % 30 * 0.1;
		}
		avet[0] = (t[0][0] + t[0][1] + t[0][2] + t[0][3] + t[0][4]) / 5;
		v[0] = h / avet[0];
		eta[0] = (rho - rho0)*g*d*d / (18.0 * v[0] * (1.0 + K*d / D));

		for(int i=0;i<5;i++)
		{
			t[1][i] = 30 + rand() % 30 * 0.1;
		}
		avet[1] = (t[1][0] + t[1][1] + t[1][2] + t[1][3] + t[1][4]) / 5;
		v[1] = h / avet[1];
		eta[1] = (rho - rho0)*g*d*d / (18.0 * v[1] * (1.0 + K*d / D));

		for(int i=0;i<5;i++)
		{
			t[2][i] = 24.5 + rand() % 30 * 0.1;
		}
		avet[2] = (t[2][0] + t[2][1] + t[2][2] + t[2][3] + t[2][4]) / 5;
		v[2] = h / avet[2];
		eta[2] = (rho - rho0)*g*d*d / (18.0 * v[2] * (1.0 + K*d / D));
	}
};

//3.4 弯曲法测定杨氏模量
class Class3_4
{
	double h[6], Utie[6], Utong[8], d, avea, aveb, ud, ua, ub;
public:
	void initialize()
	{
		//铁板
		cout << "请输入铁板的显微镜读数h（m从0g到100g时）（单位：mm）：" << endl;
		for (int i = 0; i < 6; i++)
		{
			cin >> h[i];
		}
		cout << "请输入铁板的电压值读数U（m从0g到100g时）（单位：V）：" << endl;
		for (int i = 0; i < 6; i++)
		{
			cin >> Utie[i];
		}

		//黄铜板
		cout << "请输入黄铜板的电压值读数U（m从0g到70g时）（单位：V）：" << endl;
		for (int i = 0; i < 8; i++)
		{
			cin >> Utong[i];
		}

		//计算a的不确定度
		int na;//na为组数
		cout << "实验所测得黄铜板不同部位的厚度a的数据共有几个？" << endl;
		cin >> na;
		if (na == 1)
		{
			cout << "请输入黄铜板厚度a（单位：mm）：" << endl;
			double a;
			cin >> a;
			avea = a;
			ua = 0;
			cout << "由于只有一组数据，无法测量不确定度，默认不确定度ua=0。" << endl;
		}
		else
		{
			double * a = new double[na];
			double totala = 0;
			cout << "请分别输入黄铜板厚度a（单位：mm）:";
			for (int i = 0; i < na; i++)
			{
				cin >> a[i];
			}
			for (int i = 0; i < na; i++)
			{
				totala += a[i];
			}
			avea = totala / na;//求出平均值avea
			ua = 0;
			for (int i = 0; i < na; i++)
			{
				ua += pow(a[i] - avea, 2);
			}
			ua /= na*(na - 1);
			ua = sqrt(ua);
		}

		//计算b的不确定度
		int nb;//nb为组数
		cout << "实验所测得黄铜板不同部位的宽度b的数据共有几个？" << endl;
		cin >> nb;
		if (nb == 1)
		{
			cout << "请输入黄铜板宽度b（单位：mm）：" << endl;
			double b;
			cin >> b;
			aveb = b;
			ub = 0;
			cout << "由于只有一组数据，无法测量不确定度，默认不确定度ub=0。" << endl;
		}
		else
		{
			double * b = new double[nb];
			double totalb=0;
			cout << "请分别输入黄铜板宽度b（单位：mm）:";
			for (int i = 0; i < nb; i++)
			{
				cin >> b[i];
			}
			for (int i = 0; i < nb; i++)
			{
				totalb += b[i];
			}
			aveb = totalb / nb;//求出平均值aveb
			ub = 0;
			for (int i = 0; i < nb; i++)
			{
				ub += pow(b[i] - aveb, 2);
			}
			ub /= nb*(nb - 1);
			ub = sqrt(ub);
		}

		//计算d的不确定度
		cout << "请输入两立柱刀口间的距离d(单位：mm）(d的不确定度ud默认为0)：" << endl;
		cin >> d;
		ud = 0;
		char changeud;
	J:
		cout << "是否估算d的不确定度（如果不懂请输入N）？(Y/N)" << endl;
		cin >> changeud;
		if (changeud == 'y' || changeud == 'Y'){ cout << "请输入估算的不确定度ud：" << endl; cin >> ud; }
		else if (changeud == 'n' || changeud == 'N'){ ; }
		else { goto J; }

	}
	void print()
	{
		double a_, b_, Lxx_, Lyy_, Lxy_, avex_ = 0, avey_ = 0, avexy_ = 0, avex2_ = 0, avey2_ = 0, R_;
		for (int i = 0; i < 6; i++)
		{
			avex_ += h[i];
			avey_ += Utie[i];
			avexy_ += h[i] * Utie[i];
			avex2_ += h[i] * h[i];
			avey2_ += Utie[i] * Utie[i];
		}
		avex_ /= 6;
		avey_ /= 6;
		avexy_ /= 6;
		avex2_ /= 6;
		avey2_ /= 6;
		//求斜率a和截距b
		a_ = (avexy_ - avex_*avey_) / (avex2_ - (avex_*avex_));
		b_ = avey_ - a_*avex_;
		//求相关系数R，检验y和x的线性关系
		Lxy_ = avexy_ - avex_*avey_;
		Lxx_ = avex2_ - avex_*avex_;
		Lyy_ = avey2_ - avey_*avey_;
		R_ = Lxy_ / sqrt(Lxx_*Lyy_);
		//输出x,y数据列表
		cout << "序号i\txi\t\tyi\t\txi^2\t\tyi^2\t\txiyi" << endl;
		for (int i = 0; i < 6; i++)
		{
			cout << i + 1 << "\t" << h[i] << "\t\t" << Utie[i] << "\t\t" << h[i] * h[i] << "\t\t" << Utie[i] * Utie[i] << "\t\t" << h[i] * Utie[i] << endl;
		}
		cout << "∑\t" << avex_*6 << "\t\t" << avey_*6 << "\t\t" << avex2_*6 << "\t\t" << avey2_*6 << "\t\t" << avexy_*6 << endl;
		cout << "平均值\t" << avex_ << "\t\t" << avey_ << "\t\t" << avex2_ << "\t\t" << avey2_ << "\t\t" << avexy_ << endl;
		//输出算式
		cout << "①根据最小二乘法公式求斜率和截距：" << endl;
		cout << "斜率a=" << a_ << endl;
		cout << "截距b=" << b_ << endl;
		cout << "②求相关系数，检验y和x的线性关系：" << endl;
		cout << "Lxy=" << Lxy_ << endl;
		cout << "Lxx=" << Lxx_ << endl;
		cout << "Lyy=" << Lyy_ << endl;
		cout << "相关系数R=Lxy / sqrt(Lxx*Lyy)=" << R_ << endl;
		cout << "根据所求得的回归直线的斜率和截距，得回归方程：y =" << a_ << "x+" << b_ << endl<<endl;
		double K;
		K = fabs(a_);
		cout <<lightblue<< "霍尔传感器的灵敏度K = " << K << endl;
		cout << "相关系数R = " << R_ << endl << endl<<white;
		

		//输出表格
		cout << "n\t" << "Ui/mV\t\t" << "Ui+4/mV\t\t" << "△Ui/mV\t\t" << "△hi/mm=△Ui/K" << endl;
		for (int i = 0; i < 4; i++)
		{
			cout << i + 1 << "\t" << Utong[i] << "\t\t" << Utong[i + 4] << "\t\t" << Utong[i + 4] - Utong[i] << "\t\t" << fabs((Utong[i + 4] - Utong[i]) / K )<< endl;
		}
		cout << endl;

		//计算△h的方差sigmah，其中aveh为平均值，totalh为总值
		double totalh = 0,sigmah = 0,aveh;
		for (int i = 0; i < 4; i++)
		{
			totalh += fabs((Utong[i + 4] - Utong[i]) / K);
		}
		aveh = totalh / 4;
		for (int i = 0; i < 4; i++)
		{
			sigmah += (fabs((Utong[i + 4] - Utong[i]) / K) - aveh)*(fabs((Utong[i + 4] - Utong[i]) / K) - aveh);
		}
		sigmah /= 4;
		sigmah = sqrt(sigmah);

		//计算杨氏模量Y(单位：N/mm^2）
		double Y, uY;
		Y = d*d*d * 0.04 * 9.8 / (4 * avea*avea*avea*aveb*aveh);
		uY = Y*sqrt(9 * (ud / d)* (ud / d) + 9 * (ua / avea)*(ua / avea) + (ub / aveb)*(ub / aveb) + (sigmah / aveh)*(sigmah / aveh));
		cout <<lightblue<< "a的不确定度ua = " << ua << endl;
		cout << "b的不确定度ua = " << ub << endl;
		cout << "d的不确定度ud = " << ud << endl;
		cout << "不确定度误差计算 uY/Y = " << uY / Y << endl;
		cout << "杨氏模量 Y = " << Y << "± " << uY << "（单位：N/mm^2）" << endl;
		cout << "即 " << Y * 1000 * 1000 << " ± " << uY * 1000 * 1000 << "（单位：N/m^2）" << endl<<endl<<white;
	}
	void randdata()
	{
		srand(time(0));
		//铁板
		cout << "铁板的显微镜读数h（m从0g到100g时）（单位：mm）：" << endl;
		h[0] = 5 + rand() % 2000 * 0.001;
		for (int i = 1; i < 6; i++)
		{
			h[i] = h[i - 1] + 0.3 + rand() % 500 * 0.001;
		}
		for (int i = 0; i < 6; i++)
		{
			cout << h[i]<<" ";
		}
		cout <<endl<< "铁板的电压值读数U（m从0g到100g时）（单位：V）：" << endl;
		Utie[0] = rand() % 400 * 0.1;
		for (int i = 1; i < 6; i++)
		{
			Utie[i] = Utie[i - 1] - 6.5 + rand() % 10 * 0.1;
		}
		for (int i = 0; i < 6; i++)
		{
			cout<< Utie[i]<<" ";
		}

		//黄铜板
		cout <<endl<< "黄铜板的电压值读数U（m从0g到70g时）（单位：V）：" << endl;
		Utong[0] = rand() % 4000 * 0.01 - 20;
		for (int i = 1; i < 8; i++)
		{
			Utong[i] = Utong[i - 1] + 3.5 + rand() % 10 * 0.1;
		}
		for (int i = 0; i < 8; i++)
		{
			cout<< Utong[i]<<" ";
		}
		cout << endl;

		//计算a的不确定度
		double * a = new double[5];
		double totala = 0;
		cout << "黄铜板厚度a分别为（单位：mm）:";
		for (int i = 0; i < 5; i++)
		{
			a[i] = 0.98 + rand() % 4 * 0.01;
			cout << a[i] << " ";
		}
		cout << endl;
		for (int i = 0; i < 5; i++)
		{
			totala += a[i];
		}
		avea = totala / 5;//求出平均值avea
		ua = 0;
		for (int i = 0; i < 5; i++)
		{
			ua += pow(a[i] - avea, 2);
		}
		ua /= 5*(5 - 1);
		ua = sqrt(ua);
	

		//计算b的不确定度
		double * b = new double[5];
		double totalb = 0;
		cout << "黄铜板宽度b分别为（单位：mm）:";
		for (int i = 0; i < 5; i++)
		{
			b[i] = 22 + rand() % 100 * 0.01;
			cout << b[i] << " ";
		}
		cout << endl;
		for (int i = 0; i < 5; i++)
		{
			totalb += b[i];
		}
		aveb = totalb / 5;//求出平均值avea
		ub = 0;
		for (int i = 0; i < 5; i++)
		{
			ub += pow(b[i] - aveb, 2);
		}
		ub /= 5 * (5 - 1);
		ub = sqrt(ub);

		//计算d的不确定度
		cout << "两立柱刀口间的距离d(单位：mm）(d的不确定度ud默认为0)为：";
		d=220+rand()%20;
		cout << d << endl;
		ud = 0;

	}
};

//4.1 PN结正向电压温度特性研究
class Class4_1
{
	double S, Vg0, Vf, tr, Eg0, *V, *t; int n;
public:
	void initialize()
	{
		cout << "请输入室温tr：" << endl;
		cin >> tr;
		cout << "请输入室温下的电压值Vf（单位：mV）：" << endl;
		cin >> Vf;
		J:
		cout << "请输入t与△V（单位：mV）数据的组数n：" << endl;
		cin >> n;
		if (n == 1){ cout << "ERROR：数据组数不能为1！" << endl; goto J; }
		t = new double[n];
		V = new double[n];
		for (int i = 0; i < n; i++)
		{
			cout << "请输入第" << i + 1 << "组数据的t和△V（单位：mV）：" << endl;
			cin >> t[i] >> V[i];
		}
	}
	void print()
	{	
		cout.precision(5);
		double a, b, Lxx, Lyy, Lxy, avex = 0, avey = 0, avexy = 0, avex2 = 0, avey2 = 0, R;

		for (int i = 0; i < n; i++)
		{
			avex += t[i];
			avey += V[i];
			avexy += t[i] * V[i];
			avex2 += t[i] * t[i];
			avey2 += V[i] * V[i];
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
			cout << i + 1 << "\t" << t[i] << "\t\t" << V[i] << "\t\t" << t[i] * t[i] << "\t\t" << V[i] * V[i] << "\t\t" << t[i] * V[i] << endl;
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

		S = -a;
		cout << endl <<yellow<< "PN结温度传感器灵敏度S = " << S << " mV/°C" << endl;
		Vf = Vf / 1000.0;
		for (int i = 0; i < n; i++)
		{
			V[i] = V[i] / 1000.0;
		}
		Vg0 = Vf + S/1000.0*(273.2 + tr);
		cout << endl << "热力学温度0K时PN结材料的导带底与价带顶的电势差Vg(0)为：" << endl << "Vg(0) = Vf + S * (273.2 + tr) = " << Vg0 <<"eV"<< endl;
		Eg0 = Vg0;
		cout << endl << "PN结材料的禁带宽度Eg(0) = " << Eg0 <<" eV"<< endl;
		cout << "Eg(0)与公认值1.21eV的";
		basic1(Eg0, 1.21);
		cout << endl<<white;
	}
	void randdata()
	{
		srand(time(0));
		tr=25.6+rand()%10*0.1;
		cout << "室温tr=" <<tr<< endl;
		Vf=610+rand()%11;
		cout << "室温下的电压值Vf="<<Vf<<"（mV）" << endl;
		n=11;
		t = new double[n];
		V = new double[n];
		for(int i=0;i<n;i++)
		{
			V[i]=-10*(i+1);
		}
		t[0]=25.6+rand()%10*0.1;
		t[1]=33.9+rand()%10*0.1;
		t[2]=39.5+rand()%10*0.1;
		t[3]=44.8+rand()%10*0.1;
		t[4]=49.5+rand()%10*0.1;
		t[5]=58.9+rand()%10*0.1;
		t[6]=62.9+rand()%10*0.1;
		t[7]=66.9+rand()%10*0.1;
		t[8]=66.8+rand()%10*0.1;
		t[9]=71.2+rand()%10*0.1;
		t[10]=74.5+rand()%10*0.1;

		cout<<"△V/mV\t";
		for(int i=0;i<6;i++)
		{
			cout<<V[i]<<"\t";
		}
		cout<<endl<<"T/°C\t";
		for(int i=0;i<6;i++)
		{
			cout<<t[i]<<"\t";
		}
		cout<<endl;

		cout<<"△V/mV\t";
		for(int i=6;i<11;i++)
		{
			cout<<V[i]<<"\t";
		}
		cout<<endl<<"T/°C\t";
		for(int i=6;i<11;i++)
		{
			cout<<t[i]<<"\t";
		}
		cout<<endl;
	}
};

//4.3 惠斯登电桥测电阻
class Class4_3
{
	double R0a, R0a1, R0a2, R0b, R0b1, R0b2, R0c, R0c1, R0c2, R0d, R0d1, R0d2;

public:
	void initialize()
	{
		cout << "请分别输入待测电阻为51Ω时的测量值R0，左偏和右偏后的电阻R0'：" << endl;
		cin >> R0a >> R0a1 >> R0a2;
		cout << "请分别输入待测电阻为220Ω时的测量值R0，左偏和右偏后的电阻R0'：" << endl;
		cin >> R0b >> R0b1 >> R0b2;
		cout << "请分别输入待测电阻为1500Ω时的测量值R0，左偏和右偏后的电阻R0'：" << endl;
		cin >> R0c >> R0c1 >> R0c2;
		cout << "请分别输入待测电阻为22000Ω时的测量值R0，左偏和右偏后的电阻R0'：" << endl;
		cin >> R0d >> R0d1 >> R0d2;
	}
	void print()
	{
		double Elima, Elimb, Elimc, Elimd; double deltaRa, deltaRb, deltaRc, deltaRd;
		
		Elima = (100.0 / 10.0 + R0a)*0.5*0.01 / 100.0;
		Elimb = (1000.0 / 10.0 + R0b)*0.3*0.1 / 100.0;
		Elimc = (10000.0 / 10.0 + R0c)*0.2 / 100.0;
		Elimd = (100000.0 / 10.0 + R0d)*10.0 / 100.0;
		deltaRa = (fabs(R0a1 - R0a) + fabs(R0a2 - R0a)) / 2.0;
		deltaRb = (fabs(R0b1 - R0b) + fabs(R0b2 - R0b)) / 2.0;
		deltaRc = (fabs(R0c1 - R0c) + fabs(R0c2 - R0c)) / 2.0;
		deltaRd = (fabs(R0d1 - R0d) + fabs(R0d2 - R0d)) / 2.0;

		cout.precision(4);
		cout << yellow;

		cout << "待测电阻\tRx1\t\tRx2\t\tRx3\t\tRx4" << endl;
		cout << "电阻标称值/Ω\t51Ω\t\t220Ω\t\t1500Ω\t\t22000Ω" << endl;
		cout << "比率k\t\t0.01\t\t0.1\t\t1\t\t10" << endl;
		cout << "准确度等级α\t0.5\t\t0.3\t\t0.2\t\t1" << endl;
		cout << "R0(R3)/Ω\t" << R0a << "\t\t" << R0b << "\t\t" << R0c << "\t\t" << R0d << endl;
		cout << "平衡后G偏调2格\t 左偏\t 右偏\t 左偏\t 右偏\t 左偏\t 右偏\t 左偏\t 右偏" << endl;
		cout << "（偏0.1μA）\t(负偏)\t(正偏)\t(负偏)\t(正偏)\t(负偏)\t(正偏)\t(负偏)\t(正偏)" << endl;
		cout << "R0'(R3')/Ω\t" << R0a1 << "\t" << R0a2 << "\t" << R0b1 << "\t" << R0b2 << "\t" << R0c1 << "\t" << R0c2 << "\t" << R0d1 << "\t" << R0d2 << endl;
		cout << "△R0=|R0-R0'|\t" << fabs(R0a1 - R0a) << "\t" << fabs(R0a2 - R0a) << "\t" << fabs(R0b1 - R0b) << "\t" << fabs(R0b2 - R0b) << "\t" << fabs(R0c1 - R0c) << "\t" << fabs(R0c2 - R0c) << "\t" << fabs(R0d1 - R0d) << "\t" << fabs(R0d2 - R0d) << endl;
		cout << "μB/Ω\t\t" << 0.01*fabs(R0a1 - R0a) / 1.732 << "\t" << 0.01*fabs(R0a2 - R0a) / 1.732 << "\t" << 0.1*fabs(R0b1 - R0b) / 1.732 << "\t" << 0.1*fabs(R0b2 - R0b) / 1.732 << "\t" << fabs(R0c1 - R0c) / 1.732 << "\t" << fabs(R0c2 - R0c) / 1.732 << "\t" << 10 * fabs(R0d1 - R0d) / 1.732 << "\t" << 10 * fabs(R0d2 - R0d) / 1.732 << endl;
		cout << "μB的均值/Ω\t" << (0.01*fabs(R0a1 - R0a) / 1.732 + 0.01*fabs(R0a2 - R0a) / 1.732) / 2.0 << "\t\t" << (0.1*fabs(R0b1 - R0b) / 1.732 + 0.1*fabs(R0b2 - R0b) / 1.732) / 2.0 << "\t\t" << (fabs(R0c1 - R0c) / 1.732 + fabs(R0c2 - R0c) / 1.732) / 2.0 << "\t\t" << (10.0*fabs(R0d1 - R0d) / 1.732 + 10 * fabs(R0d2 - R0d) / 1.732) / 2.0 << endl;
		cout << "测量量kR0/Ω\t" << 0.01*R0a << "\t\t" << 0.1*R0b << "\t\t" << R0c << "\t\t" << 10.0 * R0d << endl;
		cout << "|Elim|/Ω\t" << Elima << "\t\t" << Elimb << "\t\t" << Elimc << "\t\t" << Elimd << endl;
		cout << "μR/Ω\t\t" << sqrt(Elima*Elima + deltaRa*deltaRa) << "\t\t" << sqrt(Elimb*Elimb + deltaRb*deltaRb) << "\t\t" << sqrt(Elimc*Elimc + deltaRc*deltaRc) << "\t\t" << sqrt(Elimd*Elimd + deltaRd*deltaRd) << endl;
		cout << "Rx=kR0±μR/Ω\t" << 0.01*R0a << "±" << sqrt(Elima*Elima + deltaRa*deltaRa) << "\t" << 0.1*R0b << "±" << sqrt(Elimb*Elimb + deltaRb*deltaRb) << "\t" << R0c << "±" << sqrt(Elimc*Elimc + deltaRc*deltaRc) << "\t" << 10.0 * R0d << "±" << sqrt(Elimd*Elimd + deltaRd*deltaRd) << endl;
		cout << endl << white;
	}
	void randdata()
	{
		srand(time(0));
		R0a = 5080 + rand() % 40;
		R0a1 = R0a + rand() % 4+ 1;
		R0a2 = R0a - rand() % 4 - 1;
		R0b = 2185 + rand() % 30;
		R0b1 = R0b + rand() % 3 + 1;
		R0b2 = R0b - rand() % 3 - 1;
		R0c = 1540 + rand() % 20;
		R0c1 = R0c + rand() % 2 + 1;
		R0c2 = R0c - rand() % 2 - 1;
		R0d = 2180 + rand() % 40;
		R0d1 = R0d + rand() % 10 + 1;
		R0d2 = R0d - rand() % 10 - 1;
	}
};

//4.4 非平衡电桥电压输出特性研究
class Class4_4
{	
	double *deltaR, *R, *UAB, *T, k; int n, Tjiange;
public:
	void initialize()
	{
		cout << "请输入非平衡电压测量组数n（默认为8）：" << endl;
		cin >> n;
		UAB = new double[n + 1];
		T = new double[n + 1];
		R = new double[n + 1];
		deltaR = new double[n + 1];
		deltaR[0] = 0; UAB[0] = 0;
		cout << "请输入室温温度T0：" << endl;
		cin >> T[0];
		cout << "请输入室温时铜电阻阻值RX0：" << endl;
		cin >> R[0];
		k = 500.0 / R[0];
		cout << "请输入记录第一个非平衡电压时的温度T1：" << endl;
		cin >> T[1];
		cout << "请输入每次测量温度间隔（默认为5°C）：" << endl;
		cin >> Tjiange;
		for (int i = 1; i < n; i++)
		{
			T[i + 1] = T[1] + i*Tjiange;
		}
		cout << "请依次输入非平衡电压UAB的数值：" << endl;
		for (int i = 1; i < n + 1; i++)
		{
			cin >> UAB[i];
		}
	}
	void print()
	{
		cout.precision(5);
		double U0 = 1300.0;
		
		for (int i = 1; i < n + 1; i++)
		{
			deltaR[i] = (k + 1)*(k + 1)*UAB[i] * R[0] / (k*U0 - (k + 1)*UAB[i]);
		}
		for (int i = 1; i < n + 1; i++)
		{
			R[i] = R[0] + deltaR[i];
		}

		cout << yellow;
		cout << "T/°C\t\t非平衡电压UAB/mV\t铜电阻变化量△R/Ω\t铜电阻R/Ω" << endl;
		for (int i = 1; i < n + 1; i++)
		{
			cout << T[i] << "\t\t" << UAB[i] << "\t\t\t" << deltaR[i] << "\t\t\t" << R[i] << endl;
		}
		cout << white;
		cout << endl << "以下用最小二乘法拟合直线R(T)-T：" << endl;

		double a, b, Lxx, Lyy, Lxy, avex = 0, avey = 0, avexy = 0, avex2 = 0, avey2 = 0, R_;
		for (int i = 0; i < n+1; i++)
		{
			avex += T[i];
			avey += R[i];
			avexy += T[i] * R[i];
			avex2 += T[i] * T[i];
			avey2 += R[i] * R[i];
		}
		avex /= n+1;
		avey /= n+1;
		avexy /= n+1;
		avex2 /= n+1;
		avey2 /= n+1;
		//求斜率a和截距b
		a = (avexy - avex*avey) / (avex2 - (avex*avex));
		b = avey - a*avex;
		//求相关系数R，检验y和x的线性关系
		Lxy = avexy - avex*avey;
		Lxx = avex2 - avex*avex;
		Lyy = avey2 - avey*avey;
		R_ = Lxy / sqrt(Lxx*Lyy);
		//输出x,y数据列表
		cout << "序号i\txi\t\tyi\t\txi^2\t\tyi^2\t\txiyi" << endl;
		for (int i = 0; i < n+1; i++)
		{
			cout << i + 1 << "\t" << T[i] << "\t\t" << R[i] << "\t\t" << T[i] * T[i] << "\t\t" << R[i] * R[i] << "\t\t" << T[i] * R[i] << endl;
		}
		cout << "∑\t" << avex*(n + 1) << "\t\t" << avey*(n + 1) << "\t\t" << avex2*(n + 1) << "\t\t" << avey2*(n + 1) << "\t\t" << avexy*(n + 1) << endl;
		cout << "平均值\t" << avex << "\t\t" << avey << "\t\t" << avex2 << "\t\t" << avey2 << "\t\t" << avexy << endl;
		//输出算式
		cout << "①根据最小二乘法公式求斜率和截距：" << endl;
		cout << "斜率a=" << a << endl;
		cout << "截距b=" << b << endl;
		cout << "②求相关系数，检验y和x的线性关系：" << endl;
		cout << "Lxy=" << Lxy << endl;
		cout << "Lxx=" << Lxx << endl;
		cout << "Lyy=" << Lyy << endl;
		cout << "相关系数R=Lxy / sqrt(Lxx*Lyy)=" << R_ << endl;
		cout << "根据所求得的回归直线的斜率和截距，得回归方程：y =" << a << "x+" << b << endl;

		cout << yellow << endl << "0°C时的电阻值R0=" << b << "，电阻温度系数α=△R/R0△T=" << a / b << endl;
		cout << "铜电阻与温度的关系表达式：R = " << a << "T + " << b << endl;
		cout << "取室温T0时铜电阻与理论值比较，";
		basic1(R[0], a*T[0] + b);
		cout << white;

	}
	void randdata()
	{
		srand(time(0));
		n = 8;
		UAB = new double[n + 1];
		T = new double[n + 1];
		R = new double[n + 1];
		deltaR = new double[n + 1];
		deltaR[0] = 0; UAB[0] = 0;

		T[0] = 25+rand()%200*0.01;
		cout << "室温温度T0为"<<T[0]<<"度。" << endl;
		R[0]=55+rand()%200*0.01;
		cout << "室温时铜电阻阻值RX0为"<<R[0]<<"Ω" << endl;
		k = 500.0 / R[0];
		T[1] = 5 + T[0];
		Tjiange=5;
		for (int i = 1; i < n; i++)
		{
			T[i + 1] = T[1] + i*Tjiange;
		}
		UAB[1] = 1.3 + rand() % 4 * 0.1;
		UAB[2] = 3.7 + rand() % 4 * 0.1;
		UAB[3] = 5.8 + rand() % 4 * 0.1;
		UAB[4] = 7.8 + rand() % 4 * 0.1;
		UAB[5] = 9.9 + rand() % 4 * 0.1;
		UAB[6] = 12.0 + rand() % 4 * 0.1;
		UAB[7] = 14.1 + rand() % 4 * 0.1;
		UAB[8] = 16.4 + rand() % 4 * 0.1;

	}
};

//4.6 模拟示波器的使用
class Class4_6
{
	double A[8], K[8], VPP[8], D[8], S[8], f[8];
public:
	void initialize()
	{
		cout << "请按顺序输入8个数据A/DIV：" << endl;
		for (int i = 0; i < 8;i++)
		{
			cin >> A[i];
		}
		cout << "请按顺序输入8个数据K/(V/DIV)（单位：V）：" << endl;
		for (int i = 0; i < 8; i++)
		{
			cin >> K[i];
		}
		cout << "请按顺序输入8个数据D/DIV：" << endl;
		for (int i = 0; i < 8; i++)
		{
			cin >> D[i];
		}
		cout << "请按顺序输入8个数据S/(S/DIV)"<<red<<"（单位是秒啊！)：" <<white<< endl;
		for (int i = 0; i < 8; i++)
		{
			cin >> S[i];
		}
	}
	void print()
	{
		cout.precision(3);
		for (int i = 0; i < 8; i++)
		{
			VPP[i] = K[i] * A[i];
			f[i] = 1 / (D[i] * S[i]);
		}
		
		cout << yellow;
		cout << "项目\\信号名称\tU1\tU2\tU3\tU4\tU5\tU6\tU7\tU8"<<endl;
		cout << "A/DIV\t";
		for (int i = 0; i < 8; i++)
		{
			cout << "\t" << A[i];
		}
		cout << endl;
		cout << "K/(V/DIV)";
		for (int i = 0; i < 8; i++)
		{
			cout << "\t" << K[i];
		}
		cout << endl;
		cout << "Vp-p/V\t";
		for (int i = 0; i < 8; i++)
		{
			cout << "\t" << VPP[i];
		}
		cout << endl;
		cout << "D/DIV\t";
		for (int i = 0; i < 8; i++)
		{
			cout << "\t" << D[i];
		}
		cout << endl;
		cout << "S/(S/DIV)";
		for (int i = 0; i < 8; i++)
		{
			cout << "\t" << S[i];
		}
		cout << endl;
		cout << "f/Hz\t";
		for (int i = 0; i < 8; i++)
		{
			cout << "\t" << f[i];
		}
		cout << endl;
		cout << white;
	}
	void randdata()
	{
		cout << red << "为了尊重客观事实，本实验只提供一组真实数据。" << endl << endl << yellow ;
		A[0] = 3.5; A[1] = 1.8; A[2] = 4.4; A[3] = 2.6; A[4] = 3; A[5] = 5.8; A[6] = 5.2; A[7] = 2.4;
		K[0] = 5; K[1] = 5; K[2] = 2; K[3] = 2; K[4] = 2; K[5] = 2; K[6] = 2; K[7] = 2;
		D[0] = 4; D[1] = 5; D[2] = 4; D[3] = 5; D[4] = 5; D[5] = 5; D[6] = 5; D[7] = 2;
		S[0] = 0.005; S[1] = 0.002; S[2] = 0.005; S[3] = 0.0002; S[4] = 0.00002; S[5] = 0.0002; S[6] = 0.00002; S[7] = 0.0005;
		cout << white;
	}
};

//5.2 偏振光特性研究
void print5_2()
{
	cout << "本实验不涉及数据处理，以下实验现象仅供参考：" << endl;
	cout << "1/4波片C转动角度\tA转动360°的现象\t从1/4波片C出来的光的偏振性质"<<endl;
	cout << "\t0°\t\t消光-亮-消光-亮-消光\t\t线偏振光" << endl;
	cout << "\t15°\t\t暗-亮-暗-亮-暗\t\t\t椭圆偏振光" << endl;
	cout << "\t30°\t\t暗-亮-暗-亮-暗\t\t\t椭圆偏振光" << endl;
	cout << "\t45°\t\t亮度不变\t\t\t圆偏振光" << endl;
	cout << "\t60°\t\t暗-亮-暗-亮-暗\t\t\t椭圆偏振光" << endl;
	cout << "\t75°\t\t暗-亮-暗-亮-暗\t\t\t椭圆偏振光" << endl;
	cout << "\t90°\t\t消光-亮-消光-亮-消光\t\t线偏振光" << endl;
}

//5.3 光的等厚干涉现象
class Class5_3
{
	double *Dm, *Dn, *pingfangcha, *R, avepingfangcha , uR , aveR ; int maxm, minn, hangshu;//平方差pingfangcha=Dm^2-Dn^2,maxm为最大暗环级数,minn为最小
	double *zuo, *you;
public:
	void initialize()
	{
		avepingfangcha = 0; uR = 0; aveR = 0;
	J:
		cout << "请输入最大的暗环级数m（默认30）：" << endl;
		cin >> maxm;
		cout << "请输入最小的暗环级数n（默认19）：" << endl;
		cin >> minn;
		if ((maxm - minn) % 2 == 0){ cout << "ERROR：请确保暗环级数个数为偶数！" << endl; goto J; }
		hangshu = (maxm - minn + 1) / 2;
		zuo = new double[hangshu * 2];
		you = new double[hangshu * 2];
		Dm = new double[hangshu];
		Dn = new double[hangshu];
		pingfangcha = new double[hangshu];
		R = new double[hangshu];
		cout << "请按暗环级数从大到小顺序输入暗环位置为左时的数据："<< endl;
		for (int i = 0; i < hangshu*2; i++)
		{
			cin >> zuo[i];
		}
		cout << "请按暗环级数从大到小顺序输入暗环位置为右时的数据：" << endl;
		for (int i = 0; i < hangshu*2; i++)
		{
			cin >> you[i];
		}
		for (int i = 0; i < hangshu; i++)
		{
			Dm[i] = fabs(zuo[i] - you[i]);
			Dn[i] = fabs(zuo[i+hangshu]-you[i+hangshu]);
		}
	}
	void print()
	{
		cout.precision(5);
		cout << endl << "钠光波长λ=589.3nm，环数差m-n=" << hangshu << "，单位mm。" << endl;
		cout << "暗环级数m\tDm\t暗环级数n\tDn\tDm^2-Dn^2/mm^2\tR" << endl;
		for (int i = 0; i < hangshu; i++)
		{
			pingfangcha[i] = Dm[i] * Dm[i] - Dn[i] * Dn[i];
			avepingfangcha += pingfangcha[i];
			R[i] = pingfangcha[i] / (4.0 * hangshu*589.3*0.000001);
			aveR += R[i];
			cout << maxm - i << "\t\t" << Dm[i] << "\t" << maxm - hangshu - i << "\t\t" << Dn[i] << "\t" << pingfangcha[i] << "\t\t" << R[i] << endl;
		}
		avepingfangcha /= hangshu;
		aveR /= hangshu;//get aveR
		for (int i = 0; i < hangshu; i++)
		{
			uR += pow(pingfangcha[i] - avepingfangcha, 2);
		}
		uR = sqrt(uR / double(hangshu - 1));
		cout << purple;
		cout << "Dm^2-Dn^2的平均值为：" << avepingfangcha << "mm^2" << endl;
		cout << "半径R的平均值averageR = " << aveR << " (mm)" << endl;
		cout << "半径R的不确定度uR = " << uR << " (mm)" << endl;
		cout << "牛顿环曲率半径为R = averageR±uR = " << aveR << " ± " << uR << " (mm)" << endl;
		cout << white;
	}
	void randdata()
	{
		srand(time(0));
		avepingfangcha = 0; uR = 0; aveR = 0;
		maxm = 15;
		minn = 6;
		hangshu = (maxm - minn + 1) / 2;
		zuo = new double[hangshu * 2];
		you = new double[hangshu * 2];
		Dm = new double[hangshu];
		Dn = new double[hangshu];
		pingfangcha = new double[hangshu];
		R = new double[hangshu];
		cout << "暗环级数从大到小顺序输入暗环位置为左时的数据：" << endl;
		zuo[0] = 21.7 + rand() % 200 * 0.001;
		for (int i = 1; i < hangshu * 2; i++)
		{
			zuo[i] = zuo[i - 1] - 0.08 - rand() % 30 * 0.001;
		}
		for (int i = 0; i < hangshu * 2; i++)
		{
			cout << zuo[i] << " ";
		}
		cout << endl;
		cout << "暗环级数从大到小顺序输入暗环位置为右时的数据：" << endl;
		you[0] = 15.7 + rand() % 200 * 0.001;
		for (int i = 1; i < hangshu * 2; i++)
		{
			you[i] = you[i - 1] + 0.1 + rand() % 30 * 0.001;
		}
		for (int i = 0; i < hangshu * 2; i++)
		{
			cout << you[i] << " ";
		}
		cout << endl;
		for (int i = 0; i < hangshu; i++)
		{
			Dm[i] = fabs(zuo[i] - you[i]);
			Dn[i] = fabs(zuo[i + hangshu] - you[i + hangshu]);
		}
	}
};

//5.4 光的衍射
class Class5_4
{
	double I0, I1a, I1b, I2a, I2b;
public:
	void print()
	{
	J:
		cout << "请输入衍射角φ=0时光强值I0：" << endl;
		cin >> I0;
		cout << "请输入衍射角φ满足sinφ=±1.43λ/a时光强值（两个）：" << endl;
		cin >> I1a >> I1b;
		cout << "请输入衍射角φ满足sinφ=±2.46λ/a时光强值（两个）：" << endl;
		cin >> I2a >> I2b;
		cout << "sinφ=±1.43λ/a时光强值与I0比例为(理论值0.047)：" << I1a / I0 << "\t" << I1b / I0 << endl;
		cout << "sinφ=±2.46λ/a时光强值与I0比例为(理论值0.017)：" << I2a / I0 << "\t" << I2b / I0 << endl;
	K:
		cout << "再算一组？（Y/N）" << endl;
		char again;
		cin >> again;
		if (again == 'Y' || again == 'y'){ goto J; }
		else if (again == 'N' || again == 'n'){ ; }
		else { goto K; }
	}
	void randdata()
	{
		cout << purple;
		double a,b,c,d,e;
		srand(time(0));
		cout<<"\tI2\tI1\tI0\tI1\tI2"<<endl;
		c=400+rand()%1800;
		a=c*(0.015+(rand()%15*0.001));
		b=c*(0.015+(rand()%15*0.001));
		d=c*(0.04+(rand()%20*0.001));
		e=c*(0.04+(rand()%20*0.001));
		cout<<"测量值\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<endl;
		cout<<"比例\t"<<a/c<<"\t"<<b/c<<"\t"<<c/c<<"\t"<<d/c<<"\t"<<e/c<<endl;
		c=400+rand()%1800;
		a=c*(0.015+(rand()%15*0.001));
		b=c*(0.015+(rand()%15*0.001));
		d=c*(0.04+(rand()%20*0.001));
		e=c*(0.04+(rand()%20*0.001));
		cout<<"测量值\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<endl;
		cout<<"比例\t"<<a/c<<"\t"<<b/c<<"\t"<<c/c<<"\t"<<d/c<<"\t"<<e/c<<endl;
		c=400+rand()%1800;
		a=c*(0.015+(rand()%15*0.001));
		b=c*(0.015+(rand()%15*0.001));
		d=c*(0.04+(rand()%20*0.001));
		e=c*(0.04+(rand()%20*0.001));
		cout<<"测量值\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<endl;
		cout<<"比例\t"<<a/c<<"\t"<<b/c<<"\t"<<c/c<<"\t"<<d/c<<"\t"<<e/c<<endl;
		c=400+rand()%1800;
		a=c*(0.015+(rand()%15*0.001));
		b=c*(0.015+(rand()%15*0.001));
		d=c*(0.04+(rand()%20*0.001));
		e=c*(0.04+(rand()%20*0.001));
		cout<<"测量值\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<endl;
		cout<<"比例\t"<<a/c<<"\t"<<b/c<<"\t"<<c/c<<"\t"<<d/c<<"\t"<<e/c<<endl;
		c=400+rand()%1800;
		a=c*(0.015+(rand()%15*0.001));
		b=c*(0.015+(rand()%15*0.001));
		d=c*(0.04+(rand()%20*0.001));
		e=c*(0.04+(rand()%20*0.001));
		cout<<"测量值\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<endl;
		cout<<"比例\t"<<a/c<<"\t"<<b/c<<"\t"<<c/c<<"\t"<<d/c<<"\t"<<e/c<<endl;
		
		cout << white;
	}
};

//5.5 分光计的调整与使用
class Class5_5
{
	double theta1[5], theta1_[5], theta2[5], theta2_[5], theta0[5], avetheta0, utheta0, n[5], aven, un, *fai, avefai, ufai;
	int nfai;

public:
	void initialize()
	{
		avetheta0 = 0; utheta0 = 0; avefai = 0; ufai = 0;
		//棱镜顶角fai的计算及不确定度
		cout << "请输入测量棱镜的顶角φ数值的个数（可为1）：" << endl;
		cin >> nfai;
		if (nfai == 1)
		{
			cout << "请输入棱镜的顶角φ数值（弧度制）：" << endl;
			cin >> avefai;
			ufai = 0;
			cout << "请输入顶角φ的不确定度：" << endl;
			cin >> ufai;
		}
		else
		{
			fai = new double[nfai];
			cout << "请输入棱镜的顶角φ数值（弧度制）：" << endl;
			for (int i = 0; i < nfai; i++)
			{
				cin >> fai[i];
			}
			for (int i = 0; i < nfai; i++)
			{
				avefai += fai[i];
			}
			avefai /= nfai;//求出平均值avefai
			for (int i = 0; i < nfai; i++)
			{
				ufai += pow(fai[i] - avefai, 2);
			}
			ufai /= nfai*(nfai - 1);
			ufai = sqrt(ufai);//fai的不确定度ufai
			cout << "φ的不确定度uφ=" << ufai << endl;
			cout << "φ = " << avefai << " ± " << ufai << endl;
		}


		//输入数据
		cout << "请按顺序输入折射光位置读数θ1，θ1'和入射光位置读数θ2，θ2'：" << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << "测量序数k=" << i + 1 << endl;
			cin >> theta1[i] >> theta1_[i] >> theta2[i] >> theta2_[i];
			theta0[i] = (fabs(theta1[i] - theta2[i]) + fabs(theta1_[i] - theta2_[i])) / 2;
			n[i] = sin(0.5*(avefai + theta0[i])) / sin(0.5*avefai);
		}
	}
	void print()
	{
		cout.precision(4);
		cout << purple;
		//输出表格
		cout << "测量序数k\t折射光位置读数\t\t入射光位置读数\t\tθ0\tn" << endl;
		cout << "\t\tθ1\tθ'1\t\tθ2\tθ'2" << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << "\t" << i + 1 << "\t" << theta1[i] << "\t" << theta1_[i] << "\t\t" << theta2[i] << "\t" << theta2_[i] << "\t\t" << theta0[i] << "\t" << n[i] << endl;
		}

		//theta0的计算及不确定度
		for (int i = 0; i < 5; i++)
		{
			avetheta0 += theta0[i];
		}
		avetheta0 /= 5;//求出平均值avetheta0
		for (int i = 0; i < 5; i++)
		{
			utheta0 += pow(theta0[i] - avetheta0, 2);
		}
		utheta0 /= 5*(5 - 1);
		utheta0 = sqrt(utheta0);//theta0的不确定度utheta0;
		cout << "θ0的不确定度uθ0=" << utheta0 << endl;
		cout << "θ0 = " << avetheta0 << " ± " << utheta0 << endl;

		//棱镜的折射率
		aven = sin(0.5*(avefai + avetheta0)) / sin(0.5*avefai);
		cout << "棱镜的折射率n均值为" << aven << endl;

		//n的不确定度
		double n_fai, n_theta;//偏导
		n_fai = 0.5*cos(0.5*(avefai + avetheta0))*sin(0.5*avefai) - 0.5*cos(0.5*avefai)*sin(0.5*(avefai + avetheta0)) / pow(sin(0.5*avefai), 2);
		n_theta = 0.5*cos(0.5*(avefai + avetheta0));
		un = sqrt(n_fai*n_fai*ufai*ufai + n_theta*n_theta*utheta0*utheta0);
		cout << "n的不确定度un = " << un << endl;


		//计算结果
		cout << "计算结果n = " << aven << " ± " << un << endl;
		cout << white;

	}
};

//6.9 物质旋光率的测量
class Class6_9
{
	double l1, l2, c, alpha1, alpha2, *phi1, *phi2, ave1, ave2;//phi->φ偏转面旋转角度,ave1和ave2为phi的均值
	int n;//n为数组phi的长度
public:
	void initialize()
	{

		ave1 = 0; ave2 = 0;
		cout << "********本实验只提供溶液旋光率的测量数据处理********" << endl;
		cout << "请输入试管长度l1与l2（单位：mm）：" << endl;
		cin >> l1 >> l2;
		cout << "请输入溶液浓度c：" << endl;
		cin >> c;
		cout << "请输入每种试管旋转角度φ的数据个数n：" << endl;
		cin >> n;
		phi1 = new double[n];
		phi2 = new double[n];
		cout << "请输入试管长度为l1时的旋转角度测量值（单位：°）：" << endl;
		for (int i = 0; i < n; i++)
		{
			cin >> phi1[i];
			ave1 += phi1[i];
		}
		ave1 /= n;
		cout << "请输入试管长度为l2时的旋转角度测量值（单位：°）：" << endl;
		for (int i = 0; i < n; i++)
		{
			cin >> phi2[i];
			ave2 += phi2[i];
		}
		ave2 /= n;
		alpha1 = ave1 / (l1*c);
		alpha2 = ave2 / (l2*c);
	}
	void print()
	{	
		cout << green;
		cout << "长度为l1的试管计算得到的旋光率为（单位：°/mm）：" << alpha1 << endl;
		cout << "长度为l2的试管计算得到的旋光率为（单位：°/mm）：" << alpha2 << endl;
		cout << white;

	}
	void randdata()
	{
		srand(time(0));
		l1 = 100; l2 = 200;
		cout << "试管长度l1=100mm,l2=200mm" << endl;
		c = 0.1;
		cout << "溶液浓度c=0.1" << endl;
		ave1 = 0; ave2 = 0;
		cout << "每种试管旋转角度φ的数据个数n=10" << endl;
		n = 10;
		phi1 = new double[n];
		phi2 = new double[n];
		cout << "l1试管的旋转角度测量值分别为：";
		for (int i = 0; i < n; i++)
		{
			phi1[i] = 4.4 + (rand() % 40)*0.01;
			ave1 += phi1[i];
			cout << phi1[i] << " ";
		}
		cout << endl;
		ave1 /= n;
		cout << "l2试管的旋转角度测量值分别为：";
		for (int i = 0; i < n; i++)
		{
			phi2[i] = 9.2 + (rand() % 40)*0.01;
			ave2 += phi2[i];
			cout << phi2[i] << " ";
		}
		cout << endl;
		ave2 /= n;
		alpha1 = ave1 / (l1*c);
		alpha2 = ave2 / (l2*c);

	}
};

int main()
{
	Class3_2 C3_2;
	Class3_4 C3_4;
	Class4_1 C4_1;
	Class4_3 C4_3;
	Class4_4 C4_4;
	Class4_6 C4_6;
	Class5_3 C5_3;
	Class5_4 C5_4;
	Class5_5 C5_5;
	Class6_9 C6_9;

J:
	system("cls");
	
	cout << "*************欢迎使用大物实验数据处理系统*************" << endl;

	cout << purple;
	cout << "第三章 力学与热学实验" << endl;
	cout << "3.2 液体粘滞系数的测量及其温度特性研究" << endl;
	cout << "3.4 弯曲法测定杨氏模量" << endl << endl;

	cout << green;
	cout << "第四章 电磁学实验" << endl;
	cout << "4.1 PN结正向电压温度特性研究" << endl;
	cout << "4.3 惠斯登电桥测电阻" << endl;
	cout << "4.4 非平衡电桥电压输出特性研究" << endl;
	cout << "4.6 模拟示波器的使用" << endl << endl;

	cout << yellow;
	cout << "第五章 光学实验" << endl;
	cout << "5.2 偏振光特性研究" << endl;
	cout << "5.3 光的等厚干涉现象" << endl;
	cout << "5.4 光的衍射" << endl;
	cout << "5.5 分光计的调整与使用(仅支持弧度制)" << endl << endl;

	cout << red;
	cout << "第六章 综合性实验" << endl;
	cout << "6.9 物质旋光率的测量" << endl<<endl;

	cout << white;
	cout << "***********************其他功能***********************" << endl;
	cout << lightblue;
	cout << "1 相对误差E的计算" << endl;
	cout << "2 随机误差Sx的估算" << endl;
	cout << "3 异常数据的判别与剔除（推荐每次实验前先使用本功能）" << endl;
	cout << "4 A类不确定度的测量" << endl;
	cout << "5 B类不确定度的测量" << endl;
	cout << "6 合成标准不确定度u" << endl;
	cout << "7 最小二乘法拟合直线" << endl;
	cout << "8 逐差法处理数据" << endl;
	cout << "9 角度制转换弧度制（处理实验5.5之前请先使用此功能）" << endl<<endl;

	cout << white;
	cout << "*****************开发者：qw & 代号007*****************" << endl;
	cout << blue;
	cout << "0 获取<实验数据生成>功能！" << endl<<endl;
	cout << white;

K:
	cout << "输入章节号，开始实验数据处理！" << endl;
	double go;
	cin >> go;

	if (go == 666666)
		{
		D:
			system("cls");

			cout << "提供随机生成实验数据的实验有：" << endl<<endl;
			cout << lightblue;
			cout << "第三章 力学与热学实验" << endl;
			cout << "3.2 液体粘滞系数的测量及其温度特性研究" << endl;
			cout << "3.4 弯曲法测定杨氏模量" << endl << endl;
			cout << yellow;
			cout << "第四章 电磁学实验" << endl;
			cout << "4.1 PN结正向电压温度特性研究" << endl;
			cout << "4.3 惠斯登电桥测电阻" << endl;
			cout << "4.4 非平衡电桥电压输出特性研究" << endl;
			cout << "4.6 模拟示波器的使用" << endl << endl;
			cout << purple;
			cout << "第五章 光学实验" << endl;
			cout << "5.3 光的等厚干涉现象" << endl;
			cout << "5.4 光的衍射" << endl<<endl;
			cout << green;
			cout << "第六章 综合性实验" << endl;
			cout << "6.9 物质旋光率的测量" << endl << endl;
			cout << blue;
			cout << "0 返回主菜单" << endl<<endl;
		E:
			cout << white;
			cout << "输入章节号，随机生成实验数据！" << endl;

			double go1;
			cin >> go1;
			
			if (go1 == 3.2) { system("cls"); C3_2.randdata(); C3_2.print(); }
			else if (go1 == 3.4) { system("cls"); C3_4.randdata(); C3_4.print(); }
			else if (go1 == 4.1) { system("cls"); C4_1.randdata(); C4_1.print(); }
			else if (go1 == 4.3) { system("cls"); C4_3.randdata(); C4_3.print(); }
			else if (go1 == 4.4) { system("cls"); C4_4.randdata(); C4_4.print(); }
			else if (go1 == 4.6) { system("cls"); C4_6.randdata(); C4_6.print(); }
			else if (go1 == 5.3) { system("cls"); C5_3.randdata(); C5_3.print(); }
			else if (go1 == 5.4) { system("cls"); C5_4.randdata(); }
			else if (go1 == 6.9) { system("cls"); C6_9.randdata(); C6_9.print(); }
			else if (go1 == 0){ goto J; }
			else { cout << "ERROR：并没有这个章节！请重新输入。" << endl; goto E; }
			
			cout << "输入B返回生成数据菜单，或输入0返回主菜单，或输入其他键退出程序。" << endl;
			char back1;
			cin >> back1;
			if (back1 == 'b' || back1 == 'B'){ system("cls"); goto D; }
			if (back1 == '0'){ goto J; }
			else{ exit(0); }

			//C5_5 不提供

		}

	else if (go == 3.2) { system("cls"); C3_2.initialize(); C3_2.print(); }
	else if (go == 3.4)	{ system("cls"); C3_4.initialize(); C3_4.print(); }
	else if (go == 4.1) { system("cls"); C4_1.initialize(); C4_1.print(); }
	else if (go == 4.3) { system("cls"); C4_3.initialize(); C4_3.print(); }
	else if (go == 4.4) { system("cls"); C4_4.initialize(); C4_4.print(); }
	else if (go == 4.6) { system("cls"); C4_6.initialize(); C4_6.print(); }
	else if (go == 5.2) { system("cls"); print5_2(); }
	else if (go == 5.3) { system("cls"); C5_3.initialize(); C5_3.print(); }
	else if (go == 5.4) { system("cls"); C5_4.print(); }
	else if (go == 5.5) { system("cls"); C5_5.initialize(); C5_5.print(); }
	else if (go == 6.9) { system("cls"); C6_9.initialize(); C6_9.print(); }
	
	else if (go == 1)
	{
		system("cls");
		double measurex, truex;
		cout << "请输入真值：" << endl;
		cin >> truex;
		cout << "请输入测量值：" << endl;
		cin >> measurex;
		basic1(measurex, truex);
	}

	else if (go == 2)
	{
		system("cls");
		double * p2; int n2;
		cout << "请输入数据的个数n：" << endl;
		cin >> n2;
		p2 = new double[n2];
		cout << "请分别输入数据的值：" << endl;
		for (int i = 0; i < n2; i++)
		{
			cin >> p2[i];
		}
		basic2(p2, n2);
	}

	else if (go == 3)
	{
		system("cls");
		double * p3; int n3;
		cout << "请输入数据的个数n：" << endl;
		cin >> n3;
		p3 = new double[n3];
		cout << "请分别输入数据的值：" << endl;
		for (int i = 0; i < n3; i++)
		{
			cin >> p3[i];
		}
		basic3(p3, n3);
	}

	else if (go == 4)
	{
		system("cls");
		double * p4; int n4;
		cout << "请输入数据的个数n：" << endl;
		cin >> n4;
		p4 = new double[n4];
		cout << "请分别输入数据的值：" << endl;
		for (int i = 0; i < n4; i++)
		{
			cin >> p4[i];
		}
		basic4(p4, n4);
	}

	else if (go == 5)
	{
		system("cls");
		double deltayi5;
		cout << "请输入仪器的误差△仪：" << endl;
		cin >> deltayi5;
		basic5(deltayi5);
	}

	else if (go == 6)
	{
		system("cls");
		double * p6; int n6;
		cout << "请输入数据的个数n：" << endl;
		cin >> n6;
		p6 = new double[n6];
		cout << "请分别输入数据的值：" << endl;
		for (int i = 0; i < n6; i++)
		{
			cin >> p6[i];
		}
		double deltayi6;
		cout << "请输入仪器的误差△仪：" << endl;
		cin >> deltayi6;
		basic6(p6, n6,deltayi6);
	}

	else if (go == 7)
	{ 
		system("cls");
	J7:
		double *x7, *y7; int n7;
		cout << "请输入(x,y)的个数n：" << endl;
		cin >> n7;
		if (n7 == 1){ cout << "ERROR：点个数不能为1！" << endl; goto J7; }
		else
		{
			x7 = new double[n7];
			y7 = new double[n7];
			cout << "请按一定顺序输入各点的横坐标x：" << endl;
			for (int i = 0; i < n7; i++)
			{
				cin >> x7[i];
			}
			cout << "请按一定顺序输入各点的纵坐标y：" << endl;
			for (int i = 0; i < n7; i++)
			{
				cin >> y7[i];
			}
			basic7(x7, y7, n7);
		}
	}

	else if (go == 8)
	{
		system("cls");
		double * p8;int n8;
		cout << "请输入数据的个数n：" << endl;
		cin >> n8;
		p8 = new double[n8];
		cout << "请分别输入数据的值：" << endl;
		for (int i = 0; i < n8; i++)
		{
			cin >> p8[i];
		}
		basic8(p8, n8);
	}

	else if (go == 9)
	{
		system("cls");
		basic9();
	}

	else if (go == 0){ system("cls"); code(); }

	else { cout << red<<"ERROR：并没有这个章节！请重新输入。" <<white<< endl; goto K; }

	cout << "输入B返回主菜单，或输入其他键退出程序。" << endl;
	char back;
	cin >> back;
	if (back == 'b' || back == 'B'){ system("cls"); goto J; }
	else { exit(0); }
	system("pause");
}

