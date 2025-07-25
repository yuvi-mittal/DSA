class Solution {
	public:
	
		void solve(vector<string> &ans, string &output,string digits, int index,string mapping[] )
		{
			if(index>= digits.size()){
				ans.push_back(output);
				return;
			}
			int number = digits[index] -'0';
			string letter = mapping[number];
	
			for(int i =0 ; i<letter.length() ; i++){
				 output.push_back(letter[i]);
				 solve(ans, output , digits , index+1 , mapping);
				 output.pop_back();
			}
	
		}
		vector<string> letterCombinations(string digits) {
			vector<string> ans;
			string output;
			int index = 0;
			 if (digits.empty()){
					 return ans;
				}
			string mapping[10] = {"" , "", "abc" , "def", "ghi" , "jkl" , "mno", "pqrs" ,"tuv" ,"wxyz"};
	
			solve(ans,output, digits, index , mapping);
	
			return ans;




