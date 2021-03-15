#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <cstring>
#include <iostream>

using namespace std;

int main(int argc, char *argv[], char *enpv[]) {
	string ptr, str;
	
	cout << "Enter your text (enter ex to start example program): ";
	getline(cin, str);
	
	if (str == "ex") str = "Our four foresters with weapons walked through the forest to protect forest animals without erecting walls. The wolf and the wolf pit a bear and a bears den the fox and foxhole.";
	if (str[str.length()-1] != '.') str.insert(str.length(), 1, '.'); 
	
	
	cout << "[Original text]\n" << str;
	
	string user;
	cout << "\n\nDisplay only duplicate triads (y/n): ";
	cin >> user;
	
	cout << "\n\nDivide the text into parts...\n\n";
	int old_str = - 2, end_str = -2, i = 1;
	while (1) {		
		old_str = end_str + 2;
		end_str = str.find('.', end_str + 2) < str.length() - 1 ? str.find('.', end_str + 3) : str.length() - 1;
		ptr = str.substr(old_str, end_str - old_str);
		char p[ptr.length()+1];
		strcpy(p, ptr.c_str());
		cout << "[Parent program] Part " << i << endl << p << endl;
		
		
		pid_t pid = 0;
		int   status;		
		pid = fork();
		char u[1];
		strcpy(u, user.c_str());
		if (pid == 0) execl("p1", "", u, p,  NULL);
		if (pid > 0) {
			cout << "\n[Child program]\n";
			pid = wait(&status);
		}				
		cout << endl;
		i++;
		if (end_str > str.length() - 2) break;
	}
	
	return 0;
}
