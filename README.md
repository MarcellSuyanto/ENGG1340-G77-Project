# CASINO ROYALE
Welcome to Casino Royale, we exist to make your gambling wishes come true!

You will be placed in a casino and 4 games will be available. You start with coins which you can use to bet inside the games.  
  
Try your best to get as many coins as possible without going bankrupt.

## Contributors
- Dang Kow Parrik Hiram [3035962300](https://github.com/ParrikD)
- Qiao Yuhan [3036265357](https://github.com/Justin-hhhhh)
- Suyanto Gregorius Marcell [3036254102](https://github.com/MarcellSuyanto)

## GAMES
- Blackjack
- Higher or Lower
- Baccarat
- Slot Machine

## Game Rules
### Blackjack
- The table starts with 4 cards: 2 Dealer cards, 2 Player cards
- The Dealer cards have one face-up and one face-down, while the Player cards are face-up
- The goal of the game is to get a hand that totals up more than the Dealer's hand
- The Player can ask for more cards from the deck to their hand and can stop whenever they want
- However, if the Player's hand exceeds 21, they lose
- If the Player's hand is 21, they automatically win, no matter the Dealer's hand
- If the Dealer's hand is greater than or equal to the Player's, the Dealer wins
- The Dealer can add more cards to their hand while their hand is less than 17
- However, if the Dealer's hand exceeds 21, they lose
- Face cards equal to 10, Aces can switch from 1 and 11 and will depend on the hand.

### Higher or Lower
- The Player will be presented 5 cards: 1 face-up and 4 face-down
- The goal is the game is to guess whether the next cards is higher/lower than the previous card
- The Player must guess all 4 cards correctly to win
- If the Player fails at any point, they lose
- The cards start from Ace to King in ascending order

### Baccarat
- The player can put their bet on either: PLAYER, BANKER, TIE
- Two cards are dealt to each the Player and Banker (Dealer)
- Cards 2-9 retain their value, Ace is 1, 10 and face cards are 0
- If the total of one's hand exceeds 9, we only take the ones digit as the hand total
- The hand closest to 9 wins
- There exists an extensive third card draw rule, open to the link provided for reference [Third Card Rule](https://gathertogethergames.com/baccarat)


### Slot Machine
- High risk, High reward
- Player must get three identical shapes to win, gaining 10x their bet
- If the player gets two identical shapes, they lose their bet
- If the player gets no identical shapes, they lose 2x their bet

Note: All games start with player placing a bet

## Running the Game
To compile our programs, simply do
```bash
make
```
and to run the game, do
```bash
./run
```
You will then be asked to either make a new profile, or load an existing one
New profiles will start with 1000 coins, bankrupted profiles will be given 100 coins

Then, you will be placed in our casino, use the WASD keys and press enter to move around  

![Casino](Casino_Map.png)

There will be numbered chairs where you can take a seat and play the game  
  
You can stay at that table as long as you like, until you go bankrupt  
  
Once bankrupt, you will be taken back to the main menu and given 100 coins to that profile out of pity  
  
There is an EXIT on the left side if the player wishes to leave the casino

## Libraries
- **iostream**: Input and Output
- **string**: Handling string variable types and operations
- **vector**: Handling vector variable types and operations
- **algorithm**: Used for __random_shuffle()__; shuffling the deck of cards
- **fstream**: Input and Output of file handling for recording player profiles
- **sstream**: Used for input string validation
- **stdio.h**: Used for __NULL__/__nullptr__
- **cstdlib**: Random generation
- **ctime**: Used for time; alongside random
- **stdlib.h**: Used for __srand()__ and random; random-generated events

## Code Requirements
### Generation of Random Events
- Random generation of a deck of cards; [playingcards.cpp](playingcards.cpp)
- Random generation of slots; [slotmachine.cpp](slotmachine.cpp)

### Data Structures for Storing Data
- Vectors to store deck of cards, cards in hand and slots; ALL
- Struct to store individual cards; [playingcards.h](playingcards.h)

### Dynamic Memory Management
- Dynamic memory used for slots; [slotmachine.cpp](slotmachine.cpp)
- Dynamic memory in terms of the use of __vectors__; ALL

### File Input/Output
- File storage to record player profiles (username and coins); [profile.cpp](profile.cpp)

### Program codes in Multiple Files
- Code separated into multiple files
- Files are combined in [main.cpp](main.cpp)

### Proper Indentation and Naming Styles and In-code Documentation
- Ensures readability and strengthens collaborativity
