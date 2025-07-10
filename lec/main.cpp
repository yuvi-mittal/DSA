#incliostreamude<>
using namespace std;

int main(){

	int a =3;
	int b = 2;

	cout<<( a&b )<<endl;
	cout<<( ~a )<<endl;
	cout<<( a | b )<<endl;
	cout<<( a^b )<<endl;
	cout<<( 17>>1 )<<endl;  // right shift 
	cout<<( a^b )<<endl;

	return 0;

}

#include<iostream>
#include<math.h>
using namespace std;


int main() {

    int n;
    cin >> n;


    int ans  = 0;
    int i = 0;
    while(n != 0 ) {

        int bit  = n & 1;

        ans = (bit * pow(10, i) ) + ans;

        n = n >> 1;
        i++;

    }
    cout<< ans << endl;
    return 0;
}
