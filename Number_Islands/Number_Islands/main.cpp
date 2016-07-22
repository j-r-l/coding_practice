
#include <iostream>
#include <vector>
using namespace std;

void depth_first_search(vector<vector<char>> & grid,
                        vector<vector<bool>> & grid_bools,
                        int i, int j);

////////////////////////////////////////////////////////////////////////////////

int numIslands(vector<vector<char>> & grid)
{
    // create corresponding matrix of boolean to track visited and unvisited
    size_t n_rows = grid.size();
    size_t n_cols = grid.empty() ? 0 : grid[0].size();  // stupid corner case

    vector<vector<bool>> is_visited (n_rows, vector<bool>(n_cols, false));
    
    int n_islands=0;
    for (int i=0; i<n_rows; ++i)      // for every row
    {
        for (int j=0; j<n_cols; ++j)  // for every col
        {
            // if not visited and [i][j] == '1'
            if (grid[i][j] == '1' and is_visited[i][j] == false)
            {
                n_islands++;                // found another island
                is_visited[i][j] = true;    // mark visited
                depth_first_search(grid, is_visited, i, j);
                // extended island
            }
        }
    }
    return n_islands;
}


void depth_first_search(vector<vector<char>> & grid,
                        vector<vector<bool>> & is_visited,
                        int i, int j)
{
    size_t n_rows = grid.size();
    size_t n_cols = grid.empty() ? 0 : grid[0].size(); 
    
    vector< pair<int,int> > neighbors
    {   // get all neighbors
        make_pair(i-1, j),
        make_pair(i+1, j),
        make_pair(i, j-1),
        make_pair(i, j+1)
    };
    
    // for every neighbor, extend the island if possible
    for (auto pair : neighbors)
    {
        int i = pair.first;
        int j = pair.second;
        
        if (i >= 0 and i < n_rows and j >= 0 and j < n_cols
            and grid[i][j] == '1' and is_visited[i][j] == false) // check bounds
        {
            is_visited[i][j] = true;    // mark visited
            depth_first_search(grid, is_visited, i, j);
            // recursively extend island
        }
    }
}

////////////////////////////////////////////////////////////////////////////////

int main(int argc, const char * argv[])
{
    vector<vector<char>> grid(5, vector<char>(5, '1'));
    int n_island = numIslands(grid);
    cout << n_island << endl;
    return 0;
}
































