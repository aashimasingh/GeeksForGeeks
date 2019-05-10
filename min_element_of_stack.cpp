#include<iostream>
#include<stack>
using namespace std;
void push(int a);
bool isFull(int n);
bool isEmpty();
int pop();
int getMin();
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty()){
		    pop();
		}
		while(!isFull(n)){
			cin>>a;
			push(a);
		}
		cout<<getMin()<<endl;
	}
}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Complete the function(s) below*/
void push(int a)
{
     //add code here.
     s.push(a);
}
bool isFull(int n)
{
     //add code here.
     if (s.size() == n) {
         return true;
     }
     else 
        return false;
}
bool isEmpty()
{
    //add code here.
    return s.empty();
}
int pop()
{
    //add code here.
    int topel = s.top();
    s.pop();
    return topel;
}
int getMin()
{
   //add code here.
   int minel = s.top();
   while( !s.empty() ) {
       if (s.top() < minel) 
           minel = s.top();
    s.pop();
   }
   return minel;