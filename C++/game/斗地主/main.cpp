#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

// 定义扑克牌的点数和花色
const vector<string> faces = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
const vector<string> suits = {"♠", "♥", "♣", "♦"};

// 定义一张扑克牌的结构体
struct Card {
    string face;  // 点数
    string suit;  // 花色
    Card(string f, string s) : face(f), suit(s) {}
};

// 定义斗地主游戏类
class LandlordGame {
public:
    LandlordGame();
    void start();
private:
    vector<Card> deck;      // 洗好的牌堆
    vector<Card> bottom;    // 底牌
    vector<Card> player1;   // 玩家1手中的牌
    vector<Card> player2;   // 玩家2手中的牌
    vector<Card> player3;   // 玩家3手中的牌
    int player_num;         // 地主玩家编号
    int play_turn;          // 当前出牌玩家编号
    vector<Card> curr_stack;    // 当前出牌的牌堆
    
    void init_deck();  // 初始化牌堆
    void shuffle_deck();  // 洗牌
    void deal_cards();  // 发牌
    void show_cards(const vector<Card>& cards);  // 显示一组牌的内容
    int calculate_card_score(const vector<Card>& cards);  // 计算牌分
    bool verify_cards(const vector<Card>& cards);  // 验证出牌是否合法
    vector<Card> select_cards_to_play();  // 玩家选择要出的牌
    vector<Card> select_cards_to_discard();  // 玩家选择要弃掉的牌
    vector<Card> robot_select_cards_to_play();  // 机器人选择要出的牌
    vector<Card> robot_select_cards_to_discard();  // 机器人选择要弃掉的牌
    void play_cards();  // 出牌环节
    void discard_cards();  // 弃牌环节
    bool is_game_over();  // 判断游戏是否结束
    void show_game_result();  // 显示游戏结果
};

// 构造函数：初始化牌堆以及其他数据成员
LandlordGame::LandlordGame() {
    init_deck();
    player_num = 0;
    play_turn = 1;
    curr_stack.clear();
}

// 初始化牌堆
void LandlordGame::init_deck() {
    deck.clear();
    
    for (string face : faces) {
        for (string suit : suits) {
            deck.push_back(Card(face, suit));
        }
    }
}

// 洗牌
void LandlordGame::shuffle_deck() {
    srand(time(0));
    random_shuffle(deck.begin(), deck.end());
}

// 发牌
void LandlordGame::deal_cards() {
    for (int i = 0; i < 17; i++) {
        player1.push_back(deck.back());
        deck.pop_back();
        
        player2.push_back(deck.back());
        deck.pop_back();
        
        player3.push_back(deck.back());
        deck.pop_back();
    }
    
    bottom.clear();
    for (int i = 0; i < 3; i++) {
        bottom.push_back(deck.back());
        deck.pop_back();
    }
}

// 显示一组牌的内容
void LandlordGame::show_cards(const vector<Card>& cards) {
    for (Card card : cards) {
        cout << card.face << card.suit << " ";
    }
    cout << endl;
}

// 计算牌分
int LandlordGame::calculate_card_score(const vector<Card>& cards) {
    int score = 0;
    for (Card card : cards) {
        if (card.face == "10" || card.face == "J" || card.face == "Q" || card.face == "K") {
            score += 10;
        }
        else if (card.face == "A") {
            score += 20;
        }
    }
    return score;
}

// 验证出牌是否合法
bool LandlordGame::verify_cards(const vector<Card>& cards) {
    if (cards.empty()) {
        return false;
    }
    
    // 所有牌都必须是同种牌型
    string type = cards.front().face;
    for (Card card : cards) {
        if (card.face != type) {
            return false;
        }
    }
    
    // 牌型必须大于前一个出牌人
    if (!curr_stack.empty()) {
        if (cards.size() != curr_stack.size()) {
            return false;
        }
        if (type == "2") {  // 炸弹牌型
            if (curr_stack.front().face != "2") {
                return true;
            }
            else if (cards.front().suit == curr_stack.front().suit) {
                return cards.front().suit > curr_stack.front().suit;
            }
            else {
                return false;
            }
        }
        else if (type == "joker" || type == "JOKER") {  // 王炸牌型
            return true;
        }
        else {  // 普通牌型
            return type > curr_stack.front().face;
        }
    }
    else {  // 第一个出牌人可以随便出牌
        return true;
    }
}

// 玩家选择要出的牌
vector<Card> LandlordGame::select_cards_to_play() {
    vector<Card> selected_cards;
    string input;
    cout << "请玩家" << play_turn << "出牌（输入0跳过）：" << endl;
    getline(cin, input);
    if (input == "0") {
        selected_cards.clear();
    }
    else {
        vector<string> tokens;
        string token;
        size_t pos = 0;
        while ((pos = input.find(' ')) != string::npos) {
            token = input.substr(0, pos);
            tokens.push_back(token);
            input.erase(0, pos + 1);
        }
        tokens.push_back(input);
        for (string token : tokens) {
            bool found = false;
            for (Card card : player1) {
                if (card.face + card.suit == token) {
                    selected_cards.push_back(card);
                    player1.erase(find(player1.begin(), player1.end(), card));
                    found = true;
                    break;
                }
            }
            if (!found) {
                selected_cards.clear();
                break;
            }
        }
    }
    return selected_cards;
}

// 玩家选择要弃掉的牌
vector<Card> LandlordGame::select_cards_to_discard() {
    vector<Card> selected_cards;
    string input;
    cout << "请玩家" << play_turn << "弃牌（输入0跳过）：" << endl;
    getline(cin, input);
    if (input == "0") {
        selected_cards.clear();
    }
    else {
        vector<string> tokens;
        string token;
        size_t pos = 0;
        while ((pos = input.find(' ')) != string::npos) {
            token = input.substr(0, pos);
            tokens.push_back(token);
            input.erase(0, pos + 1);
        }
        tokens.push_back(input);
        for (string token : tokens) {
            bool found = false;
            for (Card card : played_cards) {
                if (card.face + card.suit == token) {
                    selected_cards.push_back(card);
                    played_cards.erase(find(played_cards.begin(), played_cards.end(), card));
                    found = true;
                    break;
                }
            }
            if (!found) {
                selected_cards.clear();
                break;
            }
        }
    }
    return selected_cards;
}

// 机器人选择要出的牌
vector<Card> LandlordGame::robot_select_cards_to_play() {
    vector<Card> selected_cards;
    vector<Card> candidates;
    
    // 遍历所有手牌，找出能够出的牌
    for (Card card : player2) {
        if (curr_stack.empty() || card.face == curr_stack.front().face) {
            candidates.push_back(card);
        }
    }
    
    // 从候选牌中找出最大牌型
    if (!candidates.empty()) {
        selected_cards.push_back(candidates.front());
        for (Card card : candidates) {
            if (card.face > selected_cards.front().face) {
                selected_cards.clear();
                selected_cards.push_back(card);
            }
        }
    }
    
    return selected_cards;
}

// 机器人选择要弃掉的牌
vector<Card> LandlordGame::robot_select_cards_to_discard() {
    vector<Card> selected_cards;
    if (played_cards.empty()) {
        selected_cards = player2;
    }
    else {
        // 遍历所有手牌，找出最小点数的牌
        selected_cards.push_back(player2.front());
        for (Card card : player2) {
            if (card.face < selected_cards.front().face) {
                selected_cards.clear();
                selected_cards.push_back(card);
            }
        }
    }
    return selected_cards;
}

// 出牌环节，重复进行直到出牌合法
void LandlordGame::play_cards() {
    while (true) {
        cout << "现在是玩家" << play_turn << "出牌：" << endl;
        
        // 如果是机器人出牌，无需等待输入，直接选择要出的牌
        if (play_turn == 2) {
            curr_stack = robot_select_cards_to_play();
            if (curr_stack.empty()) {
                cout << "机器人选择不出！" << endl;
            }
            else {
                cout << "机器人出了牌：";
                show_cards(curr_stack);
                player2.erase(remove_if(player2.begin(), player2.end(), [](Card card) { return card.face == curr_stack.front().face; }), player2.end());
            }
        }
        
        // 如果是玩家出牌，等待玩家输入
        else {
            curr_stack = select_cards_to_play();
            if (curr_stack.empty()) {
                cout << "玩家选择不出！" << endl;
            }
        }
        
        // 如果出的牌不合法，重新出牌
        if (!verify_cards(curr_stack)) {
            cout << "出牌不合法！" << endl;
        }
        else {
            cout << "玩家" << play_turn << "出牌成功！" << endl;
            break;
        }
    }
    
    played_cards.insert(played_cards.end(), curr_stack.begin(), curr_stack.end());
}

// 弃牌环节
void LandlordGame::discard_cards() {
    cout << "现在是玩家" << play_turn << "弃牌：" << endl;
    
    // 如果是机器人弃牌，直接选择要弃掉的牌
    if (play_turn == 2) {
        curr_stack = robot_select_cards_to_discard();
        cout << "机器人弃掉了牌：";
        show_cards(curr_stack);
        player2.erase(remove_if(player2.begin(), player2.end(), [](Card card) { return card.face == curr_stack.front().face; }), player2.end());
    }
    
    // 如果是玩家弃牌，等待玩家输入。如果输入的牌不合法，则重新出牌。
    else {
        while (true) {
            curr_stack = select_cards_to_discard();
            if (!verify_cards(curr_stack)) {
                cout << "弃牌不合法，请重新选择！" << endl;
            }
            else {
                break;
            }
        }
    }
    
    played_cards.insert(played_cards.end(), curr_stack.begin(), curr_stack.end());
}

// 判断游戏是否结束
bool LandlordGame::is_game_over() {
    if (player1.empty() || player2.empty() || player3.empty()) {
        return true;
    }
    return false;
}

// 显示游戏结果
void LandlordGame::show_game_result() {
    int score1 = calculate_card_score(played_cards);
    int score2 = calculate_card_score(player2);
    if (player_num == 2) {
        score2 += calculate_card_score(bottom);
    }
    int score3 = calculate_card_score(played_cards);
    if (player_num == 3) {
        score3 += calculate_card_score(bottom);
    }
    if (score1 > score2 && score1 > score3) {
        cout << "玩家1获胜！" << endl;
    }
    else if (score2 > score1 && score2 > score3) {
        cout << "玩家2获胜！" << endl;
    }
    else {
        cout << "玩家3获胜！" << endl;
    }
}

// 开始游戏
void LandlordGame::start() {
    shuffle_deck();
    deal_cards();
    player_num = 1;
    played_cards.clear();
    
    // 首先进行叫地主环节，任意一位玩家叫地主后就停止
    cout << "现在开始叫地主环节：" << endl;
    while (true) {
        cout << "现在是玩家" << player_num << "叫地主（输入1表示叫，输入0表示不叫）：" << endl;
        string input;
        getline(cin, input);
        if (input == "1") {
            cout << "玩家" << player_num << "成为了地主！" << endl;
            player1.insert(player1.end(), bottom.begin(), bottom.end());
            sort(player1.begin(), player1.end(), [](Card x, Card y) { return x.face > y.face; });
            play_turn = 2;
            break;
        }
        else {
            player_num++;
            if (player_num > 3) {
                bottom.clear();
                bottom.push_back(deck.back());
                deck.pop_back();
                bottom.push_back(deck.back());
                deck.pop_back();
                bottom.push_back(deck.back());
                deck.pop_back();
                player_num = 1;
            }
        }
    }
    
    // 进行出牌和弃牌环节，直到游戏结束
    while (!is_game_over()) {
        cout << "现在开始出牌环节：" << endl;
        play_cards();
        if (is_game_over()) {
            break;
        }
        cout << "现在开始弃牌环节：" << endl;
        discard_cards();
        if (is_game_over()) {
            break;
        }
        play_turn = (play_turn + 1) % 3;
    }
    
    show_game_result();
}

// 主函数
int main() {
    LandlordGame game;
    game.start();
    return 0;
}

