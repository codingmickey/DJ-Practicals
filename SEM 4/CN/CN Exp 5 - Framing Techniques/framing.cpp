#include <iostream>
#include <string>

using namespace std;

int main()
{
    int opt;
    do
    {
        cout << "1. Character count\n2. Starting and ending with character stuffing(NOT NEEDED for pracs)\n3. Character stuffing\n4. Starting and ending Flag, with bit stuffng.\n5. Exit";
        cout << "\n\nEnter an option: ";
        string data, finalData, temp;
        cin >> opt;
        switch (opt)
        {
        case 1:
        {
            cout << "Enter the number of frames: ";
            int frames;
            cin >> frames;
            while (frames--)
            {
                cout << "Enter frame data: ";
                cin >> temp;
                finalData += (std::to_string(temp.length()) + temp);
            }
            cout << "\nFinal data: " << finalData << "\n\n";
            break;
        }
        // case 2:
        // {
        //     cout << "Enter the data: ";
        //     cin >> data;
        //     string stx = "STX", dle = "DLE";
        //     finalData = stx + dle + data + dle + stx;
        //     cout << "\nFinal data: " << finalData << "\n\n";
        //     break;
        // }
        case 3:
        {
            cout << "Enter the data: ";
            cin >> data;
            string stx = "STX", dle = "DLE";
            int i = 0, count = 0;
            finalData += stx + dle;
            while (i != data.length())
            {
                finalData += data[i];
                if (data[i] == 'D')
                {
                    count++;
                }
                else if (count == 1 && data[i] == 'L')
                {
                    count++;
                }
                else if (count == 2 && data[i] == 'E')
                {
                    finalData += "DLE";
                    count = 0;
                }
                else
                {
                    count = 0;
                }
                i++;
            }
            finalData += dle + stx;
            cout << "\nFinal data: " << finalData << "\n\n";
            break;
        }
        case 4:
        {
            cout << "Enter the data: ";
            cin >> data;
            int count = 0;
            string flag = "01111110";
            finalData += flag;
            for (int i = 0; i != data.length(); i++)
            {
                if (data[i] == '1' && count == 5)
                {
                    count = 0;
                    finalData += '0';
                }
                if (data[i] == '1')
                {
                    count++;
                }
                else if (count > 0)
                {
                    count = 0;
                }
                finalData += data[i];
            }
            finalData += flag;
            cout << "\nFinal data: " << finalData << "\n\n";
            break;
        }
        case 5:
        {
            cout << "Exiting..!\n";
            break;
        }
        default:
        {
            cout << "Enter an valid OPTION!!\n\n";
        }
        }
    } while (opt != 5);
    return 0;
}