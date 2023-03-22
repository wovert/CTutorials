#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

/*
斗地主是一种扑克牌游戏，通常由3名玩家参与，每人17张牌，一副牌除去大小王共有52张牌。游戏分为叫地主和打牌两个阶段。

在叫地主阶段，首先由一名玩家随机发出一张牌，这张牌为地主牌，其余两名玩家将与地主牌对抗。接下来，玩家可以选择是否叫地主，叫地主者将成为地主，并获得地主牌。如果第一个玩家不叫地主，则下一个玩家可以选择是否叫地主，直到有玩家叫地主为止。叫地主者需要支付一定数量的筹码。

在打牌阶段，地主先出牌，然后其他玩家轮流出牌，直到所有玩家都不再出牌。最后出完牌的玩家获胜。出牌需要遵守以下规则：

牌型：单张、对子、三张、三带一、三带二、顺子、连对、飞机、炸弹等牌型。

牌面大小：从大到小为：大王、小王、2、A、K、Q、J、10、9、8、7、6、5、4、3。

出牌顺序：先出牌型相同的牌中最大的牌，如果牌型不同，则不能出牌。

地主先出牌：地主有优先出牌权，其他玩家必须等待地主出牌后才能出牌。

至于机器人的实现，可以考虑采用人工智能算法来实现，例如博弈树搜索、蒙特卡罗树搜索等。在游戏中，机器人需要分析当前牌局状态、自身手牌情况以及其他玩家出牌情况，以此来决定出什么牌。机器人的出牌策略应该考虑以下因素：

牌型：选择最大的牌型出牌，优先选择能够出完的牌型。

牌面大小：出牌时应选择能够压制其他玩家的牌。

出牌顺序：尽可能地拖延其他玩家的出牌时间。

节约牌面：不浪费大牌，尽量保留大牌以应对后续牌局。
*/

// 扑克牌类
class Card {
public:
	enum Suit { CLUB, DIAMOND, HEART, SPADE };
	enum Rank { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };
	Card(Suit suit, Rank rank);
	int get_value() const;
	void display() const;

private:
	Suit suit_;
	Rank rank_;
};

// 扑克牌构造函数
Card::Card(Suit suit, Rank rank)
	: suit_(suit), rank_(rank) {}

// 获取扑克牌的值
int Card::get_value() const {
	return 13 * suit_ + rank_;
}

// 打印扑克牌
void Card::display() const {
	const char suits[] = { 'C', 'D', 'H', 'S' };
	const char* ranks[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
	cout << ranks[rank_] << suits[suit_] << " ";
}

// 洗牌函数
void shuffle(vector<Card>& deck) {
	srand(static_cast<unsigned int>(time(nullptr)));
	random_shuffle(deck.begin(), deck.end());
}

// 初始化扑克牌
void init_deck(vector<Card>& deck) {
	for (int suit = Card::CLUB; suit <= Card::SPADE; ++suit) {
		for (int rank = Card::TWO; rank <= Card::ACE; ++rank) {
			deck.push_back(Card(static_cast<Card::Suit>(suit), static_cast<Card::Rank>(rank)));
		}
	}
}

// 发牌函数
void deal(vector<Card>& deck, vector<Card>& hand, int n) {
	for (int i = 0; i < n; ++i) {
		hand.push_back(deck.back());
		deck.pop_back();
	}
}

// 主函数
int main() {
	// 初始化扑克牌
	vector<Card> deck;
	init_deck(deck);
	shuffle(deck);

	// 发牌给三个玩家
	vector<Card> player1, player2, player3;
	deal(deck, player1, 17);
	deal(deck, player2, 17);
	deal(deck, player3, 17);

	// 打印玩家手牌
	cout << "Player 1: ";
	for (auto& card : player1) {
		card.display();
	}
	cout << endl;

	cout << "Player 2: ";
	for (auto& card : player2) {
		card.display();
	}
	cout << endl;

	cout << "Player 3: ";
	for (auto& card : player3) {
		card.display();
	}
	cout << endl;

	return 0;
}