#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int findMinimumPages(vector<int> &books, int students, int currBook, vector<vector<int>> &memo)
{
    if (students == 1)
    {
        int totalPages = 0;
        for (int i = currBook; i < books.size(); i++)
        {
            totalPages += books[i];
        }
        return totalPages;
    }

    if (currBook >= books.size())
    {
        return INT_MAX;
    }

    if (memo[currBook][students] != -1)
    {
        return memo[currBook][students];
    }

    int totalPages = 0;
    int minPages = INT_MAX;

    for (int i = currBook; i < books.size(); i++)
    {
        totalPages += books[i];
        int remainingPages = findMinimumPages(books, students - 1, i + 1, memo);
        minPages = min(minPages, max(totalPages, remainingPages));
    }

    memo[currBook][students] = minPages;
    return minPages;
}

int allocateBooks(vector<int> &books, int students)
{
    int n = books.size();
    if (n < students)
    {
        return -1; // Not enough books to allocate to each student
    }

    vector<vector<int>> memo(n, vector<int>(students + 1, -1));

    return findMinimumPages(books, students, 0, memo);
}

int main()
{
    vector<int> books = {10, 20, 30, 40};
    int students = 2;

    int minPages = allocateBooks(books, students);

    if (minPages == -1)
    {
        cout << "Not enough books to allocate to each student." << endl;
    }
    else
    {
        cout << "Minimum number of pages: " << minPages << endl;
    }

    return 0;
}
