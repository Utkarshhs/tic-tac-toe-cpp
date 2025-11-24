#include <iostream>
#include <ctime>

void drawboard(char *space){

    std::cout << "\n";
    std::cout << "     |     |     " << '\n';
    std::cout << "  "<< space[0] << "  |  "<< space[1] << "  |  "<< space[2] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  "<< space[3] << "  |  "<< space[4] << "  |  "<< space[5] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  "<< space[6] << "  |  "<< space[7] << "  |  "<< space[8] << "  " << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "\n";

}
void playermove(char *space, char player){
    int number;
    do
    {
        std::cout << "enter the area you want to mark (1-9)\n";
        std::cin >> number;
        number--;
        if (space[number] == ' ')
        {
            space[number] = player;
            break;
        }
        
    }  while (number < 0 || number > 8 || space[number] != ' ');

    

}
void compmove(char *space, char comp){
    int number;
    srand(time(0));
    while (true)
    {
        number = rand() % 9;
        if (space[number] == ' ')
        {
            space[number] = comp;
            break;
        }
        
    }
    

}
bool checkwinner(char *space, char player, char comp){
    if (space[0]!= ' ' && space[0] == space[1] && space[1] == space[2])

    {
        if (space[0] == player)
        {
            std::cout << "you win\n";
        }
        else{
            std::cout << "you loose";
        }
        
    }
    else if (space[3]!= ' ' && space[3] == space[4] && space[4] == space[5]
)
    {
          if (space[3] == player)
        {
            std::cout << "you win\n";
        }
        else{
            std::cout << "you loose";
        }
    }
    else if (space[6]!= ' ' && space[6] == space[7] && space[7] == space[8]
)
    {
          if (space[6] == player)
        {
            std::cout << "you win\n";
        }
        else{
            std::cout << "you loose";
        }
    }
    
    else if (space[0]!= ' ' &&space[0] == space[3] && space[3] == space[6]
)
    {
          if (space[0] == player)
        {
            std::cout << "you win\n";
        }
        else{
            std::cout << "you loose";
        }
    }
    else if (space[1]!= ' ' && space[1] == space[4] && space[4] == space[7]
)
    {
          if (space[1] == player)
        {
            std::cout << "you win\n";
        }
        else{
            std::cout << "you loose";
        }
    }
    else if (space[2]!= ' ' && space[2] == space[5] && space[5] == space[8]
)
    {
          if (space[2] == player)
        {
            std::cout << "you win\n";
        }
        else{
            std::cout << "you loose";
        }
    }
    
    else if (space[0]!= ' ' && space[0] == space[4] && space[4] == space[8]
)
    {
          if (space[0] == player)
        {
            std::cout << "you win\n";
        }
        else{
            std::cout << "you loose";
        }
    }
    
    else if (space[2]!= ' ' && space[2] == space[4] && space[4] == space[6]
)
    {
          if (space[2] == player)
        {
            std::cout << "you win\n";
        }
        else{
            std::cout << "you loose";
        }
    }
    else{
        return false;
    }
    
    return true;

}
bool checktie(char *space){
    for (int i = 0; i < 9; i++)
    {
        if (space[i] ==' ')
        {
            return false;
        }
        
    }
    std::cout << "it's a TIE\n";
    return true;
    

}

int main(){
    char space[] = {' ',' ',' ' ,' ',' ', ' ',' ', ' ',' '};
    char player = 'x';
    char comp = 'o';
    bool runnnnig = true;
    drawboard(space);

    while (runnnnig)
    {
        playermove(space,player);
        drawboard(space);
        if (checkwinner(space, player,comp))
        {
            runnnnig = false;
            break;
        }
        else if (checktie(space))
        {
            runnnnig = false;
            break;
        }
        
        
        compmove(space, comp);
        drawboard(space);
        if (checkwinner(space, player,comp))
        {
            runnnnig = false;
            break;
        }
        else if (checktie(space))
        {
            runnnnig = false;
            break;
        }
        
    }
    
    return 0;
}