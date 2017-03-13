/*	Ŀ¼��	
һ��������E�ļ���			
����������Sx�Ĺ���		
�����쳣���ݵ��б����޳�	
�ġ�A�಻ȷ���ȵĲ���		
�塢B�಻ȷ���ȵĲ���		
�����ϳɱ�׼��ȷ����u		
�ߡ���С���˷����ֱ��
�ˡ�����������
�š��Ƕ��ƻ�����ֵ
*/

#include <iostream>
#include <cmath>
using namespace std;

//һ��������E�ļ���
void basic1(double measurex, double truex)//measurexΪ����ֵ��truexΪ��ֵ����ƽ��ֵ��
{
	cout<<"������E="<<fabs(measurex - truex) * 100 / truex << "%"<<endl;
}

//����������Sx�Ĺ���
void basic2(double * p, int n)//*pΪ�������飬nΪ���鳤��
{
	double average=0;
	for (int i = 0; i < n; i++)
	{
		average += p[i];
	}
	average /= n;//���ƽ��ֵaverage
	double Sx = 0;
	for (int i = 0; i < n; i++)
	{
		Sx += pow(p[i] - average, 2);
	}
	Sx /= n - 1;
	Sx = sqrt(Sx);//���������Sx
	cout << "������Sx=" << Sx << endl;
}

//�����쳣���ݵ��б����޳�
void basic3(double * p, int & n)//*pΪ�������飬nΪ���鳤��
{	
	double g0;
	double a;//��Ϊ�쳣���ݵĸ���
J:
	cout << "��������Ϊ�쳣���ݵĸ���a��0.05����0.01��:" << endl;
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
			default:cout << "������������12��С��4���޷��б�" << endl; goto L;
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
			default:cout << "������������12��С��4���޷��б�" << endl; goto L;
		}
	}
	else { cout << "a����Ϊ0.05����0.01!" << endl; goto J; }//g0�ĳ�ʼ��

	double average = 0;
	for (int i = 0; i < n; i++)
	{
		average += p[i];
	}
	average /= n;//���ƽ��ֵaverage
	double Sx = 0;
	for (int i = 0; i < n; i++)
	{
		Sx += pow(p[i] - average, 2);
	}
	Sx /= n - 1;
	Sx = sqrt(Sx);//���������Sx
	
	for (int i = 0; i < n; i++)	//�޳��쳣���ݣ�������쳣���ݣ�����������K��n=n-1
	{
		double gi;
		gi = (p[i] - average)/Sx;
		if (gi >= g0) 
		{
			cout <<"��" << i+1 << "������" <<p[i] << "���쳣���ݣ����޳���" << endl;
			for (int j = i; j < n - 1; j++)
			{
				p[j] = p[j + 1];
			}
			n -= 1;
			goto K;
		}
	}
	cout << "�޳��쳣������ϣ�ʣ������Ϊ��";
	for (int i = 0; i < n; i++)
	{
		cout << p[i] << " ";
	}
L:
	cout << endl;

}

//�ġ�A�಻ȷ���ȵĲ���
void basic4(double * p, int n)
{	
	if (n>1)
	{
		double average = 0;
		for (int i = 0; i < n; i++)
		{
			average += p[i];
		}
		average /= n;//���ƽ��ֵaverage
		double uA = 0;
		for (int i = 0; i < n; i++)
		{
			uA += pow(p[i] - average, 2);
		}
		uA /= n*(n - 1);
		uA = sqrt(uA);//A�಻ȷ����uA
		cout << "A�಻ȷ����uA=" << uA << endl;
		cout << "�����������ʾΪ" << average << "��" << uA << endl;
	}
	else 
	{
		cout << "���ݸ����������1��" << endl;
	}
}

//�塢B�಻ȷ���ȵĲ���
void basic5(double deltayi)
{
	cout << "B�಻ȷ����uB=" << deltayi/1.732<< endl;
}

//�����ϳɱ�׼��ȷ����u
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
		average /= n;//���ƽ��ֵaverage
		for (int i = 0; i < n; i++)
		{
			uA += pow(p[i] - average, 2);
		}
		uA /= n*(n - 1);
		uA = sqrt(uA);//A�಻ȷ����uA

		double uB;
		uB = deltayi / 1.732;
		double u;
		u = sqrt(pow(uA, 2) + pow(uB, 2));
		cout << "�ϳɱ�׼��ȷ����u=" << u << endl;
		cout << "�����������ʾΪ" << average << "��" << u << endl;
	}
	else
	{
		cout << "���ݸ����������1��" << endl;
	}
}

//�ߡ���С���˷����ֱ��
void basic7(double * x, double * y, int n)
{
	double a, b, Lxx, Lyy, Lxy, avex = 0, avey = 0, avexy = 0, avex2 = 0, avey2 = 0, R;
	if (n == 1){ cout << "ERROR��������������Ϊ1��" << endl; exit(0); }
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
			cout << i + 1 << "\t" << x[i] << "\t\t" << y[i] << "\t\t" << x[i] * x[i] << "\t\t" << y[i] * y[i] << "\t\t" << x[i] * y[i] << endl;
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
	}
}

//�ˡ�����������
void basic8(double * p, int n)
{
	int jiange;//ÿ������������֮��ļ��
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
		cout << "���ݸ���Ϊ��������������һ�����ݣ�" << endl;
		jiange = n / 2;
		for (int i = 1; i < jiange;i++)
		{
			total += p[i + jiange] - p[i];
		}
		average = total / (jiange * jiange);
	}
	cout << "�����Ϊ��" << average << endl;
}

//�š��Ƕ��ƻ�������
void basic9()
{
	int a, b, c;
J:
	cout << "������Ƕȣ��㣩��" << endl;
	cin >> a;
	cout << "������Ƕȣ�������" << endl;
	cin >> b;
	cout << "������Ƕȣ�������" << endl;
	cin >> c;
	cout << "ת����Ļ���Ϊ��rad����" << a*0.01745 + b*0.01745 / 60 + c*0.01745 / 360 << endl;
K:
	cout << "����һ�飿��Y/N��" << endl;
	char again;
	cin >> again;
	if (again == 'Y' || again == 'y'){ goto J; }
	else if (again == 'N' || again == 'n'){ ; }
	else { goto K; }
}