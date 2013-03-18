#ifndef MySqlAPI_H
#define MySqlAPI_H

#include <iostream>
#include <string>
#include <fstream>

#include <stdlib.h>
#include <dirent.h>
//#include <sys/types.h>
//#include <sys/stat.h>
//#include <unistd.h>
#include <string.h>

#define DEFAULT_PATH "C:/mysql/bin/mysql.exe"
#define XAMPP_PATH "C:/xampp/mysql/bin/mysql.exe"

using namespace std;

class MySqlAPI{

    private:
        string mysql_path;
        string file_param;
        string string_param;

    public:
        MySqlAPI(string path, string bdd);

        int file_req_exec(string sql_file_path, string outputfile = "");
        int string_req_exec(string sql_string, string outputfile = "");
        int rep_exec(string path, string outfile = "");

};

#endif // MySqlAPI_H
