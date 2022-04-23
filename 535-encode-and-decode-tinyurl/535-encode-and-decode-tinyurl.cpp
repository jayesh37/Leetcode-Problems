class Solution {
public:
    map<string,string> codeDB, origDB;
    
    string chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    // Encodes a URL to a shortened URL
    
    string getcode()
    {
        string code= "";
        for(int i=0;i<62;i++)
        {
            code += chars[rand()%62];
        }
        return "http://tinyurl.com/" + code;
    }
    
    string encode(string longUrl) {
        
        if(origDB.find(longUrl)!=origDB.end())
            return origDB[longUrl];
        
        string code = getcode();
        
        while(codeDB.find(code)!=codeDB.end())
            code= getcode();
        
        codeDB[code]=longUrl;
        origDB[longUrl]=code;
        
        return code;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return codeDB[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));