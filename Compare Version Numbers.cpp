/* review again */
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

//version2
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int m = version1.size(), n = version2.size();
        int l1 = 0, l2 = 0;
        while(l1 < m || l2 < n){
            int r1 = version1.find(".", l1);
            int r2 = version2.find(".", l2);
            if(r1 == -1) r1 = m;
            if(r2 == -1) r2 = n;
            int v1 = l1 == r1 ? 0 : stoi(version1.substr(l1, r1-l1));
            int v2 = l2 == r2 ? 0 : stoi(version2.substr(l2, r2-l2));
            if(v1 < v2) return -1;
            else if(v1 > v2) return 1;
            l1 = min(r1+1, m);
            l2 = min(r2+1, n);
        }
        return 0;
    }
};


//version2
//redo
int compareVersion(string version1, string version2) {
  int l1 = 0, l2 = 0, end1 = version1.size(), end2 = version2.size();
  while(l1 < end1 || l2 < end2) {
    //注意此处的find用法 可以设置pos的位置
    int r1 = version1.find('.', l1);
    int r2 = version2.find('.', l2);
    if(r1 == -1) r1 = end1;
    if(r2 == -1) r2 = end2;

    int v1 = l1 == r1? 0: stoi(version1.substr(l1, r1-l1));
    int v2 = l2 == r2? 0: stoi(version2.substr(l2, r2-l2));
    if(v1 < v2) return -1;
    if(v1 > v2) return 1;

    l1 = min(r1+1, end1);
    l2 = min(r2+1, end2);
  }
  return 0;
}

