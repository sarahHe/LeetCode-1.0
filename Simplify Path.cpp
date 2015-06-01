// Given an absolute path for a file (Unix-style), simplify it.
// For example,
// path = "/home/", => "/home"
// path = "/a/./b/../../c/", => "/c"
// Corner Cases:
// Did you consider the case where path = "/../"?
// In this case, you should return "/".
// Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
// In this case, you should ignore redundant slashes and return "/home/foo".

// 模拟整个过程：
// 1. "/" 根目录
// 2. ".." 跳转上级目录，上级目录为空，所以依旧处于 "/"
// 3. "a" 进入子目录a，目前处于 "/a"
// 4. "b" 进入子目录b，目前处于 "/a/b"
// 5. "c" 进入子目录c，目前处于 "/a/b/c"
// 6. "." 当前目录，不操作，仍处于 "/a/b/c"
// 7. ".." 返回上级目录，最终为 "/a/b"

// 我用一个堆栈来模拟路径的行为，遇到"."不操作，遇到".."退栈，其他情况都压入堆栈。
// P.S.
// 有以"."开头的路径，例如："/.fdfd"。
class Solution {
public:
    string simplifyPath(string path) {
        int i = 0;
        vector<string> s;
        while (i < path.length()) {
            while (i < path.length() && path[i] == '/')
                i++; //begining '/'
            if (i == path.length())
                break;
            
            int start = i;
            while (i < path.length() && path[i] != '/')
                i++; 
                
            string cur = path.substr(start, i - start);
            if (cur == "..") {
                if (!s.empty())
                    s.pop_back();
            }
            else if (cur != ".")
                s.push_back(cur);
        }
        if (s.size() == 0)  return "/";
        string res = "";
        for (int i = 0; i < s.size(); i++)
            res += '/' + s[i];
        return res;
    }
};




2015.5.31 update
class Solution {
public:
    string simplifyPath(string path) {
        string res, tmp;
        stack<string> s;
        stringstream ss(path);
        while (getline(ss, tmp, '/')) {
            if (tmp == "" || tmp == ".") continue;
            else if (tmp == ".." && !s.empty()) s.pop();
            else if (tmp != "..")   s.push(tmp);
        }
        while (!s.empty()) {
            res = "/" + s.top() + res;
            s.pop();
        }
        return res == "" ? "/" : res;
    }
};
