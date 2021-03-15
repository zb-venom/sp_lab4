#include <sys/types.h>
#include <unistd.h>
#include <string>
#include <iostream>

using namespace std;

void Sort(int data[], string str[], int lenD);

int main(int argc, char *argv[], char *enpv[]) {
	string user = argv[1], str = argv[2], buffer;
	int n = str.length() - 3, num = 0;
	string trl[n];
	int trl_count[n];
	
	for (int i = 0; i < n; i++) {
		buffer = str.substr(i, 3);
		if (buffer.find(" ") > 3) {
			trl[num] = buffer;
			trl_count[num] = 1;
			//cout << trl[num] << " ";
			num++;
		}
	}
	//cout << endl;
	n = num;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (trl[i]==trl[j] && i != j) {
				for (int k = j; k < n; k++) {
					trl[k] = trl[k+1];
					trl_count[k] = trl_count[k+1];
				}
				trl_count[i]++;
				j--;
				n--;
			}
		}
	}
	Sort(trl_count, trl, n);
	for (int i = 0; i < n; i++) {
		cout <<  trl[i] << "[" << trl_count[i] << "] ";
		int t = ( n / 2 ) < 3 ? n / 2 : 3;
		if ( (i + 1) % t == 0) cout << endl; 		
		if (trl_count[i+1] == 1 && (user == "y" || user == "Y")) break;
	}
	cout << endl;
	return 0;
}



void Sort(int data[], string str[], int lenD)
{
  int tmp = 0;
  string tmpS;
  for(int i = 0;i<lenD;i++){
    for(int j = (lenD-1);j>=(i+1);j--){
      if(data[j]>data[j-1]){
        tmp = data[j];
        data[j]=data[j-1];
        data[j-1]=tmp;
        tmpS= str[j];
        str[j]=str[j-1];
        str[j-1]=tmpS;
      }
    }
  }
}
