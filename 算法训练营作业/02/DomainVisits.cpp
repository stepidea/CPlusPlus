#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;
using std::vector;

/*
���������ʼ�����https://leetcode-cn.com/problems/subdomain-visit-count/
�������е�string���ո���Ϊ���ֺ������浽cd�����У�
�ٽ�������.���в�ִ�ŵ�domainArr�����У�
����ֺ��domainArr��Ϣ�Ӻ���ǰ��ϴ�ŵ�ӳ��domianMap����¼��Ӧ�������ʹ�����
���domianMap����������
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
                subdomain = domainArr[i] + (subdomain.empty() ? "" : "." + subdomain);
                domianMap[subdomain] += count;
            }
            subdomain = "";
        }

        vector<string> resDomain;
        for (auto& subStr : domianMap)
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