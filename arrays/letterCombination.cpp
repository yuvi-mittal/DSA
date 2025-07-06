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
			string mapping[10] = {"" , "", "abc" , "def", "ghi" , "jkl" ,   "mno",            "pqrs" ,"tuv" ,"wxyz"};
	
			solve(ans,output, digits, index , mapping);
	
			return ans;
	



lder],
    lhs: bool,
    op: str,
    rhs: bool,
    expected: str,
) -> None:
    """Test literal Boolean AND/OR operations."""
    builder = builder_class()
    module = builder.module()

    # build the ASTx expression: (lhs && rhs) or (lhs || rhs)
    left = astx.LiteralBoolean(lhs)
    right = astx.LiteralBoolean(rhs)
    expr = astx.BinaryOp(op, left, right)

    proto = astx.FunctionPrototype(
        name="main",
        args=astx.Arguments(),
        return_type=astx.Boolean(),
    )
    block = astx.Block()
    block.append(astx.FunctionReturn(expr))
    fn = astx.FunctionDef(prototype=proto, body=block)
    module.block.append(fn)

    success = True
    try:
        check_result("build", builder, module, expected_output=expected)
    except subprocess.CalledProcessError as e:
        success = False
        assert e.returncode == int(expected)
    assert not success


@pytest.mark.parametrize(
    "int_type,literal_type",
    [
        (astx.Int8, astx.LiteralInt8),
        (astx.Int16, astx.LiteralInt16),
        (astx.Int32, astx.LiteralInt32),
        (astx.Int64, astx.LiteralInt64),
    ],
)
@pytest.mark.parametrize(
    "lhs,op,rhs,expected",
    [
        (1, "<", 2, "1"),
        (2, "<", 1, "0"),
        (3, ">", 2, "1"),
        (2, ">", 3, "0"),
        (5, "<=", 5, "1"),
        (4, "<=", 3, "0"),
        (6, ">=", 6, "1"),
        (2, ">=", 7, "0"),
    ],
)
@pytest.mark.parametrize(
    "builder_class",
    [
        LLVMLiteIR,
    ],
)
def test_boolean_comparison(
    builder_class: Type[Builder],
    int_type: type,
    literal_type: type,
    lhs: int,
    op: str,
    rhs: int,
    expected: str,
) -> None:
    """Test integer comparisons."""
    builder = builder_class()
    module = builder.module()

    # build e.g. LiteralInt32(1) < LiteralInt32(2)
    left = literal_type(lhs)
    right = literal_type(rhs)
    expr = astx.BinaryOp(op, left, right)

    # wrap in a main() returning a  Boolean
    proto = astx.FunctionPrototype(
        name="main",
        args=astx.Arguments(),
        return_type=astx.Boolean(),
    )
    block = astx.Block()
    block.append(astx.FunctionReturn(expr))
    fn = astx.FunctionDef(prototype=proto, body=block)
    module.block.append(fn)

    success = True
    try:
        check_result("build", builder, module, expected_output=expected)
    except subprocess.CalledProcessError as e:
        success = False
        assert e.returncode == int(expected)
    assert not success

	
	
	
		}
	};
