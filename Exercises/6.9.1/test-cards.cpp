static void testCardClass(void)
{
	CardDeck deck;
	CardHand hand;
	int handSize, playerScore, progScore;
	qout << "How many cards in a hand? " << endl;
	handSize = QInputDialog::getInt(0, QString("getInt()"), \
									QString("How many cards in hand?"), 1, 5);
	QMessageBox::StandardButton sb;
	do {
		hand = deck.deal(handSize);
		qout << "Here is your hand:" << endl;
		qout << hand.toString() << endl;
		playerScore = hand.getValue();
		qout << QString("Your score is: %1 points.")
				.arg(playerScore) << endl;
		// Now a hand for the dealer:
		hand = deck.deal(handSize);
		progScore = hand.getValue();
		qout << "Here is my hand:" << endl;
		qout << hand.toString() << endl;
		qout << QString("My score is: %1 points.")
				.arg(progScore) << endl;
		qout << QString("%1 win!!")
				.arg((playerScore > progScore)?"You":"I") << endl;
		sb = QMessageBox::question(0, QString("QMessageBox::question()"),
								   QString("Another hand?"), QMessageBox::Yes | QMessageBox::No);

	} while (sb == QMessageBox::Yes);
}