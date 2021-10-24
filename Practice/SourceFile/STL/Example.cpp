// 5����ί��4���˴��
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>

using namespace std;

class Person{
public:
    Person(string name,int score){
        m_name = name;
        m_score = score;
    }

    string m_name;
    int m_score;
};

void createPerson(vector<Person> &v){
    string nameSeed = "ABCD";
    for (int i = 0; i < 4; i++)
    {
        string name = "ѡ��" ;
        name += nameSeed[i];
        Person p(name, 0);
        v.push_back(p);
    }    
}

void setScore(vector<Person> &v){
    for(vector<Person>::iterator vit = v.begin(); vit != v.end(); vit++){
        deque<int> d;
        for (int i = 0; i < 5; i++)
        {
            d.push_back(rand() % 41 + 60);
        }

        sort(d.begin(),d.end());

        d.pop_back();
        d.pop_front();

        int sum = 0;
        for (deque<int>::iterator it = d.begin(); it < d.end(); it++)
        {
            sum += *it;
        }
        cout << sum << endl;
        vit->m_score = sum/d.size();
    }
    
}

int main(){
    //����4����
    vector<Person> v;
    createPerson(v);

    //5����ί���
    setScore(v);

    //���4���˵�����
    for(vector<Person>::iterator it = v.begin(); it != v.end(); it++){
        cout << "������" << it->m_name << " ������" << it->m_score << endl;
    }
    return 0;
}
