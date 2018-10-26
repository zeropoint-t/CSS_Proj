#ifndef DataCompressor_h
#define DataCompressor_h

    #include <vector>
    #include <string>

    using namespace std;

    class DataCompressor{
        public:
            DataCompressor();
            DataCompressor(const string str);
            void Compress(const string str);
            void Decompress();

            int getNum(const vector<char>& nums) const;
            void expand(const int cnt, const char c);

            vector<char> compressed;
            vector<char> decompressed;
            
        private:
            // vector<char> compressed;
            // vector<char> decompressed;
            // int getNum(const vector<char> nums) const;
            // void expand(const int cnt, const char c);
    };

#endif