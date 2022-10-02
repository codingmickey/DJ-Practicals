// Non-restoring division

#include <bits/stdc++.h>

using namespace std;

vector<bool> oneSComplement(vector<bool> num)
{
    for (int i = 0; i < num.size(); i++)
    {
        num[i] = !num[i];
    }
    return num;
}

vector<bool> twoSComplement(vector<bool> num)
{
    num = oneSComplement(num);
    if (num[num.size() - 1])
    {
        num[num.size() - 1] = 0;
        num[num.size() - 2] = 1;
    }
    else
    {
        num[num.size() - 1] = 1;
    }
    return num;
}

vector<bool> binaryAddition(vector<bool> a, vector<bool> b, int n)
{
    vector<bool> ans(n);
    bool carry = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == 1 && b[i] == 1 && carry)
        {
            ans[i] = 1;
            carry = 1;
        }
        else if ((a[i] == 1 && b[i] == 1) || (((a[i] == 1) || (b[i] == 1)) && carry))
        {
            ans[i] = 0;
            carry = 1;
        }
        else
        {
            ans[i] = a[i] + b[i] + carry;
            carry = 0;
        }
    }
    return ans;
}

// Returns the right most shifted value from the q
bool arithmeticRightShift(vector<bool> &a, vector<bool> &q)
{
    bool kachra = q[q.size() - 1], prev = a[0], temp;
    for (int i = 1; i < a.size(); i++)
    {
        temp = a[i];
        a[i] = prev;
        prev = temp;
    }
    temp = q[0];
    q[0] = prev;
    prev = temp;
    for (int i = 1; i < q.size(); i++)
    {
        temp = q[i];
        q[i] = prev;
        prev = temp;
    }
    return kachra;
}

// Left Shifts the 2 numbers :)
void arithmeticLeftShift(vector<bool> &a, vector<bool> &q)
{
    bool kachra = q[q.size() - 1], prev = a[0], temp;
    for (int i = 0; i < a.size() - 1; i++)
    {
        a[i] = a[i+1];
    }
    a[a.size() - 1] = q[0];
    for (int i = 0; i < q.size() - 1; i++)
    {
        q[i] = q[i+1];
    }
}

int main()
{
    // Taking the input in string so that we don't need to ask for the size of the number
    string qtemp, mtemp;
    // Then storing the number in a vector(Array) for easy access
    vector<bool> q, m, a, negM;
    bool qNeg = 0;

    // We'll be taking the input in binary format only
    cout << "Enter m: ";
    cin >> mtemp;
    cout << "Enter q: ";
    cin >> qtemp;

    // Counter
    int n;
    // Assigning the counter with the max value
    // if (mtemp.length() > qtemp.length())
    //     n = mtemp.length();
    // else
    //     n = qtemp.length();
        
    n = qtemp.length();

    int count = n;

    // Assigning the Accumulator with 0's
    for (int i = 0; i < n + 1; i++)
    {
        a.push_back(0);
    }
    
    int mtempNum = (n+1)-mtemp.length();
    while(mtempNum>0) {
        m.push_back(0);
        mtempNum--;
    }

    // Converting the string into vector(array)
    for (int i = 0; i < qtemp.length(); i++)
    {
        if (qtemp[i] == '1')
            q.push_back(1);
        else
            q.push_back(0);
    }
    for (int i = 0; i < mtemp.length(); i++)
    {
        if (mtemp[i] == '1')
            m.push_back(1);
        else
            m.push_back(0);
    }

    // Calculating the -M
    negM = twoSComplement(m);

    vector<bool> ans = binaryAddition(m, q, n);

    while (count--)
    {
        arithmeticLeftShift(a, q);
        cout << "1a";
        for (auto x : a)
            cout << x;

        cout << "\n";
        for (auto x : m)
            cout << x;

        cout << "\n";
        cout << "q";
        for (auto x : q)
            cout << x;

        cout << "\n";
        cout << "\n";
        
        a = binaryAddition(a, negM, n+1);
        
            cout << "2a";
        for (auto x : a)
            cout << x;

        cout << "\n";
        cout << "q";
        for (auto x : q)
            cout << x;

        cout << "\n";
        cout << "\n";
        
        // a[0] = 1 means the number is -ve
        if(a[0]) {
            q[q.size()-1] = 0;
            a = binaryAddition(a, m, n+1);
        } else {
            q[q.size()-1] = 1;
        }
        
        cout << "3a";
        for (auto x : a)
            cout << x;

        cout << "\n";
        cout << "q";
        for (auto x : q)
            cout << x;
            cout<<"\n";
        cout << "\n";
    };
    
    cout << "Answer: ";
    for (auto x : a)
        cout << x;

    cout << "\n";
    for (auto x : q)
        cout << x;

    return 0;
}