#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void PrintMatr(int **mas, int m) {
  int i, j;
  for (i = 0; i<m; i++) {
    for (j = 0; j<m; j++)
      cout << mas[i][j] << " ";
    cout << endl;
  }
}

void GetMatr(int **mas, int **p, int i, int j, int m) {
  int ki, kj, di, dj;
  di = 0;
  for (ki = 0; ki<m - 1; ki++) {
    if (ki == i) di = 1;
    dj = 0;
    for (kj = 0; kj<m - 1; kj++) {
      if (kj == j) dj = 1;
      p[ki][kj] = mas[ki + di][kj + dj];
    }
  }
}

int Determinant(int **mas, int m) {
  int i, j, d, k, n;
  int **p;
  p = new int*[m];
  for (i = 0; i<m; i++)
    p[i] = new int[m];
  j = 0; d = 0;
  k = 1;
  n = m - 1;
  if (m<1) cout << "Îïðåäåëèòåëü âû÷èñëèòü íåâîçìîæíî!";
  if (m == 1) {
    d = mas[0][0];
    return(d);
  }
  if (m == 2) {
    d = mas[0][0] * mas[1][1] - (mas[1][0] * mas[0][1]);
    return(d);
  }
  if (m>2) {
    for (i = 0; i<m; i++) {
      GetMatr(mas, p, i, 0, m);
      cout << mas[i][j] << endl;
      PrintMatr(p, n);
      d = d + k * mas[i][0] * Determinant(p, n);
      k = -k;
    }
  }
  return(d);
}

int main() {
  int m, i, j, d, k;
  int **mas;
  setlocale(LC_ALL, "Russian");
  system("chcp 1251");
  system("cls");
  cout << "Ââåäèòå ðàçìåðíîñòü êâàäðàòíîé ìàòðèöû: ";
  cin >> m;
  cout << "Ââåäèòå ìàêñèìàëüíûå ðàçðåøåííûå ÷èñëà â ìàòðèöå: ";
  cin >> k;
  mas = new int*[m];
  srand(time(0));
  for (i = 0; i<m; i++) {
    mas[i] = new int[m];
    for (j = 0; j<m; j++) {

      if(rand()%2==0) {mas[i][j]=-(rand()%k);} else {mas[i][j]=rand()%k;}
    }
  }
  PrintMatr(mas, m);
  d = Determinant(mas, m);
  cout << "Îïðåäåëèòåëü ìàòðèöû ðàâåí " << d;
  //cin.get(); cin.get();
  return 0;
}
