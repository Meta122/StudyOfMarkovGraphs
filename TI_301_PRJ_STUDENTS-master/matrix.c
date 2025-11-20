//
// Created by overl on 20/11/2025.
//

float * create_matrix_zeros(int n)
{
    float * lines[n];
    for (int i = 0; i < n; i++)
    {
        float column[n];
        for (int j = 0; j < n; j++)
        {
            column[j] = 0;
        }
        lines[i] = column;
    }
    return lines;
}

float * copy_matrix(float * matr)
{
    int lenght=0;
    while (matr[lenght])
    {
        lenght++;
    }
    float * mcopy[lenght];
    for (int i = 0; i < lenght; i++)
    {
        for (int j = 0; j < lenght; j++)
        {
            mcopy[lenght] = matr[lenght];
        }
    }
    return mcopy;

}

float * multiply_matrix(float * matr1, float * matr2)
{
    float * result;

}

float difference_matrix(float * matr1, float * matr2)
{
    float * result;
    int i=0,j=0;
    while (matr1[i])
    {
        while (matr2[j])
        {
            result[i][j]=matr[1]-matr[2];
            j++;
        }
        i++;
    }
    return result;
}

