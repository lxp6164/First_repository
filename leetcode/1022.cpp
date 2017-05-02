class Solution
{
public:
    void dfs(vector<string> &vec,string s, int left_cnt,int right_cnt)
    {
        if(!left_cnt && !right_cnt)
        {
            vec.push_back(s);
            return ;
        }
        if(left_cnt>0) dfs(vec,s+"(",left_cnt-1,right_cnt);
        if(right_cnt>0 && right_cnt>left_cnt) dfs(vec,s+")",left_cnt,right_cnt-1);
        return ;
    }




    vector<string> generateParenthesis(int n)
    {
        vector<string> vec;
        string str = "";
        dfs(vec,str,n,n);
        
        
        return vec;
        
        
    }
};
