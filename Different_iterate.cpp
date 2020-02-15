#include <list>
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>

struct Player {
    
    int id;
    
    std::string name;
    
    Player(int playerId, std::string playerName) :
            id(playerId), 
            name(playerName)
        {
        }
};



int main()
{
    std::list<Player> listofPlayers =
    { 
        Player(22, "Sid"), 
        Player(3, "Laura"), 
        Player(43, "Riti"), 
        Player(30, "Angel"), 
        Player(2, "Laura") 
    };
    std::cout << "*******Iterate std::list using Iterators*******" << std::endl;
    //Create an iterator of std::list
    std::list<Player>::iterator it;
    // Make iterate point to begining and incerement it one by one till it reaches the end of list.
    for (it = listofPlayers.begin(); it != listofPlayers.end(); it++)
    {
        // Access the object through iterator
        int id = it->id;
        std::string name = it->name;
        //Print the contents
        std::cout << id << " :: " << name << std::endl;
    }
    
    std::cout
    << "*******Iterate std::list using for_each and c++11's Lambda function *********"
    << std::endl;


    std::for_each(listofPlayers.begin(), listofPlayers.end(),
    [](const Player & player)
    {
        //Print the contents
        std::cout<<player.id<< " :: "<<player.name<<std::endl;
    });

    std::cout
    << "*******Iterate std::list using c++11 Range Based For Loop *********"
    << std::endl;

    for (const Player & player : listofPlayers)
    {
        std::cout << player.id << " :: " << player.name << std::endl;
    }

    std::cout
    << "*******Iterate std::list in backwords using Iterators *********"
    << std::endl;
    
    //Create a reverse iterator of std::list
    std::list<Player>::reverse_iterator revIt;
    // Make iterate point to begining and incerement it one by one till it reaches the end of list.
    for (revIt = listofPlayers.rbegin(); revIt != listofPlayers.rend(); revIt++)
    {
        // Access the object through iterator
        int id = revIt->id;
        std::string name = revIt->name;
        //Print the contents
        std::cout << id << " :: " << name << std::endl;
    }
return 0;
}