#include <iostream>
#include "rational.h"

using namespace std;

int main()
{	
	setlocale(LC_ALL, "Russian");

	int size;
	cout << "Ââåäèòå êîëè÷åñòâî äðîáåé -> "; cin >> size;
	cout << "\n";
	rational* arr = new rational[size];
	int a, b;

	cout << "Ââîäèòü ÷èñëà íóæíî ñòðîãî ÷åðåç ïðîáåë\n";
	for (int i = 0; i < size; i++)
	{
		cout << "Ââåäèòå ÷èñëèòåëü è çíàìèíàòåëü äðîáè íîìåð " << i + 1 << " : "; cin >> a >> b;
		(arr[i]).set(a, b);
	}
	cout << "\n";
	for (int i = 0; i < size; i++)
	{
		cout << "\nÄðîáü íîìåð " << i + 1 << " : ";
		(arr[i]).show();
	}
	cout << "\n";

	int i1, i2;

	cout << "\nÓêàæèòå äâå äðîáè, êîòîðûå âû õîòèòå ñëîæèòü: "; cin >> i1 >> i2; i1 = i1 - 1; i2 = i2 - 1;
	cout << "\n"; (arr[i1]).show(); cout << " + "; (arr[i2]).show(); cout << " = ";
	((arr[i1]) + (arr[i2])).show();
	cout << "\n";

	cout << "\nÓêàæèòå äâå äðîáè, îäíó èç êîòîðûõ âû õîòèòå âû÷åñòü èç äðóãîé: "; cin >> i1 >> i2; i1 = i1 - 1; i2 = i2 - 1;
	cout << "\n"; (arr[i1]).show(); cout << " - "; (arr[i2]).show(); cout << " = ";
	((arr[i1]) - (arr[i2])).show();
	cout << "\n";

	cout << "\nÓêàæèòå äðîáü, ê ÷èñëèòåëþ êîòîðîé âû õîòèòå ïðèáàâèòü åäèíèöó: "; cin >> i1; i1 = i1 - 1;
	cout << "\n"; (arr[i1]).show(); cout << "++";cout << " = ";
	rational xr = arr[i1];
	(++xr).show();
	cout << "\n";

	cout << "\nÓêàæèòå äâå äðîáè, êîòîðûå âû õîòèòå ïðîâåðèòü íà ðàâåíñòâî: "; cin >> i1 >> i2; i1 = i1 - 1; i2 = i2 - 1;
	cout << "\n"; (arr[i1]).show(); cout << " == "; (arr[i2]).show();
	if (arr[i1] == arr[i2]) cout << "\nÄðîáè ðàâíû";
	else cout << "\nÄðîáè íå ðàâíû";
	cout << "\n";

	cout << "\nÓêàæèòå äâå äðîáè, êîòîðûå âû õîòèòå ñðàâíèòü: "; cin >> i1 >> i2; i1 = i1 - 1; i2 = i2 - 1;
	cout << "\n"; (arr[i1]).show(); cout << " > "; (arr[i2]).show();
	if (arr[i1] > arr[i2]) cout << "\nÏåðâàÿ äðîáü áîëüøå";
	else cout << "\nÂòîðàÿ äðîáü áîëüøå";
	cout << "\n";

	delete[] arr;

	return 0;
}
