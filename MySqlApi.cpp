#include "MySqlApi.h"

MySqlAPI::MySqlAPI(string path, string bdd, string adr, string user, string pwd){
    string default_param("");
    mysql_path = path;
    default_param += " -h "+ adr +" -u "+ user ;

    if(pwd.length()){
        default_param += " -p " + pwd;
    }
    default_param += " --default-character-set=latin1 ";
    default_param += (bdd + " -e \"");
    string_param = default_param;
    file_param = default_param + "source ";
}

int MySqlAPI::file_req_exec(string sql_file_path, string outfile){
    int ret = -1;

    //cout << "Insertion depuis " << sql_file_path << "...";

    string cmd = mysql_path + file_param + sql_file_path + "\"";

    if(outfile.length()) cmd += (" > "+ outfile);

    if(system(NULL)) ret = system(cmd.c_str());

    //cout << (ret==0 ? "OK!" : "ERREUR!") << endl;
    return ret;
}

int MySqlAPI::string_req_exec(string sql_string, string outfile){
    int ret = -1;
    string cmd = mysql_path + string_param + sql_string + "\"";

    if(outfile.length()>0) cmd += (" > "+ outfile);

    //cout << "Execute : \n" << sql_string << "...";
    if(system(NULL)) ret = system(cmd.c_str());
    //cout << (ret==0 ? "OK!" : "ERREUR!") << endl;
    return ret;
}

int MySqlAPI::rep_exec(string path, string outfile){
    int ret = 0;

    DIR *rep = opendir(path.c_str());
    if(rep){
        struct dirent *cur_file = NULL;
        while( (cur_file = readdir(rep))!=NULL  && ret==0 ){
            if(strcmp(cur_file->d_name,".")!=0 && strcmp(cur_file->d_name,"..")!=0){
                string cur_file_path = path + "/" + cur_file->d_name;
                ret = file_req_exec(cur_file_path, outfile);
            }
        }
    }
    else cerr << "Erreur, impossible de trouver : " << path << endl;
    return ret;
}
