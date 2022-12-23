#include <ncurses.h>
#include <future>

bool now_playing = true;
int i = 0;

void loop_test1();
void loop();
void draw();

int main() {
    loop_test1();
}

void loop_test1()
{
    initscr(); //start ncurses window
    noecho(); //キーが入力されても表示しない
    curs_set(1);//カーソルを非表示

    //Thread start
    auto th_loop = std::thread([] {loop();});

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
    th_loop.join();
    endwin(); // end ncurses window
}

void loop()
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