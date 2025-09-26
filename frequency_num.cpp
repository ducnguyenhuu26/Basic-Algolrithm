#include<bits/stdc++.h>
using namespace std;

//O(n^2)
bool checkEqualFrequency(std::vector<int> s) 
{ vector<long long> a(690000); 
    for(int i = 0; i < s.size(); i++) 
    { a[s[i]]++; } 
    for(int i = 0; i < s.size(); i++) 
    { for(int j = i+1; j < s.size(); j++)
        { if(a[s[i]] != a[s[j]]) return false; } 
    } 
        return true; 
}

//O(n):Vector(1 <= size <= 10^6)

bool checkEqualFrequency(const vector<int>& s) {
    if (s.empty()) return true;

    int maxVal = *max_element(s.begin(), s.end());
    vector<int> freq(maxVal + 1, 0);

    for (int x : s) {
        freq[x]++;
    }

    int expected = 0;
    for (int x : s) {
        if (expected == 0) expected = freq[x];
        else if (freq[x] != expected) return false;
    }
    return true;
}

//O(n): Unordered_map(No worry about out of range)

bool checkEqualFrequency(const vector<int>& s) {
    unordered_map<int,int> freq;

    // Đếm tần suất
    for (int x : s) {
        freq[x]++;
    }

    if (freq.empty()) return true;

    // Lấy tần suất đầu tiên làm chuẩn
    int expected = freq.begin()->second;
    for (auto &p : freq) {
        if (p.second != expected) return false;
    }

    return true;
}