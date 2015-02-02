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
        if (path == "")
            return path;
        
        stack<string> s;
        string res = "", tmp = "/";
        for (int i = 1; i < (int)path.size(); i++) {
            if (path[i] == '/') {
                if (tmp == "/..") {
                    tmp = "/";
                    if (!s.empty())
                        s.pop();
                }
                else if (tmp == "/")
                    ;
                else if (tmp == "/.") {
                    tmp = "/";
                }
                else {
                    s.push(tmp);
                    tmp = "/";
                }
        
            }
            else
                tmp += path[i];
            
        }
        if (tmp == "/.." || tmp == "/.") {
            if (s.empty())
                s.push("/");
            else if (tmp == "/.."){
                s.pop();
                if (s.empty())
                    s.push("/");
            }
        }
        else if (s.empty() || tmp != "/")
            s.push(tmp);
        while (!s.empty()) {
            res = s.top() + res;
            s.pop();
        }
        return res;
    }
};


// another solution:
// string simplifyPath(string path) {
//     // Start typing your C/C++ solution below
//     // DO NOT write int main() function
//     vector<string> helper;
//     string tmp, ans = "";
//     int plen = path.length();
//     int st_pos = 0, end_pos;
//     while (st_pos < plen) {
//         while (st_pos < plen && path[st_pos] == '/') {
//             st_pos++;
//         }
//         end_pos = st_pos + 1;
//         while (end_pos < plen && path[end_pos] != '/') {
//             end_pos++;
//         }
//         tmp = path.substr(st_pos, end_pos - st_pos);
//         if (tmp == "..") {
//             if (helper.size() > 0) {
//                 helper.pop_back();
//             }
//         } else if (tmp != "." && tmp.length() > 0) {
//             helper.push_back(tmp);
//         }
//         st_pos = end_pos + 1;
//     }
//     for (int i = 0; i < helper.size(); i++) {
//         ans += '/';
//         ans += helper[i];
//     }
//     if (ans.length() == 0) {
//         return "/";
//     }
//     return ans;
// }
