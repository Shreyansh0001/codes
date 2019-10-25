#include<bits/stdc++.h>
using namespace std;

bool solveMazeUtil(int **maze,int x,int y, int **sol, int row, int col);

//function to print the solution matrix
void printSolution(int **sol,int row, int col) 
{ 
    for (int i = 0; i < row; i++) { 
        for (int j = 0; j < col; j++) 
            cout<<sol[i][j]<<"\t"; 
        cout<<"\n";
    } 
} 

//chech if the traversal is safe or not
bool isSafe(int **maze,int x, int y,int row, int col) 
{ 
    // if (x, y outside maze) return false 
    if (x >= 0 && x < row && y >= 0 && y < col && maze[x][y] == 1) 
        return true; 
  
    return false; 
} 

bool solvemaze(int **maze,int row,int col)
{
    //declaring the sol matrix for passing as an argument
    int **sol = new int* [row];
    for(int i=0;i<row;i++)
    {
        sol[i] = new int[col];
    }

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            sol[i][j]=0;
        }
    }

    if( solveMazeUtil(maze,0,0,sol,row,col) ==false)
    {
        cout<<"Solution doesn't exist";
        return false;
    }
    printSolution(sol,row,col);
    return true;
}

bool solveMazeUtil(int **maze, int x, int y, int **sol, int row, int col)
{
    //check if the destination is reached or not
    if (x == row - 1 && y == col - 1)
    { 
        sol[x][y] = 1; 
        return true; 
    } 
  
    // Check if maze[x][y] is valid 
    if (isSafe(maze, x, y,row,col) == true) { 
        sol[x][y] = 1; 

        //chcek the right side for valid solution
        if (solveMazeUtil(maze, x + 1, y, sol,row,col) == true) 
            return true; 
        //if right side is not valid we move to the downward direction
        if (solveMazeUtil(maze, x, y + 1, sol,row,col) == true) 
            return true; 
        //if no valid path is available then return false and backtrack
        sol[x][y] = 0; 
        return false; 
    } 
    return false; 
}

int main()
{
    int row,col;
    cin>>row;
    cin>>col;

    //passing a dynamic 2D array to a function using pointers
    int **maze = new int* [row];
    for(int i=0;i<row;i++)
    {
        maze[i] = new int[col];
    }


    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>maze[i][j];
        }
    }
    cout<<"\n\n";
    solvemaze(maze,row,col);
    return 0;
}

// This code is submitted by shreyansh
