# Future Ideas

## GUI

- Make communication between MainApp and the panes use one paradigm:
  - Currently, it communicates with the MovieMatch panel with the IMatch
    interface and with the AddMovie panel using a request/reply
    mechanism implemented with signals and slots.

- Integrate MainApp and MainMenu. Currently, MainMenu listens for close 
  signals from the individual panels and then forwards them to MainApp, 
  so it can close the panels.

- Add option to delete movies

- Add undo option for match

- Add text on leaderboard when there are no movies

- ??? Add movie posters

## Backend

- Use an algorithm to find good movie pairs, instead of random (choose 
  pairs with similar elo, or prefer movies that have not participated in 
  a match.

- Dynamically adjust K and D parameters based on the opponents' scores.

- Add option to delete movies

- Better handle locking when registering a movie match. Currently, the 
  elo of the two movies is fetched by the backend, which then calculates
  the new elo scores and then writes them in the database. In the meantime
  another process might have changed the Elo scores of the movies making 
  the calculations wrong and replacing the Elo scores with wrong ones. (No
  match information is lost though.)
    - One way to fix this is to calculate the new Elo scores inside the 
      MovieDatabase class, after starting the transaction, ensuring that 
      the database stays locked while the scores are calculated.