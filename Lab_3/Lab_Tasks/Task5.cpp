#include <iostream>
using namespace std;


class MusicPlayer{

    string playlist[50];
    string currentlyPlayingSong;


    public:
        void initializePlaylist(){
            for (int i = 0; i < 50; i++)
            {
                playlist[i] = " ";
            }
            
        }

        void addSong(string song){
            for (int i = 0; i < 50; i++)
            {
                if(playlist[i] == " "){
                    playlist[i] = song;
                    cout << "Song Added" << endl;
                    break;
                }
            }
        }
        
        void removeSong(string song){
            for (int i = 0; i < 50; i++)
            {
                if(playlist[i] == song){
                    playlist[i] = " ";
                    cout << "Song Removed" << endl;
                    break;
                }
            }
        }
        
        void playSong(string song){
            for (int i = 0; i < 50; i++)
            {
                if(playlist[i] == song){
                    cout << playlist[i] << " is being Played" << endl;
                    return;
                }
            }
            cout << song << " is not in playlist" << endl;
        }

        void displayPlaylist(){
            cout << "\t\t Playlist \t\t" << endl;
            for (int i = 0; i < 50; i++)
            {
                if (playlist[i] != " "){
                    cout << "\t\t" << playlist[i] << endl;
                }
            }
            cout << "\t\t End of Playlist \t\t" << endl;
        }

};

int main(){
    MusicPlayer player1;

    player1.initializePlaylist();

    player1.addSong("Despacito - Bruno Mars");
    player1.addSong("If you love her - David Cosby");

    player1.removeSong("Despacito - Bruno Mars");

    player1.displayPlaylist();

    player1.playSong("If you love her - David Cosby");
    player1.playSong("Despacito - Bruno Mars");



}