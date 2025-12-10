#include<iostream>
#include<sstream>
#include<unordered_map>
#include<vector>
using namespace std;
class CountFreqOfChar {
    public:
    vector<string> CountFreq (string s) {
        stringstream ss(s);
        string word;
        vector<string>freq; //insertion order
        unordered_map<string,int> mpp; //frequency map
        while(ss >> word) {
            string combo = "";
            combo += word[0];
            combo += word[word.size() - 1];
            if(mpp.find(combo) == mpp.end()) { //first occurance
                freq.push_back(combo);
            }
            mpp[combo]++;
        }
        int maxCombo = 0;
        for(auto &p : mpp) {
            maxCombo = max(maxCombo,p.second); //Max Frequency
        }
        vector<string>ans;
        for(auto &combo : freq) {
            if(mpp[combo] == maxCombo) {
                ans.push_back(combo);
            }
        }
        return ans;
    }
};

int main() {
    string s;
    getline(cin,s);
    CountFreqOfChar obj;
    vector<string>ans = obj.CountFreq(s);
    for(auto &p : ans) {
        cout << p << " ";
    }
    return 0;
}