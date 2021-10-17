#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;
using std::vector;

/*
将数组中的string按空格拆分为数字和域名存到cd数组中；
再将域名按.进行拆分存放到domainArr数组中；
将拆分后的domainArr信息从后往前组合存放到映射domianMap（记录对应的域名和次数）
最后将domianMap进行组合输出
*/

class DomainVisits {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int> domianMap;
        string subdomain = "";
        for(const string& domain : cpdomains)
        {
            vector<string> cd = Split(domain, ' ');
            vector<string> domainArr = Split(cd[1], '.');
            int count = stoi(cd[0]);
            for(int i = domainArr.size()-1; i >=0 ; --i)
            {
                subdomain = domainArr[i]+(subdomain.empty() ? "" : "." +subdomain );
                domianMap[subdomain] += count;
            }
            subdomain = "";
        }

        vector<string> resDomain;
        for (auto subStr : domianMap)
        {            
            // cout<<to_string(subStr.second) + " " + subStr.first<<endl;
            resDomain.push_back(to_string(subStr.second) + " " + subStr.first);
        }

        return resDomain;
    }
private:
    vector<string> Split(const string& s, char c)
    {
        vector<string> res;
        stringstream ss(s);
        string curr;
        while(std::getline(ss, curr, c))
        {
            res.push_back(curr);
        }
        return res;
    }

};

int main(){
    DomainVisits dv;
    vector<string> vstr;
    vstr.push_back("9001 discuss.leetcode.com");
    vstr.push_back("9 now.leetcode.com");
    dv.subdomainVisits(vstr);
    return 0;
}