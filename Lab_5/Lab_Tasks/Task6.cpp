#include <iostream>
using namespace std;


class Level{
    int levelNum;
    int difficulty;
    
    public:
    Level(){}
    
    Level(int ln, int d) : levelNum(ln), difficulty(d){}


        void display(){
            cout << "Level Number: " << levelNum << endl;
            cout << "Difficulty: " << difficulty << endl;
        }

    };
    
    class Game{
        string title;
        string genre;
        Level levels[10];
    
    
        public:
            Game(string t, string g, Level lvls[10]) : title(t), genre(g){
                    for (int i = 0; i < 10; i++)
                    {
                        levels[i] = lvls[i];
                    }
                }
            ~Game(){
                cout << "Game Destroyed" << endl;
            }
    
    
            void display(){
                cout << "Title: " << title << endl;
                cout << "Genre: " << genre << endl;
                for (int i = 0; i < 10; i++)
                {
                    levels[i].display();
                }
                
            }
    
    
    
    };


int main(){
    Level lvls[10];
    for (int i = 0; i < 10; i++)
    {
        lvls[i] = Level(i+1, i);
    }
    Game g1("Dark Souls", "RPG", lvls);
    
    g1.display();
    
    
    return 0;
}