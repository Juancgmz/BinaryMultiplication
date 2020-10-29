#include <iostream>
#include <cmath>

using namespace std;

int M = 0,Q = 0, A = 0, a1 = 0, b1 = 0, com[4] = { 1, 0, 0, 0};
int anum[4] = {0}, anumcp[4] = {0}, bnum[4] = {0};
int acomp[4] = {0}, bcomp[4] = {0}, pro[4] = {0}, res[4] = {0};

void BinaryConversion()
{
    a1 = fabs(M);
    b1 = fabs(Q);
    int r, r2, i, temp;

    for (int i = 0; i < 4; i++)
    {
        r = a1 % 2;
        a1 = a1 / 2;
        r2 = b1 % 2;
        b1 = b1 / 2;
        anum[i] = r;
        anumcp[i] = r;
        bnum[i] = r2;

        if(r2 == 0)
        {
            bcomp[i] = 1;
        }

        if(r == 0)
        {
            acomp[i] =1;
        }
    }
    A = 0;
    for ( i = 0; i < 4; i++)
    {
        res[i] = com[i]+ bcomp[i] + A;
        if(res[i] >= 2)
        {
            A = 1;
        }
        else
            A = 0;
        res[i] = res[i] % 2;
    }
    for (i = 3; i >= 0; i--)
    {
        bcomp[i] = res[i];
    }

    if (M < 0)
    {
        A = 0;
        for (i = 3; i >= 0; i--)
        {
            res[i] = 0;
        }
        for ( i = 0; i < 4; i++)
        {
            res[i] = com[i] + acomp[i] + A;

            if (res[i] >= 2)
            {
                A = 1;
            }

            else
            {
                A = 0;
                res[i] = res[i]%2;
            }
        }
        for (i = 3; i >= 0; i--)
        {
            anum[i] = res[i];
            anumcp[i] = res[i];
        }
    }

    if(Q < 0)
    {
        for (i = 0; i < 4; i++)
        {
            temp = bnum[i];
            bnum[i] = bcomp[i];
            bcomp[i] = temp;
        }
    }
}

void add(int num[])
{
    int i;
    A = 0;

    cout << "\t";
    for ( i = 0; i < 4; i++)
    {
        res[i] = pro[i] + num[i] + A;
        if (res[i] >= 2)
        {
            A = 1;
        }
        else
        {
            A = 0;
        }
        res[i] = res[i]%2;
    }

    for (i = 3; i >= 0; i--)
    {
        pro[i] = res[i];
        cout << pro[i];
    }

    cout << "";
    for (i = 3; i >= 0; i--)
    {
         cout << anumcp[i];
    }
}

void desplazamiento()
{

    int temp = pro[3], temp2 = pro[0], i;

    for (i = 1; i < 4  ; i++)
    {
        pro[i-1] = pro[i];
    }
    pro[3] = temp;

    for (i = 1; i < 4  ; i++)
    {
        anumcp[i-1] = anumcp[i];
    }
    anumcp[3] = temp2;
    cout << "\n\t";
    for (i = 3; i >= 0; i--)
    {
        cout << pro[i];
    }
    cout << "";
    for(i = 3; i >= 0; i--)
    {
        cout <<  anumcp[i];
    }
    cout << "\tSHIFT";

}

int main()
{
    int i, q = 0;

    cout << "\t\t Binary Multiplication - Booth Algorithm\n";
    cout << "\n\tPlease type the two numbers you want to multiply.\n\t(Keep in mind that the numbers cannot exceed 4 bits in length.)\n";

    do
    {
        cout << "\n\tType the value of M: ";
        cin >> M;
        cout << "\tType the value of Q: ";
        cin >> Q;
    }
    while(M >= 16 || Q >=16 || M <= -16 || Q <= -16);


    int DecimalResult = M*Q;
    cout << "\n\tYour result in decimal system is: ";
    cout <<DecimalResult;

    BinaryConversion();
    cout << "\n\n\tNumbers in binary: ";
    cout << "\n\tM = ";

    for (int i = 3; i>=0; i--)
    {
        cout << anum[i];
    }
    cout << "\n\tQ = ";

    for (int i = 3; i >= 0; i--)
    {
        cout << bnum[i];
    }

    cout << "\n\n\t-------------------------------------------------\n\t|\t\tTABLE OF PROCESS\t\t|\n\t-------------------------------------------------\n\n";

    for (i = 0;i < 4; i++)
    {
        if (anum[i] == q)
        {
            cout << "\t\t\tNOTHING IS DONE IN THIS PROCESS";
            desplazamiento();
            cout << "\n\n";
            q = anum[i];
        }

        else if(anum[i] == 1 && q == 0)
        {
            add(bcomp);
            cout << "\tSUBSTRACTION";
            desplazamiento();
            cout << "\n\n";
            q = anum[i];
        }

        else
        {
            add(bnum);
            cout << "\tADDITION";
            desplazamiento();
            cout << "\n\n";
            q = anum[i];
        }
    }

    cout << "\t\t-----------------------------";
    cout << "\n\t\t| Your result is = ";
    for (i = 3; i >= 0; i--)
    {
        cout << pro[i];
    }
    for (i = 3; i >= 0; i--)
    {
        cout << anumcp[i];

    }
    cout << " |\n\t\t-----------------------------";

    cout << "\n\n\n\n";
    return 0;
}
