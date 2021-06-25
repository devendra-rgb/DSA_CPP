#include <iostream>

using namespace std;

int main()
{   
    int test_cases;
    cin  >>  test_cases;
    for(int i = 0; i < test_cases; i++)
    
    {
        int max = 0, len;
        
        cin >> len;
        
        int Ai[len];
        
        int Bi[len];
        
        for(int j = 0; j < len; j++)
        {
            cin >> Ai[j];
        }
        for(int j = 0; j < len;j++)
        {
            cin  >>  Bi[j];
        }

        for(int k = 0; k < len;k++)
        {
            if(max < (Ai[k] * 20 - Bi[k] * 10))
            
             max=(Ai[k] * 20 - Bi[k] * 10);
            

        }
        
        cout  <<  max  <<  endl;

    }
    
}