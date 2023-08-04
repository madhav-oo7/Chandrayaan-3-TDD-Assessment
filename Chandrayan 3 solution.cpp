#include <bits/stdc++.h>
using namespace std;

void move_forward(int&x, int&y, int&z, char&direction){
    if(direction == 'N')
      y += 1;
    else if(direction == 'S')
      y -= 1;
    else if(direction == 'E')
      x += 1;
    else if(direction == 'W')
      x -= 1;
    else if(direction == 'U')
      z += 1;
    else if(direction == 'D') 
      z -= 1;
}

void move_backward(int&x, int&y, int&z, char&direction){
    if(direction == 'N')
      y -= 1;
    else if(direction == 'S')
      y += 1;
    else if(direction == 'E')
      x -= 1;
    else if(direction == 'W')
      x += 1;
    else if(direction == 'U')
      z -= 1;
    else if(direction == 'D') 
      z += 1;
}

void turn_left(char& direction){
    if(direction == 'N')
      direction = 'W';
    else if(direction == 'S')
      direction = 'E';
    else if(direction == 'E')
      direction = 'N';
    else if(direction == 'W')
      direction = 'S';
    else if(direction == 'U')
      direction = 'W';
    else if(direction == 'D')
      direction = 'E';
}

void turn_right(char& direction){
    if(direction == 'N')
      direction = 'E';
    else if(direction == 'S')
      direction = 'W';
    else if(direction == 'E')
      direction = 'S';
    else if(direction == 'W')
      direction = 'N';
    else if(direction == 'U')
      direction = 'E';
    else if(direction == 'D')
      direction = 'W';
}

void turn_up(char& direction){
    if(direction == 'N')
      direction = 'U';
    else if(direction == 'S')
      direction = 'D';
    else if(direction == 'E')
      direction = 'U';
    else if(direction == 'W')
      direction = 'D';
    
}
void turn_down(char& direction){
    if(direction == 'N')
      direction = 'D';
    else if(direction == 'S')
      direction = 'U';
    else if(direction == 'E')
      direction = 'D';
    else if(direction == 'W')
      direction = 'U';
  
}

void navigate_commands(int&x, int&y, int&z, char&direction, vector<char> commands){
    
    for(int i = 0; i < commands.size(); i++){
        
        if(commands[i] == 'f')
          move_forward(x,y,z,direction);
        else if(commands[i] == 'b')
          move_backward(x,y,z,direction);
        else if(commands[i] == 'l')
          turn_left(direction);
        else if(commands[i] == 'r')
          turn_right(direction);
        else if(commands[i] == 'u')
          turn_up(direction);
        else if(commands[i] == 'd')
          turn_down(direction);
    }
}

int main()
{
    int x, y, z;
    char direction;
    cout << "Enter initial position & direction of Spacecraft."<<endl;
    cout << "x_cordinate: ";
    cin >> x;
    cout << "y_cordinate: ";
    cin >> y;
    cout << "z_cordinate: ";
    cin >> z;
    cout << "direction: ";
    cin >> direction;
    
    vector<char> commands;
    char c;
    while(cin >> c){
        if(c=='0'){
            break;
        }
        else if(c!='f' && c!='b' && c!='l' && c!='r' && c!='u' && c!='d')
        {
            cout << "Please enter valid commands !" << endl;
        }
        else {
         commands.push_back(c);
        }
    }
    
    
    navigate_commands(x,y,z,direction,commands);
    cout<< "Final position: " << "(" << x << "," << y << "," << z << ")" << endl;
    cout<< "Final direction: " << direction;
    

    return 0;
}
