#include <iostream>
using namespace std;

// (a) Diagonal Matrix
class DiagonalMatrix 
{
    private:
    int* arr;
    int size;
    
    public:
    DiagonalMatrix(int n) 
    {
        size = n;
        arr = new int[n];
    }
    
    void set(int i, int j, int value) 
    {
        if (i == j) 
        {
            arr[i] = value;
        }
    }
    
    int get(int i, int j) 
    {
        if (i == j) 
        {
            return arr[i];
        }
        return 0;
    }
    
    ~DiagonalMatrix() 
    {
        delete[] arr;
    }
};

// (b) Tri-diagonal Matrix
class TriDiagonalMatrix 
{
    private:
    int* arr;
    int size;
    
    public:
    TriDiagonalMatrix(int n) 
    {
        size = n;
        arr = new int[3 * n - 2];
    }
    
    void set(int i, int j, int value) 
    {
        if (i == j) 
        {
            arr[size + i - 1] = value; // Main diagonal
        } 
        
        else if (i == j + 1) 
        {
            arr[i - 1] = value; // Lower diagonal
        } 
        
        else if (i == j - 1) 
        {
            arr[2 * size + i - 2] = value; // Upper diagonal
        }
    }
    
    int get(int i, int j) 
    {
        if (i == j) 
        {
            return arr[size + i - 1];
        } 
        
        else if (i == j + 1) 
        {
            return arr[i - 1];
        } 
        
        else if (i == j - 1) 
        {
            return arr[2 * size + i - 2];
        }

        return 0;
    }
    
    ~TriDiagonalMatrix() 
    {
        delete[] arr;
    }
};

// (c) Lower Triangular Matrix (Row-major)
class LowerTriangularMatrix 
{
    private:
    int* arr;
    int size;
    
    public:
    LowerTriangularMatrix(int n) 
    {
        size = n;
        arr = new int[n * (n + 1) / 2];
    }
    
    void set(int i, int j, int value) 
    {
        if (i >= j) {
            int index = i * (i - 1) / 2 + j - 1;
            arr[index] = value;
        }
    }
    
    int get(int i, int j) 
    {
        if (i >= j) 
        {
            int index = i * (i - 1) / 2 + j - 1;
            return arr[index];
        }
        return 0;
    }
    
    ~LowerTriangularMatrix() 
    {
        delete[] arr;
    }
    
};

int main() 
{
    // Test diagonal matrix
    DiagonalMatrix dm(3);
    dm.set(0, 0, 1);
    dm.set(1, 1, 2);
    dm.set(2, 2, 3);
    
    cout << "Diagonal Matrix element (1,1): " << dm.get(1, 1) << endl;
    
    return 0;
}