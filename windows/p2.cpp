#include <cstring>
#include <iostream>
#include <vector>
#include <windows.h>
#include <stdio.h>
#include <tchar.h>

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
		cout << "[Parent program] Part " << i << endl << ptr << endl;

        STARTUPINFO si;
        PROCESS_INFORMATION pi;

        ZeroMemory( &si, sizeof(si) );
        si.cb = sizeof(si);
        ZeroMemory( &pi, sizeof(pi) );
        string cmdLine;
        cmdLine += "string.exe ";
        cmdLine += user;
        cmdLine += " \"";
        cmdLine += ptr + "\"";

		char cmdL[cmdLine.length()+1];
		strcpy(cmdL, cmdLine.c_str());

        if( !CreateProcess( NULL,   // No module name (use command line)
            cmdL,        // Command line
            NULL,           // Process handle not inheritable
            NULL,           // Thread handle not inheritable
            FALSE,          // Set handle inheritance to FALSE
            0,              // No creation flags
            NULL,           // Use parent's environment block
            NULL,           // Use parent's starting directory
            &si,            // Pointer to STARTUPINFO structure
            &pi )           // Pointer to PROCESS_INFORMATION structure
        )
        {
            printf( "CreateProcess failed (%d).\n", GetLastError() );
            return 0;
        }
        cout << "\n[Child program]\n";

        // Wait until child process exits.
        WaitForSingleObject( pi.hProcess, INFINITE );
        cout << endl;

        // Close process and thread handles.
        CloseHandle( pi.hProcess );
        CloseHandle( pi.hThread );
		i++;
		if (end_str > str.length() - 2) break;
	}

	system("pause");

	return 0;
}
