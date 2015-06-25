class Solution {
public:
    int compareVersion(string version1, string version2) {
        if (version1 == version2)
            return 0;
        string s1, s2;
        int v1, v2;
        std::string::size_type pos1 = version1.find('.'), pos2 = version2.find('.');
        if(pos1 != std::string::npos) {
            v1 = atoi(version1.substr(0, pos1).c_str());
            s1 = version1.substr(pos1+1);
        }
        else {
            v1 = atoi(version1.c_str());
            s1 = "0";
        }
        
        if(pos2 != std::string::npos) {
            v2 = atoi(version2.substr(0, pos2).c_str());
            s2 = version2.substr(pos2+1);
        }
        else {
            v2 = atoi(version2.c_str());
            s2 = "0";
        } 
        if(v1 < v2) return -1;
        else if(v1 > v2) return 1;
        else return compareVersion(s1, s2);
    }
};