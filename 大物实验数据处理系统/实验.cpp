/*Ŀ¼��

������ ��ѧ����ѧʵ��
3.2 Һ��ճ��ϵ���Ĳ��������¶������о�	�̲������
3.4 �������ⶨ����ģ��					�̲������

������ ���ѧʵ��
4.1 PN�������ѹ�¶������о�			�̲������
4.2 �õ�����ģ�⾲�糡���¶ȳ�			��
4.3 ��˹�ǵ��Ų����					�̲������	
4.4 ��ƽ����ŵ�ѹ��������о�			�̲������
4.6 ģ��ʾ������ʹ��					��
4.7 ����ʾ������ʹ��					��

������ ��ѧʵ��
5.2 ƫ��������о�						�̲������
5.3 ��ĵȺ��������					�̲������
5.4 �������							�̲������
5.5 �ֹ�Ƶĵ�����ʹ��					��

������ �ۺ���ʵ��
6.9 ���������ʵĲ���					�̲������
*/

#include <iostream>
#include <cmath>
#include "�������ݴ���.h"
#include <windows.h>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>
#include "��ɫ.h"
using namespace std;

//3.2 Һ��ճ��ϵ���Ĳ��������¶������о�
class Class3_2
{
	double h, D, d, rho, rho0, g, *T, **t, *avet, *v, *eta;//��->eta
	int nT;
public:
	void initialize()
	{
		double K = 2.4;
		cout << "������С������ľ���h(��λ��m)(Ĭ��Ϊ0.15)��" << endl;
		cin >> h;
		cout << "��ֱ�����С����ܶȦ���Һ����ܶȦ�0/��L(��λ��kg/m^3)(Ĭ��Ϊ7800��950)��" << endl;
		cin >> rho >> rho0;
		cout << "��ֱ�����ԲͲ���ھ�D��С���ֱ��d(��λ��m)(Ĭ��Ϊ0.02��0.001)��" << endl;
		cin >> D >> d;
		cout << "�������������ٶ�g(��λm/s^2)(Ĭ��Ϊ9.8)" << endl;
		cin >> g;
		cout << "�����벻ͬ�¶Ȼ����ĸ���(Ĭ��Ϊ3)��" << endl;
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

		cout << "���С���������¶ȵ���ֵ(��λ����C)��" << endl;
		for (int i = 0; i < nT; i++)
		{
			cin >> T[i];
		}
		for (int i = 0; i < nT; i++)
		{
			cout << "������¶�T=" << T[i] << "��Cʱ��5��ʱ�����ֵt��" << endl;
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
		cout << "�¶�\\���\t1\t2\t3\t4\t5\tƽ��ֵt\tv(m/s)\t��" << endl;
		for (int i = 0; i < nT; i++)
		{
			cout << T[i] << "\t\t" << t[i][0] << "\t" << t[i][1] << "\t" << t[i][2] << "\t" << t[i][3] << "\t" << t[i][4] << "\t" << avet[i] << "\t" << v[i] << "\t" << eta[i] << endl;
		}
		cout << "�����Цǵļ��㹫ʽΪ��=����-��0��*g*d^2/(18*(1+2.4d/D)*V)������λ��Pa��" << endl<<endl<<white;
	}
	void randdata()
	{
		double K = 2.4;
		cout << "С������ľ���h=0.15m��" << endl;
		h=0.15;
		cout << "С����ܶȦ���Һ����ܶȦ�0/��L�ֱ�Ϊ7800��950 kg/m^3����" << endl;
		rho=7800;rho0=950;
		cout << "ԲͲ���ھ�D��С���ֱ��dΪ0.02m��0.001m��" << endl;
		D=0.02;d=0.001;
		cout << "�������ٶ�g=9.8m/s^2��" << endl<<endl;
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

//3.4 �������ⶨ����ģ��
class Class3_4
{
	double h[6], Utie[6], Utong[8], d, avea, aveb, ud, ua, ub;
public:
	void initialize()
	{
		//����
		cout << "�������������΢������h��m��0g��100gʱ������λ��mm����" << endl;
		for (int i = 0; i < 6; i++)
		{
			cin >> h[i];
		}
		cout << "����������ĵ�ѹֵ����U��m��0g��100gʱ������λ��V����" << endl;
		for (int i = 0; i < 6; i++)
		{
			cin >> Utie[i];
		}

		//��ͭ��
		cout << "�������ͭ��ĵ�ѹֵ����U��m��0g��70gʱ������λ��V����" << endl;
		for (int i = 0; i < 8; i++)
		{
			cin >> Utong[i];
		}

		//����a�Ĳ�ȷ����
		int na;//naΪ����
		cout << "ʵ������û�ͭ�岻ͬ��λ�ĺ��a�����ݹ��м�����" << endl;
		cin >> na;
		if (na == 1)
		{
			cout << "�������ͭ����a����λ��mm����" << endl;
			double a;
			cin >> a;
			avea = a;
			ua = 0;
			cout << "����ֻ��һ�����ݣ��޷�������ȷ���ȣ�Ĭ�ϲ�ȷ����ua=0��" << endl;
		}
		else
		{
			double * a = new double[na];
			double totala = 0;
			cout << "��ֱ������ͭ����a����λ��mm��:";
			for (int i = 0; i < na; i++)
			{
				cin >> a[i];
			}
			for (int i = 0; i < na; i++)
			{
				totala += a[i];
			}
			avea = totala / na;//���ƽ��ֵavea
			ua = 0;
			for (int i = 0; i < na; i++)
			{
				ua += pow(a[i] - avea, 2);
			}
			ua /= na*(na - 1);
			ua = sqrt(ua);
		}

		//����b�Ĳ�ȷ����
		int nb;//nbΪ����
		cout << "ʵ������û�ͭ�岻ͬ��λ�Ŀ��b�����ݹ��м�����" << endl;
		cin >> nb;
		if (nb == 1)
		{
			cout << "�������ͭ����b����λ��mm����" << endl;
			double b;
			cin >> b;
			aveb = b;
			ub = 0;
			cout << "����ֻ��һ�����ݣ��޷�������ȷ���ȣ�Ĭ�ϲ�ȷ����ub=0��" << endl;
		}
		else
		{
			double * b = new double[nb];
			double totalb=0;
			cout << "��ֱ������ͭ����b����λ��mm��:";
			for (int i = 0; i < nb; i++)
			{
				cin >> b[i];
			}
			for (int i = 0; i < nb; i++)
			{
				totalb += b[i];
			}
			aveb = totalb / nb;//���ƽ��ֵaveb
			ub = 0;
			for (int i = 0; i < nb; i++)
			{
				ub += pow(b[i] - aveb, 2);
			}
			ub /= nb*(nb - 1);
			ub = sqrt(ub);
		}

		//����d�Ĳ�ȷ����
		cout << "���������������ڼ�ľ���d(��λ��mm��(d�Ĳ�ȷ����udĬ��Ϊ0)��" << endl;
		cin >> d;
		ud = 0;
		char changeud;
	J:
		cout << "�Ƿ����d�Ĳ�ȷ���ȣ��������������N����(Y/N)" << endl;
		cin >> changeud;
		if (changeud == 'y' || changeud == 'Y'){ cout << "���������Ĳ�ȷ����ud��" << endl; cin >> ud; }
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
		//��б��a�ͽؾ�b
		a_ = (avexy_ - avex_*avey_) / (avex2_ - (avex_*avex_));
		b_ = avey_ - a_*avex_;
		//�����ϵ��R������y��x�����Թ�ϵ
		Lxy_ = avexy_ - avex_*avey_;
		Lxx_ = avex2_ - avex_*avex_;
		Lyy_ = avey2_ - avey_*avey_;
		R_ = Lxy_ / sqrt(Lxx_*Lyy_);
		//���x,y�����б�
		cout << "���i\txi\t\tyi\t\txi^2\t\tyi^2\t\txiyi" << endl;
		for (int i = 0; i < 6; i++)
		{
			cout << i + 1 << "\t" << h[i] << "\t\t" << Utie[i] << "\t\t" << h[i] * h[i] << "\t\t" << Utie[i] * Utie[i] << "\t\t" << h[i] * Utie[i] << endl;
		}
		cout << "��\t" << avex_*6 << "\t\t" << avey_*6 << "\t\t" << avex2_*6 << "\t\t" << avey2_*6 << "\t\t" << avexy_*6 << endl;
		cout << "ƽ��ֵ\t" << avex_ << "\t\t" << avey_ << "\t\t" << avex2_ << "\t\t" << avey2_ << "\t\t" << avexy_ << endl;
		//�����ʽ
		cout << "�ٸ�����С���˷���ʽ��б�ʺͽؾࣺ" << endl;
		cout << "б��a=" << a_ << endl;
		cout << "�ؾ�b=" << b_ << endl;
		cout << "�������ϵ��������y��x�����Թ�ϵ��" << endl;
		cout << "Lxy=" << Lxy_ << endl;
		cout << "Lxx=" << Lxx_ << endl;
		cout << "Lyy=" << Lyy_ << endl;
		cout << "���ϵ��R=Lxy / sqrt(Lxx*Lyy)=" << R_ << endl;
		cout << "��������õĻع�ֱ�ߵ�б�ʺͽؾ࣬�ûع鷽�̣�y =" << a_ << "x+" << b_ << endl<<endl;
		double K;
		K = fabs(a_);
		cout <<lightblue<< "������������������K = " << K << endl;
		cout << "���ϵ��R = " << R_ << endl << endl<<white;
		

		//������
		cout << "n\t" << "Ui/mV\t\t" << "Ui+4/mV\t\t" << "��Ui/mV\t\t" << "��hi/mm=��Ui/K" << endl;
		for (int i = 0; i < 4; i++)
		{
			cout << i + 1 << "\t" << Utong[i] << "\t\t" << Utong[i + 4] << "\t\t" << Utong[i + 4] - Utong[i] << "\t\t" << fabs((Utong[i + 4] - Utong[i]) / K )<< endl;
		}
		cout << endl;

		//�����h�ķ���sigmah������avehΪƽ��ֵ��totalhΪ��ֵ
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

		//��������ģ��Y(��λ��N/mm^2��
		double Y, uY;
		Y = d*d*d * 0.04 * 9.8 / (4 * avea*avea*avea*aveb*aveh);
		uY = Y*sqrt(9 * (ud / d)* (ud / d) + 9 * (ua / avea)*(ua / avea) + (ub / aveb)*(ub / aveb) + (sigmah / aveh)*(sigmah / aveh));
		cout <<lightblue<< "a�Ĳ�ȷ����ua = " << ua << endl;
		cout << "b�Ĳ�ȷ����ua = " << ub << endl;
		cout << "d�Ĳ�ȷ����ud = " << ud << endl;
		cout << "��ȷ���������� uY/Y = " << uY / Y << endl;
		cout << "����ģ�� Y = " << Y << "�� " << uY << "����λ��N/mm^2��" << endl;
		cout << "�� " << Y * 1000 * 1000 << " �� " << uY * 1000 * 1000 << "����λ��N/m^2��" << endl<<endl<<white;
	}
	void randdata()
	{
		srand(time(0));
		//����
		cout << "�������΢������h��m��0g��100gʱ������λ��mm����" << endl;
		h[0] = 5 + rand() % 2000 * 0.001;
		for (int i = 1; i < 6; i++)
		{
			h[i] = h[i - 1] + 0.3 + rand() % 500 * 0.001;
		}
		for (int i = 0; i < 6; i++)
		{
			cout << h[i]<<" ";
		}
		cout <<endl<< "����ĵ�ѹֵ����U��m��0g��100gʱ������λ��V����" << endl;
		Utie[0] = rand() % 400 * 0.1;
		for (int i = 1; i < 6; i++)
		{
			Utie[i] = Utie[i - 1] - 6.5 + rand() % 10 * 0.1;
		}
		for (int i = 0; i < 6; i++)
		{
			cout<< Utie[i]<<" ";
		}

		//��ͭ��
		cout <<endl<< "��ͭ��ĵ�ѹֵ����U��m��0g��70gʱ������λ��V����" << endl;
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

		//����a�Ĳ�ȷ����
		double * a = new double[5];
		double totala = 0;
		cout << "��ͭ����a�ֱ�Ϊ����λ��mm��:";
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
		avea = totala / 5;//���ƽ��ֵavea
		ua = 0;
		for (int i = 0; i < 5; i++)
		{
			ua += pow(a[i] - avea, 2);
		}
		ua /= 5*(5 - 1);
		ua = sqrt(ua);
	

		//����b�Ĳ�ȷ����
		double * b = new double[5];
		double totalb = 0;
		cout << "��ͭ����b�ֱ�Ϊ����λ��mm��:";
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
		aveb = totalb / 5;//���ƽ��ֵavea
		ub = 0;
		for (int i = 0; i < 5; i++)
		{
			ub += pow(b[i] - aveb, 2);
		}
		ub /= 5 * (5 - 1);
		ub = sqrt(ub);

		//����d�Ĳ�ȷ����
		cout << "���������ڼ�ľ���d(��λ��mm��(d�Ĳ�ȷ����udĬ��Ϊ0)Ϊ��";
		d=220+rand()%20;
		cout << d << endl;
		ud = 0;

	}
};

//4.1 PN�������ѹ�¶������о�
class Class4_1
{
	double S, Vg0, Vf, tr, Eg0, *V, *t; int n;
public:
	void initialize()
	{
		cout << "����������tr��" << endl;
		cin >> tr;
		cout << "�����������µĵ�ѹֵVf����λ��mV����" << endl;
		cin >> Vf;
		J:
		cout << "������t���V����λ��mV�����ݵ�����n��" << endl;
		cin >> n;
		if (n == 1){ cout << "ERROR��������������Ϊ1��" << endl; goto J; }
		t = new double[n];
		V = new double[n];
		for (int i = 0; i < n; i++)
		{
			cout << "�������" << i + 1 << "�����ݵ�t�͡�V����λ��mV����" << endl;
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
		//��б��a�ͽؾ�b
		a = (avexy - avex*avey) / (avex2 - (avex*avex));
		b = avey - a*avex;
		//�����ϵ��R������y��x�����Թ�ϵ
		Lxy = avexy - avex*avey;
		Lxx = avex2 - avex*avex;
		Lyy = avey2 - avey*avey;
		R = Lxy / sqrt(Lxx*Lyy);
		//���x,y�����б�
		cout << "���i\txi\t\tyi\t\txi^2\t\tyi^2\t\txiyi" << endl;
		for (int i = 0; i < n; i++)
		{
			cout << i + 1 << "\t" << t[i] << "\t\t" << V[i] << "\t\t" << t[i] * t[i] << "\t\t" << V[i] * V[i] << "\t\t" << t[i] * V[i] << endl;
		}
		cout << "��\t" << avex*n << "\t\t" << avey*n << "\t\t" << avex2*n << "\t\t" << avey2*n << "\t\t" << avexy*n << endl;
		cout << "ƽ��ֵ\t" << avex << "\t\t" << avey << "\t\t" << avex2 << "\t\t" << avey2 << "\t\t" << avexy << endl;
		//�����ʽ
		cout << "�ٸ�����С���˷���ʽ��б�ʺͽؾࣺ" << endl;
		cout << "б��a=" << a << endl;
		cout << "�ؾ�b=" << b << endl;
		cout << "�������ϵ��������y��x�����Թ�ϵ��" << endl;
		cout << "Lxy=" << Lxy << endl;
		cout << "Lxx=" << Lxx << endl;
		cout << "Lyy=" << Lyy << endl;
		cout << "���ϵ��R=Lxy / sqrt(Lxx*Lyy)=" << R << endl;
		cout << "��������õĻع�ֱ�ߵ�б�ʺͽؾ࣬�ûع鷽�̣�y =" << a << "x+" << b << endl;

		S = -a;
		cout << endl <<yellow<< "PN���¶ȴ�����������S = " << S << " mV/��C" << endl;
		Vf = Vf / 1000.0;
		for (int i = 0; i < n; i++)
		{
			V[i] = V[i] / 1000.0;
		}
		Vg0 = Vf + S/1000.0*(273.2 + tr);
		cout << endl << "����ѧ�¶�0KʱPN����ϵĵ�������۴����ĵ��Ʋ�Vg(0)Ϊ��" << endl << "Vg(0) = Vf + S * (273.2 + tr) = " << Vg0 <<"eV"<< endl;
		Eg0 = Vg0;
		cout << endl << "PN����ϵĽ������Eg(0) = " << Eg0 <<" eV"<< endl;
		cout << "Eg(0)�빫��ֵ1.21eV��";
		basic1(Eg0, 1.21);
		cout << endl<<white;
	}
	void randdata()
	{
		srand(time(0));
		tr=25.6+rand()%10*0.1;
		cout << "����tr=" <<tr<< endl;
		Vf=610+rand()%11;
		cout << "�����µĵ�ѹֵVf="<<Vf<<"��mV��" << endl;
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

		cout<<"��V/mV\t";
		for(int i=0;i<6;i++)
		{
			cout<<V[i]<<"\t";
		}
		cout<<endl<<"T/��C\t";
		for(int i=0;i<6;i++)
		{
			cout<<t[i]<<"\t";
		}
		cout<<endl;

		cout<<"��V/mV\t";
		for(int i=6;i<11;i++)
		{
			cout<<V[i]<<"\t";
		}
		cout<<endl<<"T/��C\t";
		for(int i=6;i<11;i++)
		{
			cout<<t[i]<<"\t";
		}
		cout<<endl;
	}
};

//4.3 ��˹�ǵ��Ų����
class Class4_3
{
	double R0a, R0a1, R0a2, R0b, R0b1, R0b2, R0c, R0c1, R0c2, R0d, R0d1, R0d2;

public:
	void initialize()
	{
		cout << "��ֱ�����������Ϊ51��ʱ�Ĳ���ֵR0����ƫ����ƫ��ĵ���R0'��" << endl;
		cin >> R0a >> R0a1 >> R0a2;
		cout << "��ֱ�����������Ϊ220��ʱ�Ĳ���ֵR0����ƫ����ƫ��ĵ���R0'��" << endl;
		cin >> R0b >> R0b1 >> R0b2;
		cout << "��ֱ�����������Ϊ1500��ʱ�Ĳ���ֵR0����ƫ����ƫ��ĵ���R0'��" << endl;
		cin >> R0c >> R0c1 >> R0c2;
		cout << "��ֱ�����������Ϊ22000��ʱ�Ĳ���ֵR0����ƫ����ƫ��ĵ���R0'��" << endl;
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

		cout << "�������\tRx1\t\tRx2\t\tRx3\t\tRx4" << endl;
		cout << "������ֵ/��\t51��\t\t220��\t\t1500��\t\t22000��" << endl;
		cout << "����k\t\t0.01\t\t0.1\t\t1\t\t10" << endl;
		cout << "׼ȷ�ȵȼ���\t0.5\t\t0.3\t\t0.2\t\t1" << endl;
		cout << "R0(R3)/��\t" << R0a << "\t\t" << R0b << "\t\t" << R0c << "\t\t" << R0d << endl;
		cout << "ƽ���Gƫ��2��\t ��ƫ\t ��ƫ\t ��ƫ\t ��ƫ\t ��ƫ\t ��ƫ\t ��ƫ\t ��ƫ" << endl;
		cout << "��ƫ0.1��A��\t(��ƫ)\t(��ƫ)\t(��ƫ)\t(��ƫ)\t(��ƫ)\t(��ƫ)\t(��ƫ)\t(��ƫ)" << endl;
		cout << "R0'(R3')/��\t" << R0a1 << "\t" << R0a2 << "\t" << R0b1 << "\t" << R0b2 << "\t" << R0c1 << "\t" << R0c2 << "\t" << R0d1 << "\t" << R0d2 << endl;
		cout << "��R0=|R0-R0'|\t" << fabs(R0a1 - R0a) << "\t" << fabs(R0a2 - R0a) << "\t" << fabs(R0b1 - R0b) << "\t" << fabs(R0b2 - R0b) << "\t" << fabs(R0c1 - R0c) << "\t" << fabs(R0c2 - R0c) << "\t" << fabs(R0d1 - R0d) << "\t" << fabs(R0d2 - R0d) << endl;
		cout << "��B/��\t\t" << 0.01*fabs(R0a1 - R0a) / 1.732 << "\t" << 0.01*fabs(R0a2 - R0a) / 1.732 << "\t" << 0.1*fabs(R0b1 - R0b) / 1.732 << "\t" << 0.1*fabs(R0b2 - R0b) / 1.732 << "\t" << fabs(R0c1 - R0c) / 1.732 << "\t" << fabs(R0c2 - R0c) / 1.732 << "\t" << 10 * fabs(R0d1 - R0d) / 1.732 << "\t" << 10 * fabs(R0d2 - R0d) / 1.732 << endl;
		cout << "��B�ľ�ֵ/��\t" << (0.01*fabs(R0a1 - R0a) / 1.732 + 0.01*fabs(R0a2 - R0a) / 1.732) / 2.0 << "\t\t" << (0.1*fabs(R0b1 - R0b) / 1.732 + 0.1*fabs(R0b2 - R0b) / 1.732) / 2.0 << "\t\t" << (fabs(R0c1 - R0c) / 1.732 + fabs(R0c2 - R0c) / 1.732) / 2.0 << "\t\t" << (10.0*fabs(R0d1 - R0d) / 1.732 + 10 * fabs(R0d2 - R0d) / 1.732) / 2.0 << endl;
		cout << "������kR0/��\t" << 0.01*R0a << "\t\t" << 0.1*R0b << "\t\t" << R0c << "\t\t" << 10.0 * R0d << endl;
		cout << "|Elim|/��\t" << Elima << "\t\t" << Elimb << "\t\t" << Elimc << "\t\t" << Elimd << endl;
		cout << "��R/��\t\t" << sqrt(Elima*Elima + deltaRa*deltaRa) << "\t\t" << sqrt(Elimb*Elimb + deltaRb*deltaRb) << "\t\t" << sqrt(Elimc*Elimc + deltaRc*deltaRc) << "\t\t" << sqrt(Elimd*Elimd + deltaRd*deltaRd) << endl;
		cout << "Rx=kR0����R/��\t" << 0.01*R0a << "��" << sqrt(Elima*Elima + deltaRa*deltaRa) << "\t" << 0.1*R0b << "��" << sqrt(Elimb*Elimb + deltaRb*deltaRb) << "\t" << R0c << "��" << sqrt(Elimc*Elimc + deltaRc*deltaRc) << "\t" << 10.0 * R0d << "��" << sqrt(Elimd*Elimd + deltaRd*deltaRd) << endl;
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

//4.4 ��ƽ����ŵ�ѹ��������о�
class Class4_4
{	
	double *deltaR, *R, *UAB, *T, k; int n, Tjiange;
public:
	void initialize()
	{
		cout << "�������ƽ���ѹ��������n��Ĭ��Ϊ8����" << endl;
		cin >> n;
		UAB = new double[n + 1];
		T = new double[n + 1];
		R = new double[n + 1];
		deltaR = new double[n + 1];
		deltaR[0] = 0; UAB[0] = 0;
		cout << "�����������¶�T0��" << endl;
		cin >> T[0];
		cout << "����������ʱͭ������ֵRX0��" << endl;
		cin >> R[0];
		k = 500.0 / R[0];
		cout << "�������¼��һ����ƽ���ѹʱ���¶�T1��" << endl;
		cin >> T[1];
		cout << "������ÿ�β����¶ȼ����Ĭ��Ϊ5��C����" << endl;
		cin >> Tjiange;
		for (int i = 1; i < n; i++)
		{
			T[i + 1] = T[1] + i*Tjiange;
		}
		cout << "�����������ƽ���ѹUAB����ֵ��" << endl;
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
		cout << "T/��C\t\t��ƽ���ѹUAB/mV\tͭ����仯����R/��\tͭ����R/��" << endl;
		for (int i = 1; i < n + 1; i++)
		{
			cout << T[i] << "\t\t" << UAB[i] << "\t\t\t" << deltaR[i] << "\t\t\t" << R[i] << endl;
		}
		cout << white;
		cout << endl << "��������С���˷����ֱ��R(T)-T��" << endl;

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
		//��б��a�ͽؾ�b
		a = (avexy - avex*avey) / (avex2 - (avex*avex));
		b = avey - a*avex;
		//�����ϵ��R������y��x�����Թ�ϵ
		Lxy = avexy - avex*avey;
		Lxx = avex2 - avex*avex;
		Lyy = avey2 - avey*avey;
		R_ = Lxy / sqrt(Lxx*Lyy);
		//���x,y�����б�
		cout << "���i\txi\t\tyi\t\txi^2\t\tyi^2\t\txiyi" << endl;
		for (int i = 0; i < n+1; i++)
		{
			cout << i + 1 << "\t" << T[i] << "\t\t" << R[i] << "\t\t" << T[i] * T[i] << "\t\t" << R[i] * R[i] << "\t\t" << T[i] * R[i] << endl;
		}
		cout << "��\t" << avex*(n + 1) << "\t\t" << avey*(n + 1) << "\t\t" << avex2*(n + 1) << "\t\t" << avey2*(n + 1) << "\t\t" << avexy*(n + 1) << endl;
		cout << "ƽ��ֵ\t" << avex << "\t\t" << avey << "\t\t" << avex2 << "\t\t" << avey2 << "\t\t" << avexy << endl;
		//�����ʽ
		cout << "�ٸ�����С���˷���ʽ��б�ʺͽؾࣺ" << endl;
		cout << "б��a=" << a << endl;
		cout << "�ؾ�b=" << b << endl;
		cout << "�������ϵ��������y��x�����Թ�ϵ��" << endl;
		cout << "Lxy=" << Lxy << endl;
		cout << "Lxx=" << Lxx << endl;
		cout << "Lyy=" << Lyy << endl;
		cout << "���ϵ��R=Lxy / sqrt(Lxx*Lyy)=" << R_ << endl;
		cout << "��������õĻع�ֱ�ߵ�б�ʺͽؾ࣬�ûع鷽�̣�y =" << a << "x+" << b << endl;

		cout << yellow << endl << "0��Cʱ�ĵ���ֵR0=" << b << "�������¶�ϵ����=��R/R0��T=" << a / b << endl;
		cout << "ͭ�������¶ȵĹ�ϵ���ʽ��R = " << a << "T + " << b << endl;
		cout << "ȡ����T0ʱͭ����������ֵ�Ƚϣ�";
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
		cout << "�����¶�T0Ϊ"<<T[0]<<"�ȡ�" << endl;
		R[0]=55+rand()%200*0.01;
		cout << "����ʱͭ������ֵRX0Ϊ"<<R[0]<<"��" << endl;
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

//4.6 ģ��ʾ������ʹ��
class Class4_6
{
	double A[8], K[8], VPP[8], D[8], S[8], f[8];
public:
	void initialize()
	{
		cout << "�밴˳������8������A/DIV��" << endl;
		for (int i = 0; i < 8;i++)
		{
			cin >> A[i];
		}
		cout << "�밴˳������8������K/(V/DIV)����λ��V����" << endl;
		for (int i = 0; i < 8; i++)
		{
			cin >> K[i];
		}
		cout << "�밴˳������8������D/DIV��" << endl;
		for (int i = 0; i < 8; i++)
		{
			cin >> D[i];
		}
		cout << "�밴˳������8������S/(S/DIV)"<<red<<"����λ���밡��)��" <<white<< endl;
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
		cout << "��Ŀ\\�ź�����\tU1\tU2\tU3\tU4\tU5\tU6\tU7\tU8"<<endl;
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
		cout << red << "Ϊ�����ؿ͹���ʵ����ʵ��ֻ�ṩһ����ʵ���ݡ�" << endl << endl << yellow ;
		A[0] = 3.5; A[1] = 1.8; A[2] = 4.4; A[3] = 2.6; A[4] = 3; A[5] = 5.8; A[6] = 5.2; A[7] = 2.4;
		K[0] = 5; K[1] = 5; K[2] = 2; K[3] = 2; K[4] = 2; K[5] = 2; K[6] = 2; K[7] = 2;
		D[0] = 4; D[1] = 5; D[2] = 4; D[3] = 5; D[4] = 5; D[5] = 5; D[6] = 5; D[7] = 2;
		S[0] = 0.005; S[1] = 0.002; S[2] = 0.005; S[3] = 0.0002; S[4] = 0.00002; S[5] = 0.0002; S[6] = 0.00002; S[7] = 0.0005;
		cout << white;
	}
};

//5.2 ƫ��������о�
void print5_2()
{
	cout << "��ʵ�鲻�漰���ݴ�������ʵ����������ο���" << endl;
	cout << "1/4��ƬCת���Ƕ�\tAת��360�������\t��1/4��ƬC�����Ĺ��ƫ������"<<endl;
	cout << "\t0��\t\t����-��-����-��-����\t\t��ƫ���" << endl;
	cout << "\t15��\t\t��-��-��-��-��\t\t\t��Բƫ���" << endl;
	cout << "\t30��\t\t��-��-��-��-��\t\t\t��Բƫ���" << endl;
	cout << "\t45��\t\t���Ȳ���\t\t\tԲƫ���" << endl;
	cout << "\t60��\t\t��-��-��-��-��\t\t\t��Բƫ���" << endl;
	cout << "\t75��\t\t��-��-��-��-��\t\t\t��Բƫ���" << endl;
	cout << "\t90��\t\t����-��-����-��-����\t\t��ƫ���" << endl;
}

//5.3 ��ĵȺ��������
class Class5_3
{
	double *Dm, *Dn, *pingfangcha, *R, avepingfangcha , uR , aveR ; int maxm, minn, hangshu;//ƽ����pingfangcha=Dm^2-Dn^2,maxmΪ��󰵻�����,minnΪ��С
	double *zuo, *you;
public:
	void initialize()
	{
		avepingfangcha = 0; uR = 0; aveR = 0;
	J:
		cout << "���������İ�������m��Ĭ��30����" << endl;
		cin >> maxm;
		cout << "��������С�İ�������n��Ĭ��19����" << endl;
		cin >> minn;
		if ((maxm - minn) % 2 == 0){ cout << "ERROR����ȷ��������������Ϊż����" << endl; goto J; }
		hangshu = (maxm - minn + 1) / 2;
		zuo = new double[hangshu * 2];
		you = new double[hangshu * 2];
		Dm = new double[hangshu];
		Dn = new double[hangshu];
		pingfangcha = new double[hangshu];
		R = new double[hangshu];
		cout << "�밴���������Ӵ�С˳�����밵��λ��Ϊ��ʱ�����ݣ�"<< endl;
		for (int i = 0; i < hangshu*2; i++)
		{
			cin >> zuo[i];
		}
		cout << "�밴���������Ӵ�С˳�����밵��λ��Ϊ��ʱ�����ݣ�" << endl;
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
		cout << endl << "�ƹⲨ����=589.3nm��������m-n=" << hangshu << "����λmm��" << endl;
		cout << "��������m\tDm\t��������n\tDn\tDm^2-Dn^2/mm^2\tR" << endl;
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
		cout << "Dm^2-Dn^2��ƽ��ֵΪ��" << avepingfangcha << "mm^2" << endl;
		cout << "�뾶R��ƽ��ֵaverageR = " << aveR << " (mm)" << endl;
		cout << "�뾶R�Ĳ�ȷ����uR = " << uR << " (mm)" << endl;
		cout << "ţ�ٻ����ʰ뾶ΪR = averageR��uR = " << aveR << " �� " << uR << " (mm)" << endl;
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
		cout << "���������Ӵ�С˳�����밵��λ��Ϊ��ʱ�����ݣ�" << endl;
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
		cout << "���������Ӵ�С˳�����밵��λ��Ϊ��ʱ�����ݣ�" << endl;
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

//5.4 �������
class Class5_4
{
	double I0, I1a, I1b, I2a, I2b;
public:
	void print()
	{
	J:
		cout << "����������Ǧ�=0ʱ��ǿֵI0��" << endl;
		cin >> I0;
		cout << "����������Ǧ�����sin��=��1.43��/aʱ��ǿֵ����������" << endl;
		cin >> I1a >> I1b;
		cout << "����������Ǧ�����sin��=��2.46��/aʱ��ǿֵ����������" << endl;
		cin >> I2a >> I2b;
		cout << "sin��=��1.43��/aʱ��ǿֵ��I0����Ϊ(����ֵ0.047)��" << I1a / I0 << "\t" << I1b / I0 << endl;
		cout << "sin��=��2.46��/aʱ��ǿֵ��I0����Ϊ(����ֵ0.017)��" << I2a / I0 << "\t" << I2b / I0 << endl;
	K:
		cout << "����һ�飿��Y/N��" << endl;
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
		cout<<"����ֵ\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<endl;
		cout<<"����\t"<<a/c<<"\t"<<b/c<<"\t"<<c/c<<"\t"<<d/c<<"\t"<<e/c<<endl;
		c=400+rand()%1800;
		a=c*(0.015+(rand()%15*0.001));
		b=c*(0.015+(rand()%15*0.001));
		d=c*(0.04+(rand()%20*0.001));
		e=c*(0.04+(rand()%20*0.001));
		cout<<"����ֵ\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<endl;
		cout<<"����\t"<<a/c<<"\t"<<b/c<<"\t"<<c/c<<"\t"<<d/c<<"\t"<<e/c<<endl;
		c=400+rand()%1800;
		a=c*(0.015+(rand()%15*0.001));
		b=c*(0.015+(rand()%15*0.001));
		d=c*(0.04+(rand()%20*0.001));
		e=c*(0.04+(rand()%20*0.001));
		cout<<"����ֵ\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<endl;
		cout<<"����\t"<<a/c<<"\t"<<b/c<<"\t"<<c/c<<"\t"<<d/c<<"\t"<<e/c<<endl;
		c=400+rand()%1800;
		a=c*(0.015+(rand()%15*0.001));
		b=c*(0.015+(rand()%15*0.001));
		d=c*(0.04+(rand()%20*0.001));
		e=c*(0.04+(rand()%20*0.001));
		cout<<"����ֵ\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<endl;
		cout<<"����\t"<<a/c<<"\t"<<b/c<<"\t"<<c/c<<"\t"<<d/c<<"\t"<<e/c<<endl;
		c=400+rand()%1800;
		a=c*(0.015+(rand()%15*0.001));
		b=c*(0.015+(rand()%15*0.001));
		d=c*(0.04+(rand()%20*0.001));
		e=c*(0.04+(rand()%20*0.001));
		cout<<"����ֵ\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<endl;
		cout<<"����\t"<<a/c<<"\t"<<b/c<<"\t"<<c/c<<"\t"<<d/c<<"\t"<<e/c<<endl;
		
		cout << white;
	}
};

//5.5 �ֹ�Ƶĵ�����ʹ��
class Class5_5
{
	double theta1[5], theta1_[5], theta2[5], theta2_[5], theta0[5], avetheta0, utheta0, n[5], aven, un, *fai, avefai, ufai;
	int nfai;

public:
	void initialize()
	{
		avetheta0 = 0; utheta0 = 0; avefai = 0; ufai = 0;
		//�⾵����fai�ļ��㼰��ȷ����
		cout << "����������⾵�Ķ��Ǧ���ֵ�ĸ�������Ϊ1����" << endl;
		cin >> nfai;
		if (nfai == 1)
		{
			cout << "�������⾵�Ķ��Ǧ���ֵ�������ƣ���" << endl;
			cin >> avefai;
			ufai = 0;
			cout << "�����붥�ǦյĲ�ȷ���ȣ�" << endl;
			cin >> ufai;
		}
		else
		{
			fai = new double[nfai];
			cout << "�������⾵�Ķ��Ǧ���ֵ�������ƣ���" << endl;
			for (int i = 0; i < nfai; i++)
			{
				cin >> fai[i];
			}
			for (int i = 0; i < nfai; i++)
			{
				avefai += fai[i];
			}
			avefai /= nfai;//���ƽ��ֵavefai
			for (int i = 0; i < nfai; i++)
			{
				ufai += pow(fai[i] - avefai, 2);
			}
			ufai /= nfai*(nfai - 1);
			ufai = sqrt(ufai);//fai�Ĳ�ȷ����ufai
			cout << "�յĲ�ȷ����u��=" << ufai << endl;
			cout << "�� = " << avefai << " �� " << ufai << endl;
		}


		//��������
		cout << "�밴˳�����������λ�ö�����1����1'�������λ�ö�����2����2'��" << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << "��������k=" << i + 1 << endl;
			cin >> theta1[i] >> theta1_[i] >> theta2[i] >> theta2_[i];
			theta0[i] = (fabs(theta1[i] - theta2[i]) + fabs(theta1_[i] - theta2_[i])) / 2;
			n[i] = sin(0.5*(avefai + theta0[i])) / sin(0.5*avefai);
		}
	}
	void print()
	{
		cout.precision(4);
		cout << purple;
		//������
		cout << "��������k\t�����λ�ö���\t\t�����λ�ö���\t\t��0\tn" << endl;
		cout << "\t\t��1\t��'1\t\t��2\t��'2" << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << "\t" << i + 1 << "\t" << theta1[i] << "\t" << theta1_[i] << "\t\t" << theta2[i] << "\t" << theta2_[i] << "\t\t" << theta0[i] << "\t" << n[i] << endl;
		}

		//theta0�ļ��㼰��ȷ����
		for (int i = 0; i < 5; i++)
		{
			avetheta0 += theta0[i];
		}
		avetheta0 /= 5;//���ƽ��ֵavetheta0
		for (int i = 0; i < 5; i++)
		{
			utheta0 += pow(theta0[i] - avetheta0, 2);
		}
		utheta0 /= 5*(5 - 1);
		utheta0 = sqrt(utheta0);//theta0�Ĳ�ȷ����utheta0;
		cout << "��0�Ĳ�ȷ����u��0=" << utheta0 << endl;
		cout << "��0 = " << avetheta0 << " �� " << utheta0 << endl;

		//�⾵��������
		aven = sin(0.5*(avefai + avetheta0)) / sin(0.5*avefai);
		cout << "�⾵��������n��ֵΪ" << aven << endl;

		//n�Ĳ�ȷ����
		double n_fai, n_theta;//ƫ��
		n_fai = 0.5*cos(0.5*(avefai + avetheta0))*sin(0.5*avefai) - 0.5*cos(0.5*avefai)*sin(0.5*(avefai + avetheta0)) / pow(sin(0.5*avefai), 2);
		n_theta = 0.5*cos(0.5*(avefai + avetheta0));
		un = sqrt(n_fai*n_fai*ufai*ufai + n_theta*n_theta*utheta0*utheta0);
		cout << "n�Ĳ�ȷ����un = " << un << endl;


		//������
		cout << "������n = " << aven << " �� " << un << endl;
		cout << white;

	}
};

//6.9 ���������ʵĲ���
class Class6_9
{
	double l1, l2, c, alpha1, alpha2, *phi1, *phi2, ave1, ave2;//phi->��ƫת����ת�Ƕ�,ave1��ave2Ϊphi�ľ�ֵ
	int n;//nΪ����phi�ĳ���
public:
	void initialize()
	{

		ave1 = 0; ave2 = 0;
		cout << "********��ʵ��ֻ�ṩ��Һ�����ʵĲ������ݴ���********" << endl;
		cout << "�������Թܳ���l1��l2����λ��mm����" << endl;
		cin >> l1 >> l2;
		cout << "��������ҺŨ��c��" << endl;
		cin >> c;
		cout << "������ÿ���Թ���ת�ǶȦյ����ݸ���n��" << endl;
		cin >> n;
		phi1 = new double[n];
		phi2 = new double[n];
		cout << "�������Թܳ���Ϊl1ʱ����ת�ǶȲ���ֵ����λ���㣩��" << endl;
		for (int i = 0; i < n; i++)
		{
			cin >> phi1[i];
			ave1 += phi1[i];
		}
		ave1 /= n;
		cout << "�������Թܳ���Ϊl2ʱ����ת�ǶȲ���ֵ����λ���㣩��" << endl;
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
		cout << "����Ϊl1���Թܼ���õ���������Ϊ����λ����/mm����" << alpha1 << endl;
		cout << "����Ϊl2���Թܼ���õ���������Ϊ����λ����/mm����" << alpha2 << endl;
		cout << white;

	}
	void randdata()
	{
		srand(time(0));
		l1 = 100; l2 = 200;
		cout << "�Թܳ���l1=100mm,l2=200mm" << endl;
		c = 0.1;
		cout << "��ҺŨ��c=0.1" << endl;
		ave1 = 0; ave2 = 0;
		cout << "ÿ���Թ���ת�ǶȦյ����ݸ���n=10" << endl;
		n = 10;
		phi1 = new double[n];
		phi2 = new double[n];
		cout << "l1�Թܵ���ת�ǶȲ���ֵ�ֱ�Ϊ��";
		for (int i = 0; i < n; i++)
		{
			phi1[i] = 4.4 + (rand() % 40)*0.01;
			ave1 += phi1[i];
			cout << phi1[i] << " ";
		}
		cout << endl;
		ave1 /= n;
		cout << "l2�Թܵ���ת�ǶȲ���ֵ�ֱ�Ϊ��";
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
	
	cout << "*************��ӭʹ�ô���ʵ�����ݴ���ϵͳ*************" << endl;

	cout << purple;
	cout << "������ ��ѧ����ѧʵ��" << endl;
	cout << "3.2 Һ��ճ��ϵ���Ĳ��������¶������о�" << endl;
	cout << "3.4 �������ⶨ����ģ��" << endl << endl;

	cout << green;
	cout << "������ ���ѧʵ��" << endl;
	cout << "4.1 PN�������ѹ�¶������о�" << endl;
	cout << "4.3 ��˹�ǵ��Ų����" << endl;
	cout << "4.4 ��ƽ����ŵ�ѹ��������о�" << endl;
	cout << "4.6 ģ��ʾ������ʹ��" << endl << endl;

	cout << yellow;
	cout << "������ ��ѧʵ��" << endl;
	cout << "5.2 ƫ��������о�" << endl;
	cout << "5.3 ��ĵȺ��������" << endl;
	cout << "5.4 �������" << endl;
	cout << "5.5 �ֹ�Ƶĵ�����ʹ��(��֧�ֻ�����)" << endl << endl;

	cout << red;
	cout << "������ �ۺ���ʵ��" << endl;
	cout << "6.9 ���������ʵĲ���" << endl<<endl;

	cout << white;
	cout << "***********************��������***********************" << endl;
	cout << lightblue;
	cout << "1 ������E�ļ���" << endl;
	cout << "2 ������Sx�Ĺ���" << endl;
	cout << "3 �쳣���ݵ��б����޳����Ƽ�ÿ��ʵ��ǰ��ʹ�ñ����ܣ�" << endl;
	cout << "4 A�಻ȷ���ȵĲ���" << endl;
	cout << "5 B�಻ȷ���ȵĲ���" << endl;
	cout << "6 �ϳɱ�׼��ȷ����u" << endl;
	cout << "7 ��С���˷����ֱ��" << endl;
	cout << "8 ����������" << endl;
	cout << "9 �Ƕ���ת�������ƣ�����ʵ��5.5֮ǰ����ʹ�ô˹��ܣ�" << endl<<endl;

	cout << white;
	cout << "*****************�����ߣ�qw & ����007*****************" << endl;
	cout << blue;
	cout << "0 ��ȡ<ʵ����������>���ܣ�" << endl<<endl;
	cout << white;

K:
	cout << "�����½ںţ���ʼʵ�����ݴ���" << endl;
	double go;
	cin >> go;

	if (go == 666666)
		{
		D:
			system("cls");

			cout << "�ṩ�������ʵ�����ݵ�ʵ���У�" << endl<<endl;
			cout << lightblue;
			cout << "������ ��ѧ����ѧʵ��" << endl;
			cout << "3.2 Һ��ճ��ϵ���Ĳ��������¶������о�" << endl;
			cout << "3.4 �������ⶨ����ģ��" << endl << endl;
			cout << yellow;
			cout << "������ ���ѧʵ��" << endl;
			cout << "4.1 PN�������ѹ�¶������о�" << endl;
			cout << "4.3 ��˹�ǵ��Ų����" << endl;
			cout << "4.4 ��ƽ����ŵ�ѹ��������о�" << endl;
			cout << "4.6 ģ��ʾ������ʹ��" << endl << endl;
			cout << purple;
			cout << "������ ��ѧʵ��" << endl;
			cout << "5.3 ��ĵȺ��������" << endl;
			cout << "5.4 �������" << endl<<endl;
			cout << green;
			cout << "������ �ۺ���ʵ��" << endl;
			cout << "6.9 ���������ʵĲ���" << endl << endl;
			cout << blue;
			cout << "0 �������˵�" << endl<<endl;
		E:
			cout << white;
			cout << "�����½ںţ��������ʵ�����ݣ�" << endl;

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
			else { cout << "ERROR����û������½ڣ����������롣" << endl; goto E; }
			
			cout << "����B�����������ݲ˵���������0�������˵����������������˳�����" << endl;
			char back1;
			cin >> back1;
			if (back1 == 'b' || back1 == 'B'){ system("cls"); goto D; }
			if (back1 == '0'){ goto J; }
			else{ exit(0); }

			//C5_5 ���ṩ

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
		cout << "��������ֵ��" << endl;
		cin >> truex;
		cout << "���������ֵ��" << endl;
		cin >> measurex;
		basic1(measurex, truex);
	}

	else if (go == 2)
	{
		system("cls");
		double * p2; int n2;
		cout << "���������ݵĸ���n��" << endl;
		cin >> n2;
		p2 = new double[n2];
		cout << "��ֱ��������ݵ�ֵ��" << endl;
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
		cout << "���������ݵĸ���n��" << endl;
		cin >> n3;
		p3 = new double[n3];
		cout << "��ֱ��������ݵ�ֵ��" << endl;
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
		cout << "���������ݵĸ���n��" << endl;
		cin >> n4;
		p4 = new double[n4];
		cout << "��ֱ��������ݵ�ֵ��" << endl;
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
		cout << "�����������������ǣ�" << endl;
		cin >> deltayi5;
		basic5(deltayi5);
	}

	else if (go == 6)
	{
		system("cls");
		double * p6; int n6;
		cout << "���������ݵĸ���n��" << endl;
		cin >> n6;
		p6 = new double[n6];
		cout << "��ֱ��������ݵ�ֵ��" << endl;
		for (int i = 0; i < n6; i++)
		{
			cin >> p6[i];
		}
		double deltayi6;
		cout << "�����������������ǣ�" << endl;
		cin >> deltayi6;
		basic6(p6, n6,deltayi6);
	}

	else if (go == 7)
	{ 
		system("cls");
	J7:
		double *x7, *y7; int n7;
		cout << "������(x,y)�ĸ���n��" << endl;
		cin >> n7;
		if (n7 == 1){ cout << "ERROR�����������Ϊ1��" << endl; goto J7; }
		else
		{
			x7 = new double[n7];
			y7 = new double[n7];
			cout << "�밴һ��˳���������ĺ�����x��" << endl;
			for (int i = 0; i < n7; i++)
			{
				cin >> x7[i];
			}
			cout << "�밴һ��˳����������������y��" << endl;
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
		cout << "���������ݵĸ���n��" << endl;
		cin >> n8;
		p8 = new double[n8];
		cout << "��ֱ��������ݵ�ֵ��" << endl;
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

	else { cout << red<<"ERROR����û������½ڣ����������롣" <<white<< endl; goto K; }

	cout << "����B�������˵����������������˳�����" << endl;
	char back;
	cin >> back;
	if (back == 'b' || back == 'B'){ system("cls"); goto J; }
	else { exit(0); }
	system("pause");
}

