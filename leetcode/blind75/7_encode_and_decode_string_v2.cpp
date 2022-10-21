class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded = "";
        for(string word : strs) {
            encoded += getBytes(word.length());
            encoded += word;
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decoded;
        for(int i = 0; i < s.length(); ) {
            int len = getLength(s.substr(i, 4));
            decoded.push_back(s.substr(i + 4, len));
            i += len + 4;
        }
        return decoded;
    }
    
private:
    string getBytes(int len) {
        string bytes = "";
        for(int i = 0; i < 4; i++) {
            unsigned char ch = (len >> (i * 8)) & 0xFF;
            bytes += (char)ch;
        }
        reverse(bytes.begin(), bytes.end());
        return bytes;
    }
    int getLength(string bytes) {
        int len = 0;
        for(int i = 0; i < 4; i++) {
            unsigned char ch = bytes[i];
            len = (len << 8) + int(ch);
        }
        return len;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));