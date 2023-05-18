void playGame() {
    vector<vector<Card>> board(BOARD_SIZE, vector<Card>(BOARD_SIZE, Card(' ', false)));

    shuffleBoard(board);

    int flips = 0;
    int row1, col1, row2, col2;

    while (!allCardsUncovered(board)) {
        cout << "Flips: " << flips << endl;
        printBoard(board);
        cout << "Enter the row and column of the first card: ";
        cin >> row1 >> col1;
        flipCard(board, row1, col1);

        cout << "Enter the row and column of the second card: ";
        cin >> row2 >> col2;
        flipCard(board, row2, col2);

        if (isMatch(board, row1, col1, row2, col2)) {
            cout << "Match found!" << endl;
        } else {
            cout << "No match. Try again." << endl;
            flipCard(board, row1, col1);
            flipCard(board, row2, col2);
        }

        flips++;
    }

    cout << "Congratulations! You completed the game in " << flips << " flips." << endl;
}