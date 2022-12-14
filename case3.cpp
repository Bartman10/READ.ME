//Jacob Campos
//cis 7
//09/14/22
#include <iostream>

using namespace std;
 
string gen(string sif, string llav)
{
    int k = sif.size();
 
    for (int i = 0; ; i++)
    {
        if (k == i)
            i = 0;
        if (llav.size() == sif.size())
            break;
        llav.push_back(llav[i]);
    }
    return llav;
}

string ecry(string sif, string llav)
{
    string cip;
 
    for (int i = 0; i < sif.size(); i++)
    {
        char k = (sif[i] + llav[i]) %26;
 
        k += 'A';
       
        cip.push_back(k);
    }
    return cip;
}

string dcry(string cip, string llav)
{
    string og_t;
 
    for (int i = 0 ; i < cip.size(); i++)
    {
        char k = (cip[i] - llav[i] + 26) %26;
 
        k += 'A'; 
        
        og_t.push_back(k);
    }
    return og_t;
}
 
void input(string &lin,string &kword)
{
    cout << "Enter the Plaintext: ";
    cin >> lin;
    cout << "Enter the keyword: ";
    cin >> kword;
    cout << "\ntext : " << lin;
    cout << "\nKeyword: " << kword<<"\n";
}
// send program to functions above
int main()
{
    string lin;
    string kword;
   
    cout << "Enter E to encrypt and D for decrypt: ";
    char k;
    cin >> k;
    input(lin,kword);
    string llav = gen(lin, kword);
    if(k=='E'){
    	string cip = ecry(lin, llav);
    	cout << "Ciphertext : "<< cip << "\n"; 
  }
    else if(k=='D')
    cout << "CipherText : "<< dcry(lin, llav);
    return 0;
}

