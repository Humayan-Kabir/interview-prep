class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ans = "";
        for(string s : strs) {
            ans += intToBytes(s.length());
            ans += s;
        }
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> strs;
        for(int i = 0; i < s.length();) {
            int len = bytesToInt(s.substr(i, 4));
            strs.push_back(s.substr(i + 4, len));
            i = i + 4 + len;
        }
        return strs;
    }
private:
    string intToBytes(int x) {
        string bytes(4,' ');
        for(int i = 3; i > -1; --i) {
          bytes[3 - i] = (char)(x >> (i * 8) & 0xff);
        }
        return string(bytes);
    }
    int bytesToInt(string bytes) {
        int len = 0;
        for(char ch : bytes) {
            len = (len << 8) + (int) ch;
        }
        return len;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));