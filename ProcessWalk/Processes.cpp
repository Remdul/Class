#include <dirent.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct process
{
    process();
    string name;
    int pid;
    vector<string> open_files;
    string proc_exe;
    void getProc(pid);
    void createProcess(string, int, vector<string>, string);
};

process::process()
{
    pid = 0;
}
void process::createProcess(string newName, int newPid, vector<string> new_open_files, string new_proc_exe)
{
    pid = newPid;
    name = newName;
    open_files = new_open_files;
    proc_exe = new_proc_exe;
}

int main()
{
    vector<string> open_files;
    struct dirent* entry;
    DIR* dir = opendir("/proc/");

    if (!dir)
    {
        cout << "ERROR: Opendirectory Failed" << endl;
        return 1;
    }

    while ((entry = readdir(dir)) != NULL )
    {
        DIR* procdir = opendir ("/proc/" + entry->d_name);
        cout << entry->d_name << endl;
    }
}
