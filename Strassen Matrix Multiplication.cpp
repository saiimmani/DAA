#include <iostream>
#include <vector>

using namespace std;

// Strassen Matrix Multiplication
vector<vector<int>> addMatrix(vector<vector<int>> &A, vector<vector<int>> &B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

vector<vector<int>> subMatrix(vector<vector<int>> &A, vector<vector<int>> &B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}

vector<vector<int>> strassen(vector<vector<int>> &A, vector<vector<int>> &B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }
    int newSize = n / 2;
    vector<vector<int>> A11(newSize, vector<int>(newSize)), A12(newSize, vector<int>(newSize)),
                         A21(newSize, vector<int>(newSize)), A22(newSize, vector<int>(newSize)),
                         B11(newSize, vector<int>(newSize)), B12(newSize, vector<int>(newSize)),
                         B21(newSize, vector<int>(newSize)), B22(newSize, vector<int>(newSize));
    
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }
    
    vector<vector<int>> M1 = strassen(addMatrix(A11, A22), addMatrix(B11, B22));
    vector<vector<int>> M2 = strassen(addMatrix(A21, A22), B11);
    vector<vector<int>> M3 = strassen(A11, subMatrix(B12, B22));
    vector<vector<int>> M4 = strassen(A22, subMatrix(B21, B11));
    vector<vector<int>> M5 = strassen(addMatrix(A11, A12), B22);
    vector<vector<int>> M6 = strassen(subMatrix(A21, A11), addMatrix(B11, B12));
    vector<vector<int>> M7 = strassen(subMatrix(A12, A22), addMatrix(B21, B22));
    
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
            C[i][j + newSize] = M3[i][j] + M5[i][j];
            C[i + newSize][j] = M2[i][j] + M4[i][j];
            C[i + newSize][j + newSize] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
        }
    }
    return C;
}

int main() {
    int n;
    cout << "Enter matrix size (power of 2): ";
    cin >> n;
    vector<vector<int>> A(n, vector<int>(n)), B(n, vector<int>(n));
    
    cout << "Enter first matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    
    cout << "Enter second matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> B[i][j];
        }
    }
    
    vector<vector<int>> C = strassen(A, B);
    
    cout << "Resultant matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
