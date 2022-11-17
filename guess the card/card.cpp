#include <iostream>
#include<string>
#include<cstdlib>
using namespace std;


enum card_name_type {ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, ACE};
enum suit_type { SPADES, HEARTS, DIAMODS, CLUBS};

struct Card
{
  card_name_type card_name;
  suit_type suit;
  int skill_level;		
};

int main() {
    int dif;
    cout<< "Win Points: 5" << endl;
    cout<< "Select Difficulty:" << endl;
    cout<< "    1. Easy" <<endl;
    cout<< "    2. Medium" <<endl;
    cout<< "    3. Hard" <<endl;
    
    cin>> dif;
    int guess_count;
    if(dif==1) {
        guess_count = 30;
    }else if(dif == 2){
        guess_count = 20;
    }else if(dif == 3){
        guess_count = 10;
    }else{
        cout<< "invalid choice"<<endl;
        return 0;
    }
    
    Card *second_deck = new Card[guess_count];
    Card *second_card;
    second_card = second_deck;
    for(int i=0;i<guess_count;i++)
    {
        second_card->card_name = static_cast<card_name_type>(rand()%13);  // convert int to enum data type
        second_card->suit = static_cast<suit_type>(rand()%4);
        second_card++;
    }
    second_card = second_deck;
    for(int i=0;i<guess_count;i++)
    {
            cout<<second_card->card_name << "-" << second_card->suit <<endl;
            second_card++;
    }
    int guess_name;
    int guess_suit;
    second_card = second_deck;
    int points=0;
    for(int tries=0;tries<guess_count;tries++)
    {
        cout << "Enter a card name: ";
        cin >> guess_name;
        cout << "Enter a card suite: ";
        cin >> guess_suit;

        if(second_card->card_name==guess_name && second_card->suit==guess_suit)
        {
            cout<< "Yayyyy! +1" <<endl;
            points++;
        }else{
            cout<< "Nahhh" <<endl;
        }
        if(points>= 5)
        {
            break;
        }
        second_card++;
    }
    if(points>=5)
    {
        cout<<"You Win!"<<endl;
    }else{
        cout<<"Better luck next time"<<endl;
    }
    return 0;
}
