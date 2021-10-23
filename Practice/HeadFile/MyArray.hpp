#pragma once
#include <iostream>

using namespace std;

//模板数组
template<class T>
class MyArray
{
public:
    MyArray(capacity){
        m_Capacity = capacity;
        m_Size = 0;
        tp = new T[this->m_Capacity];
    }

    //深拷贝
    MyArray(const MyArray &arr){
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        if(this->tp != NULL){
            delete [] tp;
            tp = nullptr;
        }
        this->tp = new T[this->m_Capacity];
        for(int i = 0; i < this->m_Size; ++i){
            this->tp[i] = arr.tp[i];
        }
    }
    //赋值
    MyArray& operator=(const MyArray &arr){
        if(this->tp != NULL){
            delete [] tp;
            tp = nullptr;
        }
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->tp = new T[this->m_Capacity];
        for(int i = 0; i < this->m_Size; ++i){
            this->tp[i] = arr.tp[i];
        }
        return *this;
    }

    void PushBack(const T &val){
        if(this->m_Size == this->m_Capacity){
            return;
        }
        this->m_Size++;
        this->tp[m_Size] = val;        
    }
    //尾删法
    void PopBack(){
        if(this->m_Size == 0){
            return;
        }
        --this->m_Size;
    }

    ~MyArray(){
        if(this->tp != NULL){
            delete [] tp;
            tp = nullptr;
        }
    }


private:
    int m_Size;
    int m_Capacity;
    T * tp;
    
};