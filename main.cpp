#include <iostream>
#include <time.h>
#include <ncurses.h>
#include <future>

bool now_playing = true;
int i = 0;
char i_char[12];

void loop_test1();
void game_loop();
void draw();

int main() {
    loop_test1();
}

void loop_test1()
{
    initscr();
    noecho(); //キーが入力されても表示しない
    curs_set(1);//カーソルを非表示

    //ゲームスレッド開始
    auto th_game = std::thread([] {game_loop();});

    while(now_playing) {
        char ch = getch();
        switch (ch) {
            case 'a':
                i++;
                break;
            case 'b':
                i--;
                break;
        }
    }
    th_game.join();
    endwin();
}

void game_loop()
{
    while (now_playing)
    {
        clear();
        draw();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        refresh();
    }
}

void draw()
{
    printw("%d ", i);
}